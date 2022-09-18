// -------------------------------------------------------------------------
//    @FileName         :    NFTestPlugin.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestPlugin
//
// -------------------------------------------------------------------------
///
#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFTestPlugin : public NFIPlugin
{
public:
	explicit NFTestPlugin(NFIPluginManager* p):NFIPlugin(p)
	{

	}

	virtual int GetPluginVersion();

	virtual std::string GetPluginName();

	virtual void Install();

	virtual void Uninstall();
};
