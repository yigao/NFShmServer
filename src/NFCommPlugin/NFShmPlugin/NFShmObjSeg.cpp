// -------------------------------------------------------------------------
//    @FileName         :    NFShmObjSeg.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFShmObjSeg.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFShmIdx.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

void *NFShmObjSeg::operator new(size_t nSize) throw()
{
	char *pTemp = (char *)(NFShmMgr::Instance()->CreateSegment(nSize));
	return (void *)pTemp;
}

void NFShmObjSeg::operator delete(void *pMem)
{
	return;
}
NFShmObjSeg::NFShmObjSeg()
{
}

int NFShmObjSeg::SetAndInitObj(size_t nObjSize, int iItemCount, NFShmObj * (*pfCreateObj)(void *), bool iUseHash, int externalDataSize, int externalItemCount)
{
	if (!NFShmMgr::Instance()->GetShmModule())
	{
		return -1;
	}

	m_nObjSize = nObjSize;
	m_iItemCount = iItemCount;
	m_iUseHash = iUseHash;
	m_iExternalDataSize = externalDataSize;
	m_iExternalItemCount = externalItemCount;
	m_iExternalBuffer = NULL;
	//TLib_Log_LogMsg("CObjSeg::%s objsize %d, count %d\n", __FUNCTION__, nObjSize, iItemCount);
	//printf("In CObjSeg::CObjSeg, ObjSize: %d nItemCount: %d\n", nObjSize, iItemCount);
	m_pIdxs = (NFShmIdx *)(NFShmMgr::Instance()->CreateSegment(m_iItemCount * sizeof(NFShmIdx)));
	m_pObjs = (NFShmObj *)(NFShmMgr::Instance()->CreateSegment(m_iItemCount * m_nObjSize));

	if (!m_pIdxs || !m_pObjs)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Allocated share mem not enough Program exit(1)\n");
		NFSLEEP(1000);
		exit(1);
		//return -1;
	}

    if (m_iUseHash)
    {
        m_iHashBuffer = (char*)(NFShmMgr::Instance()->CreateSegment(m_hashMgr.CountSize(m_iItemCount)));
        if (!m_iHashBuffer)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Allocated share mem not enough Program exit(1)\n");
            NFSLEEP(1000);
            exit(1);
        }
    }

    if (m_iExternalDataSize > 0)
    {
        m_iExternalBuffer = (char*)(NFShmMgr::Instance()->CreateSegment(m_iExternalDataSize));
        if (!m_iExternalBuffer)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Allocated share mem not enough Program exit(1)\n");
            NFSLEEP(1000);
            exit(1);
        }
    }

	m_pFn = pfCreateObj;

	if (NFShmMgr::Instance()->GetInitMode() == EN_OBJ_MODE_INIT)
	{
		NFShmMgr::Instance()->SetCreateMode(EN_OBJ_MODE_INIT);
		Initialize();

		if (m_iUseHash)
        {
            int ret = m_hashMgr.Init(m_iHashBuffer, m_iItemCount, true);
            if (ret)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "NFHashObjectMgr Init Failed!");
            }
        }
	}
	else
	{
		NFShmMgr::Instance()->SetCreateMode(EN_OBJ_MODE_RECOVER);
		RecoverIdx();
		FormatObj();

        if (m_iUseHash)
        {
            int ret = m_hashMgr.Init(m_iHashBuffer, m_iItemCount, false);
            if (ret)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "NFHashObjectMgr Init Failed!");
            }
        }
	}

	return 0;
}

NFShmObjSeg::~NFShmObjSeg()
{
	//no-op
}

NFShmObj* NFShmObjSeg::GetObj(int iIdx)
{
	return (likely(iIdx >= 0 && iIdx < m_iItemCount && m_pIdxs[iIdx].IsUsed())) ? m_pIdxs[iIdx].GetAttachedObj() : NULL;
}

//added by xxxx
NFShmObj* NFShmObjSeg::GetObjFast(int iIdx) 
{ 
	return m_pIdxs[iIdx].IsUsed() ? m_pIdxs[iIdx].GetAttachedObj() : NULL; 
}

