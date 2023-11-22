// -------------------------------------------------------------------------
//    @FileName         :    NFEventDefine2.h
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFEventDefine2
//
// -------------------------------------------------------------------------

#pragma once

enum EventId2
{
    EVENT_NONE2 = 1000,
    EVENT_SYNC_SCENE_POS,               //场景位置同步
    EVENT_SYNC_SCENE_STATE,             //场景状态同步事件
    EVENT_SYNC_SCENE_FACADE,            //同步场景外观
    EVENT_SYNC_CREATURE_ATTR,           //生物属性同步
    EVENT_SYNC_CREATURE_BROADCAST_ATTR, //广播属性同步
    EVENT_SYNC_SNS_ATTR,                //广播属性同步
};
