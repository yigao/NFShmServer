require "Common"

AllMoreServer = {
    ServerList = {
        {Server="AllServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_MASTER_SERVER..".1"},
        {Server="LogicServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_LOGIC_SERVER..".2"},
        {Server="GameServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_GAME_SERVER..".2"},
        {Server="GameServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_GAME_SERVER..".3"},
        --{Server="CrossAllServer", ID=NF_ST_WORLD_ID.."."..NF_ST_CROSS_ZONE_ID.."."..NF_ST_MASTER_SERVER..".1"},
    };
}