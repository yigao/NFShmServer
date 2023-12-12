// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MiniActivity.proto

#ifndef PROTOBUF_MiniActivity_2eproto__INCLUDED
#define PROTOBUF_MiniActivity_2eproto__INCLUDED

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
#include "Com.pb.h"
#include "ComDefine.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MiniActivity_2eproto();
void protobuf_AssignDesc_MiniActivity_2eproto();
void protobuf_ShutdownFile_MiniActivity_2eproto();

class GetGodRelicsInfoReq;
class GetGodRelicsInfoRsp;
class UpdateGodRelecsNotify;
class GetGodRelicsTaskRewardReq;
class GetGodRelicsTaskRewardRsp;
class GetGodRelecsGroupTaskRewardReq;
class GetGodRelecsGroupTaskRewardRsp;

// ===================================================================

class GetGodRelicsInfoReq : public ::google::protobuf::Message {
 public:
  GetGodRelicsInfoReq();
  virtual ~GetGodRelicsInfoReq();

  GetGodRelicsInfoReq(const GetGodRelicsInfoReq& from);

  inline GetGodRelicsInfoReq& operator=(const GetGodRelicsInfoReq& from) {
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
  static const GetGodRelicsInfoReq& default_instance();

  void Swap(GetGodRelicsInfoReq* other);

  // implements Message ----------------------------------------------

  GetGodRelicsInfoReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGodRelicsInfoReq& from);
  void MergeFrom(const GetGodRelicsInfoReq& from);
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

  // @@protoc_insertion_point(class_scope:proto_ff.GetGodRelicsInfoReq)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static GetGodRelicsInfoReq* default_instance_;
};
// -------------------------------------------------------------------

class GetGodRelicsInfoRsp : public ::google::protobuf::Message {
 public:
  GetGodRelicsInfoRsp();
  virtual ~GetGodRelicsInfoRsp();

  GetGodRelicsInfoRsp(const GetGodRelicsInfoRsp& from);

  inline GetGodRelicsInfoRsp& operator=(const GetGodRelicsInfoRsp& from) {
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
  static const GetGodRelicsInfoRsp& default_instance();

  void Swap(GetGodRelicsInfoRsp* other);

  // implements Message ----------------------------------------------

  GetGodRelicsInfoRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGodRelicsInfoRsp& from);
  void MergeFrom(const GetGodRelicsInfoRsp& from);
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

  // repeated .proto_ff.GodRelicsTaskGroupEntry group_data = 1;
  inline int group_data_size() const;
  inline void clear_group_data();
  static const int kGroupDataFieldNumber = 1;
  inline const ::proto_ff::GodRelicsTaskGroupEntry& group_data(int index) const;
  inline ::proto_ff::GodRelicsTaskGroupEntry* mutable_group_data(int index);
  inline ::proto_ff::GodRelicsTaskGroupEntry* add_group_data();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::GodRelicsTaskGroupEntry >&
      group_data() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::GodRelicsTaskGroupEntry >*
      mutable_group_data();

  // optional int64 cur_group_id = 2;
  inline bool has_cur_group_id() const;
  inline void clear_cur_group_id();
  static const int kCurGroupIdFieldNumber = 2;
  inline ::google::protobuf::int64 cur_group_id() const;
  inline void set_cur_group_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.GetGodRelicsInfoRsp)
 private:
  inline void set_has_cur_group_id();
  inline void clear_has_cur_group_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::GodRelicsTaskGroupEntry > group_data_;
  ::google::protobuf::int64 cur_group_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static GetGodRelicsInfoRsp* default_instance_;
};
// -------------------------------------------------------------------

class UpdateGodRelecsNotify : public ::google::protobuf::Message {
 public:
  UpdateGodRelecsNotify();
  virtual ~UpdateGodRelecsNotify();

  UpdateGodRelecsNotify(const UpdateGodRelecsNotify& from);

