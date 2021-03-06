// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RemotePoint.proto

#ifndef PROTOBUF_RemotePoint_2eproto__INCLUDED
#define PROTOBUF_RemotePoint_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
namespace google {
namespace protobuf {
class PointDPS;
class PointDPSDefaultTypeInternal;
extern PointDPSDefaultTypeInternal _PointDPS_default_instance_;
class PointMV;
class PointMVDefaultTypeInternal;
extern PointMVDefaultTypeInternal _PointMV_default_instance_;
class RemotePoint;
class RemotePointDefaultTypeInternal;
extern RemotePointDefaultTypeInternal _RemotePoint_default_instance_;
}  // namespace protobuf
}  // namespace google

namespace google {
namespace protobuf {

namespace protobuf_RemotePoint_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_RemotePoint_2eproto

enum MessageType {
  MT_INVALID = 0,
  MT_PointDPS = 1,
  MT_PointMV = 2,
  MessageType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MessageType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MessageType_IsValid(int value);
const MessageType MessageType_MIN = MT_INVALID;
const MessageType MessageType_MAX = MT_PointMV;
const int MessageType_ARRAYSIZE = MessageType_MAX + 1;

// ===================================================================

class PointDPS : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:google.protobuf.PointDPS) */ {
 public:
  PointDPS();
  virtual ~PointDPS();

  PointDPS(const PointDPS& from);

  inline PointDPS& operator=(const PointDPS& from) {
    CopyFrom(from);
    return *this;
  }

  static const PointDPS& default_instance();

