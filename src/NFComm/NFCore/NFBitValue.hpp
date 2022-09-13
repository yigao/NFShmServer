// -------------------------------------------------------------------------
//    @FileName         :    NFBitValue.hpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

//T just can be build-in type, like int uint16_t uint64_t 
template <class T>
class NFBitValue
{
public:
	enum NFBitValueDefine
	{
		ErrorValue = -1,
		NoneValue = 0,
		HaveValue = 1,
	};

	NFBitValue() : m_nValue(0)
	{
	}

	NFBitValue(T nValue) : m_nValue(nValue)
	{
	}

	void SetValue(const T& nValue)
	{
		m_nValue = nValue;
	}

	T GetValue() const
	{
		return m_nValue;
	}

	static int GetBitLength()
	{
		return sizeof(T) * 8;
	}

	int GetFirstNoValueIndex()
	{
		for (int i = 0; i < GetBitLength(); ++i)
		{
			if ((m_nValue & (T(1) << i)) == NoneValue)
			{
				return i;
			}
		}

		return -1;
	}

	T GetBitValue(const int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetBitLength())
		{
			return ErrorValue;
		}

		return (m_nValue & (T(1) << nIndex));
	}

	void SetBitValue(const int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetBitLength())
		{
			return;
		}

		m_nValue |= (T(1) << nIndex);
	}

	void ClearBitValue(const int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetBitLength())
		{
			return;
		}

		m_nValue &= ~(T(1) << nIndex);
	}

	bool HaveBitValue(const int nIndex)
	{
		return GetBitValue(nIndex) != NoneValue;
	}

	////////////////////////////////////////////////////////////////////////////////////////
	static int GetFirstNoValueIndex(const T& nValue)
	{
		for (int i = 0; i < GetBitLength(); ++i)
		{
			if ((nValue & (T(1) << i)) == NoneValue)
			{
				return i;
			}
		}

		return -1;
	}

	static T GetBitValue(const T& nValue, const int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetBitLength())
		{
			return ErrorValue;
		}

		return (nValue & (T(1) << nIndex));
	}

	static void SetBitValue(T& nValue, const int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetBitLength())
		{
			return;
		}

		nValue |= (T(1) << nIndex);
	}

	static void ClearBitValue(T& nValue, const int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetBitLength())
		{
			return;
		}

		nValue &= ~(T(1) << nIndex);
	}

	static bool HaveBitValue(const T& nValue, const int nIndex)
	{
		return GetBitValue(nValue, nIndex) != NoneValue;
	}

private:
	T m_nValue;
};

