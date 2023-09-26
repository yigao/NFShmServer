// -------------------------------------------------------------------------
//    @FileName         :    NFFIshTypeBaseData.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFIshTypeBaseData
//
// -------------------------------------------------------------------------

#include "NFFishTypeBaseData.h"
#include "Fish/NFGameFish.h"
#include "NFFishTypeHandler.h"
#include "Desk/NFGameFishDesk.h"

NFFishTypeBaseData::NFFishTypeBaseData()
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

NFFishTypeBaseData::~NFFishTypeBaseData()
{
}

int NFFishTypeBaseData::CreateInit()
{
    return 0;
}

int NFFishTypeBaseData::ResumeInit()
{
    return 0;
}

NFGameFishPlayer* NFFishTypeBaseData::GetPlayer(uint64_t playerId)
{
    NFGameFishDesk* pDesk = GetDesk();
    if (pDesk)
    {
        return pDesk->GetPlayer(playerId);
    }
    return nullptr;
}

NFGameFishDesk* NFFishTypeBaseData::GetDesk()
{
    NFFishTypeHandler* pHandler = GetFishTypeHandler();
    if (pHandler)
    {
        return pHandler->m_pDesk.GetPoint();
    }
    return nullptr;
}

NFFishTypeHandler* NFFishTypeBaseData::GetFishTypeHandler()
{
    return dynamic_cast<NFFishTypeHandler*>(GetShmObj());
}
