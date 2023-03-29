// -------------------------------------------------------------------------
//    @FileName         :    NFTransLogicUserBase.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransLogicUserBase.h
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFShmString.h"
#include "Base/NFTransPlayerBase.h"
#include "DBProto.pb.h"

typedef enum
{
	TRANS_SAVE_ROLE_DETAIL_STATE_INIT = 0,
	TRANS_SAVE_ROLE_DETAIL_STATE_SAVING_ROLE = 1,
	TRANS_SAVE_ROLE_DETAIL_FIN_OK,
} TRANS_SAVE_ROLE_DETAIL_STATE;

typedef enum
{
	TRANS_SAVE_ROLE_DETAIL_NORMAL = 1,
	TRANS_SAVE_ROLE_DETAIL_LOGOUT = 2,
} TRANS_SAVE_ROLE_DETAIL_REASON;

class NFTransSaveRoleDetail : public NFTransPlayerBase {
public:
	NFTransSaveRoleDetail();

	virtual ~NFTransSaveRoleDetail();

	int CreateInit();

	int ResumeInit();

    virtual std::string DebugString() const override;
public:
    /**
     * @brief
     * @param pCSMsgReq
     * @return
     */
	virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) override;

    /**
     * @brief
     * @param pSSMsgRes
     * @param cmd
     * @param table_id
     * @param seq
     * @param err_code
     * @return
     */
	virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
		uint32_t seq, int32_t err_code) override;;

    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
	virtual int HandleTransFinished(int iRunLogicRetCode) override;;
public:
    /**
     * @brief
     * @param iReason
     * @return
     */
	int SaveRoleDetail(TRANS_SAVE_ROLE_DETAIL_REASON iReason = TRANS_SAVE_ROLE_DETAIL_NORMAL);

    /**
     * @brief
     * @param err_code
     * @param seq
     * @return
     */
	int HandleSaveRoleDetailRes(uint32_t err_code, uint32_t seq);
private:
    TRANS_SAVE_ROLE_DETAIL_REASON m_reason;
	DECLARE_IDCREATE(NFTransSaveRoleDetail)
};
