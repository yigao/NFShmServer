// -------------------------------------------------------------------------
//    @FileName         :    NFFishBulletMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishBulletMgr
//
// -------------------------------------------------------------------------

#include "NFFishBulletMgr.h"


NFFishBullet::NFFishBullet()
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

int NFFishBullet::CreateInit()
{
    m_uBulletId = 0;
    m_uBulletType = eBulletType_Normal;
    m_iAngle = 0;
    m_iBulletLevel = 0;
    m_uBulletMoney = 0;
    m_llBirthTime = NFTime::Now().UnixMSec();
    m_iChairId = INVALID_ID;

    return 0;
}

int NFFishBullet::ResumeInit()
{
    return 0;
}

uint32_t NFFishBullet::GetBulletMul() const
{
    if (m_uBulletType == eBulletType_Double)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}


NFFishBulletMgr::NFFishBulletMgr()
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

NFFishBulletMgr::~NFFishBulletMgr()
{

}

int NFFishBulletMgr::CreateInit()
{
    return 0;
}

int NFFishBulletMgr::ResumeInit()
{
    return 0;
}

bool NFFishBulletMgr::SaveBullet(const NFFishBullet &bullet)
{
    auto iter = m_mapBullets.find(bullet.m_uBulletId);
    if (iter == m_mapBullets.end())
    {
        if (m_mapBullets.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "bulletId:{} Insert Failed! player bullet too much!", bullet.m_uBulletId);
            return false;
        }

        m_mapBullets.emplace(bullet.m_uBulletId, bullet);

        iter = m_mapBullets.find(bullet.m_uBulletId);
        if (iter != m_mapBullets.end())
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishBulletMgr::SaveBullet bulletId:{} OK", bullet.m_uBulletId);
        }
        else
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, 0, "NFFishBulletMgr::SaveBullet bulletId:{} NG", bullet.m_uBulletId);
        }

        return true;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "bulletId:{} Insert Failed, bullet exist", bullet.m_uBulletId);
    }
    return false;
}

void NFFishBulletMgr::DeleteBullet(uint32_t uBulletId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishBulletMgr::DeleteBullet() bulletId:{}", uBulletId);

    auto iter = m_mapBullets.find(uBulletId);
    if (iter != m_mapBullets.end())
    {
        m_mapBullets.erase(iter);
    }
}

NFFishBullet *NFFishBulletMgr::GetBullet(uint32_t uBulletId)
{
    auto iter = m_mapBullets.find(uBulletId);
    if (iter != m_mapBullets.end())
    {
        return &iter->second;
    }
    return nullptr;
}


void NFFishBulletMgr::CheckBulletOverTime()
{
    std::vector<uint32_t> vec;

    for (auto iter = m_mapBullets.begin(); iter != m_mapBullets.end(); iter++)
    {
        NFFishBullet *pBullet = &iter->second;
        if (pBullet != NULL)
        {
            if ((NFTime::Now().UnixMSec() - pBullet->m_llBirthTime > 10 * 1000))//10s
            {
                //NFLogError(NF_LOG_SYSTEMLOG, 0, "TestBullet timeS = {} , birT = {} , t = {}", NFTime::Now().UnixMSec(), pBullet->m_llBirthTime, NFTime::Now().UnixMSec() - pBullet->m_llBirthTime);
                vec.push_back(pBullet->m_uBulletId);
            }
        }
    }

    if (vec.size() > 0)
    {
        std::vector<uint32_t>::iterator iter = vec.begin();
        for (; iter != vec.end(); iter++)
        {
            DeleteBullet(*iter);
        }
    }
}