int NFShmObjSeg::Initialize()
{
	m_nIsFormated = 0;
	m_iFreeHead = -1;
	m_iUsedHead = -1;
	m_iUsedCount = 0;

	if (FormatIdx())
	{
		return -1;
	}

	m_nIsFormated = 1;
	return 0;
}

int NFShmObjSeg::FormatIdx()
{
	m_iFreeHead = 0;
	m_iUsedHead = -1;
	m_pIdxs[m_iFreeHead].Initialize();
	m_pIdxs[m_iFreeHead].SetPrevIdx(-1);

	for (int i = 1; i < m_iItemCount; i++)
	{
		m_pIdxs[i].Initialize();
		m_pIdxs[i - 1].SetNextIdx(i);
		m_pIdxs[i].SetPrevIdx(i - 1);
	}

	m_pIdxs[m_iItemCount - 1].SetNextIdx(-1);

	for (int i = 0; i < m_iItemCount; i++)
	{
		m_pIdxs[i].SetObjBuf(((char *)m_pObjs + m_nObjSize * i));
	}

	return 0;
}

int NFShmObjSeg::RecoverIdx()
{
	return 0;
}

int NFShmObjSeg::FormatObj()
{
	for (int i = 0; i < m_iItemCount; i++)
	{
		if (m_pIdxs[i].IsUsed())
		{
			m_pFn(((char *)m_pObjs + m_nObjSize * i));
		}
		m_pIdxs[i].SetObjBuf(((char *)m_pObjs + m_nObjSize * i));
	}

	return 0;
}

int NFShmObjSeg::HashAlloc(uint64_t key, int globalId)
{
    int index = m_hashMgr.HashAlloc(key);
    if (index >= 0)
    {
        int& newId = m_hashMgr[index];
        newId = globalId;
    }
    return index;
}

NFShmObj* NFShmObjSeg::HashFind(uint64_t key, int iType)
{
    int index = m_hashMgr.HashFind(key);
    if (index >= 0)
    {
        int globalId = m_hashMgr[index];
        return NFShmMgr::Instance()->GetObjFromGlobalID(globalId, iType, 1);
    }
    return NULL;
}

int NFShmObjSeg::HashErase(int hashId)
{
    return m_hashMgr.HashFreeByIndex(hashId);
}

NFHashObjectMgr<uint64_t, int>& NFShmObjSeg::GetHashMgr()
{
    return m_hashMgr;
}

void *NFShmObjSeg::AllocMemForObject()
{
	int iTempIdx = CreateIdx();

	if (iTempIdx < 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "AllocMemForObject failed! NFObjSeg alloc error ");
		return NULL;
	}

	return m_pIdxs[iTempIdx].GetObjBuf();
}

void NFShmObjSeg::FreeMemForObject(void *pMem)
{
	int iIdx = 0;
	iIdx = GetObjId((NFShmObj *)pMem);

	if (iIdx >= 0)
	{
		DestroyIdx(iIdx);
	}
}

int NFShmObjSeg::GetRunMode()
{
#ifdef MAKE_FOR_DB_CHECK_CGI
	return EN_OBJ_MODE_INIT;
#else
	return NFShmMgr::Instance()->GetInitMode();
#endif
}

int NFShmObjSeg::GetHashSize(int objCount)
{
    return NFHashObjectMgr<uint64_t, int>::CountSize(objCount);
}

