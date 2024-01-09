// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-07-08
//    @Module           :    NFCLuaScriptModule
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFILuaScriptModule.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include "NFComm/NFPluginModule/NFILuaLoader.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFCommon.h"

#include "NFComm/NFCore/NFCommMapEx.hpp"
#include "NFCommPlugin/NFKernelPlugin/NFServerLinkData.h"
#include "NFComm/NFPluginModule/NFObjectPool.hpp"
#include "NFComm/NFPluginModule/NFEventObj.h"

#include <unordered_set>

enum EnumLuaModule
{
	EnumLuaModule_NULL  = 0,
	EnumLuaModule_INIT  = 1,
	EnumLuaModule_SEC   = 6,
	EnumLuaModule_MIN   = 7,
	EnumLuaModule_5MIN  = 8,
	EnumLuaModule_10MIN = 9,
	EnumLuaModule_30MIN = 10,
	EnumLuaModule_HOUR  = 11,
	EnumLuaModule_DAY   = 12,
	EnumLuaModule_WEEK  = 13,
	EnumLuaModule_MONTH = 14,
};

class NFCLuaScriptModule;

class NFLuaTimer : public NFTimerObj
{
public:
	NFLuaTimer(NFCLuaScriptModule* p, NFIPluginManager* pPluginManager) : NFTimerObj(pPluginManager)
	{
		Clear();
		m_pLuaScriptModule = p;
	}

	void Clear()
	{
		mTimerId = 0;
		mInterVal = 0;
		mCallCount = 0;
		mCurCallCount = 0;
	}

	uint32_t mTimerId;
	std::string m_strLuaFunc;
	uint64_t mInterVal;
	uint32_t mCallCount;
	uint32_t mCurCallCount;
	NFLuaRef mDataStr;
	NFCLuaScriptModule* m_pLuaScriptModule;

	virtual int OnTimer(uint32_t nTimerID) override;
};

struct NetLuaReceiveFunctor
{
	NetLuaReceiveFunctor()
	{
	}

	NetLuaReceiveFunctor(const std::string& luaFunc) : m_strLuaFunc(luaFunc)
	{
	}

	NetLuaReceiveFunctor(const NetLuaReceiveFunctor& functor)
	{
		if (this != &functor)
		{
			m_strLuaFunc = functor.m_strLuaFunc;
		}
	}

	NetLuaReceiveFunctor& operator=(const NetLuaReceiveFunctor& functor)
	{
		if (this != &functor)
		{
			m_strLuaFunc = functor.m_strLuaFunc;
		}

		return *this;
	}

	std::string m_strLuaFunc;
};

struct NetLuaEventFunctor
{
	NetLuaEventFunctor()
	{
	}

	NetLuaEventFunctor(const std::string& luaFunc) : m_strLuaFunc(luaFunc)
	{
	}

	NetLuaEventFunctor(const NetLuaEventFunctor& functor)
	{
		if (this != &functor)
		{
			m_strLuaFunc = functor.m_strLuaFunc;
		}
	}

	NetLuaEventFunctor& operator=(const NetLuaEventFunctor& functor)
	{
		if (this != &functor)
		{
			m_strLuaFunc = functor.m_strLuaFunc;
		}

		return *this;
	}

	std::string m_strLuaFunc;
};

struct NetLuaRpcService
{
	NetLuaRpcService()
	{
	}

	NetLuaRpcService(const std::string& luaFunc) : m_strLuaFunc(luaFunc)
	{
	}

	NetLuaRpcService(const NetLuaRpcService& functor)
	{
		if (this != &functor)
		{
			m_strLuaFunc = functor.m_strLuaFunc;
		}
	}

	NetLuaRpcService& operator=(const NetLuaRpcService& functor)
	{
		if (this != &functor)
		{
			m_strLuaFunc = functor.m_strLuaFunc;
		}

		return *this;
	}

	std::string m_strLuaFunc;
};

