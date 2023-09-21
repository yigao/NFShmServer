// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Desk.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Desk
//
// -------------------------------------------------------------------------

#include "NFGameFish2004Desk.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameFish2004Desk, EOT_NFGameFish2004Desk_ID, NFShmObj)

NFGameFish2004Desk::NFGameFish2004Desk()
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

NFGameFish2004Desk::~NFGameFish2004Desk()
{
}

int NFGameFish2004Desk::CreateInit()
{
    return 0;
}

int NFGameFish2004Desk::ResumeInit()
{
    return 0;
}

int NFGameFish2004Desk::UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFish2004Desk::UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFish2004Desk::UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFish2004Desk::UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFish2004Desk::UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFish2004Desk::UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFish2004Desk::UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s *pPlayerDetail)
{
    return 0;
}

int NFGameFish2004Desk::ClearJiangChi()
{
    return 0;
}

int NFGameFish2004Desk::ChangeJiangChi(int64_t jiangchi)
{
    return 0;
}

int NFGameFish2004Desk::OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet)
{
    return 0;
}

int NFGameFish2004Desk::OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet)
{
    return 0;
}

bool NFGameFish2004Desk::IsPlayGame(int iDeskStation)
{
    return false;
}

bool NFGameFish2004Desk::IsPlayGameCanLeave(int iDeskStation)
{
    return NFIGameDeskImpl::IsPlayGameCanLeave(iDeskStation);
}

bool NFGameFish2004Desk::IsGamePlayerReady(uint64_t playerId)
{
    return NFIGameDeskImpl::IsGamePlayerReady(playerId);
}
