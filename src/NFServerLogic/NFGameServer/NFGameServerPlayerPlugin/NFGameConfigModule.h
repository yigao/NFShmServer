// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfigModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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
