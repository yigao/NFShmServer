// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetail.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFPlayer.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayer, EOT_LOGIC_PLAYER_ID, NFShmObj)

NFPlayer::NFPlayer(NFIPluginManager* pPluginManager):NFShmObj(pPluginManager)
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

NFPlayer::~NFPlayer()
{

}

int NFPlayer::CreateInit()
{
    m_bIsInited = false;
    m_iTransNum = 0;
    return 0;
}

int NFPlayer::ResumeInit()
{
    return 0;
}

int NFPlayer::GetTransNum() const
{
    return m_iTransNum;
}

/**
 * @brief 当前玩家正在使用的trans数量 +1
 */
void NFPlayer::IncreaseTransNum()
{
    m_iTransNum++;
}

/**
 * @brief 当前玩家正在使用的trans数量 -1
 */
void NFPlayer::DecreaseTransNum()
{
    m_iTransNum--;
    if(m_iTransNum < 0)
    {
        m_iTransNum = 0;
    }
}

uint64_t NFPlayer::GetRoleId() const
{
    return m_roleId;
}

void NFPlayer::SetRoleId(uint64_t roleId)
{
    m_roleId = roleId;
}

uint64_t NFPlayer::GetPlayerId() const
{
    return m_playerId;
}

void NFPlayer::SetPlayerId(uint64_t playerId)
{
    m_playerId = playerId;
}
