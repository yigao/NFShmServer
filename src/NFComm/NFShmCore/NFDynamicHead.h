#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#define _DECLARE_PREALLOCATED_(class_name)\
    public:\
    static int  SetObjSeg(NFIPluginManager* pPluginManager, int bType, size_t siObjSize,int iObjCount, const std::string& className, bool useHash, int externalDataSize, int externalItemCount, bool singleton = false);  \
    static void* operator new( size_t nSize,void *pBuffer) throw();\
    static class_name* GetObjectByID(NFIPluginManager* pPluginManager, int iID);\
    static int GetNextObjectID(NFIPluginManager* pPluginManager, int iObjID);\
    static int GetNextObjectID(NFIPluginManager* pPluginManager, class_name *pObj);\
    static int   GetItemCount(NFIPluginManager* pPluginManager);\
    static int   GetUsedCount(NFIPluginManager* pPluginManager);\
    static int   GetFreeCount(NFIPluginManager* pPluginManager);\
    static int   GetUsedHead(NFIPluginManager* pPluginManager);\
    static int   GetFreeHead(NFIPluginManager* pPluginManager);           \
    static int   GetExternalDataSize(NFIPluginManager* pPluginManager);\
    static int   GetExternalItemCount(NFIPluginManager* pPluginManager);  \
    static char* GetExternalBuffer(NFIPluginManager* pPluginManager);\
    static std::string GetClassName(NFIPluginManager* pPluginManager);    \
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
    static NFShmObj * CreateObject(NFIPluginManager* pPluginManager);\
    static NFShmObj * ResumeObject(NFIPluginManager* pPluginManager,void *pVoid);\
    static void DestroyObject(NFIPluginManager* pPluginManager,NFShmObj *pObj);\
    static int DestroyObjAutoErase(NFIPluginManager* pPluginManager,int maxNum);\
	static class_name* Instance(NFIPluginManager* pPluginManager);\
	static class_name* GetInstance(NFIPluginManager* pPluginManager);\


