// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Armor.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Armor.pb.h"

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

const ::google::protobuf::Descriptor* NotifyArmorRsp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NotifyArmorRsp_reflection_ = NULL;
const ::google::protobuf::Descriptor* ArmorActiveReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArmorActiveReq_reflection_ = NULL;
const ::google::protobuf::Descriptor* ArmorActiveRsp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArmorActiveRsp_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Armor_2eproto() {
  protobuf_AddDesc_Armor_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Armor.proto");
  GOOGLE_CHECK(file != NULL);
  NotifyArmorRsp_descriptor_ = file->message_type(0);
  static const int NotifyArmorRsp_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NotifyArmorRsp, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NotifyArmorRsp, infos_),
  };
  NotifyArmorRsp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      NotifyArmorRsp_descriptor_,
      NotifyArmorRsp::default_instance_,
      NotifyArmorRsp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NotifyArmorRsp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NotifyArmorRsp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(NotifyArmorRsp));
  ArmorActiveReq_descriptor_ = file->message_type(1);
  static const int ArmorActiveReq_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveReq, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveReq, index_),
  };
  ArmorActiveReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArmorActiveReq_descriptor_,
      ArmorActiveReq::default_instance_,
      ArmorActiveReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArmorActiveReq));
  ArmorActiveRsp_descriptor_ = file->message_type(2);
  static const int ArmorActiveRsp_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveRsp, ret_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveRsp, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveRsp, index_),
  };
  ArmorActiveRsp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArmorActiveRsp_descriptor_,
      ArmorActiveRsp::default_instance_,
      ArmorActiveRsp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveRsp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArmorActiveRsp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArmorActiveRsp));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Armor_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    NotifyArmorRsp_descriptor_, &NotifyArmorRsp::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArmorActiveReq_descriptor_, &ArmorActiveReq::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArmorActiveRsp_descriptor_, &ArmorActiveRsp::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Armor_2eproto() {
  delete NotifyArmorRsp::default_instance_;
  delete NotifyArmorRsp_reflection_;
  delete ArmorActiveReq::default_instance_;
  delete ArmorActiveReq_reflection_;
  delete ArmorActiveRsp::default_instance_;
  delete ArmorActiveRsp_reflection_;
}

void protobuf_AddDesc_Armor_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::proto_ff::protobuf_AddDesc_common_5flogic_2eproto();
  ::proto_ff::protobuf_AddDesc_Com_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013Armor.proto\022\010proto_ff\032\025yd_fieldoptions"
    ".proto\032\022common_logic.proto\032\tCom.proto\"B\n"
    "\016NotifyArmorRsp\022\014\n\004type\030\001 \001(\005\022\"\n\005infos\030\002"
    " \003(\0132\023.proto_ff.ArmorInfo\"+\n\016ArmorActive"
    "Req\022\n\n\002id\030\001 \001(\005\022\r\n\005index\030\002 \001(\005\"8\n\016ArmorA"
    "ctiveRsp\022\013\n\003ret\030\001 \001(\005\022\n\n\002id\030\002 \001(\005\022\r\n\005ind"
    "ex\030\003 \001(\005", 248);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Armor.proto", &protobuf_RegisterTypes);
  NotifyArmorRsp::default_instance_ = new NotifyArmorRsp();
  ArmorActiveReq::default_instance_ = new ArmorActiveReq();
  ArmorActiveRsp::default_instance_ = new ArmorActiveRsp();
  NotifyArmorRsp::default_instance_->InitAsDefaultInstance();
  ArmorActiveReq::default_instance_->InitAsDefaultInstance();
  ArmorActiveRsp::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Armor_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Armor_2eproto {
  StaticDescriptorInitializer_Armor_2eproto() {
    protobuf_AddDesc_Armor_2eproto();
  }
} static_descriptor_initializer_Armor_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int NotifyArmorRsp::kTypeFieldNumber;
const int NotifyArmorRsp::kInfosFieldNumber;
#endif  // !_MSC_VER

NotifyArmorRsp::NotifyArmorRsp()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void NotifyArmorRsp::InitAsDefaultInstance() {
}

NotifyArmorRsp::NotifyArmorRsp(const NotifyArmorRsp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void NotifyArmorRsp::SharedCtor() {
  _cached_size_ = 0;
  type_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NotifyArmorRsp::~NotifyArmorRsp() {
  SharedDtor();
}

void NotifyArmorRsp::SharedDtor() {
  if (this != default_instance_) {
  }
}

void NotifyArmorRsp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NotifyArmorRsp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NotifyArmorRsp_descriptor_;
}

const NotifyArmorRsp& NotifyArmorRsp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Armor_2eproto();
  return *default_instance_;
}

NotifyArmorRsp* NotifyArmorRsp::default_instance_ = NULL;

NotifyArmorRsp* NotifyArmorRsp::New() const {
  return new NotifyArmorRsp;
}

void NotifyArmorRsp::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    type_ = 0;
  }
  infos_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool NotifyArmorRsp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_infos;
        break;
      }

      // repeated .proto_ff.ArmorInfo infos = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_infos:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_infos()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_infos;
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

void NotifyArmorRsp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->type(), output);
  }

  // repeated .proto_ff.ArmorInfo infos = 2;
  for (int i = 0; i < this->infos_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->infos(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* NotifyArmorRsp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->type(), target);
  }

  // repeated .proto_ff.ArmorInfo infos = 2;
  for (int i = 0; i < this->infos_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->infos(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int NotifyArmorRsp::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->type());
    }

  }
  // repeated .proto_ff.ArmorInfo infos = 2;
  total_size += 1 * this->infos_size();
  for (int i = 0; i < this->infos_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->infos(i));
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

