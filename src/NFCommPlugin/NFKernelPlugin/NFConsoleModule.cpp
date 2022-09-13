// -------------------------------------------------------------------------
//    @FileName         :    NFConsoleModule.cpp
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFConsoleModule
//
// -------------------------------------------------------------------------

#include "NFConsoleModule.h"
#include "NFComm/NFPluginModule/NFIConsoleModule.h"

#include <string>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFTimerMgr.h"
#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFMD5.h"

NFCConsoleModule::NFCConsoleModule(NFIPluginManager* p):NFIConsoleModule(p)
{
	m_pPluginManager = p;
}

NFCConsoleModule::~NFCConsoleModule()
{
	
}

bool NFCConsoleModule::Shut()
{
	if (mBackThread.joinable())
	{
		mBackThread.detach();
	}
	if (mPluginThread.joinable())
	{
		mPluginThread.detach();
	}
	return true;
}

bool NFCConsoleModule::Awake()
{
	if (m_pPluginManager->IsDaemon() == false)
	{
		try
		{
			mCmdParser.Add("Exit", 0, "Exit App");
			mCmdParser.Add("Profiler", 0, "Open Profiler");
			mCmdParser.Add("Reload", 0, "Reload plugin config");

			mCmdParser.Add<std::string>("Dynamic", 0, "Dynamic Load Plugin", false, "xxPlugin");
		}
		catch (NFCmdLine::NFCmdLine_Error& e)
		{
			NFLogWarning(NF_LOG_SYSTEMLOG, 0, e.what());
		}

		/*
		* 创建检查输入线程
		*/
		CreateBackThread();
	}
#ifdef NF_DYNAMIC_PLUGIN
	/*
	* 创建检查可以动态加载的引擎线程
	*/
	//CheckPluginThread();
#endif
	/*
	* 定时器每1秒检查一次， 看是否有输入
	*/
	SetTimer(0, 1000, INFINITY_CALL);

	return true;
}

void NFCConsoleModule::CreateBackThread()
{
	mBackThread = std::thread(&NFCConsoleModule::BackThreadLoop, this);
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CreateBackThread...............");
}

void NFCConsoleModule::CheckPluginThread()
{
	mPluginThread = std::thread(&NFCConsoleModule::CheckPluginThreadLoop, this);
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CheckPluginThread...............");
}

void NFCConsoleModule::CheckPluginThreadLoop()
{
	uint32_t count = 0;
	while (!m_pPluginManager->GetExitApp())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		count++;
		if (count % 10 == 0)
		{
			CheckPluginFileModify();
		}
	}
}

bool  NFCConsoleModule::Execute()
{
	return true;
}

bool  NFCConsoleModule::OnReloadPlugin()
{
	return true;
}

void NFCConsoleModule::BackThreadLoop()
{
	while (!m_pPluginManager->GetExitApp())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::string s;
		std::cin >> s;

		if (s.empty())
		{
			continue;
		}

		std::string cmd = m_pPluginManager->GetAppName() + " " + s;
		try
		{
			mCmdParser.ClearParse();
			if (!mCmdParser.ParseConsoleCommand(cmd))
			{
				std::cout << mCmdParser.ErrorFull() << std::endl;
				std::cout << mCmdParser.Usage() << std::endl;
				continue;
			}

			if (mCmdParser.Exist("Exit"))
			{
				NFConsoleMsg msg;
				msg.mMsgType = NFConsoleMsg_Exit;
				mQueueMsg.Push(msg);
				mBackThread.detach();
				return;
			}

			if (mCmdParser.Exist("Profiler"))
			{
				NFConsoleMsg msg;
				msg.mMsgType = NFConsoleMsg_Profiler;
				mQueueMsg.Push(msg);
			}

			if (mCmdParser.Exist("Dynamic"))
			{
				std::string strPluginName = mCmdParser.Get<std::string>("Dynamic");
				if (!strPluginName.empty())
				{
					NFConsoleMsg msg;
					msg.mMsgType = NFConsoleMsg_Dynamic;
					msg.mParam1 = strPluginName;
					mQueueMsg.Push(msg);
				}
			}

			if (mCmdParser.Exist("Reload"))
			{
				NFConsoleMsg msg;
				msg.mMsgType = NFConsoleMsg_Reload;
				mQueueMsg.Push(msg);
			}
		}
		catch (NFCmdLine::NFCmdLine_Error& e)
		{
			NFLogWarning(NF_LOG_SYSTEMLOG, 0, e.what());
		}
	}
}

