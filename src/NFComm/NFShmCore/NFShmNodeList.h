// -------------------------------------------------------------------------
//    @FileName         :    NFShmNodeList.h
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmNodeList
//
// -------------------------------------------------------------------------

#pragma once

#include "NFRawShmObj.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"

// 链表对象类
// 此对象需要继承NFShmObj类
// 方便共享内存对象的链表管理
class NFIListNodeObj
{
public:
    virtual ~NFIListNodeObj() {}

    NFIListNodeObj()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        } else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_iPrevNode = INVALID_ID;
        m_iNextNode = INVALID_ID;
        m_iListCheckID = INVALID_ID;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int GetPrevNode() const
    {
        return m_iPrevNode;
    }

    void SetPrevNode(int iNode)
    {
        m_iPrevNode = iNode;
    }

    int GetNextNode() const
    {
        return m_iNextNode;
    }

    void SetNextNode(int iNode)
    {
        m_iNextNode = iNode;
    }

    int GetListCheckID() const
    {
        return m_iListCheckID;
    }

    void SetListCheckID(int iListCheckID)
    {
        m_iListCheckID = iListCheckID;
    }

    static int GetListCheckIDSeq();

public:
    static int s_iListCheckIDSeq;
    int m_iListCheckID;
    int m_iPrevNode;
    int m_iNextNode;
};

template<class NodeObjType>
class NFListNodeObjWithObjectID : public NFIListNodeObj
{
public:
    virtual ~NFListNodeObjWithObjectID() {}

    static NodeObjType *GetObjByListNodeID(NFIPluginManager *pPluginManager, int iListNodeID)
    {
        return NodeObjType::GetObjectByID(pPluginManager, iListNodeID);
    }

    int GetListNodeID()
    {
        return dynamic_cast<NodeObjType *>( this )->GetObjId();
    }
};

template<class NodeObjType, int CLASSTYPE>
class NFListNodeObjWithGlobalID : public NFIListNodeObj
{
public:
    virtual ~NFListNodeObjWithGlobalID() {}

    static NodeObjType *GetObjByListNodeID(NFIPluginManager *pPluginManager, int iListNodeID)
    {
        return (NodeObjType *) pPluginManager->FindModule<NFISharedMemModule>()->GetObjByGlobalId(CLASSTYPE, iListNodeID, true);
    }

    int GetListNodeID()
    {
        return dynamic_cast<NodeObjType *>( this )->GetGlobalId();
    }
};



template<class NodeObjType>
class NFListNodeObjWithUserID : public NFIListNodeObj
{
public:
    virtual ~NFListNodeObjWithUserID() {}
    //请自己实现
    //static NodeObjType* GetObjByListNodeID(int iListNodeID);
    //int GetListNodeID();
};

