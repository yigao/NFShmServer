// -------------------------------------------------------------------------
//    @FileName         :    NFFishGroup.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishGroup.cpp
//
// -------------------------------------------------------------------------

#include "NFFishGroup.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFFishCtrlCfgDef.h"
#include "NFFishTraceMgr.h"

CFishGroup::CFishGroup()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

int CFishGroup::CreateInit()
{
    m_roomId = 0;
    m_unId = 0;
	m_FishList.clear();
    m_usFishCount = 0;
    m_bValid = false;
    m_usGroupType = E_FISH_GROUP_TYPE_YU_QUN;
    m_usPrepareTime = 1000;
	m_byHideWave = 0;
	m_usCenterX = 0;
	m_usCenterY = 0;
	m_byVersion = 0;
	m_bySceneType = 0;
	m_szMD5.clear();
    m_bySceneIndex = 0;

    return 0;
}

int CFishGroup::ResumeInit()
{
    return 0;
}


CFishGroup::~CFishGroup() {
}

const NFShmVector<CFish, MAX_FISH_NUM> &CFishGroup::GetFishList() {
    return m_FishList;
}

std::string CFishGroup::ToHEX(char *buf, int len) {
    std::string str = "";

    for (int i = 0; i < len; i++) {
        char szFile[16] = {0};
        snprintf(szFile, sizeof(szFile), "%02X", (unsigned char) buf[i]);

        str += szFile;
        str += " ";
    }

    return str;
}

void CFishGroup::Clear()
{
    CreateInit();
}


int CFishGroup::Load(const std::string &strFile, uint32_t roomId, NFIPluginManager* pPluginManager)
{
    m_roomId = roomId;
    FILE *fpGroup = NULL;
    int iRet = 0;

    do 
	{
        fpGroup = fopen(strFile.c_str(), "rb");

        if (NULL == fpGroup) 
		{
            iRet = -1;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() open file: %s error, errno = {}: {}", strFile, errno, strerror(errno));

            break;
        }

        FishGroupHead head;
        size_t bytes = fread(&head, 1, sizeof(head), fpGroup);

        if (sizeof(head) != bytes) 
		{
            iRet = -1;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() read head failed, bytes = {}", bytes);
            break;
        }

        m_usGroupType = head.usGroupType;
        m_usPrepareTime = head.usPrepareTime;
        m_byHideWave = head.byHideWave;
		m_usCenterX  = head.usCenterX;
		m_usCenterY  = head.usCenterY;
		m_byVersion  = head.byVersion;
		m_bySceneType= head.bySceneType;
		m_bySceneIndex = head.bySceneIndex;

        //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() group id = {} m_byVersion = {}", m_unId, m_byVersion);

		if (m_byVersion == 0)
		{
			iRet = ReadGroupFileVer0(fpGroup, pPluginManager);

		}
		else if (m_byVersion == 1)
		{
			iRet = ReadGroupFileVer1(fpGroup, pPluginManager);
		}
		else
		{
			iRet = -1;
		}

        if (0 != iRet) 
		{
            break;
        }

        if (head.usFishCount != m_usFishCount) 
		{
            iRet = -1;

            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() read fish count = {} != head count = {}", m_usFishCount, head.usFishCount);
            break;
        }

        m_bValid = true;

        //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() read OK, fish count = {}", m_usFishCount);

    } while (0);


    if (NULL != fpGroup) 
	{
        fclose(fpGroup);

        fpGroup = NULL;
    }

    return iRet;
}

