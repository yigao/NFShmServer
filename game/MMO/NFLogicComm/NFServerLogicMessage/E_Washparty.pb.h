// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Washparty.proto

#ifndef PROTOBUF_E_5fWashparty_2eproto__INCLUDED
#define PROTOBUF_E_5fWashparty_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fWashparty_2eproto();
void protobuf_AssignDesc_E_5fWashparty_2eproto();
void protobuf_ShutdownFile_E_5fWashparty_2eproto();

class E_WashpartyWashparty;
class Sheet_WashpartyWashparty;
class E_WashpartyExp;
class Sheet_WashpartyExp;

// ===================================================================

class E_WashpartyWashparty : public ::google::protobuf::Message {
 public:
  E_WashpartyWashparty();
  virtual ~E_WashpartyWashparty();

  E_WashpartyWashparty(const E_WashpartyWashparty& from);

  inline E_WashpartyWashparty& operator=(const E_WashpartyWashparty& from) {
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
  static const E_WashpartyWashparty& default_instance();

  void Swap(E_WashpartyWashparty* other);

  // implements Message ----------------------------------------------

  E_WashpartyWashparty* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_WashpartyWashparty& from);
  void MergeFrom(const E_WashpartyWashparty& from);
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

  // optional int32 m_collectid = 2;
  inline bool has_m_collectid() const;
  inline void clear_m_collectid();
  static const int kMCollectidFieldNumber = 2;
  inline ::google::protobuf::int32 m_collectid() const;
  inline void set_m_collectid(::google::protobuf::int32 value);

  // optional int32 m_collectnum = 3;
  inline bool has_m_collectnum() const;
  inline void clear_m_collectnum();
  static const int kMCollectnumFieldNumber = 3;
  inline ::google::protobuf::int32 m_collectnum() const;
  inline void set_m_collectnum(::google::protobuf::int32 value);

  // optional int32 m_collectposid = 4;
  inline bool has_m_collectposid() const;
  inline void clear_m_collectposid();
  static const int kMCollectposidFieldNumber = 4;
  inline ::google::protobuf::int32 m_collectposid() const;
  inline void set_m_collectposid(::google::protobuf::int32 value);

  // optional int32 m_collectgeninterval = 5;
  inline bool has_m_collectgeninterval() const;
  inline void clear_m_collectgeninterval();
  static const int kMCollectgenintervalFieldNumber = 5;
  inline ::google::protobuf::int32 m_collectgeninterval() const;
  inline void set_m_collectgeninterval(::google::protobuf::int32 value);

  // optional int32 m_collectmax = 6;
  inline bool has_m_collectmax() const;
  inline void clear_m_collectmax();
  static const int kMCollectmaxFieldNumber = 6;
  inline ::google::protobuf::int32 m_collectmax() const;
  inline void set_m_collectmax(::google::protobuf::int32 value);

  // optional int32 m_splashnum = 7;
  inline bool has_m_splashnum() const;
  inline void clear_m_splashnum();
  static const int kMSplashnumFieldNumber = 7;
  inline ::google::protobuf::int32 m_splashnum() const;
  inline void set_m_splashnum(::google::protobuf::int32 value);

  // optional int32 m_splashreward = 8;
  inline bool has_m_splashreward() const;
  inline void clear_m_splashreward();
  static const int kMSplashrewardFieldNumber = 8;
  inline ::google::protobuf::int32 m_splashreward() const;
  inline void set_m_splashreward(::google::protobuf::int32 value);

  // optional int32 m_massagenum = 9;
  inline bool has_m_massagenum() const;
  inline void clear_m_massagenum();
  static const int kMMassagenumFieldNumber = 9;
  inline ::google::protobuf::int32 m_massagenum() const;
  inline void set_m_massagenum(::google::protobuf::int32 value);

  // optional int32 m_massagetime = 10;
  inline bool has_m_massagetime() const;
  inline void clear_m_massagetime();
  static const int kMMassagetimeFieldNumber = 10;
  inline ::google::protobuf::int32 m_massagetime() const;
  inline void set_m_massagetime(::google::protobuf::int32 value);

