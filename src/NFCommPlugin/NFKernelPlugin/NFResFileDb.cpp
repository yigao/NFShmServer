// -------------------------------------------------------------------------
//    @FileName         :    NFResFileDb.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFResFileDb.cpp
//
// -------------------------------------------------------------------------

#include "NFResFileDb.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include <fstream>
#include "NFComm/NFCore/NFCommon.h"

NFFileResTable::NFFileResTable(NFIPluginManager* p, NFFileResDB* pFileResDB, const std::string& name):NFResTable(p)
{
    m_name = name;
	m_pFileResDB = pFileResDB;
}

int NFFileResTable::FindAllRecord(const std::string &gamePath, google::protobuf::Message *pMessage)
{
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    std::string szFileName = m_pFileResDB->GetPath() + "/" + gamePath + "/" + m_name + ".bin";
    std::fstream input(szFileName.c_str(), std::ios::in | std::ios::binary);
    bool ok = pMessage->ParseFromIstream(&input);
    input.close();

    CHECK_EXPR(ok, -1, "parse error:{} {}", pMessage->InitializationErrorString(), pMessage->DebugString());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "parse file:{} Success", szFileName);

	return 0;
}

int NFFileResTable::FindOneRecord(const std::string &serverId, google::protobuf::Message *pMessage)
{
   return 0;
}

int NFFileResTable::SaveOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) {
    return 0;
}

int NFFileResTable::InsertOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage)
{
    return 0;
}

int NFFileResTable::DeleteOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage)
{
    return 0;
}

NFFileResDB::NFFileResDB(NFIPluginManager* p, const std::string &szResFilePath):NFResDB(p)
{
    m_szResFilePath = szResFilePath;
}

NFResTable *NFFileResDB::GetTable(const std::string &name) {
    auto iter = m_tablesMap.find(name);
    if (iter != m_tablesMap.end()) {
        return iter->second;
    }

    NFFileResTable *pTable = new NFFileResTable(m_pObjPluginManager, this, name);
    m_tablesMap.emplace(name, pTable);
    return pTable;
}