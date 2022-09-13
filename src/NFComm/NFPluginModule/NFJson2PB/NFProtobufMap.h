// -------------------------------------------------------------------------
//    @FileName         :    NFPBToJson.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include <google/protobuf/descriptor.h>

namespace NFJson2PB {

const char* const KEY_NAME = "key";
const char* const VALUE_NAME = "value";
const int KEY_INDEX = 0;
const int VALUE_INDEX = 1;

// Map inside protobuf is officially supported in proto3 using
// statement like: map<string, string> my_map = N;
// However, we can still emmulate this map in proto2 by writing:
// message MapFieldEntry {
//     required string key = 1;           // MUST be the first
//     required string value = 2;         // MUST be the second
// }
// repeated MapFieldEntry my_map = N;
// 
// Natually, when converting this map to json, it should be like:
// { "my_map": {"key1": value1, "key2": value2 } }
// instead of:
// { "my_map": [{"key": "key1", "value": value1},
//              {"key": "key2", "value": value2}] }
// In order to get the former one, the type of `key' field MUST be
// string since JSON only supports string keys

// Check whether `field' is a map type field and is convertable
bool IsProtobufMap(const google::protobuf::FieldDescriptor* field);

} //
