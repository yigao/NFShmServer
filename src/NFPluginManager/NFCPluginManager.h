// -------------------------------------------------------------------------
//    @FileName         :    NFCPluginManager.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFCPluginManager
//
// -------------------------------------------------------------------------

#ifndef NFC_PLUGIN_MANAGER_H
#define NFC_PLUGIN_MANAGER_H

#include <map>
#include <string>
#include <ctime>
#include <list>
#include <atomic>
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFCDynLib.h"
#include "NFComm/NFPluginModule/NFSystemInfo.h"
#include "NFComm/NFPluginModule/NFProfiler.h"
#include "NFCAppInited.h"

/*
	系统的Module，分为加载DLL创建的唯一Module，和自己独立创建出来的Module，
	DLL创建的唯一Module，统一由系统负责处理，
	创建出来的单独Module,
	它们的Awake,Init,AfterInit由创建者负责，
	其余ReadExecute，Execute。。。,以及资源的释放由系统负责
*/

class NFCPluginManager
        : public NFIPluginManager
{
public:
    NFCPluginManager();

    virtual ~NFCPluginManager();

    virtual bool Begin() override;

    virtual bool End() override;

    virtual bool AfterLoadAllPlugin() override;

    virtual bool AfterInitShmMem() override;

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool CheckConfig() override;

    virtual bool ReadyExecute() override;

    virtual bool Execute() override;

    virtual bool BeforeShut() override;

    virtual bool Shut() override;

    virtual bool Finalize() override;

    virtual bool OnReloadConfig() override;

    virtual bool AfterOnReloadConfig() override;

    /**
    * @brief 服务器连接完成后
    * @return
    */
    virtual bool AfterAllConnectFinish() override;

    /**
     * @brief 加载完服务器数据，包过excel, 以及从数据拉取的数据
     * @return
     */
    virtual bool AfterAllDescStoreLoaded() override;

    /**
     * @brief 从db加载全局数据, 这个加载一定在完成连接后，有可能依赖descstore数据，也可能不依赖
     * @return
     */
    virtual bool AfterObjFromDBLoaded() override;

    /**
     * @brief 完成服务器之间的注册
     * @return
     */
    virtual bool AfterServerRegisterFinish() override;

    /**
     * @brief  服务器完成初始化之后
     * @return
     */
    virtual bool AfterAppInitFinish() override;
    //////////////////////////////////////////////////////////////////////////

    virtual void
    RegisteredStaticPlugin(const std::string &strPluginName, const CREATE_PLUGIN_FUNCTION &createFunc) override;

    virtual void Registered(NFIPlugin *pPlugin) override;

    virtual void UnRegistered(NFIPlugin *pPlugin) override;

    //////////////////////////////////////////////////////////////////////////

    virtual NFIPlugin *FindPlugin(const std::string &strPluginName) override;

    virtual int AddModule(const std::string &strModuleName, NFIModule *pModule) override;

    virtual void RemoveModule(const std::string &strModuleName) override;

    virtual NFIModule *FindModule(const std::string &strModuleName) override;

    virtual bool LoadAllPlugin() override;

    virtual bool LoadPluginLibrary(const std::string &strPluginDLLName) override;

    virtual bool UnLoadPluginLibrary(const std::string &strPluginDLLName) override;

    virtual bool DynamicLoadPluginLibrary(const std::string &strPluginDLLName) override;

    virtual int GetAppID() const override;

    virtual void SetAppID(const int nAppID) override;

    virtual int GetWorldID() const override;

    virtual int GetZoneID() const override;

    virtual const std::string &GetConfigPath() const override;

    virtual void SetConfigPath(const std::string &strPath) override;

    virtual const std::string &GetPluginPath() const override;

    virtual void SetPluginPath(const std::string &strPath) override;

    virtual const std::string &GetFullPath() const override;

    virtual void SetFullPath(const std::string &strAppName) override;

    virtual const std::string &GetStrParam() const override;

    virtual void SetStrParam(const std::string &strAppName) override;

    virtual const std::string &GetAppName() const override;

    virtual void SetAppName(const std::string &strAppName) override;

    virtual const std::string &GetLogPath() const override;

    virtual void SetLogPath(const std::string &strName) override;

    virtual void SetLuaScriptPath(const std::string &luaScriptPath) override;

    virtual const std::string &GetLuaScriptPath() const override;

    virtual void SetBusName(const std::string &busName) override;

    virtual const std::string &GetBusName() const override;

    virtual bool IsLoadAllServer() const override;

    virtual void SetLoadAllServer(bool b) override;

    virtual uint32_t GetFrame() const override;

    virtual uint32_t GetFrameTime() const override;

    virtual bool IsFixedFrame() const override;

    virtual void SetFixedFrame(bool frame) override;

    virtual uint32_t GetIdleSleepUs() const override;

    virtual void SetIdelSleepUs(uint32_t time) override;

    virtual uint64_t GetInitTime() const override;

    virtual uint64_t GetNowTime() const override;

    virtual bool IsDaemon() const override;

    virtual void SetDaemon() override;

    virtual bool IsInitShm() const override;

    virtual void SetInitShm() override;

    virtual void SetPidFileName() override;

    virtual const std::string &GetPidFileName() override;

#if NF_PLATFORM == NF_PLATFORM_LINUX

    virtual int TimedWait(pid_t pid, int sec) override;

    virtual int CheckPidFile() override;

    virtual int CreatePidFile() override;

    virtual int KillPreApp() override;

    virtual void StopApp() override;

    virtual void ReloadApp() override;

    virtual void QuitApp() override;

#endif

    virtual void SetOpenProfiler(bool b) override;

    virtual bool IsOpenProfiler() override;

    virtual uint32_t GetCurFrameCount() const override;

    virtual bool IsInited() const override;

    virtual bool IsInited(NF_SERVER_TYPES eServerType) const override;

    virtual void SetIsInited(bool b) override;

    virtual int RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string &desc,
                                uint32_t taskGroup = APP_INIT_TASK_GROUP_SERVER_CONNECT) override;

    virtual int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType,
                              uint32_t taskGroup = APP_INIT_TASK_GROUP_SERVER_CONNECT) override;

    virtual bool IsFinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const override;

    virtual bool IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const override;

    virtual bool IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup, uint32_t taskType) const override;

    virtual int SendDumpInfo(const std::string &dmpInfo) override;

    virtual std::list<NFIPlugin *> GetListPlugin() override;

    virtual std::string GetMachineAddrMD5() override;

    template<typename T>
    T *FindModule()
    {
        return ((NFIPluginManager *) this)->FindModule<T>();
    }

