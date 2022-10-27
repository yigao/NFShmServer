// -------------------------------------------------------------------------
//    @FileName         :    NFIDRuntimeClass.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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
    m_iIndexCount = 0;
    m_iIndexTime = 0;
}