  // optional int32 m_massagereward = 11;
  inline bool has_m_massagereward() const;
  inline void clear_m_massagereward();
  static const int kMMassagerewardFieldNumber = 11;
  inline ::google::protobuf::int32 m_massagereward() const;
  inline void set_m_massagereward(::google::protobuf::int32 value);

  // optional int32 m_pairexpaddition = 12;
  inline bool has_m_pairexpaddition() const;
  inline void clear_m_pairexpaddition();
  static const int kMPairexpadditionFieldNumber = 12;
  inline ::google::protobuf::int32 m_pairexpaddition() const;
  inline void set_m_pairexpaddition(::google::protobuf::int32 value);

  // optional int32 m_mapid = 13;
  inline bool has_m_mapid() const;
  inline void clear_m_mapid();
  static const int kMMapidFieldNumber = 13;
  inline ::google::protobuf::int32 m_mapid() const;
  inline void set_m_mapid(::google::protobuf::int32 value);

  // optional int32 m_duration = 14;
  inline bool has_m_duration() const;
  inline void clear_m_duration();
  static const int kMDurationFieldNumber = 14;
  inline ::google::protobuf::int32 m_duration() const;
  inline void set_m_duration(::google::protobuf::int32 value);

  // optional int32 m_expaddinterval = 15;
  inline bool has_m_expaddinterval() const;
  inline void clear_m_expaddinterval();
  static const int kMExpaddintervalFieldNumber = 15;
  inline ::google::protobuf::int32 m_expaddinterval() const;
  inline void set_m_expaddinterval(::google::protobuf::int32 value);

  // optional int32 m_splashsi = 16;
  inline bool has_m_splashsi() const;
  inline void clear_m_splashsi();
  static const int kMSplashsiFieldNumber = 16;
  inline ::google::protobuf::int32 m_splashsi() const;
  inline void set_m_splashsi(::google::protobuf::int32 value);

  // optional int32 m_birthareaid = 17;
  inline bool has_m_birthareaid() const;
  inline void clear_m_birthareaid();
  static const int kMBirthareaidFieldNumber = 17;
  inline ::google::protobuf::int32 m_birthareaid() const;
  inline void set_m_birthareaid(::google::protobuf::int32 value);

