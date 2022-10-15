// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vip.proto

#ifndef PROTOBUF_vip_2eproto__INCLUDED
#define PROTOBUF_vip_2eproto__INCLUDED

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
void  protobuf_AddDesc_vip_2eproto();
void protobuf_AssignDesc_vip_2eproto();
void protobuf_ShutdownFile_vip_2eproto();

class vipvip;
class Sheet_vipvip;
class vipprivilege;
class Sheet_vipprivilege;
class vipgift;
class Sheet_vipgift;

// ===================================================================

class vipvip : public ::google::protobuf::Message {
 public:
  vipvip();
  virtual ~vipvip();

  vipvip(const vipvip& from);

  inline vipvip& operator=(const vipvip& from) {
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
  static const vipvip& default_instance();

  void Swap(vipvip* other);

  // implements Message ----------------------------------------------

  vipvip* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const vipvip& from);
  void MergeFrom(const vipvip& from);
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

  // optional int64 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int64 id() const;
  inline void set_id(::google::protobuf::int64 value);

  // optional int32 level = 2;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 2;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // optional int32 vipType = 3;
  inline bool has_viptype() const;
  inline void clear_viptype();
  static const int kVipTypeFieldNumber = 3;
  inline ::google::protobuf::int32 viptype() const;
  inline void set_viptype(::google::protobuf::int32 value);

  // optional int32 exp = 4;
  inline bool has_exp() const;
  inline void clear_exp();
  static const int kExpFieldNumber = 4;
  inline ::google::protobuf::int32 exp() const;
  inline void set_exp(::google::protobuf::int32 value);

  // optional string privilege_id = 5;
  inline bool has_privilege_id() const;
  inline void clear_privilege_id();
  static const int kPrivilegeIdFieldNumber = 5;
  inline const ::std::string& privilege_id() const;
  inline void set_privilege_id(const ::std::string& value);
  inline void set_privilege_id(const char* value);
  inline void set_privilege_id(const char* value, size_t size);
  inline ::std::string* mutable_privilege_id();
  inline ::std::string* release_privilege_id();
  inline void set_allocated_privilege_id(::std::string* privilege_id);

  // optional int64 chat = 6;
  inline bool has_chat() const;
  inline void clear_chat();
  static const int kChatFieldNumber = 6;
  inline ::google::protobuf::int64 chat() const;
  inline void set_chat(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.vipvip)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_viptype();
  inline void clear_has_viptype();
  inline void set_has_exp();
  inline void clear_has_exp();
  inline void set_has_privilege_id();
  inline void clear_has_privilege_id();
  inline void set_has_chat();
  inline void clear_has_chat();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 id_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 viptype_;
  ::std::string* privilege_id_;
  ::google::protobuf::int64 chat_;
  ::google::protobuf::int32 exp_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_vip_2eproto();
  friend void protobuf_AssignDesc_vip_2eproto();
  friend void protobuf_ShutdownFile_vip_2eproto();

  void InitAsDefaultInstance();
  static vipvip* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_vipvip : public ::google::protobuf::Message {
 public:
  Sheet_vipvip();
  virtual ~Sheet_vipvip();

  Sheet_vipvip(const Sheet_vipvip& from);

  inline Sheet_vipvip& operator=(const Sheet_vipvip& from) {
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
  static const Sheet_vipvip& default_instance();

  void Swap(Sheet_vipvip* other);

  // implements Message ----------------------------------------------

  Sheet_vipvip* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_vipvip& from);
  void MergeFrom(const Sheet_vipvip& from);
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

  // repeated .proto_ff.vipvip vipvip_List = 1;
  inline int vipvip_list_size() const;
  inline void clear_vipvip_list();
  static const int kVipvipListFieldNumber = 1;
  inline const ::proto_ff::vipvip& vipvip_list(int index) const;
  inline ::proto_ff::vipvip* mutable_vipvip_list(int index);
  inline ::proto_ff::vipvip* add_vipvip_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::vipvip >&
      vipvip_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::vipvip >*
      mutable_vipvip_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_vipvip)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::vipvip > vipvip_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_vip_2eproto();
  friend void protobuf_AssignDesc_vip_2eproto();
  friend void protobuf_ShutdownFile_vip_2eproto();

