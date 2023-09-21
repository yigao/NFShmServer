#include "HMPoint.h"
#include <math.h>
#include <vector>

CHMPoint::CHMPoint()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}


CHMPoint::CHMPoint(int iPosX, int iPosY, short sSpeed/*=0*/)
{
	m_iPosX = iPosX;
	m_iPosY = iPosY;
	m_sSpeed = sSpeed;

	m_iDirPosX = 0;
	m_iDirPosY = 0;
}

CHMPoint::~CHMPoint()
{

}

void CHMPoint::Clear()
{
	m_iPosX = 0;
	m_iPosY = 0;
	m_sSpeed = 0;
	m_iDirPosX = 0;
	m_iDirPosY = 0;
}

bool CHMPoint::IsNull()
{
	return m_iPosX == 0 || m_iPosY == 0;
}

int CHMPoint::CreateInit() {
	Clear();
	return 0;
}

int CHMPoint::ResumeInit() {
	return 0;
}





CHMPoint CHMPoint::Rotate(CHMPoint ptCenter, double angle)
{
	//CPoint ptpt;
	//ptpt.x = (pt.x - dpt.x)*cos(angle) - (pt.y - dpt.y)*sin(angle) + dpt.x;
	//ptpt.y = (pt.y - dpt.y)*cos(angle) - (pt.x - dpt.x)*sin(angle) + dpt.y;
	//return ptpt;

	double angle0 = angle / 180 * 3.14;

	double diffX = m_iPosX - ptCenter.m_iPosX;
	double diffY = m_iPosY - ptCenter.m_iPosY;
	double angle1 = atan2(diffY, diffX);
	double angle2 = angle1 + angle0;
	double r = sqrt(diffX*diffX + diffY*diffY);

	double xx = r * cos(angle2) + ptCenter.m_iPosX;
	double yy = r * sin(angle2) + ptCenter.m_iPosY;

	CHMPoint ptpt;
	ptpt.m_iPosX = xx;
	ptpt.m_iPosY = yy;
	ptpt.m_sSpeed = m_sSpeed;
	//ptpt.m_iDirPosX = 111;//TODO
	//ptpt.m_iDirPosY = 222;//TODO

	return ptpt;
}

CHMPoint CHMPoint::OffSet(int iOffsetX, int iOffsetY)
{
	CHMPoint hmPoint;

	hmPoint.m_iPosX    = m_iPosX + iOffsetX;
	hmPoint.m_iPosY    = m_iPosY + iOffsetY;
	hmPoint.m_sSpeed   = m_sSpeed;
	hmPoint.m_iDirPosX = m_iDirPosX + iOffsetX;
	hmPoint.m_iDirPosY = m_iDirPosY + iOffsetY;

	return hmPoint;
}



double HMDistance(CHMPoint point1, CHMPoint point2)
{
	int diffX = point1.m_iPosX - point2.m_iPosX;
	int diffY = point1.m_iPosY - point2.m_iPosY;

	return sqrt(diffX*diffX + diffY*diffY);
}
double HMDistanceDouble(CHMPointDouble point1, CHMPointDouble point2)
{
	double diffX = point1.m_dblPosX - point2.m_dblPosX;
	double diffY = point1.m_dblPosY - point2.m_dblPosY;

	return sqrt(diffX*diffX + diffY*diffY);
}

bool IsPointInScreen(CHMPoint point)
{
	if (point.m_iPosX>0 && point.m_iPosX<SCREEN_WIDTH && point.m_iPosY>0 && point.m_iPosY< SCREEN_HEIGHT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsPointInCenterScreen(CHMPoint point)
{
	if (point.m_iPosX > 100 && point.m_iPosX < SCREEN_WIDTH-100 && point.m_iPosY>50 && point.m_iPosY < SCREEN_HEIGHT-50)
	{
		return true;
	}
	else
	{
		return false;
	}
}