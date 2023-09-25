// -------------------------------------------------------------------------
//    @FileName         :    NFFishGroupMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishGroupMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFFishGroup.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"

#define DEFAULT_GROUPNUM 600

class NFFishGroupConfig : public NFShmObj
{
public:
    NFFishGroupConfig();

    virtual ~NFFishGroupConfig();

    int CreateInit();

    int ResumeInit();


    virtual int LoadConfig(uint32_t gameId, uint32_t roomId);
    virtual int GetAllGroupFiles(const std::string& strFishGroupPath, std::list<std::string> & FilesList);
    int GetFileContainMD5(const std::string& strFileName, std::string& fileMd5);

	bool IsSceneIndexExist(int32_t iSceceIndex);
    int32_t* InsertSceneIndex(int32_t iSceceIndex);

    CFishGroup* GetFishGroup(int groupId);
    CFishGroup* InsertFishGroup(int groupId);
private:
    uint32_t m_roomId;
    NFShmHashMap<uint32_t, CFishGroup, DEFAULT_GROUPNUM> m_FishGroupMap;
	NFShmHashMap<int32_t, int32_t, 20> m_SceneIndexMap;

    DECLARE_IDCREATE(NFFishGroupConfig);
};