// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: st_mission.proto

#ifndef PROTOBUF_st_5fmission_2eproto__INCLUDED
#define PROTOBUF_st_5fmission_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace progame {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_st_5fmission_2eproto();
void protobuf_AssignDesc_st_5fmission_2eproto();
void protobuf_ShutdownFile_st_5fmission_2eproto();

class missioninfo;
class missionlist;

// ===================================================================

class missioninfo : public ::google::protobuf::Message {
 public:
  missioninfo();
  virtual ~missioninfo();

  missioninfo(const missioninfo& from);

  inline missioninfo& operator=(const missioninfo& from) {
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
  static const missioninfo& default_instance();

  void Swap(missioninfo* other);

  // implements Message ----------------------------------------------

  missioninfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const missioninfo& from);
  void MergeFrom(const missioninfo& from);
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

  // optional int32 userid = 2;
  inline bool has_userid() const;
  inline void clear_userid();
  static const int kUseridFieldNumber = 2;
  inline ::google::protobuf::int32 userid() const;
  inline void set_userid(::google::protobuf::int32 value);

  // optional int32 missionid = 3;
  inline bool has_missionid() const;
  inline void clear_missionid();
  static const int kMissionidFieldNumber = 3;
  inline ::google::protobuf::int32 missionid() const;
  inline void set_missionid(::google::protobuf::int32 value);

  // optional int32 finish = 4;
  inline bool has_finish() const;
  inline void clear_finish();
  static const int kFinishFieldNumber = 4;
  inline ::google::protobuf::int32 finish() const;
  inline void set_finish(::google::protobuf::int32 value);

  // optional int32 state = 5;
  inline bool has_state() const;
  inline void clear_state();
  static const int kStateFieldNumber = 5;
  inline ::google::protobuf::int32 state() const;
  inline void set_state(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:progame.missioninfo)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_userid();
  inline void clear_has_userid();
  inline void set_has_missionid();
  inline void clear_has_missionid();
  inline void set_has_finish();
  inline void clear_has_finish();
  inline void set_has_state();
  inline void clear_has_state();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 userid_;
  ::google::protobuf::int32 missionid_;
  ::google::protobuf::int32 finish_;
  ::google::protobuf::int32 state_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_st_5fmission_2eproto();
  friend void protobuf_AssignDesc_st_5fmission_2eproto();
  friend void protobuf_ShutdownFile_st_5fmission_2eproto();

  void InitAsDefaultInstance();
  static missioninfo* default_instance_;
};
// -------------------------------------------------------------------

class missionlist : public ::google::protobuf::Message {
 public:
  missionlist();
  virtual ~missionlist();

  missionlist(const missionlist& from);

  inline missionlist& operator=(const missionlist& from) {
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
  static const missionlist& default_instance();

  void Swap(missionlist* other);

  // implements Message ----------------------------------------------

  missionlist* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const missionlist& from);
  void MergeFrom(const missionlist& from);
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

  // optional int32 timesec = 1;
  inline bool has_timesec() const;
  inline void clear_timesec();
  static const int kTimesecFieldNumber = 1;
  inline ::google::protobuf::int32 timesec() const;
  inline void set_timesec(::google::protobuf::int32 value);

  // repeated .progame.missioninfo mslist = 2;
  inline int mslist_size() const;
  inline void clear_mslist();
  static const int kMslistFieldNumber = 2;
  inline const ::progame::missioninfo& mslist(int index) const;
  inline ::progame::missioninfo* mutable_mslist(int index);
  inline ::progame::missioninfo* add_mslist();
  inline const ::google::protobuf::RepeatedPtrField< ::progame::missioninfo >&
      mslist() const;
  inline ::google::protobuf::RepeatedPtrField< ::progame::missioninfo >*
      mutable_mslist();

