#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFGameCommon/NFPoint3.h"
#include "NFGameCommon/NFPoint2.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "DescStore/MapMapDesc.h"
#include "E_Role_s.h"
#include "NFGameCommon/NFComTypeDefine.h"

#define NF_MAP_DESC_BORN_MAX_SIZE 200
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
    NFPointCfg()
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
        mapid = 0;
        id = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int64_t mapid;        //地图ID
    int64_t id;        //坐标点ID
    VecPosCfg vecposcfg;    //坐标配置列表
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

typedef NFShmVector<NFAreaPosCfg, NF_MAP_DESC_AREA_MAX_POS_SIZE> VecAreaPosCfg;

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

class MapDescEx : public NFShmObjGlobalTemplate<MapDescEx, EOT_CONST_MAP_DESC_EX_ID, NFIDescStoreEx>
{
public:
    MapDescEx();

    virtual ~MapDescEx();

    int CreateInit();

    int ResumeInit();
public:
    virtual int Load() override;
    virtual int CheckWhenAllDataLoaded() override;
public:
    /**
     * @brief
     * @param mapId
     * @param file
     * @return
     */
    int LoadBornCfg(uint64_t mapId, const std::string &file);

    /**
     * @brief 地图出生地点数量
     * @param mapId
     * @return
     */
    int32_t BornPointCount(int64_t mapId);

    /**
     * @brief 随机一个地图的出生点
     * @param mapId
     * @return
     */
    const NFPoint3<float> *RandBornPoint(int64_t mapId);

    /**
     * @brief 获取地图出生点配置
     * @param mapId
     * @return
     */
    const VecPosCfg *GetBornPosCfg(int64_t mapId);

    /**
     * @brief 获取角色出生配置
     * @param prof
     * @return
     */
    const proto_ff_s::E_RoleBorn_s *GetBornCfg(int32_t prof);

public:
    /**
     * @brief 获取坐标点配置
     * @param id
     * @return
     */
    const NFPointCfg *GetPointCfg(int64_t id);

    /**
     * @brief 获取路径配置
     * @param id
     * @return
     */
    const NFPathCfg *GetPathCfg(int64_t id);

    /**
     * @brief 获取区域配置
     * @param id
     * @return
     */
    const NFAreaCfg *GetAreaCfg(int64_t id);

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

public:
    /**
     * @brief 获取主城列表
     * @return
     */
    const NFShmHashSet<uint64_t, MAX_MAP_MAP_NUM> &GetMainCityLst() { return m_setMainCity; }

    /**
     * @brief 是否是动态地图
     * @param mapId
     * @return
     */
    bool IsDynamic(int64_t mapId);

    /**
     * @brief 是否是活动特殊地图
     * @param mapId
     * @return
     */
    bool IsActSpecMap(int64_t mapId);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool IsCrossBossDupMap(int64_t mapId);

    /**
     * @brief 是否是主城
     * @param mapId
     * @return
     */
    bool IsMainCity(int64_t mapId);
    bool IsMainCity(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief 是否是1v1准备场景
     * @param mapId
     * @return
     */
    bool Is1v1Ready(int64_t mapId);
    bool Is1v1Ready(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief 获取 1v1 准备场景ID
     * @return
     */
    uint64_t Get1v1ReadyMap() { return m_1v1ReadyMapId; }

    /**
     * @brief 是否是青云之巅地图
     * @param mapId
     * @return
     */
    bool IsQyActMap(int64_t mapId);
    bool IsQyActMap(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool Is3v3WaitMap(int64_t mapId);
    bool Is3v3WaitMap(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool Is3v3Map(int64_t mapId);
    bool Is3v3Map(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief 是否是西游准备地图
     * @param mapId
     * @return
     */
    bool IsXiYouReadyMap(int64_t mapId);
    bool IsXiYouReadyMap(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool IsXiYouKillBossMap(int64_t mapId);
    bool IsXiYouKillBossMap(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool IsXiYouRouBaoZiMap(int64_t mapId);
    bool IsXiYouRouBaoZiMap(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool IsXiYouCaiJiMap(int64_t mapId);
    bool IsXiYouCaiJiMap(const proto_ff_s::E_MapMap_s* pCfg);

    /**
     * @brief
     * @param mapId
     * @return
     */
    bool IsSafeMap(int64_t mapId);
    bool IsSafeMap(const proto_ff_s::E_MapMap_s* pCfg);

    uint64_t GetQyActMap() { return m_qyMapId; }

    uint64_t Get3v3WaitMap() { return m_3v3WaitMapId; }

    uint64_t Get3v3Map() { return m_3v3MapId; }

    uint64_t GetSafeMap() { return m_safeMapId; }

private:
    NFShmHashMap<uint64_t, VecPosCfg, MAX_MAP_MAP_NUM> m_bornPosMap;
    NFShmHashMap<uint64_t, uint64_t, 10> m_bornProfMap;
private:
    NFShmHashMap<uint64_t, NFPointCfg, MAX_MAP_MAP_NUM * 10> m_pointMap;
    NFShmHashMap<uint64_t, NFAreaCfg, MAX_MAP_MAP_NUM * 10> m_areaMap;
    NFShmHashMap<uint64_t, NFPathCfg, MAX_MAP_MAP_NUM * 10> m_pathMap;

    NFShmHashSet<uint64_t, MAX_MAP_MAP_NUM> m_setMainCity; //主城地图
    uint64_t m_1v1ReadyMapId;//1v1准备地图ID
    uint64_t m_qyMapId;
    uint64_t m_3v3WaitMapId;
    uint64_t m_3v3MapId;
    uint64_t m_safeMapId;
};
