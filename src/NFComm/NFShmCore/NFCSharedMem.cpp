// -------------------------------------------------------------------------
//    @FileName         :    NFCSharedMem.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFCSharedMem.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFServerTime.h"

#define MAYEX_SHM_CAN_BE_DESTROY_SAFE_MAGIC 123456789
#define MAYEX_SHM_INIT_SUCCESS_MAGIC 987654321
#define MAGIC_SERVER_VER 100001

char *NFCSharedMem::pbCurrentShm = NULL;
bool NFCSharedMem::s_bCheckInitSuccessFlag = false;

EN_OBJ_MODE NFCSharedMem::GetInitMode()
{
	return m_enRunMode;
}

void  NFCSharedMem::SetInitMode(EN_OBJ_MODE mode)
{
	m_enRunMode = mode;
}

void *NFCSharedMem::operator new(size_t siSize) throw()
{
	char* pTemp = NULL;

	if (!pbCurrentShm)
	{
		return NULL;
	}

	pTemp = pbCurrentShm;
	return (void *)pTemp;
}

void NFCSharedMem::operator delete(void *pMem)
{
    std::cout << "delete ..." << std::endl;
}

#if NF_PLATFORM == NF_PLATFORM_WIN
NFCSharedMem::NFCSharedMem(key_t nKey, size_t siSize, EN_OBJ_MODE enInitFlag, HANDLE shemID)
#else
NFCSharedMem::NFCSharedMem(key_t nKey, size_t siSize, EN_OBJ_MODE enInitFlag, int shemID)
#endif
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	m_shemID = shemID;
#else
	m_shemID = shemID;
#endif
	m_pbCurrentSegMent = pbCurrentShm + sizeof(NFCSharedMem);

	if (EN_OBJ_MODE_RECOVER == enInitFlag)
	{
		if (m_iServerCheckVersion != MAGIC_SERVER_VER)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "shm check version error,need version {},cur version {}\n", m_iServerCheckVersion, MAGIC_SERVER_VER);
			NFSLEEP(1000);
			exit(0);
		}

		if (s_bCheckInitSuccessFlag)
		{
			if (MAYEX_SHM_INIT_SUCCESS_MAGIC != m_iInitSuccessFlag)
			{
				enInitFlag = EN_OBJ_MODE_INIT;
				NFLogError(NF_LOG_SYSTEMLOG, 0, "shm change to mode INIT from RECOVER because no MAYEX_SHM_INIT_SUCCESS_MAGIC");
			}
		}
	}

	if (EN_OBJ_MODE_INIT == enInitFlag)
	{
		m_siAddrOffset = 0;
		m_pShmAddr = pbCurrentShm;
		m_iObjSeqNum = 0;
		m_iCanBeDestroySafe = 0;
		m_iInitSuccessFlag = 0;
		m_iServerCheckVersion = MAGIC_SERVER_VER;
	}
	else
	{
		m_siAddrOffset = (size_t)(pbCurrentShm - m_pShmAddr);
		NFLogInfo(NF_LOG_SYSTEMLOG, 0, "recover mode,shm address change from {} to {}, addroffset {}", (void*)m_pShmAddr, (void*)pbCurrentShm, m_siAddrOffset);
		m_pShmAddr = pbCurrentShm;
		m_iCanBeDestroySafe = 0;
	}

	Initialize(nKey, siSize);
	m_enRunMode = enInitFlag;
}

NFCSharedMem::~NFCSharedMem()
{

}

int NFCSharedMem::Initialize(key_t nKey, size_t siSize)
{
	m_iCreateTime = NFTime::Now().UnixSec();
	m_iLastStamp = m_iCreateTime;

	m_nShmKey = nKey;
	m_siShmSize = siSize;
	m_siCRC = (unsigned int)m_nShmKey ^ m_siShmSize ^ (unsigned int)m_iCreateTime ^ (unsigned int)m_iLastStamp;
	return 0;
}

void *NFCSharedMem::CreateSegment(size_t siSize)
{
	size_t siTempUsedLength = 0;
	char* pTemp;

	if (siSize == 0)
	{
		return NULL;
	}

	siTempUsedLength = (size_t)(m_pbCurrentSegMent - (char*)this);

	if (m_siShmSize - siTempUsedLength < siSize)
	{
		return NULL;
	}

	pTemp = m_pbCurrentSegMent;
	m_pbCurrentSegMent += siSize;
	return (void *)pTemp;
}

void NFCSharedMem::SetStamp()
{
	m_iLastStamp = NFTime::Now().UnixSec();
	m_siCRC = (unsigned int)m_nShmKey ^ m_siShmSize ^ (unsigned int)m_iCreateTime ^ (unsigned int)m_iLastStamp;
}

void NFCSharedMem::SetShmCanbeDestroySafe()
{
	m_iCanBeDestroySafe = MAYEX_SHM_CAN_BE_DESTROY_SAFE_MAGIC;
}

void NFCSharedMem::SetShmInitSuccessFlag()
{
	m_iInitSuccessFlag = MAYEX_SHM_INIT_SUCCESS_MAGIC;
}

void NFCSharedMem::ClearShmInitSuccessFlag()
{
	m_iInitSuccessFlag = 0;
}

