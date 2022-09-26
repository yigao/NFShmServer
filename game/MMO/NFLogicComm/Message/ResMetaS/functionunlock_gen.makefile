include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/functionunlockfunctionUnlock.bin 

${GAME_DATA_PATH}/functionunlockfunctionUnlock.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/functionunlock.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_functionunlockfunctionUnlock  --excel_sheetname=functionUnlock  --proto_msgname=functionunlockfunctionUnlock  --start_row=4 --out_path=${GAME_DATA_PATH}/

