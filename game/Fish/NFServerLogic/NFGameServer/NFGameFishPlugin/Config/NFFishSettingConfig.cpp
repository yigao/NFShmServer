#include "NFFishSettingConfig.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFIniReader.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include <stdlib.h>
#include <stdint.h>
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFCommon.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFLogicCommon/NFFishDefine.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishSettingConfig, EOT_GAME_FISH_SETTING_DESC_ID, NFShmObj)

NFFishSettingConfig::NFFishSettingConfig()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFFishSettingConfig::~NFFishSettingConfig()
{

}


int NFFishSettingConfig::CreateInit()
{
    m_roomId = 0;
    m_iDNTGKilledGroup = 0;
    m_iDNTGGroupInterval = 0;
    m_iOneCannonKilled = 0;
    m_iDoubleCannonEnable = 0;
    m_iDoubleCannonRatio = 0;
    m_mapShootTraces.CreateInit();
    m_mapWayBills.CreateInit();
    return 0;
}

int NFFishSettingConfig::ResumeInit()
{
    return 0;
}

int NFFishSettingConfig::LoadConfig(uint32_t roomId)
{
    m_roomId = roomId;
    std::string strFishSettingPath = NFFileUtility::NormalizePath(
            m_pObjPluginManager->GetConfigPath() + "/Config" + NFCommon::tostr(GAME_ID_FISH_HAIWANG_2004) + "_" + NFCommon::tostr(m_roomId)) +
                                     "FishKind/FishSetting.ini";

    NFINIReader iniReader;
    int iRetCode = iniReader.Parse(strFishSettingPath);
    CHECK_EXPR(iRetCode == 0, -1, "NFINIReader Parse:{} Failed", strFishSettingPath);

    //std::string value = reader.Get(sectionName, field, "");

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() ===============> OK !");

    m_iDNTGKilledGroup = iniReader.GetInt32("setting", "DNTGKilledGroup", 0);
    m_iDNTGGroupInterval = iniReader.GetInt32("setting", "DNTGInterval", 100);
    //m_iYuZhenIntervalMin = iniReader.GetInt32("setting", "YuZhenIntervalMin", 120000);
    //m_iYuZhenIntervalMax = iniReader.GetInt32("setting", "YuZhenIntervalMax", 120000);
    m_iOneCannonKilled = iniReader.GetInt32("setting", "OneCannonKilled", 0);
    m_iKillJudgeType = iniReader.GetInt32("setting", "KillJudgeType", 0);

    m_iDoubleCannonEnable = iniReader.GetInt32("doublecannon", "enable", 0);
    m_iDoubleCannonRatio = iniReader.GetInt32("doublecannon", "ratio", 5);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iDNTGKilledGroup = {}", m_iDNTGKilledGroup);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iDNTGGroupInterval = {}", m_iDNTGGroupInterval);
    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iYuZhenIntervalMin = {}", m_iYuZhenIntervalMin);
    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iYuZhenIntervalMax = {}", m_iYuZhenIntervalMax);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iOneCannoKilled = {}", m_iOneCannonKilled);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iKillJudgeType = {}", m_iKillJudgeType);

    std::set<std::string> setFields = iniReader.GetFields("waybillratio");
    std::set<std::string>::iterator iter = setFields.begin();
    for (; iter != setFields.end(); iter++)
    {
        std::string strKey = *iter;
        std::string strValue = iniReader.Get("waybillratio", strKey, "");
        int iValue = atoi(strValue.c_str());

        if (m_mapWayBills.full())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapWayBills full");
            NFSLEEP(1000);
            exit(0);
        }
        m_mapWayBills.emplace(strKey, iValue);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load waybillratio: {} = {}", strKey, iValue);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iDNTGKilledGroup = {}", m_iDNTGKilledGroup);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iDNTGGroupInterval = {}", m_iDNTGGroupInterval);
    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iYuZhenIntervalMin = {}", m_iYuZhenIntervalMin);
    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iYuZhenIntervalMax = {}", m_iYuZhenIntervalMax);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iOneCannoKilled = {}", m_iOneCannonKilled);

    /*std::set<std::string>*/ setFields = iniReader.GetFields("ZuanTouTrace");
    /*std::set<std::string>::iterator*/ iter = setFields.begin();
    for (; iter != setFields.end(); iter++)
    {
        std::string strKey = *iter;
        std::string strValue = iniReader.Get("ZuanTouTrace", strKey, "");

        int iKey = atoi(strKey.c_str());
        std::vector<uint32_t> vec;
        NFStringUtility::SplitStringToVectorInt(strValue, ",", vec);

        NFShmVector<uint32_t, 20> ary;
        ary.insert(ary.end(), vec.begin(), vec.end());

        if (!m_mapShootTraces.full())
        {
            m_mapShootTraces.emplace(iKey, ary);

            std::string strLog;
            for (int i = 0; i < (int)ary.size(); i++)
            {
                strLog += ",";
                strLog += NFCommon::tostr(ary[i]);
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load ZuanTouTrace: {} = {}", iKey, strLog);
        }
        else
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load m_mapChangeSceneType_Time Full !");
        }
    }

    //////////////////////////////////////////////////////////////////////////

    std::string strMaxValue = iniReader.Get("CtrlParam", "MaxValue", "100000");
    std::string strMinValue = iniReader.Get("CtrlParam", "MinValue", "10000");
    std::string strCtrlTime = iniReader.Get("CtrlParam", "TimeSecods", "300");
    std::string strCtrlParams = iniReader.Get("CtrlParam", "Params", "");

    m_illMaxValue = atoll(strMaxValue.c_str());
    m_illMinValue = atoll(strMinValue.c_str());
    m_iCtrlTime = atoi(strCtrlTime.c_str());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_illMaxValue = {}", m_illMaxValue);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_illMinValue = {}", m_illMinValue);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_iCtrlTime   = {}", m_iCtrlTime);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() strCtrlParams = {}", strCtrlParams);


    std::vector<std::string> vecStr;
    NFStringUtility::SplitStringToVector(strCtrlParams, "|", vecStr);
    std::vector<std::string>::iterator iterCtrlP = vecStr.begin();
    for (; iterCtrlP != vecStr.end(); iterCtrlP++)
    {
        std::string strTmp = *iterCtrlP;

        //auto pos = strTmp.find(",");
        //std::string str1 = strTmp.substr(0, pos);
        //std::string str2 = strTmp.substr(pos + 1);
        std::vector<std::string> vecStr1;
        NFStringUtility::SplitStringToVector(strTmp, ",", vecStr1);
        if (vecStr1.size() == 2)
        {
            std::string str1 = vecStr1[0];
            std::string str2 = vecStr1[1];

            CtrlParam param;
            param.m_dbPercent = atof(str1.c_str());
            param.m_dbValuePercent = atof(str2.c_str());
            param.m_llMaxValue = 0;

            if (m_AryCtrlParam.size() >= m_AryCtrlParam.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_AryCtrlParam full");
                NFSLEEP(1000);
                exit(0);
            }
            m_AryCtrlParam.push_back(param);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishSetting::Load() m_dbPercent = {} , m_dbValuePercent = {}", param.m_dbPercent,
                       param.m_dbValuePercent);
        }
    }

    return 0;
}

