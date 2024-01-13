// -------------------------------------------------------------------------
//    @FileName         :    NFShmQueue.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFShmDefine.h"

typedef struct Queue_tag
{
	int iData[MAX_GLOBALID_QUEUESIZE];
	int iFront, iRear;
} NFIntQUEUE;

void InitQueue(NFIntQUEUE *);
int EmptyQueue(NFIntQUEUE *);
int FullQueue(NFIntQUEUE *);
int InQueue(NFIntQUEUE *, int);
int OutQueue(NFIntQUEUE *);