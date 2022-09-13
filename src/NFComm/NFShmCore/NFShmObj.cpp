// -------------------------------------------------------------------------
//    @FileName         :    NFShmObj.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFDynamicHead.h"
#include "NFShmObj.h"
#include "NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE_NOPARENT(NFShmObj, 0)

NFShmObj::NFShmObj()
{
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
	{
		CreateInit();
	}
	else
	{
		ResumeInit();
	}
}


NFShmObj::~NFShmObj()
{
#if defined(MAKE_FOR_DB_CHECK_CGI)
	return;
#endif

#if defined(_DEBUG) | defined(_DEBUG_)
	CheckMemMagicNum();

	//m_iMagicCheckNum = 0;
	if (m_iGlobalID != INVALID_ID)
	{
		//有globalid的对象删除没有使用CIDRuntimeClass::DestroyObj会发生这种问题，这是不允许的
		NFShmObj *pObj = NFShmMgr::Instance()->GetObjFromGlobalIDWithNoCheck(m_iGlobalID);
		assert(pObj == NULL);
	}

#endif
	m_iGlobalID = INVALID_ID;
}

int NFShmObj::CreateInit()
{
#if defined(_DEBUG) | defined(_DEBUG_)
	m_iMagicCheckNum = OBJECT_MAGIC_CHECK_NUMBER;
#endif
	m_iGlobalID = INVALID_ID;
	m_iObjectID = INVALID_ID;
    m_iHashID = INVALID_ID;
	m_iObjSeq = NFShmMgr::Instance()->IncreaseObjSeqNum();

	m_bIsInRecycle = false;

	return 0;
}

int NFShmObj::GetHashKey(void *pvKey, int &iKeyLength)
{
	return -1;
}
int NFShmObj::SetHashKey(const void *pvKey, int iKeyLength)
{

	return -1;
}
int NFShmObj::Show(FILE *fpOut)
{
	return -1;
}