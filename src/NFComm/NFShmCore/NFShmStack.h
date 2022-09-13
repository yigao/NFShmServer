// -------------------------------------------------------------------------
//    @FileName         :    NFShmStack.h
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

template <class TYPE, int iSize>
class NFShmStack
{
public:
	NFShmStack() 
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

	~NFShmStack() {}

	int CreateInit()
	{
		Initialize();
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	int Initialize();

	int Push(const TYPE *pstItem);
	TYPE *Pop();

	int GetTop()
	{
		return m_iTop;
	}
	TYPE *GetItem(int iIdx);
private:
	bool IsFull();

	int m_iTop;
	TYPE m_aItem[iSize];
};

template<class TYPE, int iSize>
int NFShmStack<TYPE, iSize>::Initialize()
{
	m_iTop = 0;
	memset(m_aItem, 0, sizeof(m_aItem));
	return 0;
}

template<class TYPE, int iSize>
int NFShmStack<TYPE, iSize>::Push(const TYPE *pstItem)
{
	if (pstItem && !IsFull())
	{
		m_aItem[m_iTop] = *pstItem;
		++m_iTop;
	}

	return 0;
}

template<class TYPE, int iSize>
TYPE *NFShmStack<TYPE, iSize>::Pop()
{
	TYPE *pstItem = NULL;

	if (m_iTop > 0)
	{
		pstItem = &m_aItem[m_iTop - 1];
		--m_iTop;
	}

	return pstItem;
}

template<class TYPE, int iSize>
bool NFShmStack<TYPE, iSize>::IsFull()
{
	return m_iTop >= iSize;
}

template<class TYPE, int iSize>
TYPE *NFShmStack<TYPE, iSize>::GetItem(int iIdx)
{
	if (iIdx >= 0 && iIdx < m_iTop)
	{
		return &m_aItem[iIdx];
	}

	return NULL;
}
