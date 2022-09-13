// -------------------------------------------------------------------------
//    @FileName         :    NFServerIDUtil.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerIDUtil
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

#define WORLD_ID_POS 0
#define ZONE_ID_POS_PREFIX 0
#define ZONE_ID_POS 1
#define SERVER_TYPE_POS 2
#define INST_ID_POS 3

struct NFChannelAddress
{
    NFChannelAddress()
    {
        mPort = 0;
    }
    std::string mAddress; // 主机完整地址，比如：tcp://127.0.0.1:8123 udp://127.0.0.1:1000 或 bus://127.0.0.1
    std::string mScheme;  // 协议名称，比如：tcp 或 bus
    std::string mHost;    // 主机地址，比如：127.0.0.1
    int mPort;            // 端口。（仅网络连接有效）
};

/*
* @brief    BUS通信地址模板分析的相关接口
* Bus系统进程通信地址有两种表示方法：
*	1.内部表示：32位无符号整数
*	2.外部显示或配置表示：十进制点分表示的字符串 xx.xx.xx.xxx
*/

class NFServerIDUtil
{
public:
	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	*
	* @param busId
	* @return uint32_t 服务器类型（
	*/
	static uint32_t GetWorldID(uint32_t busId);

	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	*
	* @param busId
	* @return uint32_t 分区ID
	*/
	static uint32_t GetZoneID(uint32_t busId);

	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	*
	* @param busId
	* @return uint32_t 服务器类型
	*/
	static uint32_t GetServerType(uint32_t busId);

	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	*
	* @param busId
	* @return uint32_t 索引
	*/
	static uint32_t GetInstID(uint32_t busId);

	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	* 区域服务器ID = 世界服ID * 10000 + 分区ID
	* @param busId
	* @return uint32_t 区域服务器ID
	*/
	static uint32_t GetZoneAreaID(uint32_t busId);

	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	*
	* @param world				世界服ID
	* @param zone				分区ID
	* @param servertype		服务器类型
	* @param inst				索引
	* @return uint32_t 区域服务器ID
	*/
	static uint32_t MakeProcID(uint8_t world, uint16_t zone, uint8_t servertype, uint8_t inst);

	/**
	* @brief 通过busid(15.50.5.1)获得世界服ID, 15是世界服ID， 50是分区ID， 5是服务器类型, 1是索引
	*
	* @param busname	字符串 xx.xx.xx.xxx 表示的busid
	* @return uint32_t 32位数字表示的busid
	*/
	static uint32_t GetBusID(const std::string& busname);

    /**
    * @param busname	字符串 xx.xx.xx.xxx 表示的busid
    * @return uint32_t 32位数字表示的shmobjid
    */
    static uint32_t GetShmObjKey(const std::string& busname);

	static std::string GetBusNameFromBusID(uint32_t busId);
    static std::string GetBusNameFromBusID(const std::string& busId);

    static bool MakeAddress(const std::string& addrStr, NFChannelAddress &addr);

    static void MakeAddress(const std::string& scheme, const std::string& host, int port, NFChannelAddress &addr);
};


