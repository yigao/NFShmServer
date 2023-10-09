// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Link.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "E_Link.pb.h"

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

const ::google::protobuf::Descriptor* E_LinkLink_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  E_LinkLink_reflection_ = NULL;
const ::google::protobuf::Descriptor* Sheet_LinkLink_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Sheet_LinkLink_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_E_5fLink_2eproto() {
  protobuf_AddDesc_E_5fLink_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "E_Link.proto");
  GOOGLE_CHECK(file != NULL);
  E_LinkLink_descriptor_ = file->message_type(0);
  static const int E_LinkLink_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, m_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, m_icon_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, m_dbargs_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, m_argsm_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, m_functionunlock_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, m_linknpc_),
  };
  E_LinkLink_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      E_LinkLink_descriptor_,
      E_LinkLink::default_instance_,
      E_LinkLink_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_LinkLink, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(E_LinkLink));
  Sheet_LinkLink_descriptor_ = file->message_type(1);
  static const int Sheet_LinkLink_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_LinkLink, e_linklink_list_),
  };
  Sheet_LinkLink_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Sheet_LinkLink_descriptor_,
      Sheet_LinkLink::default_instance_,
      Sheet_LinkLink_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_LinkLink, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_LinkLink, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Sheet_LinkLink));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_E_5fLink_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    E_LinkLink_descriptor_, &E_LinkLink::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Sheet_LinkLink_descriptor_, &Sheet_LinkLink::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_E_5fLink_2eproto() {
  delete E_LinkLink::default_instance_;
  delete E_LinkLink_reflection_;
  delete Sheet_LinkLink::default_instance_;
  delete Sheet_LinkLink_reflection_;
}

void protobuf_AddDesc_E_5fLink_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014E_Link.proto\022\010proto_ff\032\025yd_fieldoption"
    "s.proto\"\210\002\n\nE_LinkLink\022\030\n\004m_id\030\001 \001(\003B\n\302\377"
    "\024\006\345\272\217\345\217\267\022$\n\006m_icon\030\002 \001(\tB\024\302\377\024\014\346\230\276\347\244\272\345\233\276\346"
    "\240\207\220\301\024@\022;\n\010m_dbargs\030\003 \001(\tB)\302\377\024!\344\270\273\345\217\202\346\225\260\345"
    "\205\263\350\201\224\347\232\204\351\205\215\347\275\256\350\241\250\345\220\215\347\247\260\220\301\024@\022%\n\007m_argsm\030\004"
    " \001(\tB\024\302\377\024\014\345\244\207\351\200\211\345\217\202\346\225\260\220\301\024@\0220\n\020m_function"
    "unlock\030\005 \001(\005B\026\302\377\024\022\345\205\263\350\201\224\345\212\237\350\203\275\345\274\200\346\224\276\022$\n\t"
    "m_linknpc\030\006 \001(\tB\021\302\377\024\t\345\205\263\350\201\224npc\220\301\024@\"F\n\016Sh"
    "eet_LinkLink\0224\n\017E_LinkLink_List\030\001 \003(\0132\024."
    "proto_ff.E_LinkLinkB\005\210\301\024\200\004", 386);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "E_Link.proto", &protobuf_RegisterTypes);
  E_LinkLink::default_instance_ = new E_LinkLink();
  Sheet_LinkLink::default_instance_ = new Sheet_LinkLink();
  E_LinkLink::default_instance_->InitAsDefaultInstance();
  Sheet_LinkLink::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_E_5fLink_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_E_5fLink_2eproto {
  StaticDescriptorInitializer_E_5fLink_2eproto() {
    protobuf_AddDesc_E_5fLink_2eproto();
  }
} static_descriptor_initializer_E_5fLink_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int E_LinkLink::kMIdFieldNumber;
const int E_LinkLink::kMIconFieldNumber;
const int E_LinkLink::kMDbargsFieldNumber;
const int E_LinkLink::kMArgsmFieldNumber;
const int E_LinkLink::kMFunctionunlockFieldNumber;
const int E_LinkLink::kMLinknpcFieldNumber;
#endif  // !_MSC_VER

E_LinkLink::E_LinkLink()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void E_LinkLink::InitAsDefaultInstance() {
}

