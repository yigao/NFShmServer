#include "HMTraceBin.h"



CHMTraceBin::CHMTraceBin()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

CHMTraceBin::~CHMTraceBin()
{

}

int CHMTraceBin::CreateInit()
{
	m_uTraceId = 0;
	m_sTime = 0;
	m_uType = 0;//0-no angle   1-with angle
	return 0;
}

int CHMTraceBin::ResumeInit()
{
	return 0;
}

void CHMTraceBin::AddPoint(const CHMPoint& hmPoint)
{
	int ret = m_vecPoints.push_back(hmPoint);
	if (ret < 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "m_vecPoints.Add Failed! Space Not Enough!");
		NFSLEEP(1000);
		exit(0);
		return;
	}
}

int CHMTraceBin::GetPointCount()
{
	return m_vecPoints.size();
}

CHMPoint CHMTraceBin::GetPointByIndex(unsigned int uIndex)
{
	if (uIndex < (unsigned int)m_vecPoints.size())
	{
		return m_vecPoints[uIndex];
	}

	return CHMPoint();
}

int CHMTraceBin::GetIndexByPoint(CHMPoint point, CHMPoint& dstHMPoint)
{
	int iIndex = -1;
	double dDistance = 9999999;

	for (int i = 0; i < (int)m_vecPoints.size(); i++)
	{
		double d = HMDistance(m_vecPoints[i], point);
		if (d < dDistance && d < 20)
		{
			dDistance = d;
			iIndex = i;

			dstHMPoint = m_vecPoints[i];
		}
	}

	return iIndex;
}

CHMTraceBin CHMTraceBin::Rotate(double angle)
{
	CHMTraceBin traceBin;

	traceBin.m_sTime    = m_sTime;
	traceBin.m_uType    = m_uType;
	traceBin.m_ptCenter = m_ptCenter;

	for (int i = 0; i < (int)m_vecPoints.size(); i++)
	{
		traceBin.AddPoint(m_vecPoints[i].Rotate(m_ptCenter, angle));
	}

	return traceBin;
}

CHMTraceBin CHMTraceBin::Offset(int iOffsetX, int iOffsetY)
{
	CHMTraceBin traceBin;

	traceBin.m_uType    = m_uType;
	traceBin.m_ptCenter = m_ptCenter.OffSet(iOffsetX, iOffsetY);

	for (int i = 0; i < (int)m_vecPoints.size(); i++)
	{
		traceBin.AddPoint(m_vecPoints[i].OffSet(iOffsetX, iOffsetY));
	}
	
	return traceBin;
}



