// -------------------------------------------------------------------------
//    @FileName         :    NFPackageMng.h
//    @Author           :    gaoyi
//    @Date             :    2022/9/30
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageMng
//
// -------------------------------------------------------------------------

#pragma once


#include "NFServerLogicMessage/ServerConfig.pb.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFServerLogicMessage/ClientServerCmd.pb.h"
#include "NFPackageConfig.h"


enum PKG_RATE_ERROR
{
    PKG_RATE_UPPER_LIMIT = 1,
    MSG_PKG_RATE_UPPER_LIMIT = 2,
    CMDID_OUT_MAX_VALUE = 3,
    CMDID_NOT_MONITOR = 4,
};

#define DEFAULT_MSG_CONTROL_INTERVAL 10000
#define DEFAULT_MSG_MIN_INTERVAL 0
#define DEFAULT_MSG_INTERVAL_LIMIT_COUNT 100

#define DEFAULT_MSG_STATISTIC_MIN_INTEVAL 10000
#define DEFAULT_MSG_STATISTIC_MAX_INTEVAL 60000

class NFMsgInputInfo
{
public:
    NFMsgInputInfo()
    {
        m_beginTime = 0;
        m_lastTime = 0;
        m_count = 0;
    }

    int64_t m_beginTime;
    int64_t m_lastTime;
    uint16_t m_count;
};

class NFMsgInputStatistic
{
public:
    NFMsgInputStatistic()
    {
        m_lastMinBeginTime = 0;
        m_lastMaxBeginTime = 0;
        m_lastMinCount = 0;
        m_lastMaxCount = 0;
        m_minCount = 0;
        m_maxCount = 0;
    }

    int64_t m_lastMinBeginTime;
    int64_t m_lastMaxBeginTime;
    uint32_t m_lastMinCount;
    uint32_t m_lastMaxCount;
    uint32_t m_minCount;
    uint32_t m_maxCount;
};

class NFPackageConfig;
class NFPackageMng
{
public:
    NFPackageMng();

    virtual ~NFPackageMng();

    int CheckPkgRate(NFPackageConfig* pConfig, int iMsgID, int &count, int &interval);

    int AddPkgStatistic(int iMsgID, uint64_t roleID, uint64_t linkId);

private:
    NFMsgInputInfo m_msgInputInfo[CLIENT_MAX_CMD_ID_VALUE];
    NFMsgInputStatistic m_msgStatisticInfo[CLIENT_MAX_CMD_ID_VALUE];
};