#define _IMPLEMENT_PREALLOCATED_(class_name, type) \
	class_name* class_name::GetObjectByID(NFIPluginManager* pPluginManager, int iID)\
	{\
        return (class_name*)pPluginManager->FindModule<NFISharedMemModule>()->GetObj(type, iID);\
	}\
	int class_name::GetItemCount(NFIPluginManager* pPluginManager)\
	{\
	    return pPluginManager->FindModule<NFISharedMemModule>()->GetItemCount(type);\
	}\
	int class_name::GetUsedCount(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetUsedCount(type);\
	}\
	int class_name::GetFreeCount(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetFreeCount(type);\
	}\
	int class_name::GetUsedHead(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetUsedHead(type);\
	}\
	int class_name::GetFreeHead(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetFreeHead(type);\
	}                                                 \
	int class_name::GetExternalDataSize(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetExternalDataSize(type);\
	}\
	int class_name::GetExternalItemCount(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetExternalItemCount(type);\
	}\
    char* class_name::GetExternalBuffer(NFIPluginManager* pPluginManager)\
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetExternalBuffer(type);\
	}\
	std::string class_name::GetClassName(NFIPluginManager* pPluginManager) \
	{\
        return pPluginManager->FindModule<NFISharedMemModule>()->GetClassName(type);\
	}                                                 \
    int class_name::GetStaticClassType()           \
    {\
        return type;\
    }\
	int class_name::GetClassType() const\
	{\
        return FindModule<NFISharedMemModule>()->GetClassType(type);\
	}\
	void* class_name::operator new( size_t nSize,void *pBuffer ) throw()\
	{\
		return  pBuffer;\
	}\
	int class_name::GetNextObjectID(NFIPluginManager* pPluginManager, int iObjID) \
	{ \
		if (0 > iObjID)\
		{\
			return -1;\
		}\
		return pPluginManager->FindModule<NFISharedMemModule>()->GetNextObjectID(type, iObjID);\
	}\
	int class_name::GetNextObjectID(NFIPluginManager* pPluginManager, class_name *pstObj) \
	{ \
		int iObjID = pstObj->GetObjectID();\
		if (0 > iObjID)\
		{\
			return -1;\
		}\
		return GetNextObjectID(pPluginManager, iObjID); \
	}\
	int class_name::GetObjectID()\
	{\
		if(m_iObjectID == INVALID_ID)\
		{\
			m_iObjectID = FindModule<NFISharedMemModule>()->GetObjectID(type, this);\
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
	NFShmObj * class_name::CreateObject(NFIPluginManager* pPluginManager)\
	{\
		class_name *pTmp = NULL;\
		void* pVoid = pPluginManager->FindModule<NFISharedMemModule>()->AllocMemForObject(type);      \
		if(!pVoid)\
		{\
			NFLogError(NF_LOG_SYSTEMLOG, 0, "ERROR: class:{}, Item:{}, Used:{}, Free:{}", GetClassName(pPluginManager), GetItemCount(pPluginManager), GetUsedCount(pPluginManager), GetFreeCount(pPluginManager)); \
            return NULL;\
		}\
        pTmp = new (pVoid) class_name(pPluginManager);\
		return pTmp;\
	}\
	NFShmObj * class_name::ResumeObject(NFIPluginManager* pPluginManager, void * pVoid)\
	{\
		class_name *pTmp = NULL;\
		pTmp = new (pVoid) class_name(pPluginManager);\
		return pTmp;\
	}\
	void  class_name::DestroyObject(NFIPluginManager* pPluginManager, NFShmObj *pObj)\
	{\
		class_name *pTmp = NULL;\
		pTmp = (class_name*)pObj;\
        pPluginManager->FindModule<NFISharedMemModule>()->FreeMemForObject(type, pTmp);\
		return;\
	}\
    int class_name::DestroyObjAutoErase(NFIPluginManager* pPluginManager, int maxNum = INVALID_ID)\
    {\
        return pPluginManager->FindModule<NFISharedMemModule>()->DestroyObjAutoErase(type, maxNum);\
    }\
	class_name* class_name::Instance(NFIPluginManager* pPluginManager)\
	{\
		return (class_name *)pPluginManager->FindModule<NFISharedMemModule>()->GetHeadObj(type);\
	}\
	class_name* class_name::GetInstance(NFIPluginManager* pPluginManager)\
	{\
		return (class_name *)pPluginManager->FindModule<NFISharedMemModule>()->GetHeadObj(type);\
	}\


#define DECLARE_IDCREATE(class_name)\
    _DECLARE_PREALLOCATED_(class_name)\

#define IMPLEMENT_IDCREATE_WITHTYPE(class_name, type, parent_class) \
	_IMPLEMENT_PREALLOCATED_(class_name, type)\
	int  class_name::SetObjSeg(NFIPluginManager* pPluginManager, int bType, size_t siObjSize,int iObjCount,const std::string& className, bool useHash, int externalDataSize, int externalItemCount, bool singleton)\
	{\
		pPluginManager->FindModule<NFISharedMemModule>()->SetObjSegParam(bType, siObjSize,iObjCount, class_name::ResumeObject,\
													   class_name::CreateObject,class_name::DestroyObject, parent_class::GetStaticClassType(),\
													   className, useHash, externalDataSize, externalItemCount, singleton);\
		return 0;\
	}\

#define IMPLEMENT_IDCREATE_WITHTYPE_NOPARENT(class_name,type)\
	_IMPLEMENT_PREALLOCATED_(class_name, type)\
	int  class_name::SetObjSeg(NFIPluginManager* pPluginManager, int bType, size_t siObjSize,int iObjCount,const std::string& className, bool useHash, int externalDataSize, int externalItemCount, bool singleton)\
	{\
		pPluginManager->FindModule<NFISharedMemModule>()->SetObjSegParam((EN_SHMOBJ_TYPE)bType, siObjSize,iObjCount, class_name::ResumeObject,\
													   class_name::CreateObject,class_name::DestroyObject, -1,\
													   className, useHash, externalDataSize, externalItemCount, singleton);\
		return 0;\
	}\



