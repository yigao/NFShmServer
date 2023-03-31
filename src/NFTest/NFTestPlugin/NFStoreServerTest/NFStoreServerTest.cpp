// -------------------------------------------------------------------------
//    @FileName         :    NFStoreServerTest.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFStoreServerTest
//
// -------------------------------------------------------------------------

#include "NFStoreServerTest.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

NFStoreServerTest::NFStoreServerTest(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFStoreServerTest::~NFStoreServerTest()
{
}

bool NFStoreServerTest::Execute()
{
    if (!m_pObjPluginManager->IsInited())
    {
        return true;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        return true;
    }

    static bool flag = false;
    if (flag == false)
    {
        //Test_GetRpcInsertObjService();
        //Test_GetRpcDeleteService();
        //Test_GetRpcUpdateObjService();
        //Test_GetRpcExecuteObjService();
        Test_GetRpcExecuteMoreObjService();
        //Test_GetRpcModifyObjService();
        //Test_GetRpcDeleteObjService();
        flag = true;
    }

    return true;
}

int NFStoreServerTest::Test_GetRpcInsertObjService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        for (int i = 1; i < 500; i++)
        {
            proto_ff::tbServerMgr data;
            data.set_id(i);
            data.set_contract(NFCommon::tostr(i));
            data.set_machine_addr(NFCommon::tostr(i));
            int iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService
                    (NF_ST_LOGIC_SERVER, 0, data,
                     [](int rpcRetCode)
                     {
                         if (rpcRetCode != 0)
                         {
                             NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Test_GetRpcInsertObjService rpcRetCode:{}", GetErrorStr(rpcRetCode));
                         }
                     });
            if (iRet != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Test_GetRpcInsertObjService Failed!");
                return 0;
            }
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     for (int i = 500; i < 1000; i++)
                     {
                         proto_ff::tbServerMgr data;
                         data.set_id(i);
                         data.set_contract(NFCommon::tostr(i));
                         data.set_machine_addr(NFCommon::tostr(i));
                         int iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_LOGIC_SERVER, 0, data);
                         if (iRet != 0)
                         {
                             NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcInsertObjService iRet:{}", GetErrorStr(iRet));
                         }
                     }
                 });
    }
    return 0;
}

int NFStoreServerTest::Test_GetRpcModifyObjService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        proto_ff::tbServerMgr data;
        data.set_id(1200);
        data.set_contract("1");
        data.set_machine_addr("2");
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcModifyObjService
                (NF_ST_LOGIC_SERVER, 0, data,
                 [](int rpcRetCode)
                 {
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcModifyObjService rpcRetCode:{}", GetErrorStr(rpcRetCode));
                 });

        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcSelectObjService Failed!");
            return 0;
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     proto_ff::tbServerMgr data;
                     data.set_id(1201);
                     data.set_contract("1");
                     data.set_machine_addr("2");
                     int iRet = FindModule<NFIServerMessageModule>()->GetRpcModifyObjService(NF_ST_LOGIC_SERVER, 0, data);
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcModifyObjService iRet:{}", GetErrorStr(iRet));
                 });
    }
    return 0;
}

int NFStoreServerTest::Test_GetRpcUpdateObjService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        proto_ff::tbServerMgr data;
        data.set_id(1200);
        data.set_contract("1200");
        data.set_machine_addr("1200");
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcUpdateObjService
                (NF_ST_LOGIC_SERVER, 0, data,
                 [](int rpcRetCode)
                 {
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcUpdateObjService rpcRetCode:{}", GetErrorStr(rpcRetCode));
                 });

        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcUpdateObjService Failed!");
            return 0;
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     proto_ff::tbServerMgr data;
                     data.set_id(1201);
                     data.set_contract("1201");
                     data.set_machine_addr("1201");
                     int iRet = FindModule<NFIServerMessageModule>()->GetRpcUpdateObjService(NF_ST_LOGIC_SERVER, 0, data);
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcUpdateObjService iRet:{}", GetErrorStr(iRet));
                 });
    }
    return 0;
}

