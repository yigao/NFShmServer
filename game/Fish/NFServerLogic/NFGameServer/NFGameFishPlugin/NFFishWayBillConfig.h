#pragma once
#include "NFFishWayBill.h"
#include <vector>
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

#define MAX_WAYBILL_FILE_COUNT 30

class NFFishWayBillConfig  : public NFShmObj
{
public:
    NFFishWayBillConfig();
    ~NFFishWayBillConfig();
    int CreateInit();
    int ResumeInit();

    int LoadConfig(uint32_t roomId);

    static void LoadWayBills(const std::string& strWayBillPath, NFShmVector<CFishWayBillData, MAX_WAYBILL_FILE_COUNT>& vecWayBills);

    CFishWayBillData* GetFishWayBillByFileName(const std::string& fileName);
public:
    uint32_t m_roomId;
    NFShmVector<CFishWayBillData, MAX_WAYBILL_FILE_COUNT> m_vecWayBills;
    NFShmVector<CFishWayBillData, MAX_WAYBILL_FILE_COUNT> m_vecWayBillExts;
DECLARE_IDCREATE(NFFishWayBillConfig);
};


