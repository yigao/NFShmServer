// -------------------------------------------------------------------------
//    @FileName         :    NFShmObjectMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFShmObjectMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFCheck.h"

/**
* Object和Buffer管理器的基类, 核心逻辑
* 每个Object都有iIndexCount个CTList结构，这些结构可以组成若干个链表\n
* 例如已分配的Object是一个链表，未分配的Object在另外一个链表\n
* CTList共有  iObjectCount* iIndexCount个\n
* CTListInfo共有 iListCount * iIndexCount个
*/
class NFObjectMgrBase
{
public:
    /**
    * Index链表的头部.
    * @note CTListInfo和CTList一样大，便于在某些情况下把CTList作为CTListInfo使用
    */
    class NFListInfo
    {
    public:
        int		iHead;  ///< 链表头元素在数组中下标
        int		iTail;  ///< 链表尾元素在数组中下标
        int		iSize;  ///< 链表中共有多少个元素

        NFListInfo() : iHead(-1), iTail(-1), iSize(0) {}

        void Init()
        {
            iHead = -1;
            iTail = -1;
            iSize = 0;
        }
    };

    /**
    * 用来组成链表的结构
    */
    class NFList
    {
    public:
        int		iPrev;  ///< 链表中我的前一个元素在数组中下标
        int		iNext;  ///< 链表中我的后一个元素在数组中下标
        int		iFlag;  ///< 用来表示我在哪个链表中，空闲链表？已分配链表？还是其他链表？

        NFList() : iPrev(-1), iNext(-1), iFlag(0) {}

        void Init()
        {
            iPrev = -1;
            iNext = -1;
            iFlag = 0;
        }
    };

public:
    NFObjectMgrBase() :
            m_iObjectCount(0),
            m_iObjectSize(0),
            m_iListCount(0),
            m_iIndexCount(0),
            m_pstInfo(0),
            m_pstList(0),
            m_pDataBuffer(0)
    {
    }

    virtual ~NFObjectMgrBase()
    {
    }

protected:
    /**
    * 初始化.
    * 这个初始化是protected的，请使用继承类
    * 内存在外部分配好了传进来，需要多大空间用CountSize()计算
    * @param[in] pBuffer: CTObjectMgr所用的内存是从外面传进来的, 这里不分配内存
    * @param[in] iOjbectCount: T的个数
    * @param[in] iObjectSize: 应该等于Size(T), 如果T是char*, 那么就是字符串期望分配的大小
    * @param[in] iListCount: 每个索引中可以存在iListCount个链表
    * @param[in] iIndexCount: 索引的个数
    */
    virtual int Init(const char* pBuffer, int iObjectCount, int iObjectSize, bool bResetShm = true, int iListCount = 2, int iIndexCount = 1)
    {
        NF_ASSERT(!(!pBuffer || iObjectCount <= 0 || iObjectSize <= 0 || iListCount < 2 || iIndexCount < 1));
        if (!pBuffer || iObjectCount <= 0 || iObjectSize <= 0 || iListCount < 2 || iIndexCount < 1)
        {

            return -1;
        }

        const size_t iCountSize = CountSize(iObjectCount, iObjectSize, iListCount, iIndexCount);

        m_iObjectCount = iObjectCount;
        m_iObjectSize = iObjectSize;
        m_iListCount = iListCount;
        m_iIndexCount = iIndexCount;

        m_pstInfo = (NFListInfo*) (pBuffer);
        m_pstList = (NFList*) (pBuffer + sizeof(NFListInfo) * m_iListCount * m_iIndexCount);
        m_pDataBuffer = (char*) pBuffer + sizeof(NFListInfo) * m_iListCount * m_iIndexCount
                        + sizeof(NFList) * m_iObjectCount * m_iIndexCount;

        if (bResetShm)
        {
            memset((void*)pBuffer, 0, iCountSize);
            // 默认的, 所有结点都在0号链表中, 0号链表必须是空闲结点链表
            for (int iIndexID = 0; iIndexID < m_iIndexCount; ++iIndexID)
            {
                for (int i = 0; i < m_iListCount; ++i)
                {
                    ListInfo(i, iIndexID).Init();
                }

                BuildInfoList(ListInfo(0, iIndexID), 0, iIndexID);
            }
        }

        return 0;
    }

public:
    /**
    * 计算所用内存的大小
    */
    static size_t CountSize(int iObjectCount, int iObjectSize, int iListCount = 2, int iIndexCount = 1)
    {
        return sizeof(NFListInfo) * iListCount * iIndexCount
               + sizeof(NFList) * iObjectCount * iIndexCount
               + iObjectCount * iObjectSize;
    }

public:
    //=================================
    // InfoList相关操作

