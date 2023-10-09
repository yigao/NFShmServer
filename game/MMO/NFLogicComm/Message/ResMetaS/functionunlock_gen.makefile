include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_functionunlock_bin

${PROTOCGEN_FILE_PATH}/module_functionunlock_bin:${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds ${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_functionunlock_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/functionunlock.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FunctionunlockDescEx.h ${PROTOCGEN_FILE_PATH}/FunctionunlockDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FunctionunlockFunctionunlock.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FunctionunlockFunctionunlockDesc.h ${PROTOCGEN_FILE_PATH}/FunctionunlockFunctionunlockDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FunctionunlockPreview.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FunctionunlockPreviewDesc.h ${PROTOCGEN_FILE_PATH}/FunctionunlockPreviewDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_functionunlock_bin
