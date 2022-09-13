// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashObjectMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFShmHashObjectMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFShmObjectMgr.h"
#include <unordered_map>
#include "NFShmMgr.h"

/**
 * Hash元素初始化函数.
*/
template<typename TYPE>
struct CTHashObjInitor
{
    void operator()(TYPE* pstHashObj)
    {
        pstHashObj->~TYPE();
    }
};

template<>
struct CTHashObjInitor<int>
{
    void operator()(int* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<unsigned int>
{
    void operator()(unsigned int* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<char>
{
    void operator()(char* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<unsigned char>
{
    void operator()(unsigned char* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<short>
{
    void operator()(short* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<unsigned short>
{
    void operator()(unsigned short* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<int64_t>
{
    void operator()(int64_t* pstHashObj)
    {
        return;
    }
};

template<>
struct CTHashObjInitor<uint64_t>
{
    void operator()(uint64_t* pstHashObj)
    {
        return;
    }
};

/**
* 基于CTObjectMgr的Hash表
*/
/**
* Hash对象管理器.
* 模板参数类似gcc hashmap
*/
template<typename KEY,
        typename VALUE,
        typename HASH_FUNC = std::hash<KEY>,
        typename EQUAL_KEY = std::equal_to<KEY> >
class NFHashObjectMgr;

template<typename KEY,
        typename VALUE,
        typename HASH_FUNC,
        typename EQUAL_KEY>
class NFHashObjectMgr
{
public:
    typedef class tagPair
    {
    public:
        KEY     stKey;
        VALUE   stValue;

        tagPair()
        {
            if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
                CreateInit();
            } else {
                ResumeInit();
            }
        }

        //非继承函数, 不要加virtual
        int CreateInit()
        {
            return 0;
        }

        //非继承函数, 不要加virtual
        int ResumeInit()
        {
            return 0;
        }

        ~tagPair()
        {

        }
    }
    TPair;

    enum
    {
        ALLOC_INDEX = 0,    ///< 用来保存节点是否分配
        FREE_LIST = 0,
        USED_LIST = 1,

        HASH_INDEX = 1,     ///< 用来记录冲突链表
    };
    NFObjectMgr<TPair>  m_stMgr;    ///< 先设为public, 外部可能会用到索引链表操作
    typedef void(*pDumpFunc)(KEY& stKey, VALUE &stData);  ///< 外部用来dump Hash表中内容的函数
public:
    NFHashObjectMgr()
    {

    }

    virtual ~NFHashObjectMgr()
    {

    }

    /**
    * 计算需要多少空间.
    */
    static size_t CountSize(int iObjectCount, int iListCount = 2, int iIndexCount = 2)
    {
        return NFObjectMgr<TPair>::CountSize(iObjectCount, sizeof(TPair), iListCount, iIndexCount);
    }

    /**
    * 初始化.
    * @note
    * iIndexID=0 用来保存节点是否分配
    * iIndexID=1 用来记录冲突链表
    */
    virtual int Init(const char* pBuffer, int iObjectCount, bool bResetShm = true, int iListCount = 2, int iIndexCount = 2)
    {
        if (iIndexCount < 2 && iListCount < 2) // 至少要2个索引
        {
            return -1;
        }

        int iRet = m_stMgr.Init(pBuffer, iObjectCount, bResetShm, sizeof(TPair), iListCount, iIndexCount);
        if (iRet)
        {
            return iRet;
        }

        if (bResetShm)
        {
            m_stMgr.BuildEachList(HASH_INDEX);
            for (int i = 0; i < m_stMgr.GetObjectCount(); ++i)
            {
                m_stMgr.Flag(i, HASH_INDEX) = -1;
            }
        }
        else
        {
            for(int i = 0; i < GetObjectCount(); i++)
            {
                if (CheckIndexUsed(i))
                {
                    new (&m_stMgr[i])TPair();
                }
            }
        }

        return 0;
    }

    /**
    * 基于Hash的分配.
    * @param[in] stKey Key
    * @param[in] bFindExist 分配之前检查是否已存在
    * @return 返回的是分配的节点的下标
    */
    virtual int HashAlloc(const KEY& stKey, bool bFindExist = true)
    {
        if (bFindExist)
        {
            int i = HashFind(stKey);
            if (i >= 0) // 已存在就返回以前分配的下标
            {
                return i;
            }
        }

        // 分配的节点的Prev(iNew, HASH_INDEX) 必然是-1
        // Prev(iNew, HASH_INDEX)如果不是-1 表示这个节点以前是某个冲突链的头节点
        int iKey = HASH_FUNC()(stKey);
        iKey &= 0x7FFFFFFF;
        int iIndex = iKey % m_stMgr.GetObjectCount();
        int iRetIndex = iIndex;
        if (m_stMgr.Flag(iIndex, ALLOC_INDEX) == FREE_LIST) // 未分配
        {
            m_stMgr.InfoListMove(iIndex, ALLOC_INDEX, USED_LIST);
        }
        else
        {
            // 已经分配了
            // ALLOC_INDEX链可能有其它LIST，如果已经分配是否要放到USED_LIST中需要考虑 by will
            iRetIndex = m_stMgr.InfoListAlloc(ALLOC_INDEX, USED_LIST);
            if (iRetIndex < 0)  // 分配失败
            {
                return -1;
            }
        }

        if (m_stMgr.Flag(iIndex, HASH_INDEX) == -1)
        {
            m_stMgr.Flag(iIndex, HASH_INDEX) = iRetIndex;
        }
        else  // 后续冲突节点
        {
            int iRet = m_stMgr.EachListAppend(iRetIndex, HASH_INDEX,
                                              m_stMgr.Flag(iIndex, HASH_INDEX));
            if (iRet) // 调整冲突链条失败
            {
                return -1;
            }
        }

        m_stMgr[iRetIndex].stKey = stKey;
        new (&m_stMgr[iRetIndex].stValue)VALUE();

        return iRetIndex;
    }

    /**
    * 释放节点
    * @param[in] i 节点的下标
    * @return 释放成功返回0
    */
    virtual int HashFreeByIndex(int i)
    {
        if (i < 0 || i >= m_stMgr.GetObjectCount())
        {
            return -1;
        }

        CTHashObjInitor<VALUE>()(&(this->m_stMgr[i].stValue));
        memset(&m_stMgr[i].stValue, 0, sizeof(m_stMgr[i].stValue));

        if (m_stMgr.Flag(i, ALLOC_INDEX) == FREE_LIST)  // 状态不对
        {
            return -1;
        }

        int iRet = m_stMgr.InfoListMove(i, ALLOC_INDEX, FREE_LIST);
        if (iRet)
        {
            return iRet;
        }

        if (m_stMgr.Prev(i, HASH_INDEX) == -1) // 是冲突链表的头
        {
            int iKey = HASH_FUNC()(m_stMgr[i].stKey);
            iKey &= 0x7FFFFFFF;
            int iTempIndex = iKey % m_stMgr.GetObjectCount();
            m_stMgr.Flag(iTempIndex, HASH_INDEX) = m_stMgr.Next(i, HASH_INDEX);
        }

        return m_stMgr.EachListRemove(i, HASH_INDEX);
    }

    /**
    * 释放节点
    * @param[in] stKey 要释放的Key
    * @return 释放成功返回0
    */
    virtual int HashFreeByKey(const KEY& stKey)
    {
        int i = HashFind(stKey);
        return HashFreeByIndex(i);
    }

    /**
    * 按Key进行查找
    * @param[in] piFindCount 返回查找次数
    * @return 找到了就返回对应的下标, 否则就返回-1
    */
    virtual int HashFind(const KEY& stKey, int* piFindCount = NULL)
    {
        int iKey = HASH_FUNC()(stKey);
        iKey &= 0x7FFFFFFF;
        int i = iKey % m_stMgr.GetObjectCount();
        if (m_stMgr.Flag(i, HASH_INDEX) == -1) // 未分配  Flag(i, ALLOC_INDEX) == FREE_LIST &&
        {
            return -1;
        }

        int iFindCount = 0;
        int* piCount = (piFindCount ? piFindCount : &iFindCount);
        *piCount = 0;

        i = m_stMgr.Flag(i, HASH_INDEX);
        while (i >= 0)
        {
            ++(*piCount);
            if (m_stMgr.Flag(i, ALLOC_INDEX) != FREE_LIST &&  EQUAL_KEY()(stKey, m_stMgr[i].stKey))
            {
                //调整一下位置，将最近访问的放在最后
                m_stMgr.InfoListMove(i, ALLOC_INDEX, m_stMgr.Flag(i, ALLOC_INDEX));

                return i;
            }

            i = m_stMgr.Next(i, HASH_INDEX); // 移动下一个冲突节点
        }

        return -1;
    }

public:
    virtual VALUE& operator[] (int i)
    {
        NF_ASSERT(i >= 0 && i < m_stMgr.GetObjectCount());
        return m_stMgr[i].stValue;
    }

    virtual const VALUE& operator[] (int i) const
    {
        NF_ASSERT(i >= 0 && i < m_stMgr.GetObjectCount());
        return m_stMgr[i].stValue;
    }

    bool IsFull()
    {
        if (Size(USED_LIST) >= GetObjectCount())
        {
            return true;
        }
        return false;
    }

    bool IsEmpty()
    {
        if (Size(USED_LIST) == 0)
        {
            return true;
        }
        return false;
    }
public:
    int GetObjectCount() const
    {
        return m_stMgr.GetObjectCount();
    }

    int GetListCount() const
    {
        return m_stMgr.GetListCount();
    }

    int GetIndexCount() const
    {
        return m_stMgr.GetIndexCount();
    }

    int Size(int iListID) const
    {
        return m_stMgr.ListInfo(iListID).iSize;
    }

    virtual int GetHeadIndex()
    {
        return m_stMgr.Head(USED_LIST, ALLOC_INDEX);
    }

    virtual int GetNextIndex(int iIndex)
    {
        if (m_stMgr.Flag(iIndex, ALLOC_INDEX) == FREE_LIST)
        {
            return -1;
        }
        return m_stMgr.Next(iIndex, ALLOC_INDEX);
    }

    virtual int GetTailIndex()
    {
        return m_stMgr.Tail(USED_LIST, ALLOC_INDEX);
    }

    virtual int GetPrevIndex(int iIndex)
    {
        if (m_stMgr.Flag(iIndex, ALLOC_INDEX) == FREE_LIST)
        {
            return -1;
        }
        return m_stMgr.Prev(iIndex, ALLOC_INDEX);
    }

    virtual bool CheckIndexUsed(int iIndex)
    {
        if (m_stMgr.Flag(iIndex, ALLOC_INDEX) == FREE_LIST)
        {
            return false;
        }
        return true;
    }

    KEY GetKeyByIndex(int iIndex) const
    {
        return m_stMgr[iIndex].stKey;
    }

    void HashFreeHead()
    {
        HashFreeByIndex(GetHeadIndex());
    }

    void SwapHashByMaxCount(int iMaxCount)
    {
        if (Size(USED_LIST) < iMaxCount)
        {
            return;
        }

        while (Size(USED_LIST) > iMaxCount)
        {
            HashFreeByIndex(GetHeadIndex());
        }
    }

    /**
    *本意是Hash内已分配的数据都初始化
    */
    void HashClean()
    {
        int iIndex = GetHeadIndex();
        while (iIndex >= 0)
        {
            HashFreeByIndex(iIndex);
            iIndex = GetHeadIndex();
        }
    }

    /**导出hash表所有已分配的节点到指定函数里*/
    int DumpData(const pDumpFunc& pDf)
    {
        int iRetCounts = 0;
        int iIndex = GetHeadIndex();
        while(iIndex != -1)
        {
            pDf(GetKeyByIndex(iIndex), m_stMgr[iIndex].stValue);
            iIndex = GetNextIndex(iIndex);
            ++iRetCounts;
        }
        return iRetCounts;
    }
};
