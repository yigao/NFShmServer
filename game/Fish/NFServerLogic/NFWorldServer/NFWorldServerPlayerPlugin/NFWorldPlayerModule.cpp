// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerModule.h"

#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p) {

}

NFCWorldPlayerModule::~NFCWorldPlayerModule() {
}

bool NFCWorldPlayerModule::Awake() {
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    //////////player enter game////////////////////////////////////
    return true;
}

bool NFCWorldPlayerModule::Execute()
{
	return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
	return true;
}


