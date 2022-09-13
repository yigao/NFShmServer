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
#include "NFCoroutine.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include <unordered_map>
#include <set>

class NFSchedule;

#ifdef Yield
#undef Yield
#endif

class NFCoroutineTask;
class NFCoroutineSchedule;

/// @brief Timer超时回调函数返回码定义
typedef enum {
    kTIMER_BE_REMOVED = -1,   // 超时后timer被停止并remove
    kTIMER_BE_CONTINUED = 0,    // 超时后timer仍然保持，重新计时
    kTIMER_BE_RESETED           // 超时后timer仍然保持，使用返回值作为超时时间(ms)重新计时
} OnTimerCallbackReturnCode;

class NFCoroutineTaskTimer : public NFTimerObj {
    enum EnumNFCoroutineTaskTimer {
        ENUM_NF_COROUTINE_TASK_TIMER_YIELD = 1, //yield time out
    };
public:
    NFCoroutineTaskTimer(NFCoroutineSchedule* pCoSche, int64_t taskId);
    virtual ~NFCoroutineTaskTimer();

    virtual void SetYieldTimeout(int32_t timeout_ms = -1);
    virtual void OnTimer(uint32_t nTimerID);
    virtual void SetDelete();
	virtual bool IsDelete() const { return m_delete; }
private:
    NFCoroutineSchedule* m_pCoSche;
    int64_t m_taskId;
    bool m_delete;
};

/// @brief 类:NFCoroutineSchedule 协程调度类
///
/// 与协程任务类NFCoroutineTask是友员\n
/// 管理和调度协程, 是一个协程系统, 封装schedule, 管理多个协程
class NFCoroutineSchedule : public NFTimerObj {
    friend class NFCCoroutineModule;

public:
    /// @brief 构造函数
    explicit NFCoroutineSchedule();

    /// @brief 析构函数
    virtual ~NFCoroutineSchedule();

	virtual void OnTimer(uint32_t nTimerID);

	virtual void ClearTimer();
public:
    /// @brief 初始化工作, new了一个新的schedule
    /// @param stack_size 协程的栈大小，默认是256k
    /// @return = 0 成功
    /// @return = -1 失败
    int Init(uint32_t stack_size = 256 * 1024);

    /// @brief 关闭协程系统, 释放所有资源
    /// @return 还未结束的协程数
    int Close();

    /// @brief 返回当前协程数量
    /// @return 当前的协程数量
    int Size() const;

    /// @brief 获取当前正在运行的协程任务
    /// @return 正在运行的协程任务对象的指针
    /// @note 此函数必须在协程中调用
    NFCoroutineTask *CurrentTask() const;

    /// @brief 获取当前正在运行的协程ID
    /// @reurn 正在运行的协程ID
    /// @note 此函数必须在协程中调用
    int64_t CurrentTaskId() const;

    /// @brief 挂起当前协程
    /// @param timeout_ms 超时时间，单位为毫秒，默认-1，<=0时表示不进行超时处理
    /// @return 处理结果，@see CoroutineErrorCode
    /// @note 此函数必须在协程中调用
    int32_t Yield(int32_t timeout_ms = -1);

    /// @brief 激活指定ID的协程
    /// @param id 协程ID
    /// @param result resume时可传递结果，默认为0
    /// @return 处理结果，@see CoroutineErrorCode
    int32_t Resume(int64_t id, int32_t result = 0);

    /// @brief 返回指定id协程的状态
    /// @param id 协程ID
    /// @return 协程状态
    int Status(int64_t id);

    int AddTaskToSchedule(NFCoroutineTask *task);
    int32_t OnTimeout(int64_t id);
    NFCoroutineTask *Find(int64_t id) const;
private:
    NFSchedule *schedule_;
    std::unordered_map<int64_t, NFCoroutineTask *> task_map_;
    std::set<NFCoroutineTask *> pre_start_task_;
    std::list<NFCoroutineTaskTimer*> m_taskTimer;
};
