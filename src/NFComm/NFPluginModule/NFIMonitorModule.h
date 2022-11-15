// -------------------------------------------------------------------------
//    @FileName         :    NFIMonitorModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIDynamicModule.h"
#include <vector>
#include <string>
#include "NFSystemInfo.h"

class NFIMonitorModule : public NFIDynamicModule
{
public:
    NFIMonitorModule(NFIPluginManager *p) : NFIDynamicModule(p)
    {

    }

    virtual ~NFIMonitorModule()
    {

    }

    virtual const NFSystemInfo &GetSystemInfo() const = 0;

    virtual uint32_t GetUserCount() const = 0;

    virtual void SetUserCount(uint32_t count) = 0;

    virtual double GetCpuUsed() = 0;

    virtual uint64_t GetMemUsed() = 0;

    virtual void CountAndPrint() = 0;
};

