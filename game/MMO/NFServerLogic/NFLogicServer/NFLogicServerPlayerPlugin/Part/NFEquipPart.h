// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFPart.h"
#include "NFLogicCommon/NFItemDefine.h"
#include "NFLogicCommon/NFEquipDefine.h"

class NFEquipPart : public NFPart
{
    struct stEquipLvAttrInfo
    {
        stEquipLvAttrInfo()
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
            type = 0;
            id = 0;
            return 0;
        }

        int ResumeInit()
        {
            return 0;
        }

        int32_t type;
        int32_t id;
    };

public:
    NFEquipPart();

    virtual ~NFEquipPart();

    int CreateInit();

    int ResumeInit();

public:
    //******************part调用生物接口******************
    //生物init调用
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);

    //生物uint调用
    virtual int UnInit();

public:
    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();

    /**
     * @brief  登陆入口
     * @param playerInfo
     * @return
     */
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo) { return 0; };

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }

    /**
     * @brief
     * @param outproto
     */
    virtual void SetFacadeProto(proto_ff::RoleFacadeProto &outproto);

    /**
     * @brief 进入场景携带的数据
     * @param outproto
     */
    virtual void SetEnterSceneProto(proto_ff::RoleEnterSceneData &outproto);

    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyUpdate(uint64_t unixSec) { return 0; }

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekUpdate(uint64_t unixSec) { return 0; }
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate(uint64_t unixSec) { return 0; }

    /**
     * @brief 每日零点 刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate(uint64_t unixSec) { return 0; }

public:
    /**
     * @brief update
     * @param tick
     */
    virtual int Update(uint64_t tick) { return 0; }

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);

public:
    static int RegisterClientMessage(NFIPluginManager *pPluginManager);

    static int RegisterServerMessage(NFIPluginManager *pPluginManager);

public:
public:
    bool ValidPos(int32_t pos);

    stDressEquipInfo *GetEquip(int32_t pos);

    int ProcessStoveAttr(int32_t level, bool bAdd, bool bSync = true);

public:
    int SendAllEquip();                                                //发送所有装备
    int SendLvAttr();

    int SendEquip(int32_t pos);                                        //更新单个装备
    int SendEquip(VEC_INT16 vec_pos);                                    //更新某些装备
    int calcEquipScore(int32_t pos);                                    //计算评分
    int calcAttr(bool sync);                                            //计算属性
    int calcDressAttr(MAP_INT32_INT64 &outAttr);                        //计算身上穿戴的属性
    int calcStrongAttr(MAP_INT32_INT64 &outAttr);                        //计算强化属性加成
    int calcStoneAttr(MAP_INT32_INT64 &outAttr);                        //计算宝石属性加成
    int calcTotalAttr(MAP_INT32_INT64 &outAttr);                        //计算总等级加成
    int calcStoveAttr(MAP_INT32_INT64 &outAttr);                        //计算熔炉等级加成
    int calcWashAttr(MAP_INT32_INT64 &outAttr);                        //计算洗练属性
    int calcSuitAttr(MAP_INT32_INT64 &outAttr);                        //计算套装属性
    int CalcSuitAttrEx(MAP_INT32_INT64 &outAttr, const VEC_INT32 &vecPos, int32_t type);                            //计算套装属性
private:
    VecDressEquip m_equips;                                    //已穿戴的装备
    NFShmHashMap<int32_t, stEquipLvAttrInfo, 5> m_lvAttr;                        //type->等级加成属性
    uint32_t m_stoveLevel;                               //熔炉等级
    uint64_t m_stoveExp;                               //熔炉经验
    NFShmHashMap<uint32_t, uint64_t, DEFINE_E_EQUIPSTOVEATT_M_ATTRIBUTE_MAX_NUM> m_mapStoveAttr;//熔炉带来的属性
private:
DECLARE_IDCREATE(NFEquipPart)
};