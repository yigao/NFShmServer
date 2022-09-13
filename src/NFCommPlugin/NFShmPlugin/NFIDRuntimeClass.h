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

class NFIDRuntimeClass
{
public:
	NFIDRuntimeClass();
	~NFIDRuntimeClass() {}

	static NFShmObj   *GetObj(int iType, int iIndex);

	static NFShmObj   *CreateObj(int iType);
	static NFShmObj   *GetHeadObj(int iType);
	static NFShmObj   *GetNextObj(int iType, NFShmObj *pObj);
	static void     DestroyObj(NFShmObj *pObj);
	static NFShmObj   *GetObjFromGlobalID(int iGlobalID, int iType, int iStrongType = 1);
	// 根据混合ID获得对象
	// iType不为-1表示校验对象类型
	static NFShmObj *GetObjFromMiscID(int iMiscID, int iType = -1);

	static bool   IsEnd(int iType, int iIndex);

	static bool IsTypeValid(int iType);

	std::string m_pszName;
	NFShmObj *(*m_pCreatefn)();
	void(*m_pDestroyFn)(NFShmObj *);
	NFIDRuntimeClass *m_pParent;
	int m_iSelfType;
	NFShmObjSeg *m_pObjSeg;
	bool m_iUseHash;
	int m_iExternalDataSize;
    int m_iExternalItemCount;
};


