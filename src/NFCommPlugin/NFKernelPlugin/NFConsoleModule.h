// -------------------------------------------------------------------------
//    @FileName         :    NFConsoleModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFConsoleModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIConsoleModule.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include "NFComm/NFCore/NFCmdLine.h"
#include "NFComm/NFCore/NFQueue.hpp"

#include <thread>
#include <future>

enum NFConsoleMsgEnum
{
    NFConsoleMsg_Null = 0,
    NFConsoleMsg_Exit = 1,
    NFConsoleMsg_Profiler = 2,
    NFConsoleMsg_Reload = 3,    //重载引擎配置
    NFConsoleMsg_Dynamic = 4,    //动态加载引擎
    NFConsoleMsg_ProductFile = 5, //类节点头文件
    NFConsoleMsg_HotfixLua = 6, //类节点头文件
    NFConsoleMsg_HotfixAllLua = 7, //类节点头文件
};

struct NFConsoleMsg
{
    NFConsoleMsgEnum mMsgType;
    std::string mParam1;
    std::string mParam2;
    std::string mParam3;
    std::string mParam4;
    std::string mParam5;
};

struct NFConsolePluginFile
{
    NFConsolePluginFile()
    {
        mModifyTime = 0;
        mTempModifyTime = 0;
    }

    uint32_t mTempModifyTime;
    uint32_t mModifyTime;
    std::string mPluginFile;
    std::string mPluginName;
    std::string mPluginMd5;
};

class NFCConsoleModule : public NFIConsoleModule
{
public:
    NFCConsoleModule(NFIPluginManager *p);

    virtual ~NFCConsoleModule();

public:
    virtual bool Awake();

    virtual bool Execute();

    virtual bool Shut();

    virtual bool OnReloadConfig();

    virtual void OnTimer(uint32_t nTimerID);

    virtual void AddDynamicPluginFile(const std::string &file);

    virtual void CheckPluginFileModify();

public:
    virtual void CreateBackThread();

    virtual void CheckPluginThread();

    virtual void BackThreadLoop();

    virtual void CheckPluginThreadLoop();

private:
    NFCmdLine::NFParser mCmdParser;
    std::shared_ptr<std::thread> mBackThread;
    std::shared_ptr<std::thread> mPluginThread;
    NFQueueVector<NFConsoleMsg> mQueueMsg;

    std::vector<NFConsolePluginFile> mPluginFileList;
};
