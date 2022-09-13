// -------------------------------------------------------------------------
//    @FileName         :    NFKernelPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFKernelPlugin.h"
#include "NFCommPlugin/NFKernelPlugin/NFCKernelModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCTimerModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCEventModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCLogModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCConfigModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFConsoleModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFMonitorModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCMessageModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCCoroutineModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCMysqlModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCTaskModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCAsyMysqlModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFCNamingModule.h"
#include "NFComm/NFShmCore/NFDescStoreTrans.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFCommPlugin/NFKernelPlugin/NFCNoSqlModule.h"

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
	REGISTER_MODULE(m_pPluginManager, NFILogModule, NFCLogModule);
	REGISTER_MODULE(m_pPluginManager, NFIConfigModule, NFCConfigModule);
	REGISTER_MODULE(m_pPluginManager, NFITimerModule, NFCTimerModule);
	REGISTER_MODULE(m_pPluginManager, NFIEventModule, NFCEventModule);
	REGISTER_MODULE(m_pPluginManager, NFIKernelModule, NFCKernelModule);
	REGISTER_MODULE(m_pPluginManager, NFIMonitorModule, NFCMonitorModule);
	REGISTER_MODULE(m_pPluginManager, NFIConsoleModule, NFCConsoleModule);
	REGISTER_MODULE(m_pPluginManager, NFIMessageModule, NFCMessageModule);
    REGISTER_MODULE(m_pPluginManager, NFICoroutineModule, NFCCoroutineModule);
    REGISTER_MODULE(m_pPluginManager, NFIMysqlModule, NFCMysqlModule);
	REGISTER_MODULE(m_pPluginManager, NFIAsyMysqlModule, NFCAsyMysqlModule);
    //REGISTER_MODULE(m_pPluginManager, NFINoSqlModule, NFCNoSqlModule);
	REGISTER_MODULE(m_pPluginManager, NFITaskModule, NFCTaskModule);
    REGISTER_MODULE(m_pPluginManager, NFINamingModule, NFCNamingModule);
}

void NFKernelPlugin::Uninstall()
{

	UNREGISTER_MODULE(m_pPluginManager, NFIMonitorModule, NFCMonitorModule);
	UNREGISTER_MODULE(m_pPluginManager, NFIConsoleModule, NFCConsoleModule);
	UNREGISTER_MODULE(m_pPluginManager, NFIKernelModule, NFCKernelModule);
	UNREGISTER_MODULE(m_pPluginManager, NFIEventModule, NFCEventModule);
	UNREGISTER_MODULE(m_pPluginManager, NFITimerModule, NFCTimerModule);
	UNREGISTER_MODULE(m_pPluginManager, NFILogModule, NFCLogModule);
	UNREGISTER_MODULE(m_pPluginManager, NFIConfigModule, NFCConfigModule);
	UNREGISTER_MODULE(m_pPluginManager, NFIMessageModule, NFCMessageModule);
    UNREGISTER_MODULE(m_pPluginManager, NFICoroutineModule, NFCCoroutineModule);

    UNREGISTER_MODULE(m_pPluginManager, NFIMysqlModule, NFCMysqlModule);
	UNREGISTER_MODULE(m_pPluginManager, NFIAsyMysqlModule, NFCAsyMysqlModule);
    //UNREGISTER_MODULE(m_pPluginManager, NFINoSqlModule, NFCNoSqlModule);
	UNREGISTER_MODULE(m_pPluginManager, NFITaskModule, NFCTaskModule);
    UNREGISTER_MODULE(m_pPluginManager, NFINamingModule, NFCNamingModule);
}

bool NFKernelPlugin::InitShmObjectRegister()
{
	return true;
}
