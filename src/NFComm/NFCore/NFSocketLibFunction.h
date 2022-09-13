// -------------------------------------------------------------------------
//    @FileName         :    NFSocketLibFunction.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_WIN
#include <winsock2.h>
#include <WinError.h>
#include <winsock.h>
#include <Ws2tcpip.h>
#include <errno.h>

#else
#include <signal.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/eventfd.h>
#include <sys/uio.h>
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN
typedef SOCKET NFSocketFD;
#define NF_ERRNO WSAGetLastError()
#define NF_ENOTSOCK WSAENOTSOCK
#define NF_EWOULDBLOCK WSAEWOULDBLOCK
#define NF_EINTR WSAEINTR
#define NF_ECONNABORTED WSAECONNABORTED
#define NF_SOCKET_ERROR SOCKET_ERROR
#define NF_INVALID_SOCKET INVALID_SOCKET

#else
#define NF_ERRNO errno
#define NF_ENOTSOCK EBADF
#define NF_EWOULDBLOCK EAGAIN
#define NF_EINTR EINTR
#define NF_ECONNABORTED ECONNABORTED
typedef int NFSocketFD;
#define NF_SOCKET_ERROR (-1)
#define NF_INVALID_SOCKET (-1)
#endif

class NFSocketLibFunction
{
public:
	static bool InitSocket()
	{
		bool ret = true;
#if NF_PLATFORM == NF_PLATFORM_WIN
		static WSADATA g_WSAData;
		static bool WinSockIsInit = false;
		if (WinSockIsInit)
		{
			return true;
		}
		if (WSAStartup(MAKEWORD(2, 2), &g_WSAData) == 0)
		{
			WinSockIsInit = true;
		}
		else
		{
			ret = false;
		}
#else
		signal(SIGPIPE, SIG_IGN);
#endif

		return ret;
	}

	static void DestroySocket()
	{
#if NF_PLATFORM == NF_PLATFORM_WIN
		WSACleanup();
#endif
	}

