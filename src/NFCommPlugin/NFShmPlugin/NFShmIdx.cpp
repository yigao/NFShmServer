// -------------------------------------------------------------------------
//    @FileName         :    NFShmIdx.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
}

void NFShmIdx::Initialize()
{
	m_iPrevIdx = 0;
	m_iNextIdx = -1;
	m_nUseFlag = 0;
	m_uEntity.m_pAttachedObj = NULL;
	ClearDsInfo();
}

int NFShmIdx::GetDsInfo(short nDsIdx, int *piDsVal)
{
	if (nDsIdx < 0 || nDsIdx >= MAXDSINFOITEM || piDsVal == NULL)
	{
		return -1;
	}

	*piDsVal = m_piDsInfo[nDsIdx];
	return 0;
}

int NFShmIdx::SetDsInfo(short nDsIdx, int iDsVal)
{
	if (nDsIdx < 0 || nDsIdx >= MAXDSINFOITEM)
	{
		return -1;
	}

	m_piDsInfo[nDsIdx] = iDsVal;
	return 0;
}

int NFShmIdx::ClearDsInfo()
{
	int i;

	for (i = 0; i < MAXDSINFOITEM; i++)
	{
		m_piDsInfo[i] = IDXNULL;
	}

	return 0;
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

void NFShmIdx::SetAttachedObj(NFShmObj *pObj)
{
	assert(pObj);
	m_uEntity.m_pAttachedObj = pObj;
}

short NFShmIdx::IsUsed()
{
	return m_nUseFlag;
}

int NFShmIdx::GetNextIdx()
{
	return m_iNextIdx;
}

void NFShmIdx::SetNextIdx(int iIdx)
{
	m_iNextIdx = iIdx;
}

int NFShmIdx::GetPrevIdx()
{
	return m_iPrevIdx;
}

void NFShmIdx::SetPrevIdx(int iIdx)
{
	m_iPrevIdx = iIdx;
}

void NFShmIdx::SetUsed()
{
	m_nUseFlag = 1;
}

void NFShmIdx::SetFree()
{
	m_nUseFlag = 0;
}
