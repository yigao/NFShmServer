// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Wordshout.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "E_Wordshout.pb.h"

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

const ::google::protobuf::Descriptor* E_WordshoutShout_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  E_WordshoutShout_reflection_ = NULL;
const ::google::protobuf::Descriptor* Sheet_WordshoutShout_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Sheet_WordshoutShout_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_E_5fWordshout_2eproto() {
  protobuf_AddDesc_E_5fWordshout_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "E_Wordshout.proto");
  GOOGLE_CHECK(file != NULL);
  E_WordshoutShout_descriptor_ = file->message_type(0);
  static const int E_WordshoutShout_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_WordshoutShout, m_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_WordshoutShout, m_channel_),
  };
  E_WordshoutShout_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      E_WordshoutShout_descriptor_,
      E_WordshoutShout::default_instance_,
      E_WordshoutShout_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_WordshoutShout, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_WordshoutShout, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(E_WordshoutShout));
  Sheet_WordshoutShout_descriptor_ = file->message_type(1);
  static const int Sheet_WordshoutShout_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_WordshoutShout, e_wordshoutshout_list_),
  };
  Sheet_WordshoutShout_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Sheet_WordshoutShout_descriptor_,
      Sheet_WordshoutShout::default_instance_,
      Sheet_WordshoutShout_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_WordshoutShout, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_WordshoutShout, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Sheet_WordshoutShout));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_E_5fWordshout_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    E_WordshoutShout_descriptor_, &E_WordshoutShout::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Sheet_WordshoutShout_descriptor_, &Sheet_WordshoutShout::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_E_5fWordshout_2eproto() {
  delete E_WordshoutShout::default_instance_;
  delete E_WordshoutShout_reflection_;
  delete Sheet_WordshoutShout::default_instance_;
  delete Sheet_WordshoutShout_reflection_;
}

void protobuf_AddDesc_E_5fWordshout_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021E_Wordshout.proto\022\010proto_ff\032\025yd_fieldo"
    "ptions.proto\"M\n\020E_WordshoutShout\022\024\n\004m_ID"
    "\030\001 \001(\005B\006\302\377\024\002id\022#\n\tm_Channel\030\002 \001(\005B\020\302\377\024\014\351"
    "\242\221\351\201\223\345\255\227\346\256\265\"W\n\024Sheet_WordshoutShout\022\?\n\025E"
    "_WordshoutShout_List\030\001 \003(\0132\032.proto_ff.E_"
    "WordshoutShoutB\004\210\301\024\010", 220);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "E_Wordshout.proto", &protobuf_RegisterTypes);
  E_WordshoutShout::default_instance_ = new E_WordshoutShout();
  Sheet_WordshoutShout::default_instance_ = new Sheet_WordshoutShout();
  E_WordshoutShout::default_instance_->InitAsDefaultInstance();
  Sheet_WordshoutShout::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_E_5fWordshout_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_E_5fWordshout_2eproto {
  StaticDescriptorInitializer_E_5fWordshout_2eproto() {
    protobuf_AddDesc_E_5fWordshout_2eproto();
  }
} static_descriptor_initializer_E_5fWordshout_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int E_WordshoutShout::kMIDFieldNumber;
const int E_WordshoutShout::kMChannelFieldNumber;
#endif  // !_MSC_VER

E_WordshoutShout::E_WordshoutShout()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void E_WordshoutShout::InitAsDefaultInstance() {
}

E_WordshoutShout::E_WordshoutShout(const E_WordshoutShout& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void E_WordshoutShout::SharedCtor() {
  _cached_size_ = 0;
  m_id_ = 0;
  m_channel_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

E_WordshoutShout::~E_WordshoutShout() {
  SharedDtor();
}

void E_WordshoutShout::SharedDtor() {
  if (this != default_instance_) {
  }
}

void E_WordshoutShout::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* E_WordshoutShout::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return E_WordshoutShout_descriptor_;
}

const E_WordshoutShout& E_WordshoutShout::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fWordshout_2eproto();
  return *default_instance_;
}

E_WordshoutShout* E_WordshoutShout::default_instance_ = NULL;

E_WordshoutShout* E_WordshoutShout::New() const {
  return new E_WordshoutShout;
}

void E_WordshoutShout::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    m_id_ = 0;
    m_channel_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool E_WordshoutShout::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 m_ID = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_id_)));
          set_has_m_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_m_Channel;
        break;
      }

      // optional int32 m_Channel = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_Channel:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_channel_)));
          set_has_m_channel();
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

