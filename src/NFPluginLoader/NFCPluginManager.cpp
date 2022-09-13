// -------------------------------------------------------------------------
//    @FileName         :    NFCPluginManager.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCPluginManager
//
// -------------------------------------------------------------------------

#include "NFCPluginManager.h"
#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFProfiler.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFPrintfLogo.h"
#include "NFComm/NFCore/NFServerTime.h"
#include "NFComm/NFPluginModule/NFIConsoleModule.h"
#include "NFComm/NFPluginModule/NFEventMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFCore/NFMD5.h"
#include "hwinfo/hw_info.h"

#include <csignal>
#include <utility>
#include <thread>
#include <chrono>

#if NF_PLATFORM == NF_PLATFORM_WIN
#pragma comment( lib, "ws2_32.lib" )
#endif

#include "sigar/sigar.h"

#ifdef __cplusplus
extern "C"
{
#endif
int sigar_net_address_to_string(sigar_t *sigar,
                                sigar_net_address_t *address,
                                char *addr_str);
#ifdef __cplusplus
}
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN
#elif NF_PLATFORM == NF_PLATFORM_LINUX
#include "NFComm/NFPluginModule/NFCheck.h"
#endif

NFIPluginManager* NFIPluginManager::m_pInstance = nullptr;

NFIPluginManager* NFIPluginManager::GetSingletonPtr()
{
    if (nullptr == m_pInstance)
    {
		m_pInstance = new NFCPluginManager();
    }

    return m_pInstance;
}

NFCPluginManager::NFCPluginManager() : NFIPluginManager()
{
	m_nCurFrameCount = 0;
	m_nAppID = 0;

	m_strConfigPath = "../../Config";
	m_strPluginPath = "../../Plugin";
	m_strLogPath = "logs";

	m_nInitTime = NFTime::Now().UnixMSec();
	m_nNowTime = m_nInitTime;
	m_isDaemon = false;
	m_bInitShm = false;
	m_isKillPreApp = false;
	m_bReloadApp = false;
	m_bExitApp = false;
	m_bChangeProfileApp = false;
	m_bShutDownApp = false;
    m_bFixedFrame = true;

	m_isInited = false;

    m_isAllServer = false;

    m_idleSleepUs = 1000;

	g_GetGlobalServerTime()->Init(m_nFrame);

	NFRandomSeed();
	SetOpenProfiler(false);
}

NFCPluginManager::~NFCPluginManager()
{
}

bool NFCPluginManager::IsDaemon() const
{
	return m_isDaemon;
}

void NFCPluginManager::SetDaemon()
{
	m_isDaemon = true;
}

bool NFCPluginManager::IsInitShm() const
{
	return m_bInitShm;
}

void NFCPluginManager::SetInitShm()
{
	m_bInitShm = true;
}

bool NFCPluginManager::IsLoadAllServer() const
{
	return m_isAllServer;
}

void NFCPluginManager::SetLoadAllServer(bool b)
{
    m_isAllServer = b;
}

bool NFCPluginManager::AfterLoadAllPlugin()
{
    //调用所有module的Awake函数
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterLoadAllPlugin();
    }

    return true;
}

bool NFCPluginManager::Awake()
{
	//调用所有module的Awake函数
	for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
	{
		(*iter)->Awake();
	}

	return true;
}

bool NFCPluginManager::LoadAllPlugin()
{
#ifndef NF_DYNAMIC_PLUGIN
	RegisterStaticPlugin(); //注册静态引擎
	LoadKernelPlugin(); //NFKernelPlugin比较特殊，提前加载
	//打印LOG
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{}", PrintfLogo());

	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader Awake................");

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:NFKernelPlugin");
	//加载引擎配置plugin.xml, 创建引擎，生成module
	LoadPluginConfig();
	for (PluginNameVec::iterator it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		LoadStaticPlugin(*it);
	}
#else
	LoadKernelPlugin(); //NFKernelPlugin比较特殊，提前加载


	//打印LOG
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{}", PrintfLogo());

	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader Awake................");
	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:NFKernelPlugin");
	//加载引擎配置plugin.xml, 创建引擎，生成module
	LoadPluginConfig();
	for (PluginNameVec::iterator it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		LoadPluginLibrary(*it);
		NFIPlugin* pPlugin = FindPlugin(*it);
		if (pPlugin->IsDynamicLoad())
		{
			((NFIPluginManager*)this)->FindModule<NFIConsoleModule>()->AddDynamicPluginFile(*it);
		}
	}

#endif
	return true;
}

