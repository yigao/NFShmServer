// -------------------------------------------------------------------------
//    @FileName         :    NFTutorialPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :    24-1-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFTutorialPlugin
//
// -------------------------------------------------------------------------

#include "NFTutorialPlugin.h"

#include "NFTutorialModule.h"
#include "NFTutorialShmObj.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFTutorialPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFTutorialPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFTutorialPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFTutorialPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFTutorialPlugin);
}

void NFTutorialPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFTutorialModule, NFTutorialModule);
}

void NFTutorialPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFTutorialModule, NFTutorialModule);
}

bool NFTutorialPlugin::InitShmObjectRegister()
{
	REGISTER_SINGLETON_SHM_OBJ(NFTutorialShmObj);//
	return true;
}
