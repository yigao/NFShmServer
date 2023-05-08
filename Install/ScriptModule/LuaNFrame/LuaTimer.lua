--添加服务器秒定时器
function LuaNFrame.AddTimer(strLuaFunc, nInterValSec, nCallCount, dataStr)
	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
	end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
	end

    if nInterValSec == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nInterValSec Para Error")
		return
	end

    if nCallCount == nil then
		nCallCount = 0;
	elseif type(nCallCount) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nCallCount is not number")
		return
	end

	return CPPNFrame:AddTimer(strLuaFunc, nInterValSec*1000, nCallCount, dataStr)
end

--每嗝1毫秒的定时器示例, 300ms执行testtimer函数一次,总共执行5此
--LuaNFrame.addtimermsec("testtimer",300, 5)
function LuaNFrame.AddTimerMSec(strLuaFunc, nInterValMSec, nCallCount, dataStr)
	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
	end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
	end

	if type(nInterValMSec) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nInterValMSec Para Error")
		return
    end

	if nCallCount == nil then
		nCallCount = 0;
	elseif type(nCallCount) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nCallCount is not number")
		return
	end

	return CPPNFrame:AddTimer(strLuaFunc, nInterValMSec, nCallCount, dataStr)
end


--停止服务器定时器
function LuaNFrame.StopTimer(timer)
	if type(timer) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "StopTimer Para Error")
		return 
	end
	CPPNFrame:StopTimer(timer)
end

-- 关于闹钟实例：
--  原理解释：
	-- intervalSec 表示从1970年开始到现在，把所有的时间以intervalSec为单位划分用 “---”表示
	-- sec 表示，在intervalSec这个单位时间段内需要触发闹钟的时刻用"*"表示
	-- 所以要求sec < intervalSec
	-- 图示：1970开始｜-*---｜-*--｜-*--|.......|-*--|now
-- 实例：
-- （1）每隔物理10秒的第1秒时钟实例 ：LuaNFrame.addclocker("testclocker",1,10,0);
	--function testclocker(text,clocker)
	--	LuaNFrame.debug("testclocker:"..text)
	--  clocker.Stop()
	--end
--  (2) 每天上午8点触发闹钟实例：LuaNFrame.addclocker("OnClocker", 8*3600, 24*3600, 0 );
	--function OnClocker(text,clocker)
	--	LuaNFrame.debug("每日触发实列")
	--end
-- (3) 每周（7*24*3600）的第34个小时触发闹钟：LuaNFrame.addclocker("OnClocker", 34*3600, 7*24*3600, 0);
-- 
function LuaNFrame.AddClocker(luaFunc, sec, intervalSec, nCallCount, dataStr)
	if type(luaFunc) ~= "function" or type(sec) ~= "number" or type(intervalSec) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "AddClocker Para Error")
		return
    end

    if nCallCount == nil then
        nCallCount = 0;
	end
	
	if nCallCount == nil then
		nCallCount = 0;
	elseif type(nCallCount) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "AddClocker Para Error:nCallCount is not number")
		return
	end

	return CPPNFrame:AddClocker(luaFunc, sec, intervalSec, nCallCount, dataStr)
end

--执行定时函数
function LuaNFrame.DispatchTimer(timeId, luaFunc, strLuaFunc, callCount, dataStr)
	local function timerExecute()
		luaFunc(timeId, callCount, dataStr)
	end
	
	local status, msg = xpcall (timerExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.DispatchTimer error, strLuaFunc:"..strLuaFunc.." timeId:"..timeId.." callCount:"..callCount.." param:"..tostring(dataStr), msg)
    end
end