void NotifyArmorRsp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const NotifyArmorRsp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const NotifyArmorRsp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void NotifyArmorRsp::MergeFrom(const NotifyArmorRsp& from) {
  GOOGLE_CHECK_NE(&from, this);
  infos_.MergeFrom(from.infos_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void NotifyArmorRsp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NotifyArmorRsp::CopyFrom(const NotifyArmorRsp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NotifyArmorRsp::IsInitialized() const {

  return true;
}

void NotifyArmorRsp::Swap(NotifyArmorRsp* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    infos_.Swap(&other->infos_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata NotifyArmorRsp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NotifyArmorRsp_descriptor_;
  metadata.reflection = NotifyArmorRsp_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ArmorActiveReq::kIdFieldNumber;
const int ArmorActiveReq::kIndexFieldNumber;
#endif  // !_MSC_VER

ArmorActiveReq::ArmorActiveReq()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ArmorActiveReq::InitAsDefaultInstance() {
}

ArmorActiveReq::ArmorActiveReq(const ArmorActiveReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ArmorActiveReq::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  index_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArmorActiveReq::~ArmorActiveReq() {
  SharedDtor();
}

void ArmorActiveReq::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArmorActiveReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArmorActiveReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArmorActiveReq_descriptor_;
}

const ArmorActiveReq& ArmorActiveReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Armor_2eproto();
  return *default_instance_;
}

ArmorActiveReq* ArmorActiveReq::default_instance_ = NULL;

ArmorActiveReq* ArmorActiveReq::New() const {
  return new ArmorActiveReq;
}

void ArmorActiveReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    index_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArmorActiveReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_index;
        break;
      }

      // optional int32 index = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_index:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &index_)));
          set_has_index();
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

void ArmorActiveReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional int32 index = 2;
  if (has_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->index(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ArmorActiveReq::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional int32 index = 2;
  if (has_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->index(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ArmorActiveReq::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional int32 index = 2;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->index());
    }

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

void ArmorActiveReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArmorActiveReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArmorActiveReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArmorActiveReq::MergeFrom(const ArmorActiveReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_index()) {
      set_index(from.index());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArmorActiveReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArmorActiveReq::CopyFrom(const ArmorActiveReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArmorActiveReq::IsInitialized() const {

  return true;
}

void ArmorActiveReq::Swap(ArmorActiveReq* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(index_, other->index_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArmorActiveReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArmorActiveReq_descriptor_;
  metadata.reflection = ArmorActiveReq_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ArmorActiveRsp::kRetFieldNumber;
const int ArmorActiveRsp::kIdFieldNumber;
const int ArmorActiveRsp::kIndexFieldNumber;
#endif  // !_MSC_VER

ArmorActiveRsp::ArmorActiveRsp()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ArmorActiveRsp::InitAsDefaultInstance() {
}

ArmorActiveRsp::ArmorActiveRsp(const ArmorActiveRsp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ArmorActiveRsp::SharedCtor() {
  _cached_size_ = 0;
  ret_ = 0;
  id_ = 0;
  index_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArmorActiveRsp::~ArmorActiveRsp() {
  SharedDtor();
}

void ArmorActiveRsp::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArmorActiveRsp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArmorActiveRsp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArmorActiveRsp_descriptor_;
}

const ArmorActiveRsp& ArmorActiveRsp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Armor_2eproto();
  return *default_instance_;
}

ArmorActiveRsp* ArmorActiveRsp::default_instance_ = NULL;

ArmorActiveRsp* ArmorActiveRsp::New() const {
  return new ArmorActiveRsp;
}

void ArmorActiveRsp::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    ret_ = 0;
    id_ = 0;
    index_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArmorActiveRsp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 ret = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &ret_)));
          set_has_ret();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_id;
        break;
      }

      // optional int32 id = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_index;
        break;
      }

      // optional int32 index = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_index:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &index_)));
          set_has_index();
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

void ArmorActiveRsp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 ret = 1;
  if (has_ret()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->ret(), output);
  }

  // optional int32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->id(), output);
  }

  // optional int32 index = 3;
  if (has_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->index(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ArmorActiveRsp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 ret = 1;
  if (has_ret()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->ret(), target);
  }

  // optional int32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->id(), target);
  }

  // optional int32 index = 3;
  if (has_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->index(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ArmorActiveRsp::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 ret = 1;
    if (has_ret()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->ret());
    }

    // optional int32 id = 2;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional int32 index = 3;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->index());
    }

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

void ArmorActiveRsp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArmorActiveRsp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArmorActiveRsp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArmorActiveRsp::MergeFrom(const ArmorActiveRsp& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_ret()) {
      set_ret(from.ret());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_index()) {
      set_index(from.index());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArmorActiveRsp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArmorActiveRsp::CopyFrom(const ArmorActiveRsp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArmorActiveRsp::IsInitialized() const {

  return true;
}

void ArmorActiveRsp::Swap(ArmorActiveRsp* other) {
  if (other != this) {
    std::swap(ret_, other->ret_);
    std::swap(id_, other->id_);
    std::swap(index_, other->index_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArmorActiveRsp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArmorActiveRsp_descriptor_;
  metadata.reflection = ArmorActiveRsp_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
