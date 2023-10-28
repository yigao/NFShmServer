// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOCommonModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFLogicCommon/NFLogicError.h"
#include "NFLogicCommon/Attr/NFAttrMgr.h"

bool NFMMOCommonModule::Awake()
{
    NFError::Instance()->SetErrorFunction(GetLogicErrorStr);
    Subscribe(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE,
              __FUNCTION__);
    return true;
}

int NFMMOCommonModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    if (nEventID == proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE &&
        nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE)
    {
        NFAttrMgr::Instance(m_pObjPluginManager)->Init();
    }
    return 0;
}