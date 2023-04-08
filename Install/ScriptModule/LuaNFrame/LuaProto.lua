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

 -- 载入刚才编译的pb文件
function LuaNFrame.LoadPbFile(pbfile)
    if type(pbfile) ~= "string" then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "LuaNFrame.LoadPbFile Failed, param pbfile is not string, can't load")
        assert(false)
    end

    local result = LuaNFrame.pb.loadfile(pbfile)
    if result == nil or result == false then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "LuaNFrame.LoadPbFile Failed, can 't load file fail:"..pbfile)
        assert(false)
    end
end

function LuaNFrame.Decode(msgtype, msgdata_buffer)
    if type(msgtype) ~= "string" then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "msgtype param is not string")
        return nil
    end

    if type(msgdata_buffer) ~= "string" then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "msgdata_buffer param is not string")
        return nil
    end

    return LuaNFrame.pb.decode(msgtype, msgdata_buffer)
end

function LuaNFrame.DecodePackage(msgtype,  dataPackage)
    local data = LuaNFrame.Decode(msgtype, dataPackage:GetData())
    if data == nil then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "LuaNFrame.DecodePackage Fail,  package:"..dataPackage:ToString())
    else
        LuaNFrame.Debug(NF_LOG_SYSTEMLOG, 0, LuaNFrame.serpent.block(ata))
    end
    return data
end

function LuaNFrame.Encode(msgtype, msgdata)
    if type(msgtype) ~= "string" then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "msgtype param is not string")
        return nil
    end

    if type(msgdata) ~= "string" then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0,  "msgdata param is not string")
        return nil
    end

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
    return data
end

function LuaNFrame.PrintProto(msgdata)
    LuaNFrame.Info(NF_LOG_SYSTEMLOG, 0, LuaNFrame.serpent.block(msgdata))
end