void E_WordshoutShout::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 m_ID = 1;
  if (has_m_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->m_id(), output);
  }

  // optional int32 m_Channel = 2;
  if (has_m_channel()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->m_channel(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* E_WordshoutShout::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 m_ID = 1;
  if (has_m_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->m_id(), target);
  }

  // optional int32 m_Channel = 2;
  if (has_m_channel()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->m_channel(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int E_WordshoutShout::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 m_ID = 1;
    if (has_m_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_id());
    }

    // optional int32 m_Channel = 2;
    if (has_m_channel()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_channel());
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

void E_WordshoutShout::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const E_WordshoutShout* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const E_WordshoutShout*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void E_WordshoutShout::MergeFrom(const E_WordshoutShout& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_m_id()) {
      set_m_id(from.m_id());
    }
    if (from.has_m_channel()) {
      set_m_channel(from.m_channel());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void E_WordshoutShout::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void E_WordshoutShout::CopyFrom(const E_WordshoutShout& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool E_WordshoutShout::IsInitialized() const {

  return true;
}

void E_WordshoutShout::Swap(E_WordshoutShout* other) {
  if (other != this) {
    std::swap(m_id_, other->m_id_);
    std::swap(m_channel_, other->m_channel_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata E_WordshoutShout::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = E_WordshoutShout_descriptor_;
  metadata.reflection = E_WordshoutShout_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Sheet_WordshoutShout::kEWordshoutShoutListFieldNumber;
#endif  // !_MSC_VER

Sheet_WordshoutShout::Sheet_WordshoutShout()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Sheet_WordshoutShout::InitAsDefaultInstance() {
}

Sheet_WordshoutShout::Sheet_WordshoutShout(const Sheet_WordshoutShout& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Sheet_WordshoutShout::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Sheet_WordshoutShout::~Sheet_WordshoutShout() {
  SharedDtor();
}

void Sheet_WordshoutShout::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Sheet_WordshoutShout::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Sheet_WordshoutShout::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Sheet_WordshoutShout_descriptor_;
}

const Sheet_WordshoutShout& Sheet_WordshoutShout::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fWordshout_2eproto();
  return *default_instance_;
}

Sheet_WordshoutShout* Sheet_WordshoutShout::default_instance_ = NULL;

Sheet_WordshoutShout* Sheet_WordshoutShout::New() const {
  return new Sheet_WordshoutShout;
}

void Sheet_WordshoutShout::Clear() {
  e_wordshoutshout_list_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Sheet_WordshoutShout::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto_ff.E_WordshoutShout E_WordshoutShout_List = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_E_WordshoutShout_List:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_e_wordshoutshout_list()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_E_WordshoutShout_List;
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

void Sheet_WordshoutShout::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .proto_ff.E_WordshoutShout E_WordshoutShout_List = 1;
  for (int i = 0; i < this->e_wordshoutshout_list_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->e_wordshoutshout_list(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Sheet_WordshoutShout::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .proto_ff.E_WordshoutShout E_WordshoutShout_List = 1;
  for (int i = 0; i < this->e_wordshoutshout_list_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->e_wordshoutshout_list(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Sheet_WordshoutShout::ByteSize() const {
  int total_size = 0;

  // repeated .proto_ff.E_WordshoutShout E_WordshoutShout_List = 1;
  total_size += 1 * this->e_wordshoutshout_list_size();
  for (int i = 0; i < this->e_wordshoutshout_list_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->e_wordshoutshout_list(i));
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

void Sheet_WordshoutShout::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Sheet_WordshoutShout* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Sheet_WordshoutShout*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Sheet_WordshoutShout::MergeFrom(const Sheet_WordshoutShout& from) {
  GOOGLE_CHECK_NE(&from, this);
  e_wordshoutshout_list_.MergeFrom(from.e_wordshoutshout_list_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Sheet_WordshoutShout::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sheet_WordshoutShout::CopyFrom(const Sheet_WordshoutShout& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sheet_WordshoutShout::IsInitialized() const {

  return true;
}

void Sheet_WordshoutShout::Swap(Sheet_WordshoutShout* other) {
  if (other != this) {
    e_wordshoutshout_list_.Swap(&other->e_wordshoutshout_list_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Sheet_WordshoutShout::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Sheet_WordshoutShout_descriptor_;
  metadata.reflection = Sheet_WordshoutShout_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
