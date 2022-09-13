// -------------------------------------------------------------------------
//    @FileName         :    NFCrashHandlerMgr.cpp
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

#include "NFCrashHandlerMgr.h"

#if NF_PLATFORM == NF_PLATFORM_WIN

void CreateDumpFile(const std::string& strDumpFilePathName, EXCEPTION_POINTERS* pException)
{
	//Dump
	HANDLE hDumpFile = CreateFile(strDumpFilePathName.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
	dumpInfo.ExceptionPointers = pException;
	dumpInfo.ThreadId = GetCurrentThreadId();
	dumpInfo.ClientPointers = TRUE;

	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, nullptr, nullptr);

	CloseHandle(hDumpFile);
}

long ApplicationCrashHandler(EXCEPTION_POINTERS* pException)
{
	time_t t = time(nullptr);
	char szDmupName[MAX_PATH];
	tm* ptm = localtime(&t);

	sprintf_s(szDmupName, "%04d_%02d_%02d_%02d_%02d_%02d.dmp", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	CreateDumpFile(szDmupName, pException);

	FatalAppExit(-1, szDmupName);

	return EXCEPTION_EXECUTE_HANDLER;
}
#endif