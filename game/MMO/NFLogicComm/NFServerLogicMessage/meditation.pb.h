// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meditation.proto

#ifndef PROTOBUF_meditation_2eproto__INCLUDED
#define PROTOBUF_meditation_2eproto__INCLUDED

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
void  protobuf_AddDesc_meditation_2eproto();
void protobuf_AssignDesc_meditation_2eproto();
void protobuf_ShutdownFile_meditation_2eproto();

class E_MeditationMeditationAttributeDesc;
class E_MeditationMeditationActiveattributeDesc;
class E_MeditationMeditation;
class Sheet_MeditationMeditation;

// ===================================================================

class E_MeditationMeditationAttributeDesc : public ::google::protobuf::Message {
 public:
  E_MeditationMeditationAttributeDesc();
  virtual ~E_MeditationMeditationAttributeDesc();

  E_MeditationMeditationAttributeDesc(const E_MeditationMeditationAttributeDesc& from);

  inline E_MeditationMeditationAttributeDesc& operator=(const E_MeditationMeditationAttributeDesc& from) {
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
  static const E_MeditationMeditationAttributeDesc& default_instance();

  void Swap(E_MeditationMeditationAttributeDesc* other);

  // implements Message ----------------------------------------------

  E_MeditationMeditationAttributeDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_MeditationMeditationAttributeDesc& from);
  void MergeFrom(const E_MeditationMeditationAttributeDesc& from);
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

  // optional int32 m_type = 1;
  inline bool has_m_type() const;
  inline void clear_m_type();
  static const int kMTypeFieldNumber = 1;
  inline ::google::protobuf::int32 m_type() const;
  inline void set_m_type(::google::protobuf::int32 value);

  // optional int32 m_value = 2;
  inline bool has_m_value() const;
  inline void clear_m_value();
  static const int kMValueFieldNumber = 2;
  inline ::google::protobuf::int32 m_value() const;
  inline void set_m_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_MeditationMeditationAttributeDesc)
 private:
  inline void set_has_m_type();
  inline void clear_has_m_type();
  inline void set_has_m_value();
  inline void clear_has_m_value();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_type_;
  ::google::protobuf::int32 m_value_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_meditation_2eproto();
  friend void protobuf_AssignDesc_meditation_2eproto();
  friend void protobuf_ShutdownFile_meditation_2eproto();

  void InitAsDefaultInstance();
  static E_MeditationMeditationAttributeDesc* default_instance_;
};
// -------------------------------------------------------------------

class E_MeditationMeditationActiveattributeDesc : public ::google::protobuf::Message {
 public:
  E_MeditationMeditationActiveattributeDesc();
  virtual ~E_MeditationMeditationActiveattributeDesc();

  E_MeditationMeditationActiveattributeDesc(const E_MeditationMeditationActiveattributeDesc& from);

  inline E_MeditationMeditationActiveattributeDesc& operator=(const E_MeditationMeditationActiveattributeDesc& from) {
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
  static const E_MeditationMeditationActiveattributeDesc& default_instance();

  void Swap(E_MeditationMeditationActiveattributeDesc* other);

  // implements Message ----------------------------------------------

  E_MeditationMeditationActiveattributeDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_MeditationMeditationActiveattributeDesc& from);
  void MergeFrom(const E_MeditationMeditationActiveattributeDesc& from);
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

  // optional int32 m_type = 1;
  inline bool has_m_type() const;
  inline void clear_m_type();
  static const int kMTypeFieldNumber = 1;
  inline ::google::protobuf::int32 m_type() const;
  inline void set_m_type(::google::protobuf::int32 value);

