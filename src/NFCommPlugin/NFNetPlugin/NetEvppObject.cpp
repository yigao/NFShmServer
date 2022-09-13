// -------------------------------------------------------------------------
//    @FileName         :    NetEvppObject.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
// -------------------------------------------------------------------------

#include "NetEvppObject.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFIPacketParse.h"
#include "NFComm/NFCore/NFSHA2.h"
#include "NFComm/NFCore/NFBase64.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFStringUtility.h"

#define MAGIC_KEY "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"

NetEvppObject::NetEvppObject(const evpp::TCPConnPtr& conn) : m_usLinkId(0), mNeedRemove(false), mConnPtr(conn)
{
	mIsServer = true;
	mPacketParseType = 0;
	mLastHeartBeatTime = NFGetTime();
}

NetEvppObject::~NetEvppObject()
{
}

std::string NetEvppObject::GetStrIp() const
{
	return m_strIp;
}

void NetEvppObject::SetStrIp(std::string val)
{
	m_strIp = val;
}

void NetEvppObject::SetIsServer(bool b)
{
	mIsServer = b;
}

uint64_t NetEvppObject::GetLinkId() const
{
	return m_usLinkId;
}

void NetEvppObject::SetLinkId(uint64_t linkId)
{
	m_usLinkId = linkId;
}

bool NetEvppObject::GetNeedRemove() const
{
	return mNeedRemove;
}

void NetEvppObject::SetNeedRemove(bool val)
{
	mNeedRemove = val;
}

void NetEvppObject::CloseObject()
{
	if (mConnPtr)
	{
		if (mConnPtr->IsConnected() || mConnPtr->IsConnecting())
		{
			mConnPtr->Close();
		}
	}
}
