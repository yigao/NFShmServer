#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskreward_s.h"

#define MAX_TASKREWARD_TASKREWARD_NUM 16384

#define MAX_COM_INDEX_TASKREWARD_TASKREWARD_TASKTYPE_NUM 1024

#define UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_TASKTYPE_NUM 16

#define MAX_COM_INDEX_TASKREWARD_TASKREWARD_LV_NUM 16

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


class TaskrewardTaskrewardDesc : public NFIDescStore
{
public:
	TaskrewardTaskrewardDesc();
	virtual ~TaskrewardTaskrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskrewardTaskreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskrewardTaskreward_s* GetDescByIndex(int index);
public:
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDescByTasktypeLv(int64_t Tasktype, int64_t Lv);
private:
	NFShmHashMap<TaskrewardTaskrewardTasktypeLv ,uint32_t, UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_TASKTYPE_NUM*UNIQUE_KEY_MAX_COM_INDEX_TASKREWARD_TASKREWARD_LV_NUM> m_TasktypeLvComIndexMap;
IMPL_RES_HASH_DESC(TaskrewardTaskrewardDesc, proto_ff_s::E_TaskrewardTaskreward_s, E_TaskrewardTaskreward, MAX_TASKREWARD_TASKREWARD_NUM);
DECLARE_IDCREATE(TaskrewardTaskrewardDesc);
};
