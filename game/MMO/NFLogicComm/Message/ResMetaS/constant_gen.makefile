include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/constantconstant.bin 

${GAME_DATA_PATH}/constantconstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/constant.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/constant.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_constantconstant  --excel_sheetname=constant  --proto_msgname=constantconstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

