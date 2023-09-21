// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Desk.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Desk
//
// -------------------------------------------------------------------------

#include "NFGameFishDesk.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameFishDesk, EOT_NFGameFish2004Desk_ID, NFShmObj)

NFGameFishDesk::NFGameFishDesk()
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

NFGameFishDesk::~NFGameFishDesk()
{
}

int NFGameFishDesk::CreateInit()
{
    return 0;
}

int NFGameFishDesk::ResumeInit()
{
    return 0;
}

int NFGameFishDesk::UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s *pPlayerDetail)
{
    return 0;
}

int NFGameFishDesk::ClearJiangChi()
{
    return 0;
}

int NFGameFishDesk::ChangeJiangChi(int64_t jiangchi)
{
    return 0;
}

int NFGameFishDesk::OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet)
{
    return 0;
}

int NFGameFishDesk::OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet)
{
    return 0;
}

bool NFGameFishDesk::IsPlayGame(int iDeskStation)
{
    return false;
}

bool NFGameFishDesk::IsPlayGameCanLeave(int iDeskStation)
{
    return NFIGameDeskImpl::IsPlayGameCanLeave(iDeskStation);
}

bool NFGameFishDesk::IsGamePlayerReady(uint64_t playerId)
{
    return NFIGameDeskImpl::IsGamePlayerReady(playerId);
}
