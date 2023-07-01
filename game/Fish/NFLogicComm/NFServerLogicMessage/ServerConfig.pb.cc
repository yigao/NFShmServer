// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerConfig.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ServerConfig.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto_ff {

namespace {

const ::google::protobuf::Descriptor* WorldExternalConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  WorldExternalConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameExternalConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameExternalConfig_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* TableID_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_ServerConfig_2eproto() {
  protobuf_AddDesc_ServerConfig_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ServerConfig.proto");
  GOOGLE_CHECK(file != NULL);
  WorldExternalConfig_descriptor_ = file->message_type(0);
  static const int WorldExternalConfig_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, tokentimecheck_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, whiteliststate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, maxregisternum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, whitelist_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, startqueuenum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, maxqueuenum_),
  };
  WorldExternalConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      WorldExternalConfig_descriptor_,
      WorldExternalConfig::default_instance_,
      WorldExternalConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldExternalConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(WorldExternalConfig));
  GameExternalConfig_descriptor_ = file->message_type(1);
  static const int GameExternalConfig_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameExternalConfig, map_),
  };
  GameExternalConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameExternalConfig_descriptor_,
      GameExternalConfig::default_instance_,
      GameExternalConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameExternalConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameExternalConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameExternalConfig));
  TableID_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ServerConfig_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    WorldExternalConfig_descriptor_, &WorldExternalConfig::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameExternalConfig_descriptor_, &GameExternalConfig::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_ServerConfig_2eproto() {
  delete WorldExternalConfig::default_instance_;
  delete WorldExternalConfig_reflection_;
  delete GameExternalConfig::default_instance_;
  delete GameExternalConfig_reflection_;
}

void protobuf_AddDesc_ServerConfig_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022ServerConfig.proto\022\010proto_ff\032\025yd_field"
    "options.proto\"\242\001\n\023WorldExternalConfig\022\026\n"
    "\016TokenTimeCheck\030\001 \001(\010\022\026\n\016WhiteListState\030"
    "\002 \001(\010\022\026\n\016MaxRegisterNum\030\003 \001(\r\022\027\n\tWhiteLi"
    "st\030\004 \003(\004B\004\210\301\024d\022\025\n\rStartQueueNum\030\006 \001(\r\022\023\n"
    "\013MaxQueueNum\030\007 \001(\r\"\'\n\022GameExternalConfig"
    "\022\021\n\003map\030\001 \003(\004B\004\240\301\024\001*5\n\007TableID\022\020\n\014E_TABL"
    "E_NONE\020\000\022\030\n\024E_TABLE_ROLE_DB_DATA\020\001", 314);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ServerConfig.proto", &protobuf_RegisterTypes);
  WorldExternalConfig::default_instance_ = new WorldExternalConfig();
  GameExternalConfig::default_instance_ = new GameExternalConfig();
  WorldExternalConfig::default_instance_->InitAsDefaultInstance();
  GameExternalConfig::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ServerConfig_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ServerConfig_2eproto {
  StaticDescriptorInitializer_ServerConfig_2eproto() {
    protobuf_AddDesc_ServerConfig_2eproto();
  }
} static_descriptor_initializer_ServerConfig_2eproto_;
const ::google::protobuf::EnumDescriptor* TableID_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TableID_descriptor_;
}
bool TableID_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int WorldExternalConfig::kTokenTimeCheckFieldNumber;
const int WorldExternalConfig::kWhiteListStateFieldNumber;
const int WorldExternalConfig::kMaxRegisterNumFieldNumber;
const int WorldExternalConfig::kWhiteListFieldNumber;
const int WorldExternalConfig::kStartQueueNumFieldNumber;
const int WorldExternalConfig::kMaxQueueNumFieldNumber;
#endif  // !_MSC_VER

WorldExternalConfig::WorldExternalConfig()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void WorldExternalConfig::InitAsDefaultInstance() {
}

