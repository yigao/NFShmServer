// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFLogicCommon/NFLogicError.h"

bool NFCommLogicModule::Awake()
{
    NFError::Instance()->SetSingletonPtr(new NFLogicError());
    return true;
}