  // optional int32 m_actid = 18;
  inline bool has_m_actid() const;
  inline void clear_m_actid();
  static const int kMActidFieldNumber = 18;
  inline ::google::protobuf::int32 m_actid() const;
  inline void set_m_actid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_WashpartyWashparty)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_collectid();
  inline void clear_has_m_collectid();
  inline void set_has_m_collectnum();
  inline void clear_has_m_collectnum();
  inline void set_has_m_collectposid();
  inline void clear_has_m_collectposid();
  inline void set_has_m_collectgeninterval();
  inline void clear_has_m_collectgeninterval();
  inline void set_has_m_collectmax();
  inline void clear_has_m_collectmax();
  inline void set_has_m_splashnum();
  inline void clear_has_m_splashnum();
  inline void set_has_m_splashreward();
  inline void clear_has_m_splashreward();
  inline void set_has_m_massagenum();
  inline void clear_has_m_massagenum();
  inline void set_has_m_massagetime();
  inline void clear_has_m_massagetime();
  inline void set_has_m_massagereward();
  inline void clear_has_m_massagereward();
  inline void set_has_m_pairexpaddition();
  inline void clear_has_m_pairexpaddition();
  inline void set_has_m_mapid();
  inline void clear_has_m_mapid();
  inline void set_has_m_duration();
  inline void clear_has_m_duration();
  inline void set_has_m_expaddinterval();
  inline void clear_has_m_expaddinterval();
  inline void set_has_m_splashsi();
  inline void clear_has_m_splashsi();
  inline void set_has_m_birthareaid();
  inline void clear_has_m_birthareaid();
  inline void set_has_m_actid();
  inline void clear_has_m_actid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_id_;
  ::google::protobuf::int32 m_collectid_;
  ::google::protobuf::int32 m_collectnum_;
  ::google::protobuf::int32 m_collectposid_;
  ::google::protobuf::int32 m_collectgeninterval_;
  ::google::protobuf::int32 m_collectmax_;
  ::google::protobuf::int32 m_splashnum_;
  ::google::protobuf::int32 m_splashreward_;
  ::google::protobuf::int32 m_massagenum_;
  ::google::protobuf::int32 m_massagetime_;
  ::google::protobuf::int32 m_massagereward_;
  ::google::protobuf::int32 m_pairexpaddition_;
  ::google::protobuf::int32 m_mapid_;
  ::google::protobuf::int32 m_duration_;
  ::google::protobuf::int32 m_expaddinterval_;
  ::google::protobuf::int32 m_splashsi_;
  ::google::protobuf::int32 m_birthareaid_;
  ::google::protobuf::int32 m_actid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(18 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fWashparty_2eproto();
  friend void protobuf_AssignDesc_E_5fWashparty_2eproto();
  friend void protobuf_ShutdownFile_E_5fWashparty_2eproto();

  void InitAsDefaultInstance();
  static E_WashpartyWashparty* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_WashpartyWashparty : public ::google::protobuf::Message {
 public:
  Sheet_WashpartyWashparty();
  virtual ~Sheet_WashpartyWashparty();

  Sheet_WashpartyWashparty(const Sheet_WashpartyWashparty& from);

  inline Sheet_WashpartyWashparty& operator=(const Sheet_WashpartyWashparty& from) {
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
  static const Sheet_WashpartyWashparty& default_instance();

  void Swap(Sheet_WashpartyWashparty* other);

  // implements Message ----------------------------------------------

  Sheet_WashpartyWashparty* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_WashpartyWashparty& from);
  void MergeFrom(const Sheet_WashpartyWashparty& from);
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

  // repeated .proto_ff.E_WashpartyWashparty E_WashpartyWashparty_List = 1;
  inline int e_washpartywashparty_list_size() const;
  inline void clear_e_washpartywashparty_list();
  static const int kEWashpartyWashpartyListFieldNumber = 1;
  inline const ::proto_ff::E_WashpartyWashparty& e_washpartywashparty_list(int index) const;
  inline ::proto_ff::E_WashpartyWashparty* mutable_e_washpartywashparty_list(int index);
  inline ::proto_ff::E_WashpartyWashparty* add_e_washpartywashparty_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyWashparty >&
      e_washpartywashparty_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyWashparty >*
      mutable_e_washpartywashparty_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_WashpartyWashparty)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyWashparty > e_washpartywashparty_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fWashparty_2eproto();
  friend void protobuf_AssignDesc_E_5fWashparty_2eproto();
  friend void protobuf_ShutdownFile_E_5fWashparty_2eproto();

  void InitAsDefaultInstance();
  static Sheet_WashpartyWashparty* default_instance_;
};
// -------------------------------------------------------------------

class E_WashpartyExp : public ::google::protobuf::Message {
 public:
  E_WashpartyExp();
  virtual ~E_WashpartyExp();

  E_WashpartyExp(const E_WashpartyExp& from);

  inline E_WashpartyExp& operator=(const E_WashpartyExp& from) {
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
  static const E_WashpartyExp& default_instance();

  void Swap(E_WashpartyExp* other);

  // implements Message ----------------------------------------------

  E_WashpartyExp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_WashpartyExp& from);
  void MergeFrom(const E_WashpartyExp& from);
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

  // optional int32 m_lv = 1;
  inline bool has_m_lv() const;
  inline void clear_m_lv();
  static const int kMLvFieldNumber = 1;
  inline ::google::protobuf::int32 m_lv() const;
  inline void set_m_lv(::google::protobuf::int32 value);

  // optional int32 m_washexp = 2;
  inline bool has_m_washexp() const;
  inline void clear_m_washexp();
  static const int kMWashexpFieldNumber = 2;
  inline ::google::protobuf::int32 m_washexp() const;
  inline void set_m_washexp(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_WashpartyExp)
 private:
  inline void set_has_m_lv();
  inline void clear_has_m_lv();
  inline void set_has_m_washexp();
  inline void clear_has_m_washexp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_lv_;
  ::google::protobuf::int32 m_washexp_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fWashparty_2eproto();
  friend void protobuf_AssignDesc_E_5fWashparty_2eproto();
  friend void protobuf_ShutdownFile_E_5fWashparty_2eproto();