WorldExternalConfig::WorldExternalConfig(const WorldExternalConfig& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void WorldExternalConfig::SharedCtor() {
  _cached_size_ = 0;
  tokentimecheck_ = false;
  whiteliststate_ = false;
  maxregisternum_ = 0u;
  startqueuenum_ = 0u;
  maxqueuenum_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

WorldExternalConfig::~WorldExternalConfig() {
  SharedDtor();
}

void WorldExternalConfig::SharedDtor() {
  if (this != default_instance_) {
  }
}

void WorldExternalConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* WorldExternalConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return WorldExternalConfig_descriptor_;
}

const WorldExternalConfig& WorldExternalConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_ServerConfig_2eproto();
  return *default_instance_;
}

WorldExternalConfig* WorldExternalConfig::default_instance_ = NULL;

WorldExternalConfig* WorldExternalConfig::New() const {
  return new WorldExternalConfig;
}

void WorldExternalConfig::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    tokentimecheck_ = false;
    whiteliststate_ = false;
    maxregisternum_ = 0u;
    startqueuenum_ = 0u;
    maxqueuenum_ = 0u;
  }
  whitelist_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool WorldExternalConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool TokenTimeCheck = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &tokentimecheck_)));
          set_has_tokentimecheck();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_WhiteListState;
        break;
      }

      // optional bool WhiteListState = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_WhiteListState:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &whiteliststate_)));
          set_has_whiteliststate();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_MaxRegisterNum;
        break;
      }

      // optional uint32 MaxRegisterNum = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_MaxRegisterNum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &maxregisternum_)));
          set_has_maxregisternum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_WhiteList;
        break;
      }

      // repeated uint64 WhiteList = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_WhiteList:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 1, 32, input, this->mutable_whitelist())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_whitelist())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_WhiteList;
        if (input->ExpectTag(48)) goto parse_StartQueueNum;
        break;
      }

      // optional uint32 StartQueueNum = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_StartQueueNum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &startqueuenum_)));
          set_has_startqueuenum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_MaxQueueNum;
        break;
      }

      // optional uint32 MaxQueueNum = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_MaxQueueNum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &maxqueuenum_)));
          set_has_maxqueuenum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void WorldExternalConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional bool TokenTimeCheck = 1;
  if (has_tokentimecheck()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->tokentimecheck(), output);
  }

  // optional bool WhiteListState = 2;
  if (has_whiteliststate()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->whiteliststate(), output);
  }

  // optional uint32 MaxRegisterNum = 3;
  if (has_maxregisternum()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->maxregisternum(), output);
  }

  // repeated uint64 WhiteList = 4;
  for (int i = 0; i < this->whitelist_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(
      4, this->whitelist(i), output);
  }

  // optional uint32 StartQueueNum = 6;
  if (has_startqueuenum()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->startqueuenum(), output);
  }

  // optional uint32 MaxQueueNum = 7;
  if (has_maxqueuenum()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->maxqueuenum(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* WorldExternalConfig::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional bool TokenTimeCheck = 1;
  if (has_tokentimecheck()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->tokentimecheck(), target);
  }

  // optional bool WhiteListState = 2;
  if (has_whiteliststate()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->whiteliststate(), target);
  }

  // optional uint32 MaxRegisterNum = 3;
  if (has_maxregisternum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->maxregisternum(), target);
  }

  // repeated uint64 WhiteList = 4;
  for (int i = 0; i < this->whitelist_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64ToArray(4, this->whitelist(i), target);
  }

  // optional uint32 StartQueueNum = 6;
  if (has_startqueuenum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->startqueuenum(), target);
  }

  // optional uint32 MaxQueueNum = 7;
  if (has_maxqueuenum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->maxqueuenum(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int WorldExternalConfig::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool TokenTimeCheck = 1;
    if (has_tokentimecheck()) {
      total_size += 1 + 1;
    }

    // optional bool WhiteListState = 2;
    if (has_whiteliststate()) {
      total_size += 1 + 1;
    }

    // optional uint32 MaxRegisterNum = 3;
    if (has_maxregisternum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->maxregisternum());
    }

    // optional uint32 StartQueueNum = 6;
    if (has_startqueuenum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->startqueuenum());
    }

    // optional uint32 MaxQueueNum = 7;
    if (has_maxqueuenum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->maxqueuenum());
    }

  }
  // repeated uint64 WhiteList = 4;
  {
    int data_size = 0;
    for (int i = 0; i < this->whitelist_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt64Size(this->whitelist(i));
    }
    total_size += 1 * this->whitelist_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void WorldExternalConfig::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const WorldExternalConfig* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const WorldExternalConfig*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void WorldExternalConfig::MergeFrom(const WorldExternalConfig& from) {
  GOOGLE_CHECK_NE(&from, this);
  whitelist_.MergeFrom(from.whitelist_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_tokentimecheck()) {
      set_tokentimecheck(from.tokentimecheck());
    }
    if (from.has_whiteliststate()) {
      set_whiteliststate(from.whiteliststate());
    }
    if (from.has_maxregisternum()) {
      set_maxregisternum(from.maxregisternum());
    }
    if (from.has_startqueuenum()) {
      set_startqueuenum(from.startqueuenum());
    }
    if (from.has_maxqueuenum()) {
      set_maxqueuenum(from.maxqueuenum());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void WorldExternalConfig::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WorldExternalConfig::CopyFrom(const WorldExternalConfig& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WorldExternalConfig::IsInitialized() const {

  return true;
}

void WorldExternalConfig::Swap(WorldExternalConfig* other) {
  if (other != this) {
    std::swap(tokentimecheck_, other->tokentimecheck_);
    std::swap(whiteliststate_, other->whiteliststate_);
    std::swap(maxregisternum_, other->maxregisternum_);
    whitelist_.Swap(&other->whitelist_);
    std::swap(startqueuenum_, other->startqueuenum_);
    std::swap(maxqueuenum_, other->maxqueuenum_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata WorldExternalConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = WorldExternalConfig_descriptor_;
  metadata.reflection = WorldExternalConfig_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameExternalConfig::kMapFieldNumber;
#endif  // !_MSC_VER

GameExternalConfig::GameExternalConfig()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void GameExternalConfig::InitAsDefaultInstance() {
}

GameExternalConfig::GameExternalConfig(const GameExternalConfig& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void GameExternalConfig::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameExternalConfig::~GameExternalConfig() {
  SharedDtor();
}

void GameExternalConfig::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameExternalConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameExternalConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameExternalConfig_descriptor_;
}

const GameExternalConfig& GameExternalConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_ServerConfig_2eproto();
  return *default_instance_;
}

GameExternalConfig* GameExternalConfig::default_instance_ = NULL;

GameExternalConfig* GameExternalConfig::New() const {
  return new GameExternalConfig;
}

void GameExternalConfig::Clear() {
  map_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameExternalConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated uint64 map = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_map:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 1, 8, input, this->mutable_map())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_map())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(8)) goto parse_map;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void GameExternalConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated uint64 map = 1;
  for (int i = 0; i < this->map_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(
      1, this->map(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* GameExternalConfig::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated uint64 map = 1;
  for (int i = 0; i < this->map_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64ToArray(1, this->map(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int GameExternalConfig::ByteSize() const {
  int total_size = 0;

  // repeated uint64 map = 1;
  {
    int data_size = 0;
    for (int i = 0; i < this->map_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt64Size(this->map(i));
    }
    total_size += 1 * this->map_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameExternalConfig::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameExternalConfig* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameExternalConfig*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameExternalConfig::MergeFrom(const GameExternalConfig& from) {
  GOOGLE_CHECK_NE(&from, this);
  map_.MergeFrom(from.map_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameExternalConfig::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameExternalConfig::CopyFrom(const GameExternalConfig& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameExternalConfig::IsInitialized() const {

  return true;
}

void GameExternalConfig::Swap(GameExternalConfig* other) {
  if (other != this) {
    map_.Swap(&other->map_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameExternalConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameExternalConfig_descriptor_;
  metadata.reflection = GameExternalConfig_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
