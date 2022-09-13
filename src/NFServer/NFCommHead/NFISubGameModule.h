// -------------------------------------------------------------------------
//    @FileName         :    NFISubGameModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFISubGameModule.h
//
// -------------------------------------------------------------------------

#pragma once

/**
* @brief sub game module
*/

#include "NFIGameRoomModule.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFServer/NFCommHead/NFIGameRobotHandle.h"
#include "NFComm/NFMessageDefine/ResMeta_s.h"
#include <string>

class NFISubGameModule : public NFIDynamicModule
{
public:
    NFISubGameModule(NFIPluginManager* p):NFIDynamicModule(p)
    {

    }

    virtual ~NFISubGameModule()
    {
        if (FindModule<NFIGameRoomModule>())
        {
            FindModule<NFIGameRoomModule>()->ClearGameDeskCreator(this);
        }
    }

    virtual int RegisterGameDeskCreator(uint32_t gameKind)
    {
        return FindModule<NFIGameRoomModule>()->RegisterGameDeskCreator(gameKind, this);
    }

    virtual NFIGameDeskHandle* CreateGameDeskHandle() = 0;

	virtual NFIGameRobotHandle* CreateGameRobotHandle() { return NULL; };

	virtual const proto_ff_s::GameRoomDesc_s* GetRoomConfig(uint32_t roomId) = 0;
};