  inline UpdateGodRelecsNotify& operator=(const UpdateGodRelecsNotify& from) {
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
  static const UpdateGodRelecsNotify& default_instance();

  void Swap(UpdateGodRelecsNotify* other);

  // implements Message ----------------------------------------------

  UpdateGodRelecsNotify* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UpdateGodRelecsNotify& from);
  void MergeFrom(const UpdateGodRelecsNotify& from);
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

  // optional .proto_ff.GodRelicsTaskGroupEntry group_data = 1;
  inline bool has_group_data() const;
  inline void clear_group_data();
  static const int kGroupDataFieldNumber = 1;
  inline const ::proto_ff::GodRelicsTaskGroupEntry& group_data() const;
  inline ::proto_ff::GodRelicsTaskGroupEntry* mutable_group_data();
  inline ::proto_ff::GodRelicsTaskGroupEntry* release_group_data();
  inline void set_allocated_group_data(::proto_ff::GodRelicsTaskGroupEntry* group_data);

  // optional uint32 cur_id = 2;
  inline bool has_cur_id() const;
  inline void clear_cur_id();
  static const int kCurIdFieldNumber = 2;
  inline ::google::protobuf::uint32 cur_id() const;
  inline void set_cur_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.UpdateGodRelecsNotify)
 private:
  inline void set_has_group_data();
  inline void clear_has_group_data();
  inline void set_has_cur_id();
  inline void clear_has_cur_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::proto_ff::GodRelicsTaskGroupEntry* group_data_;
  ::google::protobuf::uint32 cur_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static UpdateGodRelecsNotify* default_instance_;
};
// -------------------------------------------------------------------

class GetGodRelicsTaskRewardReq : public ::google::protobuf::Message {
 public:
  GetGodRelicsTaskRewardReq();
  virtual ~GetGodRelicsTaskRewardReq();

  GetGodRelicsTaskRewardReq(const GetGodRelicsTaskRewardReq& from);

  inline GetGodRelicsTaskRewardReq& operator=(const GetGodRelicsTaskRewardReq& from) {
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
  static const GetGodRelicsTaskRewardReq& default_instance();

  void Swap(GetGodRelicsTaskRewardReq* other);

  // implements Message ----------------------------------------------

  GetGodRelicsTaskRewardReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGodRelicsTaskRewardReq& from);
  void MergeFrom(const GetGodRelicsTaskRewardReq& from);
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

  // optional int64 group_id = 1;
  inline bool has_group_id() const;
  inline void clear_group_id();
  static const int kGroupIdFieldNumber = 1;
  inline ::google::protobuf::int64 group_id() const;
  inline void set_group_id(::google::protobuf::int64 value);

  // optional int64 task_id = 2;
  inline bool has_task_id() const;
  inline void clear_task_id();
  static const int kTaskIdFieldNumber = 2;
  inline ::google::protobuf::int64 task_id() const;
  inline void set_task_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.GetGodRelicsTaskRewardReq)
 private:
  inline void set_has_group_id();
  inline void clear_has_group_id();
  inline void set_has_task_id();
  inline void clear_has_task_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 group_id_;
  ::google::protobuf::int64 task_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static GetGodRelicsTaskRewardReq* default_instance_;
};
// -------------------------------------------------------------------

class GetGodRelicsTaskRewardRsp : public ::google::protobuf::Message {
 public:
  GetGodRelicsTaskRewardRsp();
  virtual ~GetGodRelicsTaskRewardRsp();

  GetGodRelicsTaskRewardRsp(const GetGodRelicsTaskRewardRsp& from);

  inline GetGodRelicsTaskRewardRsp& operator=(const GetGodRelicsTaskRewardRsp& from) {
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
  static const GetGodRelicsTaskRewardRsp& default_instance();

  void Swap(GetGodRelicsTaskRewardRsp* other);

  // implements Message ----------------------------------------------

  GetGodRelicsTaskRewardRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGodRelicsTaskRewardRsp& from);
  void MergeFrom(const GetGodRelicsTaskRewardRsp& from);
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

