// -------------------------------------------------------------------------
//    @FileName         :    NFStoreServerTest.h
//    @Author           :    gaoyi
//    @Date             :    23-3-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFStoreServerTest
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFStoreServerTest : public NFIDynamicModule
{
public:
    NFStoreServerTest(NFIPluginManager* p);

    virtual ~NFStoreServerTest();
public:
    virtual bool Execute() override;
public:
    int Test_GetRpcInsertObjService();
    int Test_GetRpcDeleteService();
    int Test_GetRpcModifyObjService();
    int Test_GetRpcUpdateObjService();
    int Test_GetRpcDeleteObjService();
    int Test_GetRpcExecuteObjService();
    int Test_GetRpcExecuteMoreObjService();
};