    /**
    * 把iIndexID索引初始化成InfoList链表.
    * 链表的ListID就是iListID
    */
    void BuildInfoList(NFListInfo& stListInfo, int iListID, int iIndexID = 0)
    {
        for (int i = 0; i < m_iObjectCount; ++i)
        {
            Prev(i, iIndexID) = i - 1;
            Next(i, iIndexID) = i + 1;
            Flag(i, iIndexID) = iListID;
        }
        Next(m_iObjectCount - 1, iIndexID) = -1;

        stListInfo.iHead = 0;
        stListInfo.iTail = m_iObjectCount - 1;
        stListInfo.iSize = m_iObjectCount;
    }

    /**
    * 简化的分配一个可用元素.
    * 从0号链表中分配一个元素到iNewListID号链表
    * 这个函数要求ListInfo不能是外部的
    * @param[in] iNewListID 分配到几号链表？必须大与0
    * @return 成功就返回分配元素的数组下标，失败时返回-1
    */
    int InfoListAlloc(int iIndexID, int iNewListID)
    {
        if (iIndexID < 0 || iIndexID >= m_iIndexCount || iNewListID < 0 || iNewListID >= m_iListCount)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "InfoListAlloc error : invalid index id({}) or new list id({})", iIndexID, iNewListID);
            return -1;
        }

        return InfoListAlloc(iIndexID, iNewListID,
                             ListInfo(0, iIndexID),
                             ListInfo(iNewListID, iIndexID));
    }

    /**
    * 简化的InfoList中将节点i移到新链表.
    * 这个函数要求ListInfo不能是外部的
    * @note 如果已在这号链表中 会加入到链表的最后
    */
    int InfoListMove(int i, int iIndexID, int iNewListID)
    {
        if (iIndexID < 0 || iIndexID >= m_iIndexCount || iNewListID < 0 || iNewListID >= m_iListCount)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "InfoListMove error : invalid index id({}) or new list id({})", iIndexID, iNewListID);
            return -1;
        }

        return InfoListMove(i, iIndexID, iNewListID,
                            ListInfo(Flag(i, iIndexID), iIndexID),
                            ListInfo(iNewListID, iIndexID));
    }

