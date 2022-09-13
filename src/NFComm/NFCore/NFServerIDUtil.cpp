// -------------------------------------------------------------------------
//    @FileName         :    NFServerIDUtil.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerIDUtil
//
// -------------------------------------------------------------------------

#include "NFServerIDUtil.h"
#include "NFStringUtility.h"
#include "NFCommon.h"

uint32_t NFServerIDUtil::GetWorldID(uint32_t busId)
{
    unsigned char *pszSvrID = ( unsigned char * )&busId;
    return ((uint32_t)(pszSvrID[WORLD_ID_POS] & 0xF0)) >> 4;
}


uint32_t NFServerIDUtil::GetZoneID(uint32_t busId)
{
    unsigned char *pszSvrID = ( unsigned char * )&busId;
    return (((uint32_t)(pszSvrID[ZONE_ID_POS_PREFIX] & 0x0F)) << 8) + pszSvrID[ZONE_ID_POS];
}


uint32_t NFServerIDUtil::GetServerType(uint32_t busId)
{
    unsigned char *pszSvrID = ( unsigned char * )&busId;
    return pszSvrID[SERVER_TYPE_POS];
}


uint32_t NFServerIDUtil::GetInstID(uint32_t busId)
{
    unsigned char *pszSvrID = ( unsigned char * )&busId;
    return pszSvrID[INST_ID_POS];
}

uint32_t NFServerIDUtil::GetZoneAreaID(uint32_t busId)
{
    return GetWorldID(busId) * 10000 + GetZoneID(busId);
}

uint32_t NFServerIDUtil::MakeProcID(uint8_t world, uint16_t zone, uint8_t servertype, uint8_t inst)
{
    int iTmpID = 0;
    unsigned char* pszSvrID = ( unsigned char * )&iTmpID;
    pszSvrID[SERVER_TYPE_POS] = servertype;
    pszSvrID[INST_ID_POS] = inst;
    pszSvrID[WORLD_ID_POS] = (world & 0x0F) << 4;
    pszSvrID[ZONE_ID_POS_PREFIX] = pszSvrID[ZONE_ID_POS_PREFIX] | ((zone & 0x0F00) >> 8);
    pszSvrID[ZONE_ID_POS] = (uint8_t)zone;

    return iTmpID;
}

uint32_t NFServerIDUtil::GetBusID(const std::string& busname)
{
	std::vector<uint32_t> vec;
	NFStringUtility::SplitStringToUint32(busname, ".", vec);
	uint8_t world = 0;
	uint16_t zone = 0;
	uint8_t servertype= 0;
	uint8_t inst = 0;
	if (vec.size() >= 1)
	{
		world = vec[0];
	}

	if (vec.size() >= 2)
	{
		zone = vec[1];
	}

	if (vec.size() >= 3)
	{
		servertype = vec[2];
	}

	if (vec.size() >= 4)
	{
		inst = vec[3];
	}

	return MakeProcID(world, zone, servertype, inst);
}

uint32_t NFServerIDUtil::GetShmObjKey(const std::string& busname)
{
    std::vector<uint32_t> vec;
    NFStringUtility::SplitStringToUint32(busname, ".", vec);
    uint8_t world = 0;
    uint16_t zone = 0;
    uint8_t servertype= 0;
    uint8_t inst = 0;
    if (vec.size() >= 1)
    {
        world = vec[0];
    }

    if (vec.size() >= 2)
    {
        zone = vec[1];
    }

    if (vec.size() >= 3)
    {
        servertype = vec[2];
    }

    if (vec.size() >= 4)
    {
        inst = vec[3];
    }

    return zone*100000+servertype*1000+inst;
}

std::string NFServerIDUtil::GetBusNameFromBusID(uint32_t busId)
{
    uint32_t worldId = GetWorldID(busId);
    uint32_t zoneId = GetZoneID(busId);
    uint32_t serverId = GetServerType(busId);
    uint32_t instId = GetInstID(busId);
    std::string str = NF_FORMAT("{}.{}.{}.{}", worldId, zoneId, serverId, instId);
    return str;
}

std::string NFServerIDUtil::GetBusNameFromBusID(const std::string& busId)
{
    return GetBusNameFromBusID(NFCommon::strto<uint32_t>(busId));
}

bool NFServerIDUtil::MakeAddress(const std::string& addrStr, NFChannelAddress &addr)
{
    addr.mAddress = addrStr;

    // 获取协议
    size_t scheme_end = addr.mAddress.find_first_of("://");
    if (addr.mAddress.npos == scheme_end) {
        return false;
    }

    addr.mScheme = addr.mAddress.substr(0, scheme_end);
    NFStringUtility::ToLower(addr.mScheme);

    size_t port_end = addr.mAddress.find_last_of(":");
    addr.mPort = 0;
    if (addr.mAddress.npos != port_end && port_end >= scheme_end + 3) {
        addr.mPort = NFCommon::strto<int>(addr.mAddress.c_str() + port_end + 1);
    }

    // 截取域名
    addr.mHost = addr.mAddress.substr(scheme_end + 3, (port_end == addr.mAddress.npos) ? port_end : port_end - scheme_end - 3);

    return true;
}

void NFServerIDUtil::MakeAddress(const std::string& scheme, const std::string& host, int port, NFChannelAddress &addr)
{
    addr.mScheme = scheme;
    addr.mHost = host;
    addr.mPort = port;
    addr.mAddress.reserve(addr.mScheme.size() + addr.mHost.size() + 4 + 8);
    addr.mAddress = addr.mScheme + "://" + addr.mHost;

    if (port > 0) {
        std::string portStr = NFCommon::tostr(port);
        addr.mAddress += ":";
        addr.mAddress += portStr;
    }
}
