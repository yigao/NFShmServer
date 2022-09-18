// -------------------------------------------------------------------------
//    @FileName         :    NFIRoomManagerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIRoomManagerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
class NFGameRoomInfoMgr;

class NFIRoomServerModule : public NFIDynamicModule {
public:
    NFIRoomServerModule(NFIPluginManager *p) : NFIDynamicModule(p) {

    }

    virtual ~NFIRoomServerModule() {

    }
};