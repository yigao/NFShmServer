#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTP_NUM 32

#define MAX_COM_INDEX_XINGCHEN_XCTP_POSITIONID_NUM 4

#define UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCTP_POSITIONID_NUM 16

#define MAX_COM_INDEX_XINGCHEN_XCTP_XCQUALITY_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCTP_XCQUALITY_NUM 4

struct XingchenXctpPositionidXcquality
{
	XingchenXctpPositionidXcquality()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}
	int CreateInit()
	{
		m_PositionID=0;
		m_XcQuality=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_PositionID;
	int64_t m_XcQuality;
	bool operator==(const XingchenXctpPositionidXcquality& data) const
	{
		 return m_PositionID==data.m_PositionID && m_XcQuality==data.m_XcQuality;
	}
};

namespace std
{
	template<>
	struct hash<XingchenXctpPositionidXcquality>
	{
		size_t operator()(const XingchenXctpPositionidXcquality& data) const
		{
			return NFHash::hash_combine(data.m_PositionID,data.m_XcQuality);
		}
	};
}


class XingchenXctpDesc : public NFIDescStore
{
public:
	XingchenXctpDesc();
	virtual ~XingchenXctpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXctp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXctp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXctp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXctp_s* GetDescByIndex(int index);
public:
	const proto_ff_s::E_XingchenXctp_s* GetDescByPositionidXcquality(int64_t Positionid, int64_t Xcquality);
private:
	NFShmHashMap<XingchenXctpPositionidXcquality ,uint32_t, UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCTP_POSITIONID_NUM*UNIQUE_KEY_MAX_COM_INDEX_XINGCHEN_XCTP_XCQUALITY_NUM> m_PositionidXcqualityComIndexMap;
IMPL_RES_HASH_DESC(XingchenXctpDesc, proto_ff_s::E_XingchenXctp_s, E_XingchenXctp, MAX_XINGCHEN_XCTP_NUM);
DECLARE_IDCREATE(XingchenXctpDesc);
};
