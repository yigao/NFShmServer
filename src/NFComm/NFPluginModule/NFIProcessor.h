// -------------------------------------------------------------------------
//    @FileName         :    NFIProcessor.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

/// @brief 消息处理抽象接口
class NFIProcessor 
{
public:
	NFIProcessor();
	virtual ~NFIProcessor();

	/// @brief 消息处理入口(Processor的输入)
	/// @param handle 网络句柄(用于传输消息的连接或消息队列标识)
	/// @param msg 消息
	/// @param msg_len 消息长度
	/// @param msg_info 消息属性
	/// @param is_overload 是否过载(框架根据程序运行情况告知Processor目前是否过载，由Processor自行过载处理)
	///     涵盖了具体的过载类型，具体可参考 @see OverLoadType
	/// @return 0 成功
	/// @return 非0 失败
	// TODO: 每个Processor建议维护一个消息白名单或优先级列表，允许某些消息即使在过载情况下仍然要处理
	virtual int32_t OnMessage(int64_t handle, const uint8_t* msg, uint32_t msg_len, const MsgExternInfo* msg_info, uint32_t is_overload) = 0;

	/// @brief Processor发送消息接口，实际使用SetSendFunction设置的send函数，用户可扩展在send前做些特殊处理
	/// @return 0 成功，<0 失败
	virtual int32_t Send(int64_t handle, const uint8_t* msg, uint32_t msg_len, int32_t flag);

	/// @brief Processor发送消息接口，实际使用SetSendFunction设置的sendv函数，用户可扩展在send前做些特殊处理
	/// @return 0 成功，<0 失败
	virtual int32_t SendV(int64_t handle, uint32_t msg_frag_num,
		const uint8_t* msg_frag[], uint32_t msg_frag_len[], int32_t flag);
};
