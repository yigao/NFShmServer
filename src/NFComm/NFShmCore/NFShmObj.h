// -------------------------------------------------------------------------
//    @FileName         :    NFShmObj.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFShmDefine.h"
#include "NFDynamicHead.h"
#include "NFShmTimerObj.h"

class NFShmObj : public NFShmTimerObj
{
public:
	NFShmObj(NFIPluginManager* pPluginManager);
	virtual ~NFShmObj();

    //非继承函数, 不要加virtual
	int CreateInit();

    //非继承函数, 不要加virtual
	int ResumeInit()
	{
		return 0;
	}

	//must be virtual
	virtual void OnTimer(int timeId, int callcount)
    {

    }

#if defined(_DEBUG) | defined(_DEBUG_)
	void CheckMemMagicNum()
	{
		assert(m_iMagicCheckNum == OBJECT_MAGIC_CHECK_NUMBER);
	}
#endif

	virtual int GetHashKey(void *pvKey, int &iKeyLength);
	virtual int SetHashKey(const void *pvKey, int iKeyLength);
	virtual int Show(FILE *fpOut);

	void SetInRecycle(bool bRet)
	{
		m_bIsInRecycle = bRet;
	}

	bool IsInRecycle()
	{
		return m_bIsInRecycle;
	}

	int GetGlobalID() const
	{
		return m_iGlobalID;
	}

	void SetGlobalID(int iID)
	{
		m_iGlobalID = iID;
	}

	int GetTypeIndexID()
	{
		return ((GetClassType() << 23) | 0x80000000) | GetObjectID();
	}

	int GetMiscID()
	{
		if (m_iGlobalID >= 0)
		{
			return m_iGlobalID;
		}
		else
		{
			return GetTypeIndexID();
		}
	}

#if defined(_DEBUG) | defined(_DEBUG_)
	int m_iMagicCheckNum;
#endif
	int  m_iGlobalID;
	int  m_iObjectID;
	int  m_iObjSeq;
	int  m_iHashID;

	bool m_bIsInRecycle;

	DECLARE_IDCREATE(NFShmObj)
};

