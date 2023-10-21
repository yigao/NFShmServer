// -------------------------------------------------------------------------
//    @FileName         :    NFAttrMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFAttrMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmStaticList.hpp"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "Com.pb.h"
#include "NFAttr.h"

class NFAttrMgr : public NFShmObj
{
public:
    NFAttrMgr();

    virtual ~NFAttrMgr();

    int CreateInit();

    int ResumeInit();

    bool Init();   //初始化
    bool UnInit();
public:
    //是否是战斗属性ID
    bool ValidFightAttrId(uint32_t ANum);

    //是否是普通属性ID
    bool ValidCommonAttrId(uint32_t ANum);


    //是否是 通用战斗属性ID
    bool IsComFightAttr(uint32_t ANum);

    //是否是通用的战斗属性组ID
    bool IsComFightAttrGroup(uint32_t groupid);

    //根据 战斗属性ID获取 通用战斗属性数组的索引
    uint8_t GetComFightIndex(uint32_t ANum);

    //根据 通用战斗属性数组的索引 获取 战斗属性ID
    uint32_t GetComFightAttr(uint8_t index);


    //是否是 角色战斗属性ID
    bool IsRoleFightAttr(uint32_t ANum);

    //是否是 角色战斗属性组ID
    bool IsRoleFightAttrGroup(uint32_t groupid);

    //根据 战斗属性ID获取 角色战斗属性数组的索引
    uint8_t GetRoleFightIndex(uint32_t ANum);

    //根据 角色战斗属性数组的索引 获取 战斗属性ID
    uint32_t GetRoleFightAttr(uint8_t index);

    //是否是通用  普通属性ID
    bool IsComAttr(uint32_t ANum);

    //根据属性ID 获取普通属性数组的索引
    uint16_t GetComIndex(uint32_t ANum);

    //根据 普通属性数组的索引 获取属性ID
    uint32_t GetComAttr(uint16_t index);


    //是否是角色  普通属性ID
    bool IsRoleAttr(uint32_t ANum);

    //根据属性ID 获取角色 普通属性数组的索引
    uint16_t GetRoleIndex(uint32_t ANum);

    //根据 角色普通属性数组的索引 获取属性ID
    uint32_t GetRoleAttr(uint16_t index);

    //
    IFightAttr *MakeFightAttrObj(EAttrType type);

    void FreeFightAttrObj(IFightAttr *obj);

    IAttr *MakeAttrObj(EAttrType type);

    void FreeAttrObj(IAttr *obj);

public:
    //是否需要同步到客户端的属性
    bool IsSynClient(uint32_t ANum);

    //是否需要广播到客户端
    bool IsBroadClient(uint32_t ANum);

    //获取玩家视野数据中用到的属性ID
    const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &PlayerViewAttr();

    //获取怪物视野数据中用到的属性ID
    const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &MonViewAttr();

    //伙伴视野数据中用到的属性ID
    const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &PartnerViewAttr();

    //需要同步给的战斗服务器属性用到的 属性ID
    const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &GameSyncAttr();
public:
    //初始化战斗属性和索引之间的映射
    bool InitFightAttrToIndex();

private:
protected:
    //同步到客户端的属性
    //对应属性索引所在元素值为0表示不需要同步到客户端, 为1表示需要同步到客户端
    int8_t m_arySynClient[proto_ff::A_COMMON_END];
    //需要广播到客户端的属性
    int8_t m_aryBroadClient[proto_ff::A_COMMON_END];
    //玩家视野数据中用到的 属性ID
    NFShmHashSet<int32_t, proto_ff::A_COMMON_END> m_setPlayerViewAttr;
    //怪物视野数据中用到的 属性ID
    NFShmHashSet<int32_t, proto_ff::A_COMMON_END> m_setMonsViewAttr;
    //伙伴视野数据中用到的 属性ID
    NFShmHashSet<int32_t, proto_ff::A_COMMON_END> m_setPartnerViewAttr;
    //需要同步给的战斗服务器属性用到的 属性ID
    NFShmHashSet<int32_t, proto_ff::A_COMMON_END> m_setGameSyncAttr;

    //通用的 配置表中的 战斗属性ID 和 程序中使用的 通用战斗属性数组的索引 之间的映射
    uint8_t m_comIdToIndex[proto_ff::A_FIGHT_END];
    uint8_t m_comIndexToId[proto_ff::A_FIGHT_END];

    //配置表中的 战斗属性 和 程序中使用的 角色战斗属性数组的索引 之间的映射
    uint8_t m_roleIdToIndex[proto_ff::A_FIGHT_END];
    uint8_t m_roleIndexToId[proto_ff::A_FIGHT_END];

    //通用的 配置表中的 普通属性ID 和 程序中使用的 通用普通属性数组的索引 之间的映射
    uint16_t m_comNormal_IdToIndex[proto_ff::A_COMMON_END];
    uint16_t m_comNormal_IndexToId[proto_ff::A_COMMON_END];

    //配置表中的 普通属性ID 和 程序中使用的 角色普通属性数组的索引 之间的映射
    uint16_t m_roleNormal_IdToIndex[proto_ff::A_COMMON_END];
    uint16_t m_roleNormal_IndexToId[proto_ff::A_COMMON_END];
DECLARE_IDCREATE(NFAttrMgr)
};