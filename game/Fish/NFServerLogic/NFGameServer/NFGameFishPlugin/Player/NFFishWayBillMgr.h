// -------------------------------------------------------------------------
//    @FileName         :    NFFishWayBillMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishWayBillMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "Config/NFFishWayBill.h"
#include <vector>
#include "Config/NFFishWayBillConfig.h"
#include "Config/NFFishSettingConfig.h"

class NFFishWayBillMgr
{
public:
    NFFishWayBillMgr();
    ~NFFishWayBillMgr();

    int CreateInit();
    int ResumeInit();

    void Clear();

    int InitWayBills(NFFishWayBillConfig* pFishBillConfig, bool flag);
    void RandomShuffleWayBills();


    bool GetOneItem(NFFishWayBillConfig *pConfig, FishWayBillItem & Item);
    bool ForcastOneItem(FishWayBillItem & Item);
    int  GetDefaultGroupDelay();

    CFishWayBill* GetWayBill();
    CFishWayBill* GetCurWayBill();
    CFishWayBill* GetWayBillByName(const std::string& strName);

    CFishWayBill* GetPirorWayBill(NFFishSettingConfig* pFishSettingConfig);

    void  Print();

public:
    NFShmVector<CFishWayBill, MAX_WAYBILL_FILE_COUNT> m_vecWayBills;

    int m_iCurWayBillIndex;
};