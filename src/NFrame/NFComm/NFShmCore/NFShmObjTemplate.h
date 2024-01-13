// -------------------------------------------------------------------------
//    @FileName         :    NFShmObjTemplate.h
//    @Author           :    gaoyi
//    @Date             :    23-10-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmObjTemplate
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmObjIterator.h"
#include "NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

template<typename className, int classType, typename parentClassName>
class NFShmObjTemplate : public parentClassName
{
    static_assert(!std::is_same<parentClassName, className>::value, "parentClassName is equal to the className");
public:
    typedef NFShmObjIterator<className, className &, className *, NFISharedMemModule> iterator;
    typedef NFShmObjIterator<className, const className &, const className *, NFISharedMemModule> const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
public:
    NFShmObjTemplate()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual ~NFShmObjTemplate()
    {
    
    }
    
    static int GetStaticItemCount(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->GetItemCount(classType);
    }
    
    static int GetStaticUsedCount(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->GetUsedCount(classType);
    }
    
    static int GetStaticFreeCount(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->GetFreeCount(classType);
    }
    
    static std::string GetStaticClassName()
    {
        return typeid(className).name();
    }
    
    static int GetStaticClassType()
    {
        return classType;
    }
    
    static iterator Begin(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->IterBegin(classType);
    }
    
    static iterator End(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->IterEnd(classType);
    }
    
    static reverse_iterator RBegin(NFIPluginManager *pPluginManager)
    {
        return reverse_iterator(End(pPluginManager));
    }
    
    static reverse_iterator REnd(NFIPluginManager *pPluginManager)
    {
        return reverse_iterator(Begin(pPluginManager));
    }
    
    static iterator Erase(NFIPluginManager *pPluginManager, iterator iter)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->Erase(iter);
    }
    
    static className *CreateObj(NFIPluginManager *pPluginManager)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->CreateObj(classType));
    }
    
    static className *CreateObjByHashKey(NFIPluginManager *pPluginManager, ShmObjHashKey hashKey)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->CreateObjByHashKey(classType, hashKey));
    }
    
    static void DestroyObj(NFIPluginManager *pPluginManager, className *pObj)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->DestroyObj(pObj);
    }
    
    static void ClearAllObj(NFIPluginManager *pPluginManager)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->ClearAllObj(classType);
    }
    
    static className *GetObjByObjId(NFIPluginManager *pPluginManager, int iObjId)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->GetObjByObjId(classType, iObjId));
    }
    
    static className *GetObjByGlobalId(NFIPluginManager *pPluginManager, int iGlobalID, bool withChildrenType = false)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->GetObjByGlobalId(classType, iGlobalID, withChildrenType));
    }
    
    static className *GetObjByHashKey(NFIPluginManager *pPluginManager, ShmObjHashKey hashKey)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->GetObjByHashKey(classType, hashKey));
    }
    
    static int DestroyObjAutoErase(NFIPluginManager *pPluginManager, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION &func = NULL)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->DestroyObjAutoErase(classType, maxNum, func);
    }
    
    static className *Instance(NFIPluginManager *pPluginManager)
    {
        return (className *) pPluginManager->FindModule<NFISharedMemModule>()->GetHeadObj(classType);
    }
    
    static className *GetInstance(NFIPluginManager *pPluginManager)
    {
        return (className *) pPluginManager->FindModule<NFISharedMemModule>()->GetHeadObj(classType);
    }
    
    static int RegisterClassToObjSeg(NFIPluginManager *pPluginManager, int bType, size_t siObjSize, int iObjCount, const std::string &strClassName, bool useHash, bool singleton = false)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->RegisterClassToObjSeg(bType, siObjSize, iObjCount, className::ResumeObjectRegisterFunction,
                                                                                className::CreateObjectRegisterFunction, className::DestroyObjectRegisterFunction, parentClassName::GetStaticClassType(),
                                                                                strClassName, useHash, singleton);
        return 0;
    }
    
    static void *operator new(size_t nSize, void *pBuffer) throw()
    {
        return pBuffer;
    }
    
    static NFShmObj *CreateObjectRegisterFunction(NFIPluginManager *pPluginManager)
    {
        className *pTmp = NULL;
        void *pVoid = pPluginManager->FindModule<NFISharedMemModule>()->AllocMemForObject(classType);
        if (!pVoid)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ERROR: class:{}, Item:{}, Used:{}, Free:{}", GetStaticClassName(), GetStaticItemCount(pPluginManager), GetStaticUsedCount(pPluginManager), GetStaticFreeCount(pPluginManager));
            return NULL;
        }
        pTmp = new(pVoid) className();
        return pTmp;
    }
    
    static NFShmObj *ResumeObjectRegisterFunction(NFIPluginManager *pPluginManager, void *pVoid)
    {
        className *pTmp = NULL;
        pTmp = new(pVoid) className();
        return pTmp;
    }
    
    static void DestroyObjectRegisterFunction(NFIPluginManager *pPluginManager, NFShmObj *pObj)
    {
        className *pTmp = NULL;
        pTmp = (className *) pObj;
        (*pTmp).className::~className();
        pPluginManager->FindModule<NFISharedMemModule>()->FreeMemForObject(classType, pTmp);
        return;
    }
    
