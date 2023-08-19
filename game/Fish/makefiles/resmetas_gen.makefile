include ./define.makefile

.PHONY:all

all:${RESDB_DESC_H} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_H} ${RESDB_DESC_STRUCT_CPP}

${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp ${PROTOCGEN_FILE_PATH}/constant.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/constant.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/constant.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --proto_fname=constant.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/Fish.pb.h ${PROTOCGEN_FILE_PATH}/Fish.pb.cc ${PROTOCGEN_FILE_PATH}/Fish_s.h ${PROTOCGEN_FILE_PATH}/Fish_s.cpp ${PROTOCGEN_FILE_PATH}/Fish.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/Fish.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --proto_fname=Fish.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Fish.pb.h ${PROTOCGEN_FILE_PATH}/Fish.pb.cc ${PROTOCGEN_FILE_PATH}/Fish_s.h ${PROTOCGEN_FILE_PATH}/Fish_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
