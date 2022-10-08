--[[
    实现重载lua文件  cocos2dx 实现
    目的:减少重启游戏,节约开发时间
    注意该功能不是能完全代替重启
    不能替换的 如 cocos 中
    function handler(obj, method)
        return function(...)
            return method(obj, ...)
        end
    end
    由于保存了 method  每次调用都用 method 进行调用,及时源文件中已经将 method 实现进行了替换  但这里的
    method 任然是原始的,这种情况 一般进行界面关闭重新打开就可以使用替换后的方法

    注意:由于各个项目中有不同的实现,这里兼容的是cocos 中原版,如果项目中自己修改过那么需要自己了解.
    该功能本来是想单独开项目进行付费使用,现在将该功能集成到luaide 中了,属于免费给大家用.所以使用过程中
    遇到什么问题,先自己研究.不要一上来就问作者.代码不难理解.注释已经写的很详细了.
    如果你不愿意花精力去看那么你用两种选择:
    1. 不使用该功能.
    2. 找作者进行定制(尽量自己研究.)
    author:k0204
    time:2018-11-17 01:08:22
]]
--@endregion
--修改子类
--@region 重新加载代码文件
--@region class

print("ReLoadFile默认关闭,如果您是cocos程序或您自己修改过luaideReLoadFile文件请将isReLoad修改为true")
local isReLoad = true
if (isReLoad) then
    --替代子类中的实现
    local debugger_changeSubclass = nil
    --子类信息缓存 这里是弱引用 __mode = "kv"
    local subClassInfos = {}
    --实例缓存集合 这里是弱引用 __mode = "kv"
    local classInstanceInfos = {}
    --记录cocos 中的class
    local debugger_classFun = class
    --重写class
    class = function(className, super, ...)
        local cls = debugger_classFun(className, super, ...)
        local superType = type(super)
        --function 或有 super 并且ctype == 1  这是 cocos 的 class 机制
        if (cls.__ctype == 1 and (superType == "table" or superType == "function")) then
            if (superType == "table") then
                local super = cls.super
                local clss = subClassInfos[super]
                if (not clss) then
                    clss = {}
                    subClassInfos[super] = clss
                    setmetatable(clss, {__mode = "kv"})
                end
                table.insert(clss, cls)
            end
            --重写 .new
            if (cls.new) then
                local clsNew = cls.new
                cls.new = function(...)
                    local instance = clsNew(...)
                    --获取实例集合
                    local instances = classInstanceInfos[cls]
                    if (not instances) then
                        instances = {}
                        -- 创建实例集合
                        setmetatable(instances, {__mode = "kv"})
                        classInstanceInfos[cls] = instances
                    end
                    -- 记录实例
                    table.insert(instances, instance)
                    return instance
                end
            end
        end
        return cls
    end

    debugger_changeSubclass = function(classInfo, newClassInfo)
        --检查子类 clss 实例集合
        local clss = subClassInfos[classInfo]
        --替换子类的方法
        if (clss) then
            --cls 实例
            for _, cls in ipairs(clss) do
                debugger_changeSubclass(cls, newClassInfo)
                for funName, funValue in pairs(newClassInfo) do
                    local classFun = classInfo[funName]
                    local newClassFun = newClassInfo[funName]
                    local clsFun = cls[funName]
                    local ctype = type(clsFun)
                    local isChange = false
                    if (ctype == "function") then
                        if (classFun == nil) then
                            isChange = true
                        elseif (classFun == clsFun) then
                            isChange = true
                        end
                    end
                    if (isChange) then
                        cls[funName] = newClassFun
                    end
                end
            end
        end
        --检查实例
        local instances = classInstanceInfos[classInfo]
        if (instances) then
            for i, ins in ipairs(instances) do
                for k, v in pairs(newClassInfo) do
                    local ctype = type(v)
                    if (ctype == "function") then
                        ins[k] = v
                    end
                end
            end
        end
        for funName, fun in pairs(newClassInfo) do
            classInfo[funName] = fun
        end
    end

    local function debugger_reLoadFile(data)
        local newValue = nil
        local chunkName = data.chunkName
        print("重载脚本1:", chunkName)
        local loaded = package.loaded[chunkName]
        if (not loaded) then
            print("程序中未加载脚本,不进行处理.")
            return
        end
        local function loadScript()
            local fun = loadstring(data.script, chunkName)
            local currentTabble = {}
            newValue = fun()
        end

        local status, msg =
            xpcall(
            loadScript,
            function(error)
                print("重载代码错误:", error)
            end
        )
        local loadeType = type(loaded)
        if (loadeType == "table") then
            if (status) then
                --检查是否存在
                local oldValue = package.loaded[chunkName]

                if (oldValue) then
                    --判断类型
                    local oldValueType = type(oldValue)
                    local newValueType = type(newValue)
                    if ((oldValueType == "table" or oldValueType == "userdata") and (newValueType == "table" or newValueType == "userdata")) then
                        if (newValue.__ctype and newValue.__ctype == 1) then
                            debugger_changeSubclass(oldValue, newValue)
                        else
                            for funName, fun in pairs(newValue) do
                                oldValue[funName] = fun
                            end
                            local newMeta = getmetatable(newValue)
                            setmetatable(oldValue, newMeta)
                        end
                    end
                end
                package.loaded[chunkName] = oldValue
                return true
            else
                return false
            end
        else
        end
    end
    return debugger_reLoadFile
end
--@endregion
