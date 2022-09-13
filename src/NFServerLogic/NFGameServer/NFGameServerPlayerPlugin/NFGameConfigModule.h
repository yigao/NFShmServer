// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfigModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameConfigModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServer/NFCommHead/NFIGameConfigModule.h"

class NFCGameConfigModule : public NFIGameConfigModule {
public:
    explicit NFCGameConfigModule(NFIPluginManager *p);

    virtual ~NFCGameConfigModule();
public:
    virtual void UnRegisterRoomInfo();

    virtual void UpdateRoomInfo(uint32_t onlinecount);
};
