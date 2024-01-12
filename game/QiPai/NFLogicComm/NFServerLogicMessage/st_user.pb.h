// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: st_user.proto

#ifndef PROTOBUF_st_5fuser_2eproto__INCLUDED
#define PROTOBUF_st_5fuser_2eproto__INCLUDED

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
void  protobuf_AddDesc_st_5fuser_2eproto();
void protobuf_AssignDesc_st_5fuser_2eproto();
void protobuf_ShutdownFile_st_5fuser_2eproto();

class rosterinfo;

// ===================================================================

class rosterinfo : public ::google::protobuf::Message {
 public:
  rosterinfo();
  virtual ~rosterinfo();

  rosterinfo(const rosterinfo& from);

  inline rosterinfo& operator=(const rosterinfo& from) {
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
  static const rosterinfo& default_instance();

  void Swap(rosterinfo* other);

  // implements Message ----------------------------------------------

  rosterinfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const rosterinfo& from);
  void MergeFrom(const rosterinfo& from);
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

  // optional int32 userid = 1;
  inline bool has_userid() const;
  inline void clear_userid();
  static const int kUseridFieldNumber = 1;
  inline ::google::protobuf::int32 userid() const;
  inline void set_userid(::google::protobuf::int32 value);

  // repeated int32 gametype = 2;
  inline int gametype_size() const;
  inline void clear_gametype();
  static const int kGametypeFieldNumber = 2;
  inline ::google::protobuf::int32 gametype(int index) const;
  inline void set_gametype(int index, ::google::protobuf::int32 value);
  inline void add_gametype(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      gametype() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_gametype();

  // repeated int32 tabletype = 3;
  inline int tabletype_size() const;
  inline void clear_tabletype();
  static const int kTabletypeFieldNumber = 3;
  inline ::google::protobuf::int32 tabletype(int index) const;
  inline void set_tabletype(int index, ::google::protobuf::int32 value);
  inline void add_tabletype(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      tabletype() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_tabletype();

  // repeated int32 rostertype = 4;
  inline int rostertype_size() const;
  inline void clear_rostertype();
  static const int kRostertypeFieldNumber = 4;
  inline ::google::protobuf::int32 rostertype(int index) const;
  inline void set_rostertype(int index, ::google::protobuf::int32 value);
  inline void add_rostertype(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      rostertype() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_rostertype();

  // repeated int32 starttime = 5;
  inline int starttime_size() const;
  inline void clear_starttime();
  static const int kStarttimeFieldNumber = 5;
  inline ::google::protobuf::int32 starttime(int index) const;
  inline void set_starttime(int index, ::google::protobuf::int32 value);
  inline void add_starttime(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      starttime() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_starttime();

  // repeated int32 endtime = 6;
  inline int endtime_size() const;
  inline void clear_endtime();
  static const int kEndtimeFieldNumber = 6;
  inline ::google::protobuf::int32 endtime(int index) const;
  inline void set_endtime(int index, ::google::protobuf::int32 value);
  inline void add_endtime(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      endtime() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_endtime();

  // repeated int32 optmark = 7;
  inline int optmark_size() const;
  inline void clear_optmark();
  static const int kOptmarkFieldNumber = 7;
  inline ::google::protobuf::int32 optmark(int index) const;
  inline void set_optmark(int index, ::google::protobuf::int32 value);
  inline void add_optmark(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      optmark() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_optmark();

  // repeated float probability = 8;
  inline int probability_size() const;
  inline void clear_probability();
  static const int kProbabilityFieldNumber = 8;
  inline float probability(int index) const;
  inline void set_probability(int index, float value);
  inline void add_probability(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      probability() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_probability();

  // @@protoc_insertion_point(class_scope:progame.rosterinfo)
 private:
  inline void set_has_userid();
  inline void clear_has_userid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > gametype_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > tabletype_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > rostertype_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > starttime_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > endtime_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > optmark_;
  ::google::protobuf::RepeatedField< float > probability_;
  ::google::protobuf::int32 userid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_st_5fuser_2eproto();
  friend void protobuf_AssignDesc_st_5fuser_2eproto();
  friend void protobuf_ShutdownFile_st_5fuser_2eproto();

  void InitAsDefaultInstance();
  static rosterinfo* default_instance_;
};
// ===================================================================


// ===================================================================

// rosterinfo

// optional int32 userid = 1;
inline bool rosterinfo::has_userid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void rosterinfo::set_has_userid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void rosterinfo::clear_has_userid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void rosterinfo::clear_userid() {
  userid_ = 0;
  clear_has_userid();
}
inline ::google::protobuf::int32 rosterinfo::userid() const {
  return userid_;
}
inline void rosterinfo::set_userid(::google::protobuf::int32 value) {
  set_has_userid();
  userid_ = value;
}

// repeated int32 gametype = 2;
inline int rosterinfo::gametype_size() const {
  return gametype_.size();
}
inline void rosterinfo::clear_gametype() {
  gametype_.Clear();
}
inline ::google::protobuf::int32 rosterinfo::gametype(int index) const {
  return gametype_.Get(index);
}
inline void rosterinfo::set_gametype(int index, ::google::protobuf::int32 value) {
  gametype_.Set(index, value);
}
inline void rosterinfo::add_gametype(::google::protobuf::int32 value) {
  gametype_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
rosterinfo::gametype() const {
  return gametype_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
rosterinfo::mutable_gametype() {
  return &gametype_;
}

// repeated int32 tabletype = 3;
inline int rosterinfo::tabletype_size() const {
  return tabletype_.size();
}
inline void rosterinfo::clear_tabletype() {
  tabletype_.Clear();
}
inline ::google::protobuf::int32 rosterinfo::tabletype(int index) const {
  return tabletype_.Get(index);
}
inline void rosterinfo::set_tabletype(int index, ::google::protobuf::int32 value) {
  tabletype_.Set(index, value);
}
inline void rosterinfo::add_tabletype(::google::protobuf::int32 value) {
  tabletype_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
rosterinfo::tabletype() const {
  return tabletype_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
rosterinfo::mutable_tabletype() {
  return &tabletype_;
}

// repeated int32 rostertype = 4;
inline int rosterinfo::rostertype_size() const {
  return rostertype_.size();
}
inline void rosterinfo::clear_rostertype() {
  rostertype_.Clear();
}
inline ::google::protobuf::int32 rosterinfo::rostertype(int index) const {
  return rostertype_.Get(index);
}
inline void rosterinfo::set_rostertype(int index, ::google::protobuf::int32 value) {
  rostertype_.Set(index, value);
}
inline void rosterinfo::add_rostertype(::google::protobuf::int32 value) {
  rostertype_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
rosterinfo::rostertype() const {
  return rostertype_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
rosterinfo::mutable_rostertype() {
  return &rostertype_;
}

// repeated int32 starttime = 5;
inline int rosterinfo::starttime_size() const {
  return starttime_.size();
}
inline void rosterinfo::clear_starttime() {
  starttime_.Clear();
}
inline ::google::protobuf::int32 rosterinfo::starttime(int index) const {
  return starttime_.Get(index);
}
inline void rosterinfo::set_starttime(int index, ::google::protobuf::int32 value) {
  starttime_.Set(index, value);
}
inline void rosterinfo::add_starttime(::google::protobuf::int32 value) {
  starttime_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
rosterinfo::starttime() const {
  return starttime_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
rosterinfo::mutable_starttime() {
  return &starttime_;
}

// repeated int32 endtime = 6;
inline int rosterinfo::endtime_size() const {
  return endtime_.size();
}
inline void rosterinfo::clear_endtime() {
  endtime_.Clear();
}
inline ::google::protobuf::int32 rosterinfo::endtime(int index) const {
  return endtime_.Get(index);
}
inline void rosterinfo::set_endtime(int index, ::google::protobuf::int32 value) {
  endtime_.Set(index, value);
}
inline void rosterinfo::add_endtime(::google::protobuf::int32 value) {
  endtime_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
rosterinfo::endtime() const {
  return endtime_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
rosterinfo::mutable_endtime() {
  return &endtime_;
}

// repeated int32 optmark = 7;
inline int rosterinfo::optmark_size() const {
  return optmark_.size();
}
inline void rosterinfo::clear_optmark() {
  optmark_.Clear();
}
inline ::google::protobuf::int32 rosterinfo::optmark(int index) const {
  return optmark_.Get(index);
}
inline void rosterinfo::set_optmark(int index, ::google::protobuf::int32 value) {
  optmark_.Set(index, value);
}
inline void rosterinfo::add_optmark(::google::protobuf::int32 value) {
  optmark_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
rosterinfo::optmark() const {
  return optmark_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
rosterinfo::mutable_optmark() {
  return &optmark_;
}

// repeated float probability = 8;
inline int rosterinfo::probability_size() const {
  return probability_.size();
}
inline void rosterinfo::clear_probability() {
  probability_.Clear();
}
inline float rosterinfo::probability(int index) const {
  return probability_.Get(index);
}
inline void rosterinfo::set_probability(int index, float value) {
  probability_.Set(index, value);
}
inline void rosterinfo::add_probability(float value) {
  probability_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
rosterinfo::probability() const {
  return probability_;
}
inline ::google::protobuf::RepeatedField< float >*
rosterinfo::mutable_probability() {
  return &probability_;
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

#endif  // PROTOBUF_st_5fuser_2eproto__INCLUDED
