// -------------------------------------------------------------------------
//    @FileName         :    NFShmMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFShmMgr.h"
#include "NFISharedMemModule.h"


NFShmMgr::NFShmMgr()
{
	m_pShmModule = nullptr;
    m_inited = false;
}

NFShmMgr::~NFShmMgr()
{
}

bool NFShmMgr::Init(NFISharedMemModule* pShmModule)
{
    m_inited = true;
	m_pShmModule = pShmModule;
	return true;
}

void NFShmMgr::UnInit()
{
}

/**
* 共享内存模式
*/
EN_OBJ_MODE	NFShmMgr::GetInitMode()
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetInitMode();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return EN_OBJ_MODE_INIT;
}

void NFShmMgr::SetInitMode(EN_OBJ_MODE mode)
{
	if (m_pShmModule)
	{
		return m_pShmModule->SetInitMode(mode);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}

/**
* 共享内存创建对象模式
*/
EN_OBJ_MODE	NFShmMgr::GetCreateMode()
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetCreateMode();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return EN_OBJ_MODE_RECOVER;
}

/**
* 共享内存创建对象模式
*/
void NFShmMgr::SetCreateMode(EN_OBJ_MODE mode)
{
	if (m_pShmModule)
	{
		m_pShmModule->SetCreateMode(mode);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}