private:
    /**
    * 从链表中删除的逻辑.
    * 把节点i从stListInfo链表中删除
    * @note stListInfo从外部传入，链表头尾的存放可以更灵活
    */
    void InfoListRemove(NFListInfo& stListInfo, int i, int iIndexID)
    {
        if (Prev(i, iIndexID) == -1)
        {
            if (Next(i, iIndexID) == -1)
            {
                stListInfo.iHead = -1;
                stListInfo.iTail = -1;
            }
            else
            {
                stListInfo.iHead = Next(i, iIndexID);
                Prev(Next(i, iIndexID), iIndexID) = -1;
            }
        }
        else
        {
            if (Next(i, iIndexID) == -1)
            {
                stListInfo.iTail = Prev(i, iIndexID);
                Next(Prev(i, iIndexID), iIndexID) = -1;
            }
            else
            {
                Prev(Next(i, iIndexID), iIndexID) = Prev(i, iIndexID);
                Next(Prev(i, iIndexID), iIndexID) = Next(i, iIndexID);
            }
        }
        --stListInfo.iSize;

        if (stListInfo.iSize > 0)
        {
            NF_ASSERT(stListInfo.iHead > -1);
        }
        else
        {
            NF_ASSERT(stListInfo.iHead == -1);
        }
    }

    /**
    * 加入到链表的逻辑.
    * 把节点i加入到stListInfo链表中
    * @note stListInfo从外部传入，链表头尾的存放可以更灵活
    */
    void InfoListAppend(NFListInfo& stListInfo, int i, int iIndexID)
    {
        if (stListInfo.iHead == -1 || stListInfo.iTail == -1)
        {
            Prev(i, iIndexID) = -1;
            Next(i, iIndexID) = -1;
            stListInfo.iHead = i;
            stListInfo.iTail = i;
        }
        else
        {
            Next(stListInfo.iTail, iIndexID) = i;
            Prev(i, iIndexID) = stListInfo.iTail;
            Next(i, iIndexID) = -1;
            stListInfo.iTail = i;
        }
        ++stListInfo.iSize;
        if (stListInfo.iSize > 0)
        {
            NF_ASSERT(stListInfo.iHead > -1);
        }
    }

    /**
    * InfoList中将节点i移到新链表
    * @note 如果已在这号链表中 会加入到链表的最后
    */
    int InfoListMove(int i, int iIndexID, int iNewListID, NFListInfo& stOldList, NFListInfo& stNewList)
    {
        if (stOldList.iSize <= 0)
        {
            return -1;
        }

        if (i < 0 || i >= m_iObjectCount)
        {
            return -2;
        }

        if (iIndexID < 0 || iIndexID >= m_iIndexCount)
        {
            return -3;
        }

        if (&m_pstInfo[Flag(i, iIndexID) + iIndexID * m_iListCount] != &stOldList)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "index({}) list is {}, index id is {}, not in old list", i, Flag(i, iIndexID) + iIndexID * m_iListCount, iIndexID);
            return -4;
        }

        Flag(i, iIndexID) = iNewListID;

        InfoListRemove(stOldList, i, iIndexID);
        InfoListAppend(stNewList, i, iIndexID);

        if (Flag(i, iIndexID) != iNewListID)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "InfoListMove error, flag changed");
        }

        if (Next(i, iIndexID) != -1)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "InfoListMove error, next is not -1");
        }

        if (Prev(i, iIndexID) == -1) //头节点
        {
            if (Head(iNewListID, iIndexID) != i)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "InfoListMove error, head error");
            }
        }
        else
        {
            if (Flag(Prev(i, iIndexID), iIndexID) != iNewListID)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "InfoListMove error, prev is not in this list");
            }
        }

        return 0;
    }

public:
    /**
    * 分配一个可用元素.
    * 从0号链表中分配一个元素到iNewLstID号链表
    * @param[in] iNewListID 分配到几号链表？必须大与0
    * @return 成功就返回分配元素的数组下标，失败时返回-1
    */
    int InfoListAlloc(int iIndexID, int iNewListID, NFListInfo& stOldList, NFListInfo& stNewList)
    {
        if (stOldList.iSize <= 0)
        {
            return -1;
        }

        int i = stOldList.iHead;
        int iRet = InfoListMove(i, iIndexID, iNewListID, stOldList, stNewList);
        if (iRet)
        {
            return iRet;
        }

        return i;
    }

    /**
    * EachList中将节点i加入到iBrother所在的链表
    */
    int EachListAppend(int i, int iIndexID, int iBrother)
    {
        int iTail = iBrother;
        int iNow = Next(iTail, iIndexID);
        while (iNow != -1 && iNow != iBrother)  // iNow != iBrother用来避免双向链表的死循环
        {
            iTail = iNow;
            iNow = Next(iNow, iIndexID);
        }

        if (iNow != -1)
        {
            return -1;
        }

        Next(iTail, iIndexID) = i;

        Prev(i, iIndexID) = iTail;
        Next(i, iIndexID) = -1;
        return 0;
    }

    /**
    * EachList中将节点i从原来的链表中释放掉
    */
    int EachListRemove(int i, int iIndexID)
    {
        if (Prev(i, iIndexID) == -1)
        {
            if (Next(i, iIndexID) == -1)
            {
                return 0;   // 已经释放了
            }
            else
            {
                Prev(Next(i, iIndexID), iIndexID) = -1;
            }
        }
        else
        {
            if (Next(i, iIndexID) == -1)
            {
                Next(Prev(i, iIndexID), iIndexID) = -1;
            }
            else
            {
                Prev(Next(i, iIndexID), iIndexID) = Prev(i, iIndexID);
                Next(Prev(i, iIndexID), iIndexID) = Next(i, iIndexID);
            }
        }

        Prev(i, iIndexID) = -1;
        Next(i, iIndexID) = -1;
        return 0;
    }

    //=================================
    // EachList相关操作

    /**
    * 把iIndexID索引初始化为EachList链表
    */
    void BuildEachList(int iIndexID)
    {
        for (int i = 0; i < m_iObjectCount; ++i)
        {
            List(i, iIndexID).Init();
        }
    }

