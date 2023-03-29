// -------------------------------------------------------------------------
//    @FileName         :    NFIMsgModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFError.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFStoreProtoCommon.h"
#include "NFServerBindRpcService.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <map>
#include <functional>
#include <unordered_set>

//#define TEST_SERVER_SEND_MSG
#define TEST_SERVER_SEND_MSG_FRAME_COUNT 10

/// @brief 基于消息的通讯接口类
class NFIServerMessageModule : public NFIDynamicModule
{
public:
    NFIServerMessageModule(NFIPluginManager *p) : NFIDynamicModule(p)
    {

    }

    virtual ~NFIServerMessageModule()
    {

    }

public:
    virtual int SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                                      uint64_t nParam2 = 0) = 0;

public:
    ////////////////////////////send proxy msg to other serer//////////////////////////////////
    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                        uint64_t nParam2 = 0) = 0;

    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                        uint64_t nParam1 = 0, uint64_t nParam2 = 0) = 0;

    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t nParam1 = 0,
                                    uint64_t nParam2 = 0) = 0;

    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                                    uint64_t nParam1 = 0, uint64_t nParam2 = 0) = 0;

    ///////////////////////////other server send msg to proxy server/////////////////////////////
    virtual int SendRedirectMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, const std::unordered_set<uint64_t> &ids, uint32_t nMsgId,
                                             const google::protobuf::Message &xData) = 0;

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                         uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t nParam1 = 0, uint64_t nParam2 = 0) = 0;

    ///////////////////////////other server send msg to world server/////////////////////////////
    virtual int SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                                     uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                         uint64_t nParam2 = 0) = 0;

    virtual int SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0,
                                       uint32_t rsp_trans_id = 0) = 0;

    ///////////////////////////other server send msg to game server/////////////////////////////
    virtual int
    SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                        uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                        uint64_t nParam1 = 0, uint64_t nParam2 = 0) = 0;

    virtual int
    SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0,
                          uint32_t rsp_trans_id = 0) = 0;

    ///////////////////////////other server send msg to logic server/////////////////////////////
    virtual int
    SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                         uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t nParam1 = 0, uint64_t nParam2 = 0) = 0;

    virtual int
    SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0,
                           uint32_t rsp_trans_id = 0) = 0;

    ///////////////////////////other server send msg to sns server/////////////////////////////
    virtual int SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                                   uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                       uint64_t nParam2 = 0) = 0;

    virtual int SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0,
                                     uint32_t rsp_trans_id = 0) = 0;

public:
    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                           const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData, int trans_id = 0,
                           uint32_t seq = 0,
                           uint64_t mod_key = 0, const std::string &cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) = 0;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                           const std::string &dbname, const std::string &table_name, const std::vector<std::string> &vecFileds,
                           const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                           const std::string &where_addtional_conds, int max_records = 100, int trans_id = 0, uint32_t seq = 0,
                           uint64_t mod_key = 0, const std::string &cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) = 0;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                           const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                           const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                           const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                           uint64_t mod_key = 0, const std::string &cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) = 0;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                           const std::string &dbname, const std::string &table_name, const std::string &xData, int max_records, int trans_id = 0,
                           uint32_t seq = 0,
                           uint64_t mod_key = 0, const std::string &cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) = 0;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                           const std::string &dbname, const std::string &table_name, const std::string &xData, int trans_id = 0, uint32_t seq = 0,
                           uint64_t mod_key = 0, const std::string &cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) = 0;

