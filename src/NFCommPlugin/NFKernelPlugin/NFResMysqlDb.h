// -------------------------------------------------------------------------
//    @FileName         :    NFResMysqlDb.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFResMysqlDb.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFResDb.h"
#include <unordered_map>

class NFResMysqlDB;

class NFMysqlResTable : public NFResTable
{
public:
    NFMysqlResTable(NFResMysqlDB* pFileResDB, const std::string& name);
    virtual ~NFMysqlResTable();
    const std::string& GetName() { return m_name; }
    virtual int FindAllRecord(const std::string &serverId, google::protobuf::Message *pMessage) override;
    virtual int SaveOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) override;
    virtual int FindOneRecord(const std::string &serverId, google::protobuf::Message *pMessage) override;
    virtual int InsertOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) override;
    virtual int DeleteOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) override;
private:
    std::string m_name;
    NFResMysqlDB* m_pMysqlResDB;
};

class NFResMysqlDB : public NFResDB
{
public:
    NFResMysqlDB();
    virtual ~NFResMysqlDB();
    virtual NFResTable *GetTable(const std::string& name);
private:
    std::unordered_map<std::string, NFMysqlResTable*> m_tablesMap;
};