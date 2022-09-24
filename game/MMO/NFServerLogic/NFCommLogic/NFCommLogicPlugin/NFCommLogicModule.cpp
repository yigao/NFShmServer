// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFConstDesc.h"
#include "NFNameDesc.h"

std::string NFCommLogicModule::GetConstValue(proto_ff::enConstType type) const
{
	NFConstDesc* pConstDesc = NFConstDesc::Instance(m_pObjPluginManager);
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

    if (nTimerID == 1)
    {
        //NFConstDesc* pConstDesc = NFConstDesc::Instance(m_pObjPluginManager);
        //auto& resDesc = pConstDesc->GetResDesc();
        //resDesc[0].value = "xxxxx";
        //resDesc[0].MarkDirty();
    }
}

bool NFCommLogicModule::Awake() {
    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    SetTimer(1, 10000, 1);
    return true;
}

std::string NFCommLogicModule::GetRandomName() const
{
    return NFNameDesc::Instance(m_pObjPluginManager)->GetRandomName();
}