include ./define.makefile
.PHONY:all

all:${ALL_PROTOCGEN_FILE} ${ALL_PROTOC_DESCRIPTOR_FILE}

${PROTOCOL_SS_H} ${PROTOCOL_SS_CPP} ${PROTOCOL_SS_DESCRIPTOR} :${PROTOCOL_SS_XML} ${PROTOCOL_COMM_XML} ${PROTOCOL_FIELD_XML} ${PROTOCOL_KERNEL_XML}
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_PATH}  -I${PROTOCOL_KERNEL_PATH}\
		--cpp_out=${PROTOCGEN_FILE_PATH} --descriptor_set_out=${PROTOCOL_SS_DESCRIPTOR}
	cp ${PROTOCOL_SS_H} ${PROTOCOL_SS_CPP} ${NEW_PROTOCGEN_FILE_PATH} -rf
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCOL_SS_DESCRIPTOR} " --dst=${GAME_LUA_PB_PATH}/


