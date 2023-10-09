include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_ai_bin

${PROTOCGEN_FILE_PATH}/module_ai_bin:${PROTOCGEN_FILE_PATH}/ai.proto.ds ${RESDB_EXCELMMO_PATH}/ai.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_ai_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/ai.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AiDescEx.h ${PROTOCGEN_FILE_PATH}/AiDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AiAi.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AiAiDesc.h ${PROTOCGEN_FILE_PATH}/AiAiDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_ai_bin