  // optional int32 m_value = 2;
  inline bool has_m_value() const;
  inline void clear_m_value();
  static const int kMValueFieldNumber = 2;
  inline ::google::protobuf::int32 m_value() const;
  inline void set_m_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_MeditationMeditationActiveattributeDesc)
 private:
  inline void set_has_m_type();
  inline void clear_has_m_type();
  inline void set_has_m_value();
  inline void clear_has_m_value();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_type_;
  ::google::protobuf::int32 m_value_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_meditation_2eproto();
  friend void protobuf_AssignDesc_meditation_2eproto();
  friend void protobuf_ShutdownFile_meditation_2eproto();

  void InitAsDefaultInstance();
  static E_MeditationMeditationActiveattributeDesc* default_instance_;
};
// -------------------------------------------------------------------

class E_MeditationMeditation : public ::google::protobuf::Message {
 public:
  E_MeditationMeditation();
  virtual ~E_MeditationMeditation();

  E_MeditationMeditation(const E_MeditationMeditation& from);

  inline E_MeditationMeditation& operator=(const E_MeditationMeditation& from) {
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
  static const E_MeditationMeditation& default_instance();

  void Swap(E_MeditationMeditation* other);

  // implements Message ----------------------------------------------

  E_MeditationMeditation* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_MeditationMeditation& from);
  void MergeFrom(const E_MeditationMeditation& from);
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

  // optional int64 m_id = 1;
  inline bool has_m_id() const;
  inline void clear_m_id();
  static const int kMIdFieldNumber = 1;
  inline ::google::protobuf::int64 m_id() const;
  inline void set_m_id(::google::protobuf::int64 value);

  // optional string m_name = 2;
  inline bool has_m_name() const;
  inline void clear_m_name();
  static const int kMNameFieldNumber = 2;
  inline const ::std::string& m_name() const;
  inline void set_m_name(const ::std::string& value);
  inline void set_m_name(const char* value);
  inline void set_m_name(const char* value, size_t size);
  inline ::std::string* mutable_m_name();
  inline ::std::string* release_m_name();
  inline void set_allocated_m_name(::std::string* m_name);

  // optional int32 m_type = 3;
  inline bool has_m_type() const;
  inline void clear_m_type();
  static const int kMTypeFieldNumber = 3;
  inline ::google::protobuf::int32 m_type() const;
  inline void set_m_type(::google::protobuf::int32 value);

  // optional int32 m_quality = 4;
  inline bool has_m_quality() const;
  inline void clear_m_quality();
  static const int kMQualityFieldNumber = 4;
  inline ::google::protobuf::int32 m_quality() const;
  inline void set_m_quality(::google::protobuf::int32 value);

  // optional string m_professionlimit = 5;
  inline bool has_m_professionlimit() const;
  inline void clear_m_professionlimit();
  static const int kMProfessionlimitFieldNumber = 5;
  inline const ::std::string& m_professionlimit() const;
  inline void set_m_professionlimit(const ::std::string& value);
  inline void set_m_professionlimit(const char* value);
  inline void set_m_professionlimit(const char* value, size_t size);
  inline ::std::string* mutable_m_professionlimit();
  inline ::std::string* release_m_professionlimit();
  inline void set_allocated_m_professionlimit(::std::string* m_professionlimit);

  // optional int64 m_activationitem = 6;
  inline bool has_m_activationitem() const;
  inline void clear_m_activationitem();
  static const int kMActivationitemFieldNumber = 6;
  inline ::google::protobuf::int64 m_activationitem() const;
  inline void set_m_activationitem(::google::protobuf::int64 value);

  // optional int32 m_activationnum = 7;
  inline bool has_m_activationnum() const;
  inline void clear_m_activationnum();
  static const int kMActivationnumFieldNumber = 7;
  inline ::google::protobuf::int32 m_activationnum() const;
  inline void set_m_activationnum(::google::protobuf::int32 value);

  // optional int64 m_starid = 8;
  inline bool has_m_starid() const;
  inline void clear_m_starid();
  static const int kMStaridFieldNumber = 8;
  inline ::google::protobuf::int64 m_starid() const;
  inline void set_m_starid(::google::protobuf::int64 value);