  void InitAsDefaultInstance();
  static Sheet_vipvip* default_instance_;
};
// -------------------------------------------------------------------

class vipprivilege : public ::google::protobuf::Message {
 public:
  vipprivilege();
  virtual ~vipprivilege();

  vipprivilege(const vipprivilege& from);

  inline vipprivilege& operator=(const vipprivilege& from) {
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
  static const vipprivilege& default_instance();

  void Swap(vipprivilege* other);

  // implements Message ----------------------------------------------

  vipprivilege* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const vipprivilege& from);
  void MergeFrom(const vipprivilege& from);
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

  // optional int64 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int64 id() const;
  inline void set_id(::google::protobuf::int64 value);

  // optional int32 type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // optional string canshuString = 3;
  inline bool has_canshustring() const;
  inline void clear_canshustring();
  static const int kCanshuStringFieldNumber = 3;
  inline const ::std::string& canshustring() const;
  inline void set_canshustring(const ::std::string& value);
  inline void set_canshustring(const char* value);
  inline void set_canshustring(const char* value, size_t size);
  inline ::std::string* mutable_canshustring();
  inline ::std::string* release_canshustring();
  inline void set_allocated_canshustring(::std::string* canshustring);

  // repeated int32 canshu = 4;
  inline int canshu_size() const;
  inline void clear_canshu();
  static const int kCanshuFieldNumber = 4;
  inline ::google::protobuf::int32 canshu(int index) const;
  inline void set_canshu(int index, ::google::protobuf::int32 value);
  inline void add_canshu(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      canshu() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_canshu();

  // @@protoc_insertion_point(class_scope:proto_ff.vipprivilege)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_canshustring();
  inline void clear_has_canshustring();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 id_;
  ::std::string* canshustring_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > canshu_;
  ::google::protobuf::int32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_vip_2eproto();
  friend void protobuf_AssignDesc_vip_2eproto();
  friend void protobuf_ShutdownFile_vip_2eproto();

  void InitAsDefaultInstance();
  static vipprivilege* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_vipprivilege : public ::google::protobuf::Message {
 public:
  Sheet_vipprivilege();
  virtual ~Sheet_vipprivilege();

  Sheet_vipprivilege(const Sheet_vipprivilege& from);

  inline Sheet_vipprivilege& operator=(const Sheet_vipprivilege& from) {
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
  static const Sheet_vipprivilege& default_instance();

  void Swap(Sheet_vipprivilege* other);

  // implements Message ----------------------------------------------

  Sheet_vipprivilege* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_vipprivilege& from);
  void MergeFrom(const Sheet_vipprivilege& from);
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

  // repeated .proto_ff.vipprivilege vipprivilege_List = 1;
  inline int vipprivilege_list_size() const;
  inline void clear_vipprivilege_list();
  static const int kVipprivilegeListFieldNumber = 1;
  inline const ::proto_ff::vipprivilege& vipprivilege_list(int index) const;
  inline ::proto_ff::vipprivilege* mutable_vipprivilege_list(int index);
  inline ::proto_ff::vipprivilege* add_vipprivilege_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::vipprivilege >&
      vipprivilege_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::vipprivilege >*
      mutable_vipprivilege_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_vipprivilege)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::vipprivilege > vipprivilege_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_vip_2eproto();
  friend void protobuf_AssignDesc_vip_2eproto();
  friend void protobuf_ShutdownFile_vip_2eproto();

  void InitAsDefaultInstance();
  static Sheet_vipprivilege* default_instance_;
};
// -------------------------------------------------------------------

class vipgift : public ::google::protobuf::Message {
 public:
  vipgift();
  virtual ~vipgift();

  vipgift(const vipgift& from);

  inline vipgift& operator=(const vipgift& from) {
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
  static const vipgift& default_instance();

  void Swap(vipgift* other);

  // implements Message ----------------------------------------------

  vipgift* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const vipgift& from);
  void MergeFrom(const vipgift& from);
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

  // optional int64 ID = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIDFieldNumber = 1;
  inline ::google::protobuf::int64 id() const;
  inline void set_id(::google::protobuf::int64 value);

