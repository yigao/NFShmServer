// -------------------------------------------------------------------------
//    @FileName         :    NFFishGroupMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishGroupMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFFishGroupConfig.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFFishDefine.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishGroupConfig, EOT_FISH_GROUP_MGR_ID, NFShmObj)


NFFishGroupConfig::NFFishGroupConfig() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFFishGroupConfig::~NFFishGroupConfig() {

}

int NFFishGroupConfig::CreateInit() {
    m_roomId = 0;
    return 0;
}

int NFFishGroupConfig::ResumeInit() {
    return 0;
}

int NFFishGroupConfig::GetFileContainMD5(const std::string& strFileName, std::string& fileMd5)
{
    bool exist = NFFileUtility::IsFileExist(strFileName);
    CHECK_EXPR(exist, -1, "strFileName:{} not exist", strFileName);

    fileMd5 = NFMD5::md5file(strFileName);
    return 0;
}

int NFFishGroupConfig::LoadConfig(uint32_t gameId, uint32_t roomId)
{
    m_roomId = roomId;
    uint64_t comKey = gameId * 100 + roomId;
    NFFishTraceConfig* pTrace = NFFishTraceConfig::GetObjByHashKey(m_pObjPluginManager, comKey);
    CHECK_NULL(pTrace);

    std::list<std::string> FilesList;
    std::string path = m_pObjPluginManager->GetConfigPath() + "/Config" + NFCommon::tostr(gameId) + "_" + NFCommon::tostr(m_roomId);

    int iRet = 0;

    GetAllGroupFiles(path, FilesList);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CFishGroupMgr::LoadConfig() ==============> FilesList.size() = {}", FilesList.size());
	

    for (auto it = FilesList.begin(); it != FilesList.end(); ++it)
    {
        std::string strUnId = NFFileUtility::GetFileNameWithoutExt(*it);
        std::string fileMd5;
        iRet = GetFileContainMD5(*it, fileMd5);
        if (iRet != 0) continue;

        unsigned int unId = NFCommon::strto<unsigned int>(strUnId);

        CFishGroup* group = GetFishGroup(unId);
        if (group == NULL)
        {
            group = InsertFishGroup(unId);
            if (!group)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Load Config:{} Failed! fish group full, not space!", *it);
                return -1;
            }
            group->Clear();
            group->SetId(unId);
            group->SetFileMD5(fileMd5);
        }
        else
        {
            if (fileMd5 == group->GetFileMD5())
            {
                continue;
            }

            group->Clear();
            group->SetId(unId);
            group->SetFileMD5(fileMd5);
        }

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroupMgr::Init() m_FishGroupMap[{}] = groupId = {}", unId, unId);
        iRet = group->Load(*it, pTrace);

		int iSceneType = group->m_bySceneType;
		int iSceneIndex = group->m_bySceneIndex;
		if (iSceneType>0 && iSceneIndex > -1)
		{
			int32_t* pSceneIndex = InsertSceneIndex(iSceneIndex);
			if (pSceneIndex != NULL)
			{
				*pSceneIndex = iSceneIndex;

				//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroupMgr::Init() groupId = {} , add iSceneIndex = {}", group->Id(), iSceneIndex);
			}
            else {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Load Config:{} Failed! fish group m_SceneIndexMap full, not space!", *it);
                return -1;
            }
		}

        //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroupMgr::Init() m_FishGroupMap[{}] = groupId = {}", unId, unId);

        if (0 != iRet)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishGroupMgr::Init() init file: {} failed.", it->c_str());
        }
    }

    uint32_t maxFishNum = 0;
    for(auto iter = m_FishGroupMap.begin(); iter != m_FishGroupMap.end(); iter++)
    {
        auto pGroup = &iter->second;
        if (pGroup)
        {
            if ((uint32_t)pGroup->m_FishList.size() > maxFishNum)
            {
                maxFishNum = pGroup->m_FishList.size();
            }
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CFishGroupMgr::Init() OK. group num:{} max fish num:{}", m_FishGroupMap.size(), maxFishNum);

    return 0;
}

int NFFishGroupConfig::GetAllGroupFiles(const string &strFishGroupPath, list<std::string> &FilesList) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    std::string strPath = NFFileUtility::NormalizePath(strFishGroupPath);
    strPath = strPath + "FishGroup";
    NFFileUtility::GetFiles(strPath, FilesList, 0, "*.group");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");

    return 0;
}

bool NFFishGroupConfig::IsSceneIndexExist(int32_t iSceceIndex)
{
	if (m_SceneIndexMap.find(iSceceIndex) != m_SceneIndexMap.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int32_t* NFFishGroupConfig::InsertSceneIndex(int32_t iSceceIndex)
{
    if (!m_SceneIndexMap.full())
    {
        return &m_SceneIndexMap[iSceceIndex];
    }

    return NULL;
}


CFishGroup* NFFishGroupConfig::GetFishGroup(int groupId)
{
    auto iter = m_FishGroupMap.find(groupId);
    if (iter != m_FishGroupMap.end())
    {
        return &iter->second;
    }

    return NULL;
}

CFishGroup* NFFishGroupConfig::InsertFishGroup(int groupId)
{
    if (!m_FishGroupMap.full())
    {
        return &m_FishGroupMap[groupId];
    }

    return NULL;
}

