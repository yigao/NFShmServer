include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/backback.bin 

${GAME_DATA_PATH}/backback.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/back.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/back.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_backback  --excel_sheetname=back  --proto_msgname=backback  --start_row=4 --out_path=${GAME_DATA_PATH}/