public:
    const char* GetBuffer() const { return (const char*)m_pstInfo; }
    int GetObjectCount() const { return m_iObjectCount; }
    int GetObjectSize() const { return m_iObjectSize; }
    int GetListCount() const { return m_iListCount; }
    int GetIndexCount() const { return m_iIndexCount; }

public:
    int Head(int iListID, int iIndexID = 0) const
    {
        return ListInfo(iListID, iIndexID).iHead;
    }

    int Tail(int iListID, int iIndexID = 0) const
    {
        return ListInfo(iListID, iIndexID).iTail;
    }

    int Size(int iListID, int iIndexID = 0) const
    {
        return ListInfo(iListID, iIndexID).iSize;
    }

    // List 操作
    int Prev(int i, int iIndexID = 0) const
    {
        return List(i, iIndexID).iPrev;
    }

    int Next(int i, int iIndexID = 0) const
    {
        return List(i, iIndexID).iNext;
    }

    int Flag(int i, int iIndexID = 0) const
    {
        return List(i, iIndexID).iFlag;
    }

    int& Size(int iListID, int iIndexID = 0)
    {
        return ListInfo(iListID, iIndexID).iSize;
    }

    // ListInfo 操作
    const NFListInfo& ListInfo(int iListID, int iIndexID = 0) const
    {
        return m_pstInfo[iIndexID * m_iListCount + iListID];
    }

    NFListInfo& ListInfo(int iListID, int iIndexID = 0)
    {
        NF_ASSERT(iIndexID * m_iListCount + iListID < m_iIndexCount * m_iListCount);
        return m_pstInfo[iIndexID * m_iListCount + iListID];
    }

    const NFList& List(int i, int iIndexID = 0) const
    {
        return m_pstList[iIndexID * m_iObjectCount + i];
    }

    int& Flag(int i, int iIndexID = 0)
    {
        return List(i, iIndexID).iFlag;
    }

    int& Next(int i, int iIndexID = 0)
    {
        return List(i, iIndexID).iNext;
    }

    int& Prev(int i, int iIndexID = 0)
    {
        return List(i, iIndexID).iPrev;
    }

    NFList& List(int i, int iIndexID = 0)
    {
        return m_pstList[iIndexID * m_iObjectCount + i];
    }

    int& Tail(int iListID, int iIndexID = 0)
    {
        return ListInfo(iListID, iIndexID).iTail;
    }

    int& Head(int iListID, int iIndexID = 0)
    {
        return ListInfo(iListID, iIndexID).iHead;
    }

protected:
    int				m_iObjectCount;
    int				m_iObjectSize;
    int				m_iListCount;
    int				m_iIndexCount;

    NFListInfo*		m_pstInfo;
    NFList*			m_pstList;
    char*			m_pDataBuffer;
};

template<typename T>
class NFObjectMgr : public NFObjectMgrBase
{
public:
    virtual ~NFObjectMgr() {}

    virtual int Init(const char* pBuffer, int iObjectCount, bool bResetShm = true, int iObjectSize = sizeof(T), int iListCount = 2, int iIndexCount = 1)
    {
        int iRet = NFObjectMgrBase::Init(pBuffer, iObjectCount, iObjectSize, bResetShm, iListCount, iIndexCount);
        if (iRet)
        {
            return iRet;
        }

        m_astObject = (T*)m_pDataBuffer;

        return 0;
    }

    T& operator[] (int i)
    {
        return m_astObject[i];
    }

    const T& operator[] (int i) const
    {
        return m_astObject[i];
    }

protected:
    T*	m_astObject;
};