  void InitAsDefaultInstance();
  static E_WashpartyExp* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_WashpartyExp : public ::google::protobuf::Message {
 public:
  Sheet_WashpartyExp();
  virtual ~Sheet_WashpartyExp();

  Sheet_WashpartyExp(const Sheet_WashpartyExp& from);

  inline Sheet_WashpartyExp& operator=(const Sheet_WashpartyExp& from) {
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
  static const Sheet_WashpartyExp& default_instance();

  void Swap(Sheet_WashpartyExp* other);

  // implements Message ----------------------------------------------

  Sheet_WashpartyExp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_WashpartyExp& from);
  void MergeFrom(const Sheet_WashpartyExp& from);
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

  // repeated .proto_ff.E_WashpartyExp E_WashpartyExp_List = 1;
  inline int e_washpartyexp_list_size() const;
  inline void clear_e_washpartyexp_list();
  static const int kEWashpartyExpListFieldNumber = 1;
  inline const ::proto_ff::E_WashpartyExp& e_washpartyexp_list(int index) const;
  inline ::proto_ff::E_WashpartyExp* mutable_e_washpartyexp_list(int index);
  inline ::proto_ff::E_WashpartyExp* add_e_washpartyexp_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyExp >&
      e_washpartyexp_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyExp >*
      mutable_e_washpartyexp_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_WashpartyExp)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyExp > e_washpartyexp_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fWashparty_2eproto();
  friend void protobuf_AssignDesc_E_5fWashparty_2eproto();
  friend void protobuf_ShutdownFile_E_5fWashparty_2eproto();

  void InitAsDefaultInstance();
  static Sheet_WashpartyExp* default_instance_;
};
// ===================================================================


// ===================================================================

// E_WashpartyWashparty

