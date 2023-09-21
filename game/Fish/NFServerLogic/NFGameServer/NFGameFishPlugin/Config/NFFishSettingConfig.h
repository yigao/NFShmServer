#pragma once
#include <string>
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmStl/NFShmString.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"

class CtrlParam
{
public:
	CtrlParam()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		} else {
			ResumeInit();
		}
	}
	~CtrlParam()
	{

	}

	int CreateInit() {
		m_dbPercent = 0;
		m_dbValuePercent = 0;
		m_llMaxValue = 0;
		return 0;
	}

	int ResumeInit() {
		return 0;
	}

public:
	double  m_dbPercent;
	double  m_dbValuePercent;
	int64_t m_llMaxValue;
};


class NFFishSettingConfig : public NFShmObj
{
public:
	NFFishSettingConfig();
	~NFFishSettingConfig();

    int CreateInit();
    int ResumeInit();


public:
    int LoadConfig(uint32_t roomId);

	uint32_t GetShootTrace(int chairId, int traceIndex);
	std::string GetPriorWayBill(std::string strLastWayBillName = "");

	CtrlParam GetCtrlParam(uint32_t& uCount, int64_t llTotalShootInCtrlTime);
	int64_t CalMaxValueByTotalShootValue(CtrlParam& ctrlParam, int64_t llTotalShootInCtrlTime);

public:
    uint32_t m_roomId;
	int m_iDNTGKilledGroup;
	int m_iDNTGGroupInterval;

	int m_iOneCannonKilled;
	int m_iKillJudgeType;

	int m_iDoubleCannonEnable;
	int m_iDoubleCannonRatio;

	NFShmHashMap<uint32_t, NFShmVector<uint32_t, 20>, 10> m_mapShootTraces;
	NFShmHashMap<NFShmString<15>, int, 30> m_mapWayBills;

	int64_t m_illMaxValue;
	int64_t m_illMinValue;
	int m_iCtrlTime;
	NFShmVector<CtrlParam, 100> m_AryCtrlParam;

	DECLARE_IDCREATE(NFFishSettingConfig);
};