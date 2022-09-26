include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/boxbox.bin 

${GAME_DATA_PATH}/boxbox.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/box.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/box.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_boxbox  --excel_sheetname=box  --proto_msgname=boxbox  --start_row=4 --out_path=${GAME_DATA_PATH}/

