// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Intimacy.proto

#ifndef PROTOBUF_E_5fIntimacy_2eproto__INCLUDED
#define PROTOBUF_E_5fIntimacy_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fIntimacy_2eproto();
void protobuf_AssignDesc_E_5fIntimacy_2eproto();
void protobuf_ShutdownFile_E_5fIntimacy_2eproto();

class E_IntimacyIntimacyAttributeDesc;
class E_IntimacyIntimacy;
class Sheet_IntimacyIntimacy;
class E_IntimacyGift;
class Sheet_IntimacyGift;

// ===================================================================

class E_IntimacyIntimacyAttributeDesc : public ::google::protobuf::Message {
 public:
  E_IntimacyIntimacyAttributeDesc();
  virtual ~E_IntimacyIntimacyAttributeDesc();

  E_IntimacyIntimacyAttributeDesc(const E_IntimacyIntimacyAttributeDesc& from);

  inline E_IntimacyIntimacyAttributeDesc& operator=(const E_IntimacyIntimacyAttributeDesc& from) {
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
  static const E_IntimacyIntimacyAttributeDesc& default_instance();

  void Swap(E_IntimacyIntimacyAttributeDesc* other);

  // implements Message ----------------------------------------------

  E_IntimacyIntimacyAttributeDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_IntimacyIntimacyAttributeDesc& from);
  void MergeFrom(const E_IntimacyIntimacyAttributeDesc& from);
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

  // optional int32 m_value = 1;
  inline bool has_m_value() const;
  inline void clear_m_value();
  static const int kMValueFieldNumber = 1;
  inline ::google::protobuf::int32 m_value() const;
  inline void set_m_value(::google::protobuf::int32 value);

  // optional int32 m_type = 2;
  inline bool has_m_type() const;
  inline void clear_m_type();
  static const int kMTypeFieldNumber = 2;
  inline ::google::protobuf::int32 m_type() const;
  inline void set_m_type(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_IntimacyIntimacyAttributeDesc)
 private:
  inline void set_has_m_value();
  inline void clear_has_m_value();
  inline void set_has_m_type();
  inline void clear_has_m_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_value_;
  ::google::protobuf::int32 m_type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fIntimacy_2eproto();
  friend void protobuf_AssignDesc_E_5fIntimacy_2eproto();
  friend void protobuf_ShutdownFile_E_5fIntimacy_2eproto();

  void InitAsDefaultInstance();
  static E_IntimacyIntimacyAttributeDesc* default_instance_;
};
// -------------------------------------------------------------------

class E_IntimacyIntimacy : public ::google::protobuf::Message {
 public:
  E_IntimacyIntimacy();
  virtual ~E_IntimacyIntimacy();

  E_IntimacyIntimacy(const E_IntimacyIntimacy& from);

  inline E_IntimacyIntimacy& operator=(const E_IntimacyIntimacy& from) {
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
  static const E_IntimacyIntimacy& default_instance();

  void Swap(E_IntimacyIntimacy* other);

  // implements Message ----------------------------------------------

  E_IntimacyIntimacy* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_IntimacyIntimacy& from);
  void MergeFrom(const E_IntimacyIntimacy& from);
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

  // optional int32 m_intimacymin = 2;
  inline bool has_m_intimacymin() const;
  inline void clear_m_intimacymin();
  static const int kMIntimacyminFieldNumber = 2;
  inline ::google::protobuf::int32 m_intimacymin() const;
  inline void set_m_intimacymin(::google::protobuf::int32 value);

  // optional int32 m_intimacymax = 3;
  inline bool has_m_intimacymax() const;
  inline void clear_m_intimacymax();
  static const int kMIntimacymaxFieldNumber = 3;
  inline ::google::protobuf::int32 m_intimacymax() const;
  inline void set_m_intimacymax(::google::protobuf::int32 value);

