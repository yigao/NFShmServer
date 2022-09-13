#pragma once
#include <string>
#include <vector>


class NFGameRoomCfg
{
public:
	NFGameRoomCfg()
	{
		iRoomID     = 0;
		iRoomType   = 0;
		strRoomName = "";
		iSiteNum    = 0;
		iDeskCount  = 0;
		iMaxPeople  = 0;
	}

public:
	int32_t iRoomID;
	int32_t iRoomType;
	std::string strRoomName;
	int32_t iSiteNum;
	int32_t iDeskCount;
	int32_t iMaxPeople;
};



std::string NFToString(int iValue);