  // optional int64 ret_code = 1;
  inline bool has_ret_code() const;
  inline void clear_ret_code();
  static const int kRetCodeFieldNumber = 1;
  inline ::google::protobuf::int64 ret_code() const;
  inline void set_ret_code(::google::protobuf::int64 value);

  // optional int64 task_id = 2;
  inline bool has_task_id() const;
  inline void clear_task_id();
  static const int kTaskIdFieldNumber = 2;
  inline ::google::protobuf::int64 task_id() const;
  inline void set_task_id(::google::protobuf::int64 value);

  // optional .proto_ff.GodRelicsTaskGroupEntry group_data = 3;
  inline bool has_group_data() const;
  inline void clear_group_data();
  static const int kGroupDataFieldNumber = 3;
  inline const ::proto_ff::GodRelicsTaskGroupEntry& group_data() const;
  inline ::proto_ff::GodRelicsTaskGroupEntry* mutable_group_data();
  inline ::proto_ff::GodRelicsTaskGroupEntry* release_group_data();
  inline void set_allocated_group_data(::proto_ff::GodRelicsTaskGroupEntry* group_data);

  // @@protoc_insertion_point(class_scope:proto_ff.GetGodRelicsTaskRewardRsp)
 private:
  inline void set_has_ret_code();
  inline void clear_has_ret_code();
  inline void set_has_task_id();
  inline void clear_has_task_id();
  inline void set_has_group_data();
  inline void clear_has_group_data();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 ret_code_;
  ::google::protobuf::int64 task_id_;
  ::proto_ff::GodRelicsTaskGroupEntry* group_data_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static GetGodRelicsTaskRewardRsp* default_instance_;
};
// -------------------------------------------------------------------

class GetGodRelecsGroupTaskRewardReq : public ::google::protobuf::Message {
 public:
  GetGodRelecsGroupTaskRewardReq();
  virtual ~GetGodRelecsGroupTaskRewardReq();

  GetGodRelecsGroupTaskRewardReq(const GetGodRelecsGroupTaskRewardReq& from);

  inline GetGodRelecsGroupTaskRewardReq& operator=(const GetGodRelecsGroupTaskRewardReq& from) {
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
  static const GetGodRelecsGroupTaskRewardReq& default_instance();

  void Swap(GetGodRelecsGroupTaskRewardReq* other);

  // implements Message ----------------------------------------------

  GetGodRelecsGroupTaskRewardReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGodRelecsGroupTaskRewardReq& from);
  void MergeFrom(const GetGodRelecsGroupTaskRewardReq& from);
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

  // optional int64 group_id = 1;
  inline bool has_group_id() const;
  inline void clear_group_id();
  static const int kGroupIdFieldNumber = 1;
  inline ::google::protobuf::int64 group_id() const;
  inline void set_group_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.GetGodRelecsGroupTaskRewardReq)
 private:
  inline void set_has_group_id();
  inline void clear_has_group_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 group_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static GetGodRelecsGroupTaskRewardReq* default_instance_;
};
// -------------------------------------------------------------------

class GetGodRelecsGroupTaskRewardRsp : public ::google::protobuf::Message {
 public:
  GetGodRelecsGroupTaskRewardRsp();
  virtual ~GetGodRelecsGroupTaskRewardRsp();

  GetGodRelecsGroupTaskRewardRsp(const GetGodRelecsGroupTaskRewardRsp& from);

  inline GetGodRelecsGroupTaskRewardRsp& operator=(const GetGodRelecsGroupTaskRewardRsp& from) {
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
  static const GetGodRelecsGroupTaskRewardRsp& default_instance();

  void Swap(GetGodRelecsGroupTaskRewardRsp* other);

  // implements Message ----------------------------------------------

  GetGodRelecsGroupTaskRewardRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGodRelecsGroupTaskRewardRsp& from);
  void MergeFrom(const GetGodRelecsGroupTaskRewardRsp& from);
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

