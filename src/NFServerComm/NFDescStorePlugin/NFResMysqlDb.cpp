// -------------------------------------------------------------------------
//    @FileName         :    NFResMysqlDb.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFResMysqlDb.cpp
//
// -------------------------------------------------------------------------

#include "NFResMysqlDb.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFIDescStoreModule.h"
#include <fstream>

NFMysqlResTable::NFMysqlResTable(NFIPluginManager* p, NFResMysqlDB* pFileResDB, const std::string& name):NFResTable(p)
{
    m_name = name;
    m_pMysqlResDB = pFileResDB;
}

NFMysqlResTable::~NFMysqlResTable()
{

}

int NFMysqlResTable::FindAllRecord(const std::string &serverId, google::protobuf::Message *pMessage)
{
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    int iRet = 0;
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);
    iRet = FindModule<NFIDescStoreModule>()->GetDescStoreByRpc((NF_SERVER_TYPES)pConfig->ServerType, serverId, m_name, pMessage);
	CHECK_EXPR(iRet == 0, iRet, "GetDescStoreByRpc Failed! iRet:{}", GetErrorStr(iRet));

    return 0;
}

int NFMysqlResTable::FindOneRecord(const std::string &serverId, google::protobuf::Message *pMessage)
{
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");
    return 0;
}

int NFMysqlResTable::InsertOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage)
{
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    std::string tempDBName = serverId;
    if (serverId.empty())
    {
        tempDBName = pConfig->DefaultDBName;
    }
    CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");

    return FindModule<NFIServerMessageModule>()->SendTransToStoreServer((NF_SERVER_TYPES)pConfig->ServerType, 0,
                                                                        proto_ff::NF_STORESVR_C2S_INSERT, 0, tempDBName, m_name, *pMessage, 0, 0, std::hash<std::string>()(m_name), pMessage->GetDescriptor()->name());
}

int NFMysqlResTable::DeleteOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage)
{
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    std::string tempDBName = serverId;
    if (serverId.empty())
    {
        tempDBName = pConfig->DefaultDBName;
    }
    CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");

    return FindModule<NFIServerMessageModule>()->SendTransToStoreServer((NF_SERVER_TYPES)pConfig->ServerType, 0,
                                                                        proto_ff::NF_STORESVR_C2S_DELETEOBJ, 0, tempDBName, m_name, *pMessage, 0, 0, std::hash<std::string>()(m_name), pMessage->GetDescriptor()->name());
}

int NFMysqlResTable::SaveOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) {
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    std::string tempDBName = serverId;
    if (serverId.empty())
    {
        tempDBName = pConfig->DefaultDBName;
    }
    CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");

    return FindModule<NFIServerMessageModule>()->SendTransToStoreServer((NF_SERVER_TYPES)pConfig->ServerType, 0,
                                                                        proto_ff::NF_STORESVR_C2S_UPDATEOBJ, 0, tempDBName, m_name, *pMessage, 0, 0, std::hash<std::string>()(m_name), pMessage->GetDescriptor()->name());
}

NFResMysqlDB::NFResMysqlDB(NFIPluginManager* p):NFResDB(p)
{
}

NFResMysqlDB::~NFResMysqlDB()
{
    for(auto iter = m_tablesMap.begin(); iter != m_tablesMap.end(); iter++)
    {
        if (iter->second)
        {
            NF_SAFE_DELETE(iter->second);
        }
    }
    m_tablesMap.clear();
}

NFResTable *NFResMysqlDB::GetTable(const std::string &name) {
    auto iter = m_tablesMap.find(name);
    if (iter != m_tablesMap.end()) {
        return iter->second;
    }

    NFMysqlResTable *pTable = new NFMysqlResTable(m_pObjPluginManager, this, name);
    m_tablesMap.emplace(name, pTable);
    return pTable;
}