  // optional string m_starnum = 9;
  inline bool has_m_starnum() const;
  inline void clear_m_starnum();
  static const int kMStarnumFieldNumber = 9;
  inline const ::std::string& m_starnum() const;
  inline void set_m_starnum(const ::std::string& value);
  inline void set_m_starnum(const char* value);
  inline void set_m_starnum(const char* value, size_t size);
  inline ::std::string* mutable_m_starnum();
  inline ::std::string* release_m_starnum();
  inline void set_allocated_m_starnum(::std::string* m_starnum);

  // optional int32 m_starup = 10;
  inline bool has_m_starup() const;
  inline void clear_m_starup();
  static const int kMStarupFieldNumber = 10;
  inline ::google::protobuf::int32 m_starup() const;
  inline void set_m_starup(::google::protobuf::int32 value);

  // optional int32 m_starber = 11;
  inline bool has_m_starber() const;
  inline void clear_m_starber();
  static const int kMStarberFieldNumber = 11;
  inline ::google::protobuf::int32 m_starber() const;
  inline void set_m_starber(::google::protobuf::int32 value);

  // repeated .proto_ff.E_MeditationMeditationAttributeDesc m_attribute = 12;
  inline int m_attribute_size() const;
  inline void clear_m_attribute();
  static const int kMAttributeFieldNumber = 12;
  inline const ::proto_ff::E_MeditationMeditationAttributeDesc& m_attribute(int index) const;
  inline ::proto_ff::E_MeditationMeditationAttributeDesc* mutable_m_attribute(int index);
  inline ::proto_ff::E_MeditationMeditationAttributeDesc* add_m_attribute();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationAttributeDesc >&
      m_attribute() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationAttributeDesc >*
      mutable_m_attribute();

  // repeated .proto_ff.E_MeditationMeditationActiveattributeDesc m_activeattribute = 13;
  inline int m_activeattribute_size() const;
  inline void clear_m_activeattribute();
  static const int kMActiveattributeFieldNumber = 13;
  inline const ::proto_ff::E_MeditationMeditationActiveattributeDesc& m_activeattribute(int index) const;
  inline ::proto_ff::E_MeditationMeditationActiveattributeDesc* mutable_m_activeattribute(int index);
  inline ::proto_ff::E_MeditationMeditationActiveattributeDesc* add_m_activeattribute();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationActiveattributeDesc >&
      m_activeattribute() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationActiveattributeDesc >*
      mutable_m_activeattribute();

