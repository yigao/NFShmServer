#ifdef _MSC_VER
#include <WinSock2.h>
#include <winsock.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#endif

#include "NFCMysqlDriver.h"
#include "NFCMysqlDriverManager.h"
#include "NFComm/NFPluginModule/NFCheck.h"

NFCMysqlDriverManager::NFCMysqlDriverManager(): mnLastCheckTime(0)
{
}

NFCMysqlDriverManager::~NFCMysqlDriverManager()
{
	for (NFCMysqlDriver* pMysqlDriver = mvMysql.First(); nullptr != pMysqlDriver; pMysqlDriver = mvMysql.Next())
	{
		NF_SAFE_DELETE(pMysqlDriver);
		pMysqlDriver = nullptr;
	}
	mvMysql.ClearAll();
	for (NFCMysqlDriver* pMysqlDriver = mvInvalidMsyql.First(); nullptr != pMysqlDriver; pMysqlDriver = mvInvalidMsyql.
	     Next())
	{
		NF_SAFE_DELETE(pMysqlDriver);
		pMysqlDriver = nullptr;
	}
	mvInvalidMsyql.ClearAll();
}

NFCMysqlDriver* NFCMysqlDriverManager::GetMysqlDriver(const std::string& serverID)
{
	return mvMysql.GetElement(serverID);
}

void NFCMysqlDriverManager::CheckMysql()
{
    if (NFGetSecondTime() - mnLastCheckTime <= 10) return;
    mnLastCheckTime = NFGetSecondTime();

	std::string nServerID;
	std::vector<std::string> xIntVec;
	for (NFCMysqlDriver* pMysqlDriver = mvMysql.First(nServerID); pMysqlDriver != nullptr; pMysqlDriver = mvMysql.
	     Next(nServerID))
	{
		if (!pMysqlDriver->Enable())
		{
			xIntVec.push_back(nServerID);
			mvInvalidMsyql.AddElement(nServerID, pMysqlDriver);
		}
	}

	for (int i = 0; i < (int)xIntVec.size(); ++i)
	{
		mvMysql.RemoveElement(xIntVec[i]);
	}
	//////////////////////////////////////////////////////////////////////////
	xIntVec.clear();
	nServerID.clear();

	for (NFCMysqlDriver* pMysqlDriver = mvInvalidMsyql.First(nServerID); pMysqlDriver != nullptr; pMysqlDriver =
	     mvInvalidMsyql.Next(nServerID))
	{
		//if (!pMysqlDriver->Enable() && pMysqlDriver->CanReconnect())
		if (!pMysqlDriver->Enable())
		{
			pMysqlDriver->Reconnect();
			if (pMysqlDriver->Enable())
			{
				xIntVec.push_back(nServerID);
				mvMysql.AddElement(nServerID, pMysqlDriver);
			}
		}
	}

	for (int i = 0; i < (int)xIntVec.size(); ++i)
	{
		mvInvalidMsyql.RemoveElement(xIntVec[i]);
	}
}

int NFCMysqlDriverManager::AddMysqlServer(const std::string& serverID, const std::string& strIP, const int nPort,
                                           const std::string strDBName, const std::string strDBUser,
                                           const std::string strDBPwd, const int nRconnectTime/* = 10*/,
                                           const int nRconneCount/* = -1*/)
{
    NFCMysqlDriver* pMysqlDriver = mvMysql.GetElement(serverID);
	CHECK_EXPR(pMysqlDriver == NULL, 0, "pMysqlDriver == NULL, nServerID:{} exist", serverID);

    NFCMysqlDriver* pInvalidRedisDriver = mvInvalidMsyql.GetElement(serverID);
	CHECK_EXPR(pInvalidRedisDriver == NULL, -1, "pInvalidRedisDriver == NULL, nServerID:{} exist", serverID);


	pMysqlDriver = NF_NEW NFCMysqlDriver(nRconnectTime, nRconneCount);
	int iRet = pMysqlDriver->Connect(strDBName, strIP, nPort, strDBUser, strDBPwd);
    if (iRet == 0) {
        mvMysql.AddElement(serverID, pMysqlDriver);
    } else {
        mvInvalidMsyql.AddElement(serverID, pMysqlDriver);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Connect Mysql Failed!");
        return -1;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0,
              "Connecy Mysql Success:nServerID:{}, strIP:{}, nPort{}, strDBName:{}, strDBUser:{}, strDBPwd:{}",
			serverID, strIP, nPort, strDBName, strDBUser, strDBPwd);

    return 0;
}
