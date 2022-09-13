// -------------------------------------------------------------------------
//    @FileName         :    NFIKernelModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFIKernelModule
//
// -------------------------------------------------------------------------

#ifndef NFI_KERNEL_MODULE_H
#define NFI_KERNEL_MODULE_H

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include "NFIModule.h"
#include "NFIDynamicModule.h"

class NFIObject;

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
	virtual uint64_t Get32UUID() = 0;
	virtual std::string GetMD5(const std::string& str) = 0;
	virtual uint32_t GetCRC32(const std::string& s) = 0;
	virtual uint16_t GetCRC16(const std::string& s) = 0;
	virtual std::string Base64Encode(const std::string& s) = 0;
	virtual std::string Base64Decode(const std::string& s) = 0;
};

#endif

