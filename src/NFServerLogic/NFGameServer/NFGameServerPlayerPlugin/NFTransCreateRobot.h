// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateRobot.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateRobot.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"

class NFTransCreateRobot : public NFTransBase {
public:
    NFTransCreateRobot();

    virtual ~NFTransCreateRobot();

    int CreateInit();

    int ResumeInit();

    virtual int HandleTransFinished(int iRunLogicRetCode);

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);
public:
    int Init(uint32_t gameId, uint32_t roomId);
    int CreateRobotAccount();
    int ProCreateAccountRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    int ProGetAccountInfoReq();
    int ProGetDetailInfoReq();
    int ProGetSimpleInfoReq();
    int ProGetAccountInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    int ProGetDetailInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    int ProGetSimpleInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);

    int CreateRobotDetail();
    int CreateRobotSimpleDetail(const proto_ff::tbUserDetailData& userDetail);
protected:
    NFSizeString<MAX_PLAYER_ACCOUNT_SIZE>  mAccount;
    uint64_t m_userId;
    uint32_t m_gameId;
    uint32_t m_roomId;
DECLARE_IDCREATE(NFTransCreateRobot)
};