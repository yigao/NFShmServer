// -------------------------------------------------------------------------
//    @FileName         :    NFArraySequence.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include "NFComm/NFPluginModule/NFPair.h"
#include "NFShmDefine.h"
#include "NFShmMgr.h"

/**
* 静态有序数组
* 保存一个按key有序排列的数组,key值唯一
* 二分查找和插入，删除和插入会有较大的性能损失
* 不建议超过1000的数据使用
* 禁止超过10000的数据使用
* 从大到小排序
*/

template<typename ELEMENT, size_t MAX_SIZE, typename KEY >
class NFArraySequence
{
public:
    NFArraySequence()
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
        m_iSize = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

	int FindIndex(const KEY &Key ) const
	{
		int index = SearchIndex(0, m_iSize, Key);
		if( Key == m_astData[index].first )
		{
			return index;
		}
		return INVALID_ID;
	}

	ELEMENT *Find(const KEY &Key)
	{
		int iIndex = FindIndex(Key);
		if( iIndex >= 0 )
		{
			return &m_astData[iIndex].second;
		}
		return NULL;
	}

	const ELEMENT *Find(const KEY &Key) const
	{
		int iIndex = FindIndex(Key);
		if( iIndex >= 0 )
		{
			return &m_astData[iIndex].second;
		}
		return NULL;
	}

	int Add(const KEY& key, const ELEMENT &stElement)
	{
		ELEMENT *pElement = Find(key);
		if( pElement )
		{
			return -1;
		}

		if( IsFull() )
		{
			return -2;
		}

		int index = SearchIndex(0,m_iSize,key);
		for(int i = m_iSize; i > index; i--)
		{
			m_astData[i]= m_astData[i-1];
		}
		m_astData[index].first = key;
		m_astData[index].second = stElement;
		m_iSize++;
		return 0;
	}

	int Del(const KEY &Key)
	{
		if(m_iSize<=0) return -1;
		int index = SearchIndex(0,m_iSize,Key);
		if( Key != m_astData[index].first)
		{
			return -1;
		}
		if( index < 0 )
		{
			return -1;
		}
		for(size_t i = index; i < m_iSize-1; i++)
		{
			m_astData[i]= m_astData[i+1];
		}
		m_iSize--;
		return 0;
	}

	size_t GetSize()
	{
		return m_iSize;
	}

	ELEMENT *Get( int iIdx )
	{
		if( iIdx >= 0 && iIdx < (int)m_iSize )
		{
			return &m_astData[iIdx].second;
		}

		return NULL;
	}

	void *GetDataPtr()
	{
		return m_astData;
	}

private:
	int SearchIndex(int left, int right,  KEY &Key)
	{
		int middle;
		while(left < right)
		{
			middle = (left+right)/2;
			if(Key == m_astData[middle].first)
				return middle;
			if(Key > m_astData[middle].first)
				right = middle;
			else left = middle + 1;
		}
		return left;
	}
private:
    bool IsFull() { return m_iSize >= MAX_SIZE; }

    size_t m_iSize;
    NFPair<KEY,ELEMENT> m_astData[ MAX_SIZE ];
};

