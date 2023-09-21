// -------------------------------------------------------------------------
//    @FileName         :    NFFishCtrlCfgDef.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishCtrlCfgDef.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

#ifdef _WIN32
#pragma pack(push,1)
#else
#pragma pack(1)
#endif


/*

鱼阵配置中的鱼的结构的

*/

struct FishItem
{
    FishItem()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit() {
        usFishKind = 0;
        usTraceId = 0;
        usStartPointIndex = 0;
        usAliveTime = 0;
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    uint16_t usFishKind;        //鱼的种类
    uint32_t usTraceId;         //鱼的轨迹ID
    uint16_t usStartPointIndex; //起始点在轨迹上的索引
    uint32_t usAliveTime;       //鱼存活时间 //低三字节是存活时间，最高字节是第一个默认子鱼kind
};

struct FishItem1
{
	FishItem1()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}

	int CreateInit() {
		usFishKind = 0;
		usTraceId = 0;
		usStartPointIndex = 0;
		usAliveTime = 0;
		sBirthDelay = 0;
		uReserved = 0;
		return 0;
	}

	int ResumeInit() {
		return 0;
	}

	uint16_t usFishKind;        //鱼的种类
	uint32_t usTraceId;         //鱼的轨迹ID
	uint16_t usStartPointIndex; //起始点在轨迹上的索引
	uint32_t usAliveTime;       //鱼存活时间 //低三字节是存活时间，最高字节是第一个默认子鱼kind
	uint16_t sBirthDelay;//
	uint32_t uReserved;
};

/*

鱼阵头结构

*/

struct FishGroupHead
{
    FishGroupHead()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit() {
        usGroupType = 0;
        usFishCount = 0;
        usPrepareTime = 0;
        uAliveTime = 0;
        byHideWave = 0;
		byVersion = 0;
        memset(&Reserve, 0, sizeof(Reserve));
        usCenterX = 0;
        usCenterY = 0;
        bySceneIndex = 0;
        bySceneType = 0;
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    uint16_t usGroupType;   //鱼阵类型, 1:散鱼鱼阵, 2: 鱼阵
    uint16_t usFishCount;   //鱼阵中鱼的个数
    uint16_t usPrepareTime; //准备时间
    uint32_t uAliveTime;    //存活时间，暂未用
	uint8_t  byHideWave;    //隐藏海浪
	uint16_t usCenterX;
	uint16_t usCenterY; 
	uint8_t  byVersion; //0 1 //以后版本都是1，没有0了
	uint8_t  bySceneType;
	int8_t   bySceneIndex;
    char     Reserve[14];   //预留字段, 长度28个字节

};

/*
路单项类型
*/
enum
{
    E_FISH_WAY_BILL_ITEM_TYPE_INVALID    = 0, //无效的类型
    E_FISH_WAY_BILL_ITEM_TYPE_YUZHEN     = 1, //鱼阵ID
    E_FISH_WAY_BILL_ITEM_TYPE_DELAY_TIME = 2, //延时时间

    E_FISH_WAY_BILL_ITEM_TYPE_MAX
};



/*

路单文件头结构

*/

struct FishWayBillHead 
{
    FishWayBillHead() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit() {
        usCount = 0;
        usInterval = 0;
        memset(&Reserve, 0, sizeof(Reserve));
        usDefaultGroupDelay = 0;
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    uint16_t usCount;     //路单项个数
    uint16_t usInterval;  //鱼的轨迹的两个轨迹点的间隔时间(单位: 毫秒)
	uint16_t usDefaultGroupDelay;

    char Reserve[26]; //预留扩展字段, 30字节
};

/*
路单项结构
*/

struct FishWayBillItem {
    FishWayBillItem() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit() {
        usType = 0;
        usValue = 0;
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    uint16_t usType;   //类型
    uint16_t usValue;  //对应的值
};





#ifdef _WIN32
#pragma pack(pop)
#else
#pragma pack()
#endif