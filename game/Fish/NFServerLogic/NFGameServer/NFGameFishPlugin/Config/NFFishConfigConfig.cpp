// -------------------------------------------------------------------------
//    @FileName         :    NFFishConfigDesc.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishConfigDesc.cpp
//
// -------------------------------------------------------------------------

#include "NFFishConfigConfig.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFLogicCommon/NFFishDefine.h"
#include <fstream>

IMPLEMENT_IDCREATE_WITHTYPE(NFFishConfigConfig, EOT_FISH_CONFIG_MGR_ID, NFShmObj)

NFFishConfigConfig::NFFishConfigConfig()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFFishConfigConfig::~NFFishConfigConfig()
{

}

int NFFishConfigConfig::CreateInit()
{
    m_roomId = 0;
    return 0;
}

int NFFishConfigConfig::ResumeInit()
{
    return 0;
}

int NFFishConfigConfig::LoadConfig(uint32_t roomId)
{
    m_roomId = roomId;
    std::string path = m_pObjPluginManager->GetConfigPath() + "/Config" + NFCommon::tostr(GAME_ID_FISH_HAIWANG_2004) + "_" + NFCommon::tostr(m_roomId);
	std::string strPath = NFFileUtility::NormalizePath(path) + "FishKind/FishConfig.csv";
    std::string fileMd5;
    int iRet = GetFileContainMD5(strPath, fileMd5);
    NF_ASSERT(iRet == 0);
    if (fileMd5 != m_szMD5.ToString())
    {
        m_szMD5 = fileMd5;
        LoadConfig(strPath);
    }

	return 0;
}

int NFFishConfigConfig::GetFileContainMD5(const std::string& strFileName, std::string& fileMd5)
{
    bool exist = NFFileUtility::IsFileExist(strFileName);
    CHECK_EXPR(exist, -1, "strFileName:{} not exist", strFileName);

    fileMd5 = NFMD5::md5file(strFileName);
    return 0;
}

int NFFishConfigConfig::LoadConfig(const std::string& strFishKindCfgFile)
{
    m_vectFishConfig.clear();
	int iRet = LoadFishConfigCSV(strFishKindCfgFile);
	CHECK_EXPR(iRet == 0, -1, "CFishKindCfgMgr::Init() init csv cfg failed.");
	return 0;
}

