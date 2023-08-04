// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Module.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Module
//
// -------------------------------------------------------------------------

#include "NFGameFish2004Module.h"
#include "NFLogicCommon/NFIGameRoomModule.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "NFLogicCommon/NFIGameDeskImpl.h"

NFGameFish2004Module::NFGameFish2004Module(NFIPluginManager *p):NFFishDynamicModule(p)
{

}

NFGameFish2004Module::~NFGameFish2004Module()
{
}

bool NFGameFish2004Module::Awake()
{
    CreateDeskFunction createFunc = [](uint32_t gameId) -> NFIGameDeskImpl*
    {
        NF_ASSERT(gameId == GAME_ID_FISH_HAIWANG_2004);
        return NULL;
    };
    FindModule<NFIGameRoomModule>()->RegisterCreateDeskFunction(GAME_ID_FISH_HAIWANG_2004, createFunc);
    return true;
}


