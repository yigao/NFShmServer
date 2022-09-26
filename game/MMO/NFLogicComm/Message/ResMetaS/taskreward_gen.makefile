include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/taskrewardtaskreward.bin 

${GAME_DATA_PATH}/taskrewardtaskreward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/taskreward.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskreward.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskrewardtaskreward  --excel_sheetname=taskreward  --proto_msgname=taskrewardtaskreward  --start_row=4 --out_path=${GAME_DATA_PATH}/