  // optional int64 ret_code = 1;
  inline bool has_ret_code() const;
  inline void clear_ret_code();
  static const int kRetCodeFieldNumber = 1;
  inline ::google::protobuf::int64 ret_code() const;
  inline void set_ret_code(::google::protobuf::int64 value);

  // optional .proto_ff.GodRelicsTaskGroupEntry old_group_data = 2;
  inline bool has_old_group_data() const;
  inline void clear_old_group_data();
  static const int kOldGroupDataFieldNumber = 2;
  inline const ::proto_ff::GodRelicsTaskGroupEntry& old_group_data() const;
  inline ::proto_ff::GodRelicsTaskGroupEntry* mutable_old_group_data();
  inline ::proto_ff::GodRelicsTaskGroupEntry* release_old_group_data();
  inline void set_allocated_old_group_data(::proto_ff::GodRelicsTaskGroupEntry* old_group_data);

  // optional .proto_ff.GodRelicsTaskGroupEntry new_group_data = 3;
  inline bool has_new_group_data() const;
  inline void clear_new_group_data();
  static const int kNewGroupDataFieldNumber = 3;
  inline const ::proto_ff::GodRelicsTaskGroupEntry& new_group_data() const;
  inline ::proto_ff::GodRelicsTaskGroupEntry* mutable_new_group_data();
  inline ::proto_ff::GodRelicsTaskGroupEntry* release_new_group_data();
  inline void set_allocated_new_group_data(::proto_ff::GodRelicsTaskGroupEntry* new_group_data);

  // @@protoc_insertion_point(class_scope:proto_ff.GetGodRelecsGroupTaskRewardRsp)
 private:
  inline void set_has_ret_code();
  inline void clear_has_ret_code();
  inline void set_has_old_group_data();
  inline void clear_has_old_group_data();
  inline void set_has_new_group_data();
  inline void clear_has_new_group_data();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 ret_code_;
  ::proto_ff::GodRelicsTaskGroupEntry* old_group_data_;
  ::proto_ff::GodRelicsTaskGroupEntry* new_group_data_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_MiniActivity_2eproto();
  friend void protobuf_AssignDesc_MiniActivity_2eproto();
  friend void protobuf_ShutdownFile_MiniActivity_2eproto();

  void InitAsDefaultInstance();
  static GetGodRelecsGroupTaskRewardRsp* default_instance_;
};
// ===================================================================


// ===================================================================

// GetGodRelicsInfoReq

// -------------------------------------------------------------------

// GetGodRelicsInfoRsp

