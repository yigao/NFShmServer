// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: constant.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "constant.pb.h"

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

const ::google::protobuf::Descriptor* E_ConstantConstant_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  E_ConstantConstant_reflection_ = NULL;
const ::google::protobuf::Descriptor* Sheet_ConstantConstant_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Sheet_ConstantConstant_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_constant_2eproto() {
  protobuf_AddDesc_constant_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "constant.proto");
  GOOGLE_CHECK(file != NULL);
  E_ConstantConstant_descriptor_ = file->message_type(0);
  static const int E_ConstantConstant_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_ConstantConstant, m_constantid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_ConstantConstant, m_constantdata_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_ConstantConstant, m_stringdata_),
  };
  E_ConstantConstant_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      E_ConstantConstant_descriptor_,
      E_ConstantConstant::default_instance_,
      E_ConstantConstant_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_ConstantConstant, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_ConstantConstant, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(E_ConstantConstant));
  Sheet_ConstantConstant_descriptor_ = file->message_type(1);
  static const int Sheet_ConstantConstant_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_ConstantConstant, e_constantconstant_list_),
  };
  Sheet_ConstantConstant_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Sheet_ConstantConstant_descriptor_,
      Sheet_ConstantConstant::default_instance_,
      Sheet_ConstantConstant_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_ConstantConstant, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_ConstantConstant, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Sheet_ConstantConstant));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_constant_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    E_ConstantConstant_descriptor_, &E_ConstantConstant::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Sheet_ConstantConstant_descriptor_, &Sheet_ConstantConstant::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_constant_2eproto() {
  delete E_ConstantConstant::default_instance_;
  delete E_ConstantConstant_reflection_;
  delete Sheet_ConstantConstant::default_instance_;
  delete Sheet_ConstantConstant_reflection_;
}

void protobuf_AddDesc_constant_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016constant.proto\022\010proto_ff\032\025yd_fieldopti"
    "ons.proto\"\213\001\n\022E_ConstantConstant\022\"\n\014m_co"
    "nstantid\030\001 \001(\005B\014\302\377\024\010\351\205\215\347\275\256id\022\"\n\016m_consta"
    "ntdata\030\002 \001(\003B\n\302\377\024\006\346\225\260\346\215\256\022-\n\014m_stringdata"
    "\030\003 \001(\tB\027\302\377\024\017\345\255\227\347\254\246\344\270\262\346\225\260\346\215\256\220\301\024<\"]\n\026Sheet"
    "_ConstantConstant\022C\n\027E_ConstantConstant_"
    "List\030\001 \003(\0132\034.proto_ff.E_ConstantConstant"
    "B\004\210\301\024\024", 286);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "constant.proto", &protobuf_RegisterTypes);
  E_ConstantConstant::default_instance_ = new E_ConstantConstant();
  Sheet_ConstantConstant::default_instance_ = new Sheet_ConstantConstant();
  E_ConstantConstant::default_instance_->InitAsDefaultInstance();
  Sheet_ConstantConstant::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_constant_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_constant_2eproto {
  StaticDescriptorInitializer_constant_2eproto() {
    protobuf_AddDesc_constant_2eproto();
  }
} static_descriptor_initializer_constant_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int E_ConstantConstant::kMConstantidFieldNumber;
const int E_ConstantConstant::kMConstantdataFieldNumber;
const int E_ConstantConstant::kMStringdataFieldNumber;
#endif  // !_MSC_VER

E_ConstantConstant::E_ConstantConstant()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void E_ConstantConstant::InitAsDefaultInstance() {
}

E_ConstantConstant::E_ConstantConstant(const E_ConstantConstant& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void E_ConstantConstant::SharedCtor() {
  _cached_size_ = 0;
  m_constantid_ = 0;
  m_constantdata_ = GOOGLE_LONGLONG(0);
  m_stringdata_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

E_ConstantConstant::~E_ConstantConstant() {
  SharedDtor();
}

void E_ConstantConstant::SharedDtor() {
  if (m_stringdata_ != &::google::protobuf::internal::kEmptyString) {
    delete m_stringdata_;
  }
  if (this != default_instance_) {
  }
}

void E_ConstantConstant::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* E_ConstantConstant::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return E_ConstantConstant_descriptor_;
}

const E_ConstantConstant& E_ConstantConstant::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_constant_2eproto();
  return *default_instance_;
}

E_ConstantConstant* E_ConstantConstant::default_instance_ = NULL;

E_ConstantConstant* E_ConstantConstant::New() const {
  return new E_ConstantConstant;
}

