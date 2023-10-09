include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_msg_bin

${PROTOCGEN_FILE_PATH}/module_msg_bin:${PROTOCGEN_FILE_PATH}/msg.proto.ds ${RESDB_EXCELMMO_PATH}/msg.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_msg_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/msg.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/msg.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/MsgDescEx.h ${PROTOCGEN_FILE_PATH}/MsgDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MsgPhpmsg.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MsgPhpmsgDesc.h ${PROTOCGEN_FILE_PATH}/MsgPhpmsgDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_msg_bin