//双向列表
template<class NodeObjType>
class NFShmNodeObjList : public NFRawShmObj
{
public:
    NFShmNodeObjList()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        } else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        InitNodeList();
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    void InitNodeList()
    {
        m_iNodeCount = 0;
        m_iHeadNode = INVALID_ID;
        m_iTailNode = INVALID_ID;
        m_iListCheckID = NFIListNodeObj::GetListCheckIDSeq();
    }

    bool IsEmpty() const
    {
        return m_iNodeCount <= 0;
    }

    bool Empty() const
    {
        return IsEmpty();
    }

    int GetNodeCount() const
    {
        return m_iNodeCount;
    }

    int GetHeadNodeID() const
    {
        return m_iHeadNode;
    }

    int GetTailNodeID() const
    {
        return m_iTailNode;
    }

    int GetLastCheckID() const
    {
        return m_iListCheckID;
    }

    NodeObjType *GetHeadNodeObj()
    {
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (m_iHeadNode != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), m_iHeadNode);
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed, m_iHeadNode:{}", m_iHeadNode);
            return pObj;
        }

        return NULL;
    }

    NodeObjType *GetTailNodeObj()
    {
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (m_iTailNode != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), m_iTailNode);
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed, m_iTailNode:{}", m_iTailNode);
            return pObj;
        }

        return NULL;
    }

    NodeObjType *GetPrevNodeObj(NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, NULL, "");
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (pNode && pNode->GetPrevNode() != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), pNode->GetPrevNode());
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed");
            return pObj;
        }

        return NULL;
    }

    NodeObjType *GetNextNodeObj(NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, NULL, "");
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (pNode && pNode->GetNextNode() != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), pNode->GetNextNode());
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed");
            return pObj;
        }

        return NULL;
    }

    int AddNode(NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetPrevNode() == INVALID_ID, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetNextNode() == INVALID_ID, -1, "");
        //assert(pNode->GetListCheckID() == INVALID_ID);
        NodeObjType *pHead = GetHeadNodeObj();

        if (pHead)
        {
            pNode->SetNextNode(pHead->GetListNodeID());
            pHead->SetPrevNode(pNode->GetListNodeID());
        }
        else
        {
            CHECK_EXPR_ASSERT(0 == m_iNodeCount, -1, "");
            m_iTailNode = pNode->GetListNodeID();
        }

        pNode->SetListCheckID(m_iListCheckID);
        m_iHeadNode = pNode->GetListNodeID();
        m_iNodeCount++;
        return 0;
    }

    //加到列表的最后
    int AddNodeToTail(NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetPrevNode() == INVALID_ID, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetNextNode() == INVALID_ID, -1, "");
        //assert(pNode->GetListCheckID() == INVALID_ID);
        NodeObjType *pTail = GetTailNodeObj();

        if (pTail)
        {
            pTail->SetNextNode(pNode->GetListNodeID());
            pNode->SetPrevNode(pTail->GetListNodeID());
        }
        else
        {
            CHECK_EXPR_ASSERT(0 == m_iNodeCount, -1, "");
            m_iHeadNode = pNode->GetListNodeID();
        }

        pNode->SetListCheckID(m_iListCheckID);
        m_iTailNode = pNode->GetListNodeID();
        m_iNodeCount++;
        return 0;
    }

    int RemoveNode(NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, -1, "");
        CHECK_EXPR_ASSERT(m_iNodeCount > 0, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetListCheckID() == m_iListCheckID, -1, "");
        NodeObjType *pPrevNode = GetPrevNodeObj(pNode);

        if (pPrevNode)
        {
            pPrevNode->SetNextNode(pNode->GetNextNode());
        }

        NodeObjType *pNextNode = GetNextNodeObj(pNode);

        if (pNextNode)
        {
            pNextNode->SetPrevNode(pNode->GetPrevNode());
        }

        if (pNode->GetListNodeID() == m_iHeadNode)
        {
            m_iHeadNode = pNode->GetNextNode();
        }

        if (pNode->GetListNodeID() == m_iTailNode)
        {
            m_iTailNode = pNode->GetPrevNode();
        }

        pNode->SetNextNode(INVALID_ID);
        pNode->SetPrevNode(INVALID_ID);
        pNode->SetListCheckID(INVALID_ID);
        m_iNodeCount--;
        return 0;
    }

    bool IsExistNode(NodeObjType *pNode)
    {
        return pNode->GetListCheckID() == m_iListCheckID;
    }
private:
    int m_iListCheckID;
    int m_iNodeCount;
    int m_iHeadNode;
    int m_iTailNode;
};

// 链表对象类
// 此对象需要继承NFShmObj类
// 方便共享内存对象的链表管理
template<size_t MAX_TYPE>
class NFIMultiListNodeObj
{
public:
    virtual ~NFIMultiListNodeObj() {}

