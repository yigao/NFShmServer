// -------------------------------------------------------------------------
//    @FileName         :    NFIMonitorModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"
#include <vector>
#include <string>
#include "NFSystemInfo.h"

class NFIMonitorModule : public NFIModule
{
public:
	NFIMonitorModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFIMonitorModule()
	{

	}

	virtual const NFSystemInfo& GetSystemInfo() const = 0;
	virtual uint32_t GetUserCount() const = 0;
	virtual void SetUserCount(uint32_t count) = 0;
    virtual double GetCpuUsed() = 0;
    virtual uint64_t GetMemUsed() = 0;
    virtual void CountAndPrint() = 0;
};