	static int  SocketNodelay(NFSocketFD fd)
	{
		const int flag = 1;
		return ::setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (const char*)&flag, sizeof(flag));
	}

	static bool SocketBlock(NFSocketFD fd)
	{
		int err;
		unsigned long ul = false;
#if NF_PLATFORM == NF_PLATFORM_WIN
		err = ioctlsocket(fd, FIONBIO, &ul);
#else
		err = ioctl(fd, FIONBIO, &ul);
#endif

		return err != NF_SOCKET_ERROR;
	}

	static bool SocketNonblock(NFSocketFD fd)
	{
		int err;
		unsigned long ul = true;
#if NF_PLATFORM == NF_PLATFORM_WIN
		err = ioctlsocket(fd, FIONBIO, &ul);
#else
		err = ioctl(fd, FIONBIO, &ul);
#endif

		return err != NF_SOCKET_ERROR;
	}

	static int  SocketSetSendSize(NFSocketFD fd, int sd_size)
	{
		return ::setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char*)&sd_size, sizeof(sd_size));
	}

	static int  SocketSetRecvSize(NFSocketFD fd, int rd_size)
	{
		return ::setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char*)&rd_size, sizeof(rd_size));
	}

	static NFSocketFD SocketCreate(int af, int type, int protocol)
	{
		return ::socket(af, type, protocol);
	}

	static void SocketClose(NFSocketFD fd)
	{
#if NF_PLATFORM == NF_PLATFORM_WIN
		::closesocket(fd);
#else
		::close(fd);
#endif
	}

	static NFSocketFD Connect(bool isIPV6, const std::string& server_ip, int port)
	{
		InitSocket();

		struct sockaddr_in ip4Addr = sockaddr_in();
		struct sockaddr_in6 ip6Addr = sockaddr_in6();
		struct sockaddr_in* paddr = &ip4Addr;
		int addrLen = sizeof(ip4Addr);

		NFSocketFD clientfd = isIPV6 ?
			SocketCreate(AF_INET6, SOCK_STREAM, 0) :
			SocketCreate(AF_INET, SOCK_STREAM, 0);

		if (clientfd == NF_INVALID_SOCKET)
		{
			return clientfd; //-V1020
		}

		bool ptonResult = false;
		if (isIPV6)
		{
			ip6Addr.sin6_family = AF_INET6;
			ip6Addr.sin6_port = htons(port);
			ptonResult = inet_pton(AF_INET6,
				server_ip.c_str(),
				&ip6Addr.sin6_addr) > 0;
			paddr = (struct sockaddr_in*) & ip6Addr; //-V641
			addrLen = sizeof(ip6Addr);
		}
		else
		{
			ip4Addr.sin_family = AF_INET;
			ip4Addr.sin_port = htons(port);
			ptonResult = inet_pton(AF_INET,
				server_ip.c_str(),
				&ip4Addr.sin_addr) > 0;
		}

		if (!ptonResult)
		{
			SocketClose(clientfd);
			return NF_INVALID_SOCKET;
		}

		while (::connect(clientfd, (struct sockaddr*)paddr, addrLen) < 0)
		{
			if (EINTR == NF_ERRNO)
			{
				continue;
			}

			SocketClose(clientfd);
			return NF_INVALID_SOCKET;
		}

		return clientfd; //-V1020
	}

	static NFSocketFD Listen(bool isIPV6, const char* ip, int port, int back_num)
	{
		InitSocket();

		struct sockaddr_in ip4Addr = sockaddr_in();
		struct sockaddr_in6 ip6Addr = sockaddr_in6();
		struct sockaddr_in* paddr = &ip4Addr;
		int addrLen = sizeof(ip4Addr);

		const auto socketfd = isIPV6 ?
			socket(AF_INET6, SOCK_STREAM, 0) :
			socket(AF_INET, SOCK_STREAM, 0);
		if (socketfd == NF_INVALID_SOCKET)
		{
			return NF_INVALID_SOCKET;
		}

		bool ptonResult = false;
		if (isIPV6)
		{
			ip6Addr.sin6_family = AF_INET6;
			ip6Addr.sin6_port = htons(port);
			ptonResult = inet_pton(AF_INET6, ip, &ip6Addr.sin6_addr) > 0;
			paddr = (struct sockaddr_in*) & ip6Addr; //-V641
			addrLen = sizeof(ip6Addr);
		}
		else
		{
			ip4Addr.sin_family = AF_INET;
			ip4Addr.sin_port = htons(port);
			ip4Addr.sin_addr.s_addr = INADDR_ANY;
			ptonResult = inet_pton(AF_INET, ip, &ip4Addr.sin_addr) > 0;
		}

		const int reuseaddr_value = 1;
		if (!ptonResult ||
			::setsockopt(socketfd,
				SOL_SOCKET,
				SO_REUSEADDR,
				(const char*)&reuseaddr_value,
				sizeof(int)) < 0)
		{
			SocketClose(socketfd);
			return NF_INVALID_SOCKET;
		}

		const int bindRet = ::bind(socketfd, (struct sockaddr*)paddr, addrLen);
		if (bindRet == NF_SOCKET_ERROR ||
			listen(socketfd, back_num) == NF_SOCKET_ERROR)
		{
			SocketClose(socketfd);
			return NF_INVALID_SOCKET;
		}

		return socketfd;
	}

	static std::string getIPString(const struct sockaddr* sa)
	{
#if NF_PLATFORM == NF_PLATFORM_WIN
		using PAddrType = PVOID;
#else
		using PAddrType = const void*;
#endif
		char tmp[INET6_ADDRSTRLEN] = { 0 };
		switch (sa->sa_family)
		{
		case AF_INET:
			inet_ntop(AF_INET, (PAddrType)(&(((const struct sockaddr_in*)sa)->sin_addr)),
				tmp, sizeof(tmp));
			break;
		case AF_INET6:
			inet_ntop(AF_INET6, (PAddrType)(&(((const struct sockaddr_in6*)sa)->sin6_addr)),
				tmp, sizeof(tmp));
			break;
		default:
			return "Unknown AF";
		}

		return tmp;
	}

	static std::string GetIPOfSocket(NFSocketFD fd)
	{
#if NF_PLATFORM == NF_PLATFORM_WIN
		struct sockaddr name = sockaddr();
		int namelen = sizeof(name);
		if (::getpeername(fd, (struct sockaddr*) & name, &namelen) == 0)
		{
			return getIPString(&name);
		}
#else
		struct sockaddr_in name = sockaddr_in();
		socklen_t namelen = sizeof(name);
		if (::getpeername(fd, (struct sockaddr*) & name, &namelen) == 0)
		{
			return getIPString((const struct sockaddr*) & name);
		}
#endif

		return "";
	}

	static int SocketSend(NFSocketFD fd, const char* buffer, int len)
	{
		int transnum = ::send(fd, buffer, len, 0);
		if (transnum < 0 && NF_EWOULDBLOCK == NF_ERRNO)
		{
			transnum = 0;
		}

		/*  send error if transnum < 0  */
		return transnum;
	}

	static NFSocketFD Accept(NFSocketFD listenSocket, struct sockaddr* addr, socklen_t* addrLen)
	{
		return ::accept(listenSocket, addr, addrLen);
	}

	static struct sockaddr_in6 getPeerAddr(NFSocketFD sockfd)
	{
		struct sockaddr_in6 peeraddr = sockaddr_in6();
		socklen_t addrlen = static_cast<socklen_t>(sizeof peeraddr);
		if (::getpeername(sockfd, (struct sockaddr*)(&peeraddr), &addrlen) < 0) //-V641
		{
			return peeraddr;
		}
		return peeraddr;
	}

	static struct sockaddr_in6 getLocalAddr(NFSocketFD sockfd)
	{
		struct sockaddr_in6 localaddr = sockaddr_in6();
		socklen_t addrlen = static_cast<socklen_t>(sizeof localaddr);
		if (::getsockname(sockfd, (struct sockaddr*)(&localaddr), &addrlen) < 0) //-V641
		{
			return localaddr;
		}
		return localaddr;
	}

	static bool IsSelfConnect(NFSocketFD fd)
	{
		struct sockaddr_in6 localaddr = getLocalAddr(fd);
		struct sockaddr_in6 peeraddr = getPeerAddr(fd);

		if (localaddr.sin6_family == AF_INET)
		{
			const struct sockaddr_in* laddr4 = reinterpret_cast<struct sockaddr_in*>(&localaddr); //-V641
			const struct sockaddr_in* raddr4 = reinterpret_cast<struct sockaddr_in*>(&peeraddr); //-V641
			return laddr4->sin_port == raddr4->sin_port
				&& laddr4->sin_addr.s_addr == raddr4->sin_addr.s_addr;
		}
		else if (localaddr.sin6_family == AF_INET6)
		{
#if NF_PLATFORM == NF_PLATFORM_WIN
			return localaddr.sin6_port == peeraddr.sin6_port
				&& memcmp(&localaddr.sin6_addr.u.Byte,
					&peeraddr.sin6_addr.u.Byte,
					sizeof localaddr.sin6_addr.u.Byte) == 0;
#else
			return localaddr.sin6_port == peeraddr.sin6_port
				&& memcmp(&localaddr.sin6_addr.s6_addr,
					&peeraddr.sin6_addr.s6_addr,
					sizeof localaddr.sin6_addr.s6_addr) == 0;
#endif
		}
		else
		{
			return false;
		}
	}

	static int BusAddrAton(const std::string& strAddr, uint32_t& busid)
	{
		int iRet = 0;

		iRet = inet_addr(strAddr.c_str());
		if (iRet < 0) {
			return -1;
		}

		busid = iRet;
		return iRet;
	}
};