  static inline const PointDPS* internal_default_instance() {
    return reinterpret_cast<const PointDPS*>(
               &_PointDPS_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(PointDPS* other);

  // implements Message ----------------------------------------------

  inline PointDPS* New() const PROTOBUF_FINAL { return New(NULL); }

  PointDPS* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const PointDPS& from);
  void MergeFrom(const PointDPS& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PointDPS* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string deviceID = 1;
  void clear_deviceid();
  static const int kDeviceIDFieldNumber = 1;
  const ::std::string& deviceid() const;
  void set_deviceid(const ::std::string& value);
  #if LANG_CXX11
  void set_deviceid(::std::string&& value);
  #endif
  void set_deviceid(const char* value);
  void set_deviceid(const char* value, size_t size);
  ::std::string* mutable_deviceid();
  ::std::string* release_deviceid();
  void set_allocated_deviceid(::std::string* deviceid);

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string timestamp = 3;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 3;
  const ::std::string& timestamp() const;
  void set_timestamp(const ::std::string& value);
  #if LANG_CXX11
  void set_timestamp(::std::string&& value);
  #endif
  void set_timestamp(const char* value);
  void set_timestamp(const char* value, size_t size);
  ::std::string* mutable_timestamp();
  ::std::string* release_timestamp();
  void set_allocated_timestamp(::std::string* timestamp);

  // int32 value = 4;
  void clear_value();
  static const int kValueFieldNumber = 4;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:google.protobuf.PointDPS)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr deviceid_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr timestamp_;
  ::google::protobuf::int32 value_;
  mutable int _cached_size_;
  friend struct protobuf_RemotePoint_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PointMV : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:google.protobuf.PointMV) */ {
 public:
  PointMV();
  virtual ~PointMV();

  PointMV(const PointMV& from);

  inline PointMV& operator=(const PointMV& from) {
    CopyFrom(from);
    return *this;
  }

  static const PointMV& default_instance();

  static inline const PointMV* internal_default_instance() {
    return reinterpret_cast<const PointMV*>(
               &_PointMV_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(PointMV* other);

  // implements Message ----------------------------------------------

  inline PointMV* New() const PROTOBUF_FINAL { return New(NULL); }

  PointMV* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const PointMV& from);
  void MergeFrom(const PointMV& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PointMV* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string deviceID = 1;
  void clear_deviceid();
  static const int kDeviceIDFieldNumber = 1;
  const ::std::string& deviceid() const;
  void set_deviceid(const ::std::string& value);
  #if LANG_CXX11
  void set_deviceid(::std::string&& value);
  #endif
  void set_deviceid(const char* value);
  void set_deviceid(const char* value, size_t size);
  ::std::string* mutable_deviceid();
  ::std::string* release_deviceid();
  void set_allocated_deviceid(::std::string* deviceid);

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string timestamp = 3;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 3;
  const ::std::string& timestamp() const;
  void set_timestamp(const ::std::string& value);
  #if LANG_CXX11
  void set_timestamp(::std::string&& value);
  #endif
  void set_timestamp(const char* value);
  void set_timestamp(const char* value, size_t size);
  ::std::string* mutable_timestamp();
  ::std::string* release_timestamp();
  void set_allocated_timestamp(::std::string* timestamp);

  // float value = 4;
  void clear_value();
  static const int kValueFieldNumber = 4;
  float value() const;
  void set_value(float value);

  // @@protoc_insertion_point(class_scope:google.protobuf.PointMV)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr deviceid_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr timestamp_;
  float value_;
  mutable int _cached_size_;
  friend struct protobuf_RemotePoint_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RemotePoint : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:google.protobuf.RemotePoint) */ {
 public:
  RemotePoint();
  virtual ~RemotePoint();

  RemotePoint(const RemotePoint& from);

  inline RemotePoint& operator=(const RemotePoint& from) {
    CopyFrom(from);
    return *this;
  }

  static const RemotePoint& default_instance();

  static inline const RemotePoint* internal_default_instance() {
    return reinterpret_cast<const RemotePoint*>(
               &_RemotePoint_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(RemotePoint* other);

  // implements Message ----------------------------------------------

  inline RemotePoint* New() const PROTOBUF_FINAL { return New(NULL); }

  RemotePoint* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const RemotePoint& from);
  void MergeFrom(const RemotePoint& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(RemotePoint* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .google.protobuf.PointDPS pointDPS = 2;
  bool has_pointdps() const;
  void clear_pointdps();
  static const int kPointDPSFieldNumber = 2;
  const ::google::protobuf::PointDPS& pointdps() const;
  ::google::protobuf::PointDPS* mutable_pointdps();
  ::google::protobuf::PointDPS* release_pointdps();
  void set_allocated_pointdps(::google::protobuf::PointDPS* pointdps);

  // .google.protobuf.PointMV pointMV = 3;
  bool has_pointmv() const;
  void clear_pointmv();
  static const int kPointMVFieldNumber = 3;
  const ::google::protobuf::PointMV& pointmv() const;
  ::google::protobuf::PointMV* mutable_pointmv();
  ::google::protobuf::PointMV* release_pointmv();
  void set_allocated_pointmv(::google::protobuf::PointMV* pointmv);

  // .google.protobuf.MessageType msgType = 1;
  void clear_msgtype();
  static const int kMsgTypeFieldNumber = 1;
  ::google::protobuf::MessageType msgtype() const;
  void set_msgtype(::google::protobuf::MessageType value);

  // @@protoc_insertion_point(class_scope:google.protobuf.RemotePoint)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::PointDPS* pointdps_;
  ::google::protobuf::PointMV* pointmv_;
  int msgtype_;
  mutable int _cached_size_;
  friend struct protobuf_RemotePoint_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// PointDPS

// string deviceID = 1;
inline void PointDPS::clear_deviceid() {
  deviceid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PointDPS::deviceid() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointDPS.deviceID)
  return deviceid_.GetNoArena();
}
inline void PointDPS::set_deviceid(const ::std::string& value) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.PointDPS.deviceID)
}
#if LANG_CXX11
inline void PointDPS::set_deviceid(::std::string&& value) {
  
  deviceid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.PointDPS.deviceID)
}
#endif
inline void PointDPS::set_deviceid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.PointDPS.deviceID)
}
inline void PointDPS::set_deviceid(const char* value, size_t size) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.PointDPS.deviceID)
}
inline ::std::string* PointDPS::mutable_deviceid() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.PointDPS.deviceID)
  return deviceid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PointDPS::release_deviceid() {
  // @@protoc_insertion_point(field_release:google.protobuf.PointDPS.deviceID)
  
  return deviceid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PointDPS::set_allocated_deviceid(::std::string* deviceid) {
  if (deviceid != NULL) {
    
  } else {
    
  }
  deviceid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), deviceid);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.PointDPS.deviceID)
}