public:
    ///////////////////////store server select obj////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcSelectObjService(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data,
                               const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                               const std::string &dbname = "")
    {
        std::string tempDBName = dbname;
        if (dbname.empty())
        {
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
            if (pConfig)
            {
                tempDBName = pConfig->DefaultDBName;
            }
        }
        CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");


        storesvr_sqldata::storesvr_selobj selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_selectobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName, vecFields);

        storesvr_sqldata::storesvr_selobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_SELECTOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0)
        {
            data.ParseFromString(selobjRes.sel_record());
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, proto_ff::E_STORESVR_C2S_SELECTOBJ iRet:{} errMsg:{}", GetErrorStr(iRet),
                       selobjRes.sel_opres().errmsg());
        }
        return iRet;
    }

    template<class DataType, typename ResponFunc>
    int GetRpcSelectObjService(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data, const ResponFunc &func,
                               const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                               const std::string &dbname = "")
    {
        return GetRpcSelectObjServiceInner(eType, mod_key, data, func, &ResponFunc::operator(), vecFields, dstBusId, dbname);
    }

    virtual int SendSelectObjTrans(NF_SERVER_TYPES eType, uint64_t mod_key, google::protobuf::Message &data, uint32_t table_id = 0, int trans_id = 0,
                                   uint32_t seq = 0,
                                   const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                                   const std::string &dbname = "") = 0;

private:
    template<class DataType, typename ResponFunc>
    int GetRpcSelectObjServiceInner(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data, const ResponFunc &responFunc,
                                    void (ResponFunc::*pf)(int rpcRetCode, DataType &respone) const,
                                    const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                                    const std::string &dbname = "")
    {
        int iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     DataType respone = data;
                     int rpcRetCode = GetRpcSelectObjService(eType, mod_key, respone, vecFields,
                                                             dstBusId, dbname);
                     (responFunc.*pf)(rpcRetCode, respone);
                 });
        return iRet;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcSelectService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, std::vector<DataType> &respone,
                            const std::vector<std::string> &vecFields = std::vector<std::string>(), const std::string &where_addtional_conds = "",
                            int max_records = 100, uint32_t dstBusId = 0,
                            const std::string &dbname = "")
    {
        std::string tempDBName = dbname;
        if (dbname.empty())
        {
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
            if (pConfig)
            {
                tempDBName = pConfig->DefaultDBName;
            }
        }
        CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");


        storesvr_sqldata::storesvr_sel sel;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");

        std::vector<storesvr_sqldata::storesvr_vk> vk_list;
        NFStoreProtoCommon::get_vk_list_from_proto(data, vk_list);

        NFStoreProtoCommon::storesvr_selectbycond(sel, tempDBName, tbname, mod_key, vecFields, vk_list, where_addtional_conds, max_records,
                                                  tbname, packageName);

        storesvr_sqldata::storesvr_sel_res selRes;
        STATIC_ASSERT_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_SELECT, storesvr_sqldata::storesvr_sel, storesvr_sqldata::storesvr_sel_res);
        NF_ASSERT_MSG(FindModule<NFICoroutineModule>()->IsInCoroutine(), "Call GetRpcService Must Int the Coroutine");
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
        CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(eType));

        proto_ff::Proto_SvrPkg svrPkg;
        svrPkg.set_msg_id(proto_ff::NF_STORESVR_C2S_SELECT);
        svrPkg.set_msg_data(sel.SerializeAsString());
        svrPkg.mutable_rpc_info()->set_req_rpc_id(FindModule<NFICoroutineModule>()->CurrentTaskId());
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(std::hash<std::string>()(sel.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(std::hash<std::string>()(selRes.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_req_server_type(eType);
        svrPkg.mutable_rpc_info()->set_req_bus_id(pConfig->BusId);

        FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, pConfig->BusId, dstBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD,
                                                        svrPkg);

        int iRet = FindModule<NFICoroutineModule>()->AddRpcService(&selRes);
        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));

        do
        {
            iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);
            CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));
            if (iRet == 0)
            {
                for (int i = 0; i < (int) selRes.sel_records_size(); i++)
                {
                    DataType result;
                    result.ParseFromString(selRes.sel_records(i));
                    respone.push_back(result);
                }

                if (selRes.is_lastbatch())
                {
                    break;
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, proto_ff::E_STORESVR_C2S_SELECTOBJ iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selRes.sel_opres().errmsg());
                break;
            }
        } while (true);


        FindModule<NFICoroutineModule>()->DelRpcService(&selRes);

        return iRet;
    }

    template<class DataType, typename ResponFunc>
    int GetRpcSelectService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const ResponFunc &func,
                             const std::vector<std::string> &vecFields = std::vector<std::string>(), const std::string &where_addtional_conds = "",
                             int max_records = 100, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        return GetRpcSelectServiceInner(eType, mod_key, data, func, &ResponFunc::operator(), vecFields,where_addtional_conds, max_records, dstBusId, dbname);
    }

