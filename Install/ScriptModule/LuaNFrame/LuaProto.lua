LuaProto = LuaProto or {}

LuaProto.pb     = require "pb"
LuaProto.pb_io   = require "pb_io"
LuaProto.pb_buffer = require "pb_buffer"
LuaProto.pb_slice  = require "pb_slice"
LuaProto.pb_conv   = require "pb_conv"
LuaProto.protoc = require "protoc"
LuaProto.serpent = require "serpent"

function LuaProto.LoadProto(proto)
    LuaProto.protoc:load(proto)
end

function LuaProto.LoadProtoFile(proto)
    LuaProto.protoc:loadfile(proto)
end

function LuaProto.AddPath(path)
    LuaProto.protoc:addpath(path)
end

function LuaProto.LoadFile(protofile)
    assert(LuaProto.pb.loadfile(protofile)) -- 载入刚才编译的pb文件
end

function LuaProto.Decode(msgtype, msgdata_buffer)
    if type(msgtype) ~= "string" or type(msgdata_buffer) ~= "string" then
        return nil
    end
    return LuaProto.pb.decode(msgtype, msgdata_buffer)
end

function LuaProto.Encode(msgtype, msgdata)
    if type(msgtype) ~= "string" or type(msgdata) ~= "table" then
        return nil
    end
    return LuaProto.pb.encode(msgtype, msgdata)
end

function LuaProto.Defaults(msgtype)
    local msg_proto_type, basename, type_name = pb.type(msgtype)
    if type_name == "enum" then
        return pb.enum(msgtype, 0)
    elseif type_name == "map" then
        return {}
    end

    local data = LuaProto.pb.defaults(msgtype)
    for name, number, type, defaultValue, fieldlabel in pb.fields(msgtype) do
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
                    data[name] = LuaProto.Defaults(type)
                end
            end
        end
      end
    return data
end

function LuaProto.PrintProto(msgdata)
    LogFile("info", LuaProto.serpent.block(msgdata))
end
