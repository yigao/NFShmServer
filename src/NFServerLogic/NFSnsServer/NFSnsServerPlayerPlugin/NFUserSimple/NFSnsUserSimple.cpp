// -------------------------------------------------------------------------
//    @FileName         :    NFSnsUserSimple.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSnsUserSimple.cpp
//
// -------------------------------------------------------------------------

#include "NFSnsUserSimple.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFTransSaveSimpleDB.h"
#include "NFSnsUserSimpleMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSnsUserSimple, EOT_SNS_USER_SIMPLE_ID, NFShmObj)

NFSnsUserSimple::NFSnsUserSimple()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFSnsUserSimple::~NFSnsUserSimple()
{

}

int NFSnsUserSimple::CreateInit()
{
    m_bSimpleInited = false;
	m_iSaveTransID = 0;
	m_dwRoleSimpleInfoSavingDBTime = 0;
    memset(&m_userData, 0, sizeof(m_userData));
	ResetCurSeq();
    return 0;
}

int NFSnsUserSimple::ResumeInit()
{
    return 0;
}

int NFSnsUserSimple::InitWithSnsRoleSimpleInfo(const proto_ff::tbUserSimpleData *pSimpleData) {
    CHECK_NULL(pSimpleData);
    CHECK_EXPR(m_bSimpleInited == false, -1, "Simple Aleady Init:{}", m_userData.userid);

    proto_ff_s::tbUserSimpleData_s::read_from_pbmsg(*pSimpleData, m_userData);

    m_bSimpleInited = true;
	m_dwRoleSimpleInfoSavingDBTime = NFTime::Now().UnixSec();
    return 0;
}

int NFSnsUserSimple::MakeUserDataCS(proto_ff::tbUserSimpleData& data)
{
	proto_ff_s::tbUserSimpleData_s::write_to_pbmsg(m_userData, data);
	return 0;
}

int NFSnsUserSimple::SetLogicRoleSimpleInfo(const proto_ff_s::UserSimpleData_s& rolesimple)
{
    CHECK_EXPR(m_userData.userid == rolesimple.userid, -1, "");
    if (m_userData.nickname.GetString() != rolesimple.nickname.GetString())
    {
        m_userData.nickname = rolesimple.nickname;
        MarkDirty();
    }

    if (m_userData.face != rolesimple.face)
    {
        m_userData.face = rolesimple.face;
        MarkDirty();
    }

    if (m_userData.gender != rolesimple.gender)
    {
        m_userData.gender = rolesimple.gender;
        MarkDirty();
    }

    if (m_userData.age != rolesimple.age)
    {
        m_userData.age = rolesimple.age;
        MarkDirty();
    }

    if (m_userData.show_userid != rolesimple.show_userid)
    {
        m_userData.show_userid = rolesimple.show_userid;
        MarkDirty();
    }

    if (m_userData.vip_level != rolesimple.vip_level)
    {
        m_userData.vip_level = rolesimple.vip_level;
        MarkDirty();
    }

	return 0;
}

int NFSnsUserSimple::GetLogicRoleSimpleInfo(proto_ff_s::UserSimpleData_s& rolesimple)
{
    rolesimple.userid = m_userData.userid;
    rolesimple.nickname = m_userData.nickname;
    rolesimple.face = m_userData.face;
    rolesimple.gender = m_userData.gender;
    rolesimple.show_userid = m_userData.show_userid;
    rolesimple.vip_level = m_userData.vip_level;
    return 0;
}

int NFSnsUserSimple::GetLogicRoleSimpleInfo(proto_ff::UserSimpleData& rolesimple)
{
    rolesimple.set_userid(m_userData.userid);
    rolesimple.set_nickname(m_userData.nickname.GetString());
    rolesimple.set_face(m_userData.face);
    rolesimple.set_gender(m_userData.gender);
    rolesimple.set_show_userid(m_userData.show_userid);
    rolesimple.set_vip_level(m_userData.vip_level);
    return 0;
}

int NFSnsUserSimple::SaveToDB(bool bForce)
{
	if (m_bSimpleInited && m_iSaveTransID == 0 && IsUrgentNeedSave())
	{
		if (bForce || NFTime::Now().UnixSec() - m_dwRoleSimpleInfoSavingDBTime >= 60)
		{
			return SaveUserSimpleToDB();
		}
	}
	return 0;
}

int NFSnsUserSimple::SaveUserSimpleToDB()
{
	NFTransSaveSimpleDB* pSave = (NFTransSaveSimpleDB*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SAVE_USER_SIMPLEL);
	CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveMoney Failed! ");

	pSave->Init(this);
	int iRet = pSave->ProHandleSaveDB();
	if (iRet != 0)
	{
		pSave->SetFinished(-1);
	}
	else
	{
		m_iSaveTransID = pSave->GetGlobalID();
	}
	return iRet;
}

int NFSnsUserSimple::OnUserSimpleSaved(bool success, uint32_t seq)
{
	m_iSaveTransID = 0;
	if (success && seq == GetCurSeq())
	{
		ClearUrgent();
	}
	return 0;
}

int NFSnsUserSimple::UserLogout()
{
	return 0;
}

bool NFSnsUserSimple::CanDelete()
{
	if (m_bSimpleInited && IsUrgentNeedSave())
		return false;

	return true;
}

