// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Qypeak.proto

#ifndef PROTOBUF_E_5fQypeak_2eproto__INCLUDED
#define PROTOBUF_E_5fQypeak_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fQypeak_2eproto();
void protobuf_AssignDesc_E_5fQypeak_2eproto();
void protobuf_ShutdownFile_E_5fQypeak_2eproto();

class E_QypeakBack;
class Sheet_QypeakBack;
class E_QypeakConstant;
class Sheet_QypeakConstant;

// ===================================================================

class E_QypeakBack : public ::google::protobuf::Message {
 public:
  E_QypeakBack();
  virtual ~E_QypeakBack();

  E_QypeakBack(const E_QypeakBack& from);

  inline E_QypeakBack& operator=(const E_QypeakBack& from) {
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
  static const E_QypeakBack& default_instance();

  void Swap(E_QypeakBack* other);

  // implements Message ----------------------------------------------

  E_QypeakBack* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_QypeakBack& from);
  void MergeFrom(const E_QypeakBack& from);
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

  // optional int32 m_layers = 1;
  inline bool has_m_layers() const;
  inline void clear_m_layers();
  static const int kMLayersFieldNumber = 1;
  inline ::google::protobuf::int32 m_layers() const;
  inline void set_m_layers(::google::protobuf::int32 value);

  // optional int32 m_skillNum = 2;
  inline bool has_m_skillnum() const;
  inline void clear_m_skillnum();
  static const int kMSkillNumFieldNumber = 2;
  inline ::google::protobuf::int32 m_skillnum() const;
  inline void set_m_skillnum(::google::protobuf::int32 value);

  // optional int32 m_reward = 3;
  inline bool has_m_reward() const;
  inline void clear_m_reward();
  static const int kMRewardFieldNumber = 3;
  inline ::google::protobuf::int32 m_reward() const;
  inline void set_m_reward(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_QypeakBack)
 private:
  inline void set_has_m_layers();
  inline void clear_has_m_layers();
  inline void set_has_m_skillnum();
  inline void clear_has_m_skillnum();
  inline void set_has_m_reward();
  inline void clear_has_m_reward();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_layers_;
  ::google::protobuf::int32 m_skillnum_;
  ::google::protobuf::int32 m_reward_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fQypeak_2eproto();
  friend void protobuf_AssignDesc_E_5fQypeak_2eproto();
  friend void protobuf_ShutdownFile_E_5fQypeak_2eproto();

  void InitAsDefaultInstance();
  static E_QypeakBack* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_QypeakBack : public ::google::protobuf::Message {
 public:
  Sheet_QypeakBack();
  virtual ~Sheet_QypeakBack();

  Sheet_QypeakBack(const Sheet_QypeakBack& from);

  inline Sheet_QypeakBack& operator=(const Sheet_QypeakBack& from) {
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
  static const Sheet_QypeakBack& default_instance();

  void Swap(Sheet_QypeakBack* other);

  // implements Message ----------------------------------------------

  Sheet_QypeakBack* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_QypeakBack& from);
  void MergeFrom(const Sheet_QypeakBack& from);
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

  // repeated .proto_ff.E_QypeakBack E_QypeakBack_List = 1;
  inline int e_qypeakback_list_size() const;
  inline void clear_e_qypeakback_list();
  static const int kEQypeakBackListFieldNumber = 1;
  inline const ::proto_ff::E_QypeakBack& e_qypeakback_list(int index) const;
  inline ::proto_ff::E_QypeakBack* mutable_e_qypeakback_list(int index);
  inline ::proto_ff::E_QypeakBack* add_e_qypeakback_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakBack >&
      e_qypeakback_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakBack >*
      mutable_e_qypeakback_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_QypeakBack)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakBack > e_qypeakback_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fQypeak_2eproto();
  friend void protobuf_AssignDesc_E_5fQypeak_2eproto();
  friend void protobuf_ShutdownFile_E_5fQypeak_2eproto();

  void InitAsDefaultInstance();
  static Sheet_QypeakBack* default_instance_;
};
// -------------------------------------------------------------------

