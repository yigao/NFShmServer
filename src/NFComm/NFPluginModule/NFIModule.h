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
#include "NFServerDefine.h"
#include "NFObject.h"

class NFIModule : public NFObject
{
public:
	NFIModule(NFIPluginManager* p):NFObject(p)
	{

	}

	virtual ~NFIModule()
	{
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

	std::string m_strName;
};

