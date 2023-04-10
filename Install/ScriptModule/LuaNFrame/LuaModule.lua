function register_module(tbl, name)
	local tmp = {tbl = tbl, tblName = name}
	table.insert(LuaNFrame.ScriptList, tmp)
	LuaNFrame.InfoWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "load module:" .. name)
end


--执行加载函数
function LuaNFrame.load_script_file(  )
    for i, fun in ipairs(LuaNFrame.LoadScriptList) do
        fun()
    end
end

function LuaNFrame.InsertLoadFunc(func)
	if type(func) == "function" then
    	table.insert(LuaNFrame.LoadScriptList, func)
	else
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "InsertLoadFunc failed")
	end
end

function LuaNFrame.Init()
	for i=1, #(LuaNFrame.ScriptList) do
		if ((LuaNFrame.ScriptList[i].tbl.Init) ~= nil) then
			LuaNFrame.ScriptList[i].tbl.Init();
		end
	end
end

function LuaNFrame.AfterInit()
	for i=1, #(LuaNFrame.ScriptList) do
		if (LuaNFrame.ScriptList[i].tbl.AfterInit ~= nil) then
			LuaNFrame.ScriptList[i].tbl.AfterInit();
		end
	end
end

function LuaNFrame.Execute()
	for i=1, #(LuaNFrame.ScriptList) do
		if ((LuaNFrame.ScriptList[i].tbl.Execute) ~= nil) then
			LuaNFrame.ScriptList[i].tbl.Execute();
		end
	end
end

function LuaNFrame.BeforeShut()
	for i=1, #(LuaNFrame.ScriptList) do
		if ((LuaNFrame.ScriptList[i].tbl.BeforeShut)~= nil) then
			LuaNFrame.ScriptList[i].tbl.BeforeShut();
		end
	end
end

function LuaNFrame.Shut()
	for i=1, #(LuaNFrame.ScriptList) do
		if ((LuaNFrame.ScriptList[i].tbl.Shut) ~= nil) then
			LuaNFrame.ScriptList[i].tbl.Shut();
		end
	end
end

--在主循环线程里执行，每一秒执行这个函数
function LuaNFrame.UpdateSec()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.UpdateSec) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.UpdateSec();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.UpdateSec error:", msg)
    end
end

--在主循环线程里执行，每一分钟的0秒执行这个函数
function LuaNFrame.UpdateMin()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.UpdateMin) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.UpdateMin();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.UpdateMin error:", msg)
    end
end

--在主循环线程里执行，每一分钟的0秒执行这个函数
function LuaNFrame.Update5Min()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.Update5Min) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.Update5Min();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.Update5Min error:", msg)
    end
end

--在主循环线程里执行，每一分钟的0秒执行这个函数
function LuaNFrame.Update10Min()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.Update10Min) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.Update10Min();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.Update10Min error:", msg)
    end
end

--在主循环线程里执行，每一分钟的0秒执行这个函数
function LuaNFrame.Update30Min()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.Update30Min) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.Update30Min();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.Update30Min error:", msg)
    end
end

---在主循环线程里执行，每一小时的0秒执行这个函数
function LuaNFrame.UpdateHour()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.UpdateHour) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.UpdateHour();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.UpdateHour error:", msg)
    end
end

---在主循环线程里执行，每一天的0秒执行这个函数
function LuaNFrame.UpdateDay()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.UpdateDay) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.UpdateDay();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.UpdateDay error:", msg)
    end
end

---在主循环线程里执行，每一周的0秒执行这个函数
function LuaNFrame.UpdateWeek()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.UpdateWeek) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.UpdateWeek();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.UpdateWeek error:", msg)
    end
end

---在主循环线程里执行，每一月的0秒执行这个函数
function LuaNFrame.UpdateMonth()
	local function timerfunc()
		for i=1, #(LuaNFrame.ScriptList) do
			if ((LuaNFrame.ScriptList[i].tbl.UpdateMonth) ~= nil) then
				LuaNFrame.ScriptList[i].tbl.UpdateMonth();
			end
		end
	end
	
	local status, msg = xpcall (timerfunc, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0,  "LuaNFrame.UpdateMonth error:", msg)
    end
end