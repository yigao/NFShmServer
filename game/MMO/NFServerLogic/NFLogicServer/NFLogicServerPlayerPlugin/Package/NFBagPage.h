// -------------------------------------------------------------------------
//    @FileName         :    NFBagPage.h
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBagPage
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "NFLogicCommon/NFPackageDefine.h"

class NFBagPage : public NFRawShmObj, public NFSeqOP
{
    typedef std::list<SItem> LIST_ITEM_EX;
    // label - LIST_ITEM_EX(标签-物品列表)
    typedef std::unordered_map<uint8_t, LIST_ITEM_EX> MAP_LABEL_LIST_ITEM_EX;
    // index - SItemEx
    typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM_EX;
    // label - MAP_INDEX_ITEM_EX
    typedef std::map<uint8_t, MAP_INDEX_ITEM_EX > MAP_LABEL_MAP_INDEX_ITEM_EX;
    
    // index - SItem
    typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM;
    
    //label - VEC_ITEM_PROTO_EX
    typedef std::unordered_map<uint8_t, VEC_ITEM_PROTO_EX> MAP_LABEL_VEC_ITEM_PROTO_EX;
    //index - ItemProtoInfo
    typedef std::map<uint16_t, proto_ff::ItemProtoInfo> MAP_INDEX_ITEM_PROTO_EX;
public:
    NFBagPage();
    
    virtual ~NFBagPage();
    
    int CreateInit();
    int ResumeInit();
};