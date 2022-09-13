// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineUserHashTable.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFOnlineUserHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFOnlineUserMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFOnlineUser.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFOnlineUserMgr, EOT_SNS_ONLINE_USER_HASH_TABLE_ID, NFShmObj)

NFOnlineUserMgr::NFOnlineUserMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

int NFOnlineUserMgr::CreateInit() {
    return 0;
}

int NFOnlineUserMgr::ResumeInit() {
    return 0;
}

NFOnlineUser *NFOnlineUserMgr::Find(uint64_t ullRoleID) {
    return dynamic_cast<NFOnlineUser *>(NFShmMgr::Instance()->GetObjFromHashKey(ullRoleID, EOT_SNS_ONLINE_USER_ID));
}

NFOnlineUser *NFOnlineUserMgr::Insert(uint64_t ullRoleID) {
    NFOnlineUser *pOnlineRole = NULL;
    pOnlineRole = Find(ullRoleID);
    if (pOnlineRole) {
        return pOnlineRole;
    }

    pOnlineRole = dynamic_cast<NFOnlineUser *>(NFShmMgr::Instance()->CreateObj(ullRoleID, EOT_SNS_ONLINE_USER_ID));
    if (!pOnlineRole) {
        NFLogError(NF_LOG_SNS_SERVER_PLUGIN, ullRoleID, "CreateObj online role failed, ullRoleID={} ", ullRoleID);
        return NULL;
    }

    pOnlineRole->SetUserID(ullRoleID);

    return pOnlineRole;
}

int NFOnlineUserMgr::Delete(uint64_t ullRoleID) {
    NFOnlineUser *pOnlineRole = Find(ullRoleID);
    CHECK_EXPR(pOnlineRole, -1, "Find Failed, roleId:{}", ullRoleID);

    NFShmMgr::Instance()->DestroyObj(pOnlineRole);

    return 0;
}

bool NFOnlineUserMgr::IsFull()
{
    return NFOnlineUser::GetUsedCount() >= NFOnlineUser::GetItemCount();
}
