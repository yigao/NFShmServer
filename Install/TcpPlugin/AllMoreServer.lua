require "Common"

AllMoreServer = {
    ServerList = {
        {Server="AllServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_MASTER_SERVER..".1"},
        {Server="ProxyServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_PROXY_SERVER..".2"},
    };
}