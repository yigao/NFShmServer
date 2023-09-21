#include "NFFishPromptConfig.h"
#include "NFComm/NFCore/NFIniReader.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "NFComm/NFCore/NFCommon.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishPromptConfig, EOT_GAME_FISH_PROMPT_CFG_DESC_2004_ID, NFShmObj)

NFFishPromptConfig::NFFishPromptConfig()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFFishPromptConfig::~NFFishPromptConfig()
{

}

int NFFishPromptConfig::CreateInit()
{
    m_roomId = 0;
    m_iSceneCount = 0;
    m_iYuChaoTipOn = 0;
    m_mapChangeSceneType_Time.CreateInit();
    return 0;
}

int NFFishPromptConfig::ResumeInit()
{
    return 0;
}

int NFFishPromptConfig::LoadConfig(uint32_t roomId)
{
    m_roomId = roomId;
	std::string strFishPromptIni = NFFileUtility::NormalizePath(m_pObjPluginManager->GetConfigPath() + "/Config" + NFCommon::tostr(GAME_ID_FISH_HAIWANG_2004) + "_" + NFCommon::tostr(m_roomId)) + "FishKind/FishPrompt.ini";

	NFINIReader iniReader;
	int iRetCode = iniReader.Parse(strFishPromptIni);
	CHECK_EXPR(iRetCode == 0, -1, "NFINIReader Parse:{} Failed", strFishPromptIni);

	m_iSceneCount = iniReader.GetInt32("SceneSetting", "SceneCount", 3);
	m_iYuChaoTipOn = iniReader.GetInt32("SceneSetting", "YuChaoTipOn", 0);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishPromptCfg::Load() m_iSceneCount = {}", m_iSceneCount);


	std::set<std::string> setFields = iniReader.GetFields("ChangeSceneTime");
	std::set<std::string>::iterator iter = setFields.begin();
	for (; iter != setFields.end(); iter++)
	{
		std::string strKey = *iter;
		double fVal = iniReader.GetReal("ChangeSceneTime", strKey, 1);
		int iKey = atof(strKey.c_str());

		if (!m_mapChangeSceneType_Time.full())
		{
			m_mapChangeSceneType_Time.emplace(iKey, fVal);
		}
		else
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "NFFishPromptCfg::Load m_mapChangeSceneType_Time Full");
		}

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishPromptCfg::Load() {} = {}", iKey, fVal);
	}

	return 0;
}

float NFFishPromptConfig::GetChangeSceneSeconds(int iChangeType)
{
	auto iter = m_mapChangeSceneType_Time.find(iChangeType);
	if (iter == m_mapChangeSceneType_Time.end())
	{
		return 1;
	}

	return iter->second;
}