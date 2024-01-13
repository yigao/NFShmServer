

#include <google/protobuf/message.h>
#include <google/protobuf/io/zero_copy_stream.h>    // ZeroCopyInputStream

namespace NFJson2PB {

struct Json2PbOptions {
    Json2PbOptions();

    // Decode string in json using base64 decoding if the type of
    // corresponding field is bytes when this option is turned on.
    // Default: false for baidu-interal, true otherwise.
    bool base64_to_bytes;
};

// Convert `json' to protobuf `message'.
// Returns true on success. `error' (if not NULL) will be set with error
// message on failure.
bool JsonToProtoMessage(const std::string& json,
                        google::protobuf::Message* message,
                        const Json2PbOptions& options,
                        std::string* error = NULL);

// send output to ZeroCopyOutputStream instead of std::string.
bool JsonToProtoMessage(google::protobuf::io::ZeroCopyInputStream *json,
                        google::protobuf::Message* message,
                        const Json2PbOptions& options,
                        std::string* error = NULL);

// Using default Json2PbOptions.
bool JsonToProtoMessage(const std::string& json,
                        google::protobuf::Message* message,
                        std::string* error = NULL);

bool JsonToProtoMessage(google::protobuf::io::ZeroCopyInputStream* stream,
                        google::protobuf::Message* message,
                        std::string* error = NULL);
} // namespace json2pb