void E_ConstantConstant::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    m_constantid_ = 0;
    m_constantdata_ = GOOGLE_LONGLONG(0);
    if (has_m_stringdata()) {
      if (m_stringdata_ != &::google::protobuf::internal::kEmptyString) {
        m_stringdata_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool E_ConstantConstant::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 m_constantid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_constantid_)));
          set_has_m_constantid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_m_constantdata;
        break;
      }

      // optional int64 m_constantdata = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_constantdata:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &m_constantdata_)));
          set_has_m_constantdata();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_m_stringdata;
        break;
      }

      // optional string m_stringdata = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_m_stringdata:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_m_stringdata()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->m_stringdata().data(), this->m_stringdata().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void E_ConstantConstant::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 m_constantid = 1;
  if (has_m_constantid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->m_constantid(), output);
  }

  // optional int64 m_constantdata = 2;
  if (has_m_constantdata()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->m_constantdata(), output);
  }

  // optional string m_stringdata = 3;
  if (has_m_stringdata()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_stringdata().data(), this->m_stringdata().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->m_stringdata(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* E_ConstantConstant::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 m_constantid = 1;
  if (has_m_constantid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->m_constantid(), target);
  }

  // optional int64 m_constantdata = 2;
  if (has_m_constantdata()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->m_constantdata(), target);
  }

  // optional string m_stringdata = 3;
  if (has_m_stringdata()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_stringdata().data(), this->m_stringdata().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->m_stringdata(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int E_ConstantConstant::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 m_constantid = 1;
    if (has_m_constantid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_constantid());
    }

    // optional int64 m_constantdata = 2;
    if (has_m_constantdata()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->m_constantdata());
    }

    // optional string m_stringdata = 3;
    if (has_m_stringdata()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->m_stringdata());
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

void E_ConstantConstant::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const E_ConstantConstant* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const E_ConstantConstant*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void E_ConstantConstant::MergeFrom(const E_ConstantConstant& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_m_constantid()) {
      set_m_constantid(from.m_constantid());
    }
    if (from.has_m_constantdata()) {
      set_m_constantdata(from.m_constantdata());
    }
    if (from.has_m_stringdata()) {
      set_m_stringdata(from.m_stringdata());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void E_ConstantConstant::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void E_ConstantConstant::CopyFrom(const E_ConstantConstant& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool E_ConstantConstant::IsInitialized() const {

  return true;
}

void E_ConstantConstant::Swap(E_ConstantConstant* other) {
  if (other != this) {
    std::swap(m_constantid_, other->m_constantid_);
    std::swap(m_constantdata_, other->m_constantdata_);
    std::swap(m_stringdata_, other->m_stringdata_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata E_ConstantConstant::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = E_ConstantConstant_descriptor_;
  metadata.reflection = E_ConstantConstant_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Sheet_ConstantConstant::kEConstantConstantListFieldNumber;
#endif  // !_MSC_VER

Sheet_ConstantConstant::Sheet_ConstantConstant()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Sheet_ConstantConstant::InitAsDefaultInstance() {
}

Sheet_ConstantConstant::Sheet_ConstantConstant(const Sheet_ConstantConstant& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Sheet_ConstantConstant::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Sheet_ConstantConstant::~Sheet_ConstantConstant() {
  SharedDtor();
}

void Sheet_ConstantConstant::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Sheet_ConstantConstant::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Sheet_ConstantConstant::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Sheet_ConstantConstant_descriptor_;
}

const Sheet_ConstantConstant& Sheet_ConstantConstant::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_constant_2eproto();
  return *default_instance_;
}

Sheet_ConstantConstant* Sheet_ConstantConstant::default_instance_ = NULL;

Sheet_ConstantConstant* Sheet_ConstantConstant::New() const {
  return new Sheet_ConstantConstant;
}

void Sheet_ConstantConstant::Clear() {
  e_constantconstant_list_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Sheet_ConstantConstant::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto_ff.E_ConstantConstant E_ConstantConstant_List = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_E_ConstantConstant_List:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_e_constantconstant_list()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_E_ConstantConstant_List;
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

void Sheet_ConstantConstant::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .proto_ff.E_ConstantConstant E_ConstantConstant_List = 1;
  for (int i = 0; i < this->e_constantconstant_list_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->e_constantconstant_list(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Sheet_ConstantConstant::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .proto_ff.E_ConstantConstant E_ConstantConstant_List = 1;
  for (int i = 0; i < this->e_constantconstant_list_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->e_constantconstant_list(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Sheet_ConstantConstant::ByteSize() const {
  int total_size = 0;

  // repeated .proto_ff.E_ConstantConstant E_ConstantConstant_List = 1;
  total_size += 1 * this->e_constantconstant_list_size();
  for (int i = 0; i < this->e_constantconstant_list_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->e_constantconstant_list(i));
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

void Sheet_ConstantConstant::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Sheet_ConstantConstant* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Sheet_ConstantConstant*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Sheet_ConstantConstant::MergeFrom(const Sheet_ConstantConstant& from) {
  GOOGLE_CHECK_NE(&from, this);
  e_constantconstant_list_.MergeFrom(from.e_constantconstant_list_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Sheet_ConstantConstant::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sheet_ConstantConstant::CopyFrom(const Sheet_ConstantConstant& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sheet_ConstantConstant::IsInitialized() const {

  return true;
}

void Sheet_ConstantConstant::Swap(Sheet_ConstantConstant* other) {
  if (other != this) {
    e_constantconstant_list_.Swap(&other->e_constantconstant_list_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Sheet_ConstantConstant::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Sheet_ConstantConstant_descriptor_;
  metadata.reflection = Sheet_ConstantConstant_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
