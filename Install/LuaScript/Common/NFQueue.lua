LuaNFrame.Class("NFQueue")


-- 构造函数
function NFQueue:Ctor()
	-- body
	-- 元素列表
	self._list = {};
end

-- 添加一个元素
function NFQueue:Push(value)
	-- body
	if value ~= nil then
		--todo
        local nPos = #self._list + 1;
		table.insert(self._list, nPos, value);
	end
end

-- 弹出一个函数
function NFQueue:Pop()
	-- body
	if self:Count() <= 0 then
		--todo
		return nil;
	end

	local nValue = self._list[1];
	table.remove(self._list, 1);

	return nValue;
end

-- 删除对象
function NFQueue:Remove(value)
	-- body
	for i=1,self:Count() do
		local nValue = self._list[i];
		if v == value then
			--todo
			table.remove(self._list, i);
			i = i - 1;
		end
	end
end

-- 数量
function NFQueue:Count()
	-- body
	return #self._list;
end

-- 清除
function NFQueue:Clear()
	-- body
	self._list={};
end
