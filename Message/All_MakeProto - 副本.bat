set OutDir="..\src\NFComm\NFMessageDefine"
  
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr common/proto_common.proto --include_imports --descriptor_set_out=%OutDir%/proto_common.proto.ds
python ../tools/proto_2_struct/proto2struct.py --proto_ds=%OutDir%/proto_common.proto.ds --proto_fname=proto_common.proto --out_path=%OutDir%/

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  common/yd_fieldoptions.proto

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  common/proto_event.proto

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_client2access.proto
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs.proto
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_cmd.proto


protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_svr/proto_svr_common.proto
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  ResMetaS/ResMeta.proto --include_imports --descriptor_set_out=%OutDir%/ResMeta.proto.ds


pause