// repeated .proto_ff.GodRelicsTaskGroupEntry group_data = 1;
inline int GetGodRelicsInfoRsp::group_data_size() const {
  return group_data_.size();
}
inline void GetGodRelicsInfoRsp::clear_group_data() {
  group_data_.Clear();
}
inline const ::proto_ff::GodRelicsTaskGroupEntry& GetGodRelicsInfoRsp::group_data(int index) const {
  return group_data_.Get(index);
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelicsInfoRsp::mutable_group_data(int index) {
  return group_data_.Mutable(index);
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelicsInfoRsp::add_group_data() {
  return group_data_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::GodRelicsTaskGroupEntry >&
GetGodRelicsInfoRsp::group_data() const {
  return group_data_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::GodRelicsTaskGroupEntry >*
GetGodRelicsInfoRsp::mutable_group_data() {
  return &group_data_;
}

// optional int64 cur_group_id = 2;
inline bool GetGodRelicsInfoRsp::has_cur_group_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GetGodRelicsInfoRsp::set_has_cur_group_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GetGodRelicsInfoRsp::clear_has_cur_group_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GetGodRelicsInfoRsp::clear_cur_group_id() {
  cur_group_id_ = GOOGLE_LONGLONG(0);
  clear_has_cur_group_id();
}
inline ::google::protobuf::int64 GetGodRelicsInfoRsp::cur_group_id() const {
  return cur_group_id_;
}
inline void GetGodRelicsInfoRsp::set_cur_group_id(::google::protobuf::int64 value) {
  set_has_cur_group_id();
  cur_group_id_ = value;
}

// -------------------------------------------------------------------

// UpdateGodRelecsNotify

// optional .proto_ff.GodRelicsTaskGroupEntry group_data = 1;
inline bool UpdateGodRelecsNotify::has_group_data() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UpdateGodRelecsNotify::set_has_group_data() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UpdateGodRelecsNotify::clear_has_group_data() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UpdateGodRelecsNotify::clear_group_data() {
  if (group_data_ != NULL) group_data_->::proto_ff::GodRelicsTaskGroupEntry::Clear();
  clear_has_group_data();
}
inline const ::proto_ff::GodRelicsTaskGroupEntry& UpdateGodRelecsNotify::group_data() const {
  return group_data_ != NULL ? *group_data_ : *default_instance_->group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* UpdateGodRelecsNotify::mutable_group_data() {
  set_has_group_data();
  if (group_data_ == NULL) group_data_ = new ::proto_ff::GodRelicsTaskGroupEntry;
  return group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* UpdateGodRelecsNotify::release_group_data() {
  clear_has_group_data();
  ::proto_ff::GodRelicsTaskGroupEntry* temp = group_data_;
  group_data_ = NULL;
  return temp;
}
inline void UpdateGodRelecsNotify::set_allocated_group_data(::proto_ff::GodRelicsTaskGroupEntry* group_data) {
  delete group_data_;
  group_data_ = group_data;
  if (group_data) {
    set_has_group_data();
  } else {
    clear_has_group_data();
  }
}

// optional uint32 cur_id = 2;
inline bool UpdateGodRelecsNotify::has_cur_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UpdateGodRelecsNotify::set_has_cur_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void UpdateGodRelecsNotify::clear_has_cur_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void UpdateGodRelecsNotify::clear_cur_id() {
  cur_id_ = 0u;
  clear_has_cur_id();
}
inline ::google::protobuf::uint32 UpdateGodRelecsNotify::cur_id() const {
  return cur_id_;
}
inline void UpdateGodRelecsNotify::set_cur_id(::google::protobuf::uint32 value) {
  set_has_cur_id();
  cur_id_ = value;
}

// -------------------------------------------------------------------

// GetGodRelicsTaskRewardReq

// optional int64 group_id = 1;
inline bool GetGodRelicsTaskRewardReq::has_group_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetGodRelicsTaskRewardReq::set_has_group_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetGodRelicsTaskRewardReq::clear_has_group_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetGodRelicsTaskRewardReq::clear_group_id() {
  group_id_ = GOOGLE_LONGLONG(0);
  clear_has_group_id();
}
inline ::google::protobuf::int64 GetGodRelicsTaskRewardReq::group_id() const {
  return group_id_;
}
inline void GetGodRelicsTaskRewardReq::set_group_id(::google::protobuf::int64 value) {
  set_has_group_id();
  group_id_ = value;
}

// optional int64 task_id = 2;
inline bool GetGodRelicsTaskRewardReq::has_task_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GetGodRelicsTaskRewardReq::set_has_task_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GetGodRelicsTaskRewardReq::clear_has_task_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GetGodRelicsTaskRewardReq::clear_task_id() {
  task_id_ = GOOGLE_LONGLONG(0);
  clear_has_task_id();
}
inline ::google::protobuf::int64 GetGodRelicsTaskRewardReq::task_id() const {
  return task_id_;
}
inline void GetGodRelicsTaskRewardReq::set_task_id(::google::protobuf::int64 value) {
  set_has_task_id();
  task_id_ = value;
}

// -------------------------------------------------------------------

// GetGodRelicsTaskRewardRsp

// optional int64 ret_code = 1;
inline bool GetGodRelicsTaskRewardRsp::has_ret_code() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetGodRelicsTaskRewardRsp::set_has_ret_code() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetGodRelicsTaskRewardRsp::clear_has_ret_code() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetGodRelicsTaskRewardRsp::clear_ret_code() {
  ret_code_ = GOOGLE_LONGLONG(0);
  clear_has_ret_code();
}
inline ::google::protobuf::int64 GetGodRelicsTaskRewardRsp::ret_code() const {
  return ret_code_;
}
inline void GetGodRelicsTaskRewardRsp::set_ret_code(::google::protobuf::int64 value) {
  set_has_ret_code();
  ret_code_ = value;
}

// optional int64 task_id = 2;
inline bool GetGodRelicsTaskRewardRsp::has_task_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GetGodRelicsTaskRewardRsp::set_has_task_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GetGodRelicsTaskRewardRsp::clear_has_task_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GetGodRelicsTaskRewardRsp::clear_task_id() {
  task_id_ = GOOGLE_LONGLONG(0);
  clear_has_task_id();
}
inline ::google::protobuf::int64 GetGodRelicsTaskRewardRsp::task_id() const {
  return task_id_;
}
inline void GetGodRelicsTaskRewardRsp::set_task_id(::google::protobuf::int64 value) {
  set_has_task_id();
  task_id_ = value;
}

// optional .proto_ff.GodRelicsTaskGroupEntry group_data = 3;
inline bool GetGodRelicsTaskRewardRsp::has_group_data() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GetGodRelicsTaskRewardRsp::set_has_group_data() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GetGodRelicsTaskRewardRsp::clear_has_group_data() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GetGodRelicsTaskRewardRsp::clear_group_data() {
  if (group_data_ != NULL) group_data_->::proto_ff::GodRelicsTaskGroupEntry::Clear();
  clear_has_group_data();
}
inline const ::proto_ff::GodRelicsTaskGroupEntry& GetGodRelicsTaskRewardRsp::group_data() const {
  return group_data_ != NULL ? *group_data_ : *default_instance_->group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelicsTaskRewardRsp::mutable_group_data() {
  set_has_group_data();
  if (group_data_ == NULL) group_data_ = new ::proto_ff::GodRelicsTaskGroupEntry;
  return group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelicsTaskRewardRsp::release_group_data() {
  clear_has_group_data();
  ::proto_ff::GodRelicsTaskGroupEntry* temp = group_data_;
  group_data_ = NULL;
  return temp;
}
inline void GetGodRelicsTaskRewardRsp::set_allocated_group_data(::proto_ff::GodRelicsTaskGroupEntry* group_data) {
  delete group_data_;
  group_data_ = group_data;
  if (group_data) {
    set_has_group_data();
  } else {
    clear_has_group_data();
  }
}

// -------------------------------------------------------------------

// GetGodRelecsGroupTaskRewardReq

// optional int64 group_id = 1;
inline bool GetGodRelecsGroupTaskRewardReq::has_group_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetGodRelecsGroupTaskRewardReq::set_has_group_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetGodRelecsGroupTaskRewardReq::clear_has_group_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetGodRelecsGroupTaskRewardReq::clear_group_id() {
  group_id_ = GOOGLE_LONGLONG(0);
  clear_has_group_id();
}
inline ::google::protobuf::int64 GetGodRelecsGroupTaskRewardReq::group_id() const {
  return group_id_;
}
inline void GetGodRelecsGroupTaskRewardReq::set_group_id(::google::protobuf::int64 value) {
  set_has_group_id();
  group_id_ = value;
}

// -------------------------------------------------------------------

// GetGodRelecsGroupTaskRewardRsp

// optional int64 ret_code = 1;
inline bool GetGodRelecsGroupTaskRewardRsp::has_ret_code() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetGodRelecsGroupTaskRewardRsp::set_has_ret_code() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetGodRelecsGroupTaskRewardRsp::clear_has_ret_code() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetGodRelecsGroupTaskRewardRsp::clear_ret_code() {
  ret_code_ = GOOGLE_LONGLONG(0);
  clear_has_ret_code();
}
inline ::google::protobuf::int64 GetGodRelecsGroupTaskRewardRsp::ret_code() const {
  return ret_code_;
}
inline void GetGodRelecsGroupTaskRewardRsp::set_ret_code(::google::protobuf::int64 value) {
  set_has_ret_code();
  ret_code_ = value;
}

// optional .proto_ff.GodRelicsTaskGroupEntry old_group_data = 2;
inline bool GetGodRelecsGroupTaskRewardRsp::has_old_group_data() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GetGodRelecsGroupTaskRewardRsp::set_has_old_group_data() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GetGodRelecsGroupTaskRewardRsp::clear_has_old_group_data() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GetGodRelecsGroupTaskRewardRsp::clear_old_group_data() {
  if (old_group_data_ != NULL) old_group_data_->::proto_ff::GodRelicsTaskGroupEntry::Clear();
  clear_has_old_group_data();
}
inline const ::proto_ff::GodRelicsTaskGroupEntry& GetGodRelecsGroupTaskRewardRsp::old_group_data() const {
  return old_group_data_ != NULL ? *old_group_data_ : *default_instance_->old_group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelecsGroupTaskRewardRsp::mutable_old_group_data() {
  set_has_old_group_data();
  if (old_group_data_ == NULL) old_group_data_ = new ::proto_ff::GodRelicsTaskGroupEntry;
  return old_group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelecsGroupTaskRewardRsp::release_old_group_data() {
  clear_has_old_group_data();
  ::proto_ff::GodRelicsTaskGroupEntry* temp = old_group_data_;
  old_group_data_ = NULL;
  return temp;
}
inline void GetGodRelecsGroupTaskRewardRsp::set_allocated_old_group_data(::proto_ff::GodRelicsTaskGroupEntry* old_group_data) {
  delete old_group_data_;
  old_group_data_ = old_group_data;
  if (old_group_data) {
    set_has_old_group_data();
  } else {
    clear_has_old_group_data();
  }
}

// optional .proto_ff.GodRelicsTaskGroupEntry new_group_data = 3;
inline bool GetGodRelecsGroupTaskRewardRsp::has_new_group_data() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GetGodRelecsGroupTaskRewardRsp::set_has_new_group_data() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GetGodRelecsGroupTaskRewardRsp::clear_has_new_group_data() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GetGodRelecsGroupTaskRewardRsp::clear_new_group_data() {
  if (new_group_data_ != NULL) new_group_data_->::proto_ff::GodRelicsTaskGroupEntry::Clear();
  clear_has_new_group_data();
}
inline const ::proto_ff::GodRelicsTaskGroupEntry& GetGodRelecsGroupTaskRewardRsp::new_group_data() const {
  return new_group_data_ != NULL ? *new_group_data_ : *default_instance_->new_group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelecsGroupTaskRewardRsp::mutable_new_group_data() {
  set_has_new_group_data();
  if (new_group_data_ == NULL) new_group_data_ = new ::proto_ff::GodRelicsTaskGroupEntry;
  return new_group_data_;
}
inline ::proto_ff::GodRelicsTaskGroupEntry* GetGodRelecsGroupTaskRewardRsp::release_new_group_data() {
  clear_has_new_group_data();
  ::proto_ff::GodRelicsTaskGroupEntry* temp = new_group_data_;
  new_group_data_ = NULL;
  return temp;
}
inline void GetGodRelecsGroupTaskRewardRsp::set_allocated_new_group_data(::proto_ff::GodRelicsTaskGroupEntry* new_group_data) {
  delete new_group_data_;
  new_group_data_ = new_group_data;
  if (new_group_data) {
    set_has_new_group_data();
  } else {
    clear_has_new_group_data();
  }
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

#endif  // PROTOBUF_MiniActivity_2eproto__INCLUDED
