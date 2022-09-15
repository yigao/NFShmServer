// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto_common.proto

#ifndef PROTOBUF_proto_5fcommon_2eproto__INCLUDED
#define PROTOBUF_proto_5fcommon_2eproto__INCLUDED

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
void  protobuf_AddDesc_proto_5fcommon_2eproto();
void protobuf_AssignDesc_proto_5fcommon_2eproto();
void protobuf_ShutdownFile_proto_5fcommon_2eproto();

class tbServerMgr;

// ===================================================================

class tbServerMgr : public ::google::protobuf::Message {
 public:
  tbServerMgr();
  virtual ~tbServerMgr();

  tbServerMgr(const tbServerMgr& from);

  inline tbServerMgr& operator=(const tbServerMgr& from) {
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
  static const tbServerMgr& default_instance();

  void Swap(tbServerMgr* other);

  // implements Message ----------------------------------------------

  tbServerMgr* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const tbServerMgr& from);
  void MergeFrom(const tbServerMgr& from);
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

  // optional uint64 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint64 id() const;
  inline void set_id(::google::protobuf::uint64 value);

  // optional string contract = 2;
  inline bool has_contract() const;
  inline void clear_contract();
  static const int kContractFieldNumber = 2;
  inline const ::std::string& contract() const;
  inline void set_contract(const ::std::string& value);
  inline void set_contract(const char* value);
  inline void set_contract(const char* value, size_t size);
  inline ::std::string* mutable_contract();
  inline ::std::string* release_contract();
  inline void set_allocated_contract(::std::string* contract);

  // optional string machine_addr = 3;
  inline bool has_machine_addr() const;
  inline void clear_machine_addr();
  static const int kMachineAddrFieldNumber = 3;
  inline const ::std::string& machine_addr() const;
  inline void set_machine_addr(const ::std::string& value);
  inline void set_machine_addr(const char* value);
  inline void set_machine_addr(const char* value, size_t size);
  inline ::std::string* mutable_machine_addr();
  inline ::std::string* release_machine_addr();
  inline void set_allocated_machine_addr(::std::string* machine_addr);

  // optional string ip = 4;
  inline bool has_ip() const;
  inline void clear_ip();
  static const int kIpFieldNumber = 4;
  inline const ::std::string& ip() const;
  inline void set_ip(const ::std::string& value);
  inline void set_ip(const char* value);
  inline void set_ip(const char* value, size_t size);
  inline ::std::string* mutable_ip();
  inline ::std::string* release_ip();
  inline void set_allocated_ip(::std::string* ip);

  // optional string bus_name = 5;
  inline bool has_bus_name() const;
  inline void clear_bus_name();
  static const int kBusNameFieldNumber = 5;
  inline const ::std::string& bus_name() const;
  inline void set_bus_name(const ::std::string& value);
  inline void set_bus_name(const char* value);
  inline void set_bus_name(const char* value, size_t size);
  inline ::std::string* mutable_bus_name();
  inline ::std::string* release_bus_name();
  inline void set_allocated_bus_name(::std::string* bus_name);

  // optional string server_desc = 6;
  inline bool has_server_desc() const;
  inline void clear_server_desc();
  static const int kServerDescFieldNumber = 6;
  inline const ::std::string& server_desc() const;
  inline void set_server_desc(const ::std::string& value);
  inline void set_server_desc(const char* value);
  inline void set_server_desc(const char* value, size_t size);
  inline ::std::string* mutable_server_desc();
  inline ::std::string* release_server_desc();
  inline void set_allocated_server_desc(::std::string* server_desc);

  // optional uint32 cur_count = 7;
  inline bool has_cur_count() const;
  inline void clear_cur_count();
  static const int kCurCountFieldNumber = 7;
  inline ::google::protobuf::uint32 cur_count() const;
  inline void set_cur_count(::google::protobuf::uint32 value);

  // optional uint64 last_login_time = 8;
  inline bool has_last_login_time() const;
  inline void clear_last_login_time();
  static const int kLastLoginTimeFieldNumber = 8;
  inline ::google::protobuf::uint64 last_login_time() const;
  inline void set_last_login_time(::google::protobuf::uint64 value);

  // optional uint64 last_logout_time = 9;
  inline bool has_last_logout_time() const;
  inline void clear_last_logout_time();
  static const int kLastLogoutTimeFieldNumber = 9;
  inline ::google::protobuf::uint64 last_logout_time() const;
  inline void set_last_logout_time(::google::protobuf::uint64 value);

