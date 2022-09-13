// -------------------------------------------------------------------------
//    @FileName         :    NFShmStaticList.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include "NFComm/NFPluginModule/NFPair.h"
#include "NFShmMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"

struct ListNodeBase
{
	ptrdiff_t m_iNext;   ///< Self-explanatory
	ptrdiff_t m_iPrev;   ///< Self-explanatory
};

template<typename T>
struct ListNode : public ListNodeBase
{
	bool m_bValid;
	T m_data;                ///< User's data.
};

template<typename T, typename Container>
struct ListIterator
{
protected:
	typedef ListIterator<T, Container> _Self;
	typedef ListNode<T> _Node;
public:
	typedef ptrdiff_t DifferenceType;
	typedef T ValueType;
	typedef T *pointer;
	typedef T &Reference;
	typedef size_t SizeType;

	ListIterator()
		: m_pNode()
	{
	}

	explicit ListIterator(Container *pContainer, SizeType iPos)
		: m_pContainer(pContainer)
	{
		m_pNode = pContainer->GetNode(iPos);
	}

	explicit ListIterator(Container *pContainer, ListNodeBase *pNode)
		: m_pContainer(pContainer), m_pNode(pNode)
	{
	}

	Reference operator*()
	{
		return static_cast<_Node *>(m_pNode)->m_data;
	}

	pointer operator->()
	{
		return &static_cast<_Node *>(m_pNode)->m_data;
	}

	_Self &
		operator++()
	{
		m_pNode = m_pContainer->GetNode(m_pNode->m_iNext);
		return *this;
	}

	_Self operator++(int)
	{
		_Self __tmp = *this;
		m_pNode = m_pContainer->GetNode(m_pNode->m_iNext);
		return __tmp;
	}

	_Self &
		operator--()
	{
		m_pNode = m_pContainer->GetNode(m_pNode->m_iPrev);
		return *this;
	}

	_Self operator--(int)
	{
		_Self __tmp = *this;
		m_pNode = m_pContainer->GetNode(m_pNode->m_iPrev);
		return __tmp;
	}

	bool operator==(const _Self &other) const
	{
		assert(m_pContainer == other.m_pContainer);
		return m_pNode == other.m_pNode;
	}

	bool operator!=(const _Self &other) const
	{
		assert(m_pContainer == other.m_pContainer);
		return m_pNode != other.m_pNode;
	}

	bool operator<(const _Self other) const
	{
		return m_pNode < other.m_pNode;
	}
	///������������Ϊ
	_Self &
		operator+=(const ptrdiff_t n)
	{
		static_cast<_Node *>(m_pNode) += n;
		return *this;
	}

	_Self operator+(const ptrdiff_t n) const
	{
		return _Self(m_pContainer, static_cast<_Node *>(m_pNode) + n);
	}

	_Self &
		operator-=(const ptrdiff_t n)
	{
		static_cast<_Node *>(m_pNode) -= n;
		return *this;
	}

	_Self operator-(const ptrdiff_t n) const
	{
		return _Self(m_pContainer, static_cast<_Node *>(m_pNode) - n);
	}

	ptrdiff_t operator-(const _Self other) const
	{
		return static_cast<_Node *>(m_pNode)
			- static_cast<_Node *>(other.m_pNode);
	}

	Container *m_pContainer;
	ListNodeBase *m_pNode;
};

template<typename T, size_t MAX_SIZE>
class NFShmStaticList
{
public:
	typedef T ValueType;
	typedef NFShmStaticList<T, MAX_SIZE> ListType;
	typedef ListIterator<T, ListType> Iterator;
	typedef size_t SizeType;
	typedef T &Reference;
	typedef const T &ConstReference;
	typedef ptrdiff_t DifferenceType;
protected:
	typedef ListNode<T> _Node;
	typedef ListNodeBase _NodeBase;

