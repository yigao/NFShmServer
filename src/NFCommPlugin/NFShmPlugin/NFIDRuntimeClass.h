// -------------------------------------------------------------------------
//    @FileName         :    NFIDRuntimeClass.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <unordered_set>

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
	int m_iIndexCount;
    int m_iIndexTime;
    std::unordered_set<int> m_childrenObjType;
    std::unordered_set<int> m_parentObjType;
};


