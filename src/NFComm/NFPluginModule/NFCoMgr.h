// -------------------------------------------------------------------------
//    @FileName         :    NFCoMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCoMgr.h
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFICoroutineModule.h"

class NFCoroutineTask;

#ifdef Yield
#undef Yield
#endif

class NFCoMgr : public NFSingleton<NFCoMgr> {
public:
    NFCoMgr();

    virtual ~NFCoMgr();

public:
    bool Init(NFICoroutineModule *pModule = nullptr);

    void UnInit();

public:

    /// @brief 启动该协程任务, 执行Run方法
    /// @param is_immediately 是否立即执行
    /// @return 返回协程ID
    int64_t Start(NFCoroutineTask *pTask, bool is_immediately = true);

    int AddTask(NFCoroutineTask *task);

    int DeleteTask(NFCoroutineTask *pTask);

    /// @brief 返回当前协程数量
    /// @return 当前的协程数量
    virtual int Size() const;

    /// @brief 获取当前正在运行的协程任务
    /// @return 正在运行的协程任务对象的指针
    /// @note 此函数必须在协程中调用
    virtual NFCoroutineTask *CurrentTask() const;

    /// @brief 获取当前正在运行的协程ID
    /// @reurn 正在运行的协程ID
    /// @note 此函数必须在协程中调用
    virtual int64_t CurrentTaskId() const;

    /// @brief 挂起当前协程
    /// @param timeout_ms 超时时间，单位为毫秒，默认-1，<=0时表示不进行超时处理
    /// @return 处理结果，@see CoroutineErrorCode
    /// @note 此函数必须在协程中调用
    virtual int32_t Yield(int32_t timeout_ms = -1);

    /// @brief 激活指定ID的协程
    /// @param id 协程ID
    /// @param result resume时可传递结果，默认为0
    /// @return 处理结果，@see CoroutineErrorCode
    virtual int32_t Resume(int64_t id, int32_t result = 0);

    /// @brief 返回指定id协程的状态
    /// @param id 协程ID
    /// @return 协程状态
    virtual int Status(int64_t id);

    /// @brief 模版方法, 新建一个协程任务
    /// @note 使用此种方法生成的task对象指针会在协程结束后自动delete掉
    template<typename TASK>
    TASK *NewTask() {
        if (CurrentTaskId() != -1) {
            return NULL;
        }
        TASK *task = new TASK();
        if (AddTask(task)) {
            delete task;
            task = NULL;
        }
        return task;
    }

    virtual int MakeCoroutine(const std::function<void()> &func);
protected:
    NFICoroutineModule *m_pCoModule;
};