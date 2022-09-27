include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/huoyuedureward.bin ${GAME_DATA_PATH}/huoyueduactive.bin 

${GAME_DATA_PATH}/huoyuedureward.bin:${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds ${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_huoyuedureward  --excel_sheetname=reward  --proto_msgname=huoyuedureward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/huoyueduactive.bin:${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds ${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_huoyueduactive  --excel_sheetname=active  --proto_msgname=huoyueduactive  --start_row=4 --out_path=${GAME_DATA_PATH}/

