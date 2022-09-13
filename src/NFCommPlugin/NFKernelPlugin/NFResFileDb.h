// -------------------------------------------------------------------------
//    @FileName         :    NFResFileDb.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFResFileDb.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFResDb.h"
#include <unordered_map>

const int C_READBUFFSIZE_MAX = 1024 * 1024 * 50;

class NFFileResDB;

class NFFileResTable : public NFResTable
{
public:
	NFFileResTable(NFFileResDB* pFileResDB, const std::string& name);
	const std::string& GetName() { return m_name; }
    virtual int FindAllRecord(const std::string &serverId, google::protobuf::Message *pMessage) override;
    virtual int SaveOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) override;
    virtual int FindOneRecord(const std::string &serverId, google::protobuf::Message *pMessage) override;
    virtual int InsertOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) override;
    virtual int DeleteOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) override;
private:
	std::string m_name;
	NFFileResDB* m_pFileResDB;
};

class NFFileResDB : public NFResDB
{
public:
	NFFileResDB(const std::string& szResFilePath);
	virtual NFResTable *GetTable(const std::string& name);
	const std::string& GetPath() { return m_szResFilePath; }
private:
	std::unordered_map<std::string, NFFileResTable*> m_tablesMap;
	std::string m_szResFilePath;
};