// string name = 2;
inline void PointDPS::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PointDPS::name() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointDPS.name)
  return name_.GetNoArena();
}
inline void PointDPS::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.PointDPS.name)
}
#if LANG_CXX11
inline void PointDPS::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.PointDPS.name)
}
#endif
inline void PointDPS::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.PointDPS.name)
}
inline void PointDPS::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.PointDPS.name)
}
inline ::std::string* PointDPS::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.PointDPS.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PointDPS::release_name() {
  // @@protoc_insertion_point(field_release:google.protobuf.PointDPS.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PointDPS::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.PointDPS.name)
}

// string timestamp = 3;
inline void PointDPS::clear_timestamp() {
  timestamp_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PointDPS::timestamp() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointDPS.timestamp)
  return timestamp_.GetNoArena();
}
inline void PointDPS::set_timestamp(const ::std::string& value) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.PointDPS.timestamp)
}
#if LANG_CXX11
inline void PointDPS::set_timestamp(::std::string&& value) {
  
  timestamp_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.PointDPS.timestamp)
}
#endif
inline void PointDPS::set_timestamp(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.PointDPS.timestamp)
}
inline void PointDPS::set_timestamp(const char* value, size_t size) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.PointDPS.timestamp)
}
inline ::std::string* PointDPS::mutable_timestamp() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.PointDPS.timestamp)
  return timestamp_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PointDPS::release_timestamp() {
  // @@protoc_insertion_point(field_release:google.protobuf.PointDPS.timestamp)
  
  return timestamp_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PointDPS::set_allocated_timestamp(::std::string* timestamp) {
  if (timestamp != NULL) {
    
  } else {
    
  }
  timestamp_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), timestamp);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.PointDPS.timestamp)
}

// int32 value = 4;
inline void PointDPS::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 PointDPS::value() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointDPS.value)
  return value_;
}
inline void PointDPS::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.PointDPS.value)
}

// -------------------------------------------------------------------

// PointMV

// string deviceID = 1;
inline void PointMV::clear_deviceid() {
  deviceid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PointMV::deviceid() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointMV.deviceID)
  return deviceid_.GetNoArena();
}
inline void PointMV::set_deviceid(const ::std::string& value) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.PointMV.deviceID)
}
#if LANG_CXX11
inline void PointMV::set_deviceid(::std::string&& value) {
  
  deviceid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.PointMV.deviceID)
}
#endif
inline void PointMV::set_deviceid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.PointMV.deviceID)
}
inline void PointMV::set_deviceid(const char* value, size_t size) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.PointMV.deviceID)
}
inline ::std::string* PointMV::mutable_deviceid() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.PointMV.deviceID)
  return deviceid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PointMV::release_deviceid() {
  // @@protoc_insertion_point(field_release:google.protobuf.PointMV.deviceID)
  
  return deviceid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PointMV::set_allocated_deviceid(::std::string* deviceid) {
  if (deviceid != NULL) {
    
  } else {
    
  }
  deviceid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), deviceid);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.PointMV.deviceID)
}

// string name = 2;
inline void PointMV::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PointMV::name() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointMV.name)
  return name_.GetNoArena();
}
inline void PointMV::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.PointMV.name)
}
#if LANG_CXX11
inline void PointMV::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.PointMV.name)
}
#endif
inline void PointMV::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.PointMV.name)
}
inline void PointMV::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.PointMV.name)
}
inline ::std::string* PointMV::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.PointMV.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PointMV::release_name() {
  // @@protoc_insertion_point(field_release:google.protobuf.PointMV.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PointMV::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.PointMV.name)
}

// string timestamp = 3;
inline void PointMV::clear_timestamp() {
  timestamp_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PointMV::timestamp() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointMV.timestamp)
  return timestamp_.GetNoArena();
}
inline void PointMV::set_timestamp(const ::std::string& value) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.PointMV.timestamp)
}
#if LANG_CXX11
inline void PointMV::set_timestamp(::std::string&& value) {
  
  timestamp_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.PointMV.timestamp)
}
#endif
inline void PointMV::set_timestamp(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.PointMV.timestamp)
}
inline void PointMV::set_timestamp(const char* value, size_t size) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.PointMV.timestamp)
}
inline ::std::string* PointMV::mutable_timestamp() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.PointMV.timestamp)
  return timestamp_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PointMV::release_timestamp() {
  // @@protoc_insertion_point(field_release:google.protobuf.PointMV.timestamp)
  
  return timestamp_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PointMV::set_allocated_timestamp(::std::string* timestamp) {
  if (timestamp != NULL) {
    
  } else {
    
  }
  timestamp_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), timestamp);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.PointMV.timestamp)
}

