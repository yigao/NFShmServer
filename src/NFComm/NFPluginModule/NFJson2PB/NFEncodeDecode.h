// -------------------------------------------------------------------------
//    @FileName         :    NFPBToJson.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

namespace NFJson2PB {

//pattern: _Zxxx_
//rules: keep original lower-case characters, upper-case characters,
//digital charactors and '_' in the original position, 
//change other special characters to '_Zxxx_', 
//xxx is the character's decimal digit
//fg: 'abc123_ABC-' convert to 'abc123_ABC_Z045_'

//params: content: content need to encode
//params: encoded_content: content encoded
//return value: false: no need to encode, true: need to encode.
//note: when return value is false, no change in encoded_content.
bool encode_name(const std::string& content, std::string & encoded_content); 

//params: content: content need to decode
//params: decoded_content: content decoded
//return value: false: no need to decode, true: need to decode.
//note: when return value is false, no change in decoded_content.
bool decode_name(const std::string& content, std::string& decoded_content);

}
