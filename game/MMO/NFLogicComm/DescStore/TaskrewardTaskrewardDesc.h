#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskreward_s.h"

#define MAX_TASKREWARD_TASKREWARD_NUM 4096

#define MAX_COM_INDEX_TASKREWARD_TASKREWARD_TASKTYPE_NUM 2048

#define UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_TASKTYPE_NUM 8

#define MAX_COM_INDEX_TASKREWARD_TASKREWARD_LV_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_LV_NUM 2048

struct TaskrewardTaskrewardTasktypeLv
{
	TaskrewardTaskrewardTasktypeLv()
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
		m_taskType=0;
		m_lv=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_taskType;
	int64_t m_lv;
	bool operator==(const TaskrewardTaskrewardTasktypeLv& data) const
	{
		 return m_taskType==data.m_taskType && m_lv==data.m_lv;
	}
};

namespace std
{
	template<>
	struct hash<TaskrewardTaskrewardTasktypeLv>
	{
		size_t operator()(const TaskrewardTaskrewardTasktypeLv& data) const
		{
			return NFHash::hash_combine(data.m_taskType,data.m_lv);
		}
	};
}


class TaskrewardTaskrewardDesc : public NFIDescTemplate<TaskrewardTaskrewardDesc, proto_ff_s::E_TaskrewardTaskreward_s, EOT_CONST_TASKREWARD_TASKREWARD_DESC_ID, MAX_TASKREWARD_TASKREWARD_NUM>
{
public:
	TaskrewardTaskrewardDesc();
	virtual ~TaskrewardTaskrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDescByTasktypeLv(int64_t Tasktype, int64_t Lv);
private:
	NFShmHashMap<TaskrewardTaskrewardTasktypeLv ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_TASKTYPE_NUM*UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_LV_NUM> m_TasktypeLvComIndexMap;
};
