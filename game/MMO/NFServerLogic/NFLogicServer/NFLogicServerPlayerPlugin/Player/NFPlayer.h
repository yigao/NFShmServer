// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetail.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFUserDetail.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFCore/NFTime.h"
#include "DBProto.pb.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "NFPlayerBase.h"
#include "NFLogicCommon/NFAttr.h"
#include "DBProto2.pb.h"

enum
{
    PLAYER_UID_INDEX = 0,
    PLAYER_MAX_INDEX = 1,
};

class NFPlayer : public NFShmObj, public NFPlayerBase
{
public:
    NFPlayer();

    virtual ~NFPlayer();

    int CreateInit();

    int ResumeInit();

    int Tick();

    int Update();

public:
    int Init(const ::proto_ff::RoleDBData &dbData);

    int UnInit();

    //存储DB部件入口
    virtual int SaveDB(proto_ff::RoleDBData &dbData) override;
    virtual void SetFacadeProto(proto_ff::RoleFacadeProto& outproto) override;
    virtual void SetEnterSceneProto(proto_ff::RoleEnterSceneData& outproto) override;

    //////////////////////////////每日每周刷新接口///////////////////////////////
    /**
     * @brief 每日每周刷新接口 策划配置，几点
     * @param unixSec
     */
    int DailyUpdate(uint64_t unixSec);

    /**
     * @brief 每日每周刷新接口 策划配置，几点
     * @param unixSec
     */
    int WeekUpdate(uint64_t unixSec);
    //////////////////////////////每日零点 每周一零点 刷新接口///////////////////////////////

    /**
     * @brief 每日零点 每周一零点 刷新接口
     * @param unixSec
     */
    int DailyZeroUpdate(uint64_t unixSec);

    /**
     * @brief 每日零点 每周一零点 刷新接口
     * @param unixSec
     */
    int WeekZeroUpdate(uint64_t unixSec);

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);
public:
    bool IsInBattle() { return false; }
    NFPart *CreatePart(uint32_t partType, const ::proto_ff::RoleDBData &dbData);
    int RecylePart(NFPart *pPart);
public:
    virtual uint32_t GetCurRoleDetailSeq() const override;
public:
    int OnLoad(bool isLoadDB);

    int OnLogin(bool isLoadDB);

    int OnLogout();

    int OnDisconnect(uint32_t reason);

    int OnReconnect();

public:
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);

    int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToSnsServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToWorldServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToGameServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

public:
    /**
     * @brief
     * @param mapId
     * @param scenceId
     * @param dstPos
     * @return
     */
    int EnterScene(uint64_t mapId, uint64_t scenceId, const NFPoint3<float>& dstPos);

    /**
     * @brief
     * @return
     */
    int NotifyPlayerInfo();

    /**
     * @brief
     * @param loginInfo
     * @param change
     * @return
     */
    int LoginGame(const CharLoginInfo& loginInfo, bool change);
public:
    //////////////////////////////////////////////////////////////////////////
    //增加属性 主要是为了增加虚拟物品相关的属性 costFlag:是否是扣除属性
    virtual void AddVirAttr(MAP_UINT32_INT64 &mapAttr, bool costFlag = false, SCommonSource *pSource = nullptr, bool syn = false);
    //属性是否足够，主要是为了属性虚拟物品的判断
    virtual bool EnoughVirAttr(MAP_UINT32_INT64 &mapAttr);

    //增加属性
    virtual bool AddAttr(uint32_t ANum, int64_t attrValue, SCommonSource* pSource = nullptr, bool syn = false);
    //增加属性 不同步到客户端
    virtual bool AddAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    //能否增加属性
    virtual bool CanAddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    //增加属性处理
    virtual void OnAddAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource = nullptr);
    //设置属性
    virtual bool SetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr, bool syn = false);
    //设置属性 不同步客户端
    virtual bool SetAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    //能否设置属性
    virtual bool CanSetAttr(uint32_t ANum, int64_t attrValue, SCommonSource* pSource = nullptr);
    //设置属性处理
    virtual void OnSetAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource* pSource = nullptr);


    //获取该组属性值
    virtual int64_t GetAttrGroup(uint32_t attrGroup, uint32_t ANum);
    //清除某一组属性
    virtual bool ClearAttrGroup(uint32_t attrGroup, SCommonSource *pSource = nullptr, bool syn = false);
    virtual bool ClearAttrGroupCache(uint32_t attrGroup, SCommonSource* pSource = nullptr);
    //增加属性组属性
    virtual bool AddAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource* pSource = nullptr, bool syn = false);
    virtual bool AddAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource* pSource = nullptr);
    //设置属性组属性
    virtual bool SetAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource* pSource = nullptr, bool syn = false);
    virtual bool SetAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource* pSource = nullptr);


    //计算属性
    virtual void CalcAttr(uint32_t ANum);
    //计算属性组属性 主要是把属性组中的属性汇总到总属性中 ANum:属性组中的属性ID
    virtual void CalcAttrGroup(uint32_t attrgroup, uint32_t ANum, MAP_UINT32_INT64 &mapchg);
    //获取属性值
    virtual int64_t GetAttr(uint32_t ANum);

    //属性改变
    virtual void OnAttrChange(int32_t ANum, int64_t oldVal, int64_t newVal, SCommonSource* pSource = nullptr);
    void CheckExp(int64_t oldexp, SCommonSource *pSource);
    void CalcLevelAttr(bool sync);

public:
    void SynAttrToClient();
public:
    template<typename PART>
    PART* GetPart(uint32_t partType)
    {
        return dynamic_cast<PART*>(GetPart(partType));
    }

    NFPart* GetPart(uint32_t partType);
private:
    NFShmVector<NFShmPtr<NFPart>, PART_MAX> m_pPart;
DECLARE_IDCREATE(NFPlayer)
};
