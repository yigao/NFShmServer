// -------------------------------------------------------------------------
//    @FileName         :    NFGameFishPlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFishPlayer
//
// -------------------------------------------------------------------------

#include "NFGameFishPlayer.h"
#include "NFGameFishDefine.h"
#include "DescStore/FishGunvalueDesc.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "CSFish.pb.h"


NFGameFishPlayer::NFGameFishPlayer() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGameFishPlayer::~NFGameFishPlayer()
{

}


int NFGameFishPlayer::CreateInit() {
    ResetPlayerData();
    return 0;
}

void NFGameFishPlayer::ResetPlayerData()
{
    m_online = false;
    m_ready = false;
    m_ullPlayerId = 0;
    m_uChairId = INVALID_ID;
    m_iGameId = 0;
    m_iRoomId = 0;
    m_iDeskId = INVALID_ID;
    m_isRobot = false;
    m_iDoubleGunValueOnOff = 0;
    m_iIndex = 0;
    m_lastDisconnectTime = 0;

    //todo:从接口或配置获取
    m_nCurBulletLevel = 1;

    m_lastSaveUserMoney = 0;

    m_uLockOnOff = 0;
    m_uLockFishId = 0;
    m_uAutoShootOnOff = 0;
    m_iBulletSpeedLev = 0;
    m_BulletMgr.CreateInit();

    m_iUserChangedTotalShootMoney = 0;
    m_iUserChangedTotalCaptureMoney = 0;
}


int NFGameFishPlayer::ResumeInit()
{
    return 0;
}

uint64_t NFGameFishPlayer::GetCurMoney()
{
    CHECK_EXPR(GetDesk(), 0, "m_pDesk == NULL");
    return GetDesk()->GetPlayerCurMoney(m_ullPlayerId);
}

int NFGameFishPlayer::ShootBullet(NFFishBullet& bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShootBullet() ==========> bullet.m_iBulletLevel = {} , m_nCurBulletLevel = {}", bullet.m_iBulletLevel, m_nCurBulletLevel);
    CHECK_NULL(m_pShmObj);

    auto pGunValue = FishGunvalueDesc::Instance()->GetDescByGameidRoomidGunid(m_iGameId, m_iRoomId, m_nCurBulletLevel);
    CHECK_EXPR(pGunValue, -1, "GetDescByGameidRoomidGunid Failed, gameId:{} roomId:{} gunId:{}", m_iGameId, m_iRoomId, m_nCurBulletLevel);

    int nShootMoneyCount = pGunValue->m_value;
    CHECK_EXPR(nShootMoneyCount > 0, -1, "nShootMoneyCount:{} error", nShootMoneyCount);

    bullet.SetBulletMoney(nShootMoneyCount);

    if (bullet.m_uBulletType != eBulletType_Free)
    {
        if (GetCurMoney() < (uint64_t)nShootMoneyCount)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player cur money is not enough, curShootMoney:{} need money:{}",
                      GetCurMoney(), nShootMoneyCount);
            return -1;
        }

        if (GetDoubeGunValueOn() == 1)
        {
            bullet.m_uBulletType = eBulletType_Double;//双倍炮，在这里不能改变炮值，在算分的地方再乘2；
        }

        AddUserChangedTotalShootMoney(nShootMoneyCount);
        GetDesk()->DeduceGameMoney(m_ullPlayerId, nShootMoneyCount);

        GameDataCommit(0, nShootMoneyCount, nShootMoneyCount);
        SendUserMoney();
    }
    else
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShootBullet() ==========> freeBullet !!!");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShootBullet() ==========>bullet.m_iAngle = {}, bullet.m_iBulletLevel = {} , bullet.BulletMoney() = {}", bullet.m_iAngle, bullet.m_iBulletLevel, bullet.GetBulletMoney());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShootBullet() ==========> m_uChairId = {}", m_uChairId);

    m_BulletMgr.SaveBullet(bullet);
    //////////////////////////////////////////////////////////////////////////

    gamefish::ShootBulletRsp shootBulletRsp;
    shootBulletRsp.set_usbulletid(bullet.m_uBulletId);
    shootBulletRsp.set_sangle(bullet.m_iAngle);
    shootBulletRsp.set_usspeedindex(1);
    shootBulletRsp.set_usintervalindex(2);
    shootBulletRsp.set_uslevelindex(bullet.m_iBulletLevel);
    shootBulletRsp.set_uschairid(GetChairIdForClient());
    shootBulletRsp.set_userrorcode(0);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShootBullet() ==========> m_isRobot = {}", m_isRobot);

    if (m_isRobot)
    {
        int realPlayerChairId = GetRealPlayerChairIdForRobot();
        shootBulletRsp.set_usprocuserchairid(realPlayerChairId+1);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "realPlayerChairId = {}", realPlayerChairId);
    }
    else
    {
        shootBulletRsp.set_usprocuserchairid(-1);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cgShootBullet.usbulletid() = {} , pPlayer->m_chairId = {}", bullet.m_uBulletId, m_uChairId);

    //SendMsgToClientByPlayerId(playerId, NF_FISH_CMD_SHOOTBULLET_RSP, gcShootBullet);
    //SendMsgToOtherClient(playerId, NF_FISH_CMD_SHOOTBULLET_RSP, gcShootBullet);
    GetDesk()->SendMsgToAllClient(NF_FISH_CMD_SHOOTBULLET_RSP, shootBulletRsp);

    return 0;
}



