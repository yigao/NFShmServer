// -------------------------------------------------------------------------
//    @FileName         :    NFResMysqlDb.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFResMysqlDb.cpp
//
// -------------------------------------------------------------------------

#include "NFResMysqlDb.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include <fstream>

NFMysqlResTable::NFMysqlResTable(NFResMysqlDB* pFileResDB, const std::string& name)
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

    int64_t coId = NFCoMgr::Instance()->CurrentTaskId();
    int iRet = 0;
    {
        NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
        CHECK_NULL(pConfig);

        iRet = NFMessageMgr::Instance()->SendDescStoreToStoreServer((NF_SERVER_TYPES)pConfig->mServerType, serverId, m_name, pMessage,
            [coId, pMessage](int iRet, google::protobuf::Message &message){
            if (iRet != 0) {
                NFCoMgr::Instance()->Resume(coId, iRet);
            }
            else {
                pMessage->CopyFrom(message);
                NFCoMgr::Instance()->Resume(coId);
            }
        });
    }

	CHECK_EXPR(iRet == 0, -1, "QueryDescStore Failed!");

	iRet = NFCoMgr::Instance()->Yield();

	CHECK_EXPR(iRet == 0, -1, "parse error:{} {}", pMessage->InitializationErrorString(), pMessage->DebugString());

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

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    return NFMessageMgr::Instance()->SendTransToStoreServer((NF_SERVER_TYPES)pConfig->mServerType,
                                                            proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_NONE, serverId, m_name, *pMessage, 0, 0, std::hash<std::string>()(m_name), pMessage->GetDescriptor()->name());
}

int NFMysqlResTable::DeleteOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage)
{
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    return NFMessageMgr::Instance()->SendTransToStoreServer((NF_SERVER_TYPES)pConfig->mServerType,
            proto_ff::E_STORESVR_C2S_DELETEOBJ, proto_ff::E_TABLE_NONE, serverId, m_name, *pMessage, 0, 0, std::hash<std::string>()(m_name), pMessage->GetDescriptor()->name());
}

int NFMysqlResTable::SaveOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) {
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    return NFMessageMgr::Instance()->SendTransToStoreServer((NF_SERVER_TYPES)pConfig->mServerType,
                                                            proto_ff::E_STORESVR_C2S_MODINSOBJ, proto_ff::E_TABLE_NONE, serverId, m_name, *pMessage, 0, 0, std::hash<std::string>()(m_name), pMessage->GetDescriptor()->name());
}

NFResMysqlDB::NFResMysqlDB()
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

    NFMysqlResTable *pTable = new NFMysqlResTable(this, name);
    m_tablesMap.emplace(name, pTable);
    return pTable;
}

