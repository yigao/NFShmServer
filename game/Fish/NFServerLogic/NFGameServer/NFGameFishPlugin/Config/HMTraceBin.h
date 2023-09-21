#pragma once
#include <list>
#include <vector>
#include <string>
#include "HMPoint.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmStl/NFShmVector.h"

#define MAX_HM_TRACE_BIN_POINT 1500

class CHMTraceBin
{
public:
	CHMTraceBin();
	~CHMTraceBin();

	int CreateInit();
	int ResumeInit();

	void AddPoint(const CHMPoint& hmPoint);
	int GetPointCount();

	CHMPoint GetPointByIndex(unsigned int uIndex);
	int GetIndexByPoint(CHMPoint point, CHMPoint& dstHMPoint);

	CHMTraceBin Rotate(double angle);
	CHMTraceBin Offset(int iOffsetX, int iOffsetY);
	
public:
	uint32_t   m_uTraceId;
	uint32_t   m_sTime;
	uint32_t   m_uType;//0-no angle   1-with angle
	CHMPoint   m_ptCenter;
	NFShmVector<CHMPoint, MAX_HM_TRACE_BIN_POINT> m_vecPoints;
};