  // repeated .proto_ff.E_IntimacyIntimacyAttributeDesc m_attribute = 4;
  inline int m_attribute_size() const;
  inline void clear_m_attribute();
  static const int kMAttributeFieldNumber = 4;
  inline const ::proto_ff::E_IntimacyIntimacyAttributeDesc& m_attribute(int index) const;
  inline ::proto_ff::E_IntimacyIntimacyAttributeDesc* mutable_m_attribute(int index);
  inline ::proto_ff::E_IntimacyIntimacyAttributeDesc* add_m_attribute();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacyAttributeDesc >&
      m_attribute() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacyAttributeDesc >*
      mutable_m_attribute();

  // @@protoc_insertion_point(class_scope:proto_ff.E_IntimacyIntimacy)
 private:
  inline void set_has_m_lv();
  inline void clear_has_m_lv();
  inline void set_has_m_intimacymin();
  inline void clear_has_m_intimacymin();
  inline void set_has_m_intimacymax();
  inline void clear_has_m_intimacymax();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_lv_;
  ::google::protobuf::int32 m_intimacymin_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacyAttributeDesc > m_attribute_;
  ::google::protobuf::int32 m_intimacymax_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fIntimacy_2eproto();
  friend void protobuf_AssignDesc_E_5fIntimacy_2eproto();
  friend void protobuf_ShutdownFile_E_5fIntimacy_2eproto();

  void InitAsDefaultInstance();
  static E_IntimacyIntimacy* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_IntimacyIntimacy : public ::google::protobuf::Message {
 public:
  Sheet_IntimacyIntimacy();
  virtual ~Sheet_IntimacyIntimacy();

  Sheet_IntimacyIntimacy(const Sheet_IntimacyIntimacy& from);

  inline Sheet_IntimacyIntimacy& operator=(const Sheet_IntimacyIntimacy& from) {
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
  static const Sheet_IntimacyIntimacy& default_instance();

  void Swap(Sheet_IntimacyIntimacy* other);

  // implements Message ----------------------------------------------

  Sheet_IntimacyIntimacy* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_IntimacyIntimacy& from);
  void MergeFrom(const Sheet_IntimacyIntimacy& from);
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

  // repeated .proto_ff.E_IntimacyIntimacy E_IntimacyIntimacy_List = 1;
  inline int e_intimacyintimacy_list_size() const;
  inline void clear_e_intimacyintimacy_list();
  static const int kEIntimacyIntimacyListFieldNumber = 1;
  inline const ::proto_ff::E_IntimacyIntimacy& e_intimacyintimacy_list(int index) const;
  inline ::proto_ff::E_IntimacyIntimacy* mutable_e_intimacyintimacy_list(int index);
  inline ::proto_ff::E_IntimacyIntimacy* add_e_intimacyintimacy_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacy >&
      e_intimacyintimacy_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacy >*
      mutable_e_intimacyintimacy_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_IntimacyIntimacy)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacy > e_intimacyintimacy_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fIntimacy_2eproto();
  friend void protobuf_AssignDesc_E_5fIntimacy_2eproto();
  friend void protobuf_ShutdownFile_E_5fIntimacy_2eproto();

  void InitAsDefaultInstance();
  static Sheet_IntimacyIntimacy* default_instance_;
};
// -------------------------------------------------------------------

class E_IntimacyGift : public ::google::protobuf::Message {
 public:
  E_IntimacyGift();
  virtual ~E_IntimacyGift();

  E_IntimacyGift(const E_IntimacyGift& from);

  inline E_IntimacyGift& operator=(const E_IntimacyGift& from) {
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
  static const E_IntimacyGift& default_instance();

  void Swap(E_IntimacyGift* other);

  // implements Message ----------------------------------------------

  E_IntimacyGift* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_IntimacyGift& from);
  void MergeFrom(const E_IntimacyGift& from);
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

  // optional int32 m_mallid = 1;
  inline bool has_m_mallid() const;
  inline void clear_m_mallid();
  static const int kMMallidFieldNumber = 1;
  inline ::google::protobuf::int32 m_mallid() const;
  inline void set_m_mallid(::google::protobuf::int32 value);

  // optional int32 m_itemid = 2;
  inline bool has_m_itemid() const;
  inline void clear_m_itemid();
  static const int kMItemidFieldNumber = 2;
  inline ::google::protobuf::int32 m_itemid() const;
  inline void set_m_itemid(::google::protobuf::int32 value);

