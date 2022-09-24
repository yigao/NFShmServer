include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/colPointscolPoints.bin ${GAME_DATA_PATH}/colPointstask.bin 

${GAME_DATA_PATH}/colPointscolPoints.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCEL_PATH}/colPoints.xlsx
	${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/colPoints.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_colPointscolPoints  --excel_sheetname=colPoints  --proto_msgname=colPointscolPoints  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/colPointstask.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCEL_PATH}/colPoints.xlsx
	${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/colPoints.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_colPointstask  --excel_sheetname=task  --proto_msgname=colPointstask  --start_row=4 --out_path=${GAME_DATA_PATH}/

