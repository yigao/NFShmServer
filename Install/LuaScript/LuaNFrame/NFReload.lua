NFLuaReload = NFLuaReload or {}

NFLuaReload.hotfix = require("Hotfix/hotfix")

-- global_objects which must not hotfix.
NFLuaReload.global_objects = {
    arg,
    assert,
    bit32,
    collectgarbage,
    coroutine,
    debug,
    dofile,
    error,
    getmetatable,
    io,
    ipairs,
    load,
    loadfile,
    loadstring,
    math,
    module,
    next,
    os,
    package,
    pairs,
    pcall,
    print,
    rawequal,
    rawget,
    rawlen,
    rawset,
    require,
    select,
    setmetatable,
    string,
    table,
    tonumber,
    tostring,
    type,
    unpack,
    utf8,
    xpcall,
}

function hotfix_log_debug(strMsg)
    LuaNFrame.Debug(NFLogId.NF_LOG_SYSTEMLOG, 0, tostring(strMsg))
end

function hotfix_log_error(strMsg)
    LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, tostring(strMsg))
end

function hotfix_log_info(strMsg)
    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, tostring(strMsg))
end

function NFLuaReload.Init()
    --hotfix.log_debug = function(s) print(s) end

    --NFLuaReload.hotfix.log_debug = hotfix_log_debug
    NFLuaReload.hotfix.log_error = hotfix_log_error
    --NFLuaReload.hotfix.log_info = hotfix_log_info
    NFLuaReload.hotfix.add_protect(NFLuaReload.global_objects)
    NFLuaReload.uptick = 0;
    -- Map file path to file time to detect modification.
    NFLuaReload.path_to_time = { };
end

--- Check modules and hotfix.
function NFLuaReload.Execute()
    local function ReloadExecute()
        local MOD_NAME = "hotfix_module_names"
        if not package.searchpath(MOD_NAME, package.path) then return end
        package.loaded[MOD_NAME] = nil  -- always reload it
        local module_names = require(MOD_NAME)

        for _, module_name in pairs(module_names) do
            NFLuaReload.ReloadNewFile(module_name)
        end  -- for
	end
	
	local status, msg = xpcall (ReloadExecute, __G__TRACKBACK__)

    if not status then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, msg)
    end
end  -- check()

--重新加载所有LUA文件
function NFLuaReload.ReloadAll()
    local modifyFiles = {}
    local function ReloadExecute()
        local change = false
        for file_path, value in pairs(package.loaded) do
            if type(file_path) == "string" and type(value) == "boolean" and  value == true then
                if NFLuaReload.ReloadNewFile(file_path) == true then
                    change = true
                    table.insert(modifyFiles, file_path)
                end
            end
        end
	end
    
    local status, msg = xpcall (ReloadExecute, __G__TRACKBACK__)

    if not status then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, msg)
        return modifyFiles
    end

    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "Reload All Modified Lua File Success")
    return modifyFiles
end

function NFLuaReload.RecordAllFilesTimes()
    local function ReloadExecute()
        for file_path, value in pairs(package.loaded) do
            if type(file_path) == "string" and type(value) == "boolean" and  value == true then
                local path, err = package.searchpath(file_path, package.path)
                -- Skip non-exist module.
                if path and string.find(path, "LuaScript") then
                    local file_time = lfs.attributes (path, "modification")
                    NFLuaReload.path_to_time[path] = file_time
                end
            end
        end
	end
	
	local status, msg = xpcall (ReloadExecute, __G__TRACKBACK__)

    if not status then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, msg)
    end
end

function NFLuaReload.ReloadNewFile(file_path)
    if type(file_path) == "string" then
        local path, err = package.searchpath(file_path, package.path)
        -- Skip non-exist module.
        if path and string.find(path, "LuaScript") then
            local file_time = lfs.attributes (path, "modification")
            --local file_time = Misc.GetFileModificationDate(path)
            if file_time ~= NFLuaReload.path_to_time[path] then
                NFLuaReload.path_to_time[path] = file_time
                if not package.loaded[file_path] then
                    require(file_path)
                else
                    NFLuaReload.hotfix.hotfix_module(file_path)
                end
                
                LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "Hotfix Lua File:{} Success", file_path)
                return true
            end
        else
            if type(err) ~= nil then
                LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, "Hotfix Lua File:{} Failed err:{} ", file_path, err)
            else
                LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, "Hotfix Lua File:{} Failed", file_path)
            end
        end
    end

    return false
end

function NFLuaReload.ReloadFile(modifyfiles)
    local function ReloadExecute()
        if modifyfiles == nil then
            local MOD_NAME = "hotfix_module_names"
            if not package.searchpath(MOD_NAME, package.path) then return end
            package.loaded[MOD_NAME] = nil  -- always reload it
            local module_names = require(MOD_NAME)

            for _, module_name in pairs(module_names) do
                NFLuaReload.ReloadNewFile(module_name)
            end  -- for
        elseif type(modifyfiles) == "table" then
            for _, file_path in ipairs(modifyfiles) do
                NFLuaReload.ReloadNewFile(file_path)
            end
        end
	end
	
	local status, msg = xpcall (ReloadExecute, __G__TRACKBACK__)

    if not status then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, msg)
    end
end