  // optional int32 m_nametype = 3;
  inline bool has_m_nametype() const;
  inline void clear_m_nametype();
  static const int kMNametypeFieldNumber = 3;
  inline ::google::protobuf::int32 m_nametype() const;
  inline void set_m_nametype(::google::protobuf::int32 value);

  // optional string m_uipic = 4;
  inline bool has_m_uipic() const;
  inline void clear_m_uipic();
  static const int kMUipicFieldNumber = 4;
  inline const ::std::string& m_uipic() const;
  inline void set_m_uipic(const ::std::string& value);
  inline void set_m_uipic(const char* value);
  inline void set_m_uipic(const char* value, size_t size);
  inline ::std::string* mutable_m_uipic();
  inline ::std::string* release_m_uipic();
  inline void set_allocated_m_uipic(::std::string* m_uipic);

  // optional int32 m_intimacy = 5;
  inline bool has_m_intimacy() const;
  inline void clear_m_intimacy();
  static const int kMIntimacyFieldNumber = 5;
  inline ::google::protobuf::int32 m_intimacy() const;
  inline void set_m_intimacy(::google::protobuf::int32 value);

  // optional int32 m_charm = 6;
  inline bool has_m_charm() const;
  inline void clear_m_charm();
  static const int kMCharmFieldNumber = 6;
  inline ::google::protobuf::int32 m_charm() const;
  inline void set_m_charm(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_IntimacyGift)
 private:
  inline void set_has_m_mallid();
  inline void clear_has_m_mallid();
  inline void set_has_m_itemid();
  inline void clear_has_m_itemid();
  inline void set_has_m_nametype();
  inline void clear_has_m_nametype();
  inline void set_has_m_uipic();
  inline void clear_has_m_uipic();
  inline void set_has_m_intimacy();
  inline void clear_has_m_intimacy();
  inline void set_has_m_charm();
  inline void clear_has_m_charm();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_mallid_;
  ::google::protobuf::int32 m_itemid_;
  ::std::string* m_uipic_;
  ::google::protobuf::int32 m_nametype_;
  ::google::protobuf::int32 m_intimacy_;
  ::google::protobuf::int32 m_charm_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fIntimacy_2eproto();
  friend void protobuf_AssignDesc_E_5fIntimacy_2eproto();
  friend void protobuf_ShutdownFile_E_5fIntimacy_2eproto();

  void InitAsDefaultInstance();
  static E_IntimacyGift* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_IntimacyGift : public ::google::protobuf::Message {
 public:
  Sheet_IntimacyGift();
  virtual ~Sheet_IntimacyGift();

  Sheet_IntimacyGift(const Sheet_IntimacyGift& from);

  inline Sheet_IntimacyGift& operator=(const Sheet_IntimacyGift& from) {
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
  static const Sheet_IntimacyGift& default_instance();

  void Swap(Sheet_IntimacyGift* other);

  // implements Message ----------------------------------------------

  Sheet_IntimacyGift* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_IntimacyGift& from);
  void MergeFrom(const Sheet_IntimacyGift& from);
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

  // repeated .proto_ff.E_IntimacyGift E_IntimacyGift_List = 1;
  inline int e_intimacygift_list_size() const;
  inline void clear_e_intimacygift_list();
  static const int kEIntimacyGiftListFieldNumber = 1;
  inline const ::proto_ff::E_IntimacyGift& e_intimacygift_list(int index) const;
  inline ::proto_ff::E_IntimacyGift* mutable_e_intimacygift_list(int index);
  inline ::proto_ff::E_IntimacyGift* add_e_intimacygift_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyGift >&
      e_intimacygift_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyGift >*
      mutable_e_intimacygift_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_IntimacyGift)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyGift > e_intimacygift_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fIntimacy_2eproto();
  friend void protobuf_AssignDesc_E_5fIntimacy_2eproto();
  friend void protobuf_ShutdownFile_E_5fIntimacy_2eproto();

  void InitAsDefaultInstance();
  static Sheet_IntimacyGift* default_instance_;
};
// ===================================================================


