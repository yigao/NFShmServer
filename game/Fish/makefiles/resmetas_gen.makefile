include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/constant_proto_finish ${PROTOCGEN_FILE_PATH}/Fish_proto_finish 

${PROTOCGEN_FILE_PATH}/constant_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/constant.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/constant_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/constant.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --src=constant.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/constant_proto_finish


${PROTOCGEN_FILE_PATH}/Fish_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/Fish.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/Fish_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --src=Fish.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Fish.pb.h ${PROTOCGEN_FILE_PATH}/Fish.pb.cc ${PROTOCGEN_FILE_PATH}/Fish_s.h ${PROTOCGEN_FILE_PATH}/Fish_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/Fish_proto_finish


