LuaNFrame = LuaNFrame or {}
LuaNFrame.protobuf_enum = LuaNFrame.protobuf_enum or {}
LuaNFrame.protobuf_class = LuaNFrame.protobuf_class or {}

LuaNFrame.pb     = require "pb"
LuaNFrame.pb_io   = require "pb_io"
LuaNFrame.pb_buffer = require "pb_buffer"
LuaNFrame.pb_slice  = require "pb_slice"
LuaNFrame.pb_conv   = require "pb_conv"
LuaNFrame.protoc = require "protoc"
LuaNFrame.serpent = require "serpent"

function LuaNFrame.CreatePb(protoPackageName)
    _G[protoPackageName] = _G[protoPackageName] or {}
end

function LuaNFrame.PbClass(protoName, className)
    return LuaNFrame.CreatePbClass(proto_ff, protoName, className)
end

function LuaNFrame.CreatePbClass(pbTable, protoName, className)
    if pbTable[className] ~= nil then
		NFLogError(NF_LOG_SYSTEMLOG, 0, "CreatePbClass被意外全局初始化,这里强制重置成类:"..className)
		return nil
	end

    local cls = {}

    cls.Ctor    = function() end
    cls.ParseFromString = function(self, dataPackage)
        local result = type(dataPackage)
        if result == "userdata" then
            local data = LuaNFrame.Decode(self.__pbName, dataPackage:GetData())
            if data == nil then
                LuaNFrame.ErrorWithThread(NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.DecodePackage Fail,  package:"..dataPackage:ToString())
            else
                LuaNFrame.TraceWithThread(NF_LOG_SYSTEMLOG, 0, 3,  LuaNFrame.serpent.block(data))
            end
            return data
        else
            data = LuaNFrame.Decode(self.__pbName, dataPackage)
            if data == nil then
                LuaNFrame.ErrorWithThread(NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.DecodePackage Fail,  package:"..dataPackage:ToString())
            else
                LuaNFrame.TraceWithThread(NF_LOG_SYSTEMLOG, 0, 3,  LuaNFrame.serpent.block(data))
            end
            return data
        end
    end
    cls.SerializeToString = function(self)
        return LuaNFrame.Encode(self.__pbName, self)
    end
    cls.GetTypeName = function(self)
        return self.__pbName
    end
    cls.__cname = className
    cls.__pbName = protoName
    cls.__ctype = 2 -- lua
    cls.__index = cls

    function cls.New(dataPackage)
        if dataPackage ~= nil then
            local data = cls:ParseFromString(dataPackage)
            local instance = setmetatable(data, cls)
            instance.class = cls
            instance:Ctor()
            return instance
        else            
            local data = LuaNFrame.Defaults(cls.__pbName)
            local instance = setmetatable(data, cls)
            instance.class = cls
            instance:Ctor()
            return instance
        end
    end

    pbTable[className] = cls
    return cls
end

function LuaNFrame.LoadProto(proto)
    LuaNFrame.protoc:load(proto)
end

function LuaNFrame.LoadProtoFile(proto)
    LuaNFrame.protoc:loadfile(proto)
end

function LuaNFrame.AddPath(path)
    LuaNFrame.protoc:addpath(path)
end

function LuaNFrame.Enum(type, value)
    return LuaNFrame.pb.enum(type, value)
end

 -- 载入刚才编译的pb文件
function LuaNFrame.LoadPbFile(pbPckageName, pbfile)
    LuaNFrame.CreatePb(pbPckageName)
    local proto_ff = _G[pbPckageName]
    if type(pbfile) ~= "string" then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.LoadPbFile Failed, param pbfile is not string, can't load")
        assert(false)
    end

    local result = LuaNFrame.pb.loadfile(pbfile)
    if result == nil or result == false then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.LoadPbFile Failed, can 't load file fail:"..pbfile)
        assert(false)
    end

    for proto_name, base_name, type_name in LuaNFrame.pb.types() do
        if type_name == "enum" then
            for enum_name, enum_number, enum_type in LuaNFrame.pb.fields(proto_name) do
                if proto_ff[enum_name] ~= nil then
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "proto the key:{} has exist, maybe the enum, message is same name", enum_name)
                end
                proto_ff[enum_name] = enum_number
            end
        else 
            if proto_ff[base_name] ~= nil then
                NFLogError(NF_LOG_SYSTEMLOG, 0, "proto the key:{} has exist, maybe the enum, message is same name", proto_name)
            end
            LuaNFrame.protobuf_class[proto_name] = LuaNFrame.PbClass(proto_name, base_name)
        end
    end
end

function LuaNFrame.Decode(msgtype, msgdata_buffer)
    return LuaNFrame.pb.decode(msgtype, msgdata_buffer)
end

function LuaNFrame.DecodePackage(msgtype,  dataPackage)
    if type(msgtype) ~= "string" then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "msgtype param is not string")
        return nil
    end

    local result = type(dataPackage)
    if result ~= "userdata" then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "dataPackage param is not string")
        return nil
    end

    local data = LuaNFrame.Decode(msgtype, dataPackage:GetData())
    if data == nil then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.DecodePackage Fail,  package:"..dataPackage:ToString())
    else
        LuaNFrame.TraceWithThread(NF_LOG_SYSTEMLOG, 0, 3,  LuaNFrame.serpent.block(data))
    end
    return data
end

function LuaNFrame.Encode(msgtype, msgdata)
    return LuaNFrame.pb.encode(msgtype, msgdata)
end

function LuaNFrame.Defaults(msgtype)
    local msg_proto_type, basename, type_name = LuaNFrame.pb.type(msgtype)
    if type_name == "enum" then
        return pb.enum(msgtype, 0)
    elseif type_name == "map" then
        return {}
    end

    local data = LuaNFrame.pb.defaults(msgtype)
    for name, number, type, defaultValue, fieldlabel in LuaNFrame.pb.fields(msgtype) do
        if type == msgtype then --无线迭代或enum
            if data[name] == nil then
                data[name] = 0
            end
            break
        end
        if fieldlabel == "repeated" then
            if data[name] == nil then
                data[name] = {}
            end
        else
            if type == "string" or type == "bytes" then
                if data[name] == nil then
                    data[name] = ""
                end
            elseif type == "int32" or  type == "uint32" or type == "sint32" or type == "fixed32" or type == "sfixed32"
                or type == "int64" or type == "uint64" or type == "sint64" or type == "fixed64" or type == "sfixed64"
                or type == "double" or type == "float" then
                if data[name] == nil then
                    data[name] = 0
                end
            elseif type == "bool" then
                if data[name] == nil then
                    data[name] = false
                end
            else
                if data[name] == nil then
                    data[name] = LuaNFrame.Defaults(type)
                end
            end
        end
      end

      data.__cname = msgtype
    return data
end

function LuaNFrame.PrintProto(msgdata)
    LuaNFrame.InfoWithThread(NF_LOG_SYSTEMLOG, 0, 3,  LuaNFrame.serpent.block(msgdata))
end
