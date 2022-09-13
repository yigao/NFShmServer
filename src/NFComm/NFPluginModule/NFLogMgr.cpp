// -------------------------------------------------------------------------
//    @FileName         :    NFLogMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#include "NFLogMgr.h"

#include <sstream>

#include "NFILogModule.h"

NFLogMgr::NFLogMgr()
{
	m_pLogModule = nullptr;
}

NFLogMgr::~NFLogMgr()
{
}

bool NFLogMgr::Init(NFILogModule* pSpdlogModule)
{
	m_pLogModule = pSpdlogModule;
	return true;
}

void NFLogMgr::UnInit()
{
	m_pLogModule = nullptr;
}

/**
* @brief 设置默认的LOG的输出等级
*
* @param  log_level log等级
* @return bool
*/
void NFLogMgr::SetDefaultLevel(NF_LOG_LEVEL log_level)
{
	if (m_pLogModule)
	{
		m_pLogModule->SetDefaultLevel(log_level);
	}
}

/**
* @brief 设置默认的LOG的刷新等级
*
* @param  log_level log等级
* @return bool
*/
void NFLogMgr::SetDefaultFlush(NF_LOG_LEVEL log_level)
{
	if (m_pLogModule)
	{
		m_pLogModule->SetDefaultFlush(log_level);
	}
}