private:
    template<class DataType, typename ResponFunc>
    int GetRpcSelectServiceInner(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const ResponFunc &responFunc,
                                 void (ResponFunc::*pf)(int rpcRetCode, std::vector<DataType> &respone) const,
                                 const std::vector<std::string> &vecFields = std::vector<std::string>(),
                                 const std::string &where_addtional_conds = "", int max_records = 100, uint32_t dstBusId = 0,
                                 const std::string &dbname = "")
    {
        int iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     std::vector<DataType> respone;
                     int rpcRetCode = GetRpcSelectService(eType, mod_key, data, respone, vecFields, where_addtional_conds, max_records,
                                                          dstBusId, dbname);

                     (responFunc.*pf)(rpcRetCode, respone);
                 });
        return iRet;
    }

public:
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server insert////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcInsertObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        std::string tempDBName = dbname;
        if (dbname.empty())
        {
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
            if (pConfig)
            {
                tempDBName = pConfig->DefaultDBName;
            }
        }
        CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");


        storesvr_sqldata::storesvr_insertobj selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_insertobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName);

        storesvr_sqldata::storesvr_insertobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_INSERTOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0)
        {
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, proto_ff::NF_STORESVR_C2S_INSERTOBJ iRet:{} errMsg:{}", GetErrorStr(iRet),
                       selobjRes.ins_opres().errmsg());
        }
        return iRet;
    }

    template<class DataType>
    int GetRpcInsertObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                               uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcInsertObjService(eType, mod_key, data, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }

/*    virtual int SendInsertObjTrans(NF_SERVER_TYPES eType, uint64_t mod_key, google::protobuf::Message &data, uint32_t table_id = 0, int trans_id = 0,
                                   uint32_t seq = 0,
                                   const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                                   const std::string &dbname = "") = 0;*/

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server modifyobj////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcModifyObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        std::string tempDBName = dbname;
        if (dbname.empty())
        {
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
            if (pConfig)
            {
                tempDBName = pConfig->DefaultDBName;
            }
        }
        CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");


        storesvr_sqldata::storesvr_modobj selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_insertobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName);

        storesvr_sqldata::storesvr_modobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_MODIFYOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0)
        {
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, proto_ff::NF_STORESVR_C2S_MODIFYOBJ iRet:{} errMsg:{}", GetErrorStr(iRet),
                       selobjRes.mod_opres().errmsg());
        }
        return iRet;
    }

    template<class DataType>
    int GetRpcModifyObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                               uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcModifyObjService(eType, mod_key, data, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server UpdateObj////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcUpdateObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        std::string tempDBName = dbname;
        if (dbname.empty())
        {
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
            if (pConfig)
            {
                tempDBName = pConfig->DefaultDBName;
            }
        }
        CHECK_EXPR(!tempDBName.empty(), -1, "no dbname ........");


        storesvr_sqldata::storesvr_modinsobj selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_insertobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName);

        storesvr_sqldata::storesvr_modinsobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_MODINSOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0)
        {
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, proto_ff::NF_STORESVR_C2S_MODINSOBJ iRet:{} errMsg:{}", GetErrorStr(iRet),
                       selobjRes.modins_opres().errmsg());
        }
        return iRet;
    }

    template<class DataType>
    int GetRpcModInsObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                               uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcModInsObjService(eType, mod_key, data, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
