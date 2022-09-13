// -------------------------------------------------------------------------
//    @FileName         :    NFArray.h
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
#include "NFShmMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"

/**
* 静态数组
*/
template<typename ELEMENT, int MAX_SIZE>
class NFArray
{
public:
	NFArray()
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

	NFArray(const NFArray<ELEMENT, MAX_SIZE>& obj)
	{
		if (&obj == this) return;

		m_iSize = obj.m_iSize;
		if (m_iSize > MAX_SIZE)
		{
			m_iSize = MAX_SIZE;
		}

		for (int i = 0; i < m_iSize; ++i)
		{
			m_astData[i] = obj.m_astData[i];
		}
	}

	int CreateInit()
	{
		m_iSize = 0;
		memset(m_astData, 0, sizeof(m_astData));
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	/*检查下标的合法性，返回合法的下标值,用于[]函数中*/
	int CheckIndex(int i) const
	{
		int iIndex = 0;
		if (i < 0)
		{
			iIndex = 0;
			NFLogError(NF_LOG_SYSTEMLOG, 0, "NFArray index:{} < 0, return the 0", i);
		}
		else
		{
			int iMaxIndex = MAX_SIZE - 1;
			if (i > iMaxIndex)
			{
				iIndex = iMaxIndex;
				NFLogError(NF_LOG_SYSTEMLOG, 0, "NFArray index:{} > maxIndex:{}, return the maxIndex", i, iMaxIndex);
			}
			else
			{
				iIndex = i;
			}

			//iIndex = i > iMaxIndex ? iMaxIndex : i;
		}
		return iIndex;
	}

	const ELEMENT& operator[] (int i) const
	{
		NF_ASSERT(i < MAX_SIZE && i >= 0);

		int iIndex = CheckIndex(i); //绝对信任CheckIndex的返回值;

		assert(iIndex>=0 && iIndex < MAX_SIZE);

		return m_astData[iIndex];
	}

	ELEMENT& operator[] (int i)
	{
		NF_ASSERT(i < MAX_SIZE && i >= 0);

		int iIndex = CheckIndex(i);//绝对信任CheckIndex的返回值;

		return m_astData[iIndex];
	}

	ELEMENT *Get(int iIdx)
	{
		if( iIdx >= 0 && iIdx < (int)m_iSize )
		{
			return &m_astData[iIdx];
		}

		return NULL;
	}

	int GetMaxSize() const
	{
		return MAX_SIZE;
	}

	NFArray<ELEMENT, MAX_SIZE>& operator = (const NFArray<ELEMENT, MAX_SIZE>& obj)
	{
		if (&obj == this) return *this;

		m_iSize = obj.m_iSize;
		if (m_iSize > MAX_SIZE)
		{
			m_iSize = MAX_SIZE;
		}

		for (int i = 0; i < m_iSize; ++i)
		{
			m_astData[i] = obj.m_astData[i];
		}
		return *this;
	}

    int Clear() {
        m_iSize = 0;
        return 0;
    }

    int GetSize() const {
        return m_iSize;
    }

    void SetSize(int size) {
        if (size >= 0 && size <= MAX_SIZE) {
            m_iSize = size;
        } else {
            if (size < 0) {
                m_iSize = 0;
            }

            if (size > MAX_SIZE) {
                m_iSize = MAX_SIZE;
            }
        }
    }

    /*
    在数组最后一位增加一个元素
    返回值：-1 表示增加失败
    否则返回新增加元素的下标
    */
    int Add(const ELEMENT &tItem) {
        if ((MAX_SIZE) == m_iSize) {//最后一个了，加不了了
			return -1;
		}

		if (m_iSize < 0 || m_iSize >= MAX_SIZE)
		{
			return -1;
		}

		int iIndex = m_iSize;
		m_astData[m_iSize] = tItem;
		++m_iSize;
		return iIndex;
	}

	int Add(const std::vector<ELEMENT> &tItem) {
		for (int i = 0; i < (int)tItem.size(); i++)
		{
			int iRet = Add(tItem[i]);
			if (iRet < 0)
			{
				return iRet;
			}
		}
		return 0;
	}

    /*
    在数组最后一位增加一个元素
    返回值：-1 表示增加失败
    否则返回新增加元素的下标
    */
    int AddMemCpy(const ELEMENT &tItem) {
        if ((MAX_SIZE) == m_iSize) {//最后一个了，加不了了
            return -1;
        }

        if (m_iSize < 0 || m_iSize >= MAX_SIZE)
        {
            return -1;
        }

        int iIndex = m_iSize;
        memcpy(&m_astData[m_iSize], &tItem, sizeof(ELEMENT));
        ++m_iSize;
        return iIndex;
    }

    int MemCopy(int iIndex, const ELEMENT &tItem) {
        if (iIndex < 0 || iIndex >= m_iSize)
        {
            return -1;
        }

        if (m_iSize <= 0 || m_iSize > MAX_SIZE) //-V560
        {
            return -1;
        }

        memcpy(&m_astData[iIndex], &tItem, sizeof(ELEMENT));
        return 0;
    }

	int Swap(int iIndex, int otherIndex) {
		if (iIndex < 0 || iIndex >= m_iSize)
		{
			return -1;
		}

		if (otherIndex < 0 || otherIndex >= m_iSize)
		{
			return -1;
		}

		if (iIndex == otherIndex)
		{
			return 0;
		}

		if (m_iSize <= 0 || m_iSize > MAX_SIZE) //-V560
		{
			return -1;
		}

		std::swap(m_astData[iIndex], m_astData[otherIndex]);
		return 0;
	}

    /*
    在数组最后一位增加一个元素
    */
    ELEMENT* Add() {
        if ((MAX_SIZE) == m_iSize) {//最后一个了，加不了了
            return NULL;
        }

        if (m_iSize < 0 || m_iSize > MAX_SIZE)
        {
            return NULL;
        }

        ELEMENT* pCur = &m_astData[m_iSize];
        ++m_iSize;
        return pCur;
    }

    ELEMENT PopBack()
    {
        NF_ASSERT(m_iSize > 0 && m_iSize <= MAX_SIZE)

        ELEMENT el = m_astData[m_iSize - 1];
        int ret = Del(m_iSize - 1);
        NF_ASSERT(ret >= 0);
        return el;
    }

    ELEMENT PopFront()
    {
        if (m_iSize <= 0 || m_iSize > MAX_SIZE)
        {
            NF_ASSERT(false);
            return ELEMENT();
        }
        MemShiftDel(0);
    }

    int PushBack(const ELEMENT& el)
    {
        return Add(el);
    }

    int PushFront(const ELEMENT& el)
    {
        if (IsFull())
        {
            return -1;
        }

        memmove(m_astData + 1, m_astData,
                sizeof(ELEMENT) * (m_iSize));

        m_astData[0] = el;

        ++m_iSize;

        return 0;
    }

    /*
	删除数组中指定下标的元素，如果删除的非最后一个元素，则用最后一个元素来填补空位
	返回值：-1表示删除失败
	否则返回被删除的元素下标索引
	*/
	int Del(int iIndex)
	{
		if (iIndex < 0 || iIndex >= m_iSize)
		{
			return -1;
		}

		if (m_iSize <= 0 || m_iSize > MAX_SIZE) //-V560
		{
			return -1;
		}

		--m_iSize;
        if (m_iSize != iIndex)
        {
            m_astData[iIndex] = m_astData[m_iSize]; //这里不做检查了。。。
        }
		return iIndex;
	}

    /*
    删除数组中指定下标的元素，如果删除的非最后一个元素，则用最后一个元素来填补空位
    返回值：-1表示删除失败
    否则返回被删除的元素下标索引
    */
    int MemDel(int iIndex)
    {
        if (iIndex < 0 || iIndex >= m_iSize)
        {
            return -1;
        }

        if (m_iSize <= 0 || m_iSize > MAX_SIZE) //-V560
        {
            return -1;
        }

        --m_iSize;
        if (m_iSize != iIndex)
        {
            memcpy(m_astData+iIndex, m_astData+m_iSize, sizeof(ELEMENT));
        }
        return iIndex;
    }

	/*
	删除数组中指定下标的元素，如果删除的非最后一个元素，则将后面的元素逐个位移过来
	返回值：-1表示删除失败
	否则返回被删除的元素下标索引
	*/
	int MemShiftDel(int iIndex)
	{
		if (iIndex < 0 || iIndex >= m_iSize)
		{
			return -1;
		}

		if (m_iSize <= 0 || m_iSize > MAX_SIZE) //-V560
		{
			return -1;
		}

        if (iIndex != m_iSize - 1)
        {
            memmove(m_astData + iIndex, m_astData + iIndex + 1,
                    sizeof(ELEMENT) * (m_iSize - iIndex - 1));
        }

        --m_iSize;

		return iIndex;
	}

    /*
    删除数组中指定下标的元素，如果删除的非最后一个元素，则将后面的元素逐个位移过来
    返回值：-1表示删除失败
    否则返回被删除的元素下标索引
    */
    int ShiftDel(int iIndex)
    {
        if (iIndex < 0 || iIndex >= m_iSize)
        {
            return -1;
        }

        if (m_iSize <= 0 || m_iSize > MAX_SIZE) //-V560
        {
            return -1;
        }

        --m_iSize;
        int i = 0;
        for (i = iIndex; i < m_iSize; ++i) //-V1008
        {
            m_astData[i] = m_astData[i+1];
        }

        return iIndex;
    }

	void* GetDataPtr()
	{
		return (void*)m_astData;
	}

    bool IsFull() { return m_iSize >= MAX_SIZE; }

    void QSort(int (*compare)(const void *, const void *))
    {
        qsort(m_astData, m_iSize, sizeof(ELEMENT), compare);
    }

    void QSort()
    {
        qsort(m_astData, m_iSize, sizeof(ELEMENT));
    }

    void Sort(bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        std::sort(m_astData, m_astData+m_iSize, compare);
    }

    void Sort()
    {
        std::sort(m_astData, m_astData+m_iSize);
    }

    bool IsSorted(bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        return std::is_sorted(m_astData, m_astData+m_iSize, compare);
    }

    ELEMENT* Find(const ELEMENT& val, bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        auto iter = std::find(m_astData, m_astData+m_iSize, val, compare);
        if (iter != m_astData+m_iSize)
        {
            return iter;
        }
        else
        {
            return NULL;
        }
    }

    ELEMENT* Find(const ELEMENT& val)
    {
        auto iter = std::find(m_astData, m_astData+m_iSize, val);
        if (iter != m_astData+m_iSize)
        {
            return iter;
        }
        else
        {
            return NULL;
        }
    }

    int FindIndex(const ELEMENT& val)
    {
        for(int i = 0; i < GetSize(); i++)
        {
            if (m_astData[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    std::vector<int> FindIndexArray(const ELEMENT& val)
    {
        std::vector<int> vec;
        for(int i = 0; i < GetSize(); i++)
        {
            if (m_astData[i] == val)
            {
                vec.push_back(i);
            }
        }
        return vec;
    }

    ELEMENT* BinaryInsert(const ELEMENT& val)
    {
        if (IsFull())
        {
            return NULL;
        }

        auto iter = std::lower_bound(m_astData, m_astData+m_iSize, val);
        if (iter == m_astData+m_iSize)
        {
           ELEMENT* pNew = Add();
           if (pNew)
           {
               memcpy(pNew, &val, sizeof(ELEMENT));
           }
           return pNew;
        }
        else
        {
            int pos = iter - m_astData;
            memmove(m_astData + pos + 1, m_astData + pos,
                    sizeof(ELEMENT) * (m_iSize - pos));
            memcpy(m_astData+pos, &val, sizeof(ELEMENT));
            m_iSize++;
            return m_astData+pos;
        }

        return NULL;
    }

    ELEMENT* BinaryInsert(const ELEMENT& val, bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        if (IsFull())
        {
            return NULL;
        }

        auto iter = std::upper_bound(m_astData, m_astData+m_iSize, val, compare);
        if (iter == m_astData+m_iSize)
        {
            ELEMENT* pNew = Add();
            if (pNew)
            {
                memcpy(pNew, &val, sizeof(ELEMENT));
            }
            return pNew;
        }
        else
        {
            int pos = iter - m_astData;
            memmove(m_astData + pos + 1, m_astData + pos,
                    sizeof(ELEMENT) * (m_iSize - pos));
            memcpy(m_astData+pos, &val, sizeof(ELEMENT));
            m_iSize++;
            return m_astData+pos;
        }

        return NULL;
    }

    ELEMENT* BinarySearch(const ELEMENT& val, bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        auto pair_iter = std::equal_range(m_astData, m_astData+m_iSize, val, compare);
        if (pair_iter.first != pair_iter.second)
        {
            return pair_iter.first;
        }
        return NULL;
    }

    ELEMENT* BinarySearch(const ELEMENT& val)
    {
        auto pair_iter = std::equal_range(m_astData, m_astData+m_iSize, val);
        if (pair_iter.first != pair_iter.second)
        {
            return pair_iter.first;
        }
        return NULL;
    }

    std::vector<ELEMENT*> BinarySearchArray(const ELEMENT& val, bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        std::vector<ELEMENT*> vec;
        auto pair_iter = std::equal_range(m_astData, m_astData+m_iSize, val, compare);
        for (auto iter = pair_iter.first; iter != pair_iter.second; iter++)
        {
            vec.push_back(iter);
        }
        return vec;
    }

    std::vector<ELEMENT*> BinarySearchArray(const ELEMENT& val)
    {
        std::vector<ELEMENT*> vec;
        auto pair_iter = std::equal_range(m_astData, m_astData+m_iSize, val);
        for (auto iter = pair_iter.first; iter != pair_iter.second; iter++)
        {
            vec.push_back(iter);
        }
        return vec;
    }

    int BinaryDelete(const ELEMENT& val, bool compare(const ELEMENT& a, const ELEMENT& b))
    {
        auto pair_iter = std::equal_range(m_astData, m_astData+m_iSize, val, compare);
        if (pair_iter.first != pair_iter.second)
        {
            int pos = pair_iter.first - m_astData;
            if (MemShiftDel(pos) >= 0)
            {
                return 0;
            }
        }
        return -1;
    }

    int BinaryDelete(const ELEMENT& val)
    {
        auto pair_iter = std::equal_range(m_astData, m_astData+m_iSize, val);
        if (pair_iter.first != pair_iter.second)
        {
            int pos = pair_iter.first - m_astData;
            if (MemShiftDel(pos) >= 0)
            {
                return 0;
            }
        }
        return -1;
    }

	void RandomShuffle()
	{
		for (int i = 0; i < m_iSize; i++)
		{
			int index = NFRandInt(0, m_iSize);
			if (index != i)
			{
				Swap(i, index);
			}
		}
	}

	std::vector<ELEMENT> ToVector()
	{
    	std::vector<ELEMENT> vec;
    	for(int i = 0; i < m_iSize; i++)
		{
    		vec.push_back(m_astData[i]);
		}
    	return vec;
	}
private:
	int m_iSize;
	ELEMENT   m_astData[MAX_SIZE];
};