  // @@protoc_insertion_point(class_scope:proto_ff.E_MeditationMeditation)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_name();
  inline void clear_has_m_name();
  inline void set_has_m_type();
  inline void clear_has_m_type();
  inline void set_has_m_quality();
  inline void clear_has_m_quality();
  inline void set_has_m_professionlimit();
  inline void clear_has_m_professionlimit();
  inline void set_has_m_activationitem();
  inline void clear_has_m_activationitem();
  inline void set_has_m_activationnum();
  inline void clear_has_m_activationnum();
  inline void set_has_m_starid();
  inline void clear_has_m_starid();
  inline void set_has_m_starnum();
  inline void clear_has_m_starnum();
  inline void set_has_m_starup();
  inline void clear_has_m_starup();
  inline void set_has_m_starber();
  inline void clear_has_m_starber();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 m_id_;
  ::std::string* m_name_;
  ::google::protobuf::int32 m_type_;
  ::google::protobuf::int32 m_quality_;
  ::std::string* m_professionlimit_;
  ::google::protobuf::int64 m_activationitem_;
  ::google::protobuf::int64 m_starid_;
  ::google::protobuf::int32 m_activationnum_;
  ::google::protobuf::int32 m_starup_;
  ::std::string* m_starnum_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationAttributeDesc > m_attribute_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationActiveattributeDesc > m_activeattribute_;
  ::google::protobuf::int32 m_starber_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(13 + 31) / 32];

  friend void  protobuf_AddDesc_meditation_2eproto();
  friend void protobuf_AssignDesc_meditation_2eproto();
  friend void protobuf_ShutdownFile_meditation_2eproto();

  void InitAsDefaultInstance();
  static E_MeditationMeditation* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_MeditationMeditation : public ::google::protobuf::Message {
 public:
  Sheet_MeditationMeditation();
  virtual ~Sheet_MeditationMeditation();

  Sheet_MeditationMeditation(const Sheet_MeditationMeditation& from);

  inline Sheet_MeditationMeditation& operator=(const Sheet_MeditationMeditation& from) {
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
  static const Sheet_MeditationMeditation& default_instance();

  void Swap(Sheet_MeditationMeditation* other);

  // implements Message ----------------------------------------------

  Sheet_MeditationMeditation* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_MeditationMeditation& from);
  void MergeFrom(const Sheet_MeditationMeditation& from);
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

  // repeated .proto_ff.E_MeditationMeditation E_MeditationMeditation_List = 1;
  inline int e_meditationmeditation_list_size() const;
  inline void clear_e_meditationmeditation_list();
  static const int kEMeditationMeditationListFieldNumber = 1;
  inline const ::proto_ff::E_MeditationMeditation& e_meditationmeditation_list(int index) const;
  inline ::proto_ff::E_MeditationMeditation* mutable_e_meditationmeditation_list(int index);
  inline ::proto_ff::E_MeditationMeditation* add_e_meditationmeditation_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditation >&
      e_meditationmeditation_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditation >*
      mutable_e_meditationmeditation_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_MeditationMeditation)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditation > e_meditationmeditation_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_meditation_2eproto();
  friend void protobuf_AssignDesc_meditation_2eproto();
  friend void protobuf_ShutdownFile_meditation_2eproto();

  void InitAsDefaultInstance();
  static Sheet_MeditationMeditation* default_instance_;
};
// ===================================================================


// ===================================================================

// E_MeditationMeditationAttributeDesc

// optional int32 m_type = 1;
inline bool E_MeditationMeditationAttributeDesc::has_m_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_MeditationMeditationAttributeDesc::set_has_m_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_MeditationMeditationAttributeDesc::clear_has_m_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_MeditationMeditationAttributeDesc::clear_m_type() {
  m_type_ = 0;
  clear_has_m_type();
}
inline ::google::protobuf::int32 E_MeditationMeditationAttributeDesc::m_type() const {
  return m_type_;
}
inline void E_MeditationMeditationAttributeDesc::set_m_type(::google::protobuf::int32 value) {
  set_has_m_type();
  m_type_ = value;
}

// optional int32 m_value = 2;
inline bool E_MeditationMeditationAttributeDesc::has_m_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_MeditationMeditationAttributeDesc::set_has_m_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_MeditationMeditationAttributeDesc::clear_has_m_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_MeditationMeditationAttributeDesc::clear_m_value() {
  m_value_ = 0;
  clear_has_m_value();
}
inline ::google::protobuf::int32 E_MeditationMeditationAttributeDesc::m_value() const {
  return m_value_;
}
inline void E_MeditationMeditationAttributeDesc::set_m_value(::google::protobuf::int32 value) {
  set_has_m_value();
  m_value_ = value;
}

// -------------------------------------------------------------------

// E_MeditationMeditationActiveattributeDesc

// optional int32 m_type = 1;
inline bool E_MeditationMeditationActiveattributeDesc::has_m_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_MeditationMeditationActiveattributeDesc::set_has_m_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_MeditationMeditationActiveattributeDesc::clear_has_m_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_MeditationMeditationActiveattributeDesc::clear_m_type() {
  m_type_ = 0;
  clear_has_m_type();
}
inline ::google::protobuf::int32 E_MeditationMeditationActiveattributeDesc::m_type() const {
  return m_type_;
}
inline void E_MeditationMeditationActiveattributeDesc::set_m_type(::google::protobuf::int32 value) {
  set_has_m_type();
  m_type_ = value;
}

