// -------------------------------------------------------------------------
//    @FileName         :    NFCCoroutineModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCCoroutineModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include <unordered_map>
#include "NFComm/NFPluginModule/NFICoroutineModule.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"

class NFCoroutineSchedule;

class NFCCoroutineModule : public NFICoroutineModule {
public:
    explicit NFCCoroutineModule(NFIPluginManager *p);

    virtual ~NFCCoroutineModule();

    virtual int OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage) override;

    virtual bool Awake() override;

    void UpdateUser();

    /*
     * 停服之前，做一些操作，满足停服条件
     * */
    virtual bool OnStopServer() override;

    virtual bool Shut() override;

    virtual bool Finalize() override;

    virtual bool Execute() override;

    /// @brief 启动该协程任务, 执行Run方法
    /// @param is_immediately 是否立即执行
    /// @return 返回协程ID
    virtual int64_t Start(NFCoroutineTask *pTask, bool is_immediately = true) override;

    virtual int DeleteTask(NFCoroutineTask *pTask) override;

    virtual int AddTask(NFCoroutineTask *pTask) override;

    /// @brief 返回当前协程数量
    /// @return 当前的协程数量
    virtual int Size() const override;

    /// @brief 获取当前正在运行的协程任务
    /// @return 正在运行的协程任务对象的指针
    /// @note 此函数必须在协程中调用
    virtual NFCoroutineTask *CurrentTask() const override;

    /// @brief 获取当前正在运行的协程ID
    /// @reurn 正在运行的协程ID
    /// @note 此函数必须在协程中调用
    virtual int64_t CurrentTaskId() const override;

    /**
     * @brief 当前是否在携程中
     * @return
     */
    virtual bool IsInCoroutine() const override;

    /// @brief 挂起当前协程
    /// @param timeout_ms 超时时间，单位为毫秒，默认-1，<=0时表示不进行超时处理
    /// @return 处理结果，@see CoroutineErrorCode
    /// @note 此函数必须在协程中调用
    virtual int32_t Yield(int32_t timeout_ms = -1) override;

    /// @brief 激活指定ID的协程
    /// @param id 协程ID
    /// @param result resume时可传递结果，默认为0
    /// @return 处理结果，@see CoroutineErrorCode
    virtual int32_t Resume(int64_t id, int32_t result = 0) override;

    /// @brief 返回指定id协程的状态
    /// @param id 协程ID
    /// @return 协程状态
    virtual int Status(int64_t id) override;

    /// @brief 获取协程
    /// @param 协程ID
    /// @return 返回
    virtual google::protobuf::Message *GetUserData(int64_t id) override;
    virtual int SetUserData(google::protobuf::Message *pUserData)  override;

    /**
     * @brief 添加玩家的协程ID
     * @param id
     * @return
     */
    virtual int AddUserCo(uint64_t userId) override;

    /**
     * @brief 减少玩家的协程ID
     * @param id
     * @return
     */
    virtual int DelUserCo(uint64_t userId) override;

    /**
     * @brief 玩家是否还有携程在运行
     * @param userId
     * @return
     */
    virtual bool IsExistUserCo(uint64_t userId) override;

    /**
     * @brief 协程是否存在，是否已经死亡
     * @return
     */
    virtual bool IsDead(int64_t id) override;

    /**
     * @brief 是否正在运行
     * @return
     */
    virtual bool IsRunning(int64_t id) override;

    /**
     * @brief 是否协程正在挂起
     * @return
     */
    virtual bool IsYielding(int64_t id) override;

    /// @brief 模版方法, 新建一个协程任务
    /// @note 使用此种方法生成的task对象指针会在协程结束后自动delete掉
    template<typename TASK>
    TASK *NewTask() {
        if (CurrentTaskId() != -1) {
            return NULL;
        }
        TASK *task = new TASK(m_pObjPluginManager);
        if (AddTask(task)) {
            delete task;
            task = NULL;
        }
        return task;
    }

    virtual int64_t MakeCoroutine(const std::function<void()> &func, bool is_immediately = true) override;
private:
    NFCoroutineSchedule *m_pCorSched;
    std::unordered_map<uint64_t, std::unordered_set<int64_t>> m_userCoIdMap;
};