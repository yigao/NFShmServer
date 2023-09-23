// -------------------------------------------------------------------------
//    @FileName         :    NFFishWayBillMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishWayBillMgr
//
// -------------------------------------------------------------------------

#include "NFFishWayBillMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include <algorithm>
#include "Config/NFFishSettingConfig.h"


NFFishWayBillMgr::NFFishWayBillMgr()
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

int NFFishWayBillMgr::CreateInit()
{
    m_iCurWayBillIndex = INVALID_ID;
    return 0;
}

void NFFishWayBillMgr::Clear()
{
    CreateInit();
    m_vecWayBills.CreateInit();
}

int NFFishWayBillMgr::ResumeInit()
{
    return 0;
}

NFFishWayBillMgr::~NFFishWayBillMgr()
{

}

void NFFishWayBillMgr::RandomShuffleWayBills()
{
    std::random_shuffle(m_vecWayBills.begin(), m_vecWayBills.end());
}

int NFFishWayBillMgr::InitWayBills(NFFishWayBillConfig* pFishBillConfig, bool flag)
{
    CHECK_NULL(pFishBillConfig);
    if (flag)
    {
        m_vecWayBills.clear();

        for (int i = 0; i < (int) pFishBillConfig->m_vecWayBills.size(); i++)
        {
            CHECK_EXPR(m_vecWayBills.size() < m_vecWayBills.max_size(), -1, "m_vecWayBills space not enough");
            m_vecWayBills.push_back();
            CFishWayBill *pBill = &m_vecWayBills.back();
            if (pBill)
            {
                pBill->CopyFrom(pFishBillConfig->m_vecWayBills[i]);
            }
        }
    }
    else
    {
        m_vecWayBills.clear();
        for (int i = 0; i < (int) pFishBillConfig->m_vecWayBillExts.size(); i++)
        {
            CHECK_EXPR(m_vecWayBills.size() < m_vecWayBills.max_size(), -1, "m_vecWayBills space not enough");
            m_vecWayBills.push_back();
            CFishWayBill *pBill = &m_vecWayBills.back();
            {
                pBill->CopyFrom(pFishBillConfig->m_vecWayBillExts[i]);
            }
        }
    }

    RandomShuffleWayBills();
    m_iCurWayBillIndex = INVALID_ID;
    return 0;
}

CFishWayBill *NFFishWayBillMgr::GetWayBill()
{
    m_iCurWayBillIndex++;

    CFishWayBill *pWayBill = NULL;

    if (m_vecWayBills.size() == 0)
    {
        m_iCurWayBillIndex = INVALID_ID;
        return pWayBill;
    }

    if (m_iCurWayBillIndex >= (int) m_vecWayBills.size())
    {
        RandomShuffleWayBills();
        m_iCurWayBillIndex = 0;
    }

    if (m_iCurWayBillIndex < (int)m_vecWayBills.size())
    {
        pWayBill = &(m_vecWayBills[m_iCurWayBillIndex]);
    }

    return pWayBill;
}

CFishWayBill *NFFishWayBillMgr::GetCurWayBill()
{
    CHECK_EXPR(m_iCurWayBillIndex >= 0 && m_iCurWayBillIndex < (int) m_vecWayBills.size(), NULL, "m_iCurWayBillIndex:{} Error", m_iCurWayBillIndex);

    return &m_vecWayBills[m_iCurWayBillIndex];
}

CFishWayBill *NFFishWayBillMgr::GetWayBillByName(const std::string &strName)
{
    for (int i = 0; i < (int)m_vecWayBills.size(); i++)
    {
        if (m_vecWayBills[i].GetFileName() == strName)
        {
            return &m_vecWayBills[i];
        }
    }

    return NULL;
}

CFishWayBill *NFFishWayBillMgr::GetPirorWayBill(NFFishSettingConfig* pFishSettingConfig)
{
    CHECK_EXPR(pFishSettingConfig, NULL, "NFFishSettingConfig:");
    std::string strWayBillName = pFishSettingConfig->GetPriorWayBill("");
    if (!strWayBillName.empty())
    {
        return GetWayBillByName(strWayBillName);
    }
    else
    {
        return NULL;
    }
}

void NFFishWayBillMgr::Print()
{
    for (int i = 0; i < (int)m_vecWayBills.size(); i++)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishWayBillName = {}", m_vecWayBills[i].GetFileName());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_iCurWayBillIndex = {}/{} , CurWayBillName = {}", m_iCurWayBillIndex, m_vecWayBills.size(), m_vecWayBills[m_iCurWayBillIndex].GetFileName());
}

bool NFFishWayBillMgr::GetOneItem(NFFishWayBillConfig *pConfig, FishWayBillItem &Item)
{
    CHECK_EXPR(pConfig, false, "");
    CFishWayBill *pCurWayBill = GetCurWayBill();
    CHECK_EXPR(pCurWayBill, false, "pCurWayBill == NULL !");

    int iLeftCount = pCurWayBill->GetOneItem(Item);
    if (iLeftCount <= 0)
    {
        pCurWayBill = GetWayBill();

        CHECK_EXPR(pCurWayBill, false, "pCurWayBill == NULL !");

        pCurWayBill->Reset(pConfig);
    }

    return true;
}

bool NFFishWayBillMgr::ForcastOneItem(FishWayBillItem &Item)
{
    CFishWayBill *pCurWayBill = GetCurWayBill();
    CHECK_EXPR(pCurWayBill, false, "pCurWayBill == NULL !");

    return pCurWayBill->ForcastOneItem(Item);
}

int NFFishWayBillMgr::GetDefaultGroupDelay()
{
    CFishWayBill *pCurWayBill = GetCurWayBill();
    CHECK_EXPR(pCurWayBill, 0, "pCurWayBill == NULL !");

    return pCurWayBill->GetDefaultGroupDelay();
}
