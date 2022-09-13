// -------------------------------------------------------------------------
//    @FileName         :    NFOrderedSet.hpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "src/NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include "src/NFComm/NFPluginModule/NFPair.h"
#include "NFShmMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"

template<typename T, size_t MAX_SIZE>
class NFShmOrderedSet
{
public:
	typedef T ValueType;
	typedef size_t SizeType;

	NFShmOrderedSet()
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
		m_iNum = 0;
		memset(m_data, 0, sizeof(m_data));
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	int Insert(ValueType element)
	{
		if (m_iNum >= (int)MAX_SIZE)
		{
			return -1;
		}

		int iInsertPos = 0;
		for (; iInsertPos < m_iNum; iInsertPos++)
		{
			if (element < m_data[iInsertPos])
			{
				break;;
			}
			else if (element == m_data[iInsertPos])
			{
				return iInsertPos;
			}
		}

		for (int i = m_iNum - 1; i >= iInsertPos; i--)
		{
			m_data[i + 1] = m_data[i];
		}

		m_data[iInsertPos] = element;
		m_iNum++;

		return iInsertPos;
	}

	int Remove(ValueType element)
	{
		int iPos = -1;
		for (int i = 0; i < m_iNum; i++)
		{
			if (m_data[i] == element)
			{
				iPos = i;
				break;
			}
		}

		if (iPos != -1)
		{
			for (int i = iPos; i < m_iNum - 1; i++)
			{
				m_data[i] = m_data[i + 1];
			}
			m_iNum--;
		}

		return 0;
	}

	void Clear()
	{
		m_iNum = 0;
	}

	SizeType Num()
	{
		return m_iNum;
	}

	ValueType& operator[](SizeType i)
	{
		return m_data[i];
	}

	COrderedSet& operator = (COrderedSet& stSet)
	{
		if (this == &stSet)
		{
			return *this;
		}

		for (int i = 0; i < (int)MAX_SIZE && i < stSet.Num(); ++i)
		{
			Insert(stSet[i]);
		}

		return *this;
	}
private:
	int m_iNum;
	ValueType m_data[MAX_SIZE];
};

