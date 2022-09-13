// -------------------------------------------------------------------------
//    @FileName         :    NetEvppObject.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
//
//                    .::::.
//                  .::::::::.
//                 :::::::::::  FUCK YOU
//             ..:::::::::::'
//           '::::::::::::'
//             .::::::::::
//        '::::::::::::::..
//             ..::::::::::::.
//           ``::::::::::::::::
//            ::::``:::::::::'        .:::.
//           ::::'   ':::::'       .::::::::.
//         .::::'      ::::     .:::::::'::::.
//        .:::'       :::::  .:::::::::' ':::::.
//       .::'        :::::.:::::::::'      ':::::.
//      .::'         ::::::::::::::'         ``::::.
//  ...:::           ::::::::::::'              ``::.
// ```` ':.          ':::::::::'                  ::::..
//                    '.:::::'                    ':'````..
//
// -------------------------------------------------------------------------
#pragma once

#include <cstdint>

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFNetDefine.h"
#include "NFComm/NFCore/NFBuffer.h"
#include "evpp/tcp_conn.h"
#include "evpp/event_loop.h"

class NFEvppNetMessage;
class NFEvppClient;

/**
* @brief 网络对象，代表一个连接
*/
class NetEvppObject
{
public:
	friend NFEvppNetMessage;

	/**
	 * @brief	构造函数
	 */
	NetEvppObject(const evpp::TCPConnPtr& conn);

	/**
	 * @brief	析构函数
	 */
	virtual ~NetEvppObject();

	/**
	 * @brief
	 *
	 * @return std::string
	 */
	std::string GetStrIp() const;

	/**
	 * @brief
	 *
	 * @param  val
	 * @return void
	 */
	void SetStrIp(std::string val);

	/**
	 * @brief	获得唯一ID
	 *
	 * @return
	 */
	uint64_t GetLinkId() const;

	/**
	* @brief	获得唯一ID
	*
	* @return
	*/
	void SetLinkId(uint64_t linkId);

	/**
	 * @brief
	 *
	 * @return bool
	 */
	bool GetNeedRemove() const;

	/**
	 * @brief
	 *
	 * @param  val
	 * @return void
	 */
	void SetNeedRemove(bool val);

	/**
	 * @brief 关闭对象禁止对象的读写功能
	 *
	 * @return void
	 */
	virtual void CloseObject();

	/**
	* @brief 是否是服务器端
	*
	* @return void
	*/
	virtual void SetIsServer(bool b);

	/**
	* @brief 设置解析方法
	*
	* @return void
	*/
	virtual void SetPacketParseType(uint32_t packetType) { mPacketParseType = packetType; }

	virtual void SetConnPtr(const evpp::TCPConnPtr conn) { mConnPtr = conn; }

	virtual void SetLastHeartBeatTime(uint64_t updateTime) { mLastHeartBeatTime = updateTime; }
	virtual uint64_t GetLastHeartBeatTime() const { return mLastHeartBeatTime; }
protected:
	/**
	 * @brief	代表客户端连接的唯一ID
	 */
	uint64_t m_usLinkId;

	/**
	 * @brief	连接代表的对方的IP
	 */
	std::string m_strIp;

	/**
	 * @brief 是否需要删除, 这个链接不在起作用，将在下一次循环中被删除
	 */
	bool mNeedRemove;

	/**
	* @brief is server
	*/
	bool mIsServer; //是否是服务器端

	/**
	* @brief 解码消息类型
	*/
	uint32_t mPacketParseType;

	/**
	* @brief 来自EVPP的链接代理
	*/
	evpp::TCPConnPtr mConnPtr;

	/**
	* @brief 心跳包更新时间
	*/
	uint64_t mLastHeartBeatTime;
};
