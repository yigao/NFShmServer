include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/closetestActivity.bin ${GAME_DATA_PATH}/closetestRebate.bin 

${GAME_DATA_PATH}/closetestActivity.bin:${PROTOCGEN_FILE_PATH}/closetest.proto.ds ${RESDB_EXCELMMO_PATH}/closetest.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/closetest.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/closetest.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_closetestActivity  --excel_sheetname=Activity  --proto_msgname=closetestActivity  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/closetestRebate.bin:${PROTOCGEN_FILE_PATH}/closetest.proto.ds ${RESDB_EXCELMMO_PATH}/closetest.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/closetest.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/closetest.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_closetestRebate  --excel_sheetname=Rebate  --proto_msgname=closetestRebate  --start_row=4 --out_path=${GAME_DATA_PATH}/

