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

class NFMovePart : public NFBattlePart
{
public:
    NFMovePart();

    virtual ~NFMovePart();

    int CreateInit();

    int ResumeInit();

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
     * @brief 移动的定时器是否已经启动
     */
    bool m_moveTimerFlag ;

    /**
     * @brief 最近一次移动的时间点，模拟走用，单位：毫秒
     */
    uint64_t m_moveTick;

    /**
     * @brief 等待客户端加载地图完成的消息
     */
    uint64_t m_waitLoadMapId;
DECLARE_IDCREATE(NFMovePart)
};