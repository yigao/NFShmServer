include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/itemitem.bin 

${GAME_DATA_PATH}/itemitem.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/item.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/item.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_itemitem  --excel_sheetname=item  --proto_msgname=itemitem  --start_row=4 --out_path=${GAME_DATA_PATH}/

