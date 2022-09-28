// -------------------------------------------------------------------------
//    @FileName         :    NFCDescStoreModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCDescStoreModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIDescStoreModule.h"
#include "NFIDescStore.h"
#include "NFComm/NFPluginModule/NFEventObj.h"
#include <unordered_map>

class NFCDescStoreModule : public NFIDescStoreModule, public NFEventObj
{
public:
	NFCDescStoreModule(NFIPluginManager* p);
	virtual ~NFCDescStoreModule();

    virtual bool AfterInitShmMem() override;

	virtual bool Awake() override;

    virtual bool Execute() override;

	virtual bool OnReloadPlugin() override;

	virtual void RegisterDescStore(const std::string& strClassName, int objType, const std::string& dbName) override;
    virtual void RegisterDescStore(const std::string& strClassName, int objType) override;

	virtual NFIDescStore* FindDescStore(const std::string& strDescName) override;

    virtual NFIDescStore* FindDescStoreByFileName(const std::string& strDescName) override;

	virtual int InitDestStoreDB(const std::string &serverId, const std::string& hostip, int port, const std::string& dbname, const std::string& user, const std::string& pass) override;

	virtual int Initialize();

	virtual int LoadFileDestSotre();
    virtual int LoadDBDestSotre();

	virtual void AddDescStore(const std::string& strDescName, NFIDescStore* pDesc);

	virtual void RemoveDescStore(const std::string& strDescName);

    virtual int InsertDescStoreByFileName(const std::string& dbName, const std::string& strDescName, const google::protobuf::Message *pMessage) override;
    virtual int DeleteDescStoreByFileName(const std::string& dbName, const std::string& strDescName, const google::protobuf::Message *pMessage) override;;
    virtual int SaveDescStoreByFileName(const std::string& dbName, const std::string& strDescName, const google::protobuf::Message *pMessage) override;;

	virtual void InitAllDescStore();

	virtual int InitDescStore(const std::string& descClass, NFIDescStore* pDescStore);
	virtual int ExtraInitializeWhenRecover();

    virtual int LoadFile();
    virtual int LoadDB();
	virtual int Reload();

	virtual bool IsAllDescStoreLoad() override;;

	int LoadDescStore(NFIDescStore *pDescStore);
	int ReLoadDescStore(NFIDescStore *pDescStore);

	virtual int CheckWhenAllDataLoaded();

	int GetFileContainMD5(const std::string& strFileName, std::string& fileMd5);

    NFResDB *CreateResDBFromRealDB();

    NFResDB *CreateResDBFromFiles(const std::string& dir);

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message) override;

    virtual void runAfterShmInit();
public:
    virtual int SendDescStoreToStoreServer(NF_SERVER_TYPES eType, const std::string& dbName, const std::string &table_name, const google::protobuf::Message *pMessage, const QueryDescStore_CB& cb) override;
private:
	std::unordered_map<std::string, NFIDescStore*> mDescStoreMap;
    std::unordered_map<std::string, NFIDescStore*> mDescStoreFileMap;
	std::unordered_map<std::string, int> mDescStoreRegister;
	std::unordered_map<std::string, std::string> mDescStoreDBNameMap;
    NFResDB* m_pResFileDB;
    NFResDB* m_pResSqlDB;
    bool m_bStartInit;
    bool m_bFinishAllLoaded;
};
