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
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFPluginModule/NFObject.h"

#define NF_MAX_DESC_STORE_INDEX_SIZE 10000

#define CHECK_DESC_RELOADING(DESCSTORENAME) if (DESCSTORENAME::Instance(m_pObjPluginManager)->IsReloading()) return true;

//proto_ff_s::RoleInitInfoDesc_s, RoleInitInfoDesc, MAX_ROLE_INIT_INFO_RECORD_NUM
#define IMPL_RES_ARRAY_DESC(DESCCLASSNAME, DESCSTORENAME, DESCNUM) \
    private:\
    NFShmVector<DESCCLASSNAME, DESCNUM> m_astDesc;                     \
    NFShmVector<int, NF_MAX_DESC_STORE_INDEX_SIZE> m_astDescIndex;\
    public:\
    int GetResNum() const override { return m_astDesc.size();}\
    NFShmVector<DESCCLASSNAME, DESCNUM>& GetResDesc() { return m_astDesc; }\
    int Initialize() override\
    {\
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
        for(int i = 0; i < (int)m_astDesc.size(); i++)\
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
    NFShmVector<DESCCLASSNAME, DESCNUM> m_astDesc;\
    NFShmHashMap<uint64_t, int, DESCNUM> m_astDescMap;\
    NFShmVector<int, NF_MAX_DESC_STORE_INDEX_SIZE> m_astDescIndex;\
    public:\
    virtual int GetResNum() const override { return m_astDesc.size();}\
    NFShmVector<DESCCLASSNAME, DESCNUM>& GetResDesc() { return m_astDesc; }\
    const NFShmVector<DESCCLASSNAME, DESCNUM>& GetResDesc() const { return m_astDesc; } \
    NFShmVector<DESCCLASSNAME, DESCNUM>* GetResDescPtr() { return &m_astDesc; }\
    const NFShmVector<DESCCLASSNAME, DESCNUM>* GetResDescPtr() const { return &m_astDesc; }\
    virtual int Initialize() override\
    {\
        m_astDescIndex.resize(m_astDescIndex.max_size());\
        for(int i = 0; i < (int)m_astDescIndex.size(); i++)\
        {\
            m_astDescIndex[i] = -1;\
        }\
        return 0;\
    }\
    virtual int Reload(NFResDB *pDB) override\
    {\
        PrepareReload();\
        int iRetCode = Load( pDB );\
        return iRetCode;\
    }\
    virtual std::string GetFileName() override\
    {\
        return std::string(#DESCSTORENAME);\
    }\
    virtual int Load(NFResDB* pDB) override;\
    virtual int CheckWhenAllDataLoaded() override;\
    virtual int CalcUseRatio() override\
    {\
        return m_astDesc.size() * 100 / m_astDesc.max_size();\
    }\
    virtual int SaveDescStore() override\
    {\
        if (!IsLoaded()) return 0;\
        for(int i = 0; i < (int)m_astDesc.size(); i++)\
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


#define IMPL_RES_SIMPLE_DESC(DESCSTORENAME) \
    private:\
	virtual int GetResNum() const  override {return 0;}  \
    virtual int Initialize() override\
    {\
        return 0;\
    }\
    virtual int Reload(NFResDB *pDB) override\
    {\
        PrepareReload();\
        int iRetCode = Load( pDB );\
        return iRetCode;\
    }\
    virtual std::string GetFileName() override\
    {\
        return std::string(#DESCSTORENAME);\
    }\
    virtual int Load(NFResDB* pDB) override;\
    virtual int CheckWhenAllDataLoaded() override;\
    virtual int CalcUseRatio() override\
    {\
        return 0;\
    }\
    int SaveDescStore() override\
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

