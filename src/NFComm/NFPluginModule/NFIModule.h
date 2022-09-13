// -------------------------------------------------------------------------
//    @FileName         :    NFIModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFIModule
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include "NFIPluginManager.h"

class NFIModule
{
public:
	NFIModule(NFIPluginManager* p)
	{
		m_pPluginManager = p;
		NF_ASSERT_MSG(m_pPluginManager != NULL, "m_pPluginManager == nullptr")
	}

	virtual ~NFIModule()
	{
	}

	template <typename T>
	T* FindModule() const
	{
		if (m_pPluginManager)
		{
			return m_pPluginManager->FindModule<T>();
		}
		return nullptr;
	}

	virtual bool AfterLoadAllPlugin()
    {
	    return true;
    }

	virtual bool Awake()
	{
		return true;
	}

	virtual bool Init()
	{
        return true;
	}

	virtual bool CheckConfig()
	{
		return true;
	}

	virtual bool ReadyExecute()
	{
		return true;
	}

	virtual bool Execute()
	{
		return true;
	}

	virtual bool BeforeShut()
	{
		return true;
	}

	virtual bool Shut()
	{
		return true;
	}

	virtual bool Finalize()
	{
		return true;
	}

	virtual bool OnReloadPlugin()
	{
		return true;
	}

	virtual bool OnDynamicPlugin()
	{
		return true;
	}

	virtual NFIPluginManager* GetPluginManager() const
	{
		return m_pPluginManager;
	}

	std::string strName;
protected:
	NFIPluginManager* m_pPluginManager = NULL;
};

