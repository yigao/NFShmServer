// -------------------------------------------------------------------------
//    @FileName         :    NFIDescStoreModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIDescStoreModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFShmMgr.h"
#include "google/protobuf/message.h"

class NFIDescStore;
class NFIDescStoreModule : public NFIModule
{
public:
    NFIDescStoreModule(NFIPluginManager* p):NFIModule(p)
    {

    }

    virtual ~NFIDescStoreModule()
    {

    }

	virtual void RegisterDescStore(const std::string& strClassName, int objType, const std::string& dbName) = 0;

    virtual int InitDestStoreDB(const std::string &serverId, const std::string& hostip, int port, const std::string& dbname, const std::string& user, const std::string& pass) = 0;

	virtual int Initialize() = 0;

    virtual int LoadDestSotre() = 0;

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
};