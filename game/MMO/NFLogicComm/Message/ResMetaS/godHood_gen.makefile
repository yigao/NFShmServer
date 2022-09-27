include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/godHoodgodHood.bin ${GAME_DATA_PATH}/godHoodexp.bin 

${GAME_DATA_PATH}/godHoodgodHood.bin:${PROTOCGEN_FILE_PATH}/godHood.proto.ds ${RESDB_EXCELMMO_PATH}/godHood.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godHood.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godHood.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godHoodgodHood  --excel_sheetname=godHood  --proto_msgname=godHoodgodHood  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/godHoodexp.bin:${PROTOCGEN_FILE_PATH}/godHood.proto.ds ${RESDB_EXCELMMO_PATH}/godHood.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godHood.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godHood.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godHoodexp  --excel_sheetname=exp  --proto_msgname=godHoodexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

