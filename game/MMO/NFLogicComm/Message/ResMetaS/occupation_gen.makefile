include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/occupationoccupation.bin ${GAME_DATA_PATH}/occupationaptitude.bin ${GAME_DATA_PATH}/occupationconditionList.bin 

${GAME_DATA_PATH}/occupationoccupation.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_occupationoccupation  --excel_sheetname=occupation  --proto_msgname=occupationoccupation  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/occupationaptitude.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_occupationaptitude  --excel_sheetname=aptitude  --proto_msgname=occupationaptitude  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/occupationconditionList.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_occupationconditionList  --excel_sheetname=conditionList  --proto_msgname=occupationconditionList  --start_row=4 --out_path=${GAME_DATA_PATH}/

