#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#define _DECLARE_PREALLOCATED_(class_name)\
    public:\
    static int  SetObjSeg(int bType, size_t siObjSize,int iObjCount, const std::string& className, bool useHash, int externalDataSize, int externalItemCount, bool singleton = false);  \
    static void* operator new( size_t nSize ) throw();\
    static void* operator new( size_t nSize,void *pBuffer) throw();\
    static void  operator delete( void *pMem ) ;\
    static void  operator delete( void *pMem ,void *pBuffer) ;\
    static class_name* GetObjectByID(int iID);\
    static int GetNextObjectID(int iObjID);\
    static int GetNextObjectID(class_name *pObj);\
    static int   GetItemCount();\
    static int   GetUsedCount();\
    static int   GetFreeCount();\
    static int   GetUsedHead();\
    static int   GetFreeHead();           \
    static int   GetExternalDataSize();\
    static int   GetExternalItemCount();  \
    static char* GetExternalBuffer();\
    static std::string GetClassName();    \
    static int GetStaticClassType();\
    virtual int GetClassType() const;\
    virtual int GetObjectID();\
    virtual int GetHashID();\
    virtual void SetHashID(int Id);\
    virtual void TestOP(){printf("Now %s OP\n",#class_name);}\
    virtual void PrintMyself(){printf("Now %s type:%d,index:%d,GlobalID:%d\n",\
                                          #class_name,class_name::GetClassType(),GetObjectID(),GetGlobalID());}                                                                         \
    virtual std::string ClassTypeInfo() { return NF_FORMAT("{} type:{}",\
                                          #class_name,class_name::GetClassType());}\
    static NFShmObj * CreateObject();\
    static NFShmObj * ResumeObject(void *pVoid);\
    static void DestroyObject(NFShmObj *pObj);\
    static int DestroyObjAutoErase(int maxNum);\
	static class_name* Instance();\
	static class_name* GetInstance();\


#define _IMPLEMENT_PREALLOCATED_(class_name, type) \
	class_name* class_name::GetObjectByID(int iID)\
	{\
        return (class_name*)NFShmMgr::Instance()->GetObj(type, iID);\
	}\
	int class_name::GetItemCount()\
	{\
	    return NFShmMgr::Instance()->GetItemCount(type);\
	}\
	int class_name::GetUsedCount()\
	{\
        return NFShmMgr::Instance()->GetUsedCount(type);\
	}\
	int class_name::GetFreeCount()\
	{\
        return NFShmMgr::Instance()->GetFreeCount(type);\
	}\
	int class_name::GetUsedHead()\
	{\
        return NFShmMgr::Instance()->GetUsedHead(type);\
	}\
	int class_name::GetFreeHead()\
	{\
        return NFShmMgr::Instance()->GetFreeHead(type);\
	}                                                 \
	int class_name::GetExternalDataSize()\
	{\
        return NFShmMgr::Instance()->GetExternalDataSize(type);\
	}\
	int class_name::GetExternalItemCount()\
	{\
        return NFShmMgr::Instance()->GetExternalItemCount(type);\
	}\
    char* class_name::GetExternalBuffer()\
	{\
        return NFShmMgr::Instance()->GetExternalBuffer(type);\
	}\
	std::string class_name::GetClassName() \
	{\
        return NFShmMgr::Instance()->GetClassName(type);\
	}                                                 \
    int class_name::GetStaticClassType()           \
    {\
        return type;\
    }\
	int class_name::GetClassType() const\
	{\
        return NFShmMgr::Instance()->GetClassType(type);\
	}\
	void* class_name::operator new( size_t nSize ) throw()\
	{\
        return NFShmMgr::Instance()->AllocMemForObject(type);\
	}\
	void* class_name::operator new( size_t nSize,void *pBuffer ) throw()\
	{\
		return  pBuffer;\
	}\
	void  class_name::operator delete( void *pMem )\
	{\
        return NFShmMgr::Instance()->FreeMemForObject(type, pMem);\
	}\
	void class_name::operator delete(void *pMem,void *pBuffer )\
	{\
	}\
	int class_name::GetNextObjectID(int iObjID) \
	{ \
		if (0 > iObjID)\
		{\
			return -1;\
		}\
		return NFShmMgr::Instance()->GetNextObjectID(type, iObjID);\
	}\
	int class_name::GetNextObjectID(class_name *pstObj) \
	{ \
		int iObjID = pstObj->GetObjectID();\
		if (0 > iObjID)\
		{\
			return -1;\
		}\
		return GetNextObjectID(iObjID); \
	}\
	int class_name::GetObjectID()\
	{\
		if(m_iObjectID == INVALID_ID)\
		{\
			m_iObjectID = NFShmMgr::Instance()->GetObjectID(type, this);\
		}\
		return m_iObjectID;\
	}\
    int class_name::GetHashID()\
    {\
        return m_iHashID;\
    }\
    void class_name::SetHashID(int Id)\
    {\
        m_iHashID = Id;\
    }\
	NFShmObj * class_name::CreateObject()\
	{\
		class_name *pTmp = NULL;\
		pTmp = new class_name;\
		if(!pTmp)\
		{\
			NFLogError(NF_LOG_SYSTEMLOG, 0, "ERROR: class:{}, Item:{}, Used:{}, Free:{}", GetClassName(), GetItemCount(), GetUsedCount(), GetFreeCount());\
		}\
		return pTmp;\
	}\
	NFShmObj * class_name::ResumeObject(void * pVoid)\
	{\
		class_name *pTmp = NULL;\
		pTmp = new (pVoid) class_name;\
		return pTmp;\
	}\
	void  class_name::DestroyObject(NFShmObj *pObj)\
	{\
		class_name *pTmp = NULL;\
		pTmp= (class_name*)pObj;\
		delete pTmp;\
		return;\
	}\
    int class_name::DestroyObjAutoErase(int maxNum = INVALID_ID)\
    {\
        return NFShmMgr::Instance()->DestroyObjAutoErase(type, maxNum);\
    }\
	class_name* class_name::Instance()\
	{\
		return (class_name *)NFShmMgr::Instance()->GetHeadObj(type);\
	}\
	class_name* class_name::GetInstance()\
	{\
		return (class_name *)NFShmMgr::Instance()->GetHeadObj(type);\
	}\


#define DECLARE_IDCREATE(class_name)\
    _DECLARE_PREALLOCATED_(class_name)\

#define IMPLEMENT_IDCREATE_WITHTYPE(class_name, type, parent_class)\
	_IMPLEMENT_PREALLOCATED_(class_name, type)\
	int  class_name::SetObjSeg(int bType, size_t siObjSize,int iObjCount,const std::string& className, bool useHash, int externalDataSize, int externalItemCount, bool singleton)\
	{\
		NFShmMgr::Instance()->SetObjSegParam(bType, siObjSize,iObjCount, class_name::ResumeObject,\
													   class_name::CreateObject,class_name::DestroyObject, parent_class::GetStaticClassType(),\
													   className, useHash, externalDataSize, externalItemCount, singleton);\
		return 0;\
	}\

#define IMPLEMENT_IDCREATE_WITHTYPE_NOPARENT(class_name,type)\
	_IMPLEMENT_PREALLOCATED_(class_name, type)\
	int  class_name::SetObjSeg(int bType, size_t siObjSize,int iObjCount,const std::string& className, bool useHash, int externalDataSize, int externalItemCount, bool singleton)\
	{\
		NFShmMgr::Instance()->SetObjSegParam((EN_SHMOBJ_TYPE)bType, siObjSize,iObjCount, class_name::ResumeObject,\
													   class_name::CreateObject,class_name::DestroyObject, -1,\
													   className, useHash, externalDataSize, externalItemCount, singleton);\
		return 0;\
	}\



