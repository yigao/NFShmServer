// -------------------------------------------------------------------------
//    @FileName         :    NFCKernelModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFCKernelModule
//    @Desc             :
// -------------------------------------------------------------------------

#ifndef NFC_KERNEL_MODULE_H
#define NFC_KERNEL_MODULE_H

#include "NFComm/NFPluginModule/NFIKernelModule.h"

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <unordered_map>

/*
    63-60 4b  worldid
    59-48 12b zoneid
    47-44 4b  checkseq
    43-32 12b seq
    31-0  32b time
*/
enum
{
    UNIQUE_ID_START_TIME = 1560000000, //Jun  8 21:20:00 2019
    WORLDID_MASK        = 0xF000000000000000,
    ZONEID_MASK         = 0x0FFF000000000000,
    CHECK_SEQ_MASK      = 0x0000F00000000000,
    ONE_SECOND_SEQ_MASK = 0x00000FFF00000000,
    ADAPTIVE_TIME_MASK  = 0x00000000FFFFFFFF,
    ONE_SECOND_SEQ_NUM = 0xFFF,
};

//由于客户端LUA 中 int64_t 类型最大只能表示 2的53次方，所以角色cid由原来的64位改成现在的54位表示(4表示世界ID,12位区服ID+4checkseq(重启16次)+32位序号)
/*
    63-60 4b  worldid
    59-48 12b zoneid
    47-44 4b  checkseq
    43-32 12b seq
    31-0  32b time
*/
enum
{
    WORLDID_53_MASK        = 0x000F00000000000000,
    ZONEID_53_MASK         = 0x0000FFF000000000,
    CHECK_SEQ_53_MASK      = 0x0000000F00000000,
};

class NFCKernelModule : public NFIKernelModule
{
public:
	explicit NFCKernelModule(NFIPluginManager* p);
	virtual ~NFCKernelModule();

	virtual bool Init() override;
	virtual bool Shut() override;
	virtual bool Finalize() override;

	virtual bool BeforeShut() override;

	virtual bool Execute() override;


	virtual uint64_t GetUUID() override;
	virtual std::string GetMD5(const std::string& str) override;
	virtual uint32_t GetCRC32(const std::string& s) override;
	virtual uint16_t GetCRC16(const std::string& s) override;
	virtual std::string Base64Encode(const std::string& s) override;
	virtual std::string Base64Decode(const std::string& s) override;

	virtual uint64_t Get64UUID() override;
    virtual uint64_t Get53UUID() override;
	virtual uint64_t Get32UUID() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    int OnKillServerProcess(uint64_t unLinkId, NFDataPackage& packet);
protected:
    int Next(int iNowSec);
    int Next53(int iNowSec);
    uint8_t UpdateCheckSeq(const std::string& szCheckSeqFile);
private:
	std::string szUniqIDFile;
    uint64_t m_ullMask;
    uint64_t m_ucCheckSeq;
    uint64_t m_ushSequence;
    uint64_t m_iAdaptiveTime;
    uint64_t m_iZoneId;
    uint64_t m_iWorldId;
    uint64_t mLastGuidTimeStamp;
};

#endif

