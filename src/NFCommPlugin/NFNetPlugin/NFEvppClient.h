// -------------------------------------------------------------------------
//    @FileName         :    NFEvppClient.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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

class NFEvppObject;

class NFEvppClient : public NFIConnection
{
public:
	NFEvppClient(NFIPluginManager* p, NF_SERVER_TYPES serverType, const NFMessageFlag& flag):NFIConnection(p, serverType, flag)
	{
		m_eventLoop = NULL;
		m_tcpClient = NULL;
	}

	virtual bool Init() override;

	virtual bool Shut() override;

	virtual bool Finalize() override;
private:
	evpp::EventLoopThread* m_eventLoop;
	evpp::TCPClient* m_tcpClient;
};
