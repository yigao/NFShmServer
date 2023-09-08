// -------------------------------------------------------------------------
//    @FileName         :    NFCShmOtherModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-8
//    @Email			:    445267987@qq.com
//    @Module           :    NFCShmOtherModule
//
// -------------------------------------------------------------------------

#include "NFCShmOtherModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

NFCShmOtherModule::NFCShmOtherModule(NFIPluginManager *p): NFIDynamicModule(p)
{

}

NFCShmOtherModule::~NFCShmOtherModule()
{
}

bool NFCShmOtherModule::Awake()
{
    Subscribe(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    return true;
}

int NFCShmOtherModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
            /*
            初始化完毕
            */
            FindModule<NFISharedMemModule>()->SetShmInitSuccessFlag();
        }
    }

    return 0;
}