E_LinkLink::E_LinkLink(const E_LinkLink& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void E_LinkLink::SharedCtor() {
  _cached_size_ = 0;
  m_id_ = GOOGLE_LONGLONG(0);
  m_icon_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  m_dbargs_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  m_argsm_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  m_functionunlock_ = 0;
  m_linknpc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

E_LinkLink::~E_LinkLink() {
  SharedDtor();
}

void E_LinkLink::SharedDtor() {
  if (m_icon_ != &::google::protobuf::internal::kEmptyString) {
    delete m_icon_;
  }
  if (m_dbargs_ != &::google::protobuf::internal::kEmptyString) {
    delete m_dbargs_;
  }
  if (m_argsm_ != &::google::protobuf::internal::kEmptyString) {
    delete m_argsm_;
  }
  if (m_linknpc_ != &::google::protobuf::internal::kEmptyString) {
    delete m_linknpc_;
  }
  if (this != default_instance_) {
  }
}

void E_LinkLink::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* E_LinkLink::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return E_LinkLink_descriptor_;
}

const E_LinkLink& E_LinkLink::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fLink_2eproto();
  return *default_instance_;
}

E_LinkLink* E_LinkLink::default_instance_ = NULL;

E_LinkLink* E_LinkLink::New() const {
  return new E_LinkLink;
}

void E_LinkLink::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    m_id_ = GOOGLE_LONGLONG(0);
    if (has_m_icon()) {
      if (m_icon_ != &::google::protobuf::internal::kEmptyString) {
        m_icon_->clear();
      }
    }
    if (has_m_dbargs()) {
      if (m_dbargs_ != &::google::protobuf::internal::kEmptyString) {
        m_dbargs_->clear();
      }
    }
    if (has_m_argsm()) {
      if (m_argsm_ != &::google::protobuf::internal::kEmptyString) {
        m_argsm_->clear();
      }
    }
    m_functionunlock_ = 0;
    if (has_m_linknpc()) {
      if (m_linknpc_ != &::google::protobuf::internal::kEmptyString) {
        m_linknpc_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool E_LinkLink::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 m_id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &m_id_)));
          set_has_m_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_m_icon;
        break;
      }

      // optional string m_icon = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_m_icon:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_m_icon()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->m_icon().data(), this->m_icon().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_m_dbargs;
        break;
      }

      // optional string m_dbargs = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_m_dbargs:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_m_dbargs()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->m_dbargs().data(), this->m_dbargs().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_m_argsm;
        break;
      }

      // optional string m_argsm = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_m_argsm:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_m_argsm()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->m_argsm().data(), this->m_argsm().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_m_functionunlock;
        break;
      }

      // optional int32 m_functionunlock = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_functionunlock:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_functionunlock_)));
          set_has_m_functionunlock();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_m_linknpc;
        break;
      }

      // optional string m_linknpc = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_m_linknpc:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_m_linknpc()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->m_linknpc().data(), this->m_linknpc().length(),
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

void E_LinkLink::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 m_id = 1;
  if (has_m_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->m_id(), output);
  }

  // optional string m_icon = 2;
  if (has_m_icon()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_icon().data(), this->m_icon().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->m_icon(), output);
  }

  // optional string m_dbargs = 3;
  if (has_m_dbargs()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_dbargs().data(), this->m_dbargs().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->m_dbargs(), output);
  }

  // optional string m_argsm = 4;
  if (has_m_argsm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_argsm().data(), this->m_argsm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->m_argsm(), output);
  }

  // optional int32 m_functionunlock = 5;
  if (has_m_functionunlock()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->m_functionunlock(), output);
  }

  // optional string m_linknpc = 6;
  if (has_m_linknpc()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_linknpc().data(), this->m_linknpc().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      6, this->m_linknpc(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* E_LinkLink::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 m_id = 1;
  if (has_m_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->m_id(), target);
  }

  // optional string m_icon = 2;
  if (has_m_icon()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_icon().data(), this->m_icon().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->m_icon(), target);
  }

  // optional string m_dbargs = 3;
  if (has_m_dbargs()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_dbargs().data(), this->m_dbargs().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->m_dbargs(), target);
  }

  // optional string m_argsm = 4;
  if (has_m_argsm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_argsm().data(), this->m_argsm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->m_argsm(), target);
  }

  // optional int32 m_functionunlock = 5;
  if (has_m_functionunlock()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->m_functionunlock(), target);
  }

  // optional string m_linknpc = 6;
  if (has_m_linknpc()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->m_linknpc().data(), this->m_linknpc().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->m_linknpc(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int E_LinkLink::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 m_id = 1;
    if (has_m_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->m_id());
    }

    // optional string m_icon = 2;
    if (has_m_icon()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->m_icon());
    }

    // optional string m_dbargs = 3;
    if (has_m_dbargs()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->m_dbargs());
    }

    // optional string m_argsm = 4;
    if (has_m_argsm()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->m_argsm());
    }

    // optional int32 m_functionunlock = 5;
    if (has_m_functionunlock()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_functionunlock());
    }

    // optional string m_linknpc = 6;
    if (has_m_linknpc()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->m_linknpc());
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

