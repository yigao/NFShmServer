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
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFConstDesc.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"
#include "NFNameDesc.h"

std::string NFCommLogicModule::GetConstValue(proto_ff::enConstType type) const
{
	NFConstDesc* pConstDesc = NFConstDesc::Instance();
	CHECK_EXPR(pConstDesc, "", "FindDescStore<NFConstDesc>() null, type:{}", type);
	return pConstDesc->GetValue(type);
}

int NFCommLogicModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(10000, 10000, 0);
        }
    }
    return 0;
}

void NFCommLogicModule::OnTimer(uint32_t nTimerID) {
    if (nTimerID == 10000) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

bool NFCommLogicModule::Awake() {
    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    return true;
}

std::string NFCommLogicModule::GetRandomName() const
{
    return NFNameDesc::Instance()->GetRandomName();
}