//
// Created by gaoyi on 2022/9/21.
//

#include "NFLogicCommon.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFMD5.h"

NFLogicCommon::NFLogicCommon()
{

}

NFLogicCommon::~NFLogicCommon()
{

}

std::string NFLogicCommon::GetLoginToken(const std::string& account, uint64_t userId, uint64_t time, const std::string& specialStr)
{
    std::string token = account + NFCommon::tostr(userId) + NFCommon::tostr(time) + specialStr;
    return NFMD5::md5str(token);
}

void NFLogicCommon::NFPoint3ToProto(const NFPoint3<float>& pos, proto_ff::Vector3PB& proto)
{
    proto.set_x(pos.x);
    proto.set_y(pos.y);
    proto.set_z(pos.z);
}

void NFLogicCommon::NFPoint3FromProto(NFPoint3<float>& pos, const proto_ff::Vector3PB& proto)
{
    pos.x = proto.x();
    pos.y = proto.y();
    pos.z = proto.z();
}