  // optional int32 Type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // optional int32 VipLv = 3;
  inline bool has_viplv() const;
  inline void clear_viplv();
  static const int kVipLvFieldNumber = 3;
  inline ::google::protobuf::int32 viplv() const;
  inline void set_viplv(::google::protobuf::int32 value);

  // optional int32 moneyType = 4;
  inline bool has_moneytype() const;
  inline void clear_moneytype();
  static const int kMoneyTypeFieldNumber = 4;
  inline ::google::protobuf::int32 moneytype() const;
  inline void set_moneytype(::google::protobuf::int32 value);

  // optional int32 OriginalPrice = 5;
  inline bool has_originalprice() const;
  inline void clear_originalprice();
  static const int kOriginalPriceFieldNumber = 5;
  inline ::google::protobuf::int32 originalprice() const;
  inline void set_originalprice(::google::protobuf::int32 value);

  // optional int32 Price = 6;
  inline bool has_price() const;
  inline void clear_price();
  static const int kPriceFieldNumber = 6;
  inline ::google::protobuf::int32 price() const;
  inline void set_price(::google::protobuf::int32 value);

  // optional int64 boxid = 7;
  inline bool has_boxid() const;
  inline void clear_boxid();
  static const int kBoxidFieldNumber = 7;
  inline ::google::protobuf::int64 boxid() const;
  inline void set_boxid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.vipgift)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_viplv();
  inline void clear_has_viplv();
  inline void set_has_moneytype();
  inline void clear_has_moneytype();
  inline void set_has_originalprice();
  inline void clear_has_originalprice();
  inline void set_has_price();
  inline void clear_has_price();
  inline void set_has_boxid();
  inline void clear_has_boxid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 id_;
  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 viplv_;
  ::google::protobuf::int32 moneytype_;
  ::google::protobuf::int32 originalprice_;
  ::google::protobuf::int64 boxid_;
  ::google::protobuf::int32 price_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_vip_2eproto();
  friend void protobuf_AssignDesc_vip_2eproto();
  friend void protobuf_ShutdownFile_vip_2eproto();

  void InitAsDefaultInstance();
  static vipgift* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_vipgift : public ::google::protobuf::Message {
 public:
  Sheet_vipgift();
  virtual ~Sheet_vipgift();

  Sheet_vipgift(const Sheet_vipgift& from);

  inline Sheet_vipgift& operator=(const Sheet_vipgift& from) {
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
  static const Sheet_vipgift& default_instance();

  void Swap(Sheet_vipgift* other);

  // implements Message ----------------------------------------------

  Sheet_vipgift* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_vipgift& from);
  void MergeFrom(const Sheet_vipgift& from);
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

  // repeated .proto_ff.vipgift vipgift_List = 1;
  inline int vipgift_list_size() const;
  inline void clear_vipgift_list();
  static const int kVipgiftListFieldNumber = 1;
  inline const ::proto_ff::vipgift& vipgift_list(int index) const;
  inline ::proto_ff::vipgift* mutable_vipgift_list(int index);
  inline ::proto_ff::vipgift* add_vipgift_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::vipgift >&
      vipgift_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::vipgift >*
      mutable_vipgift_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_vipgift)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::vipgift > vipgift_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_vip_2eproto();
  friend void protobuf_AssignDesc_vip_2eproto();
  friend void protobuf_ShutdownFile_vip_2eproto();

  void InitAsDefaultInstance();
  static Sheet_vipgift* default_instance_;
};
// ===================================================================


// ===================================================================

// vipvip

// optional int64 id = 1;
inline bool vipvip::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void vipvip::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void vipvip::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void vipvip::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::int64 vipvip::id() const {
  return id_;
}
inline void vipvip::set_id(::google::protobuf::int64 value) {
  set_has_id();
  id_ = value;
}

// optional int32 level = 2;
inline bool vipvip::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void vipvip::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void vipvip::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void vipvip::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 vipvip::level() const {
  return level_;
}
inline void vipvip::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// optional int32 vipType = 3;
inline bool vipvip::has_viptype() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void vipvip::set_has_viptype() {
  _has_bits_[0] |= 0x00000004u;
}
inline void vipvip::clear_has_viptype() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void vipvip::clear_viptype() {
  viptype_ = 0;
  clear_has_viptype();
}
inline ::google::protobuf::int32 vipvip::viptype() const {
  return viptype_;
}
inline void vipvip::set_viptype(::google::protobuf::int32 value) {
  set_has_viptype();
  viptype_ = value;
}

