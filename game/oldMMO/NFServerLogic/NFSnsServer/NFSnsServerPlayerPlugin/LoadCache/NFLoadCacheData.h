// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheData.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheData
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLoadCacheDataInfo.h"
#include "NFComm/NFShmCore/NFShmStaticList.hpp"

#define SNS_GET_ROLE_SIMPLE_INFO_QUEUE 20000
#define SNS_GETTING_ROLE_SIZE 300
#define SNS_CALLBACK_TRANS_RUN_TIMES 20

class NFLoadCacheData
{
public:
    NFLoadCacheData();

    virtual ~NFLoadCacheData();

    int CreateInit();

    int ResumeInit();

    NFLoadCacheData& operator=(const NFLoadCacheData& data)
    {
        if (this == &data)
            return *this;

        m_roleId = data.m_roleId;
        for(auto iter = data.m_roleInfo.Begin(); iter != data.m_roleInfo.End(); iter++)
        {
            m_roleInfo.PushBack(*iter);
        }
        return *this;
    }
public:
    /**
     * @brief
     * @param rid
     * @param rtrans
     * @param rtime
     * @return
     */
    int AddTrans(uint32_t transId, uint64_t time);
public:
    uint64_t m_roleId;
    NFShmStaticList<NFLoadCacheDataInfo, SNS_CALLBACK_TRANS_RUN_TIMES> m_roleInfo;
};