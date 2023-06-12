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
	NFShmObj*	GetAttachedObj();
	void	SetAttachedObj(NFShmObj *pObj);
	void*	GetObjBuf();
	void	SetObjBuf(void *pBuf);
private:
	union
	{
		NFShmObj *m_pAttachedObj;
		void *m_pBuf;
	}m_uEntity;
};
