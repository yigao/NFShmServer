// -------------------------------------------------------------------------
//    @FileName         :    NFUserMailDefine.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFUserMailDefine.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFShmCore/NFShmObj.h"

#define ROLE_MAIL_CACHE_SIZE 500
#define ROLE_MAIL_GET_MAIL_MAX 50

enum enTransMailHandleType
{
    EN_TRANS_MAIL_TYPE_NULL	= 0,
    EN_TRANS_MAIL_TYPE_SAVE	= 1,
    EN_TRANS_MAIL_TYPE_DEL	= 2,
};
