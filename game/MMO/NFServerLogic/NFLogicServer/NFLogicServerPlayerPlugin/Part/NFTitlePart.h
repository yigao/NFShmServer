// -------------------------------------------------------------------------
//    @FileName         :    NFTitlePart.h
//    @Author           :    gaoyi
//    @Date             :    23-2-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFTitlePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "Com_s.h"
#include "DescStore/TitleTitleDesc.h"
#include "NFPart.h"
#include "NFLogicCommon/NFComTypeDefine.h"

class NFTitlePart : public NFPart
{
    typedef NFShmHashMap<uint32_t, uint64_t, 10> ATTR_MAP;
    enum EAttrType
    {
        EAttrType_StarAttr = 0,
        EAttrType_LimitAttr,
    };
public:
    NFTitlePart();

    virtual ~NFTitlePart();

    int CreateInit();

    int ResumeInit();

public:
    static int RetisterClientMessage(NFIPluginManager *pPluginManager);

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);
public:
    //******************part调用生物接口******************
    //生物init调用
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);

    void LoadConfig();

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
    virtual int OnLogin();

    /**
     * @brief  登陆入口
     * @param playerInfo
     * @return
     */
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);
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
    proto_ff_s::TitleInfo_s* GetTitleInfo(uint64_t titleId);
    bool ProcessStarAttr(int64_t titleId, int32_t star, bool bAdd, bool bSync);
public:
    void calcAttr(bool sync);
    void calcAttr(MAP_INT32_INT64& outAttr);
    void MergeAttr(MAP_INT32_INT64& src, MAP_INT32_INT64& dst);
    void PrintAttr(MAP_INT32_INT64& attr);
public:
    int OnHandleTitleInfoReq(uint32_t msgId, NFDataPackage &packet);
    int OnHandleTitleActiveReq(uint32_t msgId, NFDataPackage &packet);
    int OnHandleTitleStarLvReq(uint32_t msgId, NFDataPackage &packet);
    int OnHandleTitleDressReq(uint32_t msgId, NFDataPackage &packet);
    int OnHandleTitleUnDressReq(uint32_t msgId, NFDataPackage &packet);
public:
    void OnDress(uint64_t titleId);
    void UnDress(uint64_t titleId);
private:
    uint64_t m_curWearingTitle;
    NFShmHashMap<uint64_t, proto_ff_s::TitleInfo_s, MAX_TITLE_TITLE_NUM> m_titleMap;
    NFShmHashMap<uint8_t, ATTR_MAP, EAttrType_LimitAttr> m_mapTypeAttr;//不同类型带来的属性
DECLARE_IDCREATE(NFTitlePart)
};