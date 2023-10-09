include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_assist_bin

${PROTOCGEN_FILE_PATH}/module_assist_bin:${PROTOCGEN_FILE_PATH}/assist.proto.ds ${RESDB_EXCELMMO_PATH}/assist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_assist_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/assist.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/assist.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AssistDescEx.h ${PROTOCGEN_FILE_PATH}/AssistDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AssistBox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AssistBoxDesc.h ${PROTOCGEN_FILE_PATH}/AssistBoxDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AssistThank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AssistThankDesc.h ${PROTOCGEN_FILE_PATH}/AssistThankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AssistConst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AssistConstDesc.h ${PROTOCGEN_FILE_PATH}/AssistConstDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_assist_bin
