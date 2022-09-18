// -------------------------------------------------------------------------
//    @FileName         :    NFShmIdx.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include"NFComm/NFCore/NFPlatform.h"

#define MAXDSINFOITEM  2
#define IDXNULL			-1

class NFShmObj;

class NFShmIdx
{
public:
	NFShmIdx();
	~NFShmIdx();
	void	Initialize();
	void	SetFree();
	void	SetUsed();
	short	IsUsed();
	int		GetNextIdx();
	void	SetNextIdx(int iIdx);
	int		GetPrevIdx();
	void	SetPrevIdx(int iIdx);
	int		GetDsInfo(short nDsIdx, int *piDsVal);
	int		SetDsInfo(short nDsIdx, int iDsVal);
	int		ClearDsInfo();

	NFShmObj*	GetAttachedObj();
	void	SetAttachedObj(NFShmObj *pObj);
	void*	GetObjBuf();
	void	SetObjBuf(void *pBuf);
protected:
	short m_nUseFlag;
	int m_iNextIdx;
	int m_iPrevIdx;
	int m_piDsInfo[MAXDSINFOITEM];
private:
	union
	{
		NFShmObj *m_pAttachedObj;
		void *m_pBuf;
	}m_uEntity;
};
