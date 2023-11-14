// -------------------------------------------------------------------------
//    @FileName         :    NFRunePart.h
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFRunePart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "Part/NFPart.h"

/**
 * @brief ·ûÎÄ
 */
class NFRunePart : public NFShmObjTemplate<NFRunePart, EOT_LOGIC_PART_ID + PART_RUNE, NFPart>
{
public:
    NFRunePart();
    
    virtual ~NFRunePart();
    
    int CreateInit();
    int ResumeInit();
};