#include "common/macros.h"
#include "gameroot.h"
#include "Comm/ITableGame.h"
#include "utils/tarslog.h"
#include "message/sendclientmessage.h"
#include "message/sendroommessage.h"
#include "config/gameconfig.h"

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {
            int RobotAction(void const *p, GameRoot *root)
            {
                // PERFSTATS_ENTRY();
                __TRY__

                using namespace RoomSo;
                using namespace message;

                RobotAllAction const *nnrs = static_cast<RobotAllAction const *>(p);
                if(nnrs == nullptr)
                {
                    //DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"robot config is err.");
                    return -1;
                }

                root->cfg->setRobotAllAction(nnrs);
                //DLOG_TRACE("roomid:"<<root->roomid()<<", nnrs: "<<printTars(*nnrs));

                __CATCH__
                // PERFSTATS_EXIT();
                return 0;
            }
        }
    }
}
