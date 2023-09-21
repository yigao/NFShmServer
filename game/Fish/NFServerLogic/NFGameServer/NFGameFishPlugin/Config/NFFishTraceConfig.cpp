// -------------------------------------------------------------------------
//    @FileName         :    NFFishTraceMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishTraceMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFFishTraceConfig.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFFishDefine.h"
#include <fstream>

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTraceConfig, EOT_FISH_TRACE_MGR_2004_ID, NFShmObj)


NFFishTraceConfig::NFFishTraceConfig() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFFishTraceConfig::~NFFishTraceConfig() {

}

int NFFishTraceConfig::CreateInit()
{
    return 0;
}

int NFFishTraceConfig::ResumeInit()
{
    return 0;
}

int NFFishTraceConfig::GetFileContainMD5(const std::string& strFileName, std::string& fileMd5)
{
    bool exist = NFFileUtility::IsFileExist(strFileName);
    CHECK_EXPR(exist, -1, "strFileName:{} not exist", strFileName);

    fileMd5 = NFMD5::md5file(strFileName);
    return 0;
}

int NFFishTraceConfig::LoadConfig(uint32_t roomId)
{
    m_roomId = roomId;
    std::string path = m_pObjPluginManager->GetConfigPath() + "/Config" + NFCommon::tostr(GAME_ID_FISH_HAIWANG_2004) + "_" + NFCommon::tostr(m_roomId);
	std::string strTracePack = NFFileUtility::NormalizePath(path) + "FishTrace/traces.pack";
    std::string fileMd5;
    int iRet = GetFileContainMD5(strTracePack, fileMd5);
    NF_ASSERT(iRet == 0);
    if (fileMd5 != m_szMD5.ToString())
    {
        m_szMD5 = fileMd5;
        ReadTracePack(strTracePack);
    }

	return 0;
}

bool NFFishTraceConfig::ReadTracePack(const std::string& strPackFile)
{
	std::ifstream tracdPack;
	tracdPack.open(strPackFile, std::ios::binary);

	if (tracdPack)
	{
		//tracdPack.seekg(0, std::ios::end);
		//int iFileLen = tracdPack.tellg();
		//tracdPack.seekg(0, std::ios::beg);
		//int iLeftLen = iFileLen;

		bool ret = false;
		do
		{
			CHMTraceBin traceBin;
			ret = ReadTraceBin(tracdPack, traceBin);
			if (ret)
			{
                if (m_FishTraceMap.full())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_FishTraceMap.Insert Failed, m_FishTraceMap Space Not Enough!");
                    NFSLEEP(1000);
                    exit(0);
                }

				m_FishTraceMap.emplace(traceBin.m_uTraceId, traceBin);
			}

		} while (ret);

		uint32_t maxPoints = 0;
		for(auto iter = m_FishTraceMap.begin(); iter != m_FishTraceMap.end(); iter++)
        {
		    auto pData = &iter->second;
		    if (pData)
            {
		        if ((uint32_t)pData->m_vecPoints.size() >= maxPoints)
                {
		            maxPoints = pData->m_vecPoints.size();
                }
            }
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "ReadTracePack() traceCount = {}, maxPoints:{}", m_FishTraceMap.size(), maxPoints);

		return true;
	}
	else
	{
		return false;
	}
}

bool NFFishTraceConfig::ReadTraceBin(std::ifstream& tracdPackFile, CHMTraceBin& traceBin)
{
	TRACEHEADER TraceHeader;
	tracdPackFile.read((char*)&TraceHeader, sizeof(TraceHeader));
	int len = tracdPackFile.gcount();
	if (len != sizeof(TraceHeader))
	{
		return false;
	}

	traceBin.m_uTraceId = TraceHeader.uTraceId;
	traceBin.m_sTime = TraceHeader.sTime;
	traceBin.m_uType = TraceHeader.byType;
	traceBin.m_ptCenter.m_iPosX = TraceHeader.iCenterX;
	traceBin.m_ptCenter.m_iPosY = TraceHeader.iCenterY;

	//NFLogTrace(NF_LOG_SUB_GAME_PLUGIN, 0, "NFCFishTraceModule::ReadTraceBin() m_uTraceId = {} , sPointCount = {}", traceBin.m_uTraceId, TraceHeader.sPointCount);


	int iPointCount = TraceHeader.sPointCount;
	int iPointLen = GetBinLen(TraceHeader.byType);
	for (int i = 0; i < iPointCount; i++)
	{
		HMPOINT point;
		tracdPackFile.read((char*)&point, iPointLen);
		len = tracdPackFile.gcount();

		if (len != iPointLen)
		{
			return false;
		}

		CHMPoint pt;
		pt.m_iPosX = point.iPosX / 10000;
		pt.m_iPosY = point.iPosY / 10000;
		pt.m_iDirPosX = point.iDirX / 10000;
		pt.m_iDirPosY = point.iDirY / 10000;

		traceBin.AddPoint(pt);
	}

	return true;
}

int NFFishTraceConfig::GetBinLen(int iType)
{
	return iType == 1 ? 16 : 8;
}

CHMPoint NFFishTraceConfig::GetPointByIndex(unsigned int uTraceId, unsigned int uIndex)
{
	CHMTraceBin* pBin = GetTraceBin(uTraceId);
	if (pBin)
	{
		return pBin->GetPointByIndex(uIndex);
	}
	else
	{
		return CHMPoint();
	}
}

int NFFishTraceConfig::GetTracePointCount(unsigned int uTraceId)
{
	CHMTraceBin* pBin = GetTraceBin(uTraceId);
	if (pBin)
	{
		return pBin->GetPointCount();
	}
	else
	{
		return -1;
	}
}

CHMTraceBin *NFFishTraceConfig::GetTraceBin(uint32_t id)
{
    auto iter = m_FishTraceMap.find(id);
    if (iter != m_FishTraceMap.end())
    {
        return &iter->second;
    }

    return nullptr;
}

CHMTraceBin *NFFishTraceConfig::InsertTraceBin(uint32_t id)
{
    if (!m_FishTraceMap.full())
    {
        return &m_FishTraceMap[id];
    }
    return nullptr;
}