void E_LinkLink::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const E_LinkLink* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const E_LinkLink*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void E_LinkLink::MergeFrom(const E_LinkLink& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_m_id()) {
      set_m_id(from.m_id());
    }
    if (from.has_m_icon()) {
      set_m_icon(from.m_icon());
    }
    if (from.has_m_dbargs()) {
      set_m_dbargs(from.m_dbargs());
    }
    if (from.has_m_argsm()) {
      set_m_argsm(from.m_argsm());
    }
    if (from.has_m_functionunlock()) {
      set_m_functionunlock(from.m_functionunlock());
    }
    if (from.has_m_linknpc()) {
      set_m_linknpc(from.m_linknpc());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void E_LinkLink::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void E_LinkLink::CopyFrom(const E_LinkLink& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool E_LinkLink::IsInitialized() const {

  return true;
}

void E_LinkLink::Swap(E_LinkLink* other) {
  if (other != this) {
    std::swap(m_id_, other->m_id_);
    std::swap(m_icon_, other->m_icon_);
    std::swap(m_dbargs_, other->m_dbargs_);
    std::swap(m_argsm_, other->m_argsm_);
    std::swap(m_functionunlock_, other->m_functionunlock_);
    std::swap(m_linknpc_, other->m_linknpc_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata E_LinkLink::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = E_LinkLink_descriptor_;
  metadata.reflection = E_LinkLink_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Sheet_LinkLink::kELinkLinkListFieldNumber;
#endif  // !_MSC_VER

Sheet_LinkLink::Sheet_LinkLink()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Sheet_LinkLink::InitAsDefaultInstance() {
}

Sheet_LinkLink::Sheet_LinkLink(const Sheet_LinkLink& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Sheet_LinkLink::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Sheet_LinkLink::~Sheet_LinkLink() {
  SharedDtor();
}

void Sheet_LinkLink::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Sheet_LinkLink::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Sheet_LinkLink::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Sheet_LinkLink_descriptor_;
}

const Sheet_LinkLink& Sheet_LinkLink::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fLink_2eproto();
  return *default_instance_;
}

Sheet_LinkLink* Sheet_LinkLink::default_instance_ = NULL;

Sheet_LinkLink* Sheet_LinkLink::New() const {
  return new Sheet_LinkLink;
}

void Sheet_LinkLink::Clear() {
  e_linklink_list_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Sheet_LinkLink::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto_ff.E_LinkLink E_LinkLink_List = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_E_LinkLink_List:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_e_linklink_list()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_E_LinkLink_List;
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

void Sheet_LinkLink::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .proto_ff.E_LinkLink E_LinkLink_List = 1;
  for (int i = 0; i < this->e_linklink_list_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->e_linklink_list(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Sheet_LinkLink::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .proto_ff.E_LinkLink E_LinkLink_List = 1;
  for (int i = 0; i < this->e_linklink_list_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->e_linklink_list(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Sheet_LinkLink::ByteSize() const {
  int total_size = 0;

  // repeated .proto_ff.E_LinkLink E_LinkLink_List = 1;
  total_size += 1 * this->e_linklink_list_size();
  for (int i = 0; i < this->e_linklink_list_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->e_linklink_list(i));
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

void Sheet_LinkLink::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Sheet_LinkLink* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Sheet_LinkLink*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Sheet_LinkLink::MergeFrom(const Sheet_LinkLink& from) {
  GOOGLE_CHECK_NE(&from, this);
  e_linklink_list_.MergeFrom(from.e_linklink_list_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Sheet_LinkLink::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sheet_LinkLink::CopyFrom(const Sheet_LinkLink& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sheet_LinkLink::IsInitialized() const {

  return true;
}

void Sheet_LinkLink::Swap(Sheet_LinkLink* other) {
  if (other != this) {
    e_linklink_list_.Swap(&other->e_linklink_list_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Sheet_LinkLink::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Sheet_LinkLink_descriptor_;
  metadata.reflection = Sheet_LinkLink_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
