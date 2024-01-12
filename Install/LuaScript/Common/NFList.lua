LuaNFrame.Class("NFList")

-- 构造函数
function NFList:Ctor()
	-- body
	-- 元素列表
    self._list = {};
--    nlinfo(self._list);
end



-- 添加一个元素
function NFList:Push(value)
	-- body

	table.insert(self._list, value);
end

-- 插入一个元素
function NFList:Insert(idx, value)
	table.insert(self._list, idx, value);
end

-- 获取一个元素
function NFList:Get(index)
	-- body

	if self:Count() <= 0 or index == nil or type(index) ~= "number" then
		return nil;
	end

	return self._list[index];
end

-- 获取最后一个元素
function NFList:GetLast()
	return self:Get(self:Count());
end

-- 获取第一个元素
function NFList:GetFirst()
	return self:Get(1);
end

-- 删除对象
function NFList:Remove(value)
	if value == nil then
		return
	end
	-- body
	for i=1,self:Count() do
		local nValue = self._list[i];
		if nValue == value then
			--todo
			table.remove(self._list, i);
			i = i - 1;
		end
	end
end


--删除单个对象
function NFList:RemoveOne(value)
	if value == nil then
		return
	end
	for i=1,self:Count() do
		local nValue = self._list[i];
		if nValue == value then
			--todo
			table.remove(self._list, i);
			break;
		end
	end
end

-- 根据索引删除对象
function NFList:RemoveByIndex(idx)
	if (idx < 1 or idx > self:Count()) then
		return;
	end
	
	table.remove(self._list, idx);
end

-- 自定义函数删除
-- 注意会把nil一起删除掉，如果不需要可以改下
function NFList:RemoveIf(fun, ...)
	local m = 1;
	while m <= self:Count() do
		local nValue = self._list[m];
		if (nil ~= nValue) then
			if fun(nValue, ...) then
				table.remove(self._list, m);
			else
				m = m + 1;
			end
		else
			table.remove(self._list, m);
		end
	end
end

-- 删除所有对象
function NFList:RemoveAll(Value)
	local m = 1;
	while m <= self:Count() do
		local nValue = self._list[m];
		if (nValue == Value) then
			table.remove(self._list, m);
		else
			m = m + 1;
		end
	end
end

-- 是否有某个元素
function NFList:Contain(value)
	for i=1,self:Count() do
		local nValue = self._list[i];
		if nValue == value then
			return true;
		end
	end
	
	return false;
end

-- 替换列表中的元素
-- 下标为空替换失败
function NFList:ReplaceValue( index , value )
	local nValue = self._list[index];
	if  nil ~= nValue then
		self._list[index] = value;
	end 
end

--获取列表中元素的个数
function NFList:GetValueCount(value)
	local Count = 0;
	for i=1,self:Count() do
		local nValue = self._list[i];
		if nValue == value then
			Count = Count + 1;
		end
	end
	return Count;
end

-- 获取元素的索引
-- 找不到返回-1
function NFList:IndexOf(value)
	for i = 1,self:Count() do
		local nValue = self._list[i];
		if nValue == value then
			return i;
		end
	end
	
	return -1;
end

-- 遍历所有成员
function NFList:ForEach(fun, ...)
	-- body
	for k,v in pairs(self._list) do
		fun(v, ...)
	end
end

-- 数量
function NFList:Count()
	-- body
	return #self._list;
end

-- 克隆一个
function NFList:Clone()
	local t = NFList.New()

	for i, v in pairs(self._list)  do
		t:Push(v)
	end

	return t
end

-- list赋值
function NFList:Assign(InList)
	self._list = {};
	for i = 1, InList:Count() do
		self._list[i] = InList:Get(i);
	end
end

-- 追加
function NFList:Append(InList)
	local CurCount = self:Count();
	for i = 1, InList:Count() do
		self._list[i + CurCount] = InList:Get(i);
	end
end

-- 清除
function NFList:Clear()
	-- body
	self._list={};
end

-- 排序
function NFList:Sort( Action )
	table.sort( self._list, Action );
end


-- 反序
function NFList:Reverse()
	local TmpTab = {};
	local k = 1;
	for i = #self._list, 1, -1 do
		TmpTab[k] = self._list[i];
		k = k + 1;
	end
	for i = 1, #TmpTab do
		self._list[i] = TmpTab[i];
	end
	TmpTab = nil;
end

-- 求包含的元素个数
function NFList:NumsOf(inValue)
	local Nums = 0;
	for i = 1,self:Count() do
		local nValue = self._list[i];
		if nValue == inValue then
			Nums = Nums + 1;
		end
	end
	
	return Nums;
end

-- 返回符合条件的项
function NFList:GetIf(fun, ...)
	for i = 1, self:Count() do
		local Value = self:Get(i);
		if (nil ~= Value) then
			if fun(Value, ...) then
				return Value;
			end
		end
	end
	
	return nil;
end

-- 返回符合条件项的数量
function NFList:NumsIf(fun, ...)
	local Nums = 0;
	for i = 1, self:Count() do
		local Value = self:Get(i);
		if (nil ~= Value) then
			if fun(Value, ...) then
				Nums = Nums + 1;
			end
		end
	end
	
	return Nums;
end

-- 返回所有符合条件的所有项
function NFList:GetIfAll(fun, ...)
	local ret = {};
	for i = 1, self:Count() do
		local Value = self:Get(i);
		if (nil ~= Value) then
			if fun(Value, ...) then
				table.insert(ret, Value);
			end
		end
	end
	
	return ret;
end