void NFGameFishPlayer::SetDoubleGunValueOn(int iOnOff)
{
    m_iDoubleGunValueOnOff = iOnOff;
}

int NFGameFishPlayer::GetDoubeGunValueOn()
{
    return m_iDoubleGunValueOnOff;
}

void NFGameFishPlayer::SendUserMoney()
{
    gamefish::gcUserMoney gcUserMoney;
    gcUserMoney.set_chair_id(GetChairIdForClient());
    gcUserMoney.set_user_money(GetCurMoney());

    GetDesk()->SendMsgToAllClient(NF_FISH_CMD_USERMONEY_RSP, gcUserMoney);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==============> SendUserMoney() , m_ullPlayerId = {} , m_ullUserMoney = {}", m_ullPlayerId, GetCurMoney());
}

void NFGameFishPlayer::AddUserChangedTotalShootMoney(int64_t iChangedMoney)
{
    m_iUserChangedTotalShootMoney += iChangedMoney;
}


void NFGameFishPlayer::AddUserChangedTotalCaptureMoney(int64_t iChangedMoney)
{
    m_iUserChangedTotalCaptureMoney += iChangedMoney;
}

void NFGameFishPlayer::AddCaptureMoney(int64_t ullChangedMoney)
{
    GetDesk()->AddGameMoney(m_ullPlayerId, ullChangedMoney);

    AddUserChangedTotalCaptureMoney(ullChangedMoney);

    AchievementCount(ullChangedMoney, 0);
    GameDataCommit(0, 0, -ullChangedMoney);

    SendUserMoney();
}

int32_t NFGameFishPlayer::GetRealPlayerChairIdForRobot()
{
    CHECK_EXPR(GetDesk(), -1, "m_pDesk == NULL");

    return GetDesk()->GetRealPlayerChairIdForRobot();
}

double NFGameFishPlayer::GetBulletHarmData()
{
    return 1;
}

void NFGameFishPlayer::AddHitFishCount(const NFGameFish& serverFishTraceInfo, double dbBulletHarm)
{
    m_arHitNormalFishCount[serverFishTraceInfo.m_nFishKind] += dbBulletHarm;
}

double NFGameFishPlayer::GetHitFishCount(const NFGameFish& serverFishTraceInfo)
{
    return m_arHitNormalFishCount[serverFishTraceInfo.m_nFishKind];
}

void NFGameFishPlayer::ResetHitFishCount(const NFGameFish &serverFishTraceInfo) {
    m_arHitNormalFishCount[serverFishTraceInfo.m_nFishKind] = 0;
}

int NFGameFishPlayer::Tick()
{
    if (NFTime::Now().UnixSec() - m_lastSaveUserMoney >= 60)
    {
        m_lastSaveUserMoney = NFTime::Now().UnixSec();
        if (GetDesk())
        {
            GetDesk()->ProcUserSettlement(GetPlayerID());
        }
    }
    return 0;
}

int NFGameFishPlayer::GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
{
    if (GetDesk() && !m_isRobot)
    {
        GetDesk()->GameDataCommit(cur_fee, cur_pour, cur_win);
    }
    return 0;
}

int NFGameFishPlayer::AchievementCount(uint64_t Count, uint64_t fee)
{
    if (GetDesk() && !m_isRobot)
    {
        GetDesk()->AchievementCount(GetPlayerID(), Count, fee);
    }
    return 0;
}

int NFGameFishPlayer::UpdateUserInfo(const proto_ff_s::GamePlayerDetailData_s* pUserDetailInfo)
{
    CHECK_NULL(pUserDetailInfo);

    SendUserMoney();
    return 0;
}

NFGameFishDesk* NFGameFishPlayer::GetDesk()
{
    return dynamic_cast<NFGameFishDesk*>(GetShmObj());
}