  // optional uint64 create_time = 10;
  inline bool has_create_time() const;
  inline void clear_create_time();
  static const int kCreateTimeFieldNumber = 10;
  inline ::google::protobuf::uint64 create_time() const;
  inline void set_create_time(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:proto_ff.tbServerMgr)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_contract();
  inline void clear_has_contract();
  inline void set_has_machine_addr();
  inline void clear_has_machine_addr();
  inline void set_has_ip();
  inline void clear_has_ip();
  inline void set_has_bus_name();
  inline void clear_has_bus_name();
  inline void set_has_server_desc();
  inline void clear_has_server_desc();
  inline void set_has_cur_count();
  inline void clear_has_cur_count();
  inline void set_has_last_login_time();
  inline void clear_has_last_login_time();
  inline void set_has_last_logout_time();
  inline void clear_has_last_logout_time();
  inline void set_has_create_time();
  inline void clear_has_create_time();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 id_;
  ::std::string* contract_;
  ::std::string* machine_addr_;
  ::std::string* ip_;
  ::std::string* bus_name_;
  ::std::string* server_desc_;
  ::google::protobuf::uint64 last_login_time_;
  ::google::protobuf::uint64 last_logout_time_;
  ::google::protobuf::uint64 create_time_;
  ::google::protobuf::uint32 cur_count_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(10 + 31) / 32];

  friend void  protobuf_AddDesc_proto_5fcommon_2eproto();
  friend void protobuf_AssignDesc_proto_5fcommon_2eproto();
  friend void protobuf_ShutdownFile_proto_5fcommon_2eproto();

  void InitAsDefaultInstance();
  static tbServerMgr* default_instance_;
};
// ===================================================================


// ===================================================================

// tbServerMgr

// optional uint64 id = 1;
inline bool tbServerMgr::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void tbServerMgr::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void tbServerMgr::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void tbServerMgr::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::uint64 tbServerMgr::id() const {
  return id_;
}
inline void tbServerMgr::set_id(::google::protobuf::uint64 value) {
  set_has_id();
  id_ = value;
}