protected:

    bool LoadStaticPlugin(const std::string &strPluginDLLName);

    bool UnLoadStaticPlugin(const std::string &strPluginDLLName);

    bool LoadPluginConfig();

    bool RegisterStaticPlugin();

    bool LoadKernelPlugin();

    virtual void BeginProfiler(const std::string &luaFunc) override;

    virtual uint64_t EndProfiler() override;//return this time cost time(us) 微妙
    virtual void ClearProfiler();

    virtual void PrintProfiler();

    int GetMachineAddr(const std::string &str);

private:
    const uint32_t m_nFrame = 30; //服务器帧率，一秒30帧
    const uint32_t m_nFrameTime = 1000 / m_nFrame; //一帧多少时间
    uint32_t m_nCurFrameCount = 0;
    bool m_bFixedFrame;
    uint32_t m_idleSleepUs;
private:
    int m_nAppID;
    uint64_t m_nInitTime;    //服务器开始时间，ms
    uint64_t m_nNowTime;        //服务器帧时间，ms
    std::string m_mStrBusName;
    std::string m_strConfigPath;
    std::string m_strPluginPath;
    std::string m_strAppName;
    std::string m_strLogPath;
    std::string m_strLuaScriptPath;
    std::string m_strFullPath;
    std::string m_strExeName;
    std::string m_strPidFileName;
    std::string m_strParam;
    std::string m_iMachineAddrMD5;

    typedef std::unordered_map<std::string, NFCDynLib *> PluginLibMap;
    typedef std::vector<std::string> PluginNameVec;
    typedef std::unordered_map<std::string, NFIPlugin *> PluginInstanceMap;
    typedef std::list<NFIPlugin *> PluginInstanceList;
    typedef std::unordered_map<std::string, NFIModule *> ModuleInstanceMap;
    typedef std::unordered_map<std::string, CREATE_PLUGIN_FUNCTION> PluginFuncMap; //静态加载Plugin, 先注册创建函数

    typedef void (*DLL_START_PLUGIN_FUNC)(NFIPluginManager *pm);

    typedef void (*DLL_STOP_PLUGIN_FUNC)(NFIPluginManager *pm);

    PluginLibMap m_nPluginLibMap;
    PluginNameVec m_nPluginNameVec;
    PluginInstanceMap m_nPluginInstanceMap;
    PluginInstanceList m_nPluginInstanceList;
    ModuleInstanceMap m_nModuleInstanceMap;
    PluginFuncMap m_nPluginFuncMap; ////静态加载Plugin, 先注册创建和销毁函数

    NFProfiler m_profilerMgr;