struct LuaCallBack
{
	//call back
	LuaCallBack()
	{
		mxReceiveCallBack.resize(NF_MODULE_MAX);
		for (int i = 0; i < (int)mxReceiveCallBack.size(); i++)
		{
			mxReceiveCallBack[i].resize(NF_NET_MAX_MSG_ID);
		}

		mxRpcCallBack.resize(NF_NET_MAX_MSG_ID);
	}

	virtual ~LuaCallBack()
	{
	}

	std::vector<std::vector<NetLuaReceiveFunctor>> mxReceiveCallBack;
	std::unordered_map<uint64_t, NetLuaEventFunctor> mxEventCallBack;
	std::unordered_map<uint64_t, NetLuaReceiveFunctor> mxOtherMsgCallBackList;
	NetLuaReceiveFunctor mxAllMsgCallBackList;
	std::unordered_map<uint32_t, std::unordered_map<std::string, HTTP_RECEIVE_FUNCTOR>> mxHttpMsgCBMap; //uint32_t => NFHttpType
	std::unordered_map<uint32_t, std::vector<HTTP_RECEIVE_FUNCTOR>> mxHttpOtherMsgCBMap;                //uint32_t => NFHttpType
	std::unordered_map<std::string, HTTP_FILTER_FUNCTOR> mxHttpMsgFliterMap;
	std::vector<NetLuaRpcService> mxRpcCallBack;
};

/**
 *@brief Lua事件系统对象
 */
class NFCLuaScriptModule;

class NFLuaEventObj : public NFObject
{
public:
	/**
	 *@brief 构造函数
	 */
	NFLuaEventObj(NFIPluginManager* p, NFCLuaScriptModule* pModule) : NFObject(p),
																	  m_pModule(pModule)
	{
	}

	/**
	 *@brief 析构函数
	 */
	virtual ~NFLuaEventObj()
	{
	}
public:
	/**
	* @brief 收到事件函数, 对收到的事件进行处理
	*
	* @param nEventID		事件ID
	* @param nSrcID			事件源ID，一般都是玩家，生物唯一id
	* @param bySrcType		事件源类型，玩家类型，怪物类型之类的
	* @param pEventContext	发过来的事件数据
	* @return
	*/
	/*
	* 由Fire的问题，导致的问题:
	* 问题1:如果在OnExecute函数里， 调用别的对象的UnSubscribe函数, 如果key一致(也就是nEventID,nSrcID,bySrcType都一样),
	*		可能导致将要执行的事件被删除，这可能与你预想的设计不一样
	* 问题2:如果在OnExecute函数里， Fire了别的事件，会导致迭代问题，事件系统已经了做了预付， 相同的事件，最多迭代5次，
	*       所有的Fire事件最多迭代20次
	*/

	int OnExecuteImple(const SEventKey skey, const NFLuaRef& message);

	int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const NFLuaRef& message);

	int OnExecuteImple(const SEventKey skey, const std::string& msgType, const std::string& msgData);

	int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& msgType, const std::string& msgData);
public:
	std::string m_strLuaFunc;
	NFCLuaScriptModule* m_pModule;
};

class NFCLuaScriptModule
	: public NFILuaScriptModule, public NFILuaLoader
{
public:
	NFCLuaScriptModule(NFIPluginManager* p);

	virtual ~NFCLuaScriptModule();
public:
	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool Shut() override;

	virtual bool Finalize() override;

	virtual int OnTimer(uint32_t nTimerID) override;

	virtual bool OnReloadConfig() override;
public:
	virtual void SessionReport(uint64_t playerId, const std::string& report) override;

	virtual void SessionClose(uint64_t playerId) override;

	virtual void RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr) override;
public:
	virtual uint32_t AddTimer(const std::string& strLuaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef& dataStr);

	virtual uint32_t AddClocker(const std::string& strLuaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef& dataStr);

	virtual void StopTimer(uint32_t nTimerID);

	virtual void StopClocker(uint32_t nTimerID);
public:
	virtual void SendErrorLog(uint64_t id, const std::string& funcLog, const std::string& errorLog, uint32_t count);
