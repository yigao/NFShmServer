include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_FunctionunlockFunctionunlock.bin ${PROTOCGEN_FILE_PATH}/FunctionunlockFunctionunlockDesc.h ${PROTOCGEN_FILE_PATH}/FunctionunlockFunctionunlockDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FunctionunlockPreview.bin ${PROTOCGEN_FILE_PATH}/FunctionunlockPreviewDesc.h ${PROTOCGEN_FILE_PATH}/FunctionunlockPreviewDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_FunctionunlockFunctionunlock.bin:${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds ${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/functionunlock.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FunctionunlockFunctionunlock  --excel_sheetname=functionUnlock  --proto_msgname=E_FunctionunlockFunctionunlock  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FunctionunlockFunctionunlock.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FunctionunlockFunctionunlockDesc.h ${PROTOCGEN_FILE_PATH}/FunctionunlockFunctionunlockDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FunctionunlockPreview.bin:${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds ${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/functionunlock.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FunctionunlockPreview  --excel_sheetname=preview  --proto_msgname=E_FunctionunlockPreview  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FunctionunlockPreview.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FunctionunlockPreviewDesc.h ${PROTOCGEN_FILE_PATH}/FunctionunlockPreviewDesc.cpp" --dst=${DESC_STORE_PATH}/

