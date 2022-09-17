// -------------------------------------------------------------------------
//    @FileName         :    NFIDRuntimeClass.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFIDRuntimeClass.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFShmObjSeg.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFGlobalID.h"


NFIDRuntimeClass::NFIDRuntimeClass()
{
	m_pCreatefn = NULL;
	m_pDestroyFn = NULL;
	m_pParent = NULL;
	m_iSelfType = -1;
	m_pObjSeg = NULL;
	m_iUseHash = false;
	m_iExternalDataSize = 0;
    m_iExternalItemCount = 0;
}