public:
	/**
	 * @brief 注册客户端信息处理函数
	 * @param eType
	 * @param nMsgID
	 * @return
	 */
	virtual bool RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const std::string& strLuaFunc, bool createCo = false);

	/**
	 * @brief 注册服务器信息处理函数
	 * @param eType
	 * @param nMsgID
	 * @return
	 */
	virtual bool RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const std::string& strLuaFunc, bool createCo = false);

	/**
	 * @brief 处理客户端消息
	 * @param unLinkId
	 * @param packet
	 * @return
	 */
	virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

	/**
	 * @brief 处理来自服务器的信息
	 * @param unLinkId
	 * @param packet
	 * @return
	 */
	virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);
public:
	/*
	 * 添加连接事件，掉线事件的处理函数
	 * */
	virtual bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, const std::string& strLuaFunc, bool createCo = false);

	/*
	 * 未没有注册过的消息，添加一个统一处理的回调函数
	 * */
	virtual bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, const std::string& strLuaFunc, bool createCo);

	/*
	* 对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
	* */
	virtual bool AddAllMsgCallBack(NF_SERVER_TYPES eType, const std::string& strLuaFunc, bool createCo);
public:
	/*
		处理客户端链接事件和未注册消息
	*/
	virtual int OnHandleServerSocketEvent(eMsgType nEvent, uint64_t unLinkId, uint64_t serverLinkId);

	virtual int OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet, uint64_t serverLinkId);

	virtual int OnHandleAllOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
public:
	virtual int SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const std::string& xData, uint64_t nParam1 = 0,
									  uint64_t nParam2 = 0);
public:
	////////////////////////////send proxy msg to other serer//////////////////////////////////
	virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const std::string& xData,
									uint64_t nParam1 = 0, uint64_t nParam2 = 0);

	////////////////////////////send msg by linkId//////////////////////////////////
	virtual int SendMsgByLinkId(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t param1 = 0, uint64_t param2 = 0);
public:
	///////////////////////////other server send msg to proxy msg/////////////////////////////
	virtual int SendRedirectMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, const std::unordered_set<uint64_t>& ids, uint32_t nMsgId,
											 const string& xData);

	virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const std::string& xData,
									 uint64_t nParam1 = 0, uint64_t nParam2 = 0);

	///////////////////////////other server send msg to world msg/////////////////////////////
	virtual int SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const std::string& xData, uint64_t nParam1 = 0,
									 uint64_t nParam2 = 0);

	virtual int SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const std::string& xData, uint32_t req_trans_id = 0,
									   uint32_t rsp_trans_id = 0);

	///////////////////////////other server send msg to game msg/////////////////////////////
	virtual int SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const std::string& xData,
									uint64_t nParam1 = 0, uint64_t nParam2 = 0);

	virtual int SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const std::string& xData, uint32_t req_trans_id = 0,
									  uint32_t rsp_trans_id = 0);

	///////////////////////////other server send msg to logic server/////////////////////////////
	virtual int SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const std::string& xData,
									 uint64_t nParam1 = 0, uint64_t nParam2 = 0);

	virtual int SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const std::string& xData, uint32_t req_trans_id = 0,
									   uint32_t rsp_trans_id = 0);

	///////////////////////////other server send msg to sns server/////////////////////////////
	virtual int SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const std::string& xData, uint64_t nParam1 = 0,
								   uint64_t nParam2 = 0);

	virtual int SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const std::string& xData, uint32_t req_trans_id = 0,
									 uint32_t rsp_trans_id = 0);
public:
	virtual bool AddRpcService(NF_SERVER_TYPES serverType, uint32_t nMsgId, const std::string& reqType, const std::string& rspType,
							   const std::string& strLuaFunc, bool createCo = false);

	virtual std::tuple<std::string, int> GetRpcService(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, uint32_t msgId, const std::string& reqType,
													   const std::string& request, const std::string& rspType);

	virtual int OnHandleAddRpcService(uint64_t unLinkId, uint32_t msgId, const std::string& reqType, const std::string& request,
									  const std::string& rspType, std::string& respone);
public:
	virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);
public:
	virtual void FireCppExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& msgTypeName,
								const std::string& msgData);

	virtual void FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const NFLuaRef& luaFunc);

	virtual bool Subscribe(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& strLuaFunc);

	//取消订阅执行事件
	virtual bool UnSubscribe(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& strLuaFunc);

	//取消所有执行事件的订阅
	virtual bool UnSubscribeAll(const std::string& strLuaFunc);