public:
    virtual int GetClassType() const
    {
        return classType;
    }
};

template<typename className, int classType>
class NFShmObjTemplateNoParent
{
public:
    typedef NFShmObjIterator<className, className &, className *, NFISharedMemModule> iterator;
    typedef NFShmObjIterator<className, const className &, const className *, NFISharedMemModule> const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
public:
    NFShmObjTemplateNoParent()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual ~NFShmObjTemplateNoParent()
    {
    
    }
public:
    static int GetStaticItemCount(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->GetItemCount(classType);
    }
    
    static int GetStaticUsedCount(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->GetUsedCount(classType);
    }
    
    static int GetStaticFreeCount(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->GetFreeCount(classType);
    }
    
    static std::string GetStaticClassName()
    {
        return typeid(className).name();
    }
    
    static int GetStaticClassType()
    {
        return classType;
    }
    
    static iterator Begin(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->IterBegin(classType);
    }
    
    static iterator End(NFIPluginManager *pPluginManager)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->IterEnd(classType);
    }
    
    static reverse_iterator RBegin(NFIPluginManager *pPluginManager)
    {
        return reverse_iterator(End(pPluginManager));
    }
    
    static reverse_iterator REnd(NFIPluginManager *pPluginManager)
    {
        return reverse_iterator(Begin(pPluginManager));
    }
    
    static iterator Erase(NFIPluginManager *pPluginManager, iterator iter)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->Erase(iter);
    }
    
    static className *CreateObj(NFIPluginManager *pPluginManager)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->CreateObj(classType));
    }
    
    static className *CreateObjByHashKey(NFIPluginManager *pPluginManager, ShmObjHashKey hashKey)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->CreateObjByHashKey(classType, hashKey));
    }
    
    static void DestroyObj(NFIPluginManager *pPluginManager, className *pObj)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->DestroyObj(pObj);
    }
    
    static void ClearAllObj(NFIPluginManager *pPluginManager)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->ClearAllObj(classType);
    }
    
    static className *GetObjByObjId(NFIPluginManager *pPluginManager, int iObjId)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->GetObjByObjId(classType, iObjId));
    }
    
    static className *GetObjByGlobalId(NFIPluginManager *pPluginManager, int iGlobalID, bool withChildrenType = false)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->GetObjByGlobalId(classType, iGlobalID, withChildrenType));
    }
    
    static className *GetObjByHashKey(NFIPluginManager *pPluginManager, ShmObjHashKey hashKey)
    {
        return dynamic_cast<className *>(pPluginManager->FindModule<NFISharedMemModule>()->GetObjByHashKey(classType, hashKey));
    }
    
    static int DestroyObjAutoErase(NFIPluginManager *pPluginManager, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION &func = NULL)
    {
        return pPluginManager->FindModule<NFISharedMemModule>()->DestroyObjAutoErase(classType, maxNum, func);
    }
    
    static className *Instance(NFIPluginManager *pPluginManager)
    {
        return (className *) pPluginManager->FindModule<NFISharedMemModule>()->GetHeadObj(classType);
    }
    
    static className *GetInstance(NFIPluginManager *pPluginManager)
    {
        return (className *) pPluginManager->FindModule<NFISharedMemModule>()->GetHeadObj(classType);
    }
    
    static int RegisterClassToObjSeg(NFIPluginManager *pPluginManager, int bType, size_t siObjSize, int iObjCount, const std::string &strClassName, bool useHash, bool singleton = false)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->RegisterClassToObjSeg(bType, siObjSize, iObjCount, className::ResumeObjectRegisterFunction,
                                                                                className::CreateObjectRegisterFunction, className::DestroyObjectRegisterFunction, -1,
                                                                                strClassName, useHash, singleton);
        return 0;
    }
    
    static void *operator new(size_t nSize, void *pBuffer) throw()
    {
        return pBuffer;
    }
    
    static NFShmObj *CreateObjectRegisterFunction(NFIPluginManager *pPluginManager)
    {
        className *pTmp = NULL;
        void *pVoid = pPluginManager->FindModule<NFISharedMemModule>()->AllocMemForObject(classType);
        if (!pVoid)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ERROR: class:{}, Item:{}, Used:{}, Free:{}", GetStaticClassName(), GetStaticItemCount(pPluginManager), GetStaticUsedCount(pPluginManager), GetStaticFreeCount(pPluginManager));
            return NULL;
        }
        pTmp = new(pVoid) className();
        return pTmp;
    }
    
    static NFShmObj *ResumeObjectRegisterFunction(NFIPluginManager *pPluginManager, void *pVoid)
    {
        className *pTmp = NULL;
        pTmp = new(pVoid) className();
        return pTmp;
    }
    
    static void DestroyObjectRegisterFunction(NFIPluginManager *pPluginManager, NFShmObj *pObj)
    {
        className *pTmp = NULL;
        pTmp = (className *) pObj;
        (*pTmp).className::~className();
        pPluginManager->FindModule<NFISharedMemModule>()->FreeMemForObject(classType, pTmp);
        return;
    }
