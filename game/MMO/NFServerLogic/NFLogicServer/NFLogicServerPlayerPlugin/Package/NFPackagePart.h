// -------------------------------------------------------------------------
//    @FileName         :    NFPackagePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackagePart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFBagPage.hpp"

class NFPackagePart : public NFShmObjTemplate<NFPackagePart, EOT_LOGIC_PART_ID + PART_PACKAGE, NFPart>
{
public:
    NFPackagePart();
    
    virtual ~NFPackagePart();
    
    int CreateInit();
    
    int ResumeInit();
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData &data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData &data);
    
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
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);
    
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
    
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }
    
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }
    
    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto &outproto) { return 0; }

public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();
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
private:
    ////////////////////////////////////  玩家背包逻辑  //////////////////////////////////////
    //信息
    int PackageInfo(uint32_t msgId, NFDataPackage &packet);
    //整理
    int ItemSort(uint32_t msgId, NFDataPackage &packet);
    //出售
    int ItemSell(uint32_t msgId, NFDataPackage &packet);
    //使用
    int ItemUse(uint32_t msgId, NFDataPackage &packet);
    //扩展
    int ExpandReq(uint32_t msgId, NFDataPackage &packet);
public:
    virtual uint32_t GetLastErrorCode();
    virtual uint32_t GetPackageNotSpaceErrorCode(uint32_t nPackageType);
    
    ///////////////////////////////// IPackage   /////////////////////////////////////////
    //获取指定物品数量
    virtual int64_t GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //是否存在物品
    virtual bool HasItem(LIST_ITEM &lstItem);
    //移除物品
    virtual bool RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t) EBindState::EBindState_all);
    //移除物品 sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam);
    //移除物品
    virtual bool RemoveItem(uint32_t nPackageType, LIST_ITEM &lstItem, SCommonSource &sourceParam);
    //移除物品 index,num sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItemByIndex(uint32_t nPackageType, uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam);
    //移除物品 index-num nGetType : 物品移除来源（暂时没有）
    virtual bool RemoveItem(uint32_t nPackageType, MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam);
    
    //是否能添加物品
    virtual bool CanAddItem(LIST_ITEM &lstItem);
    //能否添加物品
    virtual bool CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx);
    //添加物品
    virtual bool AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t) EBindState::EBindState_no);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update = true, bool tip = true);
    
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）,这个接口是通过传进来的物品顺序添加前端物品tip提示
    virtual bool AddItemEx(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam);
    //添加物品 sourceParam : 物品来源（暂时没有） vecProtoItemsOut:传出参数，外部需要的物品数据
    virtual bool AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //清空背包所有物品
    virtual bool ClearPackage();
    
    //扩展背包
    virtual int32_t Expand(int32_t &nNum);
    //扩展仓库
    virtual int32_t ExpandStorage(int32_t &nNum);
    
    //获取索引位置物品
    virtual NFItem *GetItem(uint16_t nIndex);
    virtual NFItem *GetItem(uint32_t packageType, uint16_t nIndex);
    virtual NFItem *GetPackageItemByIndex(uint32_t nPackageType, uint32_t nIndex);
    // 	//获取第一个指定ID的物品
    virtual NFItem *GetFirstItemById(uint32_t nPackageType, uint64_t item_id);
    //移除所有指定类型的物品（根据 tem.xlsx 表中 subType 字段 移除物品）
    virtual bool RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam);
    virtual bool RemoveAllByType(uint32_t nPackageType, int32_t itemSubType, SCommonSource &sourceParam);
    //使用物品 跟背包无关的使用物品接口 nNum:使用的数量,protoArg:使用物品需要的参数
    virtual int32_t UseItem(NFItem *pItem, int64_t &nNum, proto_ff::UseItemArgProto &protoArg);
    //使用物品 nIndex:物品所在背包索引,nNum:使用的数量,protoArg:使用物品需要的参数
    virtual int32_t UseItem(uint16_t nIndex, int64_t &nNum, proto_ff::UseItemArgProto &protoArg);
    //仓库或背包容量全部开启
    virtual void AllOpenGrid(uint32_t nPackageType);
    
    //获取标签页空格子索引列表 nNum:为0表示标签页所有的空格子，大于0时 只返回 nNum 个空格子
    bool GetEmptyGrid(uint32_t nPackageType, VEC_UINT16 &vecGrid);
    int32_t GetEmptyGrid(uint32_t nPackageType);
    //设置物品
    uint16_t SetItemByIndex(uint32_t nPackageType, uint16_t nIndex, const NFItem& item);
    uint16_t SetItemByIndex(uint32_t nPackageType, uint16_t nIndex, const NFItem* pItem);
    //整理
    void ItemSortByPackageType(uint32_t nPackageType);
    //更新背包物品
    void SendUpdatePackageByIndex(uint32_t nPackageType, NFItem *pItem, bool bDel);
    
    //添加背包更新信息
    bool AddPackageUpdateInfo(NFItem *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel = false);
    void UpdatePackage(uint32_t nPackageType, proto_ff::NotifyPackageUpdate &ret);


