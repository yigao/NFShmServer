include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_GMCommand_bin

${PROTOCGEN_FILE_PATH}/module_GMCommand_bin:${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds ${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_GMCommand_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/GMCommand.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/GmcommandDescEx.h ${PROTOCGEN_FILE_PATH}/GmcommandDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GmcommandGmcommand.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.h ${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_GMCommand_bin
