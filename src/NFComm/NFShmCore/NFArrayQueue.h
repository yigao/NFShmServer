// -------------------------------------------------------------------------
//    @FileName         :    NFShmQueue.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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