public:
	virtual const std::string& GetAppName() const;

	virtual const std::string& GetLuaScriptPath() const;

	virtual const std::string& GetGame() const;

	virtual bool IsAllServer() const;

	virtual int GetAppID() const;

	virtual uint64_t GetInitTime() const;

	virtual uint64_t GetNowTime() const;

	virtual std::string GetMD5(const std::string& str);

	virtual uint32_t GetCRC32(const std::string& s);

	virtual uint16_t GetCRC16(const std::string& s);

	virtual std::string Base64Encode(const std::string& s);

	virtual std::string Base64Decode(const std::string& s);

	virtual uint64_t GetMsecTime() const;

	virtual uint64_t GetSecTime() const;

	virtual bool RegisterSpecialMsg(uint32_t moduleId, uint32_t msgId);

	virtual std::string GetLinkIp(uint64_t usLinkId);

	virtual uint32_t GetPort(uint64_t usLinkId);
public:
	virtual std::vector<NF_SHARE_PTR<NFServerData>> GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

	virtual NF_SHARE_PTR<NFServerData> GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

	virtual NF_SHARE_PTR<NFServerData> GetFirstServerByCross(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, bool crossServer);

	virtual NF_SHARE_PTR<NFServerData> GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

	virtual NF_SHARE_PTR<NFServerData> GetRandomServerByCross(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, bool crossServer);

	virtual NF_SHARE_PTR<NFServerData> GetSuitServerByInt(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value);

	virtual NF_SHARE_PTR<NFServerData> GetSuitServerByIntCross(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value, bool crossServer);

	virtual NF_SHARE_PTR<NFServerData> GetSuitServerByStr(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string &value);

	virtual NF_SHARE_PTR<NFServerData> GetSuitServerByStrCross(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string &value, bool crossServer);
public:
	void SetLogLevel(uint32_t level);

	void SetFlushOn(uint32_t level);

	void LuaTrace(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log);

	void LuaDebug(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log);

	void LuaInfo(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log);

	void LuaWarn(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log);

	void LuaError(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log);
public:
	virtual void BeginProfiler(const std::string& luaFunc);

	virtual uint64_t EndProfiler(); //return this time cost time(us) 微妙

	virtual void ReloadAllLuaFiles();

	virtual void ReloadLuaFiles();

	virtual void ReloadLuaFiles(const std::vector<std::string>& vecStr);

	virtual std::string Sha256(const std::string& s);

	virtual std::string Platform();

	virtual bool IsThreadModule();

	virtual bool IsDebug();

	virtual bool IsInited();

	virtual bool IsServerStopping();

	virtual NFServerConfig* GetAppConfig(uint32_t serverType);

	virtual uint64_t GetClientLinkId(uint32_t serverType);

	virtual uint64_t GetServerLinkId(uint32_t serverType);

	virtual bool IsLuaFunction(const std::string& strLuaFunc);
	virtual LuaIntf::LuaRef GetLuaData(const std::string& strLuaFunc);
public:
	bool Register();

	void LoadScript();

	virtual void UpdateSec();

	virtual void UpdateMin();

	virtual void Update5Min();

	virtual void Update10Min();

	virtual void Update30Min();

	virtual void UpdateHour();

	virtual void UpdateDay();

	virtual void UpdateWeek();

	virtual void UpdateMonth();
protected:
	std::unordered_map<uint64_t, NFLuaTimer *> m_luaTimerMap;
	NFObjectPool<NFLuaTimer>* m_luaTimerPool;
	uint32_t m_luaTimerIndex;
protected:
	std::unordered_map<std::string, std::unordered_map<SEventKey, NFLuaEventObj *>> m_luaEventMap;
	NFObjectPool<NFLuaEventObj>* m_luaEventPool;
	NFEventTemplate<NFLuaEventObj, SEventKey> m_eventTemplate;
protected:
	std::vector<LuaCallBack> mxLuaCallBack;
};
