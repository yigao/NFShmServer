
TimeUtils = {}


--function: 获取秒数
--input   : table的时间类型：local tab = {year=2005, month=11, day=6, hour=22,min=18,sec=30,isdst=false}
--output  : 整形时间戳
function TimeUtils.GetTime(t)
	local tab = {}
    if type(t) == "string" then
        if _VERSION == "Lua 5.1" then
            tab.year = string.sub(t, 1, 4)
            tab.month = string.sub(t, 6, 7)
            tab.day = string.sub(t, 9, 10)
            tab.hour = string.sub(t, 12, 13)
            tab.min = string.sub(t, 15, 16)
            tab.sec = string.sub(t, 18, 19)
            tab.isdst = false
        else
            tab.year = tonumber(string.sub(t, 1, 4))
            tab.month =  tonumber(string.sub(t, 6, 7))
            tab.day =  tonumber(string.sub(t, 9, 10))
            tab.hour =   tonumber(string.sub(t, 12, 13))
            tab.min =  tonumber(string.sub(t, 15, 16))
            tab.sec =   tonumber(string.sub(t, 18, 19))
            tab.isdst = false
        end
	elseif type(t) == "number" then
		return t
	else
		tab = t
	end

	return os.time(tab)
end

--获取当前毫秒时间，没有参数
function TimeUtils.GetMescTime()
	return socket.gettime()
end


--function: 获取整天秒数
--input   : table的时间类型：local tab = {year=2005, month=11, day=6, hour=22,min=18,sec=30,isdst=false}
--output  : 整形时间戳
function TimeUtils.GetTimeDay(t)
	local tab = {}
	if type(t) == "string" then
        if _VERSION == "Lua 5.1" then
            tab.year = string.sub(t, 1, 4)
            tab.month = string.sub(t, 6, 7)
            tab.day = string.sub(t, 9, 10)
            tab.hour = string.sub(t, 12, 13)
            tab.min = string.sub(t, 15, 16)
            tab.sec = string.sub(t, 18, 19)
            tab.isdst = false
        else
            tab.year = tonumber(string.sub(t, 1, 4))
            tab.month =  tonumber(string.sub(t, 6, 7))
            tab.day =  tonumber(string.sub(t, 9, 10))
            tab.hour =   tonumber(string.sub(t, 12, 13))
            tab.min =  tonumber(string.sub(t, 15, 16))
            tab.sec =   tonumber(string.sub(t, 18, 19))
            tab.isdst = false
        end
	elseif type(t) == "table" then
		tab = t
	else
		tab = os.date("*t", t)
	end

	tab.hour = 0
	tab.min = 0
	tab.sec = 0

	return os.time(tab)
end


--function: 获取一天中过的秒数
--input   : table的时间类型：local tab = {year=2005, month=11, day=6, hour=22,min=18,sec=30,isdst=false}
--output  : 整形时间戳
function TimeUtils.GetDayCurrSec(t)
	local tab = {}
	if type(t) == "string" then
        if _VERSION == "Lua 5.1" then
            tab.year = string.sub(t, 1, 4)
            tab.month = string.sub(t, 6, 7)
            tab.day = string.sub(t, 9, 10)
            tab.hour = string.sub(t, 12, 13)
            tab.min = string.sub(t, 15, 16)
            tab.sec = string.sub(t, 18, 19)
            tab.isdst = false
        else
            tab.year = tonumber(string.sub(t, 1, 4))
            tab.month =  tonumber(string.sub(t, 6, 7))
            tab.day =  tonumber(string.sub(t, 9, 10))
            tab.hour =   tonumber(string.sub(t, 12, 13))
            tab.min =  tonumber(string.sub(t, 15, 16))
            tab.sec =   tonumber(string.sub(t, 18, 19))
            tab.isdst = false
        end
	elseif type(t) == "table" then
		tab = t
	else
		tab = os.date("*t", t)
	end

	return tab.hour*3600 + tab.min*60 + tab.sec
	
