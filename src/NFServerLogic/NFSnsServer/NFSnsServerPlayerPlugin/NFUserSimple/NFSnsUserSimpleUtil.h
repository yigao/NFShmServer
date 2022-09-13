// -------------------------------------------------------------------------
//    @FileName         :    NFSnsUserSimpleUtil.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSnsUserSimpleUtil.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmHashTable.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFShmCore/NFShmStaticList.hpp"
#include <vector>
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFComm/NFShmCore/NFArray.h"

#define SNS_GET_ROLE_SIMPLE_INFO_QUEUE 200000
#define SNS_GETTING_ROLE_SIZE 500
#define SNS_CALLBACK_TRANS_RUN_TIMES 20

class NFSnsUserSimple;

struct SGetRoleCacheData
{
	struct SGetRoleCacheDataInfo
	{
		SGetRoleCacheDataInfo()
		{
			if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
				CreateInit();
			}
			else {
				ResumeInit();
			}
		}

		SGetRoleCacheDataInfo(const SGetRoleCacheDataInfo& info)
		{
			if (this == &info)
			{
				return;
			}

			transID = info.transID;
			getTime = info.getTime;
		}

		int CreateInit()
		{
			transID = 0;
			getTime = 0;
			return 0;
		}

		int ResumeInit()
		{
			return 0;
		}
		int transID;
		uint32_t getTime;
	};

	SGetRoleCacheData()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}

	int CreateInit()
	{
		roleID = 0;
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}


    uint64_t roleID;
	NFArray<SGetRoleCacheDataInfo, SNS_CALLBACK_TRANS_RUN_TIMES> roleInfo;

    void clear()
    {
        roleID = 0;
		memset(&roleInfo, 0, sizeof(roleInfo));
    }

    int add(uint64_t rid, int rtrans, uint32_t rtime);
};

class NFSnsUserSimpleUtil : public NFShmObj {
public:
    NFSnsUserSimpleUtil();

    virtual ~NFSnsUserSimpleUtil();

    int CreateInit();

    int ResumeInit();

    virtual void OnTimer(int timeId, int callcount);
    void RefreshQueue();
public:
    // 接口没有做RoleSimple检测,需要自己提前检测（如TransSnsBase）
    int GetRoleSimpleInfo(uint64_t roleID, int transID, uint32_t time);
    // 接口会去check是否RoleSimple已经存在，存在会直接返回
    int GetCheckedRoleSimpleInfo(uint64_t roleID);

    int TransGetRoleSimpleInfo(SGetRoleCacheData *data);

    int HandleGetRoleTransFinished(int iRunLogicRetCode, uint64_t roleID);

    NFSnsUserSimple* GetRoleSimpe(uint64_t role_id, bool query=true/*找不到是否查询数据库*/);

private:
	NFShmHashMap<uint64_t, SGetRoleCacheData, SNS_GET_ROLE_SIMPLE_INFO_QUEUE> m_sRoleStatic;
    NFShmStaticList<SGetRoleCacheData, SNS_GETTING_ROLE_SIZE> m_sGetRoleStatic;
    int m_refreshTimer;

    bool flag;
DECLARE_IDCREATE(NFSnsUserSimpleUtil)
};
