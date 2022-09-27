include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/functionunlockfunctionUnlock.bin 

${PROTOCGEN_FILE_PATH}/functionunlockfunctionUnlock.bin:${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds ${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/functionunlock.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_functionunlockfunctionUnlock  --excel_sheetname=functionUnlock  --proto_msgname=functionunlockfunctionUnlock  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/functionunlockfunctionUnlock.bin" --dst=${GAME_DATA_PATH}/
