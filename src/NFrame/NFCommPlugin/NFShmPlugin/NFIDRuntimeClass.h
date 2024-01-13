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

	NFIDRuntimeClass *m_pParent;
	int m_iObjType;

    std::unordered_set<int> m_childrenObjType;
    std::unordered_set<int> m_parentObjType;
};


