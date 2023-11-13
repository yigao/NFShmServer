// -------------------------------------------------------------------------
//    @FileName         :    NFSkillPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFSkillDefine.h"

class NFSkillPart : public NFShmObjTemplate<NFSkillPart, EOT_LOGIC_PART_ID+PART_SKILL, NFPart>
{
public:
    NFSkillPart();

    virtual ~NFSkillPart();

    int CreateInit();

    int ResumeInit();
public:
    //生命改变
    void OnHpChange(int64_t oldHp, int64_t curHp, int64_t maxHp) { }
    //添加技能(永久增加)
    bool AddSkill(uint64_t skillid, int32_t level, const SCommonSource& src, bool sync = false, uint64_t use_msec = 0) { return true; }
    //移除技能(一定存在)
    bool RemoveSkill(uint64_t skillid, const SCommonSource& src, bool sync = false) { return true; }
    //技能总战力
    int64_t SkillFight() { return 0; }
    //天神变身 deityId：天神ID
    int32_t OnDeityChgFacade(int64_t deityId) { return 0; }
    
    //获取技能信息
    const SkillInfo* GetSkillInfo(uint64_t skillid) { return nullptr; }
    
    //技能升级，返回 RET_SUCCESS 成功，其他表示错误码
    int32_t SkillUpgrade(uint64_t skillid) { return 0; }
};