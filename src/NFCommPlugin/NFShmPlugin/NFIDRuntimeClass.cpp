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

NFShmObj *NFIDRuntimeClass::GetObj(int iType, int iIndex)
{
	return NFShmMgr::Instance()->GetObj(iType, iIndex);
}

bool   NFIDRuntimeClass::IsEnd(int iType, int iIndex)
{
	return NFShmMgr::Instance()->IsEnd(iType, iIndex);
}

bool NFIDRuntimeClass::IsTypeValid(int iType)
{
	return NFShmMgr::Instance()->IsTypeValid(iType);
}

NFShmObj *NFIDRuntimeClass::CreateObj(int iType)
{
	return NFShmMgr::Instance()->CreateObj(iType);
}

NFShmObj *NFIDRuntimeClass::GetObjFromGlobalID(int iGlobalID, int iType, int iStrongType)
{
	return NFShmMgr::Instance()->GetObjFromGlobalID(iGlobalID,iType,iStrongType);
}

/*static */
NFShmObj *NFIDRuntimeClass::GetObjFromMiscID(int iMiscID, int iType)
{
	return NFShmMgr::Instance()->GetObjFromMiscID(iMiscID,iType);
}

NFShmObj *NFIDRuntimeClass::GetHeadObj(int iType)
{
	return NFShmMgr::Instance()->GetHeadObj(iType);
}

NFShmObj *NFIDRuntimeClass::GetNextObj(int iType, NFShmObj *pObj)
{
	return NFShmMgr::Instance()->GetNextObj(iType, pObj);
}

void NFIDRuntimeClass::DestroyObj(NFShmObj *pObj)
{
	NFShmMgr::Instance()->DestroyObj(pObj);
}