    NFIMultiListNodeObj()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        } else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        for(int i = 0; i < (int)MAX_TYPE; i++)
        {
            m_objList[i].CreateInit();
        }
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int GetPrevNode(int typeIndex) const
    {
        CHECK_EXPR_ASSERT(typeIndex >= 0 && typeIndex < (int)MAX_TYPE, -1, "typeIndex:{} max:{}", typeIndex, MAX_TYPE);
        return m_objList[typeIndex].m_iPrevNode;
    }

    void SetPrevNode(int typeIndex, int iNode)
    {
        CHECK_EXPR_ASSERT(typeIndex >= 0 && typeIndex < (int)MAX_TYPE, , "typeIndex:{} max:{}", typeIndex, MAX_TYPE);
        m_objList[typeIndex].m_iPrevNode = iNode;
    }

    int GetNextNode(int typeIndex) const
    {
        CHECK_EXPR_ASSERT(typeIndex >= 0 && typeIndex < (int)MAX_TYPE, -1, "typeIndex:{} max:{}", typeIndex, MAX_TYPE);
        return m_objList[typeIndex].m_iNextNode;
    }

    void SetNextNode(int typeIndex, int iNode)
    {
        CHECK_EXPR_ASSERT(typeIndex >= 0 && typeIndex < (int)MAX_TYPE, , "typeIndex:{} max:{}", typeIndex, MAX_TYPE);
        m_objList[typeIndex].m_iNextNode = iNode;
    }

    int GetListCheckID(int typeIndex) const
    {
        CHECK_EXPR_ASSERT(typeIndex >= 0 && typeIndex < (int)MAX_TYPE, -1, "typeIndex:{} max:{}", typeIndex, MAX_TYPE);
        return m_objList[typeIndex].m_iListCheckID;
    }

    void SetListCheckID(int typeIndex, int iListCheckID)
    {
        CHECK_EXPR_ASSERT(typeIndex >= 0 && typeIndex < (int)MAX_TYPE, , "typeIndex:{} max:{}", typeIndex, MAX_TYPE);
        m_objList[typeIndex].m_iListCheckID = iListCheckID;
    }

protected:
    NFIListNodeObj m_objList[MAX_TYPE];
};

template<class NodeObjType, int CLASSTYPE, size_t MAX_TYPE>
class NFMultiListNodeObjWithGlobalID : public NFIMultiListNodeObj<MAX_TYPE>
{
public:
    virtual ~NFMultiListNodeObjWithGlobalID() {}

    static NodeObjType *GetObjByListNodeID(NFIPluginManager *pPluginManager, int typeIndex, int iListNodeID)
    {
        return (NodeObjType *) pPluginManager->FindModule<NFISharedMemModule>()->GetObjByGlobalId(CLASSTYPE, iListNodeID, true);
    }

    int GetListNodeID(int typeIndex)
    {
        return dynamic_cast<NodeObjType *>( this )->GetGlobalId();
    }
};