bool NFCPluginManager::Begin()
{
	LoadAllPlugin();
    AfterLoadAllPlugin();
	Awake();
	Init();
	CheckConfig();
	ReadyExecute();
	return true;
}

bool NFCPluginManager::End()
{
	NFCPluginManager::GetSingletonPtr()->BeforeShut();
	NFCPluginManager::GetSingletonPtr()->Shut();
	NFCPluginManager::GetSingletonPtr()->Finalize();

	NFCPluginManager::GetSingletonPtr()->ReleaseInstance();
	return true;
}

inline bool NFCPluginManager::Init()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader Init................");
	for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
	{
		(*iter)->Init();
	}

	return true;
}

bool NFCPluginManager::LoadPluginConfig()
{
	NFPluginConfig* pConfig = NFConfigMgr::Instance()->GetPluginConfig(m_strAppName);
	if (pConfig == nullptr)
	{
		NF_ASSERT_MSG(0, "There are no plugin:" + m_strAppName);
		return false;
	}

	for (size_t i = 0; i < pConfig->mVecPlugins.size(); i++)
	{
		std::string strPluginName = pConfig->mVecPlugins[i];
		m_nPluginNameVec.push_back(strPluginName);
	}

	return true;
}

void NFCPluginManager::RegisteredStaticPlugin(const std::string& strPluginName, const CREATE_PLUGIN_FUNCTION& createFunc)
{
	m_nPluginFuncMap.emplace(strPluginName, createFunc);
}

void NFCPluginManager::Registered(NFIPlugin* plugin)
{
	if (plugin == nullptr) return;

	//动态加载的情况下，直接使用FindPlugin(plugin->GetPluginName()) 将导致崩溃， 这到底是为啥呢
	std::string strPluginName = plugin->GetPluginName();
	if (!FindPlugin(strPluginName))
	{
		m_nPluginInstanceMap.insert(PluginInstanceMap::value_type(strPluginName, plugin));
		m_nPluginInstanceList.push_back(plugin);
		plugin->Install();
	}
	else
	{
		assert(0);
	}
}

void NFCPluginManager::UnRegistered(NFIPlugin* plugin)
{
	if (plugin == nullptr)
	{
		std::cerr << "UnRegistered, plugin == nullptr" << std::endl;
		return;
	}

	//动态加载的情况下，直接使用mPluginInstanceMap.find(plugin->GetPluginName()) 将导致崩溃， 这到底是为啥呢
	std::string strPluginName = plugin->GetPluginName();
	PluginInstanceMap::iterator it = m_nPluginInstanceMap.find(strPluginName);
	if (it != m_nPluginInstanceMap.end())
	{
		if (it->second == nullptr)
		{
			m_nPluginInstanceMap.erase(it);
			return;
		}

		for (auto listIt = m_nPluginInstanceList.begin(); listIt != m_nPluginInstanceList.end(); listIt++)
		{
			if (it->second == *listIt)
			{
				m_nPluginInstanceList.erase(listIt);
				break;
			}
		}

		it->second->Uninstall();
		NF_SAFE_DELETE(it->second);
		it->second = nullptr;
		m_nPluginInstanceMap.erase(it);
	}
}

NFIPlugin* NFCPluginManager::FindPlugin(const std::string& strPluginName)
{
	PluginInstanceMap::iterator it = m_nPluginInstanceMap.find(strPluginName);
	if (it != m_nPluginInstanceMap.end())
	{
		return it->second;
	}

	return nullptr;
}