void NFCConsoleModule::AddDynamicPluginFile(const std::string& file)
{
	std::string filePath = file;
#if NF_PLATFORM == NF_PLATFORM_WIN
	filePath.append(".dll");
#elif NF_PLATFORM == NF_PLATFORM_LINUX || NF_PLATFORM == NF_PLATFORM_ANDROID
	filePath = "lib" + filePath + ".so";
#elif NF_PLATFORM == NF_PLATFORM_APPLE || NF_PLATFORM == NF_PLATFORM_APPLE_IOS
	filePath = "lib" + filePath + ".so";
#endif
	filePath = "./" + filePath;

	if (NFFileUtility::IsFileExist(filePath))
	{
		NFConsolePluginFile pluginfile;
		pluginfile.mPluginFile = filePath;
		pluginfile.mPluginName = file;
		pluginfile.mModifyTime = NFFileUtility::GetFileModificationDate(filePath);
		pluginfile.mTempModifyTime = pluginfile.mModifyTime;
		pluginfile.mPluginMd5 = NFMD5::md5file(filePath);
		mPluginFileList.push_back(pluginfile);
	}
}

void NFCConsoleModule::CheckPluginFileModify()
{
	for(size_t i = 0; i < mPluginFileList.size(); i++)
	{
		NFConsolePluginFile& plugin = mPluginFileList[i];
		if (NFFileUtility::IsFileExist(plugin.mPluginFile))
		{
			uint32_t modifyTime = NFFileUtility::GetFileModificationDate(plugin.mPluginFile);
			if (modifyTime > plugin.mTempModifyTime)
			{
				plugin.mTempModifyTime = modifyTime;

				int loop = 5;
				while(loop >= 0)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
					modifyTime = NFFileUtility::GetFileModificationDate(plugin.mPluginFile);
					if (modifyTime > plugin.mTempModifyTime)
					{
						plugin.mTempModifyTime = modifyTime;
						loop = 5;
					}
					else if (modifyTime == plugin.mTempModifyTime)
					{
						--loop;
					}
				}

				plugin.mTempModifyTime = modifyTime;
				plugin.mModifyTime = modifyTime;

				std::string md5 = NFMD5::md5file(plugin.mPluginFile);
				if (md5 != plugin.mPluginMd5)
				{
					plugin.mPluginMd5 = md5;

					NFConsoleMsg msg;
					msg.mMsgType = NFConsoleMsg_Dynamic;
					msg.mParam1 = plugin.mPluginName;
					mQueueMsg.Push(msg);
				}

				break;
			}
		}
	}
}

void NFCConsoleModule::OnTimer(uint32_t nTimerID)
{
	std::vector<NFConsoleMsg> vec;
	mQueueMsg.Pop(vec);

	for (size_t i = 0; i < vec.size(); i++)
	{
		const NFConsoleMsg& msg = vec[i];

		if (msg.mMsgType == NFConsoleMsg_Exit)
		{
			m_pPluginManager->SetExitApp(true);
		}
		else if (msg.mMsgType == NFConsoleMsg_Profiler)
		{
			m_pPluginManager->SetChangeProfileApp(true);
		}
		else if (msg.mMsgType == NFConsoleMsg_Reload)
		{
			m_pPluginManager->SetReloadApp(true);
		}
		else if (msg.mMsgType == NFConsoleMsg_HotfixAllLua)
		{

		}
		else if (msg.mMsgType == NFConsoleMsg_HotfixLua)
		{

		}
		else if (msg.mMsgType == NFConsoleMsg_Dynamic)
		{
			m_pPluginManager->DynamicLoadPluginLibrary(msg.mParam1);
		}
		else if (msg.mMsgType == NFConsoleMsg_ProductFile)
		{
			
		}
	}
}
