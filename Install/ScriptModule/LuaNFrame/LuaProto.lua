LuaNFrame = LuaNFrame or {}

LuaNFrame.pb     = require "pb"
LuaNFrame.pb_io   = require "pb_io"
LuaNFrame.pb_buffer = require "pb_buffer"
LuaNFrame.pb_slice  = require "pb_slice"
LuaNFrame.pb_conv   = require "pb_conv"
LuaNFrame.protoc = require "protoc"
LuaNFrame.serpent = require "serpent"

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

function LuaNFrame.TransPbEnum(typeStr, maxValue)
	if type(typeStr) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "typeStr Para Error, not string")
		return
    end

	if type(maxValue) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "maxValue Para Error, not number")
		return
    end

	for i=1,  maxValue do
		local msgIdStr = LuaNFrame.Enum(typeStr, i)
		if msgIdStr ~= nil then
			_G[msgIdStr] = i
		end
	end
end

 -- 载入刚才编译的pb文件
function LuaNFrame.LoadPbFile(pbfile)
    if type(pbfile) ~= "string" then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.LoadPbFile Failed, param pbfile is not string, can't load")
        assert(false)
    end

    local result = LuaNFrame.pb.loadfile(pbfile)
    if result == nil or result == false then
        LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0,  3, "LuaNFrame.LoadPbFile Failed, can 't load file fail:"..pbfile)
        assert(false)
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
    data.__cname = msgtype
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
