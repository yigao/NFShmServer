// -------------------------------------------------------------------------
//    @FileName         :    NFIRoomManagerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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