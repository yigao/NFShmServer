// -------------------------------------------------------------------------
//    @FileName         :    NFIConnection.h
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

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFNetDefine.h"

#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include <evpp/tcp_client.h>

enum NFConnectionType
{
	NF_CONNECTION_TYPE_NONE = 0,
	NF_CONNECTION_TYPE_TCP_SERVER = 1,
	NF_CONNECTION_TYPE_TCP_CLIENT = 2,
};

class NFIConnection : public NFIModule
{
public:
	NFIConnection(NFIPluginManager* p, NF_SERVER_TYPES serverType, const NFMessageFlag& flag):NFIModule(p), mConnectionType(0), mUnLinkId(0), mServerType(serverType), mFlag(flag)
	{

	}

	virtual ~NFIConnection()
	{

	}

	virtual void SetConnCallback(const evpp::ConnectionCallback& back)
	{
		mConnCallback = back;
	}

	virtual void SetMessageCallback(const evpp::MessageCallback& back)
	{
		mMessageCallback = back;
	}

	virtual uint64_t GetBusId() const { return mFlag.mBusId; }

    virtual uint64_t GetBusLength() const { return mFlag.mBusLength; }

	virtual uint32_t GetPacketParseType() const { return mFlag.mPacketParseType; }

	virtual uint32_t GetConnectionType() { return mConnectionType; }

	virtual void SetConnectionType(uint32_t type) { mConnectionType = type; }

	virtual void SetLinkId(uint64_t id) { mUnLinkId = id; }
	virtual uint64_t GetLinkId() const { return mUnLinkId; }
protected:
	evpp::ConnectionCallback mConnCallback;

	evpp::MessageCallback mMessageCallback;

	uint32_t mConnectionType;

	uint64_t mUnLinkId;

	NF_SERVER_TYPES mServerType;

	NFMessageFlag mFlag;
};
