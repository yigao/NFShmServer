// -------------------------------------------------------------------------
//    @FileName         :    NFCPluginManager.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCPluginManager
//
// -------------------------------------------------------------------------

#include "NFCDynLib.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFCDynLibMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFTea.h"
#include "NFComm/NFCore/NFCommon.h"

bool NFCDynLib::Load()
{
    std::string strLibPath = "./";
    strLibPath += mstrName;

    mInst = (DYNLIB_HANDLE)DYNLIB_LOAD(strLibPath.c_str());
    if (mInst != NULL)
    {
#if NF_PLATFORM != NF_PLATFORM_WIN
#ifndef NF_DEBUG_MODE
        if (NFFileUtility::IsFileExist(strLibPath))
        {
            //NFFileUtility::Remove(strLibPath);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the plugin file");
            NFSLEEP(1000);
            exit(0);
        }
#endif
#endif
    }

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:{}", mstrName);
    return mInst != NULL;
}

bool NFCDynLib::UnLoad()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    DYNLIB_UNLOAD(mInst);
	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:{}", mstrName);
#else
    int succ = DYNLIB_UNLOAD(mInst);
    if (succ)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:{} failed, error={}", mstrName, dlerror());
    }
    else
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:{}", mstrName);
    }
#endif
    return true;
}

void* NFCDynLib::GetSymbol(const char* szProcName)
{
    return (DYNLIB_HANDLE)DYNLIB_GETSYM(mInst, szProcName);
}
