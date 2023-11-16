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
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <map>
#include <functional>
#include <unordered_set>

//#define TEST_SERVER_SEND_MSG
#define TEST_SERVER_SEND_MSG_FRAME_COUNT 1

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

    virtual int SendRedirectMsgToAllProxyServer(NF_SERVER_TYPES eType, const std::unordered_set<uint64_t> &ids, uint32_t nMsgId,
                                         const google::protobuf::Message &xData) = 0;

    virtual int SendRedirectMsgToAllProxyServer(NF_SERVER_TYPES eType, uint32_t nMsgId,
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

    ///////////////////////////other server send msg to center server/////////////////////////////
    virtual int SendMsgToCenterServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                                     uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToCenterServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                         uint64_t nParam2 = 0) = 0;

    virtual int SendTransToCenterServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0,
                                       uint32_t rsp_trans_id = 0) = 0;

    virtual int SendMsgToCrossCenterServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                                 uint64_t nParam2 = 0) = 0;

    virtual int
    SendMsgToCrossCenterServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0,
                         uint64_t nParam2 = 0) = 0;

    virtual int SendTransToCrossCenterServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0,
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
    /**
     * @brief 调用StoreServer的selectobj rpc， 查询数据库里的一条数据,  通过protobuf结构data传数据的key, 并通过protobuf结构data存储返回来的结果。这个函数必须在携程里调用数。
     * @tparam DataType     代表要查询的表的protobuf结构,
     * @param eType         服务器类型
     * @param mod_key       用来作为多线程查询的哈希一致性的key,0表示随机
     * @param data          作为输入存储查询的key, 作为输出存储查询的结果
     * @param vecFields     要查询的列，不填意味着查询所有的列
     * @param dstBusId      指定负责查询的storeserver
     * @param dbname        指定要查询的数据库
     * @return
     */
    template<typename DataType>
    int GetRpcSelectObjService(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data,
                               const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0, const std::string& tbname = "",
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
        std::string clsname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        std::string tempTbName;
        if (tbname.empty())
        {
            tempTbName = clsname;
        }
        else {
            tempTbName = tbname;
        }

        CHECK_EXPR(!tempTbName.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_selectobj(selobj, tempDBName, tempTbName, mod_key, data, clsname, packageName, vecFields);

        storesvr_sqldata::storesvr_selobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_SELECTOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
            data.ParseFromString(selobjRes.record());
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                if (iRet != proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::E_STORESVR_C2S_SELECTOBJ Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                               selobjRes.opres().errmsg());
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType, typename ResponFunc>
    int64_t GetRpcSelectObjService(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data, const ResponFunc &func,
                                   const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                                   const std::string& tbname = "", const std::string &dbname = "")
    {
        return GetRpcSelectObjServiceInner(eType, mod_key, data, func, &ResponFunc::operator(), vecFields, dstBusId, tbname, dbname);
    }

    virtual int SendSelectObjTrans(NF_SERVER_TYPES eType, uint64_t mod_key, google::protobuf::Message &data, uint32_t table_id = 0, int trans_id = 0,
                                   uint32_t seq = 0,
                                   const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                                   const std::string &dbname = "") = 0;

private:
    template<class DataType, typename ResponFunc>
    int64_t GetRpcSelectObjServiceInner(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data, const ResponFunc &responFunc,
                                        void (ResponFunc::*pf)(int rpcRetCode, DataType &respone) const,
                                        const std::vector<std::string> &vecFields = std::vector<std::string>(), uint32_t dstBusId = 0,
                                        const std::string& tbname = "", const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     DataType respone = data;
                     int rpcRetCode = GetRpcSelectObjService(eType, mod_key, respone, vecFields,
                                                             dstBusId, tbname, dbname);
                     (responFunc.*pf)(rpcRetCode, respone);
                 });
        return iRet;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    int GetRpcDescStoreService(NF_SERVER_TYPES eType, uint64_t mod_key, google::protobuf::Message *pDescStoreMessage,
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
        std::string tbname = NFProtobufCommon::GetDescStoreClsName(*pDescStoreMessage);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(*pDescStoreMessage);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");

        std::vector<storesvr_sqldata::storesvr_vk> vk_list;
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
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(NFHash::hash<std::string>()(sel.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(NFHash::hash<std::string>()(selRes.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_req_server_type(eType);
        svrPkg.mutable_rpc_info()->set_req_bus_id(pConfig->BusId);

        FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, pConfig->BusId, dstBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD,
                                                        svrPkg);

        int iRet = FindModule<NFICoroutineModule>()->SetUserData(&selRes);
        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));

        do
        {
            iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);
            CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));
            if (iRet == 0 && selRes.opres().err_code() == 0)
            {
                const google::protobuf::Descriptor *pSheetFieldDesc = pDescStoreMessage->GetDescriptor();
                CHECK_EXPR(pSheetFieldDesc, -1, "pSheetFieldDesc == NULL");
                const google::protobuf::Reflection *pSheetReflect = pDescStoreMessage->GetReflection();
                CHECK_EXPR(pSheetReflect, -1, "pSheetFieldDesc == NULL");

                if (pSheetFieldDesc->field_count() > 0)
                {
                    /*  比如 message Sheet_GameRoomDesc
                    *		{
                    *			repeated GameRoomDesc GameRoomDesc_List = 1  [(yd_fieldoptions.field_arysize)=100];
                    *		}
                    *		获得上面GameRoomDesc_List信息
                    */
                    const google::protobuf::FieldDescriptor *pSheetRepeatedFieldDesc = pSheetFieldDesc->field(0);
                    if (pSheetRepeatedFieldDesc->is_repeated() &&
                        pSheetRepeatedFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
                    {
                        //如果is_repeated 开始处理
                        for (int i = 0; i < (int) selRes.record_size(); i++)
                        {
                            ::google::protobuf::Message *pSheetRepeatedMessageObject = pSheetReflect->AddMessage(
                                    pDescStoreMessage, pSheetRepeatedFieldDesc);
                            pSheetRepeatedMessageObject->ParsePartialFromString(selRes.record(i));
                        }
                    }
                }

                if (selRes.is_lastbatch())
                {
                    break;
                }
            }
            else
            {
                if (iRet == 0)
                {
                    iRet = selRes.opres().err_code();
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcDescStoreService Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                               selRes.opres().errmsg());
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcDescStoreService Failed, iRet:{}", GetErrorStr(iRet));
                }

                break;
            }
        } while (true);


        FindModule<NFICoroutineModule>()->SetUserData(NULL);

        return iRet;
    }

    template<typename DataType>
    int GetRpcSelectService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, std::vector<DataType> &respone,
                            const std::vector<std::string> &vecFields = std::vector<std::string>(),
                            const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                            const std::string &where_addtional_conds = "",
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
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(NFHash::hash<std::string>()(sel.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(NFHash::hash<std::string>()(selRes.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_req_server_type(eType);
        svrPkg.mutable_rpc_info()->set_req_bus_id(pConfig->BusId);

        FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, pConfig->BusId, dstBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD,
                                                        svrPkg);

        int iRet = FindModule<NFICoroutineModule>()->SetUserData(&selRes);
        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));

        do
        {
            iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);
            CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));
            if (iRet == 0 && selRes.opres().err_code() == 0)
            {
                for (int i = 0; i < (int) selRes.record_size(); i++)
                {
                    DataType result;
                    result.ParseFromString(selRes.record(i));
                    respone.push_back(result);
                }

                if (selRes.is_lastbatch())
                {
                    break;
                }
            }
            else
            {
                if (iRet == 0)
                {
                    iRet = selRes.opres().err_code();
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::E_STORESVR_C2S_SELECT Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                               selRes.opres().errmsg());
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
                }

                break;
            }
        } while (true);


        FindModule<NFICoroutineModule>()->SetUserData(NULL);

        return iRet;
    }

    template<class DataType, typename ResponFunc>
    int64_t GetRpcSelectService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const ResponFunc &func,
                                const std::vector<std::string> &vecFields = std::vector<std::string>(),
                                const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                                const std::string &where_addtional_conds = "",
                                int max_records = 100, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        return GetRpcSelectServiceInner(eType, mod_key, data, func, &ResponFunc::operator(), vecFields, vk_list, where_addtional_conds, max_records, dstBusId,
                                        dbname);
    }

