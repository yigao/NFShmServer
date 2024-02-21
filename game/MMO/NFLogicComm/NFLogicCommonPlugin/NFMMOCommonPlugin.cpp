// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOCommonPlugin.h"
#include "NFMMOCommonModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#include "DescStore/NFDescStoreHead.h"
#include "DescStore/NFDescStoreRegister.h"
#include "NFLogicCommon/Attr/NFAttrMgr.h"
#include "DescStoreEx/NFGrowDescEx.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOCommonPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOCommonPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOCommonPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOCommonPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOCommonPlugin);
}

void NFMMOCommonPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFMMOCommonModule, NFMMOCommonModule)
}

void NFMMOCommonPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFMMOCommonModule, NFMMOCommonModule)
}

bool NFMMOCommonPlugin::InitShmObjectRegister()
{
    ////////init excel load shm///////////////////
    EOT_DESC_STORE_ALL_REGISTER_DEFINE
    
    REGISTER_SINGLETON_SHM_OBJ(NFAttrMgr);//
    REGISTER_DESCSTORE_EX(NFGrowDescEx);
    ///////////////////////////////////////////////
	return true;
}
