// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

//===========================================================
// 类中定义下一节点的下标，发生冲突时节点自动连接起来，
// 未适用的节点按的下标连接起来作为空闲链
// 节点类型/节点间比较/Hash函数可由使用者自行定义，可按节
// 点中的某个关键值Hash和比较
//===========================================================


class NFShmHashTableStat
{
public:
	NFShmHashTableStat() :
		m_iHashGetNumber(0),
		m_iHashSearchNumber(0),
		m_iHashNullNumber(0),
		m_iUsedMaxItemCount(0),
		m_iNoItemCount(0)
	{
	    memset(m_achTableName, 0, sizeof(m_achTableName));
	}

	enum
	{
		HASH_TABLE_STAT_MAX = 30,
		HASH_TABLE_NAME_LEN = 50,
	};

	void SetName(const char *pchType, int iSize)
	{
		snprintf(m_achTableName, sizeof(m_achTableName), "CHashTable<%s, %d>", pchType, iSize);
	}
	static char *GetStat();
	static void InitStat();


	int m_iHashGetNumber;
	int m_iHashSearchNumber;
	int m_iHashNullNumber;
	int m_iUsedMaxItemCount;
	int m_iNoItemCount;

	char m_achTableName[HASH_TABLE_NAME_LEN];
};

extern int m_gHashTableStatNum;
extern NFShmHashTableStat m_agHashTableStat[NFShmHashTableStat::HASH_TABLE_STAT_MAX];


template <class TYPE, int iSize>
class NFShmHashTable
{
public:
	// 返回0则比较成功，使用者具体实现
	typedef int(*Compare)(const TYPE *tKey1, const TYPE *tKey2);
	typedef int(*HashFun)(const TYPE *tKey);

public:
	NFShmHashTable();
	~NFShmHashTable();

	int Initialize();
	int Reset();

	// 创建成功返回节点下标，否则-1
	int CreatItemByKey(const TYPE *pvKey);
	// 创建失败返回NULL
	TYPE *GetItemByKey(const TYPE *pvKey);

	TYPE *GetItemByIdx(int  iIdx);
	// 同创建
	int DelItemByKey(const TYPE *pvKey);

	// 自定义结构类型需设置哈希函数和比较函数
	int SetFuction(Compare keyCmp, HashFun hashFuc);

	int GetAllItem(TYPE *&hashItem)
	{
		hashItem = m_aHashItem;
		return iSize;
	}

	int GetItemNum()
	{
		return m_iUsedItemCount;
	}

	//=============================
	// 统计数据参看算法效率
	/*
		static int m_iHashGetNumber;
		static int m_iHashSearchNumber;
		static int m_iHashNullNumber;
		static int m_iUsedMaxItemCount;
		static int m_iNoItemCount;
	*/
	static NFShmHashTableStat *m_pStat;

	int m_iUsedItemCount;

	void InitStat();
	//=============================

private:
	// 默认Hash函数
	// 字符串采用，但不适合数字
	static int ELFHash(const TYPE *pvKey);
	// 默认查找比较函数
	static int KeyCompare(const TYPE *tKey1, const TYPE *tKey2);

	// 函数指针
	Compare m_KeyCmp;
	HashFun m_HashFuc;

	// 节点数组，保存Hash表的具体内容
	// 发生冲突时用Next下标连接起来
	TYPE m_aHashItem[iSize];
	int m_aiNext[iSize]; // 先做空闲连接，发生冲突时连接

	// Hash值与对应的首节点的下标
	int m_iHashTable[iSize];

private:
	// 管理Hash节点的下标
	// 新建立节点时为其分配未使用的下标，否则回收
	int GetFreeItemIdx();
	int DelUsedItemIdx(int iIdx);

	// 将空闲节点连接起来供适用，该变量指向空闲链首节点下标
	int m_iFreeItemHead;
};

//====================================================================
// 这些统计数据不支持recover
/*
template<class TYPE, int iSize>
int CHashTable<TYPE, iSize>::m_iHashGetNumber = 0;
template<class TYPE, int iSize>
int CHashTable<TYPE, iSize>::m_iHashSearchNumber = 0;
template<class TYPE, int iSize>
int CHashTable<TYPE, iSize>::m_iHashNullNumber = 0;
template<class TYPE, int iSize>
int CHashTable<TYPE, iSize>::m_iUsedMaxItemCount = 0;
template<class TYPE, int iSize>
int CHashTable<TYPE, iSize>::m_iNoItemCount = 0;
*/