int NFFishConfigConfig::LoadFishConfigCSV(const std::string& strFishKindCfgFile)
{
	std::vector<std::vector<std::string> > values;

	int iRet = ReadCfg(strFishKindCfgFile, values);
	CHECK_EXPR(iRet == 0, -1, "NFCFishConfigModule::LoadFishConfigCSV() read csv config failed.");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFCFishConfigModule::LoadFishConfigCSV() strFishKindCfgFile: {}", strFishKindCfgFile);

	std::map<std::string, std::vector<std::string> > mapColData = ClassifyValues(values);
	std::vector<std::string> vecIds = GetColVecByColName(mapColData, "id");

	std::vector<std::string>::iterator iter = vecIds.begin();
	for (int iIndex = 0; iter != vecIds.end(); iter++, iIndex++)
	{
		std::string strId = *iter;

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFCFishConfigModule::LoadFishConfigCSV() ------------------------------------");
	   // NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFCFishConfigModule::LoadFishConfigCSV() strId = {}", strId.c_str());

       if (m_vectFishConfig.full())
       {
           NFLogError(NF_LOG_SYSTEMLOG, 0, "m_vectFishConfig full");
           NFSLEEP(1000);
           exit(0);
       }

        m_vectFishConfig.push_back();

		FishConfig* pCfg = &m_vectFishConfig.back();

		pCfg->btFishKindId = atoi(strId.c_str());
		//pCfg->strFishName= GetValue(mapColData, "fishName", iIndex);
		pCfg->btFishType   = atoi(GetValue(mapColData, "fishRuleType", iIndex).c_str());
		pCfg->nRatioMin    = atoi(GetValue(mapColData, "ratioMin", iIndex).c_str());
		pCfg->nRatioMax    = atoi(GetValue(mapColData, "ratioMax", iIndex).c_str());
		pCfg->nRatioDeath  = atoi(GetValue(mapColData, "ratioDeath", iIndex).c_str());
		pCfg->nDoubleAwardMinRatio = atoi(GetValue(mapColData, "doubleAwardMinRatio", iIndex).c_str());
		pCfg->nChildFishCount = atoi(GetValue(mapColData, "childFishCount", iIndex).c_str());

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFCFishConfigModule::LoadFishConfigCSV() pCfg->nRatioMax  = {} , pCfg->nChildFishCount = {}", pCfg->nRatioMax, pCfg->nChildFishCount);

		std::string strChildFishIds_1 = GetValue(mapColData, "childFishIds_1", iIndex);
		std::string strChildFishIds_2 = GetValue(mapColData, "childFishIds_2", iIndex);
		std::string strChildFishIds_3 = GetValue(mapColData, "childFishIds_3", iIndex);
		std::string strChildFishIds_4 = GetValue(mapColData, "childFishIds_4", iIndex);
		std::string strChildFishIds_5 = GetValue(mapColData, "childFishIds_5", iIndex);
		std::string strChildFishIds_6 = GetValue(mapColData, "childFishIds_6", iIndex);
		std::vector<uint8_t> vec1;
		std::vector<uint8_t> vec2;
		std::vector<uint8_t> vec3;
		std::vector<uint8_t> vec4;
		std::vector<uint8_t> vec5;
		std::vector<uint8_t> vec6;
		NFStringUtility::SplitStringToVectorInt(strChildFishIds_1, ":", vec1);
		NFStringUtility::SplitStringToVectorInt(strChildFishIds_2, ":", vec2);
		NFStringUtility::SplitStringToVectorInt(strChildFishIds_3, ":", vec3);
		NFStringUtility::SplitStringToVectorInt(strChildFishIds_4, ":", vec4);
		NFStringUtility::SplitStringToVectorInt(strChildFishIds_5, ":", vec5);
		NFStringUtility::SplitStringToVectorInt(strChildFishIds_6, ":", vec6);

        if (pCfg->vecVecChildFishes.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " vecVecChildFishes full ! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pCfg->vecVecChildFishes.push_back();
		auto pChildFish1 = &pCfg->vecVecChildFishes.back();
        if (pChildFish1->full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " pChildFish1 full! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pChildFish1->insert(pChildFish1->end(), vec1.begin(), vec1.end());

        if (pCfg->vecVecChildFishes.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " vecVecChildFishes full ! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pCfg->vecVecChildFishes.push_back();
		auto pChildFish2 = &pCfg->vecVecChildFishes.back();
        if (pChildFish2->full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " pChildFish2 full! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pChildFish2->insert(pChildFish2->end(), vec2.begin(), vec2.end());

        if (pCfg->vecVecChildFishes.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " vecVecChildFishes full ! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pCfg->vecVecChildFishes.push_back();
		auto pChildFish3 = &pCfg->vecVecChildFishes.back();
        if (pChildFish3->full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " pChildFish3 full! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pChildFish3->insert(pChildFish3->end(), vec3.begin(), vec3.end());

        if (pCfg->vecVecChildFishes.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " vecVecChildFishes full ! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pCfg->vecVecChildFishes.push_back();
		auto pChildFish4 = &pCfg->vecVecChildFishes.back();
        if (pChildFish4->full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " pChildFish4 full! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pChildFish4->insert(pChildFish4->end(), vec4.begin(), vec4.end());

        if (pCfg->vecVecChildFishes.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " vecVecChildFishes full ! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pCfg->vecVecChildFishes.push_back();
        auto pChildFish5 = &pCfg->vecVecChildFishes.back();
        if (pChildFish5->full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " pChildFish5 full! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pChildFish5->insert(pChildFish5->end(), vec5.begin(), vec5.end());

        if (pCfg->vecVecChildFishes.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " vecVecChildFishes full ! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pCfg->vecVecChildFishes.push_back();
        auto pChildFish6 = &pCfg->vecVecChildFishes.back();
        if (pChildFish5->full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, " pChildFish6 full! Space Not Enough");
            NFSLEEP(1000);
            exit(0);
        }

        pChildFish6->insert(pChildFish6->end(), vec6.begin(), vec6.end());

		pCfg->nDamageRadius = atoi(GetValue(mapColData, "damageRadius", iIndex).c_str());

		std::string strDamageFishIds = GetValue(mapColData, "damageFishIds", iIndex);
		std::vector<uint8_t> tmpVecDamageFishIds;
		NFStringUtility::SplitStringToVectorInt(strDamageFishIds, ":", tmpVecDamageFishIds);
		pCfg->vectDamageFishIds.insert(pCfg->vectDamageFishIds.end(), tmpVecDamageFishIds.begin(), tmpVecDamageFishIds.end());

		pCfg->nFishOutTipsID = atoi(GetValue(mapColData, "fishOutTipsID", iIndex).c_str());


		//cfg.nMiniGameId        = atoi(GetValue(mapColData, "minigameid", iIndex).c_str());

		//////////////////////////////////////////////////////////////////////////

// 		std::string strSubFishKindRange = "";
// 		for (int i = 0; i < pCfg->vecVecChildFishes.GetSize(); i++)
// 		{
// 			for (int j = 0; j < (int)pCfg->vecVecChildFishes.GetSize(); j++)
// 			{
// 				char buf[32] = { 0 };
// 				sprintf(buf, "%d", pCfg->vecVecChildFishes[i][j]);
// 				//itoa(*iter, buf, 10);
// 				strSubFishKindRange += buf;
// 				strSubFishKindRange += ":";
// 			}
// 
// 			strSubFishKindRange += "|";
// 		}
// 
// 		std::string strLogDamageFishIds = "";
// 		for (int i = 0; i < (int)pCfg->vectDamageFishIds.GetSize(); i++)
// 		{
// 			char buf[32] = { 0 };
// 			sprintf(buf, "%d", pCfg->vectDamageFishIds[i]);
// 			//itoa(*iter, buf, 10);
// 			strLogDamageFishIds += buf;
// 			strLogDamageFishIds += ":";
// 		}

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadFishConfigCSV() FishConfig: {}|{}|{}|{}|{}|{}|{}", pCfg->btFishKindId, pCfg->strFishName,
		//	pCfg->btFishType, pCfg->nRatioMin, pCfg->nRatioMax, pCfg->nDoubleAwardMinRatio, pCfg->nChildFishCount);
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadFishConfigCSV() FishConfig: {}", strSubFishKindRange);
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadFishConfigCSV() FishConfig: {}|{}", pCfg->nDamageRadius, strLogDamageFishIds);
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadFishConfigCSV() FishConfig: nFishOutTipsID = {}", pCfg->nFishOutTipsID);
	
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadFishConfigCSV() pCfg->nRatioDeath = {}", pCfg->nRatioDeath);

}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
	return 0;
}


std::map<std::string, std::vector<std::string> > NFFishConfigConfig::ClassifyValues(std::vector<std::vector<std::string> >& values)
{
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CFishKindCfgMgr::ClassifyValues()");

	std::map<std::string, std::vector<std::string> > mapColData;
	std::vector<std::string>& vecColNameRow = values[1];//the id EnglishName/keyword row

	for (size_t col = 0; col < vecColNameRow.size(); col++)
	{
		std::string strColName = vecColNameRow[col];

		std::string strLog = "CFishKindCfgMgr::ClassifyValues() " + strColName + ": ";

		//from the first data row -- the 4th row
		for (size_t row = 3; row < values.size(); row++)
		{
			if (row < values.size())
			{
				std::vector<std::string>& vecRow = values[row];

				if (col < vecRow.size())
				{
					std::string strValue = vecRow[col];

					mapColData[strColName].push_back(strValue);

					strLog += strValue + "|";
				}

			}

		}

		//NFLogInfo(NF_LOG_SYSTEMLOG, 0, strLog.c_str());
	}

	return mapColData;
}

std::string NFFishConfigConfig::GetValue(std::map<std::string, std::vector<std::string> >& mapCols, std::string strColName, int iIndex)
{
	std::map<std::string, std::vector<std::string> >::iterator iter = mapCols.find(strColName);

	if (iter != mapCols.end())
	{
		if (iIndex >= 0 && iIndex < (int)iter->second.size())
		{
			return iter->second[iIndex];
		}
	}

	return "";
}

std::vector<std::string> NFFishConfigConfig::GetColVecByColName(std::map<std::string, std::vector<std::string> >& mapCols, std::string strColName)
{
	std::map<std::string, std::vector<std::string> >::iterator iter = mapCols.find(strColName);
	if (iter != mapCols.end())
	{
		return iter->second;
	}
	else
	{
		return std::vector<std::string>();
	}
}

int NFFishConfigConfig::ReadCfg(const std::string & strFile, std::vector<std::vector<std::string> > & values)
{
	std::ifstream fin;

	fin.open(strFile.c_str());
	if (!fin)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishKindCSV::ReadCfg() open file {} failed.", strFile.c_str());
		return -1;
	}

	std::string line;
	while (getline(fin, line))
	{
		//NFLogInfo(NF_LOG_SYSTEMLOG, 0, "csv line : {}", line);

		NFStringUtility::Trim(line);

		if (line.find(',') == std::string::npos)
		{
			continue;
		}

		std::istringstream sin(line);
		std::vector<std::string> fields;

		std::string field;
		while (std::getline(sin, field, ','))
		{
			NFStringUtility::Trim(field);

			fields.push_back(field);
		}

		values.push_back(fields);
	}

	return 0;
}

FishConfig* NFFishConfigConfig::GetFishBaseInfo(char btFishKindId)
{
	for (int i = 0; i < (int)m_vectFishConfig.size(); i++)
	{
		if (m_vectFishConfig[i].btFishKindId == btFishKindId)
		{
			return &m_vectFishConfig[i];
		}

	}

	return NULL;
}

int NFFishConfigConfig::GetFishKindMaxId() {
	int count = m_vectFishConfig.size();
	if (count > 0)
	{
		int iFishKind = m_vectFishConfig[count - 1].btFishKindId;
		return iFishKind;
	}
	else {
		return 0;
	}
}