// ===================================================================

// E_IntimacyIntimacyAttributeDesc

// optional int32 m_value = 1;
inline bool E_IntimacyIntimacyAttributeDesc::has_m_value() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_IntimacyIntimacyAttributeDesc::set_has_m_value() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_IntimacyIntimacyAttributeDesc::clear_has_m_value() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_IntimacyIntimacyAttributeDesc::clear_m_value() {
  m_value_ = 0;
  clear_has_m_value();
}
inline ::google::protobuf::int32 E_IntimacyIntimacyAttributeDesc::m_value() const {
  return m_value_;
}
inline void E_IntimacyIntimacyAttributeDesc::set_m_value(::google::protobuf::int32 value) {
  set_has_m_value();
  m_value_ = value;
}

// optional int32 m_type = 2;
inline bool E_IntimacyIntimacyAttributeDesc::has_m_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_IntimacyIntimacyAttributeDesc::set_has_m_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_IntimacyIntimacyAttributeDesc::clear_has_m_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_IntimacyIntimacyAttributeDesc::clear_m_type() {
  m_type_ = 0;
  clear_has_m_type();
}
inline ::google::protobuf::int32 E_IntimacyIntimacyAttributeDesc::m_type() const {
  return m_type_;
}
inline void E_IntimacyIntimacyAttributeDesc::set_m_type(::google::protobuf::int32 value) {
  set_has_m_type();
  m_type_ = value;
}

// -------------------------------------------------------------------

// E_IntimacyIntimacy

// optional int32 m_lv = 1;
inline bool E_IntimacyIntimacy::has_m_lv() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_IntimacyIntimacy::set_has_m_lv() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_IntimacyIntimacy::clear_has_m_lv() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_IntimacyIntimacy::clear_m_lv() {
  m_lv_ = 0;
  clear_has_m_lv();
}
inline ::google::protobuf::int32 E_IntimacyIntimacy::m_lv() const {
  return m_lv_;
}
inline void E_IntimacyIntimacy::set_m_lv(::google::protobuf::int32 value) {
  set_has_m_lv();
  m_lv_ = value;
}

// optional int32 m_intimacymin = 2;
inline bool E_IntimacyIntimacy::has_m_intimacymin() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_IntimacyIntimacy::set_has_m_intimacymin() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_IntimacyIntimacy::clear_has_m_intimacymin() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_IntimacyIntimacy::clear_m_intimacymin() {
  m_intimacymin_ = 0;
  clear_has_m_intimacymin();
}
inline ::google::protobuf::int32 E_IntimacyIntimacy::m_intimacymin() const {
  return m_intimacymin_;
}
inline void E_IntimacyIntimacy::set_m_intimacymin(::google::protobuf::int32 value) {
  set_has_m_intimacymin();
  m_intimacymin_ = value;
}

// optional int32 m_intimacymax = 3;
inline bool E_IntimacyIntimacy::has_m_intimacymax() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_IntimacyIntimacy::set_has_m_intimacymax() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_IntimacyIntimacy::clear_has_m_intimacymax() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_IntimacyIntimacy::clear_m_intimacymax() {
  m_intimacymax_ = 0;
  clear_has_m_intimacymax();
}
inline ::google::protobuf::int32 E_IntimacyIntimacy::m_intimacymax() const {
  return m_intimacymax_;
}
inline void E_IntimacyIntimacy::set_m_intimacymax(::google::protobuf::int32 value) {
  set_has_m_intimacymax();
  m_intimacymax_ = value;
}

