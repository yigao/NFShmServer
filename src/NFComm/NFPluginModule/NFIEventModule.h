// -------------------------------------------------------------------------
//    @FileName         :    NFIEventModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFIEventModule
//
// -------------------------------------------------------------------------

#pragma once

#include <iostream>
#include "NFIModule.h"

class NFEventObjBase;

class NFIEventModule
	: public NFIModule
{
public:
	NFIEventModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFIEventModule()
	{

	}

	/**
	* @brief 发送事件,并执行收到事件的对象的对应函数
	*
	* @param nEventID		事件ID
	* @param nSrcID			事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType		事件源类型，玩家类型，怪物类型之类的
	* @param message	事件传输的数据
	* @return				执行是否成功
	*/
	virtual void FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message& message) = 0;

	/**
	* @brief 订阅事件
	*
	* @param nEventID	事件ID
	* @param nSrcID		事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType	事件源类型，玩家类型，怪物类型之类的
	* @param desc		事件描述，用于打印，获取信息，查看BUG之类的
	* @return			订阅事件是否成功
	*/
	virtual bool Subscribe(NFEventObjBase* pSink, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& desc) = 0;

	/**
	* @brief 取消订阅事件
	*
	* @param nEventID	事件ID
	* @param nSrcID		事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType	事件源类型，玩家类型，怪物类型之类的
	* @return			取消订阅事件是否成功
	*/
	virtual bool UnSubscribe(NFEventObjBase* pSink, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID) = 0;

	/**
	* @brief 取消NFEventObj所有订阅事件
	*
	* @return			取消订阅事件是否成功
	*/
	virtual bool UnSubscribeAll(NFEventObjBase* pSink) = 0;
};


