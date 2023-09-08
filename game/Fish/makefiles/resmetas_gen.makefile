include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/constant_proto_finish ${PROTOCGEN_FILE_PATH}/Fish_proto_finish 

${PROTOCGEN_FILE_PATH}/constant_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Constant.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/constant_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/constant.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --src=E_Constant.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Constant.pb.h ${PROTOCGEN_FILE_PATH}/E_Constant.pb.cc ${PROTOCGEN_FILE_PATH}/E_Constant_s.h ${PROTOCGEN_FILE_PATH}/E_Constant_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/constant_proto_finish


${PROTOCGEN_FILE_PATH}/Fish_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Fish.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/Fish_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --src=E_Fish.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Fish.pb.h ${PROTOCGEN_FILE_PATH}/E_Fish.pb.cc ${PROTOCGEN_FILE_PATH}/E_Fish_s.h ${PROTOCGEN_FILE_PATH}/E_Fish_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/Fish_proto_finish


