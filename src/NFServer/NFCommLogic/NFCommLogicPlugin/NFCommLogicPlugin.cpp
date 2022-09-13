// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFCommLogicPlugin.h"
#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFConstDesc.h"
#include "NFNameDesc.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFCommLogicPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFCommLogicPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFCommLogicPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFCommLogicPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFCommLogicPlugin);
}

void NFCommLogicPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFICommLogicModule, NFCommLogicModule)
}

void NFCommLogicPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFICommLogicModule, NFCommLogicModule)
}

bool NFCommLogicPlugin::InitShmObjectRegister()
{
	REGISTER_DESCSTORE(NFConstDesc, EOT_CONST_CONFIG_DESC_ID, NF_DEFAULT_MYSQL_DB_NAME);
    REGISTER_DESCSTORE(NFNameDesc, EOT_NAME_CONFIG_DESC_ID, NF_DEFAULT_MYSQL_DB_NAME);
	return true;
}
