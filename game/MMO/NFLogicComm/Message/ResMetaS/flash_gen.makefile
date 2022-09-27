include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/flashflash.bin ${GAME_DATA_PATH}/flashitemFlash.bin 

${GAME_DATA_PATH}/flashflash.bin:${PROTOCGEN_FILE_PATH}/flash.proto.ds ${RESDB_EXCELMMO_PATH}/flash.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_flashflash  --excel_sheetname=flash  --proto_msgname=flashflash  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/flashitemFlash.bin:${PROTOCGEN_FILE_PATH}/flash.proto.ds ${RESDB_EXCELMMO_PATH}/flash.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_flashitemFlash  --excel_sheetname=itemFlash  --proto_msgname=flashitemFlash  --start_row=4 --out_path=${GAME_DATA_PATH}/

