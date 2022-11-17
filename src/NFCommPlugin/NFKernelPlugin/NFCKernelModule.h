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
    63-61 3b  worldtype
    60-49 12b worldid
    48-45 4b  instid
    44-33 12b seq
    32-30 3b  checkseq
    29-0  30b time
*/
enum
{
    UNIQUE_ID_START_TIME = 1560000000, //Jun  8 21:20:00 2019
    WORLD_TYPE_MASK = 0x07,
    ADAPTIVE_TIME_MASK = 0x1FFFFFFF,
    CHECK_SEQ_MASK = 0x07,
    ONE_SECOND_SEQ_MASK = 0xFFF,
    INSTANCE_MASK = 0x0F,
    ZONEID_MASK = 0x0FFF,
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
	virtual uint64_t Get32UUID() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    int OnKillServerProcess(uint64_t unLinkId, NFDataPackage& packet);
protected:
    int Next(int iNowSec);
    uint8_t UpdateCheckSeq(const std::string& szCheckSeqFile);
private:
	std::string szUniqIDFile;
    uint64_t m_ullMask;
    uint8_t m_ucCheckSeq;
    uint16_t m_ushSequence;
    int m_iAdaptiveTime;
    uint32_t m_iZoneId;
    uint64_t mLastGuidTimeStamp;
};

#endif

