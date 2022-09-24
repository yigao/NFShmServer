// -------------------------------------------------------------------------
//    @FileName         :    NFResDb.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFResDb.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "google/protobuf/message.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFPluginModule/NFObject.h"

//proto_ff_s::RoleInitInfoDesc_s, RoleInitInfoDesc, MAX_ROLE_INIT_INFO_RECORD_NUM
#define IMPL_RES_ARRAY_DESC(DESCCLASSNAME, DESCSTORENAME, DESCNUM) \
    private:\
    NFArray<DESCCLASSNAME, DESCNUM> m_astDesc;\
    public:\
    int GetResNum() const override { return m_astDesc.GetSize();}\
    NFArray<DESCCLASSNAME, DESCNUM>& GetResDesc() { return m_astDesc; }\
    int Initialize() override\
    {\
        m_astDesc.CreateInit();\
        return 0;\
    }\
    int Reload(NFResDB *pDB) override\
    {\
        PrepareReload();\
        int iRetCode = Load( pDB );\
        return iRetCode;\
    }\
    virtual std::string GetFileName() override\
    {\
        return std::string(#DESCSTORENAME);\
    }\
    int Load(NFResDB* pDB) override;\
    int CheckWhenAllDataLoaded() override;\
    int CalcUseRatio() override\
    {\
        return m_astDesc.GetSize() * 100 / m_astDesc.GetMaxSize();\
    }\
    int SaveDescStore() override\
    {\
        if (!IsLoaded()) return 0;\
        for(int i = 0; i < (int)m_astDesc.GetSize(); i++)\
        {\
            if (m_astDesc[i].IsUrgentNeedSave())\
            {\
                auto pb = DESCCLASSNAME::make_pbmsg();\
                m_astDesc[i].write_to_pbmsg(pb);\
                SaveDescStoreToDB(&pb);\
                m_astDesc[i].ClearUrgent();\
            }\
        }\
        return 0;\
    }\
    int InsertDescStore(const DESCCLASSNAME& desc)\
    {\
        auto pb = DESCCLASSNAME::make_pbmsg();\
        desc.write_to_pbmsg(pb);\
        InsertDescStoreToDB(&pb);\
        return 0;\
    }                                                        \
    int DeleteDescStore(const DESCCLASSNAME& desc)\
    {\
        auto pb = DESCCLASSNAME::make_pbmsg();\
        desc.write_to_pbmsg(pb);\
        DeleteDescStoreToDB(&pb);\
        return 0;\
    }\




#define IMPL_RES_HASH_DESC(DESCCLASSNAME, DESCSTORENAME, DESCNUM) \
    private:\
    NFShmHashMap<uint64_t, DESCCLASSNAME, DESCNUM> m_astDesc;\
    public:\
    int GetResNum() const { return m_astDesc.GetUsedNum();}\
    NFShmHashMap<uint64_t, DESCCLASSNAME, DESCNUM>& GetResDesc() { return m_astDesc; }\
    int Initialize()\
    {                                                        \
        m_astDesc.CreateInit();\
        return 0;\
    }\
    int Reload(NFResDB *pDB)\
    {\
        PrepareReload();\
        int iRetCode = Load( pDB );\
        return iRetCode;\
    }\
    virtual std::string GetFileName() override\
    {\
        return std::string(#DESCSTORENAME);\
    }\
    int Load(NFResDB* pDB);\
    int CheckWhenAllDataLoaded();\
    int CalcUseRatio()\
    {\
        return m_astDesc.GetUsedNum() * 100 / m_astDesc.GetSize();\
    }\
    int SaveDescStore()\
    {\
        if (!IsLoaded()) return 0;\
        for(int i = 0; i < (int)m_astDesc.GetSize(); i++)\
        {\
            auto pDesc = m_astDesc.GetByIndex(i);\
            if (pDesc != NULL && pDesc->IsUrgentNeedSave())\
            {\
                auto pb = DESCCLASSNAME::make_pbmsg();\
                pDesc->write_to_pbmsg(pb);\
                SaveDescStoreToDB(&pb);\
                pDesc->ClearUrgent();\
            }\
        }\
        return 0;\
    }\
    int InsertDescStore(const DESCCLASSNAME& desc)\
    {\
        auto pb = DESCCLASSNAME::make_pbmsg();\
        desc.write_to_pbmsg(pb);\
        InsertDescStoreToDB(&pb);\
        return 0;\
    }                                                        \
    int DeleteDescStore(const DESCCLASSNAME& desc)\
    {\
        auto pb = DESCCLASSNAME::make_pbmsg();\
        desc.write_to_pbmsg(pb);\
        DeleteDescStoreToDB(&pb);\
        return 0;\
    }                                                        \


#define IMPL_RES_SIMPLE_DESC(DESCSTORENAME) \
    private:\
	int GetResNum() const {return 0;}\
    int Initialize()\
    {\
        return 0;\
    }\
    int Reload(NFResDB *pDB)\
    {\
        PrepareReload();\
        Initialize();\
        int iRetCode = Load( pDB );\
        return iRetCode;\
    }\
    virtual std::string GetFileName() override\
    {\
        return std::string(#DESCSTORENAME);\
    }\
    int Load(NFResDB* pDB);\
    int CheckWhenAllDataLoaded();\
    int CalcUseRatio()\
    {\
        return 0;\
    }                                       \
    int SaveDescStore()\
    {\
        return 0;\
    }\

#define MAX_MD5_STR_LEN  33
#define MAX_DESC_FILE_PATH_STR_LEN  512
const int MAX_DESC_NAME_LEN = 64;

enum
{
	DESC_CHECK_FATAL = -1000,
};

class NFResTable : public NFObject
{
public:
    NFResTable(NFIPluginManager* p):NFObject(p) {}
    virtual ~NFResTable() {}

	virtual int FindAllRecord(const std::string &serverId, google::protobuf::Message *pMessage) = 0;
    virtual int FindOneRecord(const std::string &serverId, google::protobuf::Message *pMessage) = 0;
    virtual int SaveOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) = 0;
    virtual int InsertOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) = 0;
    virtual int DeleteOneRecord(const std::string &serverId, const google::protobuf::Message *pMessage) = 0;
};

class NFResDB : public NFObject
{
public:
    NFResDB(NFIPluginManager* p):NFObject(p) {}
	virtual ~NFResDB() {}

	/**从数据库里取得一个资源表
	*@param[in] pname 资源表的名字， 必须和资源结构说明文件里面的结构名字， 以及数据库中table名字一致
	*@retval ==NULL 没有这个资源表
	*@retval !=NULL 资源表的指针
	*/
	virtual NFResTable *GetTable(const std::string& name) = 0;
};