// optional int32 exp = 4;
inline bool vipvip::has_exp() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void vipvip::set_has_exp() {
  _has_bits_[0] |= 0x00000008u;
}
inline void vipvip::clear_has_exp() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void vipvip::clear_exp() {
  exp_ = 0;
  clear_has_exp();
}
inline ::google::protobuf::int32 vipvip::exp() const {
  return exp_;
}
inline void vipvip::set_exp(::google::protobuf::int32 value) {
  set_has_exp();
  exp_ = value;
}

// optional string privilege_id = 5;
inline bool vipvip::has_privilege_id() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void vipvip::set_has_privilege_id() {
  _has_bits_[0] |= 0x00000010u;
}
inline void vipvip::clear_has_privilege_id() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void vipvip::clear_privilege_id() {
  if (privilege_id_ != &::google::protobuf::internal::kEmptyString) {
    privilege_id_->clear();
  }
  clear_has_privilege_id();
}
inline const ::std::string& vipvip::privilege_id() const {
  return *privilege_id_;
}
inline void vipvip::set_privilege_id(const ::std::string& value) {
  set_has_privilege_id();
  if (privilege_id_ == &::google::protobuf::internal::kEmptyString) {
    privilege_id_ = new ::std::string;
  }
  privilege_id_->assign(value);
}
inline void vipvip::set_privilege_id(const char* value) {
  set_has_privilege_id();
  if (privilege_id_ == &::google::protobuf::internal::kEmptyString) {
    privilege_id_ = new ::std::string;
  }
  privilege_id_->assign(value);
}
inline void vipvip::set_privilege_id(const char* value, size_t size) {
  set_has_privilege_id();
  if (privilege_id_ == &::google::protobuf::internal::kEmptyString) {
    privilege_id_ = new ::std::string;
  }
  privilege_id_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* vipvip::mutable_privilege_id() {
  set_has_privilege_id();
  if (privilege_id_ == &::google::protobuf::internal::kEmptyString) {
    privilege_id_ = new ::std::string;
  }
  return privilege_id_;
}
inline ::std::string* vipvip::release_privilege_id() {
  clear_has_privilege_id();
  if (privilege_id_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = privilege_id_;
    privilege_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void vipvip::set_allocated_privilege_id(::std::string* privilege_id) {
  if (privilege_id_ != &::google::protobuf::internal::kEmptyString) {
    delete privilege_id_;
  }
  if (privilege_id) {
    set_has_privilege_id();
    privilege_id_ = privilege_id;
  } else {
    clear_has_privilege_id();
    privilege_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int64 chat = 6;
inline bool vipvip::has_chat() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void vipvip::set_has_chat() {
  _has_bits_[0] |= 0x00000020u;
}
inline void vipvip::clear_has_chat() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void vipvip::clear_chat() {
  chat_ = GOOGLE_LONGLONG(0);
  clear_has_chat();
}
inline ::google::protobuf::int64 vipvip::chat() const {
  return chat_;
}
inline void vipvip::set_chat(::google::protobuf::int64 value) {
  set_has_chat();
  chat_ = value;
}

// -------------------------------------------------------------------

// Sheet_vipvip

// repeated .proto_ff.vipvip vipvip_List = 1;
inline int Sheet_vipvip::vipvip_list_size() const {
  return vipvip_list_.size();
}
inline void Sheet_vipvip::clear_vipvip_list() {
  vipvip_list_.Clear();
}
inline const ::proto_ff::vipvip& Sheet_vipvip::vipvip_list(int index) const {
  return vipvip_list_.Get(index);
}
inline ::proto_ff::vipvip* Sheet_vipvip::mutable_vipvip_list(int index) {
  return vipvip_list_.Mutable(index);
}
inline ::proto_ff::vipvip* Sheet_vipvip::add_vipvip_list() {
  return vipvip_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::vipvip >&
Sheet_vipvip::vipvip_list() const {
  return vipvip_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::vipvip >*
Sheet_vipvip::mutable_vipvip_list() {
  return &vipvip_list_;
}

// -------------------------------------------------------------------

// vipprivilege

// optional int64 id = 1;
inline bool vipprivilege::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void vipprivilege::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void vipprivilege::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void vipprivilege::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::int64 vipprivilege::id() const {
  return id_;
}
inline void vipprivilege::set_id(::google::protobuf::int64 value) {
  set_has_id();
  id_ = value;
}

// optional int32 type = 2;
inline bool vipprivilege::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void vipprivilege::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void vipprivilege::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void vipprivilege::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 vipprivilege::type() const {
  return type_;
}
inline void vipprivilege::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// optional string canshuString = 3;
inline bool vipprivilege::has_canshustring() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void vipprivilege::set_has_canshustring() {
  _has_bits_[0] |= 0x00000004u;
}
inline void vipprivilege::clear_has_canshustring() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void vipprivilege::clear_canshustring() {
  if (canshustring_ != &::google::protobuf::internal::kEmptyString) {
    canshustring_->clear();
  }
  clear_has_canshustring();
}
inline const ::std::string& vipprivilege::canshustring() const {
  return *canshustring_;
}
inline void vipprivilege::set_canshustring(const ::std::string& value) {
  set_has_canshustring();
  if (canshustring_ == &::google::protobuf::internal::kEmptyString) {
    canshustring_ = new ::std::string;
  }
  canshustring_->assign(value);
}
inline void vipprivilege::set_canshustring(const char* value) {
  set_has_canshustring();
  if (canshustring_ == &::google::protobuf::internal::kEmptyString) {
    canshustring_ = new ::std::string;
  }
  canshustring_->assign(value);
}
inline void vipprivilege::set_canshustring(const char* value, size_t size) {
  set_has_canshustring();
  if (canshustring_ == &::google::protobuf::internal::kEmptyString) {
    canshustring_ = new ::std::string;
  }
  canshustring_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* vipprivilege::mutable_canshustring() {
  set_has_canshustring();
  if (canshustring_ == &::google::protobuf::internal::kEmptyString) {
    canshustring_ = new ::std::string;
  }
  return canshustring_;
}
inline ::std::string* vipprivilege::release_canshustring() {
  clear_has_canshustring();
  if (canshustring_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = canshustring_;
    canshustring_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void vipprivilege::set_allocated_canshustring(::std::string* canshustring) {
  if (canshustring_ != &::google::protobuf::internal::kEmptyString) {
    delete canshustring_;
  }
  if (canshustring) {
    set_has_canshustring();
    canshustring_ = canshustring;
  } else {
    clear_has_canshustring();
    canshustring_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated int32 canshu = 4;
inline int vipprivilege::canshu_size() const {
  return canshu_.size();
}
inline void vipprivilege::clear_canshu() {
  canshu_.Clear();
}
inline ::google::protobuf::int32 vipprivilege::canshu(int index) const {
  return canshu_.Get(index);
}
inline void vipprivilege::set_canshu(int index, ::google::protobuf::int32 value) {
  canshu_.Set(index, value);
}
inline void vipprivilege::add_canshu(::google::protobuf::int32 value) {
  canshu_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
vipprivilege::canshu() const {
  return canshu_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
vipprivilege::mutable_canshu() {
  return &canshu_;
}

// -------------------------------------------------------------------

// Sheet_vipprivilege

// repeated .proto_ff.vipprivilege vipprivilege_List = 1;
inline int Sheet_vipprivilege::vipprivilege_list_size() const {
  return vipprivilege_list_.size();
}
inline void Sheet_vipprivilege::clear_vipprivilege_list() {
  vipprivilege_list_.Clear();
}
inline const ::proto_ff::vipprivilege& Sheet_vipprivilege::vipprivilege_list(int index) const {
  return vipprivilege_list_.Get(index);
}
inline ::proto_ff::vipprivilege* Sheet_vipprivilege::mutable_vipprivilege_list(int index) {
  return vipprivilege_list_.Mutable(index);
}
inline ::proto_ff::vipprivilege* Sheet_vipprivilege::add_vipprivilege_list() {
  return vipprivilege_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::vipprivilege >&
Sheet_vipprivilege::vipprivilege_list() const {
  return vipprivilege_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::vipprivilege >*
Sheet_vipprivilege::mutable_vipprivilege_list() {
  return &vipprivilege_list_;
}

// -------------------------------------------------------------------

// vipgift

// optional int64 ID = 1;
inline bool vipgift::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void vipgift::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void vipgift::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void vipgift::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::int64 vipgift::id() const {
  return id_;
}
inline void vipgift::set_id(::google::protobuf::int64 value) {
  set_has_id();
  id_ = value;
}

// optional int32 Type = 2;
inline bool vipgift::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void vipgift::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void vipgift::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void vipgift::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 vipgift::type() const {
  return type_;
}
inline void vipgift::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// optional int32 VipLv = 3;
inline bool vipgift::has_viplv() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void vipgift::set_has_viplv() {
  _has_bits_[0] |= 0x00000004u;
}
inline void vipgift::clear_has_viplv() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void vipgift::clear_viplv() {
  viplv_ = 0;
  clear_has_viplv();
}
inline ::google::protobuf::int32 vipgift::viplv() const {
  return viplv_;
}
inline void vipgift::set_viplv(::google::protobuf::int32 value) {
  set_has_viplv();
  viplv_ = value;
}

// optional int32 moneyType = 4;
inline bool vipgift::has_moneytype() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void vipgift::set_has_moneytype() {
  _has_bits_[0] |= 0x00000008u;
}
inline void vipgift::clear_has_moneytype() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void vipgift::clear_moneytype() {
  moneytype_ = 0;
  clear_has_moneytype();
}
inline ::google::protobuf::int32 vipgift::moneytype() const {
  return moneytype_;
}
inline void vipgift::set_moneytype(::google::protobuf::int32 value) {
  set_has_moneytype();
  moneytype_ = value;
}

// optional int32 OriginalPrice = 5;
inline bool vipgift::has_originalprice() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void vipgift::set_has_originalprice() {
  _has_bits_[0] |= 0x00000010u;
}
inline void vipgift::clear_has_originalprice() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void vipgift::clear_originalprice() {
  originalprice_ = 0;
  clear_has_originalprice();
}
inline ::google::protobuf::int32 vipgift::originalprice() const {
  return originalprice_;
}
inline void vipgift::set_originalprice(::google::protobuf::int32 value) {
  set_has_originalprice();
  originalprice_ = value;
}

// optional int32 Price = 6;
inline bool vipgift::has_price() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void vipgift::set_has_price() {
  _has_bits_[0] |= 0x00000020u;
}
inline void vipgift::clear_has_price() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void vipgift::clear_price() {
  price_ = 0;
  clear_has_price();
}
inline ::google::protobuf::int32 vipgift::price() const {
  return price_;
}
inline void vipgift::set_price(::google::protobuf::int32 value) {
  set_has_price();
  price_ = value;
}

// optional int64 boxid = 7;
inline bool vipgift::has_boxid() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void vipgift::set_has_boxid() {
  _has_bits_[0] |= 0x00000040u;
}
inline void vipgift::clear_has_boxid() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void vipgift::clear_boxid() {
  boxid_ = GOOGLE_LONGLONG(0);
  clear_has_boxid();
}
inline ::google::protobuf::int64 vipgift::boxid() const {
  return boxid_;
}
inline void vipgift::set_boxid(::google::protobuf::int64 value) {
  set_has_boxid();
  boxid_ = value;
}

// -------------------------------------------------------------------

// Sheet_vipgift

// repeated .proto_ff.vipgift vipgift_List = 1;
inline int Sheet_vipgift::vipgift_list_size() const {
  return vipgift_list_.size();
}
inline void Sheet_vipgift::clear_vipgift_list() {
  vipgift_list_.Clear();
}
inline const ::proto_ff::vipgift& Sheet_vipgift::vipgift_list(int index) const {
  return vipgift_list_.Get(index);
}
inline ::proto_ff::vipgift* Sheet_vipgift::mutable_vipgift_list(int index) {
  return vipgift_list_.Mutable(index);
}
inline ::proto_ff::vipgift* Sheet_vipgift::add_vipgift_list() {
  return vipgift_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::vipgift >&
Sheet_vipgift::vipgift_list() const {
  return vipgift_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::vipgift >*
Sheet_vipgift::mutable_vipgift_list() {
  return &vipgift_list_;
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

#endif  // PROTOBUF_vip_2eproto__INCLUDED