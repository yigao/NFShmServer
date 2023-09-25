// -------------------------------------------------------------------------
//    @FileName         :    NFFishGroup.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishGroup.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmStl/NFShmString.h"
#include "NFFishTraceConfig.h"

#include <list>

#define FISH_MAX_MD5_STR_LEN  33
#define MAX_FISH_NUM 300

enum 
{
    E_FISH_GROUP_TYPE_YU_QUN = 1,
    E_FISH_GROUP_TYPE_YU_ZHEN = 2
};

class CFish {
public:
    CFish() 
	{
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        }
        else {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_unFishId = 0;
        m_usFishKind = 0;
        m_usTraceId = 0;
        m_usStartPointIndex = 0;
        m_unAliveTime = 0;
        m_byDefaultSubFish = 0;
        m_BirthDelay = 0;
        m_uReserved  = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int Init(uint32_t unFishId, uint16_t usFishKind, uint32_t usTraceId, uint16_t usStartPointIndex, uint32_t unAliveTime)
	{
        m_unFishId = unFishId;
        m_usFishKind = usFishKind;
        m_usTraceId = usTraceId;
        m_usStartPointIndex = usStartPointIndex;
        m_unAliveTime = unAliveTime;
        m_byDefaultSubFish = 0;

        uint32_t uTmp = m_unAliveTime;

        m_byDefaultSubFish = (uTmp & 0xFF000000) >> 24;//最高一字节是默认子鱼KindId
        m_unAliveTime = uTmp & 0x00FFFFFF;//低三字节是存活时间

        //MYLOG_INFO(logger, "CFish::CFish() FishId = %u FishKind = %u TraceId = %u StartPointIndex = %u uTmp = %u(0x%x), AliveTime = %u(0x%x), m_byDefaultSubFish = %u(0x%x)", m_unFishId, m_usFishKind, m_usTraceId, m_usStartPointIndex, uTmp, uTmp, m_unAliveTime, m_unAliveTime, m_byDefaultSubFish, m_byDefaultSubFish);
        return 0;
    }

    ~CFish() {};
public:
    uint32_t m_unFishId;          //鱼ID
    uint16_t m_usFishKind;        //鱼种类ID
    uint32_t m_usTraceId;         //轨迹ID
    uint16_t m_usStartPointIndex; //起始点在轨迹上的索引
    uint32_t m_unAliveTime;       //存活时间(走完轨迹的时间, 单位: 毫秒)
    uint8_t  m_byDefaultSubFish;  //默认子鱼kind
	uint16_t m_BirthDelay;        //出鱼延时
	uint32_t m_uReserved;         //保留
};

typedef NFShmVector<CFish, MAX_FISH_NUM> FISH_LIST;

class CFishGroup {
public:
    CFishGroup();

    virtual ~CFishGroup();

    int CreateInit();

    int ResumeInit();

	int Load(const std::string &strFile, NFFishTraceConfig* pTrace);

    const FISH_LIST &GetFishList();

    void SetId(uint32_t id) { m_unId = id; }
    unsigned int Id() const { return m_unId; }

    uint16_t Type() const { return m_usGroupType; }

    uint16_t PrepareTime() const { return m_usPrepareTime; }

    char HideWave() const { return m_byHideWave; }

    std::string ToHEX(char *buf, int len);

    void Clear();

    std::string GetFileMD5() const { return m_szMD5.GetString(); }
    void SetFileMD5(const std::string& md5) { m_szMD5 = md5; }
protected:
    
	int ReadGroupFileVer0(FILE* fpGroup);
	int ReadGroupFileVer1(FILE* fpGroup, NFFishTraceConfig* pTrace);

public:
    uint32_t m_unId;          //鱼阵ID
    FISH_LIST m_FishList;     //鱼阵中的鱼的列表
    uint16_t m_usFishCount;   //鱼阵中鱼的个数
    bool m_bValid;            //是否有效
    uint16_t m_usGroupType;   //鱼阵类型
    uint16_t m_usPrepareTime; //准备时间
	uint8_t  m_byHideWave;    //隐藏海浪
	uint16_t m_usCenterX;
	uint16_t m_usCenterY;
	uint8_t  m_byVersion;
	uint8_t  m_bySceneType;
	int8_t   m_bySceneIndex;
    NFShmString<FISH_MAX_MD5_STR_LEN> m_szMD5;
};