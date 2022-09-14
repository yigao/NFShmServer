// -------------------------------------------------------------------------
//    @FileName         :    NFNetDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
// -------------------------------------------------------------------------
#pragma once

#include <stdint.h>
#include <string>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSimpleBuffer.h"
#include "NFComm/NFCore/NFDataStream.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"

#if NF_PLATFORM == NF_PLATFORM_WIN
#include <winsock2.h>
#include <windows.h>
#include <Ws2tcpip.h>
#else
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/tcp.h>
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN
#define ArkGetLastError		    WSAGetLastError
typedef int Socklen_t;
#define WIN32_LEAN_AND_MEAN
#else
#define SOCKET				int
#define ArkGetLastError()	errno
#define closesocket			close
#define ioctlsocket			ioctl
typedef struct linger 		    LINGER;
#define SOCKET_ERROR		-1
#define INVALID_SOCKET		-1
#define SD_SEND				SHUT_WR
#endif

#define MAX_SEND_BUFFER_SIZE (1024 * 100)
#define MAX_RECV_BUFFER_SIZE (1024 * 100)

struct NFMessageFlag
{
	uint32_t nWorkThreadNum; //工作线程个数
	uint16_t nPort; //端口
	uint32_t nMaxMsgNumPerTick; //每一分钟最大的消息包数
	uint32_t mPacketParseType; //解码消息类型
	std::string mStrIp;
	uint64_t mBusId;
	uint64_t mBusLength;
	uint64_t mLinkId;
	uint64_t mMaxConnectNum;
	std::string mBusName;
	bool bHttp;
	bool bActivityConnect;
	NFMessageFlag()
	{
        mLinkId = 0;
		nWorkThreadNum = 1;
		nPort = 0;
        nMaxMsgNumPerTick = 200;
        mMaxConnectNum = 100;
		mPacketParseType = 0;
		mBusId = 0;
		mBusLength = 0;
		bHttp = false;
        bActivityConnect = true;
	}
};
