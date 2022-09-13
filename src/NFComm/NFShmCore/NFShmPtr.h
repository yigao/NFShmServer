// -------------------------------------------------------------------------
//    @FileName         :    NFShmPtr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFShmObj.h"
#include "NFShmMgr.h"
/*
共享内存对象指针，指向CObj类
在recover的时候会自动适应
在对象删除之后如果指针还在，指针将会返回空
*/
template<class ObjType>
class NFShmPtr
{
public:
	explicit NFShmPtr(ObjType *pObj)
		: m_pObj(pObj),
		m_iObjSeq(pObj ? pObj->m_iObjSeq : INVALID_ID)
	{
	}
	//构造函数需要对共享内存操作
	explicit NFShmPtr()
	{
		if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT )
		{
			CreateInit();
		}
		else
		{
			ResumeInit();
		}
	}

	~NFShmPtr()
	{
		if (m_pObj)
		{
			m_pObj = 0;
		}
	}

	void CreateInit()
	{
		m_pObj = 0;
		m_iObjSeq = INVALID_ID;
	}

	void ResumeInit()
	{
		if (m_pObj)
		{
			char *m_pChar = (char *)m_pObj;
			m_pChar += NFShmMgr::Instance()->GetAddrOffset();
			m_pObj = (ObjType *)m_pChar;
		}
	}

	NFShmPtr(const NFShmPtr<ObjType> &rT)
	{
		m_pObj = (ObjType*)rT.GetPoint();

		if (m_pObj)
		{
			m_iObjSeq = m_pObj->m_iObjSeq;
		}
	}

	const NFShmPtr<ObjType> &operator = (const NFShmPtr<ObjType> &rT)
	{
		m_pObj = (ObjType*)rT.GetPoint();

		if (m_pObj)
		{
			m_iObjSeq = m_pObj->m_iObjSeq;
		}

		return *this;
	}

	/* GCC yyd,ungelivable gcc
		template<class ObjType>
		ShmPtr & operator= ( ShmPtr<ObjType> const& rT)
		{
			m_pObj = rT.GetPoint();
			if(m_pObj)
			{
				m_iObjSeq = m_pObj->m_iObjSeq;
			}
			return *this;
		}*/
	const NFShmPtr<ObjType> &operator = (const ObjType *pT)
	{
		m_pObj = (ObjType *)pT;

		if (m_pObj)
		{
			m_iObjSeq = m_pObj->m_iObjSeq;
		}
		else
		{
			m_iObjSeq = INVALID_ID;
		}

		return *this;
	}
	ObjType &operator* ()
	{
		return *GetPoint();
	}
	const ObjType &operator* () const
	{
		return *GetPoint();
	}
	ObjType *operator-> ()
	{
		return GetPoint();
	}
	const ObjType *operator-> () const
	{
		return GetPoint();
	}
	bool operator== (const NFShmPtr<ObjType> &rT) const
	{
		return GetPoint() == rT.GetPoint();
	}
	bool operator== (const ObjType *pT) const
	{
		return GetPoint() == pT;
	}
	bool operator!= (const ObjType *pT) const
	{
		return GetPoint() != pT;
	}
	operator bool() const
	{
		return 0 != GetPoint();
	}
	operator const ObjType *() const
	{
		return GetPoint();
	}
	operator ObjType *()
	{
		return GetPoint();
	}
	void Reset()
	{
		if (0 != m_pObj)
		{
			m_pObj = 0;
		}
	}
	void Reset(ObjType *pT)
	{
		m_pObj = pT;

		if (m_pObj)
		{
			m_iObjSeq = m_pObj->m_iObjSeq;
		}
	}
public:
	ObjType *GetPoint()
	{
		if (!m_pObj)
		{
			return 0;
		}

		if (m_pObj->m_iObjSeq == m_iObjSeq)
		{
			return m_pObj;
		}
		else
		{
            Reset();
		}

		return 0;
	}
	const ObjType *GetPoint() const
	{
		if (!m_pObj)
		{
			return 0;
		}

		if (m_pObj->m_iObjSeq == m_iObjSeq)
		{
			return m_pObj;
		}
		else
		{
            const_cast<NFShmPtr<ObjType>*>(this)->Reset();
		}

		return 0;
	}
	ObjType *m_pObj;
	/*对象序列号，如果这个不相等说明指针无效了*/
	int m_iObjSeq;
};

/*
不校验对象序列号的指针,因为某些时候校验是不需要的
逻辑特性决定了某些指针不会发生变化
*/
template<class ObjType>
class NFRawShmPtr
{
public:
	explicit NFRawShmPtr(ObjType *pObj)
		: m_pObj(pObj)
	{
	}
	//构造函数需要对共享内存操作
	explicit NFRawShmPtr()
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
	~NFRawShmPtr()
	{
		if (m_pObj)
		{
			m_pObj = 0;
		}
	}
	void CreateInit()
	{
		m_pObj = 0;
	}
	void ResumeInit()
	{
		if (m_pObj)
		{
			char *m_pChar = (char *)m_pObj;
			m_pChar += NFShmMgr::Instance()->GetAddrOffset();
			m_pObj = (ObjType *)m_pChar;
		}
	}
	NFRawShmPtr(const NFRawShmPtr<ObjType> &rT)
	{
		m_pObj = rT.GetPoint();
	}
	const NFRawShmPtr<ObjType> &operator = (const NFRawShmPtr<ObjType> &rT)
	{
		m_pObj = rT.GetPoint();
		return *this;
	}
	/* GCC yyd,ungelivable gcc
	template<class ObjType>
	RawShmPtr & operator= ( RawShmPtr<ObjType> const& rT)
	{
	m_pObj = rT.GetPoint();
	return *this;
	}*/
	const NFRawShmPtr<ObjType> &operator = (const ObjType *pT)
	{
		m_pObj = (ObjType *)pT;
		return *this;
	}
	ObjType &operator* ()
	{
		return *GetPoint();
	}
	const ObjType &operator* () const
	{
		return *GetPoint();
	}
	ObjType *operator-> ()
	{
		return GetPoint();
	}
	const ObjType *operator-> () const
	{
		return GetPoint();
	}
	bool operator== (const NFShmPtr<ObjType> &rT) const
	{
		return GetPoint() == rT.GetPoint();
	}
	bool operator== (const ObjType *pT) const
	{
		return GetPoint() == pT;
	}
	bool operator!= (const ObjType *pT) const
	{
		return GetPoint() != pT;
	}
	operator bool() const
	{
		return 0 != GetPoint();
	}
	operator const ObjType *() const
	{
		return GetPoint();
	}
	operator ObjType *()
	{
		return GetPoint();
	}
	void Reset()
	{
		if (0 != m_pObj)
		{
			m_pObj = 0;
		}
	}
	void Reset(ObjType *pT)
	{
		m_pObj = pT;
	}
public:
	ObjType *GetPoint()
	{
		return m_pObj;
	}
	const ObjType *GetPoint() const
	{
		return m_pObj;
	}
private:
	ObjType *m_pObj;
};

