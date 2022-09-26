include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/combinecitem.bin ${GAME_DATA_PATH}/combinestarUp.bin ${GAME_DATA_PATH}/combineitemUp.bin ${GAME_DATA_PATH}/combinerankUp.bin ${GAME_DATA_PATH}/combinequalityUp.bin 

${GAME_DATA_PATH}/combinecitem.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinecitem  --excel_sheetname=citem  --proto_msgname=combinecitem  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combinestarUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinestarUp  --excel_sheetname=starUp  --proto_msgname=combinestarUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combineitemUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combineitemUp  --excel_sheetname=itemUp  --proto_msgname=combineitemUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combinerankUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinerankUp  --excel_sheetname=rankUp  --proto_msgname=combinerankUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/combinequalityUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/combine.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinequalityUp  --excel_sheetname=qualityUp  --proto_msgname=combinequalityUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

