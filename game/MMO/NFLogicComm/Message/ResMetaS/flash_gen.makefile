include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/flashflash.bin ${GAME_DATA_PATH}/flashitemFlash.bin 

${GAME_DATA_PATH}/flashflash.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/flash.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_flashflash  --excel_sheetname=flash  --proto_msgname=flashflash  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/flashitemFlash.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/flash.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_flashitemFlash  --excel_sheetname=itemFlash  --proto_msgname=flashitemFlash  --start_row=4 --out_path=${GAME_DATA_PATH}/

