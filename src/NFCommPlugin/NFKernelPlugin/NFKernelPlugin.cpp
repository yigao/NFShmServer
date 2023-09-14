// -------------------------------------------------------------------------
//    @FileName         :    NFKernelPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFKernelPlugin.h"
#include "NFCKernelModule.h"
#include "NFCTimerModule.h"
#include "NFCEventModule.h"
#include "NFCLogModule.h"
#include "NFCConfigModule.h"
#include "NFConsoleModule.h"
#include "NFMonitorModule.h"
#include "NFCMessageModule.h"
#include "NFCCoroutineModule.h"
#include "NFCTaskModule.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFKernelPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFKernelPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFKernelPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFKernelPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFKernelPlugin);
}

bool NFKernelPlugin::IsDynamicLoad()
{
	return false;
}

void NFKernelPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFILogModule, NFCLogModule);
	REGISTER_MODULE(m_pObjPluginManager, NFIConfigModule, NFCConfigModule);
	REGISTER_MODULE(m_pObjPluginManager, NFITimerModule, NFCTimerModule);
	REGISTER_MODULE(m_pObjPluginManager, NFIEventModule, NFCEventModule);
	REGISTER_MODULE(m_pObjPluginManager, NFIKernelModule, NFCKernelModule);
	REGISTER_MODULE(m_pObjPluginManager, NFIMonitorModule, NFCMonitorModule);
	REGISTER_MODULE(m_pObjPluginManager, NFIConsoleModule, NFCConsoleModule);
	REGISTER_MODULE(m_pObjPluginManager, NFIMessageModule, NFCMessageModule);
    REGISTER_MODULE(m_pObjPluginManager, NFICoroutineModule, NFCCoroutineModule);
	REGISTER_MODULE(m_pObjPluginManager, NFITaskModule, NFCTaskModule);
}

void NFKernelPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFICoroutineModule, NFCCoroutineModule);
	UNREGISTER_MODULE(m_pObjPluginManager, NFITaskModule, NFCTaskModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIMonitorModule, NFCMonitorModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIConsoleModule, NFCConsoleModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIKernelModule, NFCKernelModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIMessageModule, NFCMessageModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIEventModule, NFCEventModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFITimerModule, NFCTimerModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFILogModule, NFCLogModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIConfigModule, NFCConfigModule);
}

bool NFKernelPlugin::InitShmObjectRegister()
{
	return true;
}
