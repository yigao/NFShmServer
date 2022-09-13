// -------------------------------------------------------------------------
//    @FileName         :    NFEvppServer.h
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

#include "NFIConnection.h"


class NFEvppServer : public NFIConnection
{
public:
	NFEvppServer(NFIPluginManager* p, NF_SERVER_TYPES serverType, const NFMessageFlag& flag):NFIConnection(p, serverType, flag)
	{
		m_eventLoop = NULL;
		m_tcpServer = NULL;
	}

	virtual bool Init() override;

	virtual bool Shut() override;

	virtual bool Finalize() override;
private:
	evpp::EventLoopThread* m_eventLoop;
	evpp::TCPServer* m_tcpServer;

	/**
	* @brief 退出的时候用来确认
	*/
	atomic_bool mExit;
};

