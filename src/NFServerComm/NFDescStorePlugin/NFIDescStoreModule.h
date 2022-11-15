// -------------------------------------------------------------------------
//    @FileName         :    NFIDescStoreModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDescStoreModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "google/protobuf/message.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIDescStore;
class NFIDescStoreModule : public NFIDynamicModule
{
public:
    NFIDescStoreModule(NFIPluginManager* p):NFIDynamicModule(p)
    {

    }

    virtual ~NFIDescStoreModule()
    {

    }

	virtual void RegisterDescStore(const std::string& strClassName, int objType, const std::string& dbName) = 0;

    virtual void RegisterDescStore(const std::string& strClassName, int objType) = 0;

    virtual int InitDestStoreDB(const std::string &serverId, const std::string& hostip, int port, const std::string& dbname, const std::string& user, const std::string& pass) = 0;

	virtual NFIDescStore* FindDescStore(const std::string& strDescName) = 0;

	virtual NFIDescStore* FindDescStoreByFileName(const std::string& strDescName) = 0;

	virtual bool IsAllDescStoreLoad() = 0;

	template <typename T>
	T* FindDescStore()
	{
		NFIDescStore* pDescStore = FindDescStore(typeid(T).name());
		if (pDescStore)
		{
			if (!TIsDerived<T, NFIDescStore>::Result)
			{
				return nullptr;
			}
			//TODO OSX上dynamic_cast返回了NULL
#if NF_PLATFORM == NF_PLATFORM_APPLE
			T* pT = (T*)pDescStore;
#else
			T* pT = dynamic_cast<T*>(pDescStore);
#endif
			return pT;
		}
		return nullptr;
	}

    virtual int SaveDescStoreByFileName(const std::string& dbName, const std::string& strDescName, const google::protobuf::Message *pMessage) = 0;
    virtual int InsertDescStoreByFileName(const std::string& dbName, const std::string& strDescName, const google::protobuf::Message *pMessage) = 0;
    virtual int DeleteDescStoreByFileName(const std::string& dbName, const std::string& strDescName, const google::protobuf::Message *pMessage) = 0;

public:
    virtual int SendDescStoreToStoreServer(NF_SERVER_TYPES eType, const std::string& dbName, const std::string &table_name, const google::protobuf::Message *pMessage, const QueryDescStore_CB& cb) = 0;
};