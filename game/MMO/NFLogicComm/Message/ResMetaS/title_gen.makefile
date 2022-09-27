include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/titletype.bin ${GAME_DATA_PATH}/titletitle.bin 

${GAME_DATA_PATH}/titletype.bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_titletype  --excel_sheetname=type  --proto_msgname=titletype  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/titletitle.bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_titletitle  --excel_sheetname=title  --proto_msgname=titletitle  --start_row=4 --out_path=${GAME_DATA_PATH}/

