#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFGameCommon/NFComTypeDefine.h"

//技能配置
struct SkillCfg
{
	SkillCfg()
	{
	
	}
	
	VEC_INT32 vec_unlocktype;					//解锁类型
	VEC_INT32 vec_unlockvalue;					//解锁值
	
	int32_t rangeValue1 = 0;					//范围值1
	int32_t rangeValue2 = 0;					//范围值2
	int32_t rangeValue3 = 0;					//范围值3
	int32_t rangeValueEx1 = 0;					//扩展范围值1
	int32_t rangeValueEx2 = 0;					//扩展范围值2
	int32_t rangeValueEx3 = 0;					//扩展范围值3
	
	VEC_INT64 vecRelation;						//关联技能
	int64_t preRelation = 0;					//前置关联技能ID
	VEC_UINT32 vecDamage;						//伤害时间点
	VEC_UINT32 vecDamageEx;						//扩展伤害时间点
};

class SkillDescEx : public NFShmObjGlobalTemplate<SkillDescEx, EOT_CONST_SKILL_DESC_EX_ID, NFIDescStoreEx>
{
public:
	SkillDescEx();
	virtual ~SkillDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
};