// repeated .proto_ff.E_IntimacyIntimacyAttributeDesc m_attribute = 4;
inline int E_IntimacyIntimacy::m_attribute_size() const {
  return m_attribute_.size();
}
inline void E_IntimacyIntimacy::clear_m_attribute() {
  m_attribute_.Clear();
}
inline const ::proto_ff::E_IntimacyIntimacyAttributeDesc& E_IntimacyIntimacy::m_attribute(int index) const {
  return m_attribute_.Get(index);
}
inline ::proto_ff::E_IntimacyIntimacyAttributeDesc* E_IntimacyIntimacy::mutable_m_attribute(int index) {
  return m_attribute_.Mutable(index);
}
inline ::proto_ff::E_IntimacyIntimacyAttributeDesc* E_IntimacyIntimacy::add_m_attribute() {
  return m_attribute_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacyAttributeDesc >&
E_IntimacyIntimacy::m_attribute() const {
  return m_attribute_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacyAttributeDesc >*
E_IntimacyIntimacy::mutable_m_attribute() {
  return &m_attribute_;
}

// -------------------------------------------------------------------

// Sheet_IntimacyIntimacy

// repeated .proto_ff.E_IntimacyIntimacy E_IntimacyIntimacy_List = 1;
inline int Sheet_IntimacyIntimacy::e_intimacyintimacy_list_size() const {
  return e_intimacyintimacy_list_.size();
}
inline void Sheet_IntimacyIntimacy::clear_e_intimacyintimacy_list() {
  e_intimacyintimacy_list_.Clear();
}
inline const ::proto_ff::E_IntimacyIntimacy& Sheet_IntimacyIntimacy::e_intimacyintimacy_list(int index) const {
  return e_intimacyintimacy_list_.Get(index);
}
inline ::proto_ff::E_IntimacyIntimacy* Sheet_IntimacyIntimacy::mutable_e_intimacyintimacy_list(int index) {
  return e_intimacyintimacy_list_.Mutable(index);
}
inline ::proto_ff::E_IntimacyIntimacy* Sheet_IntimacyIntimacy::add_e_intimacyintimacy_list() {
  return e_intimacyintimacy_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacy >&
Sheet_IntimacyIntimacy::e_intimacyintimacy_list() const {
  return e_intimacyintimacy_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyIntimacy >*
Sheet_IntimacyIntimacy::mutable_e_intimacyintimacy_list() {
  return &e_intimacyintimacy_list_;
}

// -------------------------------------------------------------------

// E_IntimacyGift

// optional int32 m_mallid = 1;
inline bool E_IntimacyGift::has_m_mallid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_IntimacyGift::set_has_m_mallid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_IntimacyGift::clear_has_m_mallid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_IntimacyGift::clear_m_mallid() {
  m_mallid_ = 0;
  clear_has_m_mallid();
}
inline ::google::protobuf::int32 E_IntimacyGift::m_mallid() const {
  return m_mallid_;
}
inline void E_IntimacyGift::set_m_mallid(::google::protobuf::int32 value) {
  set_has_m_mallid();
  m_mallid_ = value;
}

// optional int32 m_itemid = 2;
inline bool E_IntimacyGift::has_m_itemid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_IntimacyGift::set_has_m_itemid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_IntimacyGift::clear_has_m_itemid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_IntimacyGift::clear_m_itemid() {
  m_itemid_ = 0;
  clear_has_m_itemid();
}
inline ::google::protobuf::int32 E_IntimacyGift::m_itemid() const {
  return m_itemid_;
}
inline void E_IntimacyGift::set_m_itemid(::google::protobuf::int32 value) {
  set_has_m_itemid();
  m_itemid_ = value;
}

// optional int32 m_nametype = 3;
inline bool E_IntimacyGift::has_m_nametype() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_IntimacyGift::set_has_m_nametype() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_IntimacyGift::clear_has_m_nametype() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_IntimacyGift::clear_m_nametype() {
  m_nametype_ = 0;
  clear_has_m_nametype();
}
inline ::google::protobuf::int32 E_IntimacyGift::m_nametype() const {
  return m_nametype_;
}
inline void E_IntimacyGift::set_m_nametype(::google::protobuf::int32 value) {
  set_has_m_nametype();
  m_nametype_ = value;
}

// optional string m_uipic = 4;
inline bool E_IntimacyGift::has_m_uipic() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_IntimacyGift::set_has_m_uipic() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_IntimacyGift::clear_has_m_uipic() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_IntimacyGift::clear_m_uipic() {
  if (m_uipic_ != &::google::protobuf::internal::kEmptyString) {
    m_uipic_->clear();
  }
  clear_has_m_uipic();
}
inline const ::std::string& E_IntimacyGift::m_uipic() const {
  return *m_uipic_;
}
inline void E_IntimacyGift::set_m_uipic(const ::std::string& value) {
  set_has_m_uipic();
  if (m_uipic_ == &::google::protobuf::internal::kEmptyString) {
    m_uipic_ = new ::std::string;
  }
  m_uipic_->assign(value);
}
inline void E_IntimacyGift::set_m_uipic(const char* value) {
  set_has_m_uipic();
  if (m_uipic_ == &::google::protobuf::internal::kEmptyString) {
    m_uipic_ = new ::std::string;
  }
  m_uipic_->assign(value);
}
inline void E_IntimacyGift::set_m_uipic(const char* value, size_t size) {
  set_has_m_uipic();
  if (m_uipic_ == &::google::protobuf::internal::kEmptyString) {
    m_uipic_ = new ::std::string;
  }
  m_uipic_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_IntimacyGift::mutable_m_uipic() {
  set_has_m_uipic();
  if (m_uipic_ == &::google::protobuf::internal::kEmptyString) {
    m_uipic_ = new ::std::string;
  }
  return m_uipic_;
}
inline ::std::string* E_IntimacyGift::release_m_uipic() {
  clear_has_m_uipic();
  if (m_uipic_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_uipic_;
    m_uipic_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_IntimacyGift::set_allocated_m_uipic(::std::string* m_uipic) {
  if (m_uipic_ != &::google::protobuf::internal::kEmptyString) {
    delete m_uipic_;
  }
  if (m_uipic) {
    set_has_m_uipic();
    m_uipic_ = m_uipic;
  } else {
    clear_has_m_uipic();
    m_uipic_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 m_intimacy = 5;
inline bool E_IntimacyGift::has_m_intimacy() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_IntimacyGift::set_has_m_intimacy() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_IntimacyGift::clear_has_m_intimacy() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_IntimacyGift::clear_m_intimacy() {
  m_intimacy_ = 0;
  clear_has_m_intimacy();
}
inline ::google::protobuf::int32 E_IntimacyGift::m_intimacy() const {
  return m_intimacy_;
}
inline void E_IntimacyGift::set_m_intimacy(::google::protobuf::int32 value) {
  set_has_m_intimacy();
  m_intimacy_ = value;
}

// optional int32 m_charm = 6;
inline bool E_IntimacyGift::has_m_charm() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_IntimacyGift::set_has_m_charm() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_IntimacyGift::clear_has_m_charm() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_IntimacyGift::clear_m_charm() {
  m_charm_ = 0;
  clear_has_m_charm();
}
inline ::google::protobuf::int32 E_IntimacyGift::m_charm() const {
  return m_charm_;
}
inline void E_IntimacyGift::set_m_charm(::google::protobuf::int32 value) {
  set_has_m_charm();
  m_charm_ = value;
}

// -------------------------------------------------------------------

// Sheet_IntimacyGift

// repeated .proto_ff.E_IntimacyGift E_IntimacyGift_List = 1;
inline int Sheet_IntimacyGift::e_intimacygift_list_size() const {
  return e_intimacygift_list_.size();
}
inline void Sheet_IntimacyGift::clear_e_intimacygift_list() {
  e_intimacygift_list_.Clear();
}
inline const ::proto_ff::E_IntimacyGift& Sheet_IntimacyGift::e_intimacygift_list(int index) const {
  return e_intimacygift_list_.Get(index);
}
inline ::proto_ff::E_IntimacyGift* Sheet_IntimacyGift::mutable_e_intimacygift_list(int index) {
  return e_intimacygift_list_.Mutable(index);
}
inline ::proto_ff::E_IntimacyGift* Sheet_IntimacyGift::add_e_intimacygift_list() {
  return e_intimacygift_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyGift >&
Sheet_IntimacyGift::e_intimacygift_list() const {
  return e_intimacygift_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_IntimacyGift >*
Sheet_IntimacyGift::mutable_e_intimacygift_list() {
  return &e_intimacygift_list_;
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

#endif  // PROTOBUF_E_5fIntimacy_2eproto__INCLUDED
