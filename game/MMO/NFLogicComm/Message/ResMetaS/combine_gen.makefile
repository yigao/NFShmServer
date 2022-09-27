include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/combinecitem.bin ${GAME_DATA_PATH}/combinestarUp.bin ${GAME_DATA_PATH}/combineitemUp.bin ${GAME_DATA_PATH}/combinerankUp.bin ${GAME_DATA_PATH}/combinequalityUp.bin 

${GAME_DATA_PATH}/combinecitem.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinecitem  --excel_sheetname=citem  --proto_msgname=combinecitem  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combinestarUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinestarUp  --excel_sheetname=starUp  --proto_msgname=combinestarUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combineitemUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combineitemUp  --excel_sheetname=itemUp  --proto_msgname=combineitemUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combinerankUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinerankUp  --excel_sheetname=rankUp  --proto_msgname=combinerankUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combinequalityUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinequalityUp  --excel_sheetname=qualityUp  --proto_msgname=combinequalityUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

