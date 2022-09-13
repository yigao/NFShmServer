// -------------------------------------------------------------------------
//    @FileName         :    NFIDescStore.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIDescStore.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFDescStoreDefine.h"
#include "NFShmObj.h"
#include "NFShmMgr.h"
#include "NFIDescStoreModule.h"
#include "NFSizeString.h"
#include <fstream>
#include <iostream>
#include <sstream>

#define REGISTER_DESCSTORE(className, ClassType, dbName)  \
    assert((TIsDerived<className, NFIDescStore>::Result)); \
	NFIPluginManager::Instance()->FindModule<NFIDescStoreModule>()->RegisterDescStore(#className, ClassType, dbName);\
	REGISTER_SINGLETON_SHM_OBJ(className, ClassType, 1)\

class NFIDescStore : public NFShmObj
{
public:
	NFIDescStore()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}

	virtual ~NFIDescStore()
	{
	    if (m_bSaveTimer != INVALID_ID)
        {
            DeleteTimer(m_bSaveTimer);
            m_bSaveTimer = INVALID_ID;
        }
	}

	int CreateInit()
	{
		m_bValid = false;
		m_bIsLoaded = false;
		m_bIsChecked = false;
        m_bSaveTimer = INVALID_ID;
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	virtual int Load(NFResDB *pDB) = 0;
	virtual int Reload(NFResDB *pDB) = 0;
	virtual int CheckWhenAllDataLoaded() = 0;
	virtual int Initialize() = 0;
	virtual int CalcUseRatio() = 0;
	virtual std::string GetFileName() = 0;
	virtual int GetResNum() const = 0;
	virtual int SaveDescStore() = 0;

    virtual int SaveDescStoreToDB(const google::protobuf::Message *pMessage)
    {
        if (!IsFileLoad())
        {
            return FindModule<NFIDescStoreModule>()->SaveDescStoreByFileName(GetDBName(), GetFileName(), pMessage);
        }
        return 0;
    }

    virtual int InsertDescStoreToDB(const google::protobuf::Message *pMessage)
    {
        if (!IsFileLoad())
        {
            return FindModule<NFIDescStoreModule>()->InsertDescStoreByFileName(GetDBName(), GetFileName(), pMessage);
        }
        return 0;
    }

    virtual int DeleteDescStoreToDB(const google::protobuf::Message *pMessage)
    {
        if (!IsFileLoad())
        {
            return FindModule<NFIDescStoreModule>()->DeleteDescStoreByFileName(GetDBName(), GetFileName(), pMessage);
        }
        return 0;
    }

    virtual int StartSaveTimer()
    {
        int rand = NFRandInt(1000, 10000);
        m_bSaveTimer = SetTimer(1*1000, 0, 0, 0, 0, rand);
        return 0;
    }

    //must be virtual
    virtual void OnTimer(int timeId, int callcount)
    {
        if (m_bSaveTimer == timeId)
        {
            SaveDescStore();
        }
    }

	virtual int PrepareReload()
	{
		return 0;
	}
	virtual int Resume()
	{
		return 0;    // recover
	}

	virtual bool IsFileLoad()
    {
	    return false;
    }

	virtual bool IsNeedSpecialCheck()
	{
		return false;
	}

	void SetValid()
	{
		m_bValid = true;
	}
	bool IsValid()
	{
		return m_bValid;
	}

	void SetLoaded(bool bIsLoaded)
	{
		m_bIsLoaded = bIsLoaded;
	}
	bool IsLoaded()
	{
		return m_bIsLoaded;
	}

	void SetChecked(bool bIsChecked)
	{
		m_bIsChecked = bIsChecked;
	}
	bool IsChecked()
	{
		return m_bIsChecked;
	}

	void SetMD5(const std::string& pszMD5)
	{
		m_szMD5 = pszMD5;
	}

	std::string GetMD5()
	{
		return m_szMD5.GetString();
	}

	std::string GetFileMD5()
	{
		return m_szMD5.GetString();
	}

	std::string GetFilePathName()
	{
		return m_filePathName.GetString();
	}

	void SetFilePathName(const std::string& filePath)
	{
		m_filePathName = filePath;
	}

	std::string GetDBName()
    {
        return m_dbName.GetString();
    }

    void SetDBName(const std::string& dbName)
    {
        m_dbName = dbName;
    }
protected:
	bool m_bValid;
	bool m_bIsLoaded;
	bool m_bIsChecked;
	int m_bSaveTimer;
	NFSizeString<MAX_MD5_STR_LEN> m_szMD5;
	NFSizeString<MAX_DESC_FILE_PATH_STR_LEN> m_filePathName;
    NFSizeString<MAX_DESC_NAME_LEN> m_dbName;
};
