// -------------------------------------------------------------------------
//    @FileName         :    NFIPluginManager.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFIPluginManager
//
// -------------------------------------------------------------------------

#ifndef NFI_PLUGIN_MANAGER_H
#define NFI_PLUGIN_MANAGER_H

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFSystemInfo.h"
#include <functional>
#include <assert.h>
#include <list>

#define ALL_SERVER ("AllServer")

class NFIModule;
class NFIPlugin;
class NFIPluginManager;

typedef std::function<NFIModule*(NFIPluginManager* pMan)> CREATE_ALONE_MODULE;

typedef std::function<NFIPlugin*(NFIPluginManager* pMan)> CREATE_PLUGIN_FUNCTION;

#define FIND_MODULE(classBaseName, className)  \
    assert((TIsDerived<classBaseName, NFIModule>::Result));

template <typename DerivedType, typename BaseType>
class TIsDerived
{
public:
	static int AnyFunction(BaseType* base)
	{
		return 1;
	}

	static char AnyFunction(void* t2)
	{
		return 0;
	}

	enum
	{
		Result = (sizeof(int) == sizeof(AnyFunction((DerivedType*)NULL))),
	};
};

class NFIPluginManager
{
public:
    static NFIPluginManager* GetSingletonPtr();

    static NFIPluginManager* Instance()
    {
        return GetSingletonPtr();
    }

