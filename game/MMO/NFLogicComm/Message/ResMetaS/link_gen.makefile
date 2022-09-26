include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/linklink.bin 

${GAME_DATA_PATH}/linklink.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/link.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/link.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_linklink  --excel_sheetname=link  --proto_msgname=linklink  --start_row=4 --out_path=${GAME_DATA_PATH}/