public:
    virtual int GetClassType() const
    {
        return classType;
    }
};

template<typename className, int classType, typename parentClassName>
class NFShmObjGlobalTemplate : public parentClassName
{
public:
    typedef NFShmObjIterator<className, className &, className *, NFISharedMemModule> iterator;
    typedef NFShmObjIterator<className, const className &, const className *, NFISharedMemModule> const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
public:
    NFShmObjGlobalTemplate()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual ~NFShmObjGlobalTemplate()
    {
    
    }
public:
    static int GetStaticItemCount()
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetItemCount(classType);
    }
    
    static int GetStaticUsedCount()
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetUsedCount(classType);
    }
    
    static int GetStaticFreeCount()
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetFreeCount(classType);
    }
    
    static std::string GetStaticClassName()
    {
        return typeid(className).name();
    }
    
    static int GetStaticClassType()
    {
        return classType;
    }
    
    static iterator Begin()
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->IterBegin(classType);
    }
    
    static iterator End()
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->IterEnd(classType);
    }
    
    static reverse_iterator RBegin()
    {
        return reverse_iterator(End());
    }
    
    static reverse_iterator REnd()
    {
        return reverse_iterator(Begin());
    }
    
    static iterator Erase(iterator iter)
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->Erase(iter);
    }
    
    static className *CreateObj()
    {
        return dynamic_cast<className *>(NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->CreateObj(classType));
    }
    
    static className *CreateObjByHashKey(ShmObjHashKey hashKey)
    {
        return dynamic_cast<className *>(NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->CreateObjByHashKey(classType, hashKey));
    }
    
    static void DestroyObj(className *pObj)
    {
        NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->DestroyObj(pObj);
    }
    
    static void ClearAllObj()
    {
        NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->ClearAllObj(classType);
    }
    
    static className *GetObjByObjId(int iObjId)
    {
        return dynamic_cast<className *>(NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetObjByObjId(classType, iObjId));
    }
    
    static className *GetObjByGlobalId(int iGlobalID, bool withChildrenType = false)
    {
        return dynamic_cast<className *>(NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetObjByGlobalId(classType, iGlobalID, withChildrenType));
    }
    
    static className *GetObjByHashKey(ShmObjHashKey hashKey)
    {
        return dynamic_cast<className *>(NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetObjByHashKey(classType, hashKey));
    }
    
    static int DestroyObjAutoErase(int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION &func = NULL)
    {
        return NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->DestroyObjAutoErase(classType, maxNum, func);
    }
    
    static className *Instance()
    {
        return (className *) NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetHeadObj(classType);
    }
    
    static className *GetInstance()
    {
        return (className *) NFGlobalSystem::Instance()->GetGlobalPluginManager()->FindModule<NFISharedMemModule>()->GetHeadObj(classType);
    }
    
    static int RegisterClassToObjSeg(NFIPluginManager *pPluginManager, int bType, size_t siObjSize, int iObjCount, const std::string &strClassName, bool useHash, bool singleton = false)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->RegisterClassToObjSeg(bType, siObjSize, iObjCount, className::ResumeObjectRegisterFunction,
                                                                                className::CreateObjectRegisterFunction, className::DestroyObjectRegisterFunction, parentClassName::GetStaticClassType(),
                                                                                strClassName, useHash, singleton);
        return 0;
    }
    
    static void *operator new(size_t nSize, void *pBuffer) throw()
    {
        return pBuffer;
    }
    
    static NFShmObj *CreateObjectRegisterFunction(NFIPluginManager *pPluginManager)
    {
        className *pTmp = NULL;
        void *pVoid = pPluginManager->FindModule<NFISharedMemModule>()->AllocMemForObject(classType);
        if (!pVoid)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ERROR: class:{}, Item:{}, Used:{}, Free:{}", GetStaticClassName(), GetStaticItemCount(), GetStaticUsedCount(), GetStaticFreeCount());
            return NULL;
        }
        pTmp = new(pVoid) className();
        return pTmp;
    }
    
    static NFShmObj *ResumeObjectRegisterFunction(NFIPluginManager *pPluginManager, void *pVoid)
    {
        className *pTmp = NULL;
        pTmp = new(pVoid) className();
        return pTmp;
    }
    
    static void DestroyObjectRegisterFunction(NFIPluginManager *pPluginManager, NFShmObj *pObj)
    {
        className *pTmp = NULL;
        pTmp = (className *) pObj;
        (*pTmp).className::~className();
        pPluginManager->FindModule<NFISharedMemModule>()->FreeMemForObject(classType, pTmp);
        return;
    }
public:
    virtual int GetClassType() const
    {
        return classType;
    }
};