// optional string contract = 2;
inline bool tbServerMgr::has_contract() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void tbServerMgr::set_has_contract() {
  _has_bits_[0] |= 0x00000002u;
}
inline void tbServerMgr::clear_has_contract() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void tbServerMgr::clear_contract() {
  if (contract_ != &::google::protobuf::internal::kEmptyString) {
    contract_->clear();
  }
  clear_has_contract();
}
inline const ::std::string& tbServerMgr::contract() const {
  return *contract_;
}
inline void tbServerMgr::set_contract(const ::std::string& value) {
  set_has_contract();
  if (contract_ == &::google::protobuf::internal::kEmptyString) {
    contract_ = new ::std::string;
  }
  contract_->assign(value);
}
inline void tbServerMgr::set_contract(const char* value) {
  set_has_contract();
  if (contract_ == &::google::protobuf::internal::kEmptyString) {
    contract_ = new ::std::string;
  }
  contract_->assign(value);
}
inline void tbServerMgr::set_contract(const char* value, size_t size) {
  set_has_contract();
  if (contract_ == &::google::protobuf::internal::kEmptyString) {
    contract_ = new ::std::string;
  }
  contract_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* tbServerMgr::mutable_contract() {
  set_has_contract();
  if (contract_ == &::google::protobuf::internal::kEmptyString) {
    contract_ = new ::std::string;
  }
  return contract_;
}
inline ::std::string* tbServerMgr::release_contract() {
  clear_has_contract();
  if (contract_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = contract_;
    contract_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void tbServerMgr::set_allocated_contract(::std::string* contract) {
  if (contract_ != &::google::protobuf::internal::kEmptyString) {
    delete contract_;
  }
  if (contract) {
    set_has_contract();
    contract_ = contract;
  } else {
    clear_has_contract();
    contract_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string machine_addr = 3;
inline bool tbServerMgr::has_machine_addr() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void tbServerMgr::set_has_machine_addr() {
  _has_bits_[0] |= 0x00000004u;
}
inline void tbServerMgr::clear_has_machine_addr() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void tbServerMgr::clear_machine_addr() {
  if (machine_addr_ != &::google::protobuf::internal::kEmptyString) {
    machine_addr_->clear();
  }
  clear_has_machine_addr();
}
inline const ::std::string& tbServerMgr::machine_addr() const {
  return *machine_addr_;
}
inline void tbServerMgr::set_machine_addr(const ::std::string& value) {
  set_has_machine_addr();
  if (machine_addr_ == &::google::protobuf::internal::kEmptyString) {
    machine_addr_ = new ::std::string;
  }
  machine_addr_->assign(value);
}
inline void tbServerMgr::set_machine_addr(const char* value) {
  set_has_machine_addr();
  if (machine_addr_ == &::google::protobuf::internal::kEmptyString) {
    machine_addr_ = new ::std::string;
  }
  machine_addr_->assign(value);
}
inline void tbServerMgr::set_machine_addr(const char* value, size_t size) {
  set_has_machine_addr();
  if (machine_addr_ == &::google::protobuf::internal::kEmptyString) {
    machine_addr_ = new ::std::string;
  }
  machine_addr_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* tbServerMgr::mutable_machine_addr() {
  set_has_machine_addr();
  if (machine_addr_ == &::google::protobuf::internal::kEmptyString) {
    machine_addr_ = new ::std::string;
  }
  return machine_addr_;
}
inline ::std::string* tbServerMgr::release_machine_addr() {
  clear_has_machine_addr();
  if (machine_addr_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = machine_addr_;
    machine_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void tbServerMgr::set_allocated_machine_addr(::std::string* machine_addr) {
  if (machine_addr_ != &::google::protobuf::internal::kEmptyString) {
    delete machine_addr_;
  }
  if (machine_addr) {
    set_has_machine_addr();
    machine_addr_ = machine_addr;
  } else {
    clear_has_machine_addr();
    machine_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string ip = 4;
inline bool tbServerMgr::has_ip() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void tbServerMgr::set_has_ip() {
  _has_bits_[0] |= 0x00000008u;
}
inline void tbServerMgr::clear_has_ip() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void tbServerMgr::clear_ip() {
  if (ip_ != &::google::protobuf::internal::kEmptyString) {
    ip_->clear();
  }
  clear_has_ip();
}
inline const ::std::string& tbServerMgr::ip() const {
  return *ip_;
}
inline void tbServerMgr::set_ip(const ::std::string& value) {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void tbServerMgr::set_ip(const char* value) {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void tbServerMgr::set_ip(const char* value, size_t size) {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* tbServerMgr::mutable_ip() {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  return ip_;
}
inline ::std::string* tbServerMgr::release_ip() {
  clear_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = ip_;
    ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void tbServerMgr::set_allocated_ip(::std::string* ip) {
  if (ip_ != &::google::protobuf::internal::kEmptyString) {
    delete ip_;
  }
  if (ip) {
    set_has_ip();
    ip_ = ip;
  } else {
    clear_has_ip();
    ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string bus_name = 5;
inline bool tbServerMgr::has_bus_name() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void tbServerMgr::set_has_bus_name() {
  _has_bits_[0] |= 0x00000010u;
}
inline void tbServerMgr::clear_has_bus_name() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void tbServerMgr::clear_bus_name() {
  if (bus_name_ != &::google::protobuf::internal::kEmptyString) {
    bus_name_->clear();
  }
  clear_has_bus_name();
}
inline const ::std::string& tbServerMgr::bus_name() const {
  return *bus_name_;
}
inline void tbServerMgr::set_bus_name(const ::std::string& value) {
  set_has_bus_name();
  if (bus_name_ == &::google::protobuf::internal::kEmptyString) {
    bus_name_ = new ::std::string;
  }
  bus_name_->assign(value);
}
inline void tbServerMgr::set_bus_name(const char* value) {
  set_has_bus_name();
  if (bus_name_ == &::google::protobuf::internal::kEmptyString) {
    bus_name_ = new ::std::string;
  }
  bus_name_->assign(value);
}
inline void tbServerMgr::set_bus_name(const char* value, size_t size) {
  set_has_bus_name();
  if (bus_name_ == &::google::protobuf::internal::kEmptyString) {
    bus_name_ = new ::std::string;
  }
  bus_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* tbServerMgr::mutable_bus_name() {
  set_has_bus_name();
  if (bus_name_ == &::google::protobuf::internal::kEmptyString) {
    bus_name_ = new ::std::string;
  }
  return bus_name_;
}
inline ::std::string* tbServerMgr::release_bus_name() {
  clear_has_bus_name();
  if (bus_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = bus_name_;
    bus_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void tbServerMgr::set_allocated_bus_name(::std::string* bus_name) {
  if (bus_name_ != &::google::protobuf::internal::kEmptyString) {
    delete bus_name_;
  }
  if (bus_name) {
    set_has_bus_name();
    bus_name_ = bus_name;
  } else {
    clear_has_bus_name();
    bus_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string server_desc = 6;
inline bool tbServerMgr::has_server_desc() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void tbServerMgr::set_has_server_desc() {
  _has_bits_[0] |= 0x00000020u;
}
inline void tbServerMgr::clear_has_server_desc() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void tbServerMgr::clear_server_desc() {
  if (server_desc_ != &::google::protobuf::internal::kEmptyString) {
    server_desc_->clear();
  }
  clear_has_server_desc();
}
inline const ::std::string& tbServerMgr::server_desc() const {
  return *server_desc_;
}
inline void tbServerMgr::set_server_desc(const ::std::string& value) {
  set_has_server_desc();
  if (server_desc_ == &::google::protobuf::internal::kEmptyString) {
    server_desc_ = new ::std::string;
  }
  server_desc_->assign(value);
}
inline void tbServerMgr::set_server_desc(const char* value) {
  set_has_server_desc();
  if (server_desc_ == &::google::protobuf::internal::kEmptyString) {
    server_desc_ = new ::std::string;
  }
  server_desc_->assign(value);
}
inline void tbServerMgr::set_server_desc(const char* value, size_t size) {
  set_has_server_desc();
  if (server_desc_ == &::google::protobuf::internal::kEmptyString) {
    server_desc_ = new ::std::string;
  }
  server_desc_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* tbServerMgr::mutable_server_desc() {
  set_has_server_desc();
  if (server_desc_ == &::google::protobuf::internal::kEmptyString) {
    server_desc_ = new ::std::string;
  }
  return server_desc_;
}
inline ::std::string* tbServerMgr::release_server_desc() {
  clear_has_server_desc();
  if (server_desc_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = server_desc_;
    server_desc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void tbServerMgr::set_allocated_server_desc(::std::string* server_desc) {
  if (server_desc_ != &::google::protobuf::internal::kEmptyString) {
    delete server_desc_;
  }
  if (server_desc) {
    set_has_server_desc();
    server_desc_ = server_desc;
  } else {
    clear_has_server_desc();
    server_desc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional uint32 cur_count = 7;
inline bool tbServerMgr::has_cur_count() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void tbServerMgr::set_has_cur_count() {
  _has_bits_[0] |= 0x00000040u;
}
inline void tbServerMgr::clear_has_cur_count() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void tbServerMgr::clear_cur_count() {
  cur_count_ = 0u;
  clear_has_cur_count();
}
inline ::google::protobuf::uint32 tbServerMgr::cur_count() const {
  return cur_count_;
}
inline void tbServerMgr::set_cur_count(::google::protobuf::uint32 value) {
  set_has_cur_count();
  cur_count_ = value;
}

// optional uint64 last_login_time = 8;
inline bool tbServerMgr::has_last_login_time() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void tbServerMgr::set_has_last_login_time() {
  _has_bits_[0] |= 0x00000080u;
}
inline void tbServerMgr::clear_has_last_login_time() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void tbServerMgr::clear_last_login_time() {
  last_login_time_ = GOOGLE_ULONGLONG(0);
  clear_has_last_login_time();
}
inline ::google::protobuf::uint64 tbServerMgr::last_login_time() const {
  return last_login_time_;
}
inline void tbServerMgr::set_last_login_time(::google::protobuf::uint64 value) {
  set_has_last_login_time();
  last_login_time_ = value;
}

// optional uint64 last_logout_time = 9;
inline bool tbServerMgr::has_last_logout_time() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void tbServerMgr::set_has_last_logout_time() {
  _has_bits_[0] |= 0x00000100u;
}
inline void tbServerMgr::clear_has_last_logout_time() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void tbServerMgr::clear_last_logout_time() {
  last_logout_time_ = GOOGLE_ULONGLONG(0);
  clear_has_last_logout_time();
}
inline ::google::protobuf::uint64 tbServerMgr::last_logout_time() const {
  return last_logout_time_;
}
inline void tbServerMgr::set_last_logout_time(::google::protobuf::uint64 value) {
  set_has_last_logout_time();
  last_logout_time_ = value;
}

// optional uint64 create_time = 10;
inline bool tbServerMgr::has_create_time() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void tbServerMgr::set_has_create_time() {
  _has_bits_[0] |= 0x00000200u;
}
inline void tbServerMgr::clear_has_create_time() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void tbServerMgr::clear_create_time() {
  create_time_ = GOOGLE_ULONGLONG(0);
  clear_has_create_time();
}
inline ::google::protobuf::uint64 tbServerMgr::create_time() const {
  return create_time_;
}
inline void tbServerMgr::set_create_time(::google::protobuf::uint64 value) {
  set_has_create_time();
  create_time_ = value;
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

#endif  // PROTOBUF_proto_5fcommon_2eproto__INCLUDED