class E_QypeakConstant : public ::google::protobuf::Message {
 public:
  E_QypeakConstant();
  virtual ~E_QypeakConstant();

  E_QypeakConstant(const E_QypeakConstant& from);

  inline E_QypeakConstant& operator=(const E_QypeakConstant& from) {
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
  static const E_QypeakConstant& default_instance();

  void Swap(E_QypeakConstant* other);

  // implements Message ----------------------------------------------

  E_QypeakConstant* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_QypeakConstant& from);
  void MergeFrom(const E_QypeakConstant& from);
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

  // optional int32 m_id = 1;
  inline bool has_m_id() const;
  inline void clear_m_id();
  static const int kMIdFieldNumber = 1;
  inline ::google::protobuf::int32 m_id() const;
  inline void set_m_id(::google::protobuf::int32 value);

  // optional int32 m_mapid = 2;
  inline bool has_m_mapid() const;
  inline void clear_m_mapid();
  static const int kMMapidFieldNumber = 2;
  inline ::google::protobuf::int32 m_mapid() const;
  inline void set_m_mapid(::google::protobuf::int32 value);

  // optional int32 m_revivalBuff = 3;
  inline bool has_m_revivalbuff() const;
  inline void clear_m_revivalbuff();
  static const int kMRevivalBuffFieldNumber = 3;
  inline ::google::protobuf::int32 m_revivalbuff() const;
  inline void set_m_revivalbuff(::google::protobuf::int32 value);

