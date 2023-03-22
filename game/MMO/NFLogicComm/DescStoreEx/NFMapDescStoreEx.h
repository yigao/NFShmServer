// -------------------------------------------------------------------------
//    @FileName         :    NFMapDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "DescStore/MapMapDesc.h"
#include "DescStore/RoleBornDesc.h"
#include "common_logic_s.h"
#include "NFLogicCommon/NFPoint3.h"

#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmCore/NFArray.h"

#define NF_MAP_DESC_BORN_MAX_SIZE 40
#define NF_MAP_DESC_AREA_MAX_POS_SIZE 10
#define NF_MAP_DESC_PATH_MAX_POS_SIZE 10

class NFPosCfg
{
public:
    NFPosCfg()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_pos.CreateInit();
        m_dir = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    NFPoint3<float> m_pos;
    float m_dir;
};

typedef NFShmVector<NFPosCfg, NF_MAP_DESC_BORN_MAX_SIZE> VecPosCfg;
typedef NFShmVector<NFPoint3<float>, NF_MAP_DESC_PATH_MAX_POS_SIZE> VecPathPosCfg;

//各类坐标点配置
struct NFPointCfg
{
    int64_t mapid = 0;		//地图ID
    int64_t  id = 0;		//坐标点ID
    VecPosCfg vecposcfg;	//坐标配置列表
};

class NFPathCfg
{
public:
    NFPathCfg()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_pathCfg.CreateInit();
        m_id = 0;
        m_mapId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    VecPathPosCfg m_pathCfg;
    uint64_t m_id;
    uint64_t m_mapId;
};

class NFAreaPosCfg
{
public:
    NFAreaPosCfg()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_circle.CreateInit();
        m_radius = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    NFPoint3<float> m_circle;
    float m_radius;
};

typedef NFArray<NFAreaPosCfg, NF_MAP_DESC_AREA_MAX_POS_SIZE> VecAreaPosCfg;

class NFAreaCfg
{
public:
    NFAreaCfg()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_areaCfg.CreateInit();
        m_id = 0;
        m_mapId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    VecAreaPosCfg m_areaCfg;
    uint64_t m_id;
    uint64_t m_mapId;
};

class NFMapDescStoreEx : public NFIDescStore
{
public:
    NFMapDescStoreEx();

    virtual ~NFMapDescStoreEx();

    int CreateInit();

    int ResumeInit();

    virtual bool IsNeedReload();

    virtual int PrepareReload();
public:
    int LoadBornCfg(uint64_t mapId, const std::string &file);

    int32_t BornPointCount(int64_t mapId);                                //地图出生地点数量
    const NFPoint3<float> *RandBornPoint(int64_t mapId);                //随机一个地图的出生点
    const VecPosCfg *GetBornPosCfg(int64_t mapId);                    //获取地图出生点配置
    const proto_ff_s::E_RoleBorn_s *GetBornCfg(int32_t prof);                    //获取角色出生配置

    bool IsDynamic(int64_t mapId);                                            //是否是动态地图
    bool IsActSpecMap(int64_t mapId);                                        //是否是活动特殊地图
public:
    /**
     * @brief 获取坐标点配置
     * @param id
     * @return
     */
    const NFPointCfg* GetPointCfg(int64_t id);

    /**
     * @brief 获取路径配置
     * @param id
     * @return
     */
    const NFPathCfg* GetPathCfg(int64_t id);

    /**
     * @brief 获取区域配置
     * @param id
     * @return
     */
    const NFAreaCfg* GetAreaCfg(int64_t id);

    /**
     * @brief 是否在区域内
     * @param areaid
     * @param pos
     * @return
     */
    bool InArea(int64_t areaid, const NFPoint3<float> &pos);

    /**
     * @brief 区域内随机一个坐标
     * @param areaid
     * @param outpos
     * @return
     */
    bool RandPosInArea(int64_t areaid, NFPoint3<float> &outpos);


private:
    NFShmHashMap<uint64_t, VecPosCfg, MAX_MAP_MAP_NUM> m_bornPosMap;
    NFShmHashMap<uint64_t, uint64_t, 10> m_bornProfMap;
private:
    NFShmHashMap<uint64_t, NFPointCfg, MAX_MAP_MAP_NUM * 10> m_pointMap;
    NFShmHashMap<uint64_t, NFAreaCfg, MAX_MAP_MAP_NUM * 10> m_areaMap;
    NFShmHashMap<uint64_t, NFPathCfg, MAX_MAP_MAP_NUM * 10> m_pathMap;
private:
DECLARE_IDCREATE(NFMapDescStoreEx);
IMPL_RES_SIMPLE_DESC(NFMapDescStoreEx);
};