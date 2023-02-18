// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.h
//    @Author           :    gaoyi
//    @Date             :    23-2-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFPart.h"
#include "NFLogicCommon/NFMissionDefine.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"

class NFMissionPart : public NFPart
{
public:
    // eventtype - level - dynamicid
    typedef NFShmHashMap<uint32_t, NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 10>, 10>, 10> EventTabal;


    typedef NFShmHashMap<uint64_t, MissionTrack, 100> PlayerTrackMissionMap;
    typedef NFShmHashMap<int32_t, DyMissionTrack, 100> PlayerDyMissionTrackMap;
public:
    NFMissionPart();

    virtual ~NFMissionPart();

    int CreateInit();

    int ResumeInit();

public:
    static int RetisterClientMessage(NFIPluginManager *pPluginManager);

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);

public:
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

private:
public:
    PlayerTrackMissionMap _playerTrackMissionMap;    //当前任务列表
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, 100> _mapRecentSubmit;        //最近提交的任务
    NFShmHashSet<uint64_t, 100> _setAlreadySubmit;        //已经提交的任务
    //动态任务
    PlayerDyMissionTrackMap _mapDyMissionTrack;        //动态任务数据
    //MissionAllDropMap					_mapMissionAllDrop;		//任务掉落
    //
    EventTabal _eventTabal;            //任务事件表
private:
DECLARE_IDCREATE(NFMissionPart)
};