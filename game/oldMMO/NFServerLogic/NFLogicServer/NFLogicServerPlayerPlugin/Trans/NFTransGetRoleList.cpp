// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleList.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleList
//
// -------------------------------------------------------------------------

#include "NFTransGetRoleList.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFICommLogicModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetRoleList, EOT_TRANS_LOGIC_GET_ROLE_LIST, NFTransBase)

NFTransGetRoleList::NFTransGetRoleList(NFIPluginManager* pPluginManager):NFTransPlayerBase(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFTransGetRoleList::~NFTransGetRoleList()
{
}

int NFTransGetRoleList::CreateInit()
{
    SetState(EN_TGRL_INIT);
    return 0;
}

int NFTransGetRoleList::ResumeInit()
{
    return 0;
}

int NFTransGetRoleList::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{

    return 0;
}

int NFTransGetRoleList::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                   uint32_t seq, uint32_t err_code)
{
    return 0;
}