int NFStoreServerTest::Test_GetRpcDeleteObjService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        proto_ff::tbServerMgr data;
        data.set_id(1200);
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcDeleteObjService
                (NF_ST_LOGIC_SERVER, 0, data,
                 [](int rpcRetCode)
                 {
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcDeleteObjService rpcRetCode:{}", GetErrorStr(rpcRetCode));
                 });

        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcDeleteObjService Failed!");
            return 0;
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     proto_ff::tbServerMgr data;
                     data.set_id(1201);
                     int iRet = FindModule<NFIServerMessageModule>()->GetRpcDeleteObjService(NF_ST_LOGIC_SERVER, 0, data);
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcDeleteObjService iRet:{}", GetErrorStr(iRet));
                 });
    }
    return 0;
}

int NFStoreServerTest::Test_GetRpcDeleteService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        proto_ff::tbServerMgr data;
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcDeleteService
                (NF_ST_LOGIC_SERVER, 0, data,
                 [](int rpcRetCode)
                 {
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcDeleteObjService rpcRetCode:{}", GetErrorStr(rpcRetCode));
                 }, "id <= 500");

        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcDeleteObjService Failed!");
            return 0;
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     proto_ff::tbServerMgr data;
                     int iRet = FindModule<NFIServerMessageModule>()->GetRpcDeleteService(NF_ST_LOGIC_SERVER, 0, data, "id >= 500 and id <= 999");
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcDeleteObjService iRet:{}", GetErrorStr(iRet));
                 });
    }
    return 0;
}

int NFStoreServerTest::Test_GetRpcExecuteObjService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        int iRet = FindModule<NFIServerMessageModule>()->GetRpcExecuteService
                (NF_ST_LOGIC_SERVER, 0, "select * from tbServerMgr where id = 1200",
                 [](int rpcRetCode, proto_ff::tbServerMgr &respone)
                 {
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteService rpcRetCode:{} respone:{}", GetErrorStr(rpcRetCode), respone.DebugString());
                 });

        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteService Failed!");
            return 0;
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     proto_ff::tbServerMgr data;
                     int iRet = FindModule<NFIServerMessageModule>()->GetRpcExecuteService(NF_ST_LOGIC_SERVER, 0, data,
                                                                                           "select * from tbServerMgr where id = 1201");
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteService rpcRetCode:{} respone:{}", GetErrorStr(iRet), data.DebugString());
                 });
    }
    return 0;
}

int NFStoreServerTest::Test_GetRpcExecuteMoreObjService()
{
    static bool flag = false;
    if (flag == false)
    {
        flag = true;

        int iRet = FindModule<NFIServerMessageModule>()->GetRpcExecuteMoreService
                (NF_ST_LOGIC_SERVER, 0, "select * from tbServerMgr where id < 30",
                 [](int rpcRetCode, std::vector<proto_ff::tbServerMgr> &respone)
                 {
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteMoreService rpcRetCode:{} respone:{}", GetErrorStr(rpcRetCode), respone.size());
                     for(int i = 0; i < (int)respone.size(); i++)
                     {
                         NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteMoreService i:{} data:{}", i, respone[i].DebugString());
                     }
                 }, 10);

        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteMoreService Failed!");
            return 0;
        }

        FindModule<NFICoroutineModule>()->MakeCoroutine
                ([this]()
                 {
                     std::vector<proto_ff::tbServerMgr> data;
                     int iRet = FindModule<NFIServerMessageModule>()->GetRpcExecuteMoreService(NF_ST_LOGIC_SERVER, 0, data,
                                                                                           "select * from tbServerMgr where id >= 30 and id < 60", 20);
                     NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteService rpcRetCode:{} respone:{}", GetErrorStr(iRet), data.size());
                     for(int i = 0; i < (int)data.size(); i++)
                     {
                         NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcExecuteMoreService i:{} data:{}", i, data[i].DebugString());
                     }
                 });
    }
    return 0;
}

