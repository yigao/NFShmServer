include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/colPointscolPoints.bin ${GAME_DATA_PATH}/colPointstask.bin 

${GAME_DATA_PATH}/colPointscolPoints.bin:${PROTOCGEN_FILE_PATH}/colPoints.proto.ds ${RESDB_EXCELMMO_PATH}/colPoints.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/colPoints.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/colPoints.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_colPointscolPoints  --excel_sheetname=colPoints  --proto_msgname=colPointscolPoints  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/colPointstask.bin:${PROTOCGEN_FILE_PATH}/colPoints.proto.ds ${RESDB_EXCELMMO_PATH}/colPoints.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/colPoints.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/colPoints.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_colPointstask  --excel_sheetname=task  --proto_msgname=colPointstask  --start_row=4 --out_path=${GAME_DATA_PATH}/

