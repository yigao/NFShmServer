// -------------------------------------------------------------------------
//    @FileName         :    NFDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <functional>
#include <stdint.h>
#include <string.h>

enum NF_OBJECT_EVENT
{
	OBJECT_EVT_NONE = 0,
	OBJECT_EVT_DESTROY,
	OBJECT_EVT_PRE_DESTROY,
	OBJECT_EVT_PRE_LOAD_DATA,
	OBJECT_EVT_LOAD_DATA,
	OBJECT_EVT_PRE_EFFECT_DATA,
	OBJECT_EVT_EFFECT_DATA,
	OBJECT_EVT_POST_EFFECT_DATA,
	OBJECT_EVT_DATA_FINISHED,
	OBJECT_EVT_ALL_FINISHED, //Call it by yourself when create entity finished
};

class NFCData;

class DATA_TABLE_EVENT_DATA
{
public:
	DATA_TABLE_EVENT_DATA()
		: nOpType(0), nRow(-1), nCol(-1)
	{
	}

	uint8_t nOpType;
	int16_t nRow;
	int16_t nCol;
	std::string strName;
};

using DATA_NODE_EVENT_FUNCTOR = std::function<int(const uint64_t, const std::string&, const NFCData&, const NFCData&)>;
using DATA_NODE_EVENT_FUNCTOR_PTR = NF_SHARE_PTR<DATA_NODE_EVENT_FUNCTOR>;

using DATA_TABLE_EVENT_FUNCTOR = std::function<int(const uint64_t, const DATA_TABLE_EVENT_DATA&, const NFCData&, const NFCData&)>;
using DATA_TABLE_EVENT_FUNCTOR_PTR = NF_SHARE_PTR<DATA_TABLE_EVENT_FUNCTOR>;

using CLASS_EVENT_FUNCTOR = std::function<bool(const uint64_t&, const std::string&, const NF_OBJECT_EVENT, const NFCData&)>;
using CLASS_EVENT_FUNCTOR_PTR = NF_SHARE_PTR<CLASS_EVENT_FUNCTOR>;

