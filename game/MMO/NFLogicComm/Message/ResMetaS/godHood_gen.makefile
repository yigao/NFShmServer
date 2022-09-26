include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/godHoodgodHood.bin ${GAME_DATA_PATH}/godHoodexp.bin 

${GAME_DATA_PATH}/godHoodgodHood.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/godHood.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godHood.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godHoodgodHood  --excel_sheetname=godHood  --proto_msgname=godHoodgodHood  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/godHoodexp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/godHood.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godHood.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godHoodexp  --excel_sheetname=exp  --proto_msgname=godHoodexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

