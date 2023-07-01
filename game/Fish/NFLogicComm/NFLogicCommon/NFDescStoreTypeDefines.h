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

    ///////////////////////////////////DescStoreEX///////////////////////////////////////////
    EOT_CONST_MAP_CONFIG_DESCEX_ID,
    EOT_ROLE_CONFIG_DESCEX_ID,
    EOT_FUNC_UNLOCK_DESCEX_ID,
    EOT_ITEM_CONFIG_DESCEX_ID,
    EOT_MISSION_CONFIG_DESCEX_ID,
    EOT_NFGrowDescStoreEx_ID,
    EOT_DS_END_ID = EOT_DESC_STORE_END_ID,
} EN_DESC_STORE_SHMOBJ_TYPE;