bool NFCPluginManager::Execute()
{
	bool bRet = true;
	m_nNowTime = NFTime::Now().UnixMSec();
	uint64_t startTime = NFTime::Tick();
	uint64_t endTime = 0;
	m_nCurFrameCount++;

	g_GetGlobalServerTime()->Update(startTime);   //

	BeginProfiler("MainLoop");
	
	for (auto it = m_nPluginInstanceMap.begin(); it != m_nPluginInstanceMap.end(); ++it)
	{
		BeginProfiler(it->first + "--Loop");
		bool tembRet = it->second->Execute();
		bRet = bRet && tembRet;
		uint64_t useTime = EndProfiler();
		if (useTime >= 30000) //>= 10毫秒
		{
			if (!IsLoadAllServer())
			{
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} {} use time:{} ms", NFCommon::tostr(std::this_thread::get_id()), it->first + "--Loop", useTime / 1000);
			}
		}
	}

	EndProfiler();

	//采用固定帧率
	endTime = NFTime::Tick();
	uint32_t cost = static_cast<uint32_t>(endTime > startTime ? (endTime - startTime) : 0);
	if (m_bFixedFrame)
    {
        uint32_t sleepTime = m_nFrameTime > cost ? (m_nFrameTime - cost) : 0;
        if (sleepTime > 0)
        {
            NFSLEEP(sleepTime*1000);
        }
        else
        {
            if (cost >= 40 && cost <= 200)
            {
                if (!IsLoadAllServer())
                {
                    NFLogWarning(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} frame timeout:{}", NFCommon::tostr(std::this_thread::get_id()), cost);

                }
            }
            else if (cost > 200)
            {
                if (!IsLoadAllServer())
                {
                    NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} frame timeout:{}, something wrong", NFCommon::tostr(std::this_thread::get_id()), cost);
                    //PrintProfiler();
                }
            }
            else
            {
                NFSLEEP(1000);
            }
        }
    }
    else
    {
        if (cost >= 40 && cost <= 200)
        {
            if (!IsLoadAllServer())
            {
                NFLogWarning(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} frame timeout:{}", NFCommon::tostr(std::this_thread::get_id()), cost);
            }
        }
        else if (cost > 200)
        {
            if (!IsLoadAllServer())
            {
                NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} frame timeout:{}, something wrong", NFCommon::tostr(std::this_thread::get_id()), cost);
                //PrintProfiler();
            }
        }
        else
        {
            if (IsLoadAllServer())
            {
                NFSLEEP(1000);
            }
            else
            {
                NFSLEEP(m_idleSleepUs);
            }
        }
    }

	if (m_nCurFrameCount % 1000 == 0)
	{
		PrintProfiler();
	}

	return bRet;
}

inline int NFCPluginManager::GetAppID() const
{
	return m_nAppID;
}

void NFCPluginManager::SetAppID(const int nAppID)
{
	m_nAppID = nAppID;
}

const std::string& NFCPluginManager::GetConfigPath() const
{
	return m_strConfigPath;
}

void NFCPluginManager::SetConfigPath(const std::string& strPath)
{
	if (strPath.empty()) return;

	m_strConfigPath = strPath;
}

const std::string& NFCPluginManager::GetPluginPath() const
{
	return m_strPluginPath;
}

void NFCPluginManager::SetPluginPath(const std::string& strPath)
{
	if (strPath.empty()) return;

	m_strPluginPath = strPath;
}

void NFCPluginManager::SetLuaScriptPath(const std::string& luaScriptPath)
{
	if (luaScriptPath.empty()) return;
	m_strLuaScriptPath = luaScriptPath;
}

const std::string& NFCPluginManager::GetLuaScriptPath() const
{
	return m_strLuaScriptPath;
}

void NFCPluginManager::SetBusName(const std::string& busName)
{
	m_mStrBusName = busName;
}

const std::string& NFCPluginManager::GetBusName() const
{
	return m_mStrBusName;
}

const std::string& NFCPluginManager::GetAppName() const
{
	return m_strAppName;
}

const std::string& NFCPluginManager::GetStrParam() const
{
    return m_strParam;
}

void NFCPluginManager::SetStrParam(const std::string& strAppName)
{
    m_strParam = strAppName;
}


const std::string& NFCPluginManager::GetFullPath() const
{
	return m_strFullPath;
}

void NFCPluginManager::SetFullPath(const std::string& str)
{
	m_strFullPath = str;
	m_strExeName = NFFileUtility::GetFileName(str);
}

void NFCPluginManager::SetAppName(const std::string& strAppName)
{
	if (!m_strAppName.empty())
	{
		return;
	}

	m_strAppName = strAppName;
}

const std::string& NFCPluginManager::GetLogPath() const
{
	return m_strLogPath;
}

void NFCPluginManager::SetLogPath(const std::string& strName)
{
	if (strName.empty()) return;
	m_strLogPath = strName;
}

