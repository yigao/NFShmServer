// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPaoMaDengMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWorldPaoMaDengMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFPaoMaDengMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFGameSessionMgr.h"
#include "NFGameRoomMgr.h"
#include "NFGameRoom.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFServer/NFCommHead/NFICommLogicModule.h"

NFPaoMaDengMgr::NFPaoMaDengMgr() {

}

NFPaoMaDengMgr::~NFPaoMaDengMgr() {

}

int NFPaoMaDengMgr::Init()
{
    SetTimer(1, 5000);
    return 0;
}

int NFPaoMaDengMgr::AddPaoMaDeng(const proto_game::OnePaoMaDengInfo &notify) {
    m_notifyMgr.insert(std::make_pair(notify.win_jetton(), notify));
    if (m_notifyMgr.size() > 10)
    {
        m_notifyMgr.erase(m_notifyMgr.begin());
    }
    return 0;
}

void NFPaoMaDengMgr::OnTimer(uint32_t nTimerID)
{
    proto_game::Proto_SCPaoMaDengNotify notify;
    for(auto iter = m_notifyMgr.begin(); iter != m_notifyMgr.end(); iter++)
    {
        notify.add_info()->CopyFrom(iter->second);
    }

    if (notify.info_size() > 0)
    {
        NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_game::NF_SC_MSG_PaoMaDengNotify, notify, 0);
        m_notifyMgr.clear();
    }
    else
    {
        std::vector<NFGameRoom*> vec = NFGameRoomMgr::Instance()->GetAllRoom();
        for(int i = 0; i < (int)vec.size(); i++) //-V756
        {
            for(int j = 0; j < 10; j++)
            {
                proto_game::OnePaoMaDengInfo notify;
                notify.set_game_id(vec[i]->m_gameId);
                notify.set_game_name(vec[i]->m_gameName.GetString());
                notify.set_room_id(vec[i]->m_roomId);
                notify.set_room_name(vec[i]->m_roomName.GetString());
                notify.set_user_name(NFIPluginManager::Instance()->FindModule<NFICommLogicModule>()->GetRandomName());
                notify.set_win_jetton(NFRandInt(1000, 100000));
                AddPaoMaDeng(notify);
            }
        }
    }
}