//双向列表
template<class NodeObjType>
class NFShmNodeObjMultiList : public NFRawShmObj
{
public:
    NFShmNodeObjMultiList()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        } else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        InitNodeList();
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    NFShmNodeObjMultiList(const NFShmNodeObjMultiList<NodeObjType>& list)
    {
        if (this != &list)
        {
            m_iListCheckID = list.m_iListCheckID;
            m_iNodeCount = list.m_iNodeCount;
            m_iHeadNode = list.m_iHeadNode;
            m_iTailNode = list.m_iTailNode;
        }
    }

    void InitNodeList()
    {
        m_iNodeCount = 0;
        m_iHeadNode = INVALID_ID;
        m_iTailNode = INVALID_ID;
        m_iListCheckID = NFIListNodeObj::GetListCheckIDSeq();
    }

    int GetNodeCount() const
    {
        return m_iNodeCount;
    }

    bool IsEmpty() const
    {
        return m_iNodeCount <= 0;
    }

    bool Empty() const
    {
        return IsEmpty();
    }

    int GetHeadNodeID() const
    {
        return m_iHeadNode;
    }

    int GetTailNodeID() const
    {
        return m_iTailNode;
    }

    int GetLastCheckID() const
    {
        return m_iListCheckID;
    }

    NodeObjType *GetHeadNodeObj(int typeIndex)
    {
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (m_iHeadNode != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), typeIndex, m_iHeadNode);
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed, m_iHeadNode:{}", m_iHeadNode);
            return pObj;
        }

        return NULL;
    }

    NodeObjType *GetTailNodeObj(int typeIndex)
    {
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (m_iTailNode != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), typeIndex, m_iTailNode);
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed, m_iTailNode:{}", m_iTailNode);
            return pObj;
        }

        return NULL;
    }

    NodeObjType *GetPrevNodeObj(int typeIndex, NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, NULL, "");
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (pNode && pNode->GetPrevNode(typeIndex) != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), typeIndex, pNode->GetPrevNode(typeIndex));
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed");
            return pObj;
        }

        return NULL;
    }

    NodeObjType *GetNextNodeObj(int typeIndex, NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, NULL, "");
        CHECK_EXPR_ASSERT(GetPluginManager(), NULL, "");
        if (pNode && pNode->GetNextNode(typeIndex) != INVALID_ID)
        {
            NodeObjType *pObj = NodeObjType::GetObjByListNodeID(GetPluginManager(), typeIndex, pNode->GetNextNode(typeIndex));
            CHECK_EXPR_ASSERT(pObj, NULL, "GetObjByListNodeID Failed");
            return pObj;
        }

        return NULL;
    }

    int AddNode(int typeIndex, NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetPrevNode(typeIndex) == INVALID_ID, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetNextNode(typeIndex) == INVALID_ID, -1, "");
        //assert(pNode->GetListCheckID() == INVALID_ID);
        NodeObjType *pHead = GetHeadNodeObj(typeIndex);

        if (pHead)
        {
            pNode->SetNextNode(typeIndex, pHead->GetListNodeID(typeIndex));
            pHead->SetPrevNode(typeIndex, pNode->GetListNodeID(typeIndex));
        }
        else
        {
            CHECK_EXPR_ASSERT(0 == m_iNodeCount, -1, "");
            m_iTailNode = pNode->GetListNodeID(typeIndex);
        }

        pNode->SetListCheckID(typeIndex, m_iListCheckID);
        m_iHeadNode = pNode->GetListNodeID(typeIndex);
        m_iNodeCount++;
        return 0;
    }

    //加到列表的最后
    int AddNodeToTail(int typeIndex, NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetPrevNode(typeIndex) == INVALID_ID, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetNextNode(typeIndex) == INVALID_ID, -1, "");
        //assert(pNode->GetListCheckID() == INVALID_ID);
        NodeObjType *pTail = GetTailNodeObj(typeIndex);

        if (pTail)
        {
            pTail->SetNextNode(typeIndex, pNode->GetListNodeID(typeIndex));
            pNode->SetPrevNode(typeIndex, pTail->GetListNodeID(typeIndex));
        }
        else
        {
            CHECK_EXPR_ASSERT(0 == m_iNodeCount, -1, "");
            m_iHeadNode = pNode->GetListNodeID(typeIndex);
        }

        pNode->SetListCheckID(typeIndex, m_iListCheckID);
        m_iTailNode = pNode->GetListNodeID(typeIndex);
        m_iNodeCount++;
        return 0;
    }

    int RemoveNode(int typeIndex, NodeObjType *pNode)
    {
        CHECK_EXPR_ASSERT(pNode, -1, "");
        CHECK_EXPR_ASSERT(m_iNodeCount > 0, -1, "");
        CHECK_EXPR_ASSERT(pNode->GetListCheckID(typeIndex) == m_iListCheckID, -1, "");
        NodeObjType *pPrevNode = GetPrevNodeObj(typeIndex, pNode);

        if (pPrevNode)
        {
            pPrevNode->SetNextNode(typeIndex, pNode->GetNextNode(typeIndex));
        }

        NodeObjType *pNextNode = GetNextNodeObj(typeIndex, pNode);

        if (pNextNode)
        {
            pNextNode->SetPrevNode(typeIndex, pNode->GetPrevNode(typeIndex));
        }

        if (pNode->GetListNodeID(typeIndex) == m_iHeadNode)
        {
            m_iHeadNode = pNode->GetNextNode(typeIndex);
        }

        if (pNode->GetListNodeID(typeIndex) == m_iTailNode)
        {
            m_iTailNode = pNode->GetPrevNode(typeIndex);
        }

        pNode->SetNextNode(typeIndex, INVALID_ID);
        pNode->SetPrevNode(typeIndex, INVALID_ID);
        pNode->SetListCheckID(typeIndex, INVALID_ID);
        m_iNodeCount--;
        return 0;
    }

    bool IsExistNode(NodeObjType *pNode, int typeIndex)
    {
        return pNode->GetListCheckID(typeIndex) == m_iListCheckID;
    }

private:
    int m_iListCheckID;
    int m_iNodeCount;
    int m_iHeadNode;
    int m_iTailNode;
};