void NFCPluginManager::AddModule(const std::string& strModuleName, NFIModule* pModule)
{
	m_nModuleInstanceMap.insert(ModuleInstanceMap::value_type(strModuleName, pModule));
}

void NFCPluginManager::RemoveModule(const std::string& strModuleName)
{
	ModuleInstanceMap::iterator it = m_nModuleInstanceMap.find(strModuleName);
	if (it != m_nModuleInstanceMap.end())
	{
		m_nModuleInstanceMap.erase(it);
	}
}

NFIModule* NFCPluginManager::FindModule(const std::string& strModuleName)
{
	std::string strSubModuleName = strModuleName;

#if NF_PLATFORM == NF_PLATFORM_WIN
	std::size_t position = strSubModuleName.find(' ');
	if (string::npos != position)
	{
		strSubModuleName = strSubModuleName.substr(position + 1, strSubModuleName.length());
	}
#else
	for (int i = 0; i < (int)strSubModuleName.length(); i++)
	{
		std::string s = strSubModuleName.substr(0, i + 1);
		int n = atof(s.c_str());
		if ((int)strSubModuleName.length() == i + 1 + n)
		{
			strSubModuleName = strSubModuleName.substr(i + 1, strSubModuleName.length());
			break;
		}
	}
#endif

	ModuleInstanceMap::iterator it = m_nModuleInstanceMap.find(strSubModuleName);
	if (it != m_nModuleInstanceMap.end())
	{
		return it->second;
	}

	return nullptr;
}

bool NFCPluginManager::CheckConfig()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader CheckConfig................");
	
	for (PluginInstanceMap::iterator itCheckInstance = m_nPluginInstanceMap.begin(); itCheckInstance != m_nPluginInstanceMap.end(); ++itCheckInstance)
	{
		itCheckInstance->second->CheckConfig();
	}
	return true;
}

bool NFCPluginManager::ReadyExecute()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader ReadyExecute................");

	if (!m_bFixedFrame) {
	    m_profilerMgr.SetOpenProfiler(false);
    }
	
	for (PluginInstanceMap::iterator itCheckInstance = m_nPluginInstanceMap.begin(); itCheckInstance != m_nPluginInstanceMap.end(); ++itCheckInstance)
	{
		itCheckInstance->second->ReadyExecute();
	}

    bool bExitApp = false;
	while (!IsInited() && !bExitApp)
	{
        m_appInited.Execute();

		if (m_appInited.IsInitTasked())
		{
			SetIsInited(true);
			NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Task, App Inited Success..............");

			proto_ff::NFEventNoneData event;
			NFEventMgr::Instance()->FireExecute(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, 0, proto_ff::NF_EVENT_SERVER_TYPE, event);
			break;
		}

        if (bExitApp) //-V547
        {
            break;
        }

        Execute();

        if (GetShutDownApp())
        {
            ShutDownApp();
            NFSLEEP(1000);
            exit(0);
        }

        bExitApp = GetExitApp();
	}

	return true;
}

bool NFCPluginManager::BeforeShut()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader BeforeShut................");
	
	for (PluginInstanceMap::iterator itBeforeInstance = m_nPluginInstanceMap.begin(); itBeforeInstance != m_nPluginInstanceMap.end(); ++itBeforeInstance)
	{
		itBeforeInstance->second->BeforeShut();
	}

	return true;
}

bool NFCPluginManager::Shut()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader Shut................");
	
	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
		itInstance->second->Shut();
	}

	return true;
}

bool NFCPluginManager::OnReloadPlugin()
{
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPluginLoader OnReloadPlugin................");

	/*
	加载服务器配置
	*/
	((NFIPluginManager*)this)->FindModule<NFIConfigModule>()->LoadConfig();

	//first kernel plugin
	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
		if (itInstance->first == "NFKernelPlugin")
		{
			itInstance->second->OnReloadPlugin();
			break;
		}
	}

	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
		if (itInstance->first != "NFKernelPlugin")
		{
			itInstance->second->OnReloadPlugin();
		}
	}

	return true;
}

bool NFCPluginManager::InitShmObject()
{
//	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPluginLoader InitShmObjectRegister................");
//
//	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
//	{
//		itInstance->second->InitShmObjectRegister();
//	}
//
//	/*
//		分配共享内存
//	*/
//	NFShmMgr::Instance()->AllocShm();
//
//	/*
//		初始化共享内存里的对象
//	*/
//	NFShmMgr::Instance()->InitializeAllObj();
//
//	/*
//		创建一些全局性对象
//	*/
//	NFShmMgr::Instance()->InitShmObjectGlobal();
//
//	NFIPluginManager::Instance()->FindModule<NFIDescStoreModule>()->Initialize();

	return true;
}

