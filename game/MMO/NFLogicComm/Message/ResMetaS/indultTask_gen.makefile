include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/indultTaskindultTask.bin ${GAME_DATA_PATH}/indultTasktask.bin 

${GAME_DATA_PATH}/indultTaskindultTask.bin:${PROTOCGEN_FILE_PATH}/indultTask.proto.ds ${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/indultTask.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/indultTask.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_indultTaskindultTask  --excel_sheetname=indultTask  --proto_msgname=indultTaskindultTask  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/indultTasktask.bin:${PROTOCGEN_FILE_PATH}/indultTask.proto.ds ${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/indultTask.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/indultTask.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_indultTasktask  --excel_sheetname=task  --proto_msgname=indultTasktask  --start_row=4 --out_path=${GAME_DATA_PATH}/

