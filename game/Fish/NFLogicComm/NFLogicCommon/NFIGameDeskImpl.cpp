// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDeskImpl.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameDeskImpl
//
// -------------------------------------------------------------------------

#include "NFIGameDeskImpl.h"
#include "NFLogicShmTypeDefines.h"

NFIGameDeskImpl::NFIGameDeskImpl()
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

NFIGameDeskImpl::~NFIGameDeskImpl()
{
}

int NFIGameDeskImpl::CreateInit()
{
    return 0;
}

int NFIGameDeskImpl::ResumeInit()
{
    return 0;
}

int NFIGameDeskImpl::Init(NFIGameDesk* pGameHandle, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum)
{
    m_deskHandle = pGameHandle;
    m_gameId = gameId;
    m_roomId = roomId;
    m_deskId = deskId;
    m_siteNum = sitNum;
    m_maxUserNum = maxUserNum;
    return 0;
}