bool NFCPluginManager::Finalize()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginLoader Finalize................");
	
	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
		itInstance->second->Finalize();
	}

#ifndef NF_DYNAMIC_PLUGIN
	////////////////////////////////////////////////

	for (auto it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		if (*it != "NFKernelPlugin")
		{
			UnLoadStaticPlugin(*it);
		}
	}

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:NFKernelPlugin");
	UnLoadStaticPlugin("NFKernelPlugin");
#else
	for (auto it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		if (*it != "NFKernelPlugin")
		{
			UnLoadPluginLibrary(*it);
		}
	}

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:NFKernelPlugin");
	UnLoadPluginLibrary("NFKernelPlugin");
#endif

	m_nPluginInstanceMap.clear();
	m_nPluginInstanceList.clear();
	m_nModuleInstanceMap.clear();
	m_nPluginNameVec.clear();
	return true;
}

bool NFCPluginManager::LoadStaticPlugin(const std::string& strPluginName)
{
	auto it = m_nPluginFuncMap.find(strPluginName);
	if (it == m_nPluginFuncMap.end())
	{
		NFLogError(NF_LOG_PLUGIN_MANAGER, 0, " Load Static Plugin [{0}] Failed, The Plugin Not Registered, Please Registed like this 'REGISTER_STATIC_PLUGIN(this, {0})' in the NFCLoadStaticPlugin.cpp", strPluginName);
		assert(0);
		return false;
	}

	if (FindPlugin(strPluginName)) return true;

	NFIPlugin* pPlugin = it->second(this);
	if (pPlugin)
	{
		NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:{}", strPluginName);
		Registered(pPlugin);
	}
	return true;
}

bool NFCPluginManager::UnLoadStaticPlugin(const std::string& strPluginDLLName)
{
	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:{}", strPluginDLLName);
	UnRegistered(FindPlugin(strPluginDLLName));
	return true;
}

uint32_t NFCPluginManager::GetFrame() const
{
	return m_nFrame;
}

uint32_t NFCPluginManager::GetFrameTime() const
{
	return m_nFrameTime;
}

bool NFCPluginManager::IsFixedFrame() const
{
    return m_bFixedFrame;
}

void NFCPluginManager::SetFixedFrame(bool frame)
{
    if (IsLoadAllServer()) return;

    m_bFixedFrame = frame;
}

uint32_t NFCPluginManager::GetIdleSleepUs() const
{
    return m_idleSleepUs;
}

void NFCPluginManager::SetIdelSleepUs(uint32_t time)
{
    if (IsLoadAllServer()) return;

    m_idleSleepUs = time;
}

uint64_t NFCPluginManager::GetInitTime() const
{
	return m_nInitTime;
}

uint64_t NFCPluginManager::GetNowTime() const
{
	return m_nNowTime;
}

int NFCPluginManager::GetMachineAddr(const std::string& str) {
    sigar_t *pSigar;
    sigar_open(&pSigar);

    sigar_net_interface_config_t netConfig;
    if (sigar_net_interface_config_get(pSigar, NULL, &netConfig) != SIGAR_OK)
    {
        return -1;
    }

    char name[SIGAR_FQDN_LEN];
    sigar_net_address_to_string(pSigar, &netConfig.hwaddr, name);
    std::string macAddr = name;

    std::string cpuId;
    std::string diskId;
    std::string boardSerial;
    if (get_cpu_id(cpuId) || get_disk_id(diskId) || get_board_serial_number(boardSerial))
    {
        std::string machineAddr = NF_FORMAT("{}|{}|{}|{}|{}", macAddr, str, cpuId, diskId, boardSerial);
        m_iMachineAddrMD5 = NFMD5::md5str(machineAddr);
    }
    else
    {
        std::string machineAddr = NF_FORMAT("{}|{}", macAddr, str);
        m_iMachineAddrMD5 = NFMD5::md5str(machineAddr);
    }

    sigar_close(pSigar);

    return 0;
}

