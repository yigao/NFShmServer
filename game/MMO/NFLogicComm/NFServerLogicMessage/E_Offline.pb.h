// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Offline.proto

#ifndef PROTOBUF_E_5fOffline_2eproto__INCLUDED
#define PROTOBUF_E_5fOffline_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fOffline_2eproto();
void protobuf_AssignDesc_E_5fOffline_2eproto();
void protobuf_ShutdownFile_E_5fOffline_2eproto();

class E_OfflineOffline;
class Sheet_OfflineOffline;
class E_OfflineItemlistItemDesc;
class E_OfflineItemlist;
class Sheet_OfflineItemlist;

// ===================================================================

class E_OfflineOffline : public ::google::protobuf::Message {
 public:
  E_OfflineOffline();
  virtual ~E_OfflineOffline();

  E_OfflineOffline(const E_OfflineOffline& from);

  inline E_OfflineOffline& operator=(const E_OfflineOffline& from) {
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
  static const E_OfflineOffline& default_instance();

  void Swap(E_OfflineOffline* other);

  // implements Message ----------------------------------------------

  E_OfflineOffline* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_OfflineOffline& from);
  void MergeFrom(const E_OfflineOffline& from);
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

  // optional int64 m_offlineexp = 2;
  inline bool has_m_offlineexp() const;
  inline void clear_m_offlineexp();
  static const int kMOfflineexpFieldNumber = 2;
  inline ::google::protobuf::int64 m_offlineexp() const;
  inline void set_m_offlineexp(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_OfflineOffline)
 private:
  inline void set_has_m_lv();
  inline void clear_has_m_lv();
  inline void set_has_m_offlineexp();
  inline void clear_has_m_offlineexp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 m_offlineexp_;
  ::google::protobuf::int32 m_lv_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fOffline_2eproto();
  friend void protobuf_AssignDesc_E_5fOffline_2eproto();
  friend void protobuf_ShutdownFile_E_5fOffline_2eproto();

  void InitAsDefaultInstance();
  static E_OfflineOffline* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_OfflineOffline : public ::google::protobuf::Message {
 public:
  Sheet_OfflineOffline();
  virtual ~Sheet_OfflineOffline();

  Sheet_OfflineOffline(const Sheet_OfflineOffline& from);

  inline Sheet_OfflineOffline& operator=(const Sheet_OfflineOffline& from) {
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
  static const Sheet_OfflineOffline& default_instance();

  void Swap(Sheet_OfflineOffline* other);

  // implements Message ----------------------------------------------

  Sheet_OfflineOffline* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_OfflineOffline& from);
  void MergeFrom(const Sheet_OfflineOffline& from);
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

  // repeated .proto_ff.E_OfflineOffline E_OfflineOffline_List = 1;
  inline int e_offlineoffline_list_size() const;
  inline void clear_e_offlineoffline_list();
  static const int kEOfflineOfflineListFieldNumber = 1;
  inline const ::proto_ff::E_OfflineOffline& e_offlineoffline_list(int index) const;
  inline ::proto_ff::E_OfflineOffline* mutable_e_offlineoffline_list(int index);
  inline ::proto_ff::E_OfflineOffline* add_e_offlineoffline_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineOffline >&
      e_offlineoffline_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineOffline >*
      mutable_e_offlineoffline_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_OfflineOffline)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineOffline > e_offlineoffline_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fOffline_2eproto();
  friend void protobuf_AssignDesc_E_5fOffline_2eproto();
  friend void protobuf_ShutdownFile_E_5fOffline_2eproto();

  void InitAsDefaultInstance();
  static Sheet_OfflineOffline* default_instance_;
};
// -------------------------------------------------------------------

class E_OfflineItemlistItemDesc : public ::google::protobuf::Message {
 public:
  E_OfflineItemlistItemDesc();
  virtual ~E_OfflineItemlistItemDesc();

  E_OfflineItemlistItemDesc(const E_OfflineItemlistItemDesc& from);

  inline E_OfflineItemlistItemDesc& operator=(const E_OfflineItemlistItemDesc& from) {
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
  static const E_OfflineItemlistItemDesc& default_instance();

  void Swap(E_OfflineItemlistItemDesc* other);

  // implements Message ----------------------------------------------

  E_OfflineItemlistItemDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_OfflineItemlistItemDesc& from);
  void MergeFrom(const E_OfflineItemlistItemDesc& from);
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

  // optional int32 m_vle = 1;
  inline bool has_m_vle() const;
  inline void clear_m_vle();
  static const int kMVleFieldNumber = 1;
  inline ::google::protobuf::int32 m_vle() const;
  inline void set_m_vle(::google::protobuf::int32 value);

  // optional int32 m_num = 2;
  inline bool has_m_num() const;
  inline void clear_m_num();
  static const int kMNumFieldNumber = 2;
  inline ::google::protobuf::int32 m_num() const;
  inline void set_m_num(::google::protobuf::int32 value);

  // optional int64 m_id = 3;
  inline bool has_m_id() const;
  inline void clear_m_id();
  static const int kMIdFieldNumber = 3;
  inline ::google::protobuf::int64 m_id() const;
  inline void set_m_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_OfflineItemlistItemDesc)
 private:
  inline void set_has_m_vle();
  inline void clear_has_m_vle();
  inline void set_has_m_num();
  inline void clear_has_m_num();
  inline void set_has_m_id();
  inline void clear_has_m_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_vle_;
  ::google::protobuf::int32 m_num_;
  ::google::protobuf::int64 m_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fOffline_2eproto();
  friend void protobuf_AssignDesc_E_5fOffline_2eproto();
  friend void protobuf_ShutdownFile_E_5fOffline_2eproto();

  void InitAsDefaultInstance();
  static E_OfflineItemlistItemDesc* default_instance_;
};
// -------------------------------------------------------------------

class E_OfflineItemlist : public ::google::protobuf::Message {
 public:
  E_OfflineItemlist();
  virtual ~E_OfflineItemlist();

  E_OfflineItemlist(const E_OfflineItemlist& from);

  inline E_OfflineItemlist& operator=(const E_OfflineItemlist& from) {
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
  static const E_OfflineItemlist& default_instance();

  void Swap(E_OfflineItemlist* other);

  // implements Message ----------------------------------------------

  E_OfflineItemlist* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_OfflineItemlist& from);
  void MergeFrom(const E_OfflineItemlist& from);
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

  // optional int32 m_lvdown = 2;
  inline bool has_m_lvdown() const;
  inline void clear_m_lvdown();
  static const int kMLvdownFieldNumber = 2;
  inline ::google::protobuf::int32 m_lvdown() const;
  inline void set_m_lvdown(::google::protobuf::int32 value);

  // optional int32 m_lvup = 3;
  inline bool has_m_lvup() const;
  inline void clear_m_lvup();
  static const int kMLvupFieldNumber = 3;
  inline ::google::protobuf::int32 m_lvup() const;
  inline void set_m_lvup(::google::protobuf::int32 value);

  // optional int32 m_daoju = 4;
  inline bool has_m_daoju() const;
  inline void clear_m_daoju();
  static const int kMDaojuFieldNumber = 4;
  inline ::google::protobuf::int32 m_daoju() const;
  inline void set_m_daoju(::google::protobuf::int32 value);

  // repeated .proto_ff.E_OfflineItemlistItemDesc m_item = 5;
  inline int m_item_size() const;
  inline void clear_m_item();
  static const int kMItemFieldNumber = 5;
  inline const ::proto_ff::E_OfflineItemlistItemDesc& m_item(int index) const;
  inline ::proto_ff::E_OfflineItemlistItemDesc* mutable_m_item(int index);
  inline ::proto_ff::E_OfflineItemlistItemDesc* add_m_item();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlistItemDesc >&
      m_item() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlistItemDesc >*
      mutable_m_item();

  // @@protoc_insertion_point(class_scope:proto_ff.E_OfflineItemlist)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_lvdown();
  inline void clear_has_m_lvdown();
  inline void set_has_m_lvup();
  inline void clear_has_m_lvup();
  inline void set_has_m_daoju();
  inline void clear_has_m_daoju();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_id_;
  ::google::protobuf::int32 m_lvdown_;
  ::google::protobuf::int32 m_lvup_;
  ::google::protobuf::int32 m_daoju_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlistItemDesc > m_item_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fOffline_2eproto();
  friend void protobuf_AssignDesc_E_5fOffline_2eproto();
  friend void protobuf_ShutdownFile_E_5fOffline_2eproto();

  void InitAsDefaultInstance();
  static E_OfflineItemlist* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_OfflineItemlist : public ::google::protobuf::Message {
 public:
  Sheet_OfflineItemlist();
  virtual ~Sheet_OfflineItemlist();

  Sheet_OfflineItemlist(const Sheet_OfflineItemlist& from);

  inline Sheet_OfflineItemlist& operator=(const Sheet_OfflineItemlist& from) {
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
  static const Sheet_OfflineItemlist& default_instance();

  void Swap(Sheet_OfflineItemlist* other);

  // implements Message ----------------------------------------------

  Sheet_OfflineItemlist* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_OfflineItemlist& from);
  void MergeFrom(const Sheet_OfflineItemlist& from);
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

  // repeated .proto_ff.E_OfflineItemlist E_OfflineItemlist_List = 1;
  inline int e_offlineitemlist_list_size() const;
  inline void clear_e_offlineitemlist_list();
  static const int kEOfflineItemlistListFieldNumber = 1;
  inline const ::proto_ff::E_OfflineItemlist& e_offlineitemlist_list(int index) const;
  inline ::proto_ff::E_OfflineItemlist* mutable_e_offlineitemlist_list(int index);
  inline ::proto_ff::E_OfflineItemlist* add_e_offlineitemlist_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlist >&
      e_offlineitemlist_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlist >*
      mutable_e_offlineitemlist_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_OfflineItemlist)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlist > e_offlineitemlist_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fOffline_2eproto();
  friend void protobuf_AssignDesc_E_5fOffline_2eproto();
  friend void protobuf_ShutdownFile_E_5fOffline_2eproto();

  void InitAsDefaultInstance();
  static Sheet_OfflineItemlist* default_instance_;
};
// ===================================================================


// ===================================================================

// E_OfflineOffline

// optional int32 m_lv = 1;
inline bool E_OfflineOffline::has_m_lv() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_OfflineOffline::set_has_m_lv() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_OfflineOffline::clear_has_m_lv() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_OfflineOffline::clear_m_lv() {
  m_lv_ = 0;
  clear_has_m_lv();
}
inline ::google::protobuf::int32 E_OfflineOffline::m_lv() const {
  return m_lv_;
}
inline void E_OfflineOffline::set_m_lv(::google::protobuf::int32 value) {
  set_has_m_lv();
  m_lv_ = value;
}

// optional int64 m_offlineexp = 2;
inline bool E_OfflineOffline::has_m_offlineexp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_OfflineOffline::set_has_m_offlineexp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_OfflineOffline::clear_has_m_offlineexp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_OfflineOffline::clear_m_offlineexp() {
  m_offlineexp_ = GOOGLE_LONGLONG(0);
  clear_has_m_offlineexp();
}
inline ::google::protobuf::int64 E_OfflineOffline::m_offlineexp() const {
  return m_offlineexp_;
}
inline void E_OfflineOffline::set_m_offlineexp(::google::protobuf::int64 value) {
  set_has_m_offlineexp();
  m_offlineexp_ = value;
}

// -------------------------------------------------------------------

// Sheet_OfflineOffline

// repeated .proto_ff.E_OfflineOffline E_OfflineOffline_List = 1;
inline int Sheet_OfflineOffline::e_offlineoffline_list_size() const {
  return e_offlineoffline_list_.size();
}
inline void Sheet_OfflineOffline::clear_e_offlineoffline_list() {
  e_offlineoffline_list_.Clear();
}
inline const ::proto_ff::E_OfflineOffline& Sheet_OfflineOffline::e_offlineoffline_list(int index) const {
  return e_offlineoffline_list_.Get(index);
}
inline ::proto_ff::E_OfflineOffline* Sheet_OfflineOffline::mutable_e_offlineoffline_list(int index) {
  return e_offlineoffline_list_.Mutable(index);
}
inline ::proto_ff::E_OfflineOffline* Sheet_OfflineOffline::add_e_offlineoffline_list() {
  return e_offlineoffline_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineOffline >&
Sheet_OfflineOffline::e_offlineoffline_list() const {
  return e_offlineoffline_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineOffline >*
Sheet_OfflineOffline::mutable_e_offlineoffline_list() {
  return &e_offlineoffline_list_;
}

// -------------------------------------------------------------------

// E_OfflineItemlistItemDesc

// optional int32 m_vle = 1;
inline bool E_OfflineItemlistItemDesc::has_m_vle() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_OfflineItemlistItemDesc::set_has_m_vle() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_OfflineItemlistItemDesc::clear_has_m_vle() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_OfflineItemlistItemDesc::clear_m_vle() {
  m_vle_ = 0;
  clear_has_m_vle();
}
inline ::google::protobuf::int32 E_OfflineItemlistItemDesc::m_vle() const {
  return m_vle_;
}
inline void E_OfflineItemlistItemDesc::set_m_vle(::google::protobuf::int32 value) {
  set_has_m_vle();
  m_vle_ = value;
}

// optional int32 m_num = 2;
inline bool E_OfflineItemlistItemDesc::has_m_num() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_OfflineItemlistItemDesc::set_has_m_num() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_OfflineItemlistItemDesc::clear_has_m_num() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_OfflineItemlistItemDesc::clear_m_num() {
  m_num_ = 0;
  clear_has_m_num();
}
inline ::google::protobuf::int32 E_OfflineItemlistItemDesc::m_num() const {
  return m_num_;
}
inline void E_OfflineItemlistItemDesc::set_m_num(::google::protobuf::int32 value) {
  set_has_m_num();
  m_num_ = value;
}

// optional int64 m_id = 3;
inline bool E_OfflineItemlistItemDesc::has_m_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_OfflineItemlistItemDesc::set_has_m_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_OfflineItemlistItemDesc::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_OfflineItemlistItemDesc::clear_m_id() {
  m_id_ = GOOGLE_LONGLONG(0);
  clear_has_m_id();
}
inline ::google::protobuf::int64 E_OfflineItemlistItemDesc::m_id() const {
  return m_id_;
}
inline void E_OfflineItemlistItemDesc::set_m_id(::google::protobuf::int64 value) {
  set_has_m_id();
  m_id_ = value;
}

// -------------------------------------------------------------------

// E_OfflineItemlist

// optional int32 m_id = 1;
inline bool E_OfflineItemlist::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_OfflineItemlist::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_OfflineItemlist::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_OfflineItemlist::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_OfflineItemlist::m_id() const {
  return m_id_;
}
inline void E_OfflineItemlist::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_lvdown = 2;
inline bool E_OfflineItemlist::has_m_lvdown() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_OfflineItemlist::set_has_m_lvdown() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_OfflineItemlist::clear_has_m_lvdown() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_OfflineItemlist::clear_m_lvdown() {
  m_lvdown_ = 0;
  clear_has_m_lvdown();
}
inline ::google::protobuf::int32 E_OfflineItemlist::m_lvdown() const {
  return m_lvdown_;
}
inline void E_OfflineItemlist::set_m_lvdown(::google::protobuf::int32 value) {
  set_has_m_lvdown();
  m_lvdown_ = value;
}

// optional int32 m_lvup = 3;
inline bool E_OfflineItemlist::has_m_lvup() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_OfflineItemlist::set_has_m_lvup() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_OfflineItemlist::clear_has_m_lvup() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_OfflineItemlist::clear_m_lvup() {
  m_lvup_ = 0;
  clear_has_m_lvup();
}
inline ::google::protobuf::int32 E_OfflineItemlist::m_lvup() const {
  return m_lvup_;
}
inline void E_OfflineItemlist::set_m_lvup(::google::protobuf::int32 value) {
  set_has_m_lvup();
  m_lvup_ = value;
}

// optional int32 m_daoju = 4;
inline bool E_OfflineItemlist::has_m_daoju() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_OfflineItemlist::set_has_m_daoju() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_OfflineItemlist::clear_has_m_daoju() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_OfflineItemlist::clear_m_daoju() {
  m_daoju_ = 0;
  clear_has_m_daoju();
}
inline ::google::protobuf::int32 E_OfflineItemlist::m_daoju() const {
  return m_daoju_;
}
inline void E_OfflineItemlist::set_m_daoju(::google::protobuf::int32 value) {
  set_has_m_daoju();
  m_daoju_ = value;
}

// repeated .proto_ff.E_OfflineItemlistItemDesc m_item = 5;
inline int E_OfflineItemlist::m_item_size() const {
  return m_item_.size();
}
inline void E_OfflineItemlist::clear_m_item() {
  m_item_.Clear();
}
inline const ::proto_ff::E_OfflineItemlistItemDesc& E_OfflineItemlist::m_item(int index) const {
  return m_item_.Get(index);
}
inline ::proto_ff::E_OfflineItemlistItemDesc* E_OfflineItemlist::mutable_m_item(int index) {
  return m_item_.Mutable(index);
}
inline ::proto_ff::E_OfflineItemlistItemDesc* E_OfflineItemlist::add_m_item() {
  return m_item_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlistItemDesc >&
E_OfflineItemlist::m_item() const {
  return m_item_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlistItemDesc >*
E_OfflineItemlist::mutable_m_item() {
  return &m_item_;
}

// -------------------------------------------------------------------

// Sheet_OfflineItemlist

// repeated .proto_ff.E_OfflineItemlist E_OfflineItemlist_List = 1;
inline int Sheet_OfflineItemlist::e_offlineitemlist_list_size() const {
  return e_offlineitemlist_list_.size();
}
inline void Sheet_OfflineItemlist::clear_e_offlineitemlist_list() {
  e_offlineitemlist_list_.Clear();
}
inline const ::proto_ff::E_OfflineItemlist& Sheet_OfflineItemlist::e_offlineitemlist_list(int index) const {
  return e_offlineitemlist_list_.Get(index);
}
inline ::proto_ff::E_OfflineItemlist* Sheet_OfflineItemlist::mutable_e_offlineitemlist_list(int index) {
  return e_offlineitemlist_list_.Mutable(index);
}
inline ::proto_ff::E_OfflineItemlist* Sheet_OfflineItemlist::add_e_offlineitemlist_list() {
  return e_offlineitemlist_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlist >&
Sheet_OfflineItemlist::e_offlineitemlist_list() const {
  return e_offlineitemlist_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_OfflineItemlist >*
Sheet_OfflineItemlist::mutable_e_offlineitemlist_list() {
  return &e_offlineitemlist_list_;
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

#endif  // PROTOBUF_E_5fOffline_2eproto__INCLUDED
