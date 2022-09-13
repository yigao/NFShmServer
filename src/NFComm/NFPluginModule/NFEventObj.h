// -------------------------------------------------------------------------
//    @FileName         :    NFEventObj.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <stdint.h>
#include "NFComm/NFCore/NFPlatform.h"
#include "google/protobuf/message.h"

/* 事件使用注意事项
 取消订阅事件的时传入的参数一定要和订阅事件时传入的参数一致，
 事件内部是以订阅事件传入的参数（包括回调指针）组合为事件key的，
 如果取消和订阅时参数不一致， 取消订阅就会失败，就会导致有事件残留（包括野指针），下次该事件发生的时候触发回调就会异常

 事件嵌套层数不能太多，如果可以，尽量不要使用事件嵌套，主要是为了避免造成死循环，目前事件最大嵌套层数支持5层
*/

/**
 *@brief 事件系统对象，所有想使用事件系统的都必须继承这个对象
 */
class _NFExport NFEventObj
{
public:
	/**
	 *@brief 构造函数
	 */
	NFEventObj();

	/**
	 *@brief 析构函数
	 */
	virtual ~NFEventObj();
public:
	/**
	* @brief 收到事件函数, 对收到的事件进行处理
	*
	* @param nEventID		事件ID
	* @param nSrcID			事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType		事件源类型，玩家类型，怪物类型之类的
	* @param pEventContext	发过来的事件数据
	* @return
	*/
	/*
	* 由Fire的问题，导致的问题:
	* 问题1:如果在OnExecute函数里， 调用别的对象的UnSubscribe函数, 如果key一致(也就是nEventID,nSrcID,bySrcType都一样),
	*		可能导致将要执行的事件被删除，这可能与你预想的设计不一样
	* 问题2:如果在OnExecute函数里， Fire了别的事件，会导致迭代问题，事件系统已经了做了预付， 相同的事件，最多迭代5次，
	*       所有的Fire事件最多迭代20次
	*/
	virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message) = 0;
public:
	/**
	* @brief 发送事件,并执行收到事件的对象的对应函数
	*
	* @param nEventID		事件ID
	* @param nSrcID			事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType		事件源类型，玩家类型，怪物类型之类的
	* @param pEventContext	事件传输的数据
	* @return				执行是否成功
	*/
	/*
	* 几个威胁，可能导致问题, 但不会导致崩溃, 可能与你预想的不一样:
	* 问题1:假设我在Fire事件里，相同的key，删除不同的pSink,
	*		可能导致将要执行的事件被删除，这可能与你预想的设计不一样
	* 问题2:假设我在Fire事件里，相同的key，删除相同的pSink, 由于事件系统利用SubscribeInfo的Add,Sub引用计数做了预防，
	*       迭代器不会立马被删除，不会导致std::list迭代器失效， 这样删除不会导致问题
	* 问题3:假设我在Fire事件里， Fire了别的事件，会导致迭代问题，事件系统已经了做了预付， 相同的事件，最多迭代5次，
	*       所有的Fire事件最多迭代20次
	*/
	void FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message);

	/**
	* @brief 订阅事件
	*
	* @param nEventID	事件ID
	* @param nSrcID		事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType	事件源类型，玩家类型，怪物类型之类的
	* @param desc		事件描述，用于打印，获取信息，查看BUG之类的
	* @return			订阅事件是否成功
	*/
	bool Subscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string& desc);

	/**
	* @brief 取消订阅事件
	*
	* @param nEventID	事件ID
	* @param nSrcID		事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType	事件源类型，玩家类型，怪物类型之类的
	* @return			取消订阅事件是否成功
	*/
	bool UnSubscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType);

	/**
	* @brief 取消NFEventObj所有订阅事件
	*
	* @return			取消订阅事件是否成功
	*/
	bool UnSubscribeAll();
};