bool NFCPluginManager::LoadPluginLibrary(const std::string& strPluginDLLName)
{
	PluginLibMap::iterator it = m_nPluginLibMap.find(strPluginDLLName);
	if (it == m_nPluginLibMap.end())
	{
		NFCDynLib* pLib = new NFCDynLib(strPluginDLLName);
		bool bLoad = pLib->Load();

		if (bLoad)
		{
			m_nPluginLibMap.insert(PluginLibMap::value_type(strPluginDLLName, pLib));

			DLL_START_PLUGIN_FUNC pFunc = (DLL_START_PLUGIN_FUNC)pLib->GetSymbol("DllStartPlugin");
			if (!pFunc)
			{
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "Find function DllStartPlugin Failed in [{}]", pLib->GetName());
				assert(0);
				return false;
			}

			pFunc(this);

			return true;
		}
		else
		{
#if NF_PLATFORM == NF_PLATFORM_LINUX || NF_PLATFORM == NF_PLATFORM_APPLE
			char* error = dlerror();
			if (error)
			{
				std::cout << "Load shared lib failed: " << strPluginDLLName << std::endl;
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, " Load DLL[{0}] failed, ErrorNo. = [{1}] Load [{0}] failed", strPluginDLLName, error);
                NFSLEEP(1000);
				exit(0);
				return false;
			}
			else
            {
                std::cout << "Load shared lib failed: " << strPluginDLLName << std::endl;
                NFSLEEP(1000);
                exit(0);
                return false;
            }
#elif NF_PLATFORM == NF_PLATFORM_WIN
			NFLogError(NF_LOG_PLUGIN_MANAGER, 0, " Load DLL[{0}] failed, ErrorNo. = [{1}] Load [{0}] failed", pLib->GetName(), GetLastError());
			exit(0);
			return false;
#endif // NF_PLATFORM
		}
	}

	return false;
}

bool NFCPluginManager::UnLoadPluginLibrary(const std::string& strPluginDLLName)
{
	PluginLibMap::iterator it = m_nPluginLibMap.find(strPluginDLLName);
	if (it != m_nPluginLibMap.end())
	{
		NFCDynLib* pLib = it->second;
		DLL_STOP_PLUGIN_FUNC pFunc = (DLL_STOP_PLUGIN_FUNC)pLib->GetSymbol("DllStopPlugin");

		if (pFunc)
		{
			pFunc(this);
		}

		pLib->UnLoad();

		delete pLib;
		pLib = NULL;
		m_nPluginLibMap.erase(it);

		return true;
	}

	return false;
}

bool NFCPluginManager::DynamicLoadPluginLibrary(const std::string& strPluginDLLName)
{
#ifndef NF_DYNAMIC_PLUGIN
	NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "can't load plugin:{}, you are static load!", strPluginDLLName);
#else
	NFIPlugin* pPlugin = FindPlugin(strPluginDLLName);
	if (pPlugin)
	{
		if (pPlugin->IsDynamicLoad() == false)
		{
			NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "plugin:{} can't not dynamic load!", strPluginDLLName);
			return false;
		}

		/*
		**卸载动态库
		*/
		pPlugin->OnDynamicPlugin();
		pPlugin->BeforeShut();
		pPlugin->Shut();
		pPlugin->Finalize();
		pPlugin = nullptr;
		UnLoadPluginLibrary(strPluginDLLName);

		/*
		**重新加载动态库
		*/
		//EN_OBJ_MODE oldMode = NFShmMgr::Instance()->GetInitMode();
		//NFShmMgr::Instance()->SetInitMode(EN_OBJ_MODE_RECOVER);
		LoadPluginLibrary(strPluginDLLName);
		pPlugin = FindPlugin(strPluginDLLName);
		if (pPlugin)
		{
			pPlugin->Awake();
			pPlugin->Init();
			pPlugin->ReadyExecute();
		}
		else
		{
			NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "dynamic load plugin:{} failed!", strPluginDLLName);
		}
		//NFShmMgr::Instance()->SetInitMode(oldMode);
	}
	else
	{
		NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "plugin:{} is not exist!", strPluginDLLName);
		return false;
	}
#endif
	return true;
}

void NFCPluginManager::BeginProfiler(const std::string& funcName)
{
	m_profilerMgr.BeginProfiler(funcName);
}

