--lua5.3 没有math.mod函数
function math.mod(a, b)
	a = tonumber(a)
	b = tonumber(b)
	return math.fmod(a,b)
end

g_platfrom = 'luaself'           --g_platfrom init for luaself

function md5(md5Str)
	return LuaNFrame.GetMD5(md5Str)
end

g_randomsee = 0
function math.myrandom(...)
	local arg = {...}
	if g_randomsee == 0 then
		math.newrandomseed()
		g_randomsee = 1
	end
	for i = 1, #arg do
		arg[i] = math.floor(arg[i])
	end

	return math.random(table.unpack(arg))
end

function Sha256(content)
	return LuaNFrame.Sha256(content)
end

function HttpPost(url,content)
	local str = LuaNFrame.HttpPost(url,content)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end

function HttpPostWithHead(url,content,head)
	local str = LuaNFrame.HttpPostWithHead(url,content,head)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end

function HttpGet(url)
	local str = LuaNFrame.HttpGet(url)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end

function HttpGetWithHead(url,head)
	local str LuaNFrame.HttpGetWithHead(url,head)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end