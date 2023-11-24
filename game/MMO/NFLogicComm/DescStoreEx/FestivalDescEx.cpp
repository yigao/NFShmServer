#include "FestivalDescEx.h"
#include "DescStore/FestivalTemplateDesc.h"
#include "DescStore/FestivalPeriodindexDesc.h"

FestivalDescEx::FestivalDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalDescEx::~FestivalDescEx()
{
}

int FestivalDescEx::CreateInit()
{
	return 0;
}

int FestivalDescEx::ResumeInit()
{
	return 0;
}

int FestivalDescEx::Load()
{
	return 0;
}

int FestivalDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

uint8_t FestivalDescEx::ChkTimeState(const ChkFestParam &param, const FestTplCfg *tplcfg)
{
	if ((int32_t)ETimeType::permanent == tplcfg->timetype) return (uint8_t)EFestState::open;
	if ((int32_t)ETimeType::openserver == tplcfg->timetype)
	{
		if ((int64_t)EServType::newzone == tplcfg->timeparam3)
		{
			if (!param.isret || param.ismerge) return (uint8_t)EFestState::not_open;
		}
		else if ((int64_t)EServType::merge == tplcfg->timeparam3)
		{
			if (!param.isret || !param.ismerge) return (uint8_t)EFestState::not_open;
		}
		if (param.days < tplcfg->timeparam1) return (uint8_t)EFestState::not_open;
		if (param.days > tplcfg->timeparam2) return (uint8_t)EFestState::end;
		return (uint8_t)EFestState::open;
	}
	if ((int32_t)ETimeType::date == tplcfg->timetype)
	{
		if (param.curtime < (uint64_t)tplcfg->timeparam1) return (uint8_t)EFestState::not_open;
		if (tplcfg->timeparam3 > 0)
		{
			uint64_t begin = param.zerotime + tplcfg->timeparam3 * 24 * 3600;
			if (param.curtime < begin) return (uint8_t)EFestState::not_open;
		}
		if (param.curtime >= (uint64_t)tplcfg->timeparam2) return (uint8_t)EFestState::end;
		return (uint8_t)EFestState::open;
	}
	return (uint8_t)EFestState::not_open;
}

bool FestivalDescEx::IsDropServerType(int32_t serverType)
{
	return ((int32_t)ETplType::drop == serverType || (int32_t)ETplType::mult_drop == serverType);
}

bool FestivalDescEx::ProcessTemplate()
{
	return true;
}

