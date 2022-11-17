// -------------------------------------------------------------------------
//    @FileName         :    NFShmTempMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTempMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

/**
 * @brief 由于C++类的构造函数，析构函数调用虚函数的问题，又不想NFShmObj类的构造函数含有太多的参数，所以用这个类来传一些临时的参数
 */
class NFShmTempMgr : public NFSingleton<NFShmTempMgr>
{
public:
    NFShmTempMgr();

    virtual ~NFShmTempMgr();
public:
    NFIPluginManager* m_pTempPluginManager;
    int m_iType;
};