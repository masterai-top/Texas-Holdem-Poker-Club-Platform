#include "common/macros.h"
#include "common/nndef.h"
#include "common/nnlogic.h"
#include "gameroot.h"
#include "logic/gamelogic/core/sendhdcard.h"
#include "utils/tarslog.h"
#include "context/context.h"
#include "message/sendclientmessage.h"
#include "config/gameconfig.h"
#include "logic/gamelogic/core/begintimer.h"
#include "logic/gamelogic/core/endtimer.h"
#include "process/process.h"
#include "message/sendroommessage.h"
#include "third.pb.h"
#include "XGameComm.pb.h"
#include "ddz.pb.h"

using namespace nndef;

namespace game
{
    namespace logic
    {
        namespace gamelogic
        {
            void SendHdCard(GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                DLOG_TRACE("roomid:" << root->roomid() << ", " << "SendHdCard roomid:" << root->roomid());

                using namespace context;
                using namespace message;
                using namespace nnlogic;
                using namespace config;
                using namespace process;
                using namespace RoomSo;

                if(root->pro->getProcess() != NN_STATE_SEND_CARD )
                {
                    DLOG_TRACE("roomid:" << root->roomid() << ", " << "SendHdCard process err. process:" << root->pro->getProcess());
                    return ;
                }

                vecc_t &vecWallCards = root->con->refVecWallCard();
                //筑牌
                nnlogic::build(vecWallCards);
                //洗牌
                nnlogic::shuffle<card_t>(vecWallCards);

                if(vecWallCards.size() != 54)
                {
                    DLOG_TRACE("roomid:" << root->roomid() << ", " << "SendHdCard vecWallCards size:" << vecWallCards.size());
                    return ;
                }

                //优先把debug 弹出来
                vecc_t &vecCommCards = root->con->refVecCommCard();
                for(auto item : root->con->getDebugCard())
                {
                    DLOG_TRACE("roomid:" << root->roomid() << ", cid: " << item.first  <<", card size:" << item.second.size());

                    if(item.first == -1)//地主牌
                    {
                        if(item.second.size() >= 3)
                        {
                            vecCommCards.insert(vecCommCards.begin(), item.second.begin(), item.second.begin() + 3);
                        }
                        else
                        {
                            vecCommCards.insert(vecCommCards.begin(), item.second.begin(), item.second.end());
                        }
                        nnlogic::vecremove(vecWallCards, vecCommCards);
                    }
                    else
                    {
                        User* user= root->con->getUserByCid(item.first);
                        if(!user || !user->isReady())
                        {
                            continue;
                        }
                        vecc_t &vecCards = user->refVecCards();
                        if(item.second.size() >= 17)
                        {
                            vecCards.insert(vecCards.begin(), item.second.begin(), item.second.begin() + 17);
                        }
                        else
                        {
                            vecCards.insert(vecCards.begin(), item.second.begin(), item.second.end());
                        }
                        nnlogic::vecremove(vecWallCards, vecCards);
                    }
                }
                
                nnlogic::deal(vecWallCards, vecCommCards, 3 - vecCommCards.size());

                XGameDDZProto::DDZ_msg2cSendCardNotify shcm2;
                shcm2.set_lbasescore(root->cfg->getBaseScore());
                for(int i = 0; i < 3; i++)
                {
                    shcm2.add_scommcards(-1);
                }
                std::map<cid_t, User> &usermap = root->con->refUserMap();
                for (auto it = usermap.begin(); it != usermap.end(); it++)
                {
                    XGameDDZProto::PlayerInfo playerinfo;
                    vecc_t &vecCards = it->second.refVecCards();

                    if(vecCards.size() < 17)
                    {
                        nnlogic::deal(vecWallCards, vecCards, 17 - vecCards.size());
                    }

                    for(int i = 0; i < 17; i++)
                    {
                        playerinfo.add_shdcards(-1);
                    }
                    (*shcm2.mutable_mplayerinfo())[it->first] = playerinfo;
                }

                //发包
                
                for (auto it = usermap.begin(); it != usermap.end(); it++)
                {
                    auto fd = (*shcm2.mutable_mplayerinfo()).find(it->first);
                    if (fd != (*shcm2.mutable_mplayerinfo()).end())
                    {
                        fd->second.clear_shdcards();
                        for (auto itcards = it->second.getVecCards().begin(); itcards != it->second.getVecCards().end(); ++itcards)
                        {
                            fd->second.add_shdcards(*itcards);
                        }
                        sendClientMessage<XGameDDZProto::DDZ_msg2cSendCardNotify>(it->second.getUid(), XGameDDZProto::DDZ_msg2cSendCardNotify_E, shcm2, root);
                        DLOG_TRACE("roomid:" << root->roomid() << ", " << ">>>SendHdCard shcm2: " << logPb(shcm2));

                        //
                        fd->second.clear_shdcards();

                        //重置-1
                        for(int i = 0; i < 17; i++)
                        {
                            fd->second.add_shdcards(-1);
                        }
                    }
                }

                root->con->setWaitGameTime(-1, 0);

                EndTimer(NN_XTIME_GAME_XTIME, root, false);
                BeginTimer(NN_XTIME_GAME_XTIME, 3, [](TimerParam & param)->int
                {
                    auto body = static_cast<std::tuple<GameRoot *> const *>(param.getBody());
                    auto root = std::get<0>(*body);

                    root->pro->turnProcess(NN_STATE_JIAODIZHU);
                    return 0;
                }, root, false);

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
