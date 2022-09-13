// -------------------------------------------------------------------------
//    @FileName         :    NFTestPlugin.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
