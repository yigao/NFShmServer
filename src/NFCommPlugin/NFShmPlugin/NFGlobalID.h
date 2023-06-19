// -------------------------------------------------------------------------
//    @FileName         :    NFGlobalID.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFArrayQueue.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"

class NFShmObj;
class NFShmObjSeg;

typedef struct tagIDIndex
{
	int iID;
	int iIndex;
	int iType;
	NFRawShmPtr<NFShmObj> pObjPtr;
} TIDIndex;

class NFGlobalID :public NFShmObj
{
public:
	NFGlobalID();
	virtual ~NFGlobalID();

	int CreateInit();
	int ResumeInit();

	int GetGlobalID(int iType, int iIndex, NFShmObj *pObj);
    int SetTypeAndIndex(int iType, int iIndex, NFShmObj *pObj);
	int ReleaseID(int iID);
	NFShmObj  *GetObj(int iID);
	static int RegisterClassToObjSeg(NFIPluginManager* pPluginManager, int bType, int iObjSize, int iObjCount, const std::string& className, bool useHash, bool singleton);
	static void *operator new(size_t nSize, void *pBuffer) throw();
	static NFShmObj *ResumeObject(NFIPluginManager* pPluginManager, void *pBuffer);
    static NFShmObj * CreateObject(NFIPluginManager* pPluginManager);
    static void DestroyObject(NFIPluginManager* pPluginManager,NFShmObj *pObj);
    static std::string GetClassName(NFIPluginManager* pPluginManager) { return "NFGlobalID"; }
    static int GetClassType(NFIPluginManager* pPluginManager) { return EOT_GLOBAL_ID; }

	int AddSecond(int iSecond) { m_iSecOffSet += iSecond; return 0; }
	int GetSecOffset() { return m_iSecOffSet; }

	int GetUseCount() const
	{
		return m_iUseCount;
	}

	char *GetOperatingStatictis();
	void SetRunTimeFileID(int iID);

	int Get32UUID();
private:
	int ResumeFileUpdateData();
	int CalcRoundUpdateFile();
	int WriteRound();

protected:
	int m_iThisRoundCountMax;
	int m_iUseCount;
	int m_iThisRoundCount;
	int m_iRoundMultiple;
	int m_iGlobalIDAppendNum;
	char m_szFileName[32];
	NFIntQUEUE m_Queue;
	TIDIndex m_stIDTable[MAX_GLOBALID_NUM];
	time_t m_tRoundBegin;

	int m_iSecOffSet;
	int m_uuid; //32 bit only id
};

