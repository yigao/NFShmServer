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

class NFISharedMemModule;

template<typename className, int classType, typename parentClassName>
class NFShmObjTemplate : public parentClassName
{
public:
    typedef NFShmObjIterator<className, className &, className *, NFISharedMemModule> iterator;
    typedef NFShmObjIterator<className, const className &, const className *, NFISharedMemModule> const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    
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
    
    static std::string GetStaticClassName(NFIPluginManager *pPluginManager)
    {
        return GET_CLASS_NAME(className);
    }
    
    static int GetStaticClassType(NFIPluginManager *pPluginManager)
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
    
    /* 下面的函数 共享内存类系统注册函数， 不要手动调用 */\
    static int RegisterClassToObjSeg(NFIPluginManager *pPluginManager, int bType, size_t siObjSize, int iObjCount, const std::string &strClassName, bool useHash, bool singleton = false)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->RegisterClassToObjSeg(bType, siObjSize, iObjCount, className::ResumeObjectRegisterFunction,
                                                                                className::CreateObjectRegisterFunction, className::DestroyObjectRegisterFunction, parentClassName::GetStaticClassType(pPluginManager),
                                                                                strClassName, useHash, singleton);
        return 0;
    }
    
    static int RegisterClassToObjSeg(NFIPluginManager *pPluginManager, int iObjCount, bool useHash, bool singleton = false)
    {
        pPluginManager->FindModule<NFISharedMemModule>()->RegisterClassToObjSeg(classType, sizeof(className), iObjCount, className::ResumeObjectRegisterFunction,
                                                                                className::CreateObjectRegisterFunction, className::DestroyObjectRegisterFunction, parentClassName::GetStaticClassType(pPluginManager),
                                                                                GetStaticClassName(pPluginManager), useHash, singleton);
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
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ERROR: class:{}, Item:{}, Used:{}, Free:{}", GetStaticClassName(pPluginManager), GetStaticItemCount(pPluginManager), GetStaticUsedCount(pPluginManager), GetStaticFreeCount(pPluginManager));
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
};