uint32_t NFFishSettingConfig::GetShootTrace(int chairId, int traceIndex)
{
    auto iter = m_mapShootTraces.find(chairId);
    if (iter != m_mapShootTraces.end())
    {
        int count = iter->second.size();
        if (count > 0 && traceIndex < count)
        {
            return iter->second[traceIndex];
        }
    }

    return 0;
}

std::string NFFishSettingConfig::GetPriorWayBill(std::string strLastWayBillName /*= ""*/)
{
    auto iter = m_mapWayBills.find(strLastWayBillName);
    if (iter != m_mapWayBills.end())
    {
        return "";
    }
    else
    {
        std::vector<std::string> vecNames;
        for(auto iter = m_mapWayBills.begin(); iter != m_mapWayBills.end(); iter++)
        {
            vecNames.push_back(iter->first.ToString());
        }

        if (vecNames.size() > 0)
        {
            int iRand = NFRandomInt(0, (int) vecNames.size());

            if (iRand >= 0 && iRand < (int) vecNames.size())
            {
                std::string strKey = vecNames[iRand];
                auto iter = m_mapWayBills.find(strKey);
                if (iter != m_mapWayBills.end())
                {
                    iRand = NFRandomInt(0, 100);

                    if (iRand < iter->second)
                    {
                        return strKey;
                    }
                }
            }
        }
    }

    return "";
}

CtrlParam NFFishSettingConfig::GetCtrlParam(uint32_t &uCount, int64_t llTotalShootInCtrlTime)
{
    if (m_AryCtrlParam.size() > 0)
    {
        int iIndex = uCount % m_AryCtrlParam.size();
        CtrlParam param = m_AryCtrlParam[iIndex];
        param.m_llMaxValue = CalMaxValueByTotalShootValue(param, llTotalShootInCtrlTime);

        uCount++;

        return param;
    }
    else
    {
        return CtrlParam();
    }
}

int64_t NFFishSettingConfig::CalMaxValueByTotalShootValue(CtrlParam &ctrlParam, int64_t llTotalShootInCtrlTime)
{
    int64_t llTempMaxValue = llTotalShootInCtrlTime;

    if (llTempMaxValue > m_illMaxValue)
    {
        llTempMaxValue = m_illMaxValue;
    }

    llTempMaxValue = llTempMaxValue * ctrlParam.m_dbValuePercent;
    if (llTempMaxValue <= m_illMinValue)
    {
        llTempMaxValue = m_illMinValue;
    }

    if (ctrlParam.m_dbPercent > 0)
    {
        return llTempMaxValue;
    }
    else
    {
        return -llTempMaxValue;
    }
}