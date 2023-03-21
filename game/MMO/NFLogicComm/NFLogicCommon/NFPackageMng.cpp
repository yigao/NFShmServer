// -------------------------------------------------------------------------
//    @FileName         :    NFPackageMng.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/9/30
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageMng
//
// -------------------------------------------------------------------------

#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFPackageMng.h"
#include "NFLogicCommon/NFPackageConfig.h"

NFPackageMng::NFPackageMng()
{

}

NFPackageMng::~NFPackageMng()
{
}

int NFPackageMng::CheckPkgRate(NFPackageConfig* pConfig, int iMsgID, int &count, int &interval)
{
    CHECK_EXPR_ASSERT(pConfig, -1, "pConfig == NULL");
    CHECK_EXPR((iMsgID > 0 && iMsgID < CLIENT_MAX_CMD_ID_VALUE), CMDID_OUT_MAX_VALUE, "invalid msg:{}", iMsgID);

    interval = 0;
    count = 0;
    int64_t ullTimeMs = NFTime::Now().UnixMSec();

    int iMsgControlInterval = DEFAULT_MSG_CONTROL_INTERVAL;
    int iMsgMinInterval = DEFAULT_MSG_MIN_INTERVAL;
    int iMaxIntervalCount = DEFAULT_MSG_INTERVAL_LIMIT_COUNT;

    auto pPacket = pConfig->GetPacketConfig(iMsgID);
    if (pPacket)
    {
        iMsgControlInterval = pPacket->control_time();
        iMsgMinInterval = pPacket->min_interval();
        iMaxIntervalCount = pPacket->upper_limit();
    }

    if (m_msgInputInfo[iMsgID].m_beginTime == 0)
    {
        m_msgInputInfo[iMsgID].m_beginTime = ullTimeMs;
        m_msgInputInfo[iMsgID].m_lastTime = ullTimeMs;
        m_msgInputInfo[iMsgID].m_count = 1;
    } else
    {
        if (ullTimeMs - m_msgInputInfo[iMsgID].m_lastTime < iMsgMinInterval)
        {
            interval = ullTimeMs - m_msgInputInfo[iMsgID].m_lastTime;
            return PKG_RATE_UPPER_LIMIT;
        }

        if (ullTimeMs - m_msgInputInfo[iMsgID].m_beginTime > iMsgControlInterval)
        {
            m_msgInputInfo[iMsgID].m_beginTime = ullTimeMs;
            m_msgInputInfo[iMsgID].m_count = 0;
        }

        m_msgInputInfo[iMsgID].m_lastTime = ullTimeMs;
        ++m_msgInputInfo[iMsgID].m_count;
        if (m_msgInputInfo[iMsgID].m_count > iMaxIntervalCount)
        {
            interval = ullTimeMs - m_msgInputInfo[iMsgID].m_beginTime;
            count = m_msgInputInfo[iMsgID].m_count;
            return MSG_PKG_RATE_UPPER_LIMIT;
        }
    }

    return 0;
}

int NFPackageMng::AddPkgStatistic(int iMsgID, uint64_t roleID, uint64_t linkId)
{
    CHECK_EXPR(iMsgID > 0 && iMsgID < CLIENT_MAX_CMD_ID_VALUE, CMDID_OUT_MAX_VALUE, "invalid msg:{}", iMsgID);

    int64_t ullTimeMs = NFTime::Now().UnixMSec();
    if (m_msgStatisticInfo[iMsgID].m_lastMinBeginTime == 0)
    {
        m_msgStatisticInfo[iMsgID].m_lastMinBeginTime = ullTimeMs;
        m_msgStatisticInfo[iMsgID].m_lastMaxBeginTime = ullTimeMs;
        m_msgStatisticInfo[iMsgID].m_lastMinCount = 1;
        m_msgStatisticInfo[iMsgID].m_lastMaxCount = 1;
    } else
    {
        bool isLog = false;

        if (ullTimeMs - m_msgStatisticInfo[iMsgID].m_lastMinBeginTime > DEFAULT_MSG_STATISTIC_MIN_INTEVAL)
        {
            m_msgStatisticInfo[iMsgID].m_lastMinCount = 1;
            m_msgStatisticInfo[iMsgID].m_lastMinBeginTime = ullTimeMs;
        } else
        {
            m_msgStatisticInfo[iMsgID].m_lastMinCount += 1;
        }

        if (m_msgStatisticInfo[iMsgID].m_lastMinCount > m_msgStatisticInfo[iMsgID].m_minCount)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, roleID, "msg statistic, msgId:{}, minCount:{}, lastMinCount:{}", iMsgID,
                       m_msgStatisticInfo[iMsgID].m_minCount, m_msgStatisticInfo[iMsgID].m_lastMinCount);
            m_msgStatisticInfo[iMsgID].m_minCount = m_msgStatisticInfo[iMsgID].m_lastMinCount;
            isLog = true;
        }

        if (ullTimeMs - m_msgStatisticInfo[iMsgID].m_lastMaxBeginTime > DEFAULT_MSG_STATISTIC_MAX_INTEVAL)
        {
            m_msgStatisticInfo[iMsgID].m_lastMaxCount = 1;
            m_msgStatisticInfo[iMsgID].m_lastMaxBeginTime = ullTimeMs;
        } else
        {
            m_msgStatisticInfo[iMsgID].m_lastMaxCount += 1;
        }

        if (m_msgStatisticInfo[iMsgID].m_lastMaxCount > m_msgStatisticInfo[iMsgID].m_maxCount)
        {
            m_msgStatisticInfo[iMsgID].m_maxCount = m_msgStatisticInfo[iMsgID].m_lastMaxCount;
            isLog = true;
        }

        if (isLog)
        {
            //S_STATIC_MANAGER->AddSessionMsgStatistic(iMsgID, m_msgStatisticInfo[iMsgID].minCount,
            //                                         m_msgStatisticInfo[iMsgID].maxCount, roleID, uin);
        }
    }

    return 0;
}

