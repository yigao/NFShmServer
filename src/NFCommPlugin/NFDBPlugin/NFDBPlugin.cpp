// -------------------------------------------------------------------------
//    @FileName         :    NFDBPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFDBPlugin
//
// -------------------------------------------------------------------------

#include "NFDBPlugin.h"
#include "NFCMysqlModule.h"
#include "NFCNosqlModule.h"
#include "NFCAsyDBModule.h"
#include "NFCAsyNosqlModule.h"
#include "NFCAsyMysqlModule.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFDBPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFDBPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFDBPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFDBPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFDBPlugin);
}

bool NFDBPlugin::IsDynamicLoad()
{
	return false;
}

void NFDBPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFIMysqlModule, NFCMysqlModule);
    REGISTER_MODULE(m_pObjPluginManager, NFINosqlModule, NFCNosqlModule);
    REGISTER_MODULE(m_pObjPluginManager, NFIAsyDBModule, NFCAsyDBModule);
    REGISTER_MODULE(m_pObjPluginManager, NFIAsyMysqlModule, NFCAsyMysqlModule);
    REGISTER_MODULE(m_pObjPluginManager, NFIAsyNosqlModule, NFCAsyNosqlModule);
}

void NFDBPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFIAsyDBModule, NFCAsyDBModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIMysqlModule, NFCMysqlModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIAsyMysqlModule, NFCAsyMysqlModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIAsyNosqlModule, NFCAsyNosqlModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFINoSqlModule, NFCNoSqlModule);
}
