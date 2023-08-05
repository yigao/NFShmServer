// -------------------------------------------------------------------------
//    @FileName         :    NFFishTraceMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishTraceMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFFishTrace.h"
#include "HMTraceBin.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFLogicCommon.h"

#define DEFAULT_TRACENUM 1500

class NFFishTraceMgr : public NFShmObj
{
public:
	NFFishTraceMgr();

	virtual ~NFFishTraceMgr();

    int CreateInit();
    int ResumeInit();
public:
    virtual int LoadConfig(uint32_t roomId);
    int GetFileContainMD5(const std::string& strFileName, std::string& fileMd5);
public:

	CHMPoint GetPointByIndex(unsigned int uTraceId, unsigned int uIndex);
	int GetTracePointCount(unsigned int uTraceId);

private:
	bool ReadTracePack(const std::string& strPackFile);
	bool ReadTraceBin(std::ifstream& tracdPackFile, CHMTraceBin& traceBin);
	int  GetBinLen(int iType);
private:
    CHMTraceBin* GetTraceBin(uint32_t id);
    CHMTraceBin* InsertTraceBin(uint32_t id);
private:
    uint32_t m_roomId;
	NFShmHashMap<uint32_t, CHMTraceBin, DEFAULT_TRACENUM> m_FishTraceMap;
    NFCommonStr m_szMD5;
	DECLARE_IDCREATE(NFFishTraceMgr);
};