private:
    
    //通过包裹类型获取物品 byPackageType:包裹类型 详见 EPackageType枚举, nIndex:对应包裹类型格子索引
    NFItem *GetItemByPackageType(int8_t byPackageType, uint16_t nIndex);
    // 通过包裹类型设置物品 :包裹类型 详见 EPackageType枚举 , nIndex:对应包裹类型格子索引
    uint16_t SetItemByPackageType(int8_t byPackageType, uint16_t nIndex, const NFItem& item);
    
    //通过包裹类型判断是否是有效的索引
    bool ValidIndexByPackageType(uint16_t nIndex, int8_t byPackageType);
    //是否是有效的包裹类型
    bool ValidPackageType(int8_t byPackageType);
    
    //第一次登陆
    void FirstLogin();
    ////////////////////////////////  仓库接口 //////////////////////////////////////////
    //仓库操作（移入，移出）
    void StorageOperate(const char *data, uint32_t len);

private:
    //设置更新信息
    bool SetUpdateItemInfo(NFItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel = false);
    
    //清空索引记录
    void ClearIdxRecord();
    //get 索引记录
    SET_UINT16 &GetIdxRecord();

public:
    virtual void OnUseItem(uint64_t nItemId, uint32_t num);
    bool AddItemAttr(uint64_t nItemId, uint32_t nTimes);
    NFPackageBag* GetPackageByType(uint32_t nPackageType);
private:
    
    //设置背包数据保存标记
    void SetPackageSaveFlag(bool saveFlag);
    bool IsValidPackage(uint32_t nPackageType);
    NFPackageBag *GetPackageByItemID(uint64_t nItemID);
    NFPackageBag *GetItemPackageBag(uint64_t nItemID);
    uint32_t GetItemPackageType(uint64_t nItemID);
private:
    NFBagPage<NFEquip, proto_ff::EPackageType_Common, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM> m_commonBag;
    NFBagPage<NFEquip, proto_ff::EPackageType_Storage, STORAGE_PACKAGE_INIT_GRID_NUM, STORAGE_PACKAGE_MAX_GRID_NUM> m_storeageBag;
    NFBagPage<NFItem, proto_ff::EPackageType_MountEgg, MOUNT_PACKAGE_INIT_GRID_NUM, MOUNT_PACKAGE_MAX_GRID_NUM> m_mountEggBag;
    NFBagPage<NFItem, proto_ff::EPackageType_PetEgg, EGG_BAG_SIZE, EGG_BAG_SIZE> m_petEggBag;
    NFBagPage<NFDeityEquip, proto_ff::EPackageType_DeityEquip, DEITY_EQUP_PACKAGE_INIT_GRID_NUM, DEITY_EQUIP_PACKAGE_MAX_GRID_NUM> m_deityBag;
    NFBagPage<NFItem, proto_ff::EPackageType_HandBook, HANDBOOK_PACKAGE_INIT_GRID_NUM, HANDBOOK_PACKAGE_MAX_GRID_NUM> m_handBookBag;
    NFBagPage<NFBeastEquip, proto_ff::EPackageType_BeastEquip, BEAST_EQUP_PACKAGE_INIT_GRID_NUM, BEAST_EQUIP_PACKAGE_MAX_GRID_NUM> m_beastEquipBag;
    NFBagPage<NFLongHunEquip, proto_ff::EPackageType_Longhun, LONG_HUN_PACKAGE_INIT_GRID_NUM, LONG_HUN_PACKAGE_MAX_GRID_NUM> m_longHunEquipBag;
    NFBagPage<NFEquip, proto_ff::EPackageType_FindTreasure, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM> m_findTreasureBag;
    NFBagPage<NFEquip, proto_ff::EPackageType_BigDragon, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM> m_bigDragonBag;
    NFBagPage<NFShengjiEquip, proto_ff::EPackageType_shenji_aq, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM> m_shengjiAqBag;
    NFBagPage<NFShengjiEquip, proto_ff::EPackageType_shenji_lj, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM> m_shengjiLjBag;
    NFBagPage<NFGodEvilEquip, proto_ff::EPackageType_GodEvil, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM> m_godEvilBag;
    NFBagPage<NFStarEquip, proto_ff::EPackageType_star, STAR_HUN_PACKAGE_MAX_GRID_NUM, STAR_HUN_PACKAGE_MAX_GRID_NUM> m_starBag;
    NFBagPage<NFTurnEquip, proto_ff::EPackageType_turn, TURN_PACKAGE_MAX_GRID_NUM, TURN_PACKAGE_MAX_GRID_NUM> m_turnBag;
    NFBagPage<NFMountKunEquip, proto_ff::EPackageType_MountKun, MOUNT_KUN_PACKAGE_MAX_GRID_NUM, MOUNT_KUN_PACKAGE_MAX_GRID_NUM> m_mountKunBag;
    NFBagPage<NFYaoHunEquip, proto_ff::EPackageType_YaoHun, COM_BAG_SIZE, COM_BAG_SIZE> m_yaoKunBag;
    NFBagPage<NFMoFaEquip, proto_ff::EPackageType_MoFa, COM_BAG_SIZE, COM_BAG_SIZE> m_moFaBag;
    NFBagPage<NFEquip, proto_ff::EPackageType_hungu, COM_BAG_SIZE, COM_BAG_SIZE> m_hunguBag;
    NFBagPage<NFEquip, proto_ff::EPackageType_rune, COM_BAG_SIZE, COM_BAG_SIZE> m_runeBag;
    
    uint32_t m_nLastErrorCode;
    SET_UINT16 m_setIdxRecord;                        //记录每次加物品 数量有增加的格子索引，在每次加物品之前先清空
};