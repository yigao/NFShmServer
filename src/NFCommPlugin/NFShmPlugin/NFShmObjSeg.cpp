// -------------------------------------------------------------------------
//    @FileName         :    NFShmObjSeg.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFShmObjSeg.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFShmIdx.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

void *NFShmObjSeg::operator new(size_t nSize, void *pBuffer) throw()
{
    return pBuffer;
}

void NFShmObjSeg::operator delete(void *pMem)
{
    return;
}

NFShmObjSeg *NFShmObjSeg::CreateObject(NFIPluginManager *pPluginManager)
{
    void *pVoid = (void *) (pPluginManager->FindModule<NFISharedMemModule>()->CreateSegment(sizeof(NFShmObjSeg)));
    NFShmObjSeg *pTmp = new(pVoid) NFShmObjSeg(pPluginManager);
    return pTmp;
}

NFShmObjSeg::NFShmObjSeg(NFIPluginManager *p) : NFObject(p)
{
}

int NFShmObjSeg::SetAndInitObj(size_t nObjSize, int iItemCount, NFShmObj *(*pfCreateObj)(NFIPluginManager *, void *), bool iUseHash)
{
    m_nObjSize = nObjSize;
    m_iItemCount = iItemCount;
    m_iUseHash = iUseHash;
    m_nMemSize = 0;
    m_pCreateFn = pfCreateObj;

    /**
     * @brief idx mem
     */
    size_t idxSize = 0;
    char *pIdxBuffer = NULL;
    {
        idxSize = NFShmDyList<NFShmIdx>::CountSize(m_iItemCount);
        pIdxBuffer = (char *) (m_pObjPluginManager->FindModule<NFISharedMemModule>()->CreateSegment(idxSize));
        if (!pIdxBuffer)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSegment Failed, Allocated share mem not enough Program exit(1)\n");
            NFSLEEP(1000);
            exit(1);
        }

        m_nMemSize += idxSize;
    }

    /**
     * @brief use hash mem
     */
    size_t hashSize = 0;
    char *pHashBuffer = NULL;
    if (m_iUseHash)
    {
        hashSize = m_hashMgr.CountSize(m_iItemCount);
        pHashBuffer = (char *) (m_pObjPluginManager->FindModule<NFISharedMemModule>()->CreateSegment(hashSize));
        if (!pHashBuffer)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSegment Failed, Allocated share mem not enough Program exit(1)\n");
            NFSLEEP(1000);
            exit(1);
        }

        m_nMemSize += hashSize;
    }

    size_t objSize = m_iItemCount * m_nObjSize;
    m_pObjs = (NFShmObj *) (m_pObjPluginManager->FindModule<NFISharedMemModule>()->CreateSegment(objSize));
    if (!m_pObjs)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSegment Failed, Allocated share mem not enough Program exit(1)\n");
        NFSLEEP(1000);
        exit(1);
    }
    m_nMemSize += objSize;


    if (m_pObjPluginManager->FindModule<NFISharedMemModule>()->GetInitMode() == EN_OBJ_MODE_INIT)
    {
        NFShmMgr::Instance()->SetCreateMode(EN_OBJ_MODE_INIT);
        m_pObjPluginManager->FindModule<NFISharedMemModule>()->SetCreateMode(EN_OBJ_MODE_INIT);
        NFShmMgr::Instance()->SetAddrOffset(m_pObjPluginManager->FindModule<NFISharedMemModule>()->GetAddrOffset());

        int iRet = m_idxLst.Init(pIdxBuffer, idxSize, m_iItemCount, true);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_idxLst.Init Program exit(1)\n");
            NFSLEEP(1000);
            exit(1);
        }

        if (m_iUseHash)
        {
            int iRet = m_hashMgr.Init(pHashBuffer, hashSize, m_iItemCount, true);
            if (iRet != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_hashMgr.Init Program exit(1)\n");
                NFSLEEP(1000);
                exit(1);
            }
        }
    }
    else
    {
        NFShmMgr::Instance()->SetCreateMode(EN_OBJ_MODE_RECOVER);
        m_pObjPluginManager->FindModule<NFISharedMemModule>()->SetCreateMode(EN_OBJ_MODE_RECOVER);
        NFShmMgr::Instance()->SetAddrOffset(m_pObjPluginManager->FindModule<NFISharedMemModule>()->GetAddrOffset());
        int iRet = m_idxLst.Init(pIdxBuffer, idxSize, m_iItemCount, false);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_idxLst.Init Program exit(1)\n");
            NFSLEEP(1000);
            exit(1);
        }
        FormatObj();

        if (m_iUseHash)
        {
            int iRet = m_hashMgr.Init(pHashBuffer, hashSize, m_iItemCount, false);
            if (iRet != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_hashMgr.Init Program exit(1)\n");
                NFSLEEP(1000);
                exit(1);
            }
        }
    }

    return 0;
}

NFShmObjSeg::~NFShmObjSeg()
{
    //no-op
}

