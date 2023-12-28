// -------------------------------------------------------------------------
//    @FileName         :    NFFishLoginServerPlayerPlugin.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishLoginServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishLoginPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFAccountLoginModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFAccountLoginMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFFishLoginPlayerPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFFishLoginPlayerPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFFishLoginPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishLoginPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishLoginPlayerPlugin);
}

void NFFishLoginPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCAccountLoginModule, NFCAccountLoginModule);
}

void NFFishLoginPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCAccountLoginModule, NFCAccountLoginModule);
}

bool NFFishLoginPlayerPlugin::InitShmObjectRegister()
{
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
	NF_ASSERT(pConfig);

	REGISTER_SINGLETON_SHM_OBJ(NFAccountLoginMgr);
	return true;
}
