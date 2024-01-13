// -------------------------------------------------------------------------
//    @FileName         :    NFShmMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFShmDefine.h"

/**
 * @brief 由于C++类的构造函数，析构函数调用虚函数的问题，又不想NFShmObj类的构造函数含有太多的参数，所以用这个类来传一些临时的参数
 */
class NFShmMgr : public NFSingleton<NFShmMgr>
{
public:
	NFShmMgr();
	virtual ~NFShmMgr();
public:
	/**
	* 共享内存创建对象模式
	*/
	virtual EN_OBJ_MODE	GetCreateMode();

	/**
	* 共享内存创建对象模式
	*/
	virtual void	SetCreateMode(EN_OBJ_MODE mode);

    /**
    * @brief  获得偏移地址
    */
    virtual size_t   GetAddrOffset();

    virtual void SetAddrOffset(size_t offset);
public:
    EN_OBJ_MODE m_objMode;
    /**
    * 相对于上次共享内存地址recover之后的偏移量,用来恢复指针对象
    */
    size_t  m_siAddrOffset;
public:
    NFIPluginManager* m_pTempPluginManager;
    int m_iType;
};

