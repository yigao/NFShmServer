// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: back.proto

#ifndef PROTOBUF_back_2eproto__INCLUDED
#define PROTOBUF_back_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "yd_fieldoptions.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_back_2eproto();
void protobuf_AssignDesc_back_2eproto();
void protobuf_ShutdownFile_back_2eproto();

class backback;
class Sheet_backback;

// ===================================================================

class backback : public ::google::protobuf::Message {
 public:
  backback();
  virtual ~backback();

  backback(const backback& from);

  inline backback& operator=(const backback& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const backback& default_instance();

  void Swap(backback* other);

  // implements Message ----------------------------------------------

  backback* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const backback& from);
  void MergeFrom(const backback& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // optional int32 type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // optional int32 typeParam = 3;
  inline bool has_typeparam() const;
  inline void clear_typeparam();
  static const int kTypeParamFieldNumber = 3;
  inline ::google::protobuf::int32 typeparam() const;
  inline void set_typeparam(::google::protobuf::int32 value);

  // optional string name = 4;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 4;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional int32 group = 5;
  inline bool has_group() const;
  inline void clear_group();
  static const int kGroupFieldNumber = 5;
  inline ::google::protobuf::int32 group() const;
  inline void set_group(::google::protobuf::int32 value);

  // optional int32 functionUnlock = 6;
  inline bool has_functionunlock() const;
  inline void clear_functionunlock();
  static const int kFunctionUnlockFieldNumber = 6;
  inline ::google::protobuf::int32 functionunlock() const;
  inline void set_functionunlock(::google::protobuf::int32 value);

  // optional int32 levelLimit = 7;
  inline bool has_levellimit() const;
  inline void clear_levellimit();
  static const int kLevelLimitFieldNumber = 7;
  inline ::google::protobuf::int32 levellimit() const;
  inline void set_levellimit(::google::protobuf::int32 value);

  // optional int64 PboxId = 8;
  inline bool has_pboxid() const;
  inline void clear_pboxid();
  static const int kPboxIdFieldNumber = 8;
  inline ::google::protobuf::int64 pboxid() const;
  inline void set_pboxid(::google::protobuf::int64 value);

  // optional int64 boxId = 9;
  inline bool has_boxid() const;
  inline void clear_boxid();
  static const int kBoxIdFieldNumber = 9;
  inline ::google::protobuf::int64 boxid() const;
  inline void set_boxid(::google::protobuf::int64 value);

  // optional int32 backDay = 10;
  inline bool has_backday() const;
  inline void clear_backday();
  static const int kBackDayFieldNumber = 10;
  inline ::google::protobuf::int32 backday() const;
  inline void set_backday(::google::protobuf::int32 value);

  // optional int32 costItemID = 11;
  inline bool has_costitemid() const;
  inline void clear_costitemid();
  static const int kCostItemIDFieldNumber = 11;
  inline ::google::protobuf::int32 costitemid() const;
  inline void set_costitemid(::google::protobuf::int32 value);

  // optional int32 costNum = 12;
  inline bool has_costnum() const;
  inline void clear_costnum();
  static const int kCostNumFieldNumber = 12;
  inline ::google::protobuf::int32 costnum() const;
  inline void set_costnum(::google::protobuf::int32 value);

  // optional int32 PcostItemID = 13;
  inline bool has_pcostitemid() const;
  inline void clear_pcostitemid();
  static const int kPcostItemIDFieldNumber = 13;
  inline ::google::protobuf::int32 pcostitemid() const;
  inline void set_pcostitemid(::google::protobuf::int32 value);

  // optional int32 PcostNum = 14;
  inline bool has_pcostnum() const;
  inline void clear_pcostnum();
  static const int kPcostNumFieldNumber = 14;
  inline ::google::protobuf::int32 pcostnum() const;
  inline void set_pcostnum(::google::protobuf::int32 value);

  // optional int32 AcostItemID = 15;
  inline bool has_acostitemid() const;
  inline void clear_acostitemid();
  static const int kAcostItemIDFieldNumber = 15;
  inline ::google::protobuf::int32 acostitemid() const;
  inline void set_acostitemid(::google::protobuf::int32 value);

  // optional int32 AcostNum = 16;
  inline bool has_acostnum() const;
  inline void clear_acostnum();
  static const int kAcostNumFieldNumber = 16;
  inline ::google::protobuf::int32 acostnum() const;
  inline void set_acostnum(::google::protobuf::int32 value);

  // repeated int32 param = 17;
  inline int param_size() const;
  inline void clear_param();
  static const int kParamFieldNumber = 17;
  inline ::google::protobuf::int32 param(int index) const;
  inline void set_param(int index, ::google::protobuf::int32 value);
  inline void add_param(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      param() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_param();

  // @@protoc_insertion_point(class_scope:proto_ff.backback)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_typeparam();
  inline void clear_has_typeparam();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_group();
  inline void clear_has_group();
  inline void set_has_functionunlock();
  inline void clear_has_functionunlock();
  inline void set_has_levellimit();
  inline void clear_has_levellimit();
  inline void set_has_pboxid();
  inline void clear_has_pboxid();
  inline void set_has_boxid();
  inline void clear_has_boxid();
  inline void set_has_backday();
  inline void clear_has_backday();
  inline void set_has_costitemid();
  inline void clear_has_costitemid();
  inline void set_has_costnum();
  inline void clear_has_costnum();
  inline void set_has_pcostitemid();
  inline void clear_has_pcostitemid();
  inline void set_has_pcostnum();
  inline void clear_has_pcostnum();
  inline void set_has_acostitemid();
  inline void clear_has_acostitemid();
  inline void set_has_acostnum();
  inline void clear_has_acostnum();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 type_;
  ::std::string* name_;
  ::google::protobuf::int32 typeparam_;
  ::google::protobuf::int32 group_;
  ::google::protobuf::int32 functionunlock_;
  ::google::protobuf::int32 levellimit_;
  ::google::protobuf::int64 pboxid_;
  ::google::protobuf::int64 boxid_;
  ::google::protobuf::int32 backday_;
  ::google::protobuf::int32 costitemid_;
  ::google::protobuf::int32 costnum_;
  ::google::protobuf::int32 pcostitemid_;
  ::google::protobuf::int32 pcostnum_;
  ::google::protobuf::int32 acostitemid_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > param_;
  ::google::protobuf::int32 acostnum_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(17 + 31) / 32];

  friend void  protobuf_AddDesc_back_2eproto();
  friend void protobuf_AssignDesc_back_2eproto();
  friend void protobuf_ShutdownFile_back_2eproto();

  void InitAsDefaultInstance();
  static backback* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_backback : public ::google::protobuf::Message {
 public:
  Sheet_backback();
  virtual ~Sheet_backback();

  Sheet_backback(const Sheet_backback& from);

  inline Sheet_backback& operator=(const Sheet_backback& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Sheet_backback& default_instance();

  void Swap(Sheet_backback* other);

  // implements Message ----------------------------------------------

  Sheet_backback* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_backback& from);
  void MergeFrom(const Sheet_backback& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .proto_ff.backback backback_List = 1;
  inline int backback_list_size() const;
  inline void clear_backback_list();
  static const int kBackbackListFieldNumber = 1;
  inline const ::proto_ff::backback& backback_list(int index) const;
  inline ::proto_ff::backback* mutable_backback_list(int index);
  inline ::proto_ff::backback* add_backback_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::backback >&
      backback_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::backback >*
      mutable_backback_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_backback)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::backback > backback_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_back_2eproto();
  friend void protobuf_AssignDesc_back_2eproto();
  friend void protobuf_ShutdownFile_back_2eproto();

  void InitAsDefaultInstance();
  static Sheet_backback* default_instance_;
};
// ===================================================================


// ===================================================================

// backback

// optional int32 id = 1;
inline bool backback::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void backback::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void backback::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void backback::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 backback::id() const {
  return id_;
}
inline void backback::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}

// optional int32 type = 2;
inline bool backback::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void backback::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void backback::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void backback::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 backback::type() const {
  return type_;
}
inline void backback::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// optional int32 typeParam = 3;
inline bool backback::has_typeparam() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void backback::set_has_typeparam() {
  _has_bits_[0] |= 0x00000004u;
}
inline void backback::clear_has_typeparam() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void backback::clear_typeparam() {
  typeparam_ = 0;
  clear_has_typeparam();
}
inline ::google::protobuf::int32 backback::typeparam() const {
  return typeparam_;
}
inline void backback::set_typeparam(::google::protobuf::int32 value) {
  set_has_typeparam();
  typeparam_ = value;
}

// optional string name = 4;
inline bool backback::has_name() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void backback::set_has_name() {
  _has_bits_[0] |= 0x00000008u;
}
inline void backback::clear_has_name() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void backback::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& backback::name() const {
  return *name_;
}
inline void backback::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void backback::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void backback::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* backback::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* backback::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void backback::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 group = 5;
inline bool backback::has_group() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void backback::set_has_group() {
  _has_bits_[0] |= 0x00000010u;
}
inline void backback::clear_has_group() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void backback::clear_group() {
  group_ = 0;
  clear_has_group();
}
inline ::google::protobuf::int32 backback::group() const {
  return group_;
}
inline void backback::set_group(::google::protobuf::int32 value) {
  set_has_group();
  group_ = value;
}

// optional int32 functionUnlock = 6;
inline bool backback::has_functionunlock() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void backback::set_has_functionunlock() {
  _has_bits_[0] |= 0x00000020u;
}
inline void backback::clear_has_functionunlock() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void backback::clear_functionunlock() {
  functionunlock_ = 0;
  clear_has_functionunlock();
}
inline ::google::protobuf::int32 backback::functionunlock() const {
  return functionunlock_;
}
inline void backback::set_functionunlock(::google::protobuf::int32 value) {
  set_has_functionunlock();
  functionunlock_ = value;
}

// optional int32 levelLimit = 7;
inline bool backback::has_levellimit() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void backback::set_has_levellimit() {
  _has_bits_[0] |= 0x00000040u;
}
inline void backback::clear_has_levellimit() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void backback::clear_levellimit() {
  levellimit_ = 0;
  clear_has_levellimit();
}
inline ::google::protobuf::int32 backback::levellimit() const {
  return levellimit_;
}
inline void backback::set_levellimit(::google::protobuf::int32 value) {
  set_has_levellimit();
  levellimit_ = value;
}

// optional int64 PboxId = 8;
inline bool backback::has_pboxid() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void backback::set_has_pboxid() {
  _has_bits_[0] |= 0x00000080u;
}
inline void backback::clear_has_pboxid() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void backback::clear_pboxid() {
  pboxid_ = GOOGLE_LONGLONG(0);
  clear_has_pboxid();
}
inline ::google::protobuf::int64 backback::pboxid() const {
  return pboxid_;
}
inline void backback::set_pboxid(::google::protobuf::int64 value) {
  set_has_pboxid();
  pboxid_ = value;
}

// optional int64 boxId = 9;
inline bool backback::has_boxid() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void backback::set_has_boxid() {
  _has_bits_[0] |= 0x00000100u;
}
inline void backback::clear_has_boxid() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void backback::clear_boxid() {
  boxid_ = GOOGLE_LONGLONG(0);
  clear_has_boxid();
}
inline ::google::protobuf::int64 backback::boxid() const {
  return boxid_;
}
inline void backback::set_boxid(::google::protobuf::int64 value) {
  set_has_boxid();
  boxid_ = value;
}

// optional int32 backDay = 10;
inline bool backback::has_backday() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void backback::set_has_backday() {
  _has_bits_[0] |= 0x00000200u;
}
inline void backback::clear_has_backday() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void backback::clear_backday() {
  backday_ = 0;
  clear_has_backday();
}
inline ::google::protobuf::int32 backback::backday() const {
  return backday_;
}
inline void backback::set_backday(::google::protobuf::int32 value) {
  set_has_backday();
  backday_ = value;
}

// optional int32 costItemID = 11;
inline bool backback::has_costitemid() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void backback::set_has_costitemid() {
  _has_bits_[0] |= 0x00000400u;
}
inline void backback::clear_has_costitemid() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void backback::clear_costitemid() {
  costitemid_ = 0;
  clear_has_costitemid();
}
inline ::google::protobuf::int32 backback::costitemid() const {
  return costitemid_;
}
inline void backback::set_costitemid(::google::protobuf::int32 value) {
  set_has_costitemid();
  costitemid_ = value;
}

// optional int32 costNum = 12;
inline bool backback::has_costnum() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void backback::set_has_costnum() {
  _has_bits_[0] |= 0x00000800u;
}
inline void backback::clear_has_costnum() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void backback::clear_costnum() {
  costnum_ = 0;
  clear_has_costnum();
}
inline ::google::protobuf::int32 backback::costnum() const {
  return costnum_;
}
inline void backback::set_costnum(::google::protobuf::int32 value) {
  set_has_costnum();
  costnum_ = value;
}

// optional int32 PcostItemID = 13;
inline bool backback::has_pcostitemid() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void backback::set_has_pcostitemid() {
  _has_bits_[0] |= 0x00001000u;
}
inline void backback::clear_has_pcostitemid() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void backback::clear_pcostitemid() {
  pcostitemid_ = 0;
  clear_has_pcostitemid();
}
inline ::google::protobuf::int32 backback::pcostitemid() const {
  return pcostitemid_;
}
inline void backback::set_pcostitemid(::google::protobuf::int32 value) {
  set_has_pcostitemid();
  pcostitemid_ = value;
}

// optional int32 PcostNum = 14;
inline bool backback::has_pcostnum() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void backback::set_has_pcostnum() {
  _has_bits_[0] |= 0x00002000u;
}
inline void backback::clear_has_pcostnum() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void backback::clear_pcostnum() {
  pcostnum_ = 0;
  clear_has_pcostnum();
}
inline ::google::protobuf::int32 backback::pcostnum() const {
  return pcostnum_;
}
inline void backback::set_pcostnum(::google::protobuf::int32 value) {
  set_has_pcostnum();
  pcostnum_ = value;
}

// optional int32 AcostItemID = 15;
inline bool backback::has_acostitemid() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void backback::set_has_acostitemid() {
  _has_bits_[0] |= 0x00004000u;
}
inline void backback::clear_has_acostitemid() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void backback::clear_acostitemid() {
  acostitemid_ = 0;
  clear_has_acostitemid();
}
inline ::google::protobuf::int32 backback::acostitemid() const {
  return acostitemid_;
}
inline void backback::set_acostitemid(::google::protobuf::int32 value) {
  set_has_acostitemid();
  acostitemid_ = value;
}

// optional int32 AcostNum = 16;
inline bool backback::has_acostnum() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void backback::set_has_acostnum() {
  _has_bits_[0] |= 0x00008000u;
}
inline void backback::clear_has_acostnum() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void backback::clear_acostnum() {
  acostnum_ = 0;
  clear_has_acostnum();
}
inline ::google::protobuf::int32 backback::acostnum() const {
  return acostnum_;
}
inline void backback::set_acostnum(::google::protobuf::int32 value) {
  set_has_acostnum();
  acostnum_ = value;
}

// repeated int32 param = 17;
inline int backback::param_size() const {
  return param_.size();
}
inline void backback::clear_param() {
  param_.Clear();
}
inline ::google::protobuf::int32 backback::param(int index) const {
  return param_.Get(index);
}
inline void backback::set_param(int index, ::google::protobuf::int32 value) {
  param_.Set(index, value);
}
inline void backback::add_param(::google::protobuf::int32 value) {
  param_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
backback::param() const {
  return param_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
backback::mutable_param() {
  return &param_;
}

// -------------------------------------------------------------------

// Sheet_backback

// repeated .proto_ff.backback backback_List = 1;
inline int Sheet_backback::backback_list_size() const {
  return backback_list_.size();
}
inline void Sheet_backback::clear_backback_list() {
  backback_list_.Clear();
}
inline const ::proto_ff::backback& Sheet_backback::backback_list(int index) const {
  return backback_list_.Get(index);
}
inline ::proto_ff::backback* Sheet_backback::mutable_backback_list(int index) {
  return backback_list_.Mutable(index);
}
inline ::proto_ff::backback* Sheet_backback::add_backback_list() {
  return backback_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::backback >&
Sheet_backback::backback_list() const {
  return backback_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::backback >*
Sheet_backback::mutable_backback_list() {
  return &backback_list_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_back_2eproto__INCLUDED