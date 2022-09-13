// -------------------------------------------------------------------------
//    @FileName         :    NFCKernelModule.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCKernelModule
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFCKernelModule.h"

#include <NFComm/NFPluginModule/NFIPluginManager.h>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFCRC32.h"
#include "NFComm/NFCore/NFCRC16.h"
#include "NFComm/NFCore/NFBase64.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFPluginModule/NFEventMgr.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

#define NF_GUID_POWER 100000
#define NF_EPOCH 1288834974657

#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFCore/NFIniReader.h"
#include "NFComm/NFCore/NFStringUtility.h"

NFCKernelModule::NFCKernelModule(NFIPluginManager *p) : NFIKernelModule(p) {
    mLastGuidTimeStamp = 0;
    szUniqIDFile = m_pPluginManager->GetAppName() + "_" + m_pPluginManager->GetBusName() + ".uid";
    uint64_t bWorldType = 0;
    uint32_t busId = m_pPluginManager->GetAppID();
    //uint64_t bInstID = NFServerIDUtil::GetInstID(busId);
	uint64_t worldID = NFServerIDUtil::GetWorldID(busId);
    m_iZoneId = NFServerIDUtil::GetZoneID(busId);
    m_iAdaptiveTime = (int)NFGetSecondTime() - UNIQUE_ID_START_TIME;
    m_ushSequence = 0;


    m_ucCheckSeq = UpdateCheckSeq(szUniqIDFile);
    m_ullMask = ( ( ( uint64_t ) bWorldType & WORLD_TYPE_MASK ) << 61 )     /*63-61 大区类型*/
                | ( ( ( uint64_t ) worldID & INSTANCE_MASK ) << 45 )          /*48-45 进程ID*/
                | ( ( ( uint64_t ) m_ucCheckSeq & CHECK_SEQ_MASK ) << 29 );   /*31-29 校正序号*/
}

NFCKernelModule::~NFCKernelModule() {
}

uint8_t NFCKernelModule::UpdateCheckSeq(const std::string& szCheckSeqFile)
{
    uint8_t cCheckSeq = 0;
    bool iFileExists = NFFileUtility::IsFileExist(szCheckSeqFile);
    if (iFileExists)
    {
        std::string context;
        NFFileUtility::ReadFileContent(szCheckSeqFile, context);
        cCheckSeq = NFCommon::strto<uint8_t>(context);
        cCheckSeq += 1;
        if ( cCheckSeq >= 8 )
        {
            cCheckSeq = 0;
        }
    }

    NFFileUtility::WriteFile(szCheckSeqFile, &cCheckSeq, sizeof(cCheckSeq));

    return cCheckSeq;
}

bool NFCKernelModule::Execute()
{
    return true;
}

bool NFCKernelModule::BeforeShut()
{
	return true;
}

bool NFCKernelModule::Init()
{
    if (!m_pPluginManager->IsLoadAllServer())
    {
        NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
        if (pConfig)
        {
            NFMessageMgr::Instance()->AddMessageCallBack((NF_SERVER_TYPES)pConfig->mServerType, proto_ff::NF_STS_KILL_ALL_SERVER_NTF, this, &NFCKernelModule::OnKillServerProcess);
        }
    }

    return true;
}

bool NFCKernelModule::Shut()
{
	return true;
}

bool NFCKernelModule::Finalize()
{
	return true;
}

int NFCKernelModule::Next(int iNowSec)
{
    int iNowTime = iNowSec - UNIQUE_ID_START_TIME;

    if ( iNowTime <= m_iAdaptiveTime )
    {
        m_ushSequence++;

        if( m_ushSequence >= ONE_SECOND_SEQ_MASK )
        {
            m_iAdaptiveTime++;
            m_ushSequence = 0;
        }
    }
    else
    {
        m_iAdaptiveTime = iNowTime;
        m_ushSequence = 0;
    }

    return 0;
}

uint64_t NFCKernelModule::Get64UUID()
{
    Next( NFGetSecondTime() );

    uint64_t ullUniqueID = ( m_ullMask
                             | ( ( ( uint64_t )m_iZoneId  & ZONEID_MASK ) << 53 )                               /*区服ID*/
                             | ( ( ( uint64_t )m_ushSequence & ONE_SECOND_SEQ_MASK ) << 32 )    /*独立序号*/
                             | ( ( uint64_t )m_iAdaptiveTime & ADAPTIVE_TIME_MASK )             /*系统时间*/
    );

    NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "gen uuid::{}", ullUniqueID);

    return ullUniqueID;
}

uint64_t NFCKernelModule::Get32UUID()
{
	uint64_t time = NFGetSecondTime();
	if (mLastGuidTimeStamp == 0)
	{
		mLastGuidTimeStamp = time;
	}

	mLastGuidTimeStamp = mLastGuidTimeStamp + 1;
	return mLastGuidTimeStamp;
}

uint64_t NFCKernelModule::GetUUID()
{
	return Get64UUID();
}

std::string NFCKernelModule::GetMD5(const std::string& str)
{
	return NFMD5::md5str(str);
}

uint32_t NFCKernelModule::GetCRC32(const std::string& s)
{
	return NFCRC32::Sum(s);
}

uint16_t NFCKernelModule::GetCRC16(const std::string& s)
{
	return NFCRC16::Sum(s);
}

std::string NFCKernelModule::Base64Encode(const std::string& s)
{
	return NFBase64::Encode(s);
}

std::string NFCKernelModule::Base64Decode(const std::string& s)
{
	return NFBase64::Decode(s);
}

void NFCKernelModule::OnTimer(uint32_t nTimerID)
{

}

int NFCKernelModule::OnKillServerProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::NFEventNoneData xMsg;
    NFEventMgr::Instance()->FireExecute(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, xMsg);
    return 0;
}