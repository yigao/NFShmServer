// -------------------------------------------------------------------------
//    @FileName         :    NFIDynamicModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDynamicModule
//
// -------------------------------------------------------------------------


#include "NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"

NFIDynamicModule::NFIDynamicModule(NFIPluginManager* p) :NFIModule(p),NFTimerObj(p),NFEventObj(p)
{

}

NFIDynamicModule::~NFIDynamicModule()
{
	FindModule<NFIMessageModule>()->DelAllCallBack(this);
}

void NFIDynamicModule::OnTimer(uint32_t nTimerID)
{

}

int NFIDynamicModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    return 0;
}
