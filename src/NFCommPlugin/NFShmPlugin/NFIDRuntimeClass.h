// -------------------------------------------------------------------------
//    @FileName         :    NFIDRuntimeClass.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#define MAXTYPENUM   500

class NFIDRuntimeClass;
class NFShmObj;
class NFShmObjSeg;
class NFIPluginManager;

class NFIDRuntimeClass
{
public:
	NFIDRuntimeClass();
	~NFIDRuntimeClass() {}

	std::string m_pszName;
	NFShmObj *(*m_pCreatefn)(NFIPluginManager* pPluginManager);
	void(*m_pDestroyFn)(NFIPluginManager* pPluginManager, NFShmObj *);
	NFIDRuntimeClass *m_pParent;
	int m_iSelfType;
	NFShmObjSeg *m_pObjSeg;
	bool m_iUseHash;
	int m_iExternalDataSize;
    int m_iExternalItemCount;
};


