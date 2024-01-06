LuaNFrame.Class("NFMap")

function NFMap:Ctor()
	self.map = {}
    self.count = 0
end


-- Map 插入新值
function NFMap:Insert(k,v)
    if nil == self.map[k] then
        self.map[k] = v
        self.count = self.count + 1
    end
end

-- Map 插入新值并且切换旧值
function NFMap:Replace(k,v)
	if nil == self.map[k] then
		self.map[k] = v;
		self.count = self.count + 1;
	else
		self.map[k] = v;
	end
end

function NFMap:Remove(k)
    if nil ~= self.map[k] then
        self.map[k] = nil
        if self.count >0 then
            self.count = self.count - 1
        end
    end
end

function NFMap:ForEachRemove(field, value)

    local newT = {} 
    
	for k,v in pairs(self.map) do
        if v[field]~=value then
            newT[k] = v;
        end
    end 
    
    self.map = newT;
end

function NFMap:Find(k)
    return self.map[k]
end

function NFMap:Clear()
    self.map = {};
    self.count = 0
end


-- 遍历所有成员
function NFMap:ForEach(fun, ...)
	-- body
	for k,v in pairs(self.map) do
		fun(k, v, ...)
	end
end

-- Map 获取字典的count
function NFMap:Count()
	return self.count;
end