int NFShmObjSeg::CreateIdx()
{
	int iTempIdx = -1;

	if (m_iUsedCount >= m_iItemCount ||
		m_iFreeHead < 0 ||
		m_iFreeHead >= m_iItemCount)
	{
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateIdx failed! usedCount:{} allCount:{}, freeHead:{}", m_iUsedCount, m_iItemCount, m_iFreeHead);
		return -1;
	}

	iTempIdx = m_iFreeHead;
	m_iFreeHead = m_pIdxs[iTempIdx].GetNextIdx();

	if (m_iFreeHead >= 0)
	{
		m_pIdxs[m_iFreeHead].SetPrevIdx(-1);
	}

	m_pIdxs[iTempIdx].SetUsed();
	m_pIdxs[iTempIdx].SetNextIdx(m_iUsedHead);
	m_pIdxs[iTempIdx].SetPrevIdx(-1);

	if (m_iUsedHead >= 0)
	{
		m_pIdxs[m_iUsedHead].SetPrevIdx(iTempIdx);
	}

	m_iUsedHead = iTempIdx;
	m_pIdxs[iTempIdx].ClearDsInfo();
	m_iUsedCount++;
	return iTempIdx;
}

int NFShmObjSeg::DestroyIdx(int iIdx)
{
	if (iIdx >= m_iItemCount || iIdx < 0 || m_iItemCount <= 0)
	{
		return -1;
	}

	if (!m_pIdxs[iIdx].IsUsed())
	{
		return -2;
	}

	if (iIdx == m_iUsedHead)
	{
		m_iUsedHead = m_pIdxs[iIdx].GetNextIdx();
	}

	if (m_pIdxs[iIdx].GetNextIdx() >= 0)
	{
		m_pIdxs[m_pIdxs[iIdx].GetNextIdx()].SetPrevIdx(m_pIdxs[iIdx].GetPrevIdx());
	}

	if (m_pIdxs[iIdx].GetPrevIdx() >= 0)
	{
		m_pIdxs[m_pIdxs[iIdx].GetPrevIdx()].SetNextIdx(m_pIdxs[iIdx].GetNextIdx());
	}

	m_pIdxs[iIdx].SetFree();
	m_pIdxs[iIdx].SetPrevIdx(-1);
	m_pIdxs[iIdx].SetNextIdx(m_iFreeHead);

	if (m_iFreeHead >= 0)
	{
		m_pIdxs[m_iFreeHead].SetPrevIdx(iIdx);
	}

	m_iFreeHead = iIdx;
	m_iUsedCount--;
	return iIdx;
}

NFShmIdx *NFShmObjSeg::GetIdx(int iIdx)
{
	if (iIdx < 0 || iIdx >= m_iItemCount)
	{
		return NULL;
	}

	if (!m_pIdxs[iIdx].IsUsed())
	{
		return NULL;
	}

	return &m_pIdxs[iIdx];
}

NFShmObj *NFShmObjSeg::GetHeadObj()
{
	return GetObj(m_iUsedHead);
}

NFShmObj *NFShmObjSeg::GetNextObj(NFShmObj *pObj)
{
	int iIdx = -1;
	int iNextIdx = -1;
	iIdx = GetObjId(pObj);

	if (iIdx < 0)
	{
		return NULL;
	}

	iNextIdx = m_pIdxs[iIdx].GetNextIdx();

	if (iNextIdx < 0)
	{
		return NULL;
	}

	return GetObj(iNextIdx);
}

bool NFShmObjSeg::IsEnd(int iIndex)
{
	if (iIndex >= m_iItemCount)
		return true;
	else
		return false;
}

int  NFShmObjSeg::GetObjId(void *pstObj)
{
	int iIdx;

	if (!pstObj || (char *)pstObj < (char *)m_pObjs || ((char *)pstObj > (char *)((char *)m_pObjs + m_iItemCount * m_nObjSize)))
	{
		return -1;
	}

	iIdx = ((char *)pstObj - (char *)m_pObjs) / m_nObjSize;

	if ((((char *)pstObj - (char *)m_pObjs) % m_nObjSize) != 0)
	{
		return -1;
	}

	return iIdx;
}

int  NFShmObjSeg::CreateObject()
{
	void *pBuff = NULL;
	int iTempIdx = -1;
	pBuff = AllocMemForObject();

	if (!pBuff)
	{
		return iTempIdx;
	}

	m_pFn(pBuff);
	iTempIdx = GetObjId(pBuff);
	return iTempIdx;
}