// optional int32 m_value = 2;
inline bool E_MeditationMeditationActiveattributeDesc::has_m_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_MeditationMeditationActiveattributeDesc::set_has_m_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_MeditationMeditationActiveattributeDesc::clear_has_m_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_MeditationMeditationActiveattributeDesc::clear_m_value() {
  m_value_ = 0;
  clear_has_m_value();
}
inline ::google::protobuf::int32 E_MeditationMeditationActiveattributeDesc::m_value() const {
  return m_value_;
}
inline void E_MeditationMeditationActiveattributeDesc::set_m_value(::google::protobuf::int32 value) {
  set_has_m_value();
  m_value_ = value;
}

// -------------------------------------------------------------------

// E_MeditationMeditation

// optional int64 m_id = 1;
inline bool E_MeditationMeditation::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_MeditationMeditation::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_MeditationMeditation::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_MeditationMeditation::clear_m_id() {
  m_id_ = GOOGLE_LONGLONG(0);
  clear_has_m_id();
}
inline ::google::protobuf::int64 E_MeditationMeditation::m_id() const {
  return m_id_;
}
inline void E_MeditationMeditation::set_m_id(::google::protobuf::int64 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional string m_name = 2;
inline bool E_MeditationMeditation::has_m_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_MeditationMeditation::set_has_m_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_MeditationMeditation::clear_has_m_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_MeditationMeditation::clear_m_name() {
  if (m_name_ != &::google::protobuf::internal::kEmptyString) {
    m_name_->clear();
  }
  clear_has_m_name();
}
inline const ::std::string& E_MeditationMeditation::m_name() const {
  return *m_name_;
}
inline void E_MeditationMeditation::set_m_name(const ::std::string& value) {
  set_has_m_name();
  if (m_name_ == &::google::protobuf::internal::kEmptyString) {
    m_name_ = new ::std::string;
  }
  m_name_->assign(value);
}
inline void E_MeditationMeditation::set_m_name(const char* value) {
  set_has_m_name();
  if (m_name_ == &::google::protobuf::internal::kEmptyString) {
    m_name_ = new ::std::string;
  }
  m_name_->assign(value);
}
inline void E_MeditationMeditation::set_m_name(const char* value, size_t size) {
  set_has_m_name();
  if (m_name_ == &::google::protobuf::internal::kEmptyString) {
    m_name_ = new ::std::string;
  }
  m_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_MeditationMeditation::mutable_m_name() {
  set_has_m_name();
  if (m_name_ == &::google::protobuf::internal::kEmptyString) {
    m_name_ = new ::std::string;
  }
  return m_name_;
}
inline ::std::string* E_MeditationMeditation::release_m_name() {
  clear_has_m_name();
  if (m_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_name_;
    m_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_MeditationMeditation::set_allocated_m_name(::std::string* m_name) {
  if (m_name_ != &::google::protobuf::internal::kEmptyString) {
    delete m_name_;
  }
  if (m_name) {
    set_has_m_name();
    m_name_ = m_name;
  } else {
    clear_has_m_name();
    m_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 m_type = 3;
inline bool E_MeditationMeditation::has_m_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_MeditationMeditation::set_has_m_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_MeditationMeditation::clear_has_m_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_MeditationMeditation::clear_m_type() {
  m_type_ = 0;
  clear_has_m_type();
}
inline ::google::protobuf::int32 E_MeditationMeditation::m_type() const {
  return m_type_;
}
inline void E_MeditationMeditation::set_m_type(::google::protobuf::int32 value) {
  set_has_m_type();
  m_type_ = value;
}

// optional int32 m_quality = 4;
inline bool E_MeditationMeditation::has_m_quality() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_MeditationMeditation::set_has_m_quality() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_MeditationMeditation::clear_has_m_quality() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_MeditationMeditation::clear_m_quality() {
  m_quality_ = 0;
  clear_has_m_quality();
}
inline ::google::protobuf::int32 E_MeditationMeditation::m_quality() const {
  return m_quality_;
}
inline void E_MeditationMeditation::set_m_quality(::google::protobuf::int32 value) {
  set_has_m_quality();
  m_quality_ = value;
}

// optional string m_professionlimit = 5;
inline bool E_MeditationMeditation::has_m_professionlimit() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_MeditationMeditation::set_has_m_professionlimit() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_MeditationMeditation::clear_has_m_professionlimit() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_MeditationMeditation::clear_m_professionlimit() {
  if (m_professionlimit_ != &::google::protobuf::internal::kEmptyString) {
    m_professionlimit_->clear();
  }
  clear_has_m_professionlimit();
}
inline const ::std::string& E_MeditationMeditation::m_professionlimit() const {
  return *m_professionlimit_;
}
inline void E_MeditationMeditation::set_m_professionlimit(const ::std::string& value) {
  set_has_m_professionlimit();
  if (m_professionlimit_ == &::google::protobuf::internal::kEmptyString) {
    m_professionlimit_ = new ::std::string;
  }
  m_professionlimit_->assign(value);
}
inline void E_MeditationMeditation::set_m_professionlimit(const char* value) {
  set_has_m_professionlimit();
  if (m_professionlimit_ == &::google::protobuf::internal::kEmptyString) {
    m_professionlimit_ = new ::std::string;
  }
  m_professionlimit_->assign(value);
}
inline void E_MeditationMeditation::set_m_professionlimit(const char* value, size_t size) {
  set_has_m_professionlimit();
  if (m_professionlimit_ == &::google::protobuf::internal::kEmptyString) {
    m_professionlimit_ = new ::std::string;
  }
  m_professionlimit_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_MeditationMeditation::mutable_m_professionlimit() {
  set_has_m_professionlimit();
  if (m_professionlimit_ == &::google::protobuf::internal::kEmptyString) {
    m_professionlimit_ = new ::std::string;
  }
  return m_professionlimit_;
}
inline ::std::string* E_MeditationMeditation::release_m_professionlimit() {
  clear_has_m_professionlimit();
  if (m_professionlimit_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_professionlimit_;
    m_professionlimit_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_MeditationMeditation::set_allocated_m_professionlimit(::std::string* m_professionlimit) {
  if (m_professionlimit_ != &::google::protobuf::internal::kEmptyString) {
    delete m_professionlimit_;
  }
  if (m_professionlimit) {
    set_has_m_professionlimit();
    m_professionlimit_ = m_professionlimit;
  } else {
    clear_has_m_professionlimit();
    m_professionlimit_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int64 m_activationitem = 6;
inline bool E_MeditationMeditation::has_m_activationitem() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_MeditationMeditation::set_has_m_activationitem() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_MeditationMeditation::clear_has_m_activationitem() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_MeditationMeditation::clear_m_activationitem() {
  m_activationitem_ = GOOGLE_LONGLONG(0);
  clear_has_m_activationitem();
}
inline ::google::protobuf::int64 E_MeditationMeditation::m_activationitem() const {
  return m_activationitem_;
}
inline void E_MeditationMeditation::set_m_activationitem(::google::protobuf::int64 value) {
  set_has_m_activationitem();
  m_activationitem_ = value;
}

// optional int32 m_activationnum = 7;
inline bool E_MeditationMeditation::has_m_activationnum() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void E_MeditationMeditation::set_has_m_activationnum() {
  _has_bits_[0] |= 0x00000040u;
}
inline void E_MeditationMeditation::clear_has_m_activationnum() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void E_MeditationMeditation::clear_m_activationnum() {
  m_activationnum_ = 0;
  clear_has_m_activationnum();
}
inline ::google::protobuf::int32 E_MeditationMeditation::m_activationnum() const {
  return m_activationnum_;
}
inline void E_MeditationMeditation::set_m_activationnum(::google::protobuf::int32 value) {
  set_has_m_activationnum();
  m_activationnum_ = value;
}

// optional int64 m_starid = 8;
inline bool E_MeditationMeditation::has_m_starid() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void E_MeditationMeditation::set_has_m_starid() {
  _has_bits_[0] |= 0x00000080u;
}
inline void E_MeditationMeditation::clear_has_m_starid() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void E_MeditationMeditation::clear_m_starid() {
  m_starid_ = GOOGLE_LONGLONG(0);
  clear_has_m_starid();
}
inline ::google::protobuf::int64 E_MeditationMeditation::m_starid() const {
  return m_starid_;
}
inline void E_MeditationMeditation::set_m_starid(::google::protobuf::int64 value) {
  set_has_m_starid();
  m_starid_ = value;
}

// optional string m_starnum = 9;
inline bool E_MeditationMeditation::has_m_starnum() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void E_MeditationMeditation::set_has_m_starnum() {
  _has_bits_[0] |= 0x00000100u;
}
inline void E_MeditationMeditation::clear_has_m_starnum() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void E_MeditationMeditation::clear_m_starnum() {
  if (m_starnum_ != &::google::protobuf::internal::kEmptyString) {
    m_starnum_->clear();
  }
  clear_has_m_starnum();
}
inline const ::std::string& E_MeditationMeditation::m_starnum() const {
  return *m_starnum_;
}
inline void E_MeditationMeditation::set_m_starnum(const ::std::string& value) {
  set_has_m_starnum();
  if (m_starnum_ == &::google::protobuf::internal::kEmptyString) {
    m_starnum_ = new ::std::string;
  }
  m_starnum_->assign(value);
}
inline void E_MeditationMeditation::set_m_starnum(const char* value) {
  set_has_m_starnum();
  if (m_starnum_ == &::google::protobuf::internal::kEmptyString) {
    m_starnum_ = new ::std::string;
  }
  m_starnum_->assign(value);
}
inline void E_MeditationMeditation::set_m_starnum(const char* value, size_t size) {
  set_has_m_starnum();
  if (m_starnum_ == &::google::protobuf::internal::kEmptyString) {
    m_starnum_ = new ::std::string;
  }
  m_starnum_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_MeditationMeditation::mutable_m_starnum() {
  set_has_m_starnum();
  if (m_starnum_ == &::google::protobuf::internal::kEmptyString) {
    m_starnum_ = new ::std::string;
  }
  return m_starnum_;
}
inline ::std::string* E_MeditationMeditation::release_m_starnum() {
  clear_has_m_starnum();
  if (m_starnum_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_starnum_;
    m_starnum_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_MeditationMeditation::set_allocated_m_starnum(::std::string* m_starnum) {
  if (m_starnum_ != &::google::protobuf::internal::kEmptyString) {
    delete m_starnum_;
  }
  if (m_starnum) {
    set_has_m_starnum();
    m_starnum_ = m_starnum;
  } else {
    clear_has_m_starnum();
    m_starnum_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 m_starup = 10;
inline bool E_MeditationMeditation::has_m_starup() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void E_MeditationMeditation::set_has_m_starup() {
  _has_bits_[0] |= 0x00000200u;
}
inline void E_MeditationMeditation::clear_has_m_starup() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void E_MeditationMeditation::clear_m_starup() {
  m_starup_ = 0;
  clear_has_m_starup();
}
inline ::google::protobuf::int32 E_MeditationMeditation::m_starup() const {
  return m_starup_;
}
inline void E_MeditationMeditation::set_m_starup(::google::protobuf::int32 value) {
  set_has_m_starup();
  m_starup_ = value;
}

// optional int32 m_starber = 11;
inline bool E_MeditationMeditation::has_m_starber() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void E_MeditationMeditation::set_has_m_starber() {
  _has_bits_[0] |= 0x00000400u;
}
inline void E_MeditationMeditation::clear_has_m_starber() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void E_MeditationMeditation::clear_m_starber() {
  m_starber_ = 0;
  clear_has_m_starber();
}
inline ::google::protobuf::int32 E_MeditationMeditation::m_starber() const {
  return m_starber_;
}
inline void E_MeditationMeditation::set_m_starber(::google::protobuf::int32 value) {
  set_has_m_starber();
  m_starber_ = value;
}

// repeated .proto_ff.E_MeditationMeditationAttributeDesc m_attribute = 12;
inline int E_MeditationMeditation::m_attribute_size() const {
  return m_attribute_.size();
}
inline void E_MeditationMeditation::clear_m_attribute() {
  m_attribute_.Clear();
}
inline const ::proto_ff::E_MeditationMeditationAttributeDesc& E_MeditationMeditation::m_attribute(int index) const {
  return m_attribute_.Get(index);
}
inline ::proto_ff::E_MeditationMeditationAttributeDesc* E_MeditationMeditation::mutable_m_attribute(int index) {
  return m_attribute_.Mutable(index);
}
inline ::proto_ff::E_MeditationMeditationAttributeDesc* E_MeditationMeditation::add_m_attribute() {
  return m_attribute_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationAttributeDesc >&
E_MeditationMeditation::m_attribute() const {
  return m_attribute_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationAttributeDesc >*
E_MeditationMeditation::mutable_m_attribute() {
  return &m_attribute_;
}

// repeated .proto_ff.E_MeditationMeditationActiveattributeDesc m_activeattribute = 13;
inline int E_MeditationMeditation::m_activeattribute_size() const {
  return m_activeattribute_.size();
}
inline void E_MeditationMeditation::clear_m_activeattribute() {
  m_activeattribute_.Clear();
}
inline const ::proto_ff::E_MeditationMeditationActiveattributeDesc& E_MeditationMeditation::m_activeattribute(int index) const {
  return m_activeattribute_.Get(index);
}
inline ::proto_ff::E_MeditationMeditationActiveattributeDesc* E_MeditationMeditation::mutable_m_activeattribute(int index) {
  return m_activeattribute_.Mutable(index);
}
inline ::proto_ff::E_MeditationMeditationActiveattributeDesc* E_MeditationMeditation::add_m_activeattribute() {
  return m_activeattribute_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationActiveattributeDesc >&
E_MeditationMeditation::m_activeattribute() const {
  return m_activeattribute_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditationActiveattributeDesc >*
E_MeditationMeditation::mutable_m_activeattribute() {
  return &m_activeattribute_;
}

// -------------------------------------------------------------------

// Sheet_MeditationMeditation

// repeated .proto_ff.E_MeditationMeditation E_MeditationMeditation_List = 1;
inline int Sheet_MeditationMeditation::e_meditationmeditation_list_size() const {
  return e_meditationmeditation_list_.size();
}
inline void Sheet_MeditationMeditation::clear_e_meditationmeditation_list() {
  e_meditationmeditation_list_.Clear();
}
inline const ::proto_ff::E_MeditationMeditation& Sheet_MeditationMeditation::e_meditationmeditation_list(int index) const {
  return e_meditationmeditation_list_.Get(index);
}
inline ::proto_ff::E_MeditationMeditation* Sheet_MeditationMeditation::mutable_e_meditationmeditation_list(int index) {
  return e_meditationmeditation_list_.Mutable(index);
}
inline ::proto_ff::E_MeditationMeditation* Sheet_MeditationMeditation::add_e_meditationmeditation_list() {
  return e_meditationmeditation_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditation >&
Sheet_MeditationMeditation::e_meditationmeditation_list() const {
  return e_meditationmeditation_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_MeditationMeditation >*
Sheet_MeditationMeditation::mutable_e_meditationmeditation_list() {
  return &e_meditationmeditation_list_;
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

#endif  // PROTOBUF_meditation_2eproto__INCLUDED