// float value = 4;
inline void PointMV::clear_value() {
  value_ = 0;
}
inline float PointMV::value() const {
  // @@protoc_insertion_point(field_get:google.protobuf.PointMV.value)
  return value_;
}
inline void PointMV::set_value(float value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.PointMV.value)
}

// -------------------------------------------------------------------

// RemotePoint

// .google.protobuf.MessageType msgType = 1;
inline void RemotePoint::clear_msgtype() {
  msgtype_ = 0;
}
inline ::google::protobuf::MessageType RemotePoint::msgtype() const {
  // @@protoc_insertion_point(field_get:google.protobuf.RemotePoint.msgType)
  return static_cast< ::google::protobuf::MessageType >(msgtype_);
}
inline void RemotePoint::set_msgtype(::google::protobuf::MessageType value) {
  
  msgtype_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.RemotePoint.msgType)
}

// .google.protobuf.PointDPS pointDPS = 2;
inline bool RemotePoint::has_pointdps() const {
  return this != internal_default_instance() && pointdps_ != NULL;
}
inline void RemotePoint::clear_pointdps() {
  if (GetArenaNoVirtual() == NULL && pointdps_ != NULL) delete pointdps_;
  pointdps_ = NULL;
}
inline const ::google::protobuf::PointDPS& RemotePoint::pointdps() const {
  // @@protoc_insertion_point(field_get:google.protobuf.RemotePoint.pointDPS)
  return pointdps_ != NULL ? *pointdps_
                         : *::google::protobuf::PointDPS::internal_default_instance();
}
inline ::google::protobuf::PointDPS* RemotePoint::mutable_pointdps() {
  
  if (pointdps_ == NULL) {
    pointdps_ = new ::google::protobuf::PointDPS;
  }
  // @@protoc_insertion_point(field_mutable:google.protobuf.RemotePoint.pointDPS)
  return pointdps_;
}
inline ::google::protobuf::PointDPS* RemotePoint::release_pointdps() {
  // @@protoc_insertion_point(field_release:google.protobuf.RemotePoint.pointDPS)
  
  ::google::protobuf::PointDPS* temp = pointdps_;
  pointdps_ = NULL;
  return temp;
}
inline void RemotePoint::set_allocated_pointdps(::google::protobuf::PointDPS* pointdps) {
  delete pointdps_;
  pointdps_ = pointdps;
  if (pointdps) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.RemotePoint.pointDPS)
}

// .google.protobuf.PointMV pointMV = 3;
inline bool RemotePoint::has_pointmv() const {
  return this != internal_default_instance() && pointmv_ != NULL;
}
inline void RemotePoint::clear_pointmv() {
  if (GetArenaNoVirtual() == NULL && pointmv_ != NULL) delete pointmv_;
  pointmv_ = NULL;
}
inline const ::google::protobuf::PointMV& RemotePoint::pointmv() const {
  // @@protoc_insertion_point(field_get:google.protobuf.RemotePoint.pointMV)
  return pointmv_ != NULL ? *pointmv_
                         : *::google::protobuf::PointMV::internal_default_instance();
}
inline ::google::protobuf::PointMV* RemotePoint::mutable_pointmv() {
  
  if (pointmv_ == NULL) {
    pointmv_ = new ::google::protobuf::PointMV;
  }
  // @@protoc_insertion_point(field_mutable:google.protobuf.RemotePoint.pointMV)
  return pointmv_;
}
inline ::google::protobuf::PointMV* RemotePoint::release_pointmv() {
  // @@protoc_insertion_point(field_release:google.protobuf.RemotePoint.pointMV)
  
  ::google::protobuf::PointMV* temp = pointmv_;
  pointmv_ = NULL;
  return temp;
}
inline void RemotePoint::set_allocated_pointmv(::google::protobuf::PointMV* pointmv) {
  delete pointmv_;
  pointmv_ = pointmv;
  if (pointmv) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.RemotePoint.pointMV)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace protobuf
}  // namespace google

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::google::protobuf::MessageType> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_RemotePoint_2eproto__INCLUDED
