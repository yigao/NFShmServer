// -------------------------------------------------------------------------
//    @FileName         :    NFObjSeg.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmHashObjectMgr.h"
#include "NFComm/NFPluginModule/NFObject.h"
#include "NFComm/NFShmCore/NFArray.h"

class NFShmObj;

class NFShmIdx;

#define MAX_NF_SHM_OBJ_SEG_INDEX_COUNT 10

class NFShmObjSeg : public NFObject
{
    friend class NFCSharedMemModule;

public:
    static void *operator new(size_t nSize, void *pBuffer) throw();

    static NFShmObjSeg *CreateObject(NFIPluginManager *pPluginManager);

    static void operator delete(void *pSeg);


    int Initialize();

    int FormatIdx();                        //格式化索引区
    int RecoverIdx();                        //恢复索引区
    int FormatObj();                        //格式化对象区

    void *AllocMemForObject();

    void FreeMemForObject(void *pMem);

    NFShmObj *GetObj(int iIdx);

    int HashAlloc(uint64_t key, int globalId);

    NFShmObj *HashFind(uint64_t key, int iType);

    int HashErase(int hashId);

    NFShmHashObjectMgr<uint64_t, int> &GetHashMgr();

    NFShmObj *CreateIndexToHashKey(uint32_t indexId, uint64_t indexKey, uint64_t hashKey, int iType);

    NFShmObj *GetObjByIndexKey(uint32_t indexId, uint64_t indexKey, int iType);

    int CreateIndexByKeyValue(uint32_t indexId, uint64_t indexKey, uint64_t indexValue);

    uint64_t* GetIndexValueByIndexKey(uint32_t indexId, uint64_t indexKey);

    NFShmHashObjectMgr<uint64_t, uint64_t> &GetIndexMgr(uint32_t indexId);

    //added by xxxx
    NFShmObj *GetObjFast(int iIdx);

    NFShmIdx *GetIdx(int iIdx);

    int GetObjId(void *pstObj);

    NFShmObj *GetHeadObj();

    NFShmObj *GetNextObj(NFShmObj *pObj);

    bool IsEnd(int iIndex);

    int GetItemCount() { return m_iItemCount; }

    int GetUsedCount() { return m_iUsedCount; }

    int GetUsedHead() { return m_iUsedHead; }

    int GetFreeHead() { return m_iFreeHead; }

    int GetFreeCount() { return m_iItemCount - m_iUsedCount; }

    int GetObjSize() { return m_nObjSize; }

    int CreateObject();

    static int GetHashSize(int objCount);

    static int GetIndexSize(int indexCount, int indexTime, int objCount);

protected:
    int CreateIdx();

    int DestroyIdx(int iIdx);

private:

    NFShmObjSeg(NFIPluginManager *p);

    ~NFShmObjSeg();

    int
    SetAndInitObj(size_t nObjSize, int iItemCount, NFShmObj *(*pfCreateObj)(NFIPluginManager *, void *), bool iUseHash = false, int indexCount = 0,
                  int indexTime = 1);

    short m_nIsFormated;
    size_t m_nObjSize;
    NFShmIdx *m_pIdxs;
    NFShmObj *m_pObjs;
    NFShmHashObjectMgr<uint64_t, int> m_hashMgr;
    NFArray<NFShmHashObjectMgr<uint64_t, uint64_t>, MAX_NF_SHM_OBJ_SEG_INDEX_COUNT> m_indexMgr;

    int m_iItemCount;
    int m_iFreeHead;
    int m_iUsedHead;
    int m_iUsedCount;
    bool m_iUseHash;
    char *m_iHashBuffer;
    int m_iIndexCount;
    int m_iIndexTime;
    NFArray<char *, MAX_NF_SHM_OBJ_SEG_INDEX_COUNT> m_iIndexBuffer;

    NFShmObj *(*m_pFn)(NFIPluginManager *, void *);
};


