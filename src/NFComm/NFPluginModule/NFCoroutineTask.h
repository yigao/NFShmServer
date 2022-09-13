// -------------------------------------------------------------------------
//    @FileName         :    NFCoroutineSchedule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <functional>

#ifdef Yield
#undef Yield
#endif

/// 用户使用协程时继承该类, 实现Run方法完成协程的使用
class NFCoroutineTask {
public:
    /// @brief 构造函数
    NFCoroutineTask();

    /// @brief 析构函数
    virtual ~NFCoroutineTask();

    /// @brief 启动该协程任务, 执行Run方法
    /// @param is_immediately 是否立即执行
    /// @return 返回协程ID
    int64_t Start(bool is_immediately = true);

    /// @brief 协程任务的执行体, 要由使用者进行具体实现
    /// @note 在子类中实现该函数, 在函数体内可调用Yield
    virtual void Run() = 0;

    /// @brief 获得本协程任务的协程ID
    /// @return 协程ID
    inline int64_t id() {
        return id_;
    }

    /// @brief 挂起此协程
    /// @param timeout_ms 超时时间，单位为毫秒，默认-1，<0时表示不进行超时处理
    /// @return 处理结果，@see CoroutineErrorCode
    /// @note 此函数必须在协程中调用
    int32_t Yield(int32_t timeout_ms = -1);
public:
    int64_t id_;
};

/// @brief 基于function的通用的协程任务实现
class NFCommonCoroutineTask : public NFCoroutineTask {
public:
	NFCommonCoroutineTask() {}
	NFCommonCoroutineTask(const std::function<void(void)>& run):m_run(run) {}

    virtual ~NFCommonCoroutineTask() {}

    void Init(const std::function<void(void)>& run) { m_run = run; }

    virtual void Run() {
        m_run();
    }

private:
    std::function<void(void)> m_run;
};
