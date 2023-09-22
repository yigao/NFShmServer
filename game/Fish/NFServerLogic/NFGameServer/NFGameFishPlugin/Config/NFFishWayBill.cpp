// -------------------------------------------------------------------------
//    @FileName         :    NFFishWayBill.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishWayBill.cpp
//
// -------------------------------------------------------------------------

#include "NFFishWayBill.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFFishWayBillConfig.h"

CFishWayBillData::CFishWayBillData()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

CFishWayBillData::~CFishWayBillData()
{

}

int CFishWayBillData::CreateInit()
{
    Clear();
    return 0;
}

void CFishWayBillData::Clear()
{
    m_strFileName.CreateInit();
    m_usInterval = 0;
    m_usDefaultGroupDelay = 0;
    m_ItemList.CreateInit();
    m_szMD5.CreateInit();
}

int CFishWayBillData::ResumeInit()
{
    return 0;
}

int CFishWayBillData::Init(const std::string &strWayBillFile)
{
    std::string fileName = NFFileUtility::GetFileName(strWayBillFile);
    m_strFileName = fileName;

    int iRet = 0;
    FILE *fp = NULL;
    do {
        fp = fopen(strWayBillFile.c_str(), "r");

        if (NULL == fp) {
            iRet = -1;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishWayBill::Init() open file: {} error, errno = {}: {}", strWayBillFile.c_str(), errno, strerror(errno));
            break;
        }

        FishWayBillHead head;
        size_t bytes = fread(&head, 1, sizeof(head), fp);
        if (bytes != sizeof(head)) {
            iRet = -1;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishWayBill::Init() read head error, bytes = {}", bytes);
            break;
        }

        //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CFishWayBill::Init() read head, ItemCount = {} Interval = {}", head.usCount, head.usInterval);

        m_usInterval = head.usInterval;
        m_usDefaultGroupDelay = head.usDefaultGroupDelay;
        while (!feof(fp)) {
            FishWayBillItem item;

            bytes = fread(&item, 1, sizeof(item), fp);
            if (bytes != sizeof(item)) {
                if (feof(fp)) {
                    break;
                }
                iRet = -1;

                NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishWayBill::Init() read item error, bytes = %u, already read count = %u", bytes, m_ItemList.size())
                break;
            }

            //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "read type = {} value = {}", item.usType, item.usValue);
            if (m_ItemList.full())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_ItemList full");
                NFSLEEP(1000);
                exit(0);
            }

            m_ItemList.push_back(item);
        }

        if (0 != iRet) {
            break;
        }

        if (m_ItemList.size() != head.usCount) {
            iRet = -1;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CFishWayBill::Init() read item count = {} != head item count = {}", m_ItemList.size(), head.usCount);
            break;
        }

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "CFishWayBill::Init() read OK, item count = {}", m_ItemList.size());

    } while (0);

    if (NULL != fp) {
        fclose(fp);
        fp = NULL;
    }

    return iRet;
}

std::string CFishWayBillData::GetFileName()
{
    return m_strFileName.GetString();
}

std::string CFishWayBillData::GetMD5()
{
    return m_szMD5.GetString();
}

void CFishWayBillData::SetFileName(const std::string& name)
{
    m_strFileName = name;
}

void CFishWayBillData::SetMD5(const std::string& md5)
{
    m_szMD5 = md5;
}

int CFishWayBillData::GetItemCount() const {
    return m_ItemList.size();
}

int CFishWayBillData::GetInterval() const {
    return 100;
    //return m_usInterval;
}

int CFishWayBillData::GetDefaultGroupDelay() const
{
    return m_usDefaultGroupDelay;
}

CFishWayBill::CFishWayBill()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

CFishWayBill::~CFishWayBill() {

}

int CFishWayBill::CreateInit()
{
    Clear();
    return 0;
}

int CFishWayBill::ResumeInit()
{
    return 0;
}

void CFishWayBill::Clear()
{
    m_usInterval = 0;
    m_usDefaultGroupDelay = 0;
    m_ItemList4Use.CreateInit();
    m_strFileName.CreateInit();
}

int CFishWayBill::GetOneItem(FishWayBillItem & Item)
{
	if (m_ItemList4Use.size() == 0)
	{
		return -1;
	}

	FishWayBillItem &RefItem = m_ItemList4Use.front();
	Item.usType = RefItem.usType;
	Item.usValue = RefItem.usValue;
	m_ItemList4Use.pop_front();

	return m_ItemList4Use.size();
}

bool CFishWayBill::ForcastOneItem(FishWayBillItem &Item) {
    if (m_ItemList4Use.size() == 0) {
        return false;
    }

    FishWayBillItem &RefItem = m_ItemList4Use.front();
    Item.usType = RefItem.usType;
    Item.usValue = RefItem.usValue;

    return true;
}

int  CFishWayBill::Reset(NFFishWayBillConfig *pConfig)
{
    CHECK_NULL(pConfig);
    CFishWayBillData* pData = pConfig->GetFishWayBillByFileName(GetFileName());
    if (pData)
    {
        CopyFrom(*pData);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find way data:{}", GetFileName());
    }

	return m_ItemList4Use.size();
}

int CFishWayBill::GetInterval() const {
    return 100;
    //return m_usInterval;
}

int CFishWayBill::GetDefaultGroupDelay() const
{
    return m_usDefaultGroupDelay;
}

std::string CFishWayBill::GetFileName()
{
    return m_strFileName.GetString();
}




