// -------------------------------------------------------------------------
//    @FileName         :    NFStateBase.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-10-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"

/**
 * @brief 状态基类
 * @tparam T
 */
template<class T>
class NFStateBase
{
public:
    NFStateBase()
    {

    }

    virtual ~NFStateBase()
    {

    }

public:
    /**
     * 进入状态时处理
     * @param owner
     */
    void Enter(T owner)
    {

    }

    /**
     * 退出状态时处理
     * @param owner
     */
    void Exit(T owner)
    {

    }

    /**
     * 从该状态转向下一个状态的处理
     * @param owner
     */
    void ToNextState(T owner)
    {

    }

    /**
     * 执行事件处理
     * @param owner
     * @param cmd
     * @param gid
     * @param param
     */
    void Execute(T owner, uint32_t cmd)
    {

    }

    /**
     * 重连
     * @param owner
     */
    void Reload(T owner)
    {

    }
};


