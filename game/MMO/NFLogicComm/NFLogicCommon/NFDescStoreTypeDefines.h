// -------------------------------------------------------------------------
//    @FileName         :    NFTypeDefines.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "DescStore/NFDescStoreDefine.h"

typedef enum
{
    EOT_DS_BEGIN_ID = EOT_DESC_STORE_BEGIN_ID,
    EOT_DESC_STORE_ALL_ID_DEFINE
    EOT_CONST_GROW_DESC_EX_ID,
    ///////////////////////////////////DescStoreEX///////////////////////////////////////////
    EOT_DS_END_ID = EOT_DESC_STORE_END_ID,
} EN_DESC_STORE_SHMOBJ_TYPE;