	_Node m_astNodes[MAX_SIZE + 1];
	DifferenceType m_iFreeStart;
	SizeType m_iSize;
public:
	NFShmStaticList()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
		{
			CreateInit();
		}
		else
		{
			ResumeInit();
		}
	}

	int CreateInit()
	{
		//memset(m_astNodes, 0, sizeof(m_astNodes));
		m_iFreeStart = 0;

		for (SizeType i = 0; i < MAX_SIZE; i++)
		{
			m_astNodes[i].m_iNext = i + 1;
			m_astNodes[i].m_iPrev = 0;
			m_astNodes[i].m_bValid = false;
		}

		m_astNodes[MAX_SIZE].m_iNext = MAX_SIZE;
		m_astNodes[MAX_SIZE].m_iPrev = MAX_SIZE;
		m_astNodes[MAX_SIZE].m_bValid = false;

		m_iSize = 0;

		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	Reference operator[](SizeType index)
	{
		assert(m_astNodes[index].m_bValid);
		return m_astNodes[index].m_data;
	}

	_Node *
		GetNode(SizeType index)
	{
		return &m_astNodes[index];
	}

	bool IsValid(SizeType index)
	{
		if (index >= MAX_SIZE)
		{
			return false;
		}

		return GetNode(index)->m_bValid;
	}

	SizeType IndexOf(Iterator iter)
	{
		Iterator memfirst(this, GetNode(0));
		return iter - memfirst;
	}

	Iterator Begin()
	{
		return Iterator(this, &m_astNodes[m_astNodes[MAX_SIZE].m_iNext]);
	}

	Iterator End()
	{
		return Iterator(this, &m_astNodes[MAX_SIZE]);
	}

	bool Empty() const
	{
		return m_astNodes[MAX_SIZE].m_iNext == MAX_SIZE;
	}

	bool Full() const
	{
		return m_iFreeStart == MAX_SIZE;
	}

	SizeType Size() const
	{
		return m_iSize;
	}

	Reference Front()
	{
		return *Begin();
	}

	SizeType PushFront(const ValueType &v)
	{
		return Insert(--Begin(), v);
	}

	SizeType PushBack(const ValueType &v)
	{
		return Insert(--End(), v);
	}

	Iterator Erase(Iterator iter)
	{
		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		ptrdiff_t iSelf = m_astNodes[pNode->m_iNext].m_iPrev;
		ptrdiff_t iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iPrev].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = pNode->m_iPrev;

		assert(pNode->m_bValid);
		pNode->m_bValid = false;
		pNode->m_iNext = m_iFreeStart;
		m_iFreeStart = iSelf;

		m_iSize--;

		return Iterator(this, &m_astNodes[iNext]);
	}

	void Erase(SizeType pos)
	{
		assert(pos < MAX_SIZE);
		_Node *pNode = &m_astNodes[pos];
		ptrdiff_t iSelf = m_astNodes[pNode->m_iNext].m_iPrev;
		assert(iSelf == (int)pos);

		m_astNodes[pNode->m_iPrev].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = pNode->m_iPrev;

		assert(pNode->m_bValid);
		pNode->m_bValid = false;
		pNode->m_iNext = m_iFreeStart;
		m_iFreeStart = iSelf;

		m_iSize--;
	}

	SizeType Insert(Iterator iter, const ValueType &v)
	{
		ptrdiff_t iSelf = m_iFreeStart;
		m_iFreeStart = m_astNodes[m_iFreeStart].m_iNext;
		m_astNodes[iSelf].m_data = v;
		assert(!m_astNodes[iSelf].m_bValid);
		m_astNodes[iSelf].m_bValid = true;

		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		ptrdiff_t iPrev = m_astNodes[pNode->m_iNext].m_iPrev;
		m_astNodes[iSelf].m_iNext = pNode->m_iNext;
		m_astNodes[iSelf].m_iPrev = iPrev;
		m_astNodes[pNode->m_iNext].m_iPrev = iSelf;
		pNode->m_iNext = iSelf;

		m_iSize++;

		return iSelf;
	}


	SizeType InsertBefore(Iterator iter, const ValueType &v)
	{
		ptrdiff_t iSelf = m_iFreeStart;
		m_iFreeStart = m_astNodes[m_iFreeStart].m_iNext;
		m_astNodes[iSelf].m_data = v;
		assert(!m_astNodes[iSelf].m_bValid);
		m_astNodes[iSelf].m_bValid = true;

		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		m_astNodes[iSelf].m_iPrev = pNode->m_iPrev;
		m_astNodes[pNode->m_iPrev].m_iNext = iSelf;
		pNode->m_iPrev = iSelf;
		m_astNodes[iSelf].m_iNext = IndexOf(iter);

		m_iSize++;

		return iSelf;
	}


	Iterator Find(const ValueType &k)
	{
		Iterator iter = Begin();
		Iterator end = End();

		for (; iter != end; ++iter)
		{
			if (*iter == k)
			{
				return iter;
			}
		}

		return end;
	}

	void Remove(const ValueType &k)
	{
		Iterator iter = Begin();
		Iterator end = End();

		for (; iter != end;)
		{
			if (*iter == k)
			{
				iter = Erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	template<typename FuncType>
	void RemoveIf(const FuncType &func)
	{
		Iterator iter = Begin();
		Iterator end = End();

		for (; iter != end;)
		{
			if (func(&(*iter)))
			{
				iter = Erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
};

template<typename T, size_t MAX_SIZE, size_t MAX_TYPE>
class NFShmStaticMultiList
{
public:
	typedef T ValueType;
	typedef NFShmStaticMultiList<T, MAX_SIZE, MAX_TYPE> ListType;
	typedef ListIterator<T, ListType> Iterator;
	typedef size_t SizeType;
	typedef T &Reference;
	typedef const T &ConstReference;
	typedef ptrdiff_t DifferenceType;
protected:
	typedef ListNode<T> _Node;
	typedef ListNodeBase _NodeBase;

	_Node m_astNodes[MAX_SIZE + MAX_TYPE];
	DifferenceType m_iFreeStart;
	SizeType m_iSize;
public:
	NFShmStaticMultiList()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
		{
			CreateInit();
		}
		else
		{
			ResumeInit();
		}
	}

	int CreateInit()
	{
		memset(m_astNodes, 0, sizeof(m_astNodes));
		m_iFreeStart = 0;

		for (SizeType i = 0; i < MAX_SIZE; i++)
		{
			m_astNodes[i].m_iNext = i + 1;
			m_astNodes[i].m_bValid = false;
		}

		for (SizeType i = MAX_SIZE; i < MAX_SIZE + MAX_TYPE; i++)
		{
			m_astNodes[i].m_iNext = i;
			m_astNodes[i].m_iPrev = i;
			m_astNodes[i].m_bValid = false;
		}

		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	bool IsValid(SizeType index)
	{
		if (index >= MAX_SIZE)
		{
			return false;
		}

		return GetNode(index)->m_bValid;
	}

	Reference operator[](SizeType index)
	{
		assert(m_astNodes[index].m_bValid);
		return m_astNodes[index].m_data;
	}

	_Node *
		GetNode(SizeType index)
	{
		return &m_astNodes[index];
	}

	Iterator Begin(SizeType type)
	{
		return Iterator(this, &m_astNodes[m_astNodes[MAX_SIZE + type].m_iNext]);
	}

	Iterator End(SizeType type)
	{
		return Iterator(this, &m_astNodes[MAX_SIZE + type]);
	}

	bool Empty(SizeType type) const
	{
		return m_astNodes[MAX_SIZE + type].m_iNext == MAX_SIZE + type;
	}

	bool Full() const
	{
		return m_iFreeStart == MAX_SIZE;
	}

	Reference Front()
	{
		return *Begin();
	}

	SizeType Push(SizeType type, const ValueType &v)
	{
		return Insert(Begin(type), v);
	}

	Iterator Erase(Iterator iter)
	{
		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		ptrdiff_t iSelf = m_astNodes[pNode->m_iNext].m_iPrev;
		assert(iSelf >= 0 && (size_t)iSelf < MAX_SIZE);
		ptrdiff_t iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iPrev].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = pNode->m_iPrev;

		pNode->m_iNext = m_iFreeStart;
		assert(m_astNodes[iSelf].m_bValid);
		m_astNodes[iSelf].m_bValid = false;
		m_iFreeStart = iSelf;

		return Iterator(this, &m_astNodes[iNext]);
	}

	void Erase(SizeType pos)
	{
		assert(pos < MAX_SIZE);
		_Node *pNode = &m_astNodes[pos];
		ptrdiff_t iSelf = m_astNodes[pNode->m_iNext].m_iPrev;
		assert(iSelf == (int)pos);

		m_astNodes[pNode->m_iPrev].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = pNode->m_iPrev;

		pNode->m_iNext = m_iFreeStart;
		assert(m_astNodes[iSelf].m_bValid);
		m_astNodes[iSelf].m_bValid = false;
		m_iFreeStart = iSelf;
	}

	SizeType Insert(Iterator iter, const ValueType &v)
	{
		ptrdiff_t iSelf = m_iFreeStart;
		m_iFreeStart = m_astNodes[m_iFreeStart].m_iNext;
		m_astNodes[iSelf].m_data = v;

		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		ptrdiff_t iPrev = m_astNodes[pNode->m_iNext].m_iPrev;
		m_astNodes[iSelf].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = iSelf;
		pNode->m_iNext = iSelf;
		m_astNodes[iSelf].m_iPrev = iPrev;
		assert(!m_astNodes[iSelf].m_bValid);
		m_astNodes[iSelf].m_bValid = true;

		return iSelf;
	}

	Iterator Find(SizeType type, const ValueType &k)
	{
		Iterator iter = Begin(type);
		Iterator end = End(type);

		for (; iter != end; ++iter)
		{
			if (*iter == k)
			{
				return iter;
			}
		}

		return end;
	}

	void Remove(const ValueType &k)
	{
		for (SizeType type = 0; type < MAX_TYPE; type++)
		{
			Iterator iter = Begin(type);
			Iterator end = End(type);

			for (; iter != end;)
			{
				if (*iter == k)
				{
					iter = Erase(iter);
				}
				else
				{
					++iter;
				}
			}
		}
	}
};


template<typename T, size_t MAX_SIZE>
class NFShmOrderStaticList
{
public:

	typedef T ValueType;
	typedef NFShmOrderStaticList<T, MAX_SIZE> ListType;
	typedef ListIterator<T, ListType> Iterator;
	typedef size_t SizeType;
	typedef T &Reference;
	typedef const T &ConstReference;
	typedef ptrdiff_t DifferenceType;
protected:
	typedef ListNode<T> _Node;
	typedef ListNodeBase _NodeBase;

	_Node m_astNodes[MAX_SIZE + 1];
	DifferenceType m_iFreeStart;
	SizeType m_iSize;
public:
	NFShmOrderStaticList()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
		{
			CreateInit();
		}
		else
		{
			ResumeInit();
		}
	}

	int CreateInit()
	{
		//memset(m_astNodes, 0, sizeof(m_astNodes));
		m_iFreeStart = 0;

		for (SizeType i = 0; i < MAX_SIZE; i++)
		{
			m_astNodes[i].m_iNext = i + 1;
			m_astNodes[i].m_iPrev = 0;
			m_astNodes[i].m_bValid = false;
		}

		m_astNodes[MAX_SIZE].m_iNext = MAX_SIZE;
		m_astNodes[MAX_SIZE].m_iPrev = MAX_SIZE;
		m_astNodes[MAX_SIZE].m_bValid = false;

		m_iSize = 0;

		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	Reference operator[](SizeType index)
	{
		assert(m_astNodes[index].m_bValid);
		return m_astNodes[index].m_data;
	}

	_Node *
		GetNode(SizeType index)
	{
		return &m_astNodes[index];
	}

	bool IsValid(SizeType index)
	{
		if (index >= MAX_SIZE)
		{
			return false;
		}

		return GetNode(index)->m_bValid;
	}

	SizeType IndexOf(Iterator iter)
	{
		Iterator memfirst(this, GetNode(0));
		return iter - memfirst;
	}

	Iterator Begin()
	{
		return Iterator(this, &m_astNodes[m_astNodes[MAX_SIZE].m_iNext]);
	}

	Iterator End()
	{
		return Iterator(this, &m_astNodes[MAX_SIZE]);
	}

	bool Empty() const
	{
		return m_astNodes[MAX_SIZE].m_iNext == MAX_SIZE;
	}

	bool Full() const
	{
		return m_iFreeStart == MAX_SIZE;
	}

	SizeType Size() const
	{
		return m_iSize;
	}

	Reference Front()
	{
		return *Begin();
	}

	SizeType Push(const ValueType &v)
	{
		Iterator iter = Begin();
		for (; iter != End(); )
		{
			_Node *ptNode = static_cast<_Node *>(iter.m_pNode);
			if (v > ptNode->m_data)
			{
				break;
			}
			else
			{
				++iter;
			}
		}

		if (iter == Begin())
		{
			return PushFront(v);
		}

		if (iter == End())
		{
			return PushBack(v);
		}

		return Insert(--iter, v);
	}

	Iterator Erase(Iterator iter)
	{
		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		ptrdiff_t iSelf = m_astNodes[pNode->m_iNext].m_iPrev;
		ptrdiff_t iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iPrev].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = pNode->m_iPrev;

		assert(pNode->m_bValid);
		pNode->m_bValid = false;
		pNode->m_iNext = m_iFreeStart;
		m_iFreeStart = iSelf;

		m_iSize--;

		return Iterator(this, &m_astNodes[iNext]);
	}

	void Erase(SizeType pos)
	{
		assert(pos < MAX_SIZE);
		_Node *pNode = &m_astNodes[pos];
		ptrdiff_t iSelf = m_astNodes[pNode->m_iNext].m_iPrev;
		assert(iSelf == (int)pos);

		m_astNodes[pNode->m_iPrev].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = pNode->m_iPrev;

		assert(pNode->m_bValid);
		pNode->m_bValid = false;
		pNode->m_iNext = m_iFreeStart;
		m_iFreeStart = iSelf;

		m_iSize--;
	}

	SizeType Insert(Iterator iter, const ValueType &v)
	{
		ptrdiff_t iSelf = m_iFreeStart;
		m_iFreeStart = m_astNodes[m_iFreeStart].m_iNext;
		m_astNodes[iSelf].m_data = v;
		assert(!m_astNodes[iSelf].m_bValid);
		m_astNodes[iSelf].m_bValid = true;

		_Node *pNode = static_cast<_Node *>(iter.m_pNode);
		ptrdiff_t iPrev = m_astNodes[pNode->m_iNext].m_iPrev;
		m_astNodes[iSelf].m_iNext = pNode->m_iNext;
		m_astNodes[pNode->m_iNext].m_iPrev = iSelf;
		pNode->m_iNext = iSelf;
		m_astNodes[iSelf].m_iPrev = iPrev;

		m_iSize++;

		return iSelf;
	}

	Iterator Find(const ValueType &k)
	{
		Iterator iter = Begin();
		Iterator end = End();

		for (; iter != end; ++iter)
		{
			if (*iter == k)
			{
				return iter;
			}
		}

		return end;
	}

	void Remove(const ValueType &k)
	{
		Iterator iter = Begin();
		Iterator end = End();

		for (; iter != end;)
		{
			if (*iter == k)
			{
				iter = Erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	template<typename FuncType>
	void RemoveIf(const FuncType &func)
	{
		Iterator iter = Begin();
		Iterator end = End();

		for (; iter != end;)
		{
			if (func(&(*iter)))
			{
				iter = Erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

private:

	SizeType PushFront(const ValueType &v)
	{
		return Insert(--Begin(), v);
	}

	SizeType PushBack(const ValueType &v)
	{
		return Insert(--End(), v);
	}
};
