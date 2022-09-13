// -------------------------------------------------------------------------
//    @FileName         :    NFCKernelModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCKernelModule
//    @Desc             :
// -------------------------------------------------------------------------

#ifndef NFC_KERNEL_MODULE_H
#define NFC_KERNEL_MODULE_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include <unordered_map>
#include "NFComm/NFPluginModule/NFTimerObj.h"

class NFIObject;
class NFITimerModule;

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

    virtual void OnTimer(uint32_t nTimerID);

    int OnKillServerProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
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

