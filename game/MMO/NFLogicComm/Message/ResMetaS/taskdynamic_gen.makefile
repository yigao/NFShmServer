include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/taskdynamictaskdynamic.bin ${GAME_DATA_PATH}/taskdynamictaskcomcond.bin ${GAME_DATA_PATH}/taskdynamictasktext.bin 

${GAME_DATA_PATH}/taskdynamictaskdynamic.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskdynamictaskdynamic  --excel_sheetname=taskdynamic  --proto_msgname=taskdynamictaskdynamic  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/taskdynamictaskcomcond.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskdynamictaskcomcond  --excel_sheetname=taskcomcond  --proto_msgname=taskdynamictaskcomcond  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/taskdynamictasktext.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskdynamictasktext  --excel_sheetname=tasktext  --proto_msgname=taskdynamictasktext  --start_row=4 --out_path=${GAME_DATA_PATH}/