  // repeated int32 m_rankreward = 4;
  inline int m_rankreward_size() const;
  inline void clear_m_rankreward();
  static const int kMRankrewardFieldNumber = 4;
  inline ::google::protobuf::int32 m_rankreward(int index) const;
  inline void set_m_rankreward(int index, ::google::protobuf::int32 value);
  inline void add_m_rankreward(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      m_rankreward() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_m_rankreward();

  // repeated int32 m_titleshow = 5;
  inline int m_titleshow_size() const;
  inline void clear_m_titleshow();
  static const int kMTitleshowFieldNumber = 5;
  inline ::google::protobuf::int32 m_titleshow(int index) const;
  inline void set_m_titleshow(int index, ::google::protobuf::int32 value);
  inline void add_m_titleshow(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      m_titleshow() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_m_titleshow();

  // @@protoc_insertion_point(class_scope:proto_ff.E_QypeakConstant)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_mapid();
  inline void clear_has_m_mapid();
  inline void set_has_m_revivalbuff();
  inline void clear_has_m_revivalbuff();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_id_;
  ::google::protobuf::int32 m_mapid_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > m_rankreward_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > m_titleshow_;
  ::google::protobuf::int32 m_revivalbuff_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fQypeak_2eproto();
  friend void protobuf_AssignDesc_E_5fQypeak_2eproto();
  friend void protobuf_ShutdownFile_E_5fQypeak_2eproto();

  void InitAsDefaultInstance();
  static E_QypeakConstant* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_QypeakConstant : public ::google::protobuf::Message {
 public:
  Sheet_QypeakConstant();
  virtual ~Sheet_QypeakConstant();

  Sheet_QypeakConstant(const Sheet_QypeakConstant& from);

  inline Sheet_QypeakConstant& operator=(const Sheet_QypeakConstant& from) {
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
  static const Sheet_QypeakConstant& default_instance();

  void Swap(Sheet_QypeakConstant* other);

  // implements Message ----------------------------------------------

  Sheet_QypeakConstant* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_QypeakConstant& from);
  void MergeFrom(const Sheet_QypeakConstant& from);
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

  // repeated .proto_ff.E_QypeakConstant E_QypeakConstant_List = 1;
  inline int e_qypeakconstant_list_size() const;
  inline void clear_e_qypeakconstant_list();
  static const int kEQypeakConstantListFieldNumber = 1;
  inline const ::proto_ff::E_QypeakConstant& e_qypeakconstant_list(int index) const;
  inline ::proto_ff::E_QypeakConstant* mutable_e_qypeakconstant_list(int index);
  inline ::proto_ff::E_QypeakConstant* add_e_qypeakconstant_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakConstant >&
      e_qypeakconstant_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakConstant >*
      mutable_e_qypeakconstant_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_QypeakConstant)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakConstant > e_qypeakconstant_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fQypeak_2eproto();
  friend void protobuf_AssignDesc_E_5fQypeak_2eproto();
  friend void protobuf_ShutdownFile_E_5fQypeak_2eproto();

  void InitAsDefaultInstance();
  static Sheet_QypeakConstant* default_instance_;
};
// ===================================================================


// ===================================================================

// E_QypeakBack

// optional int32 m_layers = 1;
inline bool E_QypeakBack::has_m_layers() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_QypeakBack::set_has_m_layers() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_QypeakBack::clear_has_m_layers() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_QypeakBack::clear_m_layers() {
  m_layers_ = 0;
  clear_has_m_layers();
}
inline ::google::protobuf::int32 E_QypeakBack::m_layers() const {
  return m_layers_;
}
inline void E_QypeakBack::set_m_layers(::google::protobuf::int32 value) {
  set_has_m_layers();
  m_layers_ = value;
}

// optional int32 m_skillNum = 2;
inline bool E_QypeakBack::has_m_skillnum() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_QypeakBack::set_has_m_skillnum() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_QypeakBack::clear_has_m_skillnum() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_QypeakBack::clear_m_skillnum() {
  m_skillnum_ = 0;
  clear_has_m_skillnum();
}
inline ::google::protobuf::int32 E_QypeakBack::m_skillnum() const {
  return m_skillnum_;
}
inline void E_QypeakBack::set_m_skillnum(::google::protobuf::int32 value) {
  set_has_m_skillnum();
  m_skillnum_ = value;
}

// optional int32 m_reward = 3;
inline bool E_QypeakBack::has_m_reward() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_QypeakBack::set_has_m_reward() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_QypeakBack::clear_has_m_reward() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_QypeakBack::clear_m_reward() {
  m_reward_ = 0;
  clear_has_m_reward();
}
inline ::google::protobuf::int32 E_QypeakBack::m_reward() const {
  return m_reward_;
}
inline void E_QypeakBack::set_m_reward(::google::protobuf::int32 value) {
  set_has_m_reward();
  m_reward_ = value;
}

// -------------------------------------------------------------------

// Sheet_QypeakBack

// repeated .proto_ff.E_QypeakBack E_QypeakBack_List = 1;
inline int Sheet_QypeakBack::e_qypeakback_list_size() const {
  return e_qypeakback_list_.size();
}
inline void Sheet_QypeakBack::clear_e_qypeakback_list() {
  e_qypeakback_list_.Clear();
}
inline const ::proto_ff::E_QypeakBack& Sheet_QypeakBack::e_qypeakback_list(int index) const {
  return e_qypeakback_list_.Get(index);
}
inline ::proto_ff::E_QypeakBack* Sheet_QypeakBack::mutable_e_qypeakback_list(int index) {
  return e_qypeakback_list_.Mutable(index);
}
inline ::proto_ff::E_QypeakBack* Sheet_QypeakBack::add_e_qypeakback_list() {
  return e_qypeakback_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakBack >&
Sheet_QypeakBack::e_qypeakback_list() const {
  return e_qypeakback_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakBack >*
Sheet_QypeakBack::mutable_e_qypeakback_list() {
  return &e_qypeakback_list_;
}

// -------------------------------------------------------------------

// E_QypeakConstant

// optional int32 m_id = 1;
inline bool E_QypeakConstant::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_QypeakConstant::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_QypeakConstant::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_QypeakConstant::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_QypeakConstant::m_id() const {
  return m_id_;
}
inline void E_QypeakConstant::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_mapid = 2;
inline bool E_QypeakConstant::has_m_mapid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_QypeakConstant::set_has_m_mapid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_QypeakConstant::clear_has_m_mapid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_QypeakConstant::clear_m_mapid() {
  m_mapid_ = 0;
  clear_has_m_mapid();
}
inline ::google::protobuf::int32 E_QypeakConstant::m_mapid() const {
  return m_mapid_;
}
inline void E_QypeakConstant::set_m_mapid(::google::protobuf::int32 value) {
  set_has_m_mapid();
  m_mapid_ = value;
}

// optional int32 m_revivalBuff = 3;
inline bool E_QypeakConstant::has_m_revivalbuff() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_QypeakConstant::set_has_m_revivalbuff() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_QypeakConstant::clear_has_m_revivalbuff() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_QypeakConstant::clear_m_revivalbuff() {
  m_revivalbuff_ = 0;
  clear_has_m_revivalbuff();
}
inline ::google::protobuf::int32 E_QypeakConstant::m_revivalbuff() const {
  return m_revivalbuff_;
}
inline void E_QypeakConstant::set_m_revivalbuff(::google::protobuf::int32 value) {
  set_has_m_revivalbuff();
  m_revivalbuff_ = value;
}

// repeated int32 m_rankreward = 4;
inline int E_QypeakConstant::m_rankreward_size() const {
  return m_rankreward_.size();
}
inline void E_QypeakConstant::clear_m_rankreward() {
  m_rankreward_.Clear();
}
inline ::google::protobuf::int32 E_QypeakConstant::m_rankreward(int index) const {
  return m_rankreward_.Get(index);
}
inline void E_QypeakConstant::set_m_rankreward(int index, ::google::protobuf::int32 value) {
  m_rankreward_.Set(index, value);
}
inline void E_QypeakConstant::add_m_rankreward(::google::protobuf::int32 value) {
  m_rankreward_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
E_QypeakConstant::m_rankreward() const {
  return m_rankreward_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
E_QypeakConstant::mutable_m_rankreward() {
  return &m_rankreward_;
}

// repeated int32 m_titleshow = 5;
inline int E_QypeakConstant::m_titleshow_size() const {
  return m_titleshow_.size();
}
inline void E_QypeakConstant::clear_m_titleshow() {
  m_titleshow_.Clear();
}
inline ::google::protobuf::int32 E_QypeakConstant::m_titleshow(int index) const {
  return m_titleshow_.Get(index);
}
inline void E_QypeakConstant::set_m_titleshow(int index, ::google::protobuf::int32 value) {
  m_titleshow_.Set(index, value);
}
inline void E_QypeakConstant::add_m_titleshow(::google::protobuf::int32 value) {
  m_titleshow_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
E_QypeakConstant::m_titleshow() const {
  return m_titleshow_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
E_QypeakConstant::mutable_m_titleshow() {
  return &m_titleshow_;
}

// -------------------------------------------------------------------

// Sheet_QypeakConstant

// repeated .proto_ff.E_QypeakConstant E_QypeakConstant_List = 1;
inline int Sheet_QypeakConstant::e_qypeakconstant_list_size() const {
  return e_qypeakconstant_list_.size();
}
inline void Sheet_QypeakConstant::clear_e_qypeakconstant_list() {
  e_qypeakconstant_list_.Clear();
}
inline const ::proto_ff::E_QypeakConstant& Sheet_QypeakConstant::e_qypeakconstant_list(int index) const {
  return e_qypeakconstant_list_.Get(index);
}
inline ::proto_ff::E_QypeakConstant* Sheet_QypeakConstant::mutable_e_qypeakconstant_list(int index) {
  return e_qypeakconstant_list_.Mutable(index);
}
inline ::proto_ff::E_QypeakConstant* Sheet_QypeakConstant::add_e_qypeakconstant_list() {
  return e_qypeakconstant_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakConstant >&
Sheet_QypeakConstant::e_qypeakconstant_list() const {
  return e_qypeakconstant_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_QypeakConstant >*
Sheet_QypeakConstant::mutable_e_qypeakconstant_list() {
  return &e_qypeakconstant_list_;
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

#endif  // PROTOBUF_E_5fQypeak_2eproto__INCLUDED
