// -------------------------------------------------------------------------
//    @FileName         :    NFMovePart.h
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFMovePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFBattlePart.h"
#include "NFLogicCommon/NFPoint3.h"
#include "NFPath.h"
#include "Move.pb.h"

class NFScene;

class NFMovePart : public NFBattlePart
{
    enum
    {
        INTERVAL_MOVE_TIME = 100,//模拟行走定时器间隔

        INTERVAL_CLIENT_MOVE_TIMEOUT = 3000, //客户端移动同步超时时间

        INTERVAL_LOAD_MAP_TIMEOUT = 20000, //加载地图超时时间
    };
public:
    NFMovePart();

    virtual ~NFMovePart();

    int CreateInit();

    int ResumeInit();

public:
    virtual int Init(const proto_ff::RoleEnterSceneData &data);

    virtual int UnInit();

    virtual int OnTimer(int timeId, int callcount);

public:
    //移动定时器
    int OnMoveTimer();

    //通过路径移动 intertick: 间隔时间，单位：毫秒
    int MoveByPath(int64_t intertick, bool stopFlag = false);

    //模拟客户端移动(玩家移动) intertick: 间隔时间，单位：毫秒,  stopFlag:是否停止移动
    int MoveBySimulate(int64_t intertick, bool stopFlag = false);

    //计算朝向
    NFPoint3<float> CalDir(const NFPoint3<float> &dstpos, const NFPoint3<float> &srcpos);

    //根据计算单位朝向
    NFPoint3<float> CalDotByDir(const NFPoint3<float> &dir);

    //根据朝向点计算速度  dot:朝向点， fsec:间隔时间，单位：秒，  fspeed：速度，单位：m/s
    NFPoint3<float> CalSpeedByDot(const NFPoint3<float> &dot, float fsec, float fspeed);

public:
    //能否移动
    int CanMove();

    //移动到目标坐标，注意：这个接口只允许人物以外的生物调用，人物的移动是前端驱动的
    int MoveTo(const NFPoint3<float> &dstPos);

    //是否正在移动
    int IsMoving() const;

    //停止移动
    int StopMove();

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

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);

public:
    int ClientMoveReq(uint32_t msgId, NFDataPackage &packet);

    int ClientLoadMapFinshReq(uint32_t msgId, NFDataPackage &packet);

    int ClientSeatReq(uint32_t msgId, NFDataPackage &packet);

public:
    //设置客户端速度
    void SetClientSpeed(const NFPoint3<float> &speed);

    //广播移动
    int BroadcastMove(uint64_t cid, const NFPoint3<float> &pos, const NFPoint3<float> &speed, const NFPoint3<float> &dir, bool selfFlag = false);

    //传送(场景内传送、切场景传送,跨逻辑服传送)
    int TransScene(uint64_t sceneId, const NFPoint3<float> &dstPos, uint64_t mapId, STransParam &transParam);

    //瞬间移动，只限于当前地图之内 dstPos:目标坐标  type:瞬移类型  checkpos:是否需要校验坐标，如果外部可以保证坐标的有效性可以不用校验，外部不能保证坐标的有效性，必须要校验
    int Teleporting(const NFPoint3<float> dstPos, int32_t type = (int32_t) proto_ff::MoveTeleportRsp_Type_common, bool checkpos = true);

    //传送成功的处理
    int OnTransSuccess(STransParam &transParam);

    //同一个逻辑服之间的场景传送
    int TransSceneInLogic(NFScene *pDstScene, NFPoint3<float> transPos, STransParam &transParam);

private:
    /**
     * @brief 客户端最近一次发到服务器的坐标
     */
    NFPoint3<float> m_lastClientPos;

    /**
     * @brief 客户端最近一次发送移动消息的时间, 用于处理移动同步超时的情况， 单位：毫秒
     */
    uint64_t m_lastclientMoveTick;

    /**
     * @brief 客户端移动速度(矢量坐标，计算用的)
     */
    NFPoint3<float> m_clientSpeed;

    /**
     * @brief 客户端速度的单位向量
     */
    NFPoint3<float> m_clientUnitVector;

    /**
     * @brief 最近一次正确的坐标，用于出错时回退上上一次正确坐标的位置
     */
    NFPoint3<float> m_lastrightpos;

    /**
     * @brief 最近一次生物的朝向
     */
    NFPoint3<float> m_lastDir;

    /**
     * @brief 最近一次的朝向点，用来比较怪物两次行走中朝向是否有改变
     */
    NFPoint3<float> m_lastDirDot;

    /**
     * @brief 路径
     */
    NFPath m_curMovePath;


    /**
     * @brief 最近一次移动的时间点，模拟走用，单位：毫秒
     */
    uint64_t m_moveTick;

    /**
     * @brief 等待客户端加载地图完成的消息
     */
    uint64_t m_waitLoadMapId;
public:
    int m_timerIdMove;
    int m_timerIdLoadMapTimeout;
DECLARE_IDCREATE(NFMovePart)
};