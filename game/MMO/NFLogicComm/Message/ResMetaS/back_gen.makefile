include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/backback.bin 

${GAME_DATA_PATH}/backback.bin:${PROTOCGEN_FILE_PATH}/back.proto.ds ${RESDB_EXCELMMO_PATH}/back.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/back.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/back.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_backback  --excel_sheetname=back  --proto_msgname=backback  --start_row=4 --out_path=${GAME_DATA_PATH}/

