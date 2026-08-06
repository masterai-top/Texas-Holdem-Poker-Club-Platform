#include "common/macros.h"
#include "gameroot.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "utils/tarslog.h"
#include "message/sendclientmessage.h"
#include "logic/gamelogic/core/checkbegin.h"
#include "process/process.h"
#include "config/gameconfig.h"

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {
            void GameParameter(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__


                using namespace RoomSo;
                using namespace context;
                using namespace message;
                using namespace gamelogic;
                using namespace process;
                using namespace config;

                TGAME_GameParameter const *nnrs = static_cast<TGAME_GameParameter const *>(p);
                DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"TGAME_GameParameter_E" << ", smallBlind: " << nnrs->smallBlind << ", level: " << nnrs->blindlevel << ", ante: " << nnrs->ante);

                //设置盲注，前注
                root->cfg->setFrontBet(nnrs->smallBlind); //前注
                root->cfg->setMinTake(nnrs->bigBlind);    //最小携带
                root->cfg->setMaxSeatNum(nnrs->ante);    //座位数
                root->cfg->setBlindLevel(nnrs->blindlevel);

                if (nnrs->optionTime > 0)
                {
                    root->cfg->setInitBetTime(1, nnrs->optionTime - 1);
                }

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
