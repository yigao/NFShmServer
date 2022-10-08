function decode_repair(t)
	local ret = {}
	if t == nil then
		return ret
	end
	for k,v in pairs(t) do
		if type(v) == "function" then
			v = nil
		elseif type(v) == "table" then
			v = decode_repair(v)
		end
		if type(k) == "string" then
			local n = tonumber(k)
			if n ~= nil and tostring(n) == k then
				k = n
			end
		end
		ret[k] = v
	end
	return ret
end

--其他语言返回回来的null无法识别,需要处理
function null_repair(t)
	if t == nil then
		return nil
	end
	local ret = {}
	for k,v in pairs(t) do
		local vret = v
		if type(v) == "userdata" then
			vret = nil
		elseif type(v) == "table" then
			vret = null_repair(v)
		end
		ret[k] = vret
	end
	return ret
end
--把table的数字索引通通改成字串索引，用于转成json串，以免转json串时变成数组
--这个接口不会影响原始table
function encode_repair(t)
	if t == nil then
		return nil
	end
	local ret = {}
	for k,v in pairs(t) do
		local vret = v
		if type(v) == "function" then
			vret = nil
		elseif type(v) == "table" then
			vret = encode_repair(v)
		end
		if type(k) == "number" then
			k = tostring(k)
		end
		ret[k] = vret
	end
	return ret
end

function json2table(js)
	return decode_repair(json.decode(js))
end

function table2json(tbl)
	return json.encode(encode_repair(tbl))
end