public:
    /*
     * stop server，停服，意味着需要保存该保存的数据，共享内存可能后面会被清理，服务器会走正常的停服流程
     * */
    virtual bool IsServerStopping() const override { return m_bServerStopping; }

    /*
     * stop server，停服，意味着需要保存该保存的数据，共享内存可能后面会被清理，服务器会走正常的停服流程
     * */
    virtual void SetServerStopping(bool exitApp) override { m_bServerStopping = exitApp; }

    /*
     * 停服之前，检查服务器是否满足停服条件
     * */
    virtual bool CheckStopServer() override;

    /*
     * 停服之前，做一些操作，满足停服条件
     * */
    virtual bool OnStopServer() override;

    /*
     * stop server，停服，意味着需要保存该保存的数据，共享内存可能后面会被清理，服务器会走正常的停服流程
     * */
    virtual bool StopServer() override;

    /*
     * 停服之前保存需要的数据
     * */
    virtual bool SaveDB() override;

    /*
     * reload server 重新加载服务器的配置数据
     * */
    virtual bool IsReloadServer() const override { return m_bReloadServer; }

    /*
     * reload server 重新加载服务器的配置数据
     * */
    virtual void SetReloadServer(bool exitApp) override { m_bReloadServer = exitApp; }

    virtual bool GetChangeProfileApp() const override { return m_bChangeProfileApp; }

    virtual void SetChangeProfileApp(bool exitApp) override { m_bChangeProfileApp = exitApp; }

    virtual bool GetKillPreApp() const override { return m_isKillPreApp; }

    virtual void SetKillPreApp(bool exitApp) override { m_isKillPreApp = exitApp; }

    /*
     * 热更退出app, 用于服务器需要热更app代码的情况，这时候会杀掉正在运行的的的app,重启新的服务器app
     * */
    virtual bool IsHotfixServer() const override { return m_bHotfixServer; }

    /*
     * 热更退出app, 用于服务器需要热更app代码的情况，这时候会杀掉正在运行的的的app,重启新的服务器app
     * */
    virtual void SetHotfixServer(bool exitApp) override { m_bHotfixServer= exitApp; }

    /*
     * 热更退出app, 用于服务器需要热更app代码的情况，这时候会杀掉正在运行的的的app,重启新的服务器app
     * */
    virtual bool HotfixServer() override;

private:
    //通过console控制服务器变量
    std::atomic_bool m_bServerStopping{};
    //通过console控制服务器变量重新加载配置
    std::atomic_bool m_bReloadServer{};
    //通过console控制服务器变量计算服务器效率
    std::atomic_bool m_bChangeProfileApp{};
    //通过console控制服务器, 直接关闭服务器，不做处理
    std::atomic_bool m_bHotfixServer{};
    //是否初始化共享内存
    bool m_bInitShm;
    bool m_isKillPreApp;    //是否杀掉上一个应用程序，
    bool m_isDaemon;

    bool m_isAllServer;
    //程序初始化流程
    bool m_isInited;
    NFCAppInited m_appInited;
};

#endif

