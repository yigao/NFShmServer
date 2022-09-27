include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/areaarea.bin ${GAME_DATA_PATH}/areapath.bin 

${GAME_DATA_PATH}/areaarea.bin:${PROTOCGEN_FILE_PATH}/area.proto.ds ${RESDB_EXCELMMO_PATH}/area.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/area.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_areaarea  --excel_sheetname=area  --proto_msgname=areaarea  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/areapath.bin:${PROTOCGEN_FILE_PATH}/area.proto.ds ${RESDB_EXCELMMO_PATH}/area.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/area.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_areapath  --excel_sheetname=path  --proto_msgname=areapath  --start_row=4 --out_path=${GAME_DATA_PATH}/

