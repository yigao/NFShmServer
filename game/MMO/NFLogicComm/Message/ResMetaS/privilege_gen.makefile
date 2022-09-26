include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/privilegeprivilege.bin 

${GAME_DATA_PATH}/privilegeprivilege.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/privilege.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/privilege.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_privilegeprivilege  --excel_sheetname=privilege  --proto_msgname=privilegeprivilege  --start_row=4 --out_path=${GAME_DATA_PATH}/

