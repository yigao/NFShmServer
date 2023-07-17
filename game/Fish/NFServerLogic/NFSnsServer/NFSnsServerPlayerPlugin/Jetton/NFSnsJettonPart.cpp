// -------------------------------------------------------------------------
//    @FileName         :    NFSnsJettonPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsJettonPart
//
// -------------------------------------------------------------------------

#include "NFSnsJettonPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSnsJettonPart, EOT_NFSnsJettonPart_ID, NFSnsPart)

NFSnsJettonPart::NFSnsJettonPart()
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

NFSnsJettonPart::~NFSnsJettonPart()
{
}

int NFSnsJettonPart::CreateInit()
{
    return 0;
}

int NFSnsJettonPart::ResumeInit()
{
    return 0;
}