NFShmObj *NFShmObjSeg::GetObj(int iIdx)
{
    auto pNode = m_idxLst.GetNode(iIdx);
    return (likely(pNode && pNode->m_valid)) ? pNode->m_data.GetAttachedObj() : NULL;
}

int NFShmObjSeg::FormatObj()
{
    for (auto iter = m_idxLst.begin(); iter != m_idxLst.end(); iter++)
    {
        iter->SetObjBuf(((char *) m_pObjs + m_nObjSize * iter.m_node->m_self));
        m_pCreateFn(m_pObjPluginManager, ((char *) m_pObjs + m_nObjSize * iter.m_node->m_self));
    }

    return 0;
}

int NFShmObjSeg::HashInsert(uint64_t key, int objId)
{
    auto iter = m_hashMgr.find(key);
    if (iter == m_hashMgr.end())
    {
        iter = m_hashMgr.emplace_hint(key, objId);
        if (iter != m_hashMgr.end())
        {
            return 0;
        }
    }

    return INVALID_ID;
}

NFShmObj *NFShmObjSeg::HashFind(uint64_t key)
{
    auto iter = m_hashMgr.find(key);
    if (iter != m_hashMgr.end())
    {
        int objId = iter->second;
        return GetObj(objId);
    }

    return NULL;
}

int NFShmObjSeg::HashErase(uint64_t key)
{
    size_t count = m_hashMgr.erase(key);
    if (count > 0)
    {
        return 0;
    }

    return -1;
}

void *NFShmObjSeg::AllocMemForObject()
{
    NFShmIdx *pIdx = CreateIdx();

    if (pIdx == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "AllocMemForObject failed! NFObjSeg alloc error ");
        return NULL;
    }

    return pIdx->GetObjBuf();
}

void NFShmObjSeg::FreeMemForObject(void *pMem)
{
    int iIdx = 0;
    iIdx = GetObjId((NFShmObj *) pMem);

    if (iIdx >= 0)
    {
        DestroyIdx(iIdx);
    }
}

NFShmIdx *NFShmObjSeg::CreateIdx()
{
    auto iter = m_idxLst.insert(m_idxLst.end());
    if (iter == m_idxLst.end())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateIdx failed! usedCount:{} allCount:{}", m_idxLst.size(), m_idxLst.max_size());
        return NULL;
    }

    iter->SetObjBuf(((char *) m_pObjs + m_nObjSize * iter.m_node->m_self));
    return &(*iter);
}

int NFShmObjSeg::DestroyIdx(int iIdx)
{
    auto pNode = m_idxLst.GetNode(iIdx);
    if (pNode == NULL)
    {
        return -1;
    }

    if (!pNode->m_valid)
    {
        return -2;
    }

    m_idxLst.erase(m_idxLst.GetIterator(pNode));
    return iIdx;
}

NFShmIdx *NFShmObjSeg::GetIdx(int iIdx)
{
    auto pNode = m_idxLst.GetNode(iIdx);
    if (pNode == NULL)
    {
        return NULL;
    }

    if (!pNode->m_valid)
    {
        return NULL;
    }

    return &pNode->m_data;
}

NFShmObj *NFShmObjSeg::GetHeadObj()
{
    auto iter = m_idxLst.begin();
    if (iter == m_idxLst.end())
    {
        return NULL;
    }

    return iter->GetAttachedObj();
}

NFShmObj *NFShmObjSeg::GetNextObj(NFShmObj *pObj)
{
    int iIdx = -1;
    iIdx = GetObjId(pObj);
    if (iIdx < 0)
    {
        return NULL;
    }

    auto pNode = m_idxLst.GetNode(iIdx);
    if (pNode == NULL || !pNode->m_valid)
    {
        return NULL;
    }

    auto pNextNode = m_idxLst.GetNode(pNode->m_next);
    if (pNextNode == NULL || !pNextNode->m_valid)
    {
        return NULL;
    }

    return pNextNode->m_data.GetAttachedObj();
}

bool NFShmObjSeg::IsEnd(int iIndex)
{
    if (iIndex >= m_iItemCount)
        return true;
    else
        return false;
}

int NFShmObjSeg::GetObjId(void *pstObj)
{
    int iIdx;

    if (!pstObj || (char *) pstObj < (char *) m_pObjs || ((char *) pstObj > (char *) ((char *) m_pObjs + m_iItemCount * m_nObjSize)))
    {
        return -1;
    }

    iIdx = ((char *) pstObj - (char *) m_pObjs) / m_nObjSize;

    if ((((char *) pstObj - (char *) m_pObjs) % m_nObjSize) != 0)
    {
        return -1;
    }

    return iIdx;
}

int NFShmObjSeg::CreateObject()
{
    void *pBuff = NULL;
    int iTempIdx = -1;
    pBuff = AllocMemForObject();

    if (!pBuff)
    {
        return iTempIdx;
    }

    m_pCreateFn(m_pObjPluginManager, pBuff);
    iTempIdx = GetObjId(pBuff);
    return iTempIdx;
}

