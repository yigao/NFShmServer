// -------------------------------------------------------------------------
//    @FileName         :    NFArrayQueue.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFArrayQueue.h"

void InitQueue(NFIntQUEUE *pQueue)
{
	pQueue->iFront = pQueue->iRear = 0;
}
// whether queue is empty
int EmptyQueue(NFIntQUEUE *pQueue)
{
	return (pQueue->iFront == pQueue->iRear);
}
int FullQueue(NFIntQUEUE *pQueue)
{
	return (((pQueue->iFront + 1) % MAX_GLOBALID_QUEUESIZE) == pQueue->iRear);
}
int InQueue(NFIntQUEUE *pQueue, int iData)
{
	if (!FullQueue(pQueue))
	{
		pQueue->iData[pQueue->iFront] = iData;
		pQueue->iFront = (pQueue->iFront + 1) % MAX_GLOBALID_QUEUESIZE;
		return 0;
	}
	else
	{
		//  TRACESVR(LL_ERROR,"InQueue Error in %s\n",__FUNCTION__);
		return -1;

	}
}
int OutQueue(NFIntQUEUE *pQueue)
{
	int temp;

	if (!EmptyQueue(pQueue))
	{
		temp = pQueue->iData[pQueue->iRear];
		pQueue->iRear = (pQueue->iRear + 1) % MAX_GLOBALID_QUEUESIZE;
	}
	else
	{
		//  TRACESVR(LL_ERROR,"IntQUEUE is empty in %s,all ids are unavailable",__FUNCTION__);
		return -1;
	}

	return temp;
}
/*int PrintQueue(IntQUEUE* pQueue)
{
	int iFront=pQueue->iFront;
	int iRear =pQueue->iRear;
	if (iFront == iRear)
	{
	return -1;
	}
	while(iFront != iRear)
	{
		printf("%d,",pQueue->iData[iRear]);
		iRear=(iRear+1)%MAXQUEUESIZE;
	}
	printf("\n");
	return 0;
}
*/

