set OutDir="..\src\NFComm\NFMessageDefine"
set OutDir2="..\src\NFGameLogic\NFFishMessage"
  
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr common/proto_common.proto --include_imports --descriptor_set_out=%OutDir%/proto_common.proto.ds
python ../tools/proto_2_struct/proto2struct.py --proto_ds=%OutDir%/proto_common.proto.ds --proto_fname=proto_common.proto --out_path=%OutDir%/

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  common/yd_fieldoptions.proto

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_client2access.proto
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs.proto
protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_cmd.proto

protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon  -Iproto_cs/proto_cs_extend -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_extend/msg_fafafa.proto
protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon  -Iproto_cs/proto_cs_extend -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_extend/msg_link.proto
protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon  -Iproto_cs/proto_cs_extend -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_extend/proto_room.proto
protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon  -Iproto_cs/proto_cs_extend -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_extend/msg_fish.proto
protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon  -Iproto_cs/proto_cs_extend -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_extend/msg_yqs.proto
protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon -Iproto_cs/proto_cs_extend -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_cs/proto_cs_extend/st_yqs.proto

protoc.exe -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr proto_cs/proto_cs_extend/msg_fafafa.proto proto_cs/proto_cs_extend/msg_link.proto proto_cs/proto_cs_extend/proto_room.proto proto_cs/proto_cs_extend/msg_fish.proto --include_imports --descriptor_set_out=%OutDir%/proto_cs_extend.proto.ds
python ../tools/proto_2_struct/proto2struct.py --proto_ds=%OutDir2%/proto_cs_extend.proto.ds --proto_fname=msg_fish.proto --out_path=%OutDir2%/

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  proto_svr/proto_svr_common.proto

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  ResMetaS/ResMeta.proto --include_imports --descriptor_set_out=%OutDir%/ResMeta.proto.ds
python ../tools/proto_2_struct/proto2struct.py --proto_ds=%OutDir%/ResMeta.proto.ds --proto_fname=ResMeta.proto --out_path=%OutDir%/

protoc.exe --cpp_out=%OutDir2% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  ResMetaS/FishResMeta.proto --include_imports --descriptor_set_out=%OutDir2%/FishResMeta.proto.ds
python ../tools/proto_2_struct/proto2struct.py --proto_ds=%OutDir2%/FishResMeta.proto.ds --proto_fname=FishResMeta.proto --out_path=%OutDir2%/

protoc.exe --cpp_out=%OutDir% -I../thirdparty -Icommon -Iproto_cs -Iproto_svr -IResMetaS -Istoresvr  storesvr/storesvr_sqldata.proto

pause