  // @@protoc_insertion_point(class_scope:progame.missionlist)
 private:
  inline void set_has_timesec();
  inline void clear_has_timesec();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::progame::missioninfo > mslist_;
  ::google::protobuf::int32 timesec_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_st_5fmission_2eproto();
  friend void protobuf_AssignDesc_st_5fmission_2eproto();
  friend void protobuf_ShutdownFile_st_5fmission_2eproto();

  void InitAsDefaultInstance();
  static missionlist* default_instance_;
};
// ===================================================================


// ===================================================================

// missioninfo

// optional int32 id = 1;
inline bool missioninfo::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void missioninfo::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void missioninfo::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void missioninfo::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 missioninfo::id() const {
  return id_;
}
inline void missioninfo::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}

// optional int32 userid = 2;
inline bool missioninfo::has_userid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void missioninfo::set_has_userid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void missioninfo::clear_has_userid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void missioninfo::clear_userid() {
  userid_ = 0;
  clear_has_userid();
}
inline ::google::protobuf::int32 missioninfo::userid() const {
  return userid_;
}
inline void missioninfo::set_userid(::google::protobuf::int32 value) {
  set_has_userid();
  userid_ = value;
}

// optional int32 missionid = 3;
inline bool missioninfo::has_missionid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void missioninfo::set_has_missionid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void missioninfo::clear_has_missionid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void missioninfo::clear_missionid() {
  missionid_ = 0;
  clear_has_missionid();
}
inline ::google::protobuf::int32 missioninfo::missionid() const {
  return missionid_;
}
inline void missioninfo::set_missionid(::google::protobuf::int32 value) {
  set_has_missionid();
  missionid_ = value;
}

// optional int32 finish = 4;
inline bool missioninfo::has_finish() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void missioninfo::set_has_finish() {
  _has_bits_[0] |= 0x00000008u;
}
inline void missioninfo::clear_has_finish() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void missioninfo::clear_finish() {
  finish_ = 0;
  clear_has_finish();
}
inline ::google::protobuf::int32 missioninfo::finish() const {
  return finish_;
}
inline void missioninfo::set_finish(::google::protobuf::int32 value) {
  set_has_finish();
  finish_ = value;
}

// optional int32 state = 5;
inline bool missioninfo::has_state() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void missioninfo::set_has_state() {
  _has_bits_[0] |= 0x00000010u;
}
inline void missioninfo::clear_has_state() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void missioninfo::clear_state() {
  state_ = 0;
  clear_has_state();
}
inline ::google::protobuf::int32 missioninfo::state() const {
  return state_;
}
inline void missioninfo::set_state(::google::protobuf::int32 value) {
  set_has_state();
  state_ = value;
}

// -------------------------------------------------------------------

// missionlist

// optional int32 timesec = 1;
inline bool missionlist::has_timesec() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void missionlist::set_has_timesec() {
  _has_bits_[0] |= 0x00000001u;
}
inline void missionlist::clear_has_timesec() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void missionlist::clear_timesec() {
  timesec_ = 0;
  clear_has_timesec();
}
inline ::google::protobuf::int32 missionlist::timesec() const {
  return timesec_;
}
inline void missionlist::set_timesec(::google::protobuf::int32 value) {
  set_has_timesec();
  timesec_ = value;
}

// repeated .progame.missioninfo mslist = 2;
inline int missionlist::mslist_size() const {
  return mslist_.size();
}
inline void missionlist::clear_mslist() {
  mslist_.Clear();
}
inline const ::progame::missioninfo& missionlist::mslist(int index) const {
  return mslist_.Get(index);
}
inline ::progame::missioninfo* missionlist::mutable_mslist(int index) {
  return mslist_.Mutable(index);
}
inline ::progame::missioninfo* missionlist::add_mslist() {
  return mslist_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::progame::missioninfo >&
missionlist::mslist() const {
  return mslist_;
}
inline ::google::protobuf::RepeatedPtrField< ::progame::missioninfo >*
missionlist::mutable_mslist() {
  return &mslist_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace progame

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_st_5fmission_2eproto__INCLUDED