uint64_t NFCPluginManager::EndProfiler()
{
	return m_profilerMgr.EndProfiler();
}

void NFCPluginManager::ClearProfiler()
{
	m_profilerMgr.ResetAllProfilerTimer();
}

void NFCPluginManager::PrintProfiler()
{
	if (m_profilerMgr.IsOpenProfiler())
	{
		std::string str = m_profilerMgr.OutputTopProfilerTimer();
		NFLogDebug(NF_LOG_PLUGIN_MANAGER, 0, "{}", str);
	}
}

void NFCPluginManager::SetOpenProfiler(bool b)
{
	m_profilerMgr.SetOpenProfiler(b);
}

bool NFCPluginManager::IsOpenProfiler()
{
	return m_profilerMgr.IsOpenProfiler();
}

uint32_t NFCPluginManager::GetCurFrameCount() const
{
   return m_nCurFrameCount;
}

void NFCPluginManager::SetPidFileName()
{
	m_strPidFileName = NF_FORMAT("{}_{}.pid", m_strAppName, m_mStrBusName);
}

const std::string& NFCPluginManager::GetPidFileName()
{
	return m_strPidFileName;
}

#if NF_PLATFORM == NF_PLATFORM_LINUX
int NFCPluginManager::CheckPidFile()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist == false)
	{
		return 0;
	}

	std::string content;
	NFFileUtility::ReadFileContent(m_strPidFileName, content);

	pid_t proc_id = NFCommon::strto<pid_t>(content);

	std::string exe_path = NF_FORMAT("/proc/{}/cwd/{}", proc_id, m_strExeName);
	std::cout << "path = " << exe_path << std::endl;
	exist = NFFileUtility::IsFileExist(exe_path);
	if (exist == false)
	{
		return 0;
	}

	return -1;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
int  NFCPluginManager::CreatePidFile()
{
	pid_t proc_id = NFGetPID();
	std::cout << "pid = " << proc_id << std::endl;
	std::string pidName = NFCommon::tostr(proc_id);

	int32_t fd = ::open(m_strPidFileName.c_str(), O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
	if (-1 != fd &&
		::write( fd, (const void*)pidName.c_str(), pidName.length()))
	{
		close( fd );
		return 0;
	}
	return -1;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
int  NFCPluginManager::TimedWait(pid_t pid, int sec)
{
	int count = 0;
	do
	{
		sleep(1);
		count++;
		if (count >= sec)
		{
			return -1;
		}

		if (kill(pid, 0) == 0 || errno == EPERM)
			continue;
		else if (errno == ESRCH)
			break;
		else
			std::cout << "error checking pid:" << pid << " status" << std::endl;

	} while(true);
	return 0;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
int NFCPluginManager::KillPreApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUNUSED );

		return TimedWait( proc_id, 10);
	}

	return 0;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
void NFCPluginManager::KillApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUSR1);
	}
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
void NFCPluginManager::ReloadApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUSR2);
	}
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
void NFCPluginManager::QuitApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUNUSED);
	}
}
#endif

bool NFCPluginManager::IsInited() const 
{ 
	return m_isInited; 
}

void NFCPluginManager::SetIsInited(bool b) 
{ 
	m_isInited = b; 
}

int NFCPluginManager::RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t initStatus)
{
	return m_appInited.RegisterAppTask(eServerType, taskType, desc, initStatus);
}

int NFCPluginManager::FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t initStatus)
{
	return m_appInited.FinishAppTask(eServerType, taskType, initStatus);
}

int NFCPluginManager::SendDumpInfo(const std::string& dumpInfo)
{
    if (IsLoadAllServer()) return 0;

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

//    proto_ff::Proto_STMasterServerDumpInfoNtf ntf;
//    ntf.set_dump_info(dumpInfo);
//    ntf.set_bus_id(pConfig->mBusId);

//    NFMessageMgr::Instance()->SendMsgToMasterServer((NF_SERVER_TYPES)pConfig->mServerType, proto_ff::NF_STMaster_SEND_DUMP_INFO_NTF, ntf);
    return 0;
}

int NFCPluginManager::ShutDownApp()
{
    return 0;
}

std::list<NFIPlugin*> NFCPluginManager::GetListPlugin()
{
    return m_nPluginInstanceList;
}

std::string NFCPluginManager::GetMachineAddrMD5()
{
    return m_iMachineAddrMD5;
}