template<class TYPE, int iSize>
NFShmHashTableStat *NFShmHashTable<TYPE, iSize>::m_pStat = NULL;


//=============================================================================
template<class TYPE, int iSize>
NFShmHashTable<TYPE, iSize>::NFShmHashTable()
{
	//Recover就悲剧了，justinzhu,2016-2-24
	//  Initialize();
	m_KeyCmp = KeyCompare;
	m_HashFuc = ELFHash;
	m_iUsedItemCount = 0;
	memset(m_aiNext, 0, sizeof(m_aiNext));
	memset(m_iHashTable, 0, sizeof(m_iHashTable));
	m_iFreeItemHead = 0;

	if (!m_pStat)
	{
		m_pStat = &m_agHashTableStat[m_gHashTableStatNum];
		++m_gHashTableStatNum;
		assert(m_gHashTableStatNum < NFShmHashTableStat::HASH_TABLE_STAT_MAX);
		//m_pStat->SetName(typeid(*this).name());
		m_pStat->SetName(typeid(m_aHashItem[0]).name(), iSize);
	}
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::Initialize()
{
	memset((void *)m_aHashItem, 0, iSize * sizeof(TYPE));

	for (int i = 1; i < iSize; i++)
	{
		m_aiNext[i - 1] = i;
		m_iHashTable[i] = -1;
	}

	m_iHashTable[0] = -1;
	m_aiNext[iSize - 1] = -1; // end
	m_iFreeItemHead = 0; // m_aHashItem[0]的下标

	m_KeyCmp = KeyCompare;
	m_HashFuc = ELFHash;

	//InitStat();
	m_iUsedItemCount = 0;
	//m_iNoItemCount = 0;

	return 0;
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::Reset()
{
	memset((void *)m_aHashItem, 0, iSize * sizeof(TYPE));

	for (int i = 1; i < iSize; i++)
	{
		m_aiNext[i - 1] = i;
		m_iHashTable[i] = -1;
	}

	m_iHashTable[0] = -1;
	m_aiNext[iSize - 1] = -1; // end
	m_iFreeItemHead = 0; // m_aHashItem[0]的下标

	//InitStat();
	m_iUsedItemCount = 0;
	//m_iNoItemCount = 0;

	return 0;
}

template<class TYPE, int iSize>
void NFShmHashTable<TYPE, iSize>::InitStat()
{
	//m_iHashGetNumber = 0;
	//m_iHashSearchNumber = 0;
	//m_iHashNullNumber = 0;
}

template<class TYPE, int iSize>
NFShmHashTable<TYPE, iSize>::~NFShmHashTable()
{
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::SetFuction(Compare keyCmp, HashFun hashFuc)
{
	if (keyCmp && hashFuc)
	{
		m_KeyCmp = keyCmp;
		m_HashFuc = hashFuc;
		return 0;
	}

	return -1;
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::CreatItemByKey(const TYPE *pvKey)
{
	if (!pvKey)
	{
		return -1;
	}

	int iHashIdx = m_HashFuc(pvKey);

	if (iHashIdx < 0)
	{
		return -3;
	}

	iHashIdx %= iSize;

	//查找有无相同节点存在
	int iTempIdx = m_iHashTable[iHashIdx];

	while (iTempIdx >= 0)
	{
		if (0 == m_KeyCmp(&m_aHashItem[iTempIdx], pvKey))
		{
			break;
		}

		iTempIdx = m_aiNext[iTempIdx];
	}

	//如果该节点存在，则返回
	if (iTempIdx >= 0)
	{
		return -4;
	}
	else
	{
		// 创建新节点，并作为首节点
		// 取空闲链中的首节点下标
		int iIdx = GetFreeItemIdx();

		if (iIdx < 0)
		{
			// 创建失败
			m_pStat->m_iNoItemCount++;
			return -2;
		}

		m_aiNext[iIdx] = m_iHashTable[iHashIdx];
		memcpy(&m_aHashItem[iIdx], pvKey, sizeof(TYPE));
		m_iHashTable[iHashIdx] = iIdx;
		return iIdx;
	}
}

template<class TYPE, int iSize>
TYPE *NFShmHashTable<TYPE, iSize>::GetItemByKey(const TYPE *pvKey)
{
	m_pStat->m_iHashGetNumber++;

	if (!pvKey)
	{
		m_pStat->m_iHashNullNumber++;
		return NULL;
	}

	int iHashIdx = m_HashFuc(pvKey);

	if (iHashIdx < 0)
	{
		m_pStat->m_iHashNullNumber++;
		return NULL;
	}

	iHashIdx %= iSize;

	if (m_iHashTable[iHashIdx] < 0) //不存在Item
	{
		m_pStat->m_iHashNullNumber++;
		return NULL;
	}

	//查找有无相同节点存在
	int iTempIdx = m_iHashTable[iHashIdx];

	while (iTempIdx >= 0)
	{
		m_pStat->m_iHashSearchNumber++;

		if (0 == m_KeyCmp(&m_aHashItem[iTempIdx], pvKey))
		{
			break;
		}

		iTempIdx = m_aiNext[iTempIdx];
	}

	//如果该节点存在，则返回找到的节点
	if (iTempIdx >= 0 && iTempIdx < iSize)
	{
		return &m_aHashItem[iTempIdx];
	}
	else
	{
		m_pStat->m_iHashNullNumber++;
		return NULL;
	}
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::DelItemByKey(const TYPE *pvKey)
{
	if (!pvKey)
	{
		return -1;
	}

	int iHashIdx = m_HashFuc(pvKey);

	if (iHashIdx < 0)
	{
		return -3;
	}

	iHashIdx %= iSize;

	if (m_iHashTable[iHashIdx] < 0) //不存在Item
	{
		return -4;
	}

	//查找有无相同节点存在
	int iTempIdx = m_iHashTable[iHashIdx];
	int iPreIdx = iTempIdx;

	while (iTempIdx >= 0)
	{
		if (0 == m_KeyCmp(&m_aHashItem[iTempIdx], pvKey))
		{
			break;
		}

		iPreIdx = iTempIdx;
		iTempIdx = m_aiNext[iTempIdx];
	}

	//如果该节点存在，则删除该节点
	if (iTempIdx >= 0 && iTempIdx < iSize)
	{
		if (iPreIdx == iTempIdx)
		{
			m_iHashTable[iHashIdx] = m_aiNext[iTempIdx];
		}
		else
		{
			m_aiNext[iPreIdx] = m_aiNext[iTempIdx];
		}

		// 回收该节点到空闲链中
		DelUsedItemIdx(iTempIdx);

		return iTempIdx;
	}
	else
	{
		return -2;
	}
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::ELFHash(const TYPE *pvKey)
{
	int iHash = 0;
	int iPara = 0;
	int iLength = sizeof(TYPE);
	const char *pcKey = (const char *)pvKey;

	for (int i = 0; i < iLength; i++)
	{
		iHash = (iHash << 4) + pcKey[i];
		iPara = (iHash & 0xF0000000L);

		if (iPara != 0)
		{
			iHash ^= (iPara >> 24);
			iHash &= ~iPara;
		}
	}

	iHash &= 0x7FFFFFFF;

	return (iHash % iSize);
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::KeyCompare(const TYPE *tKey1, const TYPE *tKey2)
{
	return memcmp((const void *)tKey1, (const void *)tKey2, sizeof(TYPE));
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::GetFreeItemIdx()
{
	int iTempIdx = m_iFreeItemHead;

	if (iTempIdx < 0 || iTempIdx >= iSize)
	{
		return -1;
	}

	m_iFreeItemHead = m_aiNext[iTempIdx];
	m_aiNext[iTempIdx] = -1;

	m_iUsedItemCount++;

	if (m_iUsedItemCount > m_pStat->m_iUsedMaxItemCount)
	{
		m_pStat->m_iUsedMaxItemCount = m_iUsedItemCount;
	}

	return iTempIdx;
}

template<class TYPE, int iSize>
int NFShmHashTable<TYPE, iSize>::DelUsedItemIdx(int iIdx)
{
	if (iIdx < 0 || iIdx >= iSize)
	{
		return -1;
	}

	m_aiNext[iIdx] = m_iFreeItemHead;
	m_iFreeItemHead = iIdx;

	memset((void *)&m_aHashItem[iIdx], 0, sizeof(TYPE));

	m_iUsedItemCount--;

	return 0;
}

template<class TYPE, int iSize>
TYPE *NFShmHashTable<TYPE, iSize>::GetItemByIdx(int iIdx)
{
	return &m_aHashItem[iIdx];
}