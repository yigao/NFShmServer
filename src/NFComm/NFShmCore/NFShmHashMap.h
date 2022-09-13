// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashMap.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFShmHashMap.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFShmMgr.h"
#include <cstring>

/**
*@file NFShmHashMap.h
*@利用Hash索引来实现的简单Map
*
*	节点个数需要预先指定大小，暂不支持在节点用完时动态扩展的能力
*/

const int DEFAULT_HASH_MAP_NODE_SIZE = 1024; //!<默认HashMap可容纳节点个数
const int DEFAULT_HASH_MAP_SIZE = 1024; //!<默认Hash表大小，这个值越大冲突越小

typedef enum enmHashNodeUseFlag
{
    EHNF_NOT_USED = 0, //!<Hash节点未使用
    EHNF_USED = 1, //!<Hash节点已使用
} ENMHASHNODEUSEFLAG;

template <typename KEY_TYPE>
class CDefaultHashKeyCmp
{
public:
    CDefaultHashKeyCmp() {}
    ~CDefaultHashKeyCmp() {}

public:
    bool operator() (const KEY_TYPE& rstKey1, const KEY_TYPE& rstKey2);
};

template <typename KEY_TYPE>
bool CDefaultHashKeyCmp<KEY_TYPE>::operator() (const KEY_TYPE& rstKey1, const KEY_TYPE& rstKey2)
{
    if(rstKey1 == rstKey2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//!三个模板值，Key是主键类型，T是数据类型，NODE_SIZE是数据最大的大小，需要预先分配，HASH_SIZE是Hash表大小
template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE = DEFAULT_HASH_MAP_NODE_SIZE,
        int HASH_SIZE = NODE_SIZE, typename CMP_FUNC = CDefaultHashKeyCmp<KEY_TYPE>>
class NFShmHashMap
{
    typedef struct tagHashMapNode
    {
        KEY_TYPE m_stKey; //!<节点主键值，根据这个Key计算出Hash值来找到节点
        DATA_TYPE m_stData; //!<存放数据
        char m_cUseFlag; //!<节点是否使用
        int m_iHashNext; //!<当Hash值冲突值，将新加节点放在节点后面，形成冲突链
    } THashMapNode;

public:
    NFShmHashMap();
    ~NFShmHashMap();
    int CreateInit();
    int ResumeInit();
    int Initialize();
public:
    ////!通过数组下标的方式获取值（这里类似STL的Map如果发现该Key值的节点不存在会插入）
    ////TBD 由于不做异常机制，暂时不实现
    //DATA_TYPE& operator[](const KEY_TYPE& rstKeyval);

    //!指定Key值来获取数据指针，如果不存在则返回NULL，否则直接返回数据的指针
    DATA_TYPE* Find(const KEY_TYPE& rstKeyval, int *pOutSlotIdx = NULL);

    //!指定索引值来获取数据指针，一般用于遍历中
    DATA_TYPE* GetByIndex(int iDataIdx);
    KEY_TYPE* GetKeyByIndex(int iDataIdx);

    //!指定Key值来插入一个数据（如果有相同Key值的节点存在，则失败）
    int Insert(const KEY_TYPE& rstKeyval, const DATA_TYPE& rstData, int *pOutSlotIdx = NULL);
    DATA_TYPE* Insert(const KEY_TYPE& rstKeyval, int *pOutSlotIdx = NULL);

    //!指定Key值来更新一个数据（如果未发现该Key值的数据则不做任何事）
    int Update(const KEY_TYPE& rstKeyval, const DATA_TYPE& rstData, int *pOutSlotIdx = NULL);

    //!指定Key值来更新一个数据（如果未发现该Key值的数据则插入一个数据）
    int Replace(const KEY_TYPE& rstKeyval, const DATA_TYPE& rstData, int *pOutSlotIdx = NULL);

    //!获取已用节点个数
    int GetUsedNum() const { return m_iUsedNodeNum; }

    //!获取可用节点个数
    int GetFreeNum() const { return NODE_SIZE - m_iUsedNodeNum; }

	bool IsFull() const { return m_iUsedNodeNum >= NODE_SIZE; }

	bool IsEmpty() const { return m_iUsedNodeNum <= 0; }

	int GetFirstFreeIndex() const { return m_iFirstFreeIdx;  }

    //!获取总共的节点个数
    int GetSize() const { return NODE_SIZE; }

    //!清除所有节点
    int Erase();

    //!清除对应Key的节点
    int Erase(const KEY_TYPE& rstKey, int *pOutSlotIdx = NULL);

    //add by shichaolin 按索引删除
    int EraseBySID(int iSlotIdx, KEY_TYPE *pOutKey = NULL);

	DATA_TYPE* GetFirstUsedData()
	{
		for (int i = 0; i < NODE_SIZE; i++)
		{
			DATA_TYPE* pNode = GetByIndex(i);
			if (pNode)
			{
				return pNode;
			}
		}

		return NULL;
	}
private:
    //!将数据Key值通过Hash转换成索引
    int HashKeyToIndex(const KEY_TYPE& rstKey, int& riIndex) const;

private:
    int m_iUsedNodeNum; //!<已经使用的节点个数
    int m_iFirstFreeIdx; //!<空闲链表头节点
    THashMapNode m_astHashMap[NODE_SIZE]; //!<所有存放的数据节点
    int m_aiHashFirstIdx[HASH_SIZE]; //!<通过Key来Hash计算出的冲突链表的头节点索引
};

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::NFShmHashMap()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::CreateInit()
{
    Initialize();
    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::ResumeInit()
{
    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Initialize()
{
    m_iUsedNodeNum = 0;
    m_iFirstFreeIdx = 0;

    int i;
    for(i = 0; i < NODE_SIZE; ++i)
    {
        m_astHashMap[i].m_iHashNext = i + 1;
        m_astHashMap[i].m_cUseFlag = EHNF_NOT_USED;
    }

    m_astHashMap[NODE_SIZE-1].m_iHashNext = -1;

    for(i = 0; i < HASH_SIZE; ++i)
    {
        m_aiHashFirstIdx[i] = -1;
    }
    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::~NFShmHashMap()
{
    Erase();
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Erase()
{
    m_iUsedNodeNum = 0;
    m_iFirstFreeIdx = 0;

    int i;
    for(i = 0; i < NODE_SIZE; ++i)
    {
        m_astHashMap[i].m_iHashNext = i + 1;
        m_astHashMap[i].m_cUseFlag = EHNF_NOT_USED;
        m_astHashMap[i].m_stKey.KEY_TYPE::~KEY_TYPE();
        m_astHashMap[i].m_stData.DATA_TYPE::~DATA_TYPE();
    }

    m_astHashMap[NODE_SIZE-1].m_iHashNext = -1;

    for(i = 0; i < HASH_SIZE; ++i)
    {
        m_aiHashFirstIdx[i] = -1;
    }

    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
DATA_TYPE* NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::GetByIndex(int iDataIdx)
{
    if(iDataIdx < 0 || iDataIdx >= NODE_SIZE)
    {
        return NULL;
    }

    if(m_astHashMap[iDataIdx].m_cUseFlag == EHNF_USED)
    {
        return &m_astHashMap[iDataIdx].m_stData;
    }
    else
    {
        return NULL;
    }
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
KEY_TYPE* NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::GetKeyByIndex(int iDataIdx)
{
    if(iDataIdx < 0 || iDataIdx >= NODE_SIZE)
    {
        return NULL;
    }

    if(m_astHashMap[iDataIdx].m_cUseFlag == EHNF_USED)
    {
        return &m_astHashMap[iDataIdx].m_stKey;
    }
    else
    {
        return NULL;
    }
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::EraseBySID(int iSlotIdx, KEY_TYPE *pOutKey)
{
    //int iHashIdx = 0;
    if(iSlotIdx < 0 || iSlotIdx >= NODE_SIZE || m_astHashMap[iSlotIdx].m_cUseFlag != EHNF_USED)
    {
        return -1;
    }
    if(pOutKey)
    {
        memcpy(pOutKey, &(m_astHashMap[iSlotIdx].m_stKey), sizeof(KEY_TYPE));
    }
    return Erase(m_astHashMap[iSlotIdx].m_stKey);
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Erase(const KEY_TYPE& rstKeyval, int *pOutSlotIdx)
{
    int iHashIdx = 0;
    HashKeyToIndex(rstKeyval, iHashIdx);

    if(iHashIdx < 0 || iHashIdx >= HASH_SIZE )
    {
        return -1;
    }

    int iPreIndex = -1;
    int iCurIndex = m_aiHashFirstIdx[iHashIdx];
    CMP_FUNC stCmpFunc;

    while(iCurIndex != -1)
    {
        //已经存在该Key则返回失败
        if(stCmpFunc(rstKeyval, m_astHashMap[iCurIndex].m_stKey))
        {
            break;
        }

        iPreIndex = iCurIndex;
        iCurIndex = m_astHashMap[iCurIndex].m_iHashNext;
    }

    //找到需要删除的节点
    if(iCurIndex != -1)
    {
        //是冲突链表头节点
        if(m_aiHashFirstIdx[iHashIdx] == iCurIndex)
        {
            m_aiHashFirstIdx[iHashIdx] = m_astHashMap[iCurIndex].m_iHashNext;
        }
            //将上一个节点的Next索引等于当前要删除节点的Next索引
        else
        {
            m_astHashMap[iPreIndex].m_iHashNext = m_astHashMap[iCurIndex].m_iHashNext;
        }

        m_astHashMap[iCurIndex].m_cUseFlag = EHNF_NOT_USED;
        m_astHashMap[iCurIndex].m_iHashNext = m_iFirstFreeIdx;
        m_astHashMap[iCurIndex].m_stKey.KEY_TYPE::~KEY_TYPE();
        m_astHashMap[iCurIndex].m_stData.DATA_TYPE::~DATA_TYPE();
        m_iFirstFreeIdx = iCurIndex;
        --m_iUsedNodeNum;
        //add by shichaolin
        if(pOutSlotIdx)
        {
            *pOutSlotIdx = iCurIndex;
        }
    }

    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Insert(const KEY_TYPE& rstKeyval, const DATA_TYPE& rstData, int *pOutSlotIdx )
{
    int iHashIdx = 0;
    HashKeyToIndex(rstKeyval, iHashIdx);

    if(iHashIdx < 0 || iHashIdx >= HASH_SIZE)
    {
        return -1;
    }

    //已经没有可用的节点了
    if(m_iFirstFreeIdx < 0)
    {
        return -2;
    }

    int iPreIndex = -1;
    int iCurIndex = m_aiHashFirstIdx[iHashIdx];
    CMP_FUNC stCmpFunc;

    while(iCurIndex != -1)
    {
        //已经存在该Key则返回失败
        if(stCmpFunc(rstKeyval, m_astHashMap[iCurIndex].m_stKey))
        {
            return -3;
        }

        iPreIndex = iCurIndex;
        iCurIndex = m_astHashMap[iCurIndex].m_iHashNext;
    }

    int iNowAssignIdx = m_iFirstFreeIdx;
    m_iFirstFreeIdx = m_astHashMap[m_iFirstFreeIdx].m_iHashNext;
    ++m_iUsedNodeNum;
    memcpy(&m_astHashMap[iNowAssignIdx].m_stKey, &rstKeyval, sizeof(rstKeyval));
    new (&m_astHashMap[iNowAssignIdx].m_stData)DATA_TYPE();
    memcpy(&m_astHashMap[iNowAssignIdx].m_stData, &rstData, sizeof(rstData));
    m_astHashMap[iNowAssignIdx].m_cUseFlag = EHNF_USED;
    m_astHashMap[iNowAssignIdx].m_iHashNext = -1;

    //是冲突链表的第一个节点
    if(m_aiHashFirstIdx[iHashIdx] == -1)
    {
        m_aiHashFirstIdx[iHashIdx] = iNowAssignIdx;
    }
    else
    {
        m_astHashMap[iPreIndex].m_iHashNext = iNowAssignIdx;
    }
    //add by shichaolin
    if(pOutSlotIdx)
    {
        *pOutSlotIdx = iNowAssignIdx;
    }

    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
DATA_TYPE* NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Insert(const KEY_TYPE& rstKeyval, int *pOutSlotIdx )
{
    int iHashIdx = 0;
    HashKeyToIndex(rstKeyval, iHashIdx);

    if(iHashIdx < 0 || iHashIdx >= HASH_SIZE)
    {
        return NULL;
    }

    //已经没有可用的节点了
    if(m_iFirstFreeIdx < 0)
    {
        return NULL;
    }

    int iPreIndex = -1;
    int iCurIndex = m_aiHashFirstIdx[iHashIdx];
    CMP_FUNC stCmpFunc;

    while(iCurIndex != -1)
    {
        //已经存在该Key则返回失败
        if(stCmpFunc(rstKeyval, m_astHashMap[iCurIndex].m_stKey))
        {
            return NULL;
        }

        iPreIndex = iCurIndex;
        iCurIndex = m_astHashMap[iCurIndex].m_iHashNext;
    }

    int iNowAssignIdx = m_iFirstFreeIdx;
    m_iFirstFreeIdx = m_astHashMap[m_iFirstFreeIdx].m_iHashNext;
    ++m_iUsedNodeNum;
    memcpy(&m_astHashMap[iNowAssignIdx].m_stKey, &rstKeyval, sizeof(rstKeyval));
    new (&m_astHashMap[iNowAssignIdx].m_stData)DATA_TYPE();
    //DATA_TYPE rstData;
    //memcpy(&m_astHashMap[iNowAssignIdx].m_stData, &rstData, sizeof(rstData));
    m_astHashMap[iNowAssignIdx].m_cUseFlag = EHNF_USED;
    m_astHashMap[iNowAssignIdx].m_iHashNext = -1;

    //是冲突链表的第一个节点
    if(m_aiHashFirstIdx[iHashIdx] == -1)
    {
        m_aiHashFirstIdx[iHashIdx] = iNowAssignIdx;
    }
    else
    {
        m_astHashMap[iPreIndex].m_iHashNext = iNowAssignIdx;
    }
    //add by shichaolin
    if(pOutSlotIdx)
    {
        *pOutSlotIdx = iNowAssignIdx;
    }

    return &m_astHashMap[iNowAssignIdx].m_stData;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Update(const KEY_TYPE& rstKeyval, const DATA_TYPE& rstData,  int *pOutSlotIdx )
{
    //mdy by shichaolin
    DATA_TYPE* pstData = Find(rstKeyval, pOutSlotIdx);

    if(pstData == NULL)
    {
        return -1;
    }

    memcpy(pstData, &rstData, sizeof(rstData));

    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Replace(const KEY_TYPE& rstKeyval, const DATA_TYPE& rstData,  int *pOutSlotIdx )
{
    int iHashIdx = 0;
    HashKeyToIndex(rstKeyval, iHashIdx);

    if(iHashIdx < 0 || iHashIdx >= HASH_SIZE)
    {
        return -1;
    }

    int iPreIndex = -1;
    int iCurIndex = m_aiHashFirstIdx[iHashIdx];
    CMP_FUNC stCmpFunc;

    while(iCurIndex != -1)
    {
        //已经存在该Key则直接更新
        if(stCmpFunc(rstKeyval, m_astHashMap[iCurIndex].m_stKey))
        {
            memcpy(&m_astHashMap[iCurIndex].m_stKey, &rstKeyval, sizeof(rstKeyval));
            memcpy(&m_astHashMap[iCurIndex].m_stData, &rstData, sizeof(rstData));

            return 0;
        }

        iPreIndex = iCurIndex;
        iCurIndex = m_astHashMap[iCurIndex].m_iHashNext;
    }

    //已经没有可用的节点了
    if(m_iFirstFreeIdx < 0)
    {
        return -2;
    }

    int iNowAssignIdx = m_iFirstFreeIdx;
    m_iFirstFreeIdx = m_astHashMap[m_iFirstFreeIdx].m_iHashNext;
    ++m_iUsedNodeNum;
    memcpy(&m_astHashMap[iNowAssignIdx].m_stKey, &rstKeyval, sizeof(rstKeyval));
    memcpy(&m_astHashMap[iNowAssignIdx].m_stData, &rstData, sizeof(rstData));
    m_astHashMap[iNowAssignIdx].m_cUseFlag = EHNF_USED;
    m_astHashMap[iNowAssignIdx].m_iHashNext = -1;

    //是冲突链表的第一个节点
    if(m_aiHashFirstIdx[iHashIdx] == -1)
    {
        m_aiHashFirstIdx[iHashIdx] = iNowAssignIdx;
    }
    else
    {
        m_astHashMap[iPreIndex].m_iHashNext = iNowAssignIdx;
    }
    //add by shichaolin
    if(pOutSlotIdx)
    {
        *pOutSlotIdx = iNowAssignIdx;
    }
    return 0;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
DATA_TYPE* NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::Find(const KEY_TYPE& rstKeyval,  int *pOutSlotIdx )
{
    int iHashIdx = 0;
    HashKeyToIndex(rstKeyval, iHashIdx);

    if(iHashIdx < 0 || iHashIdx >= HASH_SIZE)
    {
        return NULL;
    }

    int iCurIndex = m_aiHashFirstIdx[iHashIdx];
    CMP_FUNC stCmpFunc;

    while(iCurIndex != -1)
    {
        if(stCmpFunc(rstKeyval, m_astHashMap[iCurIndex].m_stKey))
        {
            //add by shichaolin
            if(pOutSlotIdx)
            {
                *pOutSlotIdx = iCurIndex;
            }
            return &m_astHashMap[iCurIndex].m_stData;
        }

        iCurIndex = m_astHashMap[iCurIndex].m_iHashNext;
    }


    return NULL;
}

template <typename KEY_TYPE, typename DATA_TYPE, int NODE_SIZE, int HASH_SIZE, typename CMP_FUNC>
int NFShmHashMap<KEY_TYPE, DATA_TYPE, NODE_SIZE, HASH_SIZE, CMP_FUNC>::HashKeyToIndex(const KEY_TYPE& rstKey, int& riIndex) const
{
    size_t uiKeyLength = sizeof(rstKey);
    unsigned int uiHashSum = 0;
    unsigned int *piTemp = (unsigned int*)&rstKey;

    //目前Hash算法实现比较简单只是将Key值的每个字节的值加起来并对SIZE取模
    unsigned int i;
    for( i = 0; i < uiKeyLength / sizeof(unsigned int); ++i)
    {
        uiHashSum += piTemp[i];
    }

    if(uiKeyLength % sizeof(unsigned int) > 0)
    {
        unsigned char* pByte = (unsigned char*)&rstKey;
        pByte += (uiKeyLength - (uiKeyLength % sizeof(unsigned int)));
        unsigned int uiTemp = 0;
        memcpy((void *)&uiTemp, (const void *)pByte, uiKeyLength%sizeof(unsigned int));
        uiHashSum += uiTemp;
    }

    uiHashSum = (uiHashSum & ((unsigned int)0x7fffffff));

    riIndex = (int)(uiHashSum % HASH_SIZE);

    return 0;
}

