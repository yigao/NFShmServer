include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/wingwing.bin ${GAME_DATA_PATH}/wingchange.bin ${GAME_DATA_PATH}/wingfragment.bin ${GAME_DATA_PATH}/wingstarUp.bin 

${GAME_DATA_PATH}/wingwing.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/wing.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingwing  --excel_sheetname=wing  --proto_msgname=wingwing  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/wingchange.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/wing.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingchange  --excel_sheetname=change  --proto_msgname=wingchange  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/wingfragment.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/wing.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingfragment  --excel_sheetname=fragment  --proto_msgname=wingfragment  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/wingstarUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/wing.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingstarUp  --excel_sheetname=starUp  --proto_msgname=wingstarUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

