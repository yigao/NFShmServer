// -------------------------------------------------------------------------
//    @FileName         :    NFShmObj.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFDynamicHead.h"
#include "NFShmObj.h"
#include "NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"

IMPLEMENT_IDCREATE_WITHTYPE_NOPARENT(NFShmObj, 0)

NFShmObj::NFShmObj(NFIPluginManager* pPluginManager):NFShmTimerObj(pPluginManager)
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
    UnSubscribeAll();
#if defined(MAKE_FOR_DB_CHECK_CGI)
	return;
#endif

#if defined(_DEBUG) | defined(_DEBUG_)
	CheckMemMagicNum();

	//m_iMagicCheckNum = 0;
	if (m_iGlobalID != INVALID_ID)
	{
		//有globalid的对象删除没有使用CIDRuntimeClass::DestroyObj会发生这种问题，这是不允许的
		NFShmObj *pObj = FindModule<NFISharedMemModule>()->GetObjFromGlobalIDWithNoCheck(m_iGlobalID);
		assert(pObj == NULL);
	}

#endif
	m_iGlobalID = INVALID_ID;
	m_iObjSeq = INVALID_ID;
}

int NFShmObj::CreateInit()
{
#if defined(_DEBUG) | defined(_DEBUG_)
	m_iMagicCheckNum = OBJECT_MAGIC_CHECK_NUMBER;
#endif
	m_iGlobalID = INVALID_ID;
	m_iObjectID = INVALID_ID;
    m_iHashID = INVALID_ID;
	m_iObjSeq = FindModule<NFISharedMemModule>()->IncreaseObjSeqNum();

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


//发送执行事件
int NFShmObj::FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->FireExecute(nEventID, nSrcID, bySrcType, message);
}

//订阅执行事件
int NFShmObj::Subscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string& desc)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->Subscribe(this, nEventID, nSrcID, bySrcType, desc);
}

//取消订阅执行事件
int NFShmObj::UnSubscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->UnSubscribe(this, nEventID, nSrcID, bySrcType);
}

//取消所有执行事件的订阅
int NFShmObj::UnSubscribeAll()
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->UnSubscribeAll(this);
}