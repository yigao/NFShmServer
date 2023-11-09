#include "EquipDescEx.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/EquipBreakDesc.h"

EquipDescEx::EquipDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EquipDescEx::~EquipDescEx()
{
}

int EquipDescEx::CreateInit()
{
    maxStrongLv = 0;
	return 0;
}

int EquipDescEx::ResumeInit()
{
	return 0;
}

int EquipDescEx::Load()
{
    CHECK_EXPR(ProcessStrong() == 0, -1, "ProcessStrong Failed");
    CHECK_EXPR(ProcessStrongLv() == 0, -1, "ProcessStrong Failed");
    CHECK_EXPR(ProcessBreak() == 0, -1, "ProcessStrong Failed");
	return 0;
}

int EquipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

int EquipDescEx::ProcessStrong()
{
    auto pStrongMap = EquipStrongDesc::Instance()->GetResDescPtr();
    CHECK_NULL(pStrongMap);
    
    for (auto& e : *pStrongMap)
    {
        auto& ref = e.second;
        int32_t strongId = EQUIP_STRONG_ID(ref.m_position, ref.m_wearQuality);
        CHECK_EXPR(m_strong.find(strongId) == m_strong.end(), -1, "QUIP_STRONG_ID repeated!...position:{},wearQuality:{}, id:{}",ref.m_position, ref.m_wearQuality, ref.m_id);
        CHECK_EXPR(m_strong.size() < m_strong.max_size(), -1, "m_strong space not enough");
        
        stEquipStrongCfg& cfg = m_strong[strongId];
        cfg.cfg_id = e.first;
        for (auto& ie : ref.m_type)
        {
            if (ie.m_id == 0) continue;
            stEquipStrongAttrCfg t;
            t.attrId = ie.m_id;
            std::vector<float> vec;
            NFCommonApi::SplitStrToVecFloat(ie.m_num.data(), ";", &vec);
            CHECK_EXPR(vec.size() == 3, -1, "vec.size() error, id:{} attrid:{} num:{}", ref.m_id, ie.m_id, ie.m_num.data());
            t.param0 = vec[0];
            t.param1 = vec[1];
            t.param2 = vec[2];
            cfg.attr.push_back(t);
        }
    }
    
    auto pBeastStrongMap = EquipBeaststrongDesc::Instance()->GetResDescPtr();
    CHECK_NULL(pBeastStrongMap);
    
    for (auto& e : *pBeastStrongMap)
    {
        auto& ref = e.second;
        int32_t strongId = EQUIP_STRONG_ID(ref.m_position, ref.m_wearQuality);
        
        CHECK_EXPR(m_strongBeast.find(strongId) == m_strongBeast.end(), -1, "beast QUIP_STRONG_ID repeated!...position:{},wearQuality:{}, id:{}",ref.m_position, ref.m_wearQuality, ref.m_id);
        CHECK_EXPR(m_strongBeast.size() < m_strongBeast.max_size(), -1, "m_strongBeast space not enough");
        stEquipBeastStrongCfg& cfg = m_strongBeast[strongId];
        
        cfg.cfg_id = e.first;
        for (auto& ie : ref.m_type)
        {
            if (ie.m_id > 0)
            {
                stEquipStrongAttrCfg t;
                t.attrId = ie.m_id;
                std::vector<float> vec;
                NFCommonApi::SplitStrToVecFloat(ie.m_num.data(), ";", &vec);
                CHECK_EXPR(vec.size() == 3, -1, "vec.size() error, id:{} attrid:{} num:{}", ref.m_id, ie.m_id, ie.m_num.data());
                t.param0 = vec[0];
                t.param1 = vec[1];
                t.param2 = vec[2];
                cfg.attr.push_back(t);
            }
        }
    }
    
    return 0;
}

int EquipDescEx::ProcessStrongLv()
{
    auto pBreakMap = EquipBreakDesc::Instance()->GetResDescPtr();
    CHECK_NULL(pBreakMap);
    for(auto iter = pBreakMap->begin(); iter != pBreakMap->end(); iter++)
    {
        std::vector<int32_t> vec;
        NFCommonApi::SplitStrToVecInt(iter->second.m_positionType.data(), ";", &vec);
        for(size_t i = 0; i < vec.size(); i++)
        {
            m_breakStrong[vec[i]][iter->second.m_step] = iter->first;
        }
    }
    return 0;
}

int EquipDescEx::ProcessBreak()
{
    auto pStrongExpMap = EquipStrongexpDesc::Instance()->GetResDescPtr();
    CHECK_NULL(pStrongExpMap);
    
    for (auto& e : *pStrongExpMap)
    {
        auto& ref = e.second;
        
        stEquipLvCfg& lv = m_stronglv[ref.m_Lv];
        lv.cfg_id = e.first;;
        lv.costGold = ref.m_gold;
        CHECK_EXPR(ref.m_cost.size() >= 3, false, "EquipCfg::ProcessStringLv id:%d m_cost size error", ref.m_Lv);
        
        proto_ff_s::ComPair64_s& nomal = lv.m_costItem[EEquipType_nomal];
        nomal.key = ref.m_cost.at(0).m_Item;
        nomal.value = ref.m_cost.at(0).m_Num;
        
        proto_ff_s::ComPair64_s& xq = lv.m_costItem[EEquipType_xq];
        xq.key = ref.m_cost.at(1).m_Item;
        xq.value = ref.m_cost.at(1).m_Num;
        
        proto_ff_s::ComPair64_s& deity = lv.m_costItem[EEquipType_deity];
        deity.key = ref.m_cost.at(2).m_Item;
        deity.value = ref.m_cost.at(2).m_Num;
        
        
        if (ref.m_Lv > maxStrongLv)
        {
            maxStrongLv = ref.m_Lv;
        }
    }
    
    return 0;
}

stEquipStrongCfg *EquipDescEx::GetStrongCfg(int64_t id)
{
    auto iter = m_strong.find(id);
    return iter != m_strong.end() ? &(iter->second) : nullptr;
}

stEquipLvCfg *EquipDescEx::GetStrongLvCfg(int32_t lv)
{
    auto iter = m_stronglv.find(lv);
    return iter != m_stronglv.end() ? &(iter->second) : nullptr;
}

stEquipBeastStrongCfg *EquipDescEx::GetBeastStrongCfg(int64_t id)
{
    auto iter = m_strongBeast.find(id);
    return iter != m_strongBeast.end() ? &(iter->second) : nullptr;
}

const proto_ff_s::E_EquipBreak_s* EquipDescEx::GetBreakCfgInfo(int32_t pos, int32_t step)
{
    auto iter = m_breakStrong.find(pos);
    if (iter != m_breakStrong.end())
    {
        auto it = iter->second.find(step);
        if (it != iter->second.end())
        {
            return EquipBreakDesc::Instance()->GetDesc(it->second);
        }
    }
    
    return nullptr;
}