int CFishGroup::ReadGroupFileVer0(FILE* fpGroup, NFIPluginManager* pPluginManager)
{
	int iRet = 0;
	size_t bytes = 0;

	uint32_t unIndex = 1;
	while (!feof(fpGroup))
	{
		FishItem item;
		bytes = fread(&item, 1, sizeof(item), fpGroup);

		if (bytes != sizeof(item))
		{
			if (feof(fpGroup))
			{
				break;
			}
			iRet = -1;

			NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() read fish fixed error, bytes = {}", bytes);
			break;
		}

		uint32_t unFishId = m_unId * 1000 + unIndex;
        CHECK_EXPR(!m_FishList.full(), -1, "Fish List Add Failed! list full");
        m_FishList.push_back();
		CFish *fish = &m_FishList.back();
		CHECK_EXPR(fish, -1, "Fish List Add Failed! list full");

		fish->Init(unFishId, item.usFishKind, item.usTraceId, item.usStartPointIndex, item.usAliveTime);
		fish->m_BirthDelay = 0;
		fish->m_uReserved = 0;

		++m_usFishCount;
		++unIndex;

		//std::string strData = ToHEX((char*)&item, sizeof(item));
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() ver=0 usFishKind = {} , usTraceId = {} , usStartPointIndex = {} , item.usAliveTime = {}", item.usFishKind, item.usTraceId, item.usStartPointIndex, item.usAliveTime);
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() fish->m_BirthDelay = {}", fish->m_BirthDelay);
	}

	return iRet;
}

int CFishGroup::ReadGroupFileVer1(FILE* fpGroup, NFIPluginManager* pPluginManager)
{
	int iRet = 0;
	size_t bytes = 0;

    NFFishTraceMgr* pTrace = NFFishTraceMgr::GetObjByHashKey(pPluginManager, m_roomId);

	uint32_t unIndex = 1;
	while (!feof(fpGroup))
	{
		FishItem1 item;
		bytes = fread(&item, 1, sizeof(item), fpGroup);

		if (bytes != sizeof(item))
		{
			if (feof(fpGroup))
			{
				break;
			}
			iRet = -1;

			NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() read fish fixed error, bytes = {}", bytes);
			break;
		}


		//////////////////////////////////////////////////////////////////////////
		//要在这里结合轨迹计算存活时间，不使用Group里保存的存活时间了，那个有时不准；
		int iTracePointCount = pTrace->GetTracePointCount(item.usTraceId);
		if (iTracePointCount <= item.usStartPointIndex)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "Read fish error, GroupId = {}, usTraceId = {} , iTracePointCount = {} , usStartPointIndex = {}", m_unId, item.usTraceId, iTracePointCount, item.usStartPointIndex);
			continue;
		}
		
		//NFLogError(NF_LOG_SYSTEMLOG, 0, "Read fish OK, GroupId = {}, usTraceId = {} , iTracePointCount = {} , usStartPointIndex = {}", m_unId, item.usTraceId, iTracePointCount, item.usStartPointIndex);
		
		uint32_t uAliveTime = (iTracePointCount - item.usStartPointIndex) * 100;
		item.usAliveTime = (item.usAliveTime & 0xFF000000) | (uAliveTime & 0x00FFFFFF);

		//////////////////////////////////////////////////////////////////////////

		uint32_t unFishId = m_unId * 1000 + unIndex;
        CHECK_EXPR(!m_FishList.full(), -1, "Fish List Add Failed! list full");
        m_FishList.push_back();
		CFish *fish = &m_FishList.back();
		CHECK_EXPR(fish, -1, "Fish List Add Failed! list full");


		fish->Init(unFishId, item.usFishKind, item.usTraceId, item.usStartPointIndex, item.usAliveTime);
		fish->m_BirthDelay = item.sBirthDelay;
		fish->m_uReserved  = item.uReserved;
		++m_usFishCount;
		++unIndex;

		//std::string strData = ToHEX((char*)&item, sizeof(item));
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() ver=1 file = {} , usFishKind = {} , usTraceId = {} , usStartPointIndex = {} , item.usAliveTime = {}", strFile.c_str(),item.usFishKind, item.usTraceId, item.usStartPointIndex, item.usAliveTime);
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() fish->m_BirthDelay = {}", fish->m_BirthDelay);
		
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishGroup::InnerReadFile() usAliveTime={}  m_unId = {} , fish->m_byDefaultSubFish = {}", item.usAliveTime, m_unId, fish->m_byDefaultSubFish);
	}

	return iRet;
}







