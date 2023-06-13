#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmObjIterator.h"

class NFISharedMemModule;

/**
 * @brief 不要调用CreateObject，ResumeObject, DestroyObject 创建对象，会崩溃， 走系统创建函数
 */

#define _DECLARE_PREALLOCATED_(class_name)\
public:\
    typedef NFShmObjIterator<class_name, class_name &, class_name *, NFISharedMemModule> iterator;\
    typedef NFShmObjIterator<class_name, const class_name &, const class_name *, NFISharedMemModule> const_iterator;\
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;\
    typedef std::reverse_iterator<iterator> reverse_iterator;\
    static int  SetObjSeg(NFIPluginManager* pPluginManager, int bType, size_t siObjSize,int iObjCount, const std::string& className, bool useHash, bool singleton = false);  \
    static void* operator new( size_t nSize,void *pBuffer) throw();\
    static class_name* GetObjectByID(NFIPluginManager* pPluginManager, int iID);\
    static int   GetItemCount(NFIPluginManager* pPluginManager);\
    static int   GetUsedCount(NFIPluginManager* pPluginManager);\
    static int   GetFreeCount(NFIPluginManager* pPluginManager);\
    static std::string GetClassName(NFIPluginManager* pPluginManager) { return #class_name; }\
    static iterator Begin(NFIPluginManager* pPluginManager);\
    static iterator End(NFIPluginManager* pPluginManager);\
    static reverse_iterator RBegin(NFIPluginManager* pPluginManager);\
    static reverse_iterator REnd(NFIPluginManager* pPluginManager);\
    static NFShmObj * CreateObject(NFIPluginManager* pPluginManager);\
    static NFShmObj * ResumeObject(NFIPluginManager* pPluginManager,void *pVoid);\
    static void DestroyObject(NFIPluginManager* pPluginManager,NFShmObj *pObj);\
    static int DestroyObjAutoErase(NFIPluginManager* pPluginManager,int maxNum);\
	static class_name* Instance(NFIPluginManager* pPluginManager);\
	static class_name* GetInstance(NFIPluginManager* pPluginManager);\
    static int GetClassType(NFIPluginManager* pPluginManager);      \
    virtual std::string GetClassName() const;\
    virtual int GetClassType() const;     \
    virtual int GetItemCount() const;\
    virtual int GetUsedCount() const;\
    virtual int GetFreeCount() const;\
    virtual int GetObjectID();\
    virtual int64_t GetHashID();\
    virtual void SetHashID(int64_t Id);\
    virtual std::string ClassTypeInfo() { return NF_FORMAT("{} type:{}", #class_name, GetClassType());}\



#define _IMPLEMENT_PREALLOCATED_(class_name, type) \
    class_name::iterator class_name::Begin(NFIPluginManager* pPluginManager) \
    {\
        return pPluginManager->FindModule<NFISharedMemModule>()->IterBegin(type); \
    }\
    class_name::iterator class_name::End(NFIPluginManager* pPluginManager)\
    {\
        return pPluginManager->FindModule<NFISharedMemModule>()->IterEnd(type);\
    }\
    class_name::reverse_iterator class_name::RBegin(NFIPluginManager* pPluginManager) \
    {\
        return reverse_iterator(End(pPluginManager)); \
    }\
    class_name::reverse_iterator class_name::REnd(NFIPluginManager* pPluginManager)\
    {\
        return reverse_iterator(Begin(pPluginManager));\
    }\
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
	std::string class_name::GetClassName() const\
	{\
        return FindModule<NFISharedMemModule>()->GetClassName(type);\
	}                                                 \
    int class_name::GetClassType(NFIPluginManager* pPluginManager)           \
    {\
        return type;\
    }\
	int class_name::GetClassType() const\
	{\
        return FindModule<NFISharedMemModule>()->GetClassType(type);\
	}\
    int class_name::GetItemCount() const\
    {\
        return FindModule<NFISharedMemModule>()->GetItemCount(type);\
    }\
    int class_name::GetUsedCount() const\
    {\
        return FindModule<NFISharedMemModule>()->GetUsedCount(type);\
    }\
    int class_name::GetFreeCount() const\
    {\
        return FindModule<NFISharedMemModule>()->GetFreeCount(type);\
    }\
    void* class_name::operator new( size_t nSize,void *pBuffer ) throw()\
	{\
		return  pBuffer;\
	}\
	int class_name::GetObjectID()\
	{\
		if(m_iObjectID == INVALID_ID)\
		{\
			m_iObjectID = FindModule<NFISharedMemModule>()->GetObjectID(type, this);\
		}\
		return m_iObjectID;\
	}\
    int64_t class_name::GetHashID()\
    {\
        return m_iHashID;\
    }\
    void class_name::SetHashID(int64_t Id)\
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
        pTmp = new (pVoid) class_name();\
		return pTmp;\
	}\
	NFShmObj * class_name::ResumeObject(NFIPluginManager* pPluginManager, void * pVoid)\
	{\
		class_name *pTmp = NULL;\
		pTmp = new (pVoid) class_name();\
		return pTmp;\
	}\
	void  class_name::DestroyObject(NFIPluginManager* pPluginManager, NFShmObj *pObj)\
	{\
		class_name *pTmp = NULL;\
		pTmp = (class_name*)pObj;\
        (*pTmp).class_name::~class_name();\
        pPluginManager->FindModule<NFISharedMemModule>()->FreeMemForObject(type, pTmp);\
		return;\
	}\
    int class_name::DestroyObjAutoErase(NFIPluginManager* pPluginManager, int maxNum)\
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
	int  class_name::SetObjSeg(NFIPluginManager* pPluginManager, int bType, size_t siObjSize,int iObjCount,const std::string& className, bool useHash, bool singleton)\
	{\
		pPluginManager->FindModule<NFISharedMemModule>()->SetObjSegParam(bType, siObjSize,iObjCount, class_name::ResumeObject,\
													   class_name::CreateObject,class_name::DestroyObject, parent_class::GetClassType(pPluginManager),\
													   className, useHash, singleton);\
		return 0;\
	}\

#define IMPLEMENT_IDCREATE_WITHTYPE_NOPARENT(class_name,type)\
	_IMPLEMENT_PREALLOCATED_(class_name, type)\
	int  class_name::SetObjSeg(NFIPluginManager* pPluginManager, int bType, size_t siObjSize,int iObjCount,const std::string& className, bool useHash, bool singleton)\
	{\
		pPluginManager->FindModule<NFISharedMemModule>()->SetObjSegParam(bType, siObjSize,iObjCount, class_name::ResumeObject,\
													   class_name::CreateObject,class_name::DestroyObject, -1,\
													   className, useHash, singleton);\
		return 0;\
	}\