// optional int32 m_id = 1;
inline bool E_WashpartyWashparty::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_WashpartyWashparty::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_WashpartyWashparty::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_id() const {
  return m_id_;
}
inline void E_WashpartyWashparty::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_collectid = 2;
inline bool E_WashpartyWashparty::has_m_collectid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_collectid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_WashpartyWashparty::clear_has_m_collectid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_WashpartyWashparty::clear_m_collectid() {
  m_collectid_ = 0;
  clear_has_m_collectid();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_collectid() const {
  return m_collectid_;
}
inline void E_WashpartyWashparty::set_m_collectid(::google::protobuf::int32 value) {
  set_has_m_collectid();
  m_collectid_ = value;
}

// optional int32 m_collectnum = 3;
inline bool E_WashpartyWashparty::has_m_collectnum() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_collectnum() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_WashpartyWashparty::clear_has_m_collectnum() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_WashpartyWashparty::clear_m_collectnum() {
  m_collectnum_ = 0;
  clear_has_m_collectnum();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_collectnum() const {
  return m_collectnum_;
}
inline void E_WashpartyWashparty::set_m_collectnum(::google::protobuf::int32 value) {
  set_has_m_collectnum();
  m_collectnum_ = value;
}

// optional int32 m_collectposid = 4;
inline bool E_WashpartyWashparty::has_m_collectposid() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_collectposid() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_WashpartyWashparty::clear_has_m_collectposid() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_WashpartyWashparty::clear_m_collectposid() {
  m_collectposid_ = 0;
  clear_has_m_collectposid();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_collectposid() const {
  return m_collectposid_;
}
inline void E_WashpartyWashparty::set_m_collectposid(::google::protobuf::int32 value) {
  set_has_m_collectposid();
  m_collectposid_ = value;
}

// optional int32 m_collectgeninterval = 5;
inline bool E_WashpartyWashparty::has_m_collectgeninterval() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_collectgeninterval() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_WashpartyWashparty::clear_has_m_collectgeninterval() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_WashpartyWashparty::clear_m_collectgeninterval() {
  m_collectgeninterval_ = 0;
  clear_has_m_collectgeninterval();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_collectgeninterval() const {
  return m_collectgeninterval_;
}
inline void E_WashpartyWashparty::set_m_collectgeninterval(::google::protobuf::int32 value) {
  set_has_m_collectgeninterval();
  m_collectgeninterval_ = value;
}

// optional int32 m_collectmax = 6;
inline bool E_WashpartyWashparty::has_m_collectmax() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_collectmax() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_WashpartyWashparty::clear_has_m_collectmax() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_WashpartyWashparty::clear_m_collectmax() {
  m_collectmax_ = 0;
  clear_has_m_collectmax();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_collectmax() const {
  return m_collectmax_;
}
inline void E_WashpartyWashparty::set_m_collectmax(::google::protobuf::int32 value) {
  set_has_m_collectmax();
  m_collectmax_ = value;
}

// optional int32 m_splashnum = 7;
inline bool E_WashpartyWashparty::has_m_splashnum() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_splashnum() {
  _has_bits_[0] |= 0x00000040u;
}
inline void E_WashpartyWashparty::clear_has_m_splashnum() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void E_WashpartyWashparty::clear_m_splashnum() {
  m_splashnum_ = 0;
  clear_has_m_splashnum();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_splashnum() const {
  return m_splashnum_;
}
inline void E_WashpartyWashparty::set_m_splashnum(::google::protobuf::int32 value) {
  set_has_m_splashnum();
  m_splashnum_ = value;
}

// optional int32 m_splashreward = 8;
inline bool E_WashpartyWashparty::has_m_splashreward() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_splashreward() {
  _has_bits_[0] |= 0x00000080u;
}
inline void E_WashpartyWashparty::clear_has_m_splashreward() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void E_WashpartyWashparty::clear_m_splashreward() {
  m_splashreward_ = 0;
  clear_has_m_splashreward();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_splashreward() const {
  return m_splashreward_;
}
inline void E_WashpartyWashparty::set_m_splashreward(::google::protobuf::int32 value) {
  set_has_m_splashreward();
  m_splashreward_ = value;
}

// optional int32 m_massagenum = 9;
inline bool E_WashpartyWashparty::has_m_massagenum() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_massagenum() {
  _has_bits_[0] |= 0x00000100u;
}
inline void E_WashpartyWashparty::clear_has_m_massagenum() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void E_WashpartyWashparty::clear_m_massagenum() {
  m_massagenum_ = 0;
  clear_has_m_massagenum();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_massagenum() const {
  return m_massagenum_;
}
inline void E_WashpartyWashparty::set_m_massagenum(::google::protobuf::int32 value) {
  set_has_m_massagenum();
  m_massagenum_ = value;
}

// optional int32 m_massagetime = 10;
inline bool E_WashpartyWashparty::has_m_massagetime() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_massagetime() {
  _has_bits_[0] |= 0x00000200u;
}
inline void E_WashpartyWashparty::clear_has_m_massagetime() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void E_WashpartyWashparty::clear_m_massagetime() {
  m_massagetime_ = 0;
  clear_has_m_massagetime();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_massagetime() const {
  return m_massagetime_;
}
inline void E_WashpartyWashparty::set_m_massagetime(::google::protobuf::int32 value) {
  set_has_m_massagetime();
  m_massagetime_ = value;
}

// optional int32 m_massagereward = 11;
inline bool E_WashpartyWashparty::has_m_massagereward() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_massagereward() {
  _has_bits_[0] |= 0x00000400u;
}
inline void E_WashpartyWashparty::clear_has_m_massagereward() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void E_WashpartyWashparty::clear_m_massagereward() {
  m_massagereward_ = 0;
  clear_has_m_massagereward();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_massagereward() const {
  return m_massagereward_;
}
inline void E_WashpartyWashparty::set_m_massagereward(::google::protobuf::int32 value) {
  set_has_m_massagereward();
  m_massagereward_ = value;
}

// optional int32 m_pairexpaddition = 12;
inline bool E_WashpartyWashparty::has_m_pairexpaddition() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_pairexpaddition() {
  _has_bits_[0] |= 0x00000800u;
}
inline void E_WashpartyWashparty::clear_has_m_pairexpaddition() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void E_WashpartyWashparty::clear_m_pairexpaddition() {
  m_pairexpaddition_ = 0;
  clear_has_m_pairexpaddition();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_pairexpaddition() const {
  return m_pairexpaddition_;
}
inline void E_WashpartyWashparty::set_m_pairexpaddition(::google::protobuf::int32 value) {
  set_has_m_pairexpaddition();
  m_pairexpaddition_ = value;
}

// optional int32 m_mapid = 13;
inline bool E_WashpartyWashparty::has_m_mapid() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_mapid() {
  _has_bits_[0] |= 0x00001000u;
}
inline void E_WashpartyWashparty::clear_has_m_mapid() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void E_WashpartyWashparty::clear_m_mapid() {
  m_mapid_ = 0;
  clear_has_m_mapid();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_mapid() const {
  return m_mapid_;
}
inline void E_WashpartyWashparty::set_m_mapid(::google::protobuf::int32 value) {
  set_has_m_mapid();
  m_mapid_ = value;
}

// optional int32 m_duration = 14;
inline bool E_WashpartyWashparty::has_m_duration() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_duration() {
  _has_bits_[0] |= 0x00002000u;
}
inline void E_WashpartyWashparty::clear_has_m_duration() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void E_WashpartyWashparty::clear_m_duration() {
  m_duration_ = 0;
  clear_has_m_duration();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_duration() const {
  return m_duration_;
}
inline void E_WashpartyWashparty::set_m_duration(::google::protobuf::int32 value) {
  set_has_m_duration();
  m_duration_ = value;
}

// optional int32 m_expaddinterval = 15;
inline bool E_WashpartyWashparty::has_m_expaddinterval() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_expaddinterval() {
  _has_bits_[0] |= 0x00004000u;
}
inline void E_WashpartyWashparty::clear_has_m_expaddinterval() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void E_WashpartyWashparty::clear_m_expaddinterval() {
  m_expaddinterval_ = 0;
  clear_has_m_expaddinterval();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_expaddinterval() const {
  return m_expaddinterval_;
}
inline void E_WashpartyWashparty::set_m_expaddinterval(::google::protobuf::int32 value) {
  set_has_m_expaddinterval();
  m_expaddinterval_ = value;
}

// optional int32 m_splashsi = 16;
inline bool E_WashpartyWashparty::has_m_splashsi() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_splashsi() {
  _has_bits_[0] |= 0x00008000u;
}
inline void E_WashpartyWashparty::clear_has_m_splashsi() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void E_WashpartyWashparty::clear_m_splashsi() {
  m_splashsi_ = 0;
  clear_has_m_splashsi();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_splashsi() const {
  return m_splashsi_;
}
inline void E_WashpartyWashparty::set_m_splashsi(::google::protobuf::int32 value) {
  set_has_m_splashsi();
  m_splashsi_ = value;
}

// optional int32 m_birthareaid = 17;
inline bool E_WashpartyWashparty::has_m_birthareaid() const {
  return (_has_bits_[0] & 0x00010000u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_birthareaid() {
  _has_bits_[0] |= 0x00010000u;
}
inline void E_WashpartyWashparty::clear_has_m_birthareaid() {
  _has_bits_[0] &= ~0x00010000u;
}
inline void E_WashpartyWashparty::clear_m_birthareaid() {
  m_birthareaid_ = 0;
  clear_has_m_birthareaid();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_birthareaid() const {
  return m_birthareaid_;
}
inline void E_WashpartyWashparty::set_m_birthareaid(::google::protobuf::int32 value) {
  set_has_m_birthareaid();
  m_birthareaid_ = value;
}

// optional int32 m_actid = 18;
inline bool E_WashpartyWashparty::has_m_actid() const {
  return (_has_bits_[0] & 0x00020000u) != 0;
}
inline void E_WashpartyWashparty::set_has_m_actid() {
  _has_bits_[0] |= 0x00020000u;
}
inline void E_WashpartyWashparty::clear_has_m_actid() {
  _has_bits_[0] &= ~0x00020000u;
}
inline void E_WashpartyWashparty::clear_m_actid() {
  m_actid_ = 0;
  clear_has_m_actid();
}
inline ::google::protobuf::int32 E_WashpartyWashparty::m_actid() const {
  return m_actid_;
}
inline void E_WashpartyWashparty::set_m_actid(::google::protobuf::int32 value) {
  set_has_m_actid();
  m_actid_ = value;
}

// -------------------------------------------------------------------

// Sheet_WashpartyWashparty

// repeated .proto_ff.E_WashpartyWashparty E_WashpartyWashparty_List = 1;
inline int Sheet_WashpartyWashparty::e_washpartywashparty_list_size() const {
  return e_washpartywashparty_list_.size();
}
inline void Sheet_WashpartyWashparty::clear_e_washpartywashparty_list() {
  e_washpartywashparty_list_.Clear();
}
inline const ::proto_ff::E_WashpartyWashparty& Sheet_WashpartyWashparty::e_washpartywashparty_list(int index) const {
  return e_washpartywashparty_list_.Get(index);
}
inline ::proto_ff::E_WashpartyWashparty* Sheet_WashpartyWashparty::mutable_e_washpartywashparty_list(int index) {
  return e_washpartywashparty_list_.Mutable(index);
}
inline ::proto_ff::E_WashpartyWashparty* Sheet_WashpartyWashparty::add_e_washpartywashparty_list() {
  return e_washpartywashparty_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyWashparty >&
Sheet_WashpartyWashparty::e_washpartywashparty_list() const {
  return e_washpartywashparty_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyWashparty >*
Sheet_WashpartyWashparty::mutable_e_washpartywashparty_list() {
  return &e_washpartywashparty_list_;
}

// -------------------------------------------------------------------

// E_WashpartyExp

// optional int32 m_lv = 1;
inline bool E_WashpartyExp::has_m_lv() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_WashpartyExp::set_has_m_lv() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_WashpartyExp::clear_has_m_lv() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_WashpartyExp::clear_m_lv() {
  m_lv_ = 0;
  clear_has_m_lv();
}
inline ::google::protobuf::int32 E_WashpartyExp::m_lv() const {
  return m_lv_;
}
inline void E_WashpartyExp::set_m_lv(::google::protobuf::int32 value) {
  set_has_m_lv();
  m_lv_ = value;
}

// optional int32 m_washexp = 2;
inline bool E_WashpartyExp::has_m_washexp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_WashpartyExp::set_has_m_washexp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_WashpartyExp::clear_has_m_washexp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_WashpartyExp::clear_m_washexp() {
  m_washexp_ = 0;
  clear_has_m_washexp();
}
inline ::google::protobuf::int32 E_WashpartyExp::m_washexp() const {
  return m_washexp_;
}
inline void E_WashpartyExp::set_m_washexp(::google::protobuf::int32 value) {
  set_has_m_washexp();
  m_washexp_ = value;
}

// -------------------------------------------------------------------

// Sheet_WashpartyExp

// repeated .proto_ff.E_WashpartyExp E_WashpartyExp_List = 1;
inline int Sheet_WashpartyExp::e_washpartyexp_list_size() const {
  return e_washpartyexp_list_.size();
}
inline void Sheet_WashpartyExp::clear_e_washpartyexp_list() {
  e_washpartyexp_list_.Clear();
}
inline const ::proto_ff::E_WashpartyExp& Sheet_WashpartyExp::e_washpartyexp_list(int index) const {
  return e_washpartyexp_list_.Get(index);
}
inline ::proto_ff::E_WashpartyExp* Sheet_WashpartyExp::mutable_e_washpartyexp_list(int index) {
  return e_washpartyexp_list_.Mutable(index);
}
inline ::proto_ff::E_WashpartyExp* Sheet_WashpartyExp::add_e_washpartyexp_list() {
  return e_washpartyexp_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyExp >&
Sheet_WashpartyExp::e_washpartyexp_list() const {
  return e_washpartyexp_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_WashpartyExp >*
Sheet_WashpartyExp::mutable_e_washpartyexp_list() {
  return &e_washpartyexp_list_;
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

#endif  // PROTOBUF_E_5fWashparty_2eproto__INCLUDED