    static void ReleaseInstance()
    {
        if (m_pInstance)
        {
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }

private:
    static NFIPluginManager* m_pInstance;
public:
	NFIPluginManager()
	{
#if defined( _MSC_VER ) && _MSC_VER < 1200
        int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
		m_pInstance = (T*)((int)this + offset);
#else
        m_pInstance = static_cast<NFIPluginManager*>(this);
#endif
	}

	virtual ~NFIPluginManager()
	{
	}

    virtual bool AfterLoadAllPlugin()
    {
        return true;
    }

	virtual bool Awake()
	{
		return true;
	}

	virtual bool Init()
	{
		return true;
	}

	virtual bool CheckConfig()
	{
		return true;
	}

	virtual bool ReadyExecute()
	{
		return true;
	}

	virtual bool Execute()
	{
		return true;
	}

	virtual bool BeforeShut()
	{
		return true;
	}

	virtual bool Shut()
	{
		return true;
	}

	virtual bool Finalize()
	{
		return true;
	}

	virtual bool OnReloadPlugin()
	{
		return true;
	}

	virtual bool InitShmObject()
	{
		return true;
	}

	template <typename T>
	T* FindModule()
	{
		NFIModule* pLogicModule = FindModule(typeid(T).name());
		if (pLogicModule)
		{
			if (!TIsDerived<T, NFIModule>::Result)
			{
				return nullptr;
			}
			//TODO OSX上dynamic_cast返回了NULL
#if NF_PLATFORM == NF_PLATFORM_APPLE
			T* pT = (T*)pLogicModule;
#else
			T* pT = dynamic_cast<T*>(pLogicModule);
#endif
			return pT;
		}
		return nullptr;
	}

	virtual bool Begin() = 0;

	virtual bool End() = 0;

	virtual void RegisteredStaticPlugin(const std::string& strPluginName, const CREATE_PLUGIN_FUNCTION& createFunc) = 0;

	virtual void Registered(NFIPlugin* plugin) = 0;

	virtual void UnRegistered(NFIPlugin* plugin) = 0;

	virtual NFIPlugin* FindPlugin(const std::string& strPluginName) = 0;

	virtual void AddModule(const std::string& strModuleName, NFIModule* pModule) = 0;

	virtual void RemoveModule(const std::string& strModuleName) = 0;

	virtual NFIModule* FindModule(const std::string& strModuleName) = 0;

	virtual bool LoadAllPlugin() = 0;

	virtual bool LoadPluginLibrary(const std::string& strPluginDLLName) = 0;

	virtual bool UnLoadPluginLibrary(const std::string& strPluginDLLName) = 0;

	virtual bool DynamicLoadPluginLibrary(const std::string& strPluginDLLName) = 0;

	virtual const std::string& GetFullPath() const = 0;

	virtual void SetFullPath(const std::string& strAppName) = 0;

	virtual int GetAppID() const = 0;

	virtual void SetAppID(const int nAppID) = 0;

	virtual const std::string& GetConfigPath() const = 0;
	virtual void SetConfigPath(const std::string& strPath) = 0;

	virtual const std::string& GetPluginPath() const = 0;
	virtual void SetPluginPath(const std::string& strPath) = 0;

	virtual const std::string& GetAppName() const = 0;
	virtual void SetAppName(const std::string& strAppName) = 0;

    virtual const std::string& GetStrParam() const = 0;
	virtual void SetStrParam(const std::string& strAppName) = 0;

	virtual const std::string& GetLogPath() const = 0;
	virtual void SetLogPath(const std::string& strName) = 0;

	virtual bool IsLoadAllServer() const = 0;

    virtual void SetLoadAllServer(bool b) = 0;

	virtual void SetLuaScriptPath(const std::string& luaScriptPath) = 0;

	virtual const std::string& GetLuaScriptPath() const = 0;

	virtual uint64_t GetInitTime() const = 0;

	virtual uint64_t GetNowTime() const = 0;

	virtual bool IsDaemon() const = 0;
	virtual void SetDaemon() = 0;

	virtual void SetOpenProfiler(bool b) = 0;
	virtual bool IsOpenProfiler() = 0;

	virtual void BeginProfiler(const std::string& luaFunc) = 0;
	//return BeginProfiler - EndProfiler 本次的时间差，单位微妙
	virtual uint64_t EndProfiler() = 0;

	//通过console控制服务器
	virtual bool GetExitApp() const = 0;
	virtual void SetExitApp(bool exitApp) = 0;
	virtual bool GetReloadApp() const = 0;
	virtual void SetReloadApp(bool exitApp) = 0;
	virtual bool GetChangeProfileApp() const = 0;
	virtual void SetChangeProfileApp(bool exitApp) = 0;
	virtual bool GetKillPreApp() const = 0;
	virtual void SetKillPreApp(bool exitApp) = 0;
	virtual bool GetShutDownApp() const  = 0;
	virtual void SetShutDownApp(bool exitApp) = 0;
    virtual int ShutDownApp() = 0;
	virtual bool IsInitShm() const = 0;
	virtual void SetInitShm() = 0;
	virtual void SetBusName(const std::string& busName) = 0;
	virtual const std::string& GetBusName() const = 0;

    virtual void SetPidFileName() = 0;
    virtual const std::string& GetPidFileName() = 0;
#if NF_PLATFORM == NF_PLATFORM_LINUX
    virtual int  TimedWait(pid_t pid, int sec) = 0;
    virtual int  CheckPidFile() = 0;
    virtual int  CreatePidFile() = 0;
    virtual int  KillPreApp() = 0;
    virtual void KillApp()  = 0;
    virtual void ReloadApp() = 0;
    virtual void QuitApp() = 0;
#endif
    virtual uint32_t GetFrame() const = 0;
    virtual uint32_t GetFrameTime() const = 0;
    virtual uint32_t GetCurFrameCount() const = 0;
    virtual bool IsFixedFrame() const = 0;
    virtual void SetFixedFrame(bool frame) = 0;
    virtual uint32_t GetIdleSleepUs() const = 0;
    virtual void SetIdelSleepUs(uint32_t time) = 0;

	virtual bool IsInited() const = 0;

	virtual void SetIsInited(bool b) = 0;

	virtual int RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT) = 0;

	virtual int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT) = 0;

    virtual int SendDumpInfo(const std::string& dmpInfo) = 0;

    virtual std::list<NFIPlugin*> GetListPlugin() = 0;

    virtual std::string GetMachineAddrMD5() = 0;
};

#endif

