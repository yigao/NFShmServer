// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFShmHashTable.h"

int m_gHashTableStatNum = 0;
NFShmHashTableStat m_agHashTableStat[NFShmHashTableStat::HASH_TABLE_STAT_MAX];

char *NFShmHashTableStat::GetStat()
{
	int iLen = 0;
	static char achLog[4096];

	iLen += snprintf(achLog, 4096, "\n");

	for (int i = 0; i < m_gHashTableStatNum; ++i)
	{
		iLen += snprintf(achLog + iLen, 4096 - iLen, "%s , getnum:%d, searchnum:%d, nullnum:%d, useditem:%d, createerror:%d.\n",
			m_agHashTableStat[i].m_achTableName,
			m_agHashTableStat[i].m_iHashGetNumber, m_agHashTableStat[i].m_iHashSearchNumber,
			m_agHashTableStat[i].m_iHashNullNumber,
			m_agHashTableStat[i].m_iUsedMaxItemCount, m_agHashTableStat[i].m_iNoItemCount);
	}

	return achLog;
}

void NFShmHashTableStat::InitStat()
{
	for (int i = 0; i < m_gHashTableStatNum; ++i)
	{
		m_agHashTableStat[i].m_iHashGetNumber = 0;
		m_agHashTableStat[i].m_iHashSearchNumber = 0;
		m_agHashTableStat[i].m_iHashNullNumber = 0;
		//m_agHashTableStat[i].m_iUsedMaxItemCount = 0;
		m_agHashTableStat[i].m_iNoItemCount = 0;
	}
}

