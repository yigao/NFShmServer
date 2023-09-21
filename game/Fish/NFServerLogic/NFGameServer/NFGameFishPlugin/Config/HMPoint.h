#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

#define SCREEN_WIDTH  1560
#define SCREEN_HEIGHT 960


class CHMPoint
{
public:
	CHMPoint();
	CHMPoint(int iPosX, int iPosY, short sSpeed=0);
	~CHMPoint();

	int CreateInit();
	int ResumeInit();

	void Clear();
	bool IsNull();
	
	CHMPoint Rotate(CHMPoint ptCenter, double angle);
	CHMPoint OffSet(int iOffsetX, int iOffsetY);
	
public:
	int m_iPosX;
	int m_iPosY;
	float m_sSpeed;

	int m_iDirPosX;
	int m_iDirPosY;
};

class CHMPointDouble
{
public:
	CHMPointDouble()
	{
		m_dblPosX = 0;
		m_dblPosY = 0;
		m_dblDirPosX = 0;
		m_dblDirPosY = 0;
		m_sSpeed = 0;
	}

	CHMPointDouble(CHMPoint pt)
	{
		m_dblPosX = pt.m_iPosX;
		m_dblPosY = pt.m_iPosY;
		m_dblDirPosX = pt.m_iDirPosX;
		m_dblDirPosY = pt.m_iDirPosY;
		m_sSpeed = pt.m_sSpeed;
	}

	CHMPointDouble(double posX, double posY, double dirPosX, double dirPosY)
	{
		m_dblPosX = posX;
		m_dblPosY = posY;
		m_dblDirPosX = dirPosX;
		m_dblDirPosY = dirPosY;
		m_sSpeed = 0;
	}



public:
	double m_dblPosX;
	double m_dblPosY;

	double m_dblDirPosX;
	double m_dblDirPosY;

	short  m_sSpeed;
};


double HMDistance(CHMPoint point1, CHMPoint point2);
double HMDistanceDouble(CHMPointDouble point1, CHMPointDouble point2);

bool   IsPointInScreen(CHMPoint point);
bool   IsPointInCenterScreen(CHMPoint point);