private:
    template<class DataType, typename ResponFunc>
    int64_t GetRpcSelectServiceInner(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const ResponFunc &responFunc,
                                     void (ResponFunc::*pf)(int rpcRetCode, std::vector<DataType> &respone) const,
                                     const std::vector<std::string> &vecFields = std::vector<std::string>(),
                                     const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                                     const std::string &where_addtional_conds = "", int max_records = 100, uint32_t dstBusId = 0,
                                     const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     std::vector<DataType> respone;
                     int rpcRetCode = GetRpcSelectService(eType, mod_key, data, respone, vecFields, vk_list, where_addtional_conds, max_records,
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
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_INSERTOBJ Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcInsertObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                   uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
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
        NFStoreProtoCommon::storesvr_modifyobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName);

        storesvr_sqldata::storesvr_modobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_MODIFYOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_MODIFYOBJ Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcModifyObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                   uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
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


        storesvr_sqldata::storesvr_updateobj selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_updateobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName);

        storesvr_sqldata::storesvr_updateobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_UPDATEOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_UPDATEOBJ Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcUpdateObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                   uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcUpdateObjService(eType, mod_key, data, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server delete obj////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcDeleteObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, uint32_t dstBusId = 0, const std::string &dbname = "")
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


        storesvr_sqldata::storesvr_delobj selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_deleteobj(selobj, tempDBName, tbname, mod_key, data, tbname, packageName);

        storesvr_sqldata::storesvr_delobj_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_DELETEOBJ>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                      selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_DELETEOBJ Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcDeleteObjService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                   uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcDeleteObjService(eType, mod_key, data, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server delete////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcDeleteService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data,
                            const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                            const std::string &where_addtional_conds = "",
                            uint32_t dstBusId = 0, const std::string &dbname = "")
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


        storesvr_sqldata::storesvr_del selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_deletebycond(selobj, tempDBName, tbname, mod_key, vk_list, where_addtional_conds, tbname, packageName);

        storesvr_sqldata::storesvr_del_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_DELETE>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                   selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_DELETE Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcDeleteService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                                const std::string &where_addtional_conds = "",
                                uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcDeleteService(eType, mod_key, data, vk_list, where_addtional_conds, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server modify////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcModifyService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data,
                            const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                            const std::string &where_addtional_conds = "", uint32_t dstBusId = 0, const std::string &dbname = "")
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


        storesvr_sqldata::storesvr_mod selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_modifybycond(selobj, tempDBName, tbname, mod_key, data, vk_list, where_addtional_conds, tbname, packageName);

        storesvr_sqldata::storesvr_mod_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_MODIFY>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                   selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_MODIFY Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcModifyService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                                const std::string &where_addtional_conds = "",
                                uint32_t
                                dstBusId = 0,
                                const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcModifyService(eType, mod_key, data, vk_list, where_addtional_conds, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int GetRpcUpdateService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data,
                            const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                            const std::string &where_addtional_conds = "", uint32_t dstBusId = 0, const std::string &dbname = "")
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


        storesvr_sqldata::storesvr_update selobj;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");
        NFStoreProtoCommon::storesvr_updatebycond(selobj, tempDBName, tbname, mod_key, data, vk_list, where_addtional_conds, tbname, packageName);

        storesvr_sqldata::storesvr_update_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_UPDATE>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                   selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_MODINS Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }
        }
        return iRet;
    }

    template<class DataType>
    int64_t GetRpcUpdateService(NF_SERVER_TYPES eType, uint64_t mod_key, const DataType &data, const std::function<void(int)> &func,
                                const std::vector<storesvr_sqldata::storesvr_vk> &vk_list = std::vector<storesvr_sqldata::storesvr_vk>(),
                                const std::string &where_addtional_conds = "",
                                uint32_t
                                dstBusId = 0,
                                const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     int rpcRetCode = GetRpcUpdateService(eType, mod_key, data, vk_list, where_addtional_conds, dstBusId, dbname);
                     if (func)
                     {
                         func(rpcRetCode);
                     }
                 });
        return iRet;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server update////////////////////////////////////////////////////////////////////////////
    template<class DataType>
    int GetRpcExecuteService(NF_SERVER_TYPES eType, uint64_t mod_key, DataType &data, const std::string &sql,
                             uint32_t dstBusId = 0,
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


        storesvr_sqldata::storesvr_execute selobj;
        std::string clsname = NFProtobufCommon::GetProtoBaseName(data);
        //std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!clsname.empty(), -1, "no clsname ........");
        NFStoreProtoCommon::storesvr_execute(selobj, tempDBName, clsname, mod_key, sql);
        storesvr_sqldata::storesvr_execute_res selobjRes;
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_STORESVR_C2S_EXECUTE>(eType, NF_ST_STORE_SERVER, dstBusId, selobj,
                                                                                                    selobjRes);
        if (iRet == 0 && selobjRes.opres().err_code() == 0)
        {
            data.ParseFromString(selobjRes.record());
        }
        else
        {
            if (iRet == 0)
            {
                iRet = selobjRes.opres().err_code();
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_EXECUTE Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                           selobjRes.opres().errmsg());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
            }

        }
        return iRet;
    }

    template<typename ResponFunc>
    int GetRpcExecuteService(NF_SERVER_TYPES eType, uint64_t mod_key, const std::string &sql,
                             const ResponFunc &func, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        return GetRpcExecuteServiceInner(eType, mod_key, sql, func, &ResponFunc::operator(), dstBusId, dbname);
    }

private:
    template<class DataType, typename ResponFunc>
    int64_t GetRpcExecuteServiceInner(NF_SERVER_TYPES eType, uint64_t mod_key, const std::string &sql,
                                      const ResponFunc &responFunc, void (ResponFunc::*pf)(int rpcRetCode, DataType &respone) const,
                                      uint32_t dstBusId = 0,
                                      const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     DataType respone;
                     int rpcRetCode = GetRpcExecuteService(eType, mod_key, respone, sql, dstBusId, dbname);
                     (responFunc.*pf)(rpcRetCode, respone);
                 });
        return iRet;
    }

public:
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////store server select////////////////////////////////////////////////////////////////////////////
    template<typename DataType>
    int
    GetRpcExecuteMoreService(NF_SERVER_TYPES eType, uint64_t mod_key, std::vector<DataType> &respone, const std::string &sql, int max_records = 100,
                             uint32_t dstBusId = 0,
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

        DataType data;
        storesvr_sqldata::storesvr_execute_more sel;
        std::string tbname = NFProtobufCommon::GetProtoBaseName(data);
        std::string packageName = NFProtobufCommon::GetProtoPackageName(data);
        CHECK_EXPR(!tbname.empty(), -1, "no tbname ........");

        NFStoreProtoCommon::storesvr_execute_more(sel, tempDBName, tbname, mod_key, sql, max_records, tbname, packageName);
        storesvr_sqldata::storesvr_execute_more_res selRes;
        STATIC_ASSERT_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_EXECUTE_MORE, storesvr_sqldata::storesvr_execute_more,
                                       storesvr_sqldata::storesvr_execute_more_res);
        NF_ASSERT_MSG(FindModule<NFICoroutineModule>()->IsInCoroutine(), "Call GetRpcService Must Int the Coroutine");
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
        CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(eType));

        proto_ff::Proto_SvrPkg svrPkg;
        svrPkg.set_msg_id(proto_ff::NF_STORESVR_C2S_EXECUTE_MORE);
        svrPkg.set_msg_data(sel.SerializeAsString());
        svrPkg.mutable_rpc_info()->set_req_rpc_id(FindModule<NFICoroutineModule>()->CurrentTaskId());
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(NFHash::hash<std::string>()(sel.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(NFHash::hash<std::string>()(selRes.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_req_server_type(eType);
        svrPkg.mutable_rpc_info()->set_req_bus_id(pConfig->BusId);

        FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, pConfig->BusId, dstBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD,
                                                        svrPkg);

        int iRet = FindModule<NFICoroutineModule>()->SetUserData(&selRes);
        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));

        do
        {
            iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);
            CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));
            if (iRet == 0 && selRes.opres().err_code() == 0)
            {
                for (int i = 0; i < (int) selRes.record_size(); i++)
                {
                    DataType result;
                    result.ParseFromString(selRes.record(i));
                    respone.push_back(result);
                }

                if (selRes.is_lastbatch())
                {
                    break;
                }
            }
            else
            {
                if (iRet == 0)
                {
                    iRet = selRes.opres().err_code();
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "proto_ff::NF_STORESVR_C2S_EXECUTE_MORE Failed, iRet:{} errMsg:{}", GetErrorStr(iRet),
                               selRes.opres().errmsg());
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService Failed, iRet:{}", GetErrorStr(iRet));
                }

                break;
            }
        } while (true);


        FindModule<NFICoroutineModule>()->SetUserData(NULL);

        return iRet;
    }

    template<typename ResponFunc>
    int64_t GetRpcExecuteMoreService(NF_SERVER_TYPES eType, uint64_t mod_key, const std::string &sql, const ResponFunc &func,
                                     int max_records = 100, uint32_t dstBusId = 0, const std::string &dbname = "")
    {
        return GetRpcExecuteMoreServiceInner(eType, mod_key, sql, func, &ResponFunc::operator(), max_records, dstBusId,
                                             dbname);
    }

private:
    template<class DataType, typename ResponFunc>
    int64_t GetRpcExecuteMoreServiceInner(NF_SERVER_TYPES eType, uint64_t mod_key, const std::string &sql, const ResponFunc &responFunc,
                                          void (ResponFunc::*pf)(int rpcRetCode, std::vector<DataType> &respone) const,
                                          int max_records = 100, uint32_t dstBusId = 0,
                                          const std::string &dbname = "")
    {
        int64_t iRet = FindModule<NFICoroutineModule>()->MakeCoroutine
                ([=]()
                 {
                     std::vector<DataType> respone;
                     int rpcRetCode = GetRpcExecuteMoreService(eType, mod_key, respone, sql, max_records,
                                                               dstBusId, dbname);

                     (responFunc.*pf)(rpcRetCode, respone);
                 });
        return iRet;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
