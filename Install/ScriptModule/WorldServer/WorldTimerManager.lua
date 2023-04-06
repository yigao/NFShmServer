module('timerManager', package.seeall)


function timerManager.Init()
	print("init end")
end

function timerManager:createOnceTimer(strIndex)
	return _G[strIndex]
end

function timerManager.UpdateSec()
	--LogFile("info",   "LuaNFrame.UpdateSec")
end

function timerManager.UpdateMin()
	--LogFile("info",   "LuaNFrame.UpdateMin")
end

function timerManager.Update5Min()
	--LogFile("info",   "LuaNFrame.Update5Min")
end

function timerManager.Update10Min()
	--LogFile("info",   "LuaNFrame.Update10Min")
end

function timerManager.Update30Min()
	--LogFile("info",   "LuaNFrame.Update30Min")
end

function timerManager.UpdateHour()
	--LogFile("info",   "LuaNFrame.UpdateHour")
end

function timerManager.UpdateDay()
	LogFile("info",   "LuaNFrame.UpdateDay")
end

function timerManager.UpdateWeek()
	LogFile("info",   "LuaNFrame.UpdateWeek")
end

function timerManager.UpdateMonth()
	LogFile("info",   "LuaNFrame.UpdateMonth")
end


