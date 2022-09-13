// -------------------------------------------------------------------------
//    @FileName         :    NFBitMap.h
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BYTESIZE    (8*sizeof(unsigned char))

#define BITMAP_SIZE(iMax) ((iMax / 8) + ((iMax%8) > 0 ? 1 : 0))

template<int iSize>
class NFShmBitMap
{
public:
	NFShmBitMap();
	~NFShmBitMap();

	int CreateInit()
	{
		memset(m_acBitMap, 0, sizeof(m_acBitMap));
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	NFShmBitMap<iSize> &operator =(NFShmBitMap<iSize> &rExBitMap);
	bool    IsBitSetted(int iBitSeq) const;
	int SetBit(int iBitSeq);
	int ClearBit(int iBitSeq);
	int ClearAllBits();
	int GetSettedBits(int *piBitSeqs) const;
	//int GetTailBitSeq() const;
	int Get(int *piSize, char *pbyMap) const;
	int Get(std::string* pString) const;
	int Set(int iInputSize, const char *pbyMap);
	void Show(FILE *fpOut);
	void Show(char *szOut, int iLen) const;
	size_t GetSettedBitsCount() const;
protected:
	unsigned char m_acBitMap[iSize];
};

template<int iSize>
NFShmBitMap<iSize>::NFShmBitMap()
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

template<int iSize>
NFShmBitMap<iSize>::~NFShmBitMap()
{
}

template<int iSize>
NFShmBitMap<iSize> &NFShmBitMap<iSize>::operator =(NFShmBitMap<iSize> &rExBitMap)
{
	memcpy((void *)m_acBitMap, (const void *)rExBitMap.m_acBitMap, sizeof(m_acBitMap));
	return *this;
}

template<int iSize>
bool NFShmBitMap<iSize>::IsBitSetted(int iBitSeq) const
{
	int iMapIdx = 0;
	int iBitIdx = 0;
	unsigned char ucTempSMap = 0x80;

	if (iBitSeq < 0 || iBitSeq >= (int)(iSize*BYTESIZE))
	{
		return false;
	}

	iMapIdx = iBitSeq / BYTESIZE;
	iBitIdx = iBitSeq % BYTESIZE;

	if (m_acBitMap[iMapIdx] & (ucTempSMap >> iBitIdx))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<int iSize>
int NFShmBitMap<iSize>::SetBit(int iBitSeq)
{
	int iMapIdx = 0;
	int iBitIdx = 0;
	unsigned char ucTempSMap = 0x80;

	if (iBitSeq < 0 || iBitSeq >= (int)(iSize*BYTESIZE))
	{
		return 0;
	}

	iMapIdx = iBitSeq / BYTESIZE;
	iBitIdx = iBitSeq % BYTESIZE;

	m_acBitMap[iMapIdx] |= (ucTempSMap >> iBitIdx);

	return 0;
}

template<int iSize>
int NFShmBitMap<iSize>::ClearBit(int iBitSeq)
{
	int iMapIdx = 0;
	int iBitIdx = 0;
	unsigned char ucTempSMap = 0x80;

	if (iBitSeq < (int)0 || iBitSeq >= (int)(iSize*BYTESIZE))
	{
		return 0;
	}

	iMapIdx = iBitSeq / BYTESIZE;
	iBitIdx = iBitSeq % BYTESIZE;

	m_acBitMap[iMapIdx] &= (0xff ^ (ucTempSMap >> iBitIdx));

	return 0;
}

template<int iSize>
int NFShmBitMap<iSize>::ClearAllBits()
{
	memset((void *)m_acBitMap, 0, sizeof(m_acBitMap));
	return 0;
}

template<int iSize>
int NFShmBitMap<iSize>::GetSettedBits(int *piBitSeqs) const
{
	int iBitCount;
	int i;

	if (!piBitSeqs)
	{
		return -1;
	}

	iBitCount = 0;

	for (i = 0; i < (int)(iSize*BYTESIZE); i++)
	{
		if (IsBitSetted(i))
		{
			piBitSeqs[iBitCount] = i;
			iBitCount++;
		}
	}

	return iBitCount;
}

/*
template<int iSize>
int CBitMap<iSize>::GetTailBitSeq() const
{
	int i;

	for (i=iSize*BYTESIZE-1; i>=0; --i)
	{
		if( IsBitSetted(i) )
		{
			break;
		}
	}

	return i;
}
*/

template<int iSize>
int NFShmBitMap<iSize>::Get(int *riSize, char *pbyMap) const
{
	*riSize = iSize;
	memcpy((void *)pbyMap, (const void *)m_acBitMap, *riSize);
	return 0;
}

template<int iSize>
int NFShmBitMap<iSize>::Get(std::string* pString) const
{
	assert(pString);
	pString->assign(reinterpret_cast<const char*>(m_acBitMap), (size_t)iSize);

	return 0;
}

template<int iSize>
int NFShmBitMap<iSize>::Set(int iInputSize, const char *pbyMap)
{
	assert(iInputSize <= iSize);
	memcpy((void *)m_acBitMap, (const void *)pbyMap, iInputSize);
	return 0;
}


template<int iSize>
void NFShmBitMap<iSize>::Show(FILE *fpOut)
{
	int i;

	if (!fpOut)
	{
		return;
	}

	fprintf(fpOut, "BITMAP:\n");

	int iBitCount = (int)(iSize*BYTESIZE);

	for (i = 0; i < iBitCount; i++)
	{
		fprintf(fpOut, "%2d", IsBitSetted(i));
	}

	fprintf(fpOut, "\n");
	fflush(fpOut);
}

template<int iSize>
void NFShmBitMap<iSize>::Show(char *szOut, int iLen) const
{
	int i;

	if (!szOut)
	{
		return;
	}

	iLen -= snprintf(szOut + strlen(szOut), iLen - 1, "BITMAP:");

	int iBitCount = (int)(iSize*BYTESIZE);

	for (i = 0; i < iBitCount; i++)
	{
		iLen -= snprintf(szOut + strlen(szOut), iLen - 1, " %2d", IsBitSetted(i));
	}

	szOut[iLen - 1] = '\0';
}

template<int iSize>
size_t NFShmBitMap<iSize>::GetSettedBitsCount() const
{
	static const unsigned char BitsSetTable256[256] =
	{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
		B6(0), B6(1), B6(1), B6(2)
	};

	size_t iBitsCount = 0;

	for (int i = 0; i < iSize; i++)
	{
		iBitsCount += BitsSetTable256[m_acBitMap[i]];
	}

	return iBitsCount;
}

