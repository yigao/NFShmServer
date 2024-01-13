// -------------------------------------------------------------------------
//    @FileName         :    NFShmIdx.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFShmIdx.h"
#include "NFComm/NFShmCore/NFShmObj.h"

NFShmIdx::NFShmIdx()
{
	Initialize();
}

NFShmIdx::~NFShmIdx()
{
    Initialize();
}

void NFShmIdx::Initialize()
{
	m_uEntity.m_pAttachedObj = NULL;
}

void *NFShmIdx::GetObjBuf()
{
	return m_uEntity.m_pBuf;
}

void NFShmIdx::SetObjBuf(void *pBuf)
{
	assert(pBuf);
	m_uEntity.m_pBuf = pBuf;
}

NFShmObj* NFShmIdx::GetAttachedObj()
{
	return m_uEntity.m_pAttachedObj;
}

const NFShmObj* NFShmIdx::GetAttachedObj() const
{
    return m_uEntity.m_pAttachedObj;
}

void NFShmIdx::SetAttachedObj(NFShmObj *pObj)
{
	assert(pObj);
	m_uEntity.m_pAttachedObj = pObj;
}

