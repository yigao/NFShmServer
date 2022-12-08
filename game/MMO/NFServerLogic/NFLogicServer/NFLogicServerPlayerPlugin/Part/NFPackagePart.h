// -------------------------------------------------------------------------
//    @FileName         :    NFPackagePart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackagePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/PackageDefine.h"
#include "NFLogicCommon/NFLogDefine.h"
#include "NFLogicCommon/NFItemDefine.h"
#include "NFPart.h"
#include "Part/Package/NFBagPage.h"

class NFPackagePart : public NFPart
{
public:
    NFPackagePart();

    virtual ~NFPackagePart();

    int CreateInit();

    int ResumeInit();

public:
    static int RetisterClientMessage(NFIPluginManager *pPluginManager);

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);
public:
    //******************part调用生物接口******************
    //生物init调用
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);

    //生物uint调用
    virtual int UnInit();

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
    virtual int OnLogin() { return 0; }

    /**
     * @brief  登陆入口
     * @param playerInfo
     * @return
     */
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);

    virtual uint32_t GetCurRoleDetailSeq() const;
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
    /**
     * @brief
     * @param msgId
     * @param packet
     * @return
     */
    virtual int OnHandlePackageInfo(uint32_t msgId, NFDataPackage &packet);

    virtual int OnHandlePackageUseItem(uint32_t msgId, NFDataPackage &packet);

    virtual int OnHandlePackageSortItem(uint32_t msgId, NFDataPackage &packet);
public:
    NFBagPage *GetPackageByType(uint32_t nPackageType);

    NFBagPage *GetPackageByItemID(uint64_t nItemID);

    NFBagPage *GetItemPackageBag(uint64_t nItemID);

    uint32_t GetItemPackageType(uint64_t nItemID);

    NFBagPage *GetCommonPackage() { return &m_commonBag; }

    NFBagPage *GetStoragePackage() { return &m_storageBag; }

    virtual const NFGridItem* GetPackageItemByIndex(uint32_t nPackageType, uint32_t nIndex);
    //获取索引位置物品
    virtual const NFGridItem *GetItem(uint16_t nIndex);
public:
    virtual bool RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam);
    virtual bool RemoveAllByType(uint32_t nPackageType, int32_t itemSubType, SCommonSource &sourceParam);
    //使用物品 跟背包无关的使用物品接口 nNum:使用的数量,protoArg:使用物品需要的参数
    virtual int32_t UseItem(NFGridItem *pItem, int64_t& nNum, proto_ff::UseItemArgProto& protoArg);
    //使用物品 nIndex:物品所在背包索引,nNum:使用的数量,protoArg:使用物品需要的参数
    virtual int32_t UseItem(uint16_t nIndex, int64_t& nNum, proto_ff::UseItemArgProto &protoArg);
public:
    ///////////////////////////////// IPackage   /////////////////////////////////////////
    bool IsValidPackage(uint32_t nPackageType);
    //是否能添加物品
    virtual bool CanAddItem(const LIST_ITEM &lstItem);
    //能否添加物品
    virtual bool CanAddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx);
    //添加物品
    virtual bool AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t) EBindState::EBindState_no);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(const LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update = true, bool tip = true);

    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(const VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）,这个接口是通过传进来的物品顺序添加前端物品tip提示
    virtual bool AddItemEx(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam);
    //添加物品 sourceParam : 物品来源（暂时没有） vecProtoItemsOut:传出参数，外部需要的物品数据
    virtual bool AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, const VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update = true, bool tip = true);
public:
    ///////////////////////////////// IPackage   /////////////////////////////////////////
    //获取指定物品数量
    virtual int64_t GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //是否存在物品
    virtual bool HasItem(LIST_ITEM &lstItem);
    //移除物品
    virtual bool RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t)EBindState::EBindState_all);
    //移除物品 sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam);
    //移除物品
    virtual bool RemoveItem(uint32_t nPackageType, LIST_ITEM &lstItem, SCommonSource &sourceParam);
    //移除物品 index,num sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItemByIndex(uint32_t nPackageType, uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam);
    //移除物品 index-num nGetType : 物品移除来源（暂时没有）
    virtual bool RemoveItem(uint32_t nPackageType, MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam);
public:
    //通过包裹类型获取物品 byPackageType:包裹类型 详见 EPackageType枚举, nIndex:对应包裹类型格子索引
    NFGridItem *GetItemByPackageType(int8_t byPackageType,uint16_t nIndex);
    // 通过包裹类型设置物品 :包裹类型 详见 EPackageType枚举 , nIndex:对应包裹类型格子索引
    uint16_t SetItemByPackageType(int8_t byPackageType, uint16_t nIndex,NFGridItem *pItem);
private:
    NFBagPage m_commonBag;
    NFBagPage m_storageBag;
DECLARE_IDCREATE(NFPackagePart)
};