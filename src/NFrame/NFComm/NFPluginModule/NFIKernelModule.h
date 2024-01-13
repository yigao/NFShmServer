// -------------------------------------------------------------------------
//    @FileName         :    NFIKernelModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFIKernelModule
//
// -------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include "NFIDynamicModule.h"

class NFIKernelModule
	: public NFIDynamicModule
{
public:
	NFIKernelModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIKernelModule()
	{

	}

	virtual uint64_t GetUUID() = 0;
	virtual uint64_t Get64UUID() = 0;
    virtual uint64_t Get53UUID() = 0;
    //由于客户端LUA 中 int64_t 类型最大只能表示 2的53次方，所以角色cid由原来的64位改成现在的51位表示(12位区服ID+39位序号)
	virtual uint64_t Get32UUID() = 0;
	virtual std::string GetMD5(const std::string& str) = 0;
	virtual uint32_t GetCRC32(const std::string& s) = 0;
	virtual uint16_t GetCRC16(const std::string& s) = 0;
	virtual std::string Base64Encode(const std::string& s) = 0;
	virtual std::string Base64Decode(const std::string& s) = 0;
};


