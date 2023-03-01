// -------------------------------------------------------------------------
//    @FileName         :    NFMovePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFMovePart
//
// -------------------------------------------------------------------------

#include "NFMovePart.h"
#include "ClientServerCmd.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMovePart, EOT_NFMovePart_ID, NFBattlePart)

NFMovePart::NFMovePart()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFMovePart::~NFMovePart()
{
}

int NFMovePart::CreateInit()
{
    m_lastclientMoveTick = 0;
    m_moveTimerFlag = false;
    m_moveTick = 0;
    m_waitLoadMapId = 0;
    return 0;
}

int NFMovePart::ResumeInit()
{
    return 0;
}

int NFMovePart::Init(NFCreature *pMaster, uint32_t partType, const proto_ff::RoleEnterSceneData &data)
{
    return 0;
}

int NFMovePart::UnInit()
{
    return 0;
}

int NFMovePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_MOVE_REQ:
        {
            ClientMoveReq(msgId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_masterCid, "msgId:{} Not Handle", msgId);
            break;
        }
    }
    return 0;
}

int NFMovePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFBattlePart::OnHandleServerMessage(msgId, packet);
}

int NFMovePart::RetisterClientMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMovePart::RetisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMovePart::ClientMoveReq(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}