end

--function: 获取table时间类型
--input   : 整形时间戳或者字符串时间类型
--output  : table时间类型
function TimeUtils.GetTableTime(t)

	if type(t) == "number" then
		return os.date("*t", t)
	elseif type(t) == "string" then		
		local t_time = TimeUtils.GetTime(t)
		return os.date("*t", t_time)
	else
		return os.date("*t")
	end
end

--function: 获取当前时间戳是在当天的第几分钟
--input   : 整形时间戳或者table时间类型
--output  : 字符串时间类型 2016-05-12 21:03:15

function TimeUtils.GetDayMinutes(t)
	if type(t) ~= "table" then
		t = TimeUtils.GetTableTime(t)
	end
	return t.hour*60 + t.min
end

--function: 获取详细的字符串时间格式
--input   : 整形时间戳或者table时间类型
--output  : 字符串时间类型 2016-05-12 21:03:15
function TimeUtils.GetTimeString(t)
	if type(t) == "table" then
		t = os.time(t)
	end 
	return os.date("%Y-%m-%d %H:%M:%S", t)
end


--function: 获取详细的字符串时间格式
--input   : 整形时间戳或者table时间类型
--output  : 字符串时间类型 2016-05-12 21:03:15
function TimeUtils.GetTimeStringSpe(t)
	if type(t) ~= "table" then
		t = TimeUtils.GetTableTime(t)
	end 
	return t.year..t.month..t.day..t.hour..t.min..t.sec
end

--function: 获取精确到日的时间字符串
--input   : table 时间格式 或者 整形时间格式
--output  : 2016-05-12
function TimeUtils.GetDayString(t)

	if type(t) == "table" then
		t = os.time(t)
	end
	return os.date("%Y-%m-%d",t)
end

--fuction: 取得两个时间间隔，精确到秒
--input  : table 时间格式，整形时间格式，字符串时间格式
--output : 相隔的秒数
function TimeUtils.DifferentTime(tstart, tend)

	if tstart == nil then
		tstart = TimeUtils.GetTableTime()
	end

	if tend == nil then
		tend = TimeUtils.GetTableTime()
	end

	tstart = clone(tstart)
	tend = clone(tend)
	--先转换成table类型，把时分秒的字段置为0，然后在比较
	if type(tstart) ~= "number" then
		tstart = TimeUtils.GetTime(tstart)
	end

	if type(tend) ~= "number" then
		tend = TimeUtils.GetTime(tend)
	end
	return os.difftime(tend, tstart)
end

--fuction: 取得两个时间间隔，精确到天
--input  :table 时间格式，整形时间格式，字符串时间格式
--output :相隔的天数
function TimeUtils.DifferentDay(tstart, tend)

	if tstart == nil then
		tstart = TimeUtils.GetTableTime()
	end

	if tend == nil then
		tend = TimeUtils.GetTableTime()
	end
	
	tstart = clone(tstart)
	tend = clone(tend)
	--先转换成table类型，把时分秒的字段置为0，然后在比较

	if type(tstart) ~= "table" then
		tstart = TimeUtils.GetTableTime(tstart)
	end

	if type(tend) ~= "table" then
		tend = TimeUtils.GetTableTime(tend)
	end

	tstart.hour = 0
	tstart.min = 0
	tstart.sec = 0


	tend.hour = 0
	tend.min = 0
	tend.sec = 0

	tstart = TimeUtils.GetTime(tstart)
	tend = TimeUtils.GetTime(tend)

	return math.modf(os.difftime(tend, tstart)/86400)
end


--function： 获取这个月有几天
--input： table时间，int时间，string时间
--output: 对应月份的数量

function TimeUtils.GetMonthDay(t)

	t = TimeUtils.GetTableTime(t)

	if t.month % 2 == 1 then
		return 31
	elseif t.month == 2 then

		if t.year % 4 == 0 then
			return 29
		else
			return 28
		end
	else
		return 30
	end

end