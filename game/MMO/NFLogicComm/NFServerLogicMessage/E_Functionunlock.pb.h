// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Functionunlock.proto

#ifndef PROTOBUF_E_5fFunctionunlock_2eproto__INCLUDED
#define PROTOBUF_E_5fFunctionunlock_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fFunctionunlock_2eproto();
void protobuf_AssignDesc_E_5fFunctionunlock_2eproto();
void protobuf_ShutdownFile_E_5fFunctionunlock_2eproto();

class E_FunctionunlockFunctionunlock;
class Sheet_FunctionunlockFunctionunlock;
class E_FunctionunlockPreview;
class Sheet_FunctionunlockPreview;

// ===================================================================

class E_FunctionunlockFunctionunlock : public ::google::protobuf::Message {
 public:
  E_FunctionunlockFunctionunlock();
  virtual ~E_FunctionunlockFunctionunlock();

  E_FunctionunlockFunctionunlock(const E_FunctionunlockFunctionunlock& from);

  inline E_FunctionunlockFunctionunlock& operator=(const E_FunctionunlockFunctionunlock& from) {
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
  static const E_FunctionunlockFunctionunlock& default_instance();

  void Swap(E_FunctionunlockFunctionunlock* other);

  // implements Message ----------------------------------------------

  E_FunctionunlockFunctionunlock* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_FunctionunlockFunctionunlock& from);
  void MergeFrom(const E_FunctionunlockFunctionunlock& from);
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

  // optional int32 m_functionid = 1;
  inline bool has_m_functionid() const;
  inline void clear_m_functionid();
  static const int kMFunctionidFieldNumber = 1;
  inline ::google::protobuf::int32 m_functionid() const;
  inline void set_m_functionid(::google::protobuf::int32 value);

  // optional int32 m_opendaily = 2;
  inline bool has_m_opendaily() const;
  inline void clear_m_opendaily();
  static const int kMOpendailyFieldNumber = 2;
  inline ::google::protobuf::int32 m_opendaily() const;
  inline void set_m_opendaily(::google::protobuf::int32 value);

  // optional int32 m_opentype = 3;
  inline bool has_m_opentype() const;
  inline void clear_m_opentype();
  static const int kMOpentypeFieldNumber = 3;
  inline ::google::protobuf::int32 m_opentype() const;
  inline void set_m_opentype(::google::protobuf::int32 value);

  // optional int64 m_openval = 4;
  inline bool has_m_openval() const;
  inline void clear_m_openval();
  static const int kMOpenvalFieldNumber = 4;
  inline ::google::protobuf::int64 m_openval() const;
  inline void set_m_openval(::google::protobuf::int64 value);

  // optional int32 m_defaultclosed = 5;
  inline bool has_m_defaultclosed() const;
  inline void clear_m_defaultclosed();
  static const int kMDefaultclosedFieldNumber = 5;
  inline ::google::protobuf::int32 m_defaultclosed() const;
  inline void set_m_defaultclosed(::google::protobuf::int32 value);

  // optional int32 m_iconopenval = 6;
  inline bool has_m_iconopenval() const;
  inline void clear_m_iconopenval();
  static const int kMIconopenvalFieldNumber = 6;
  inline ::google::protobuf::int32 m_iconopenval() const;
  inline void set_m_iconopenval(::google::protobuf::int32 value);

  // optional int32 m_icondisapearid = 7;
  inline bool has_m_icondisapearid() const;
  inline void clear_m_icondisapearid();
  static const int kMIcondisapearidFieldNumber = 7;
  inline ::google::protobuf::int32 m_icondisapearid() const;
  inline void set_m_icondisapearid(::google::protobuf::int32 value);

  // optional int32 m_belong = 8;
  inline bool has_m_belong() const;
  inline void clear_m_belong();
  static const int kMBelongFieldNumber = 8;
  inline ::google::protobuf::int32 m_belong() const;
  inline void set_m_belong(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_FunctionunlockFunctionunlock)
 private:
  inline void set_has_m_functionid();
  inline void clear_has_m_functionid();
  inline void set_has_m_opendaily();
  inline void clear_has_m_opendaily();
  inline void set_has_m_opentype();
  inline void clear_has_m_opentype();
  inline void set_has_m_openval();
  inline void clear_has_m_openval();
  inline void set_has_m_defaultclosed();
  inline void clear_has_m_defaultclosed();
  inline void set_has_m_iconopenval();
  inline void clear_has_m_iconopenval();
  inline void set_has_m_icondisapearid();
  inline void clear_has_m_icondisapearid();
  inline void set_has_m_belong();
  inline void clear_has_m_belong();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_functionid_;
  ::google::protobuf::int32 m_opendaily_;
  ::google::protobuf::int64 m_openval_;
  ::google::protobuf::int32 m_opentype_;
  ::google::protobuf::int32 m_defaultclosed_;
  ::google::protobuf::int32 m_iconopenval_;
  ::google::protobuf::int32 m_icondisapearid_;
  ::google::protobuf::int32 m_belong_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_AssignDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_ShutdownFile_E_5fFunctionunlock_2eproto();

  void InitAsDefaultInstance();
  static E_FunctionunlockFunctionunlock* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_FunctionunlockFunctionunlock : public ::google::protobuf::Message {
 public:
  Sheet_FunctionunlockFunctionunlock();
  virtual ~Sheet_FunctionunlockFunctionunlock();

  Sheet_FunctionunlockFunctionunlock(const Sheet_FunctionunlockFunctionunlock& from);

  inline Sheet_FunctionunlockFunctionunlock& operator=(const Sheet_FunctionunlockFunctionunlock& from) {
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
  static const Sheet_FunctionunlockFunctionunlock& default_instance();

  void Swap(Sheet_FunctionunlockFunctionunlock* other);

  // implements Message ----------------------------------------------

  Sheet_FunctionunlockFunctionunlock* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_FunctionunlockFunctionunlock& from);
  void MergeFrom(const Sheet_FunctionunlockFunctionunlock& from);
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

  // repeated .proto_ff.E_FunctionunlockFunctionunlock E_FunctionunlockFunctionunlock_List = 1;
  inline int e_functionunlockfunctionunlock_list_size() const;
  inline void clear_e_functionunlockfunctionunlock_list();
  static const int kEFunctionunlockFunctionunlockListFieldNumber = 1;
  inline const ::proto_ff::E_FunctionunlockFunctionunlock& e_functionunlockfunctionunlock_list(int index) const;
  inline ::proto_ff::E_FunctionunlockFunctionunlock* mutable_e_functionunlockfunctionunlock_list(int index);
  inline ::proto_ff::E_FunctionunlockFunctionunlock* add_e_functionunlockfunctionunlock_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockFunctionunlock >&
      e_functionunlockfunctionunlock_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockFunctionunlock >*
      mutable_e_functionunlockfunctionunlock_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_FunctionunlockFunctionunlock)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockFunctionunlock > e_functionunlockfunctionunlock_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_AssignDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_ShutdownFile_E_5fFunctionunlock_2eproto();

  void InitAsDefaultInstance();
  static Sheet_FunctionunlockFunctionunlock* default_instance_;
};
// -------------------------------------------------------------------

class E_FunctionunlockPreview : public ::google::protobuf::Message {
 public:
  E_FunctionunlockPreview();
  virtual ~E_FunctionunlockPreview();

  E_FunctionunlockPreview(const E_FunctionunlockPreview& from);

  inline E_FunctionunlockPreview& operator=(const E_FunctionunlockPreview& from) {
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
  static const E_FunctionunlockPreview& default_instance();

  void Swap(E_FunctionunlockPreview* other);

  // implements Message ----------------------------------------------

  E_FunctionunlockPreview* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_FunctionunlockPreview& from);
  void MergeFrom(const E_FunctionunlockPreview& from);
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

  // optional int32 m_functionid = 1;
  inline bool has_m_functionid() const;
  inline void clear_m_functionid();
  static const int kMFunctionidFieldNumber = 1;
  inline ::google::protobuf::int32 m_functionid() const;
  inline void set_m_functionid(::google::protobuf::int32 value);

  // optional int32 m_rewarditem = 2;
  inline bool has_m_rewarditem() const;
  inline void clear_m_rewarditem();
  static const int kMRewarditemFieldNumber = 2;
  inline ::google::protobuf::int32 m_rewarditem() const;
  inline void set_m_rewarditem(::google::protobuf::int32 value);

  // optional int32 m_rewardnum = 3;
  inline bool has_m_rewardnum() const;
  inline void clear_m_rewardnum();
  static const int kMRewardnumFieldNumber = 3;
  inline ::google::protobuf::int32 m_rewardnum() const;
  inline void set_m_rewardnum(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_FunctionunlockPreview)
 private:
  inline void set_has_m_functionid();
  inline void clear_has_m_functionid();
  inline void set_has_m_rewarditem();
  inline void clear_has_m_rewarditem();
  inline void set_has_m_rewardnum();
  inline void clear_has_m_rewardnum();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_functionid_;
  ::google::protobuf::int32 m_rewarditem_;
  ::google::protobuf::int32 m_rewardnum_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_AssignDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_ShutdownFile_E_5fFunctionunlock_2eproto();

  void InitAsDefaultInstance();
  static E_FunctionunlockPreview* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_FunctionunlockPreview : public ::google::protobuf::Message {
 public:
  Sheet_FunctionunlockPreview();
  virtual ~Sheet_FunctionunlockPreview();

  Sheet_FunctionunlockPreview(const Sheet_FunctionunlockPreview& from);

  inline Sheet_FunctionunlockPreview& operator=(const Sheet_FunctionunlockPreview& from) {
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
  static const Sheet_FunctionunlockPreview& default_instance();

  void Swap(Sheet_FunctionunlockPreview* other);

  // implements Message ----------------------------------------------

  Sheet_FunctionunlockPreview* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_FunctionunlockPreview& from);
  void MergeFrom(const Sheet_FunctionunlockPreview& from);
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

  // repeated .proto_ff.E_FunctionunlockPreview E_FunctionunlockPreview_List = 1;
  inline int e_functionunlockpreview_list_size() const;
  inline void clear_e_functionunlockpreview_list();
  static const int kEFunctionunlockPreviewListFieldNumber = 1;
  inline const ::proto_ff::E_FunctionunlockPreview& e_functionunlockpreview_list(int index) const;
  inline ::proto_ff::E_FunctionunlockPreview* mutable_e_functionunlockpreview_list(int index);
  inline ::proto_ff::E_FunctionunlockPreview* add_e_functionunlockpreview_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockPreview >&
      e_functionunlockpreview_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockPreview >*
      mutable_e_functionunlockpreview_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_FunctionunlockPreview)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockPreview > e_functionunlockpreview_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_AssignDesc_E_5fFunctionunlock_2eproto();
  friend void protobuf_ShutdownFile_E_5fFunctionunlock_2eproto();

  void InitAsDefaultInstance();
  static Sheet_FunctionunlockPreview* default_instance_;
};
// ===================================================================


// ===================================================================

// E_FunctionunlockFunctionunlock

// optional int32 m_functionid = 1;
inline bool E_FunctionunlockFunctionunlock::has_m_functionid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_functionid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_functionid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_functionid() {
  m_functionid_ = 0;
  clear_has_m_functionid();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_functionid() const {
  return m_functionid_;
}
inline void E_FunctionunlockFunctionunlock::set_m_functionid(::google::protobuf::int32 value) {
  set_has_m_functionid();
  m_functionid_ = value;
}

// optional int32 m_opendaily = 2;
inline bool E_FunctionunlockFunctionunlock::has_m_opendaily() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_opendaily() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_opendaily() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_opendaily() {
  m_opendaily_ = 0;
  clear_has_m_opendaily();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_opendaily() const {
  return m_opendaily_;
}
inline void E_FunctionunlockFunctionunlock::set_m_opendaily(::google::protobuf::int32 value) {
  set_has_m_opendaily();
  m_opendaily_ = value;
}

// optional int32 m_opentype = 3;
inline bool E_FunctionunlockFunctionunlock::has_m_opentype() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_opentype() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_opentype() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_opentype() {
  m_opentype_ = 0;
  clear_has_m_opentype();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_opentype() const {
  return m_opentype_;
}
inline void E_FunctionunlockFunctionunlock::set_m_opentype(::google::protobuf::int32 value) {
  set_has_m_opentype();
  m_opentype_ = value;
}

// optional int64 m_openval = 4;
inline bool E_FunctionunlockFunctionunlock::has_m_openval() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_openval() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_openval() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_openval() {
  m_openval_ = GOOGLE_LONGLONG(0);
  clear_has_m_openval();
}
inline ::google::protobuf::int64 E_FunctionunlockFunctionunlock::m_openval() const {
  return m_openval_;
}
inline void E_FunctionunlockFunctionunlock::set_m_openval(::google::protobuf::int64 value) {
  set_has_m_openval();
  m_openval_ = value;
}

// optional int32 m_defaultclosed = 5;
inline bool E_FunctionunlockFunctionunlock::has_m_defaultclosed() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_defaultclosed() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_defaultclosed() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_defaultclosed() {
  m_defaultclosed_ = 0;
  clear_has_m_defaultclosed();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_defaultclosed() const {
  return m_defaultclosed_;
}
inline void E_FunctionunlockFunctionunlock::set_m_defaultclosed(::google::protobuf::int32 value) {
  set_has_m_defaultclosed();
  m_defaultclosed_ = value;
}

// optional int32 m_iconopenval = 6;
inline bool E_FunctionunlockFunctionunlock::has_m_iconopenval() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_iconopenval() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_iconopenval() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_iconopenval() {
  m_iconopenval_ = 0;
  clear_has_m_iconopenval();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_iconopenval() const {
  return m_iconopenval_;
}
inline void E_FunctionunlockFunctionunlock::set_m_iconopenval(::google::protobuf::int32 value) {
  set_has_m_iconopenval();
  m_iconopenval_ = value;
}

// optional int32 m_icondisapearid = 7;
inline bool E_FunctionunlockFunctionunlock::has_m_icondisapearid() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_icondisapearid() {
  _has_bits_[0] |= 0x00000040u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_icondisapearid() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_icondisapearid() {
  m_icondisapearid_ = 0;
  clear_has_m_icondisapearid();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_icondisapearid() const {
  return m_icondisapearid_;
}
inline void E_FunctionunlockFunctionunlock::set_m_icondisapearid(::google::protobuf::int32 value) {
  set_has_m_icondisapearid();
  m_icondisapearid_ = value;
}

// optional int32 m_belong = 8;
inline bool E_FunctionunlockFunctionunlock::has_m_belong() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void E_FunctionunlockFunctionunlock::set_has_m_belong() {
  _has_bits_[0] |= 0x00000080u;
}
inline void E_FunctionunlockFunctionunlock::clear_has_m_belong() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void E_FunctionunlockFunctionunlock::clear_m_belong() {
  m_belong_ = 0;
  clear_has_m_belong();
}
inline ::google::protobuf::int32 E_FunctionunlockFunctionunlock::m_belong() const {
  return m_belong_;
}
inline void E_FunctionunlockFunctionunlock::set_m_belong(::google::protobuf::int32 value) {
  set_has_m_belong();
  m_belong_ = value;
}

// -------------------------------------------------------------------

// Sheet_FunctionunlockFunctionunlock

// repeated .proto_ff.E_FunctionunlockFunctionunlock E_FunctionunlockFunctionunlock_List = 1;
inline int Sheet_FunctionunlockFunctionunlock::e_functionunlockfunctionunlock_list_size() const {
  return e_functionunlockfunctionunlock_list_.size();
}
inline void Sheet_FunctionunlockFunctionunlock::clear_e_functionunlockfunctionunlock_list() {
  e_functionunlockfunctionunlock_list_.Clear();
}
inline const ::proto_ff::E_FunctionunlockFunctionunlock& Sheet_FunctionunlockFunctionunlock::e_functionunlockfunctionunlock_list(int index) const {
  return e_functionunlockfunctionunlock_list_.Get(index);
}
inline ::proto_ff::E_FunctionunlockFunctionunlock* Sheet_FunctionunlockFunctionunlock::mutable_e_functionunlockfunctionunlock_list(int index) {
  return e_functionunlockfunctionunlock_list_.Mutable(index);
}
inline ::proto_ff::E_FunctionunlockFunctionunlock* Sheet_FunctionunlockFunctionunlock::add_e_functionunlockfunctionunlock_list() {
  return e_functionunlockfunctionunlock_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockFunctionunlock >&
Sheet_FunctionunlockFunctionunlock::e_functionunlockfunctionunlock_list() const {
  return e_functionunlockfunctionunlock_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockFunctionunlock >*
Sheet_FunctionunlockFunctionunlock::mutable_e_functionunlockfunctionunlock_list() {
  return &e_functionunlockfunctionunlock_list_;
}

// -------------------------------------------------------------------

// E_FunctionunlockPreview

// optional int32 m_functionid = 1;
inline bool E_FunctionunlockPreview::has_m_functionid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_FunctionunlockPreview::set_has_m_functionid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_FunctionunlockPreview::clear_has_m_functionid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_FunctionunlockPreview::clear_m_functionid() {
  m_functionid_ = 0;
  clear_has_m_functionid();
}
inline ::google::protobuf::int32 E_FunctionunlockPreview::m_functionid() const {
  return m_functionid_;
}
inline void E_FunctionunlockPreview::set_m_functionid(::google::protobuf::int32 value) {
  set_has_m_functionid();
  m_functionid_ = value;
}

// optional int32 m_rewarditem = 2;
inline bool E_FunctionunlockPreview::has_m_rewarditem() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_FunctionunlockPreview::set_has_m_rewarditem() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_FunctionunlockPreview::clear_has_m_rewarditem() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_FunctionunlockPreview::clear_m_rewarditem() {
  m_rewarditem_ = 0;
  clear_has_m_rewarditem();
}
inline ::google::protobuf::int32 E_FunctionunlockPreview::m_rewarditem() const {
  return m_rewarditem_;
}
inline void E_FunctionunlockPreview::set_m_rewarditem(::google::protobuf::int32 value) {
  set_has_m_rewarditem();
  m_rewarditem_ = value;
}

// optional int32 m_rewardnum = 3;
inline bool E_FunctionunlockPreview::has_m_rewardnum() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_FunctionunlockPreview::set_has_m_rewardnum() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_FunctionunlockPreview::clear_has_m_rewardnum() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_FunctionunlockPreview::clear_m_rewardnum() {
  m_rewardnum_ = 0;
  clear_has_m_rewardnum();
}
inline ::google::protobuf::int32 E_FunctionunlockPreview::m_rewardnum() const {
  return m_rewardnum_;
}
inline void E_FunctionunlockPreview::set_m_rewardnum(::google::protobuf::int32 value) {
  set_has_m_rewardnum();
  m_rewardnum_ = value;
}

// -------------------------------------------------------------------

// Sheet_FunctionunlockPreview

// repeated .proto_ff.E_FunctionunlockPreview E_FunctionunlockPreview_List = 1;
inline int Sheet_FunctionunlockPreview::e_functionunlockpreview_list_size() const {
  return e_functionunlockpreview_list_.size();
}
inline void Sheet_FunctionunlockPreview::clear_e_functionunlockpreview_list() {
  e_functionunlockpreview_list_.Clear();
}
inline const ::proto_ff::E_FunctionunlockPreview& Sheet_FunctionunlockPreview::e_functionunlockpreview_list(int index) const {
  return e_functionunlockpreview_list_.Get(index);
}
inline ::proto_ff::E_FunctionunlockPreview* Sheet_FunctionunlockPreview::mutable_e_functionunlockpreview_list(int index) {
  return e_functionunlockpreview_list_.Mutable(index);
}
inline ::proto_ff::E_FunctionunlockPreview* Sheet_FunctionunlockPreview::add_e_functionunlockpreview_list() {
  return e_functionunlockpreview_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockPreview >&
Sheet_FunctionunlockPreview::e_functionunlockpreview_list() const {
  return e_functionunlockpreview_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_FunctionunlockPreview >*
Sheet_FunctionunlockPreview::mutable_e_functionunlockpreview_list() {
  return &e_functionunlockpreview_list_;
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

#endif  // PROTOBUF_E_5fFunctionunlock_2eproto__INCLUDED
