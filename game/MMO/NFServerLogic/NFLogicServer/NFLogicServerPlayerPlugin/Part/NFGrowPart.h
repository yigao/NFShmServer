// -------------------------------------------------------------------------
//    @FileName         :    NFGrowPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFPart.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "Grow.pb.h"

class NFGrowPart : public NFPart
{
public:
public:
    //部件元素
    struct  GrowPartEntry
    {
        GrowPartEntry()
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
            id = 0;
            lv = 0;
            return 0;
        }

        int ResumeInit()
        {
            return 0;
        }

        int64_t id = 0;
        int32_t lv = 0;
    };
    typedef NFShmHashMap<int64_t, GrowPartEntry, 10> GrowPartEntryMap;
    //养成部件
    struct GrowPartData
    {
        GrowPartData()
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
            curId = 0;
            return 0;
        }

        int ResumeInit()
        {
            return 0;
        }

        int32_t type;
        GrowPartEntryMap entryMap;
        int64_t curId;
        GrowPartEntry* GetPartEntry(int64_t id);
        void SetPartEntry(GrowPartEntry& entry);
    };
    typedef NFShmHashMap<int32_t, GrowPartData, proto_ff::GrowType_MAX> GrowPartMap;
public:
    NFGrowPart();

    virtual ~NFGrowPart();

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
    virtual void SetEnterSceneProto(proto_ff::RoleEnterSceneData& outproto);

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
    static int RegisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType);

    static int RegisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType);
public:
    int FillProto(const GrowPartData& part, proto_ff::GrowSubInfo& proto);
    GrowPartData* getPart(int32_t type);
public:
    int SendAllGrowData();										//发送全部数据
    int SendGrowPartData(int32_t type);						//发送某个部件数据
public:
    void calcAttr(bool sync);
    void calcAttr(int32_t type, MAP_INT32_INT64& outAttr);		//计算养成部件属性
    void MergeAttr(MAP_INT32_INT64& src, MAP_INT32_INT64& dst);
    void PrintAttr(int32_t type, MAP_INT32_INT64& attr);
private:
    void initParts();
protected:
    GrowPartMap m_partsMap;					//所有养成的部件
private:
DECLARE_IDCREATE(NFGrowPart)
};