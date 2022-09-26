include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/arenarobot.bin ${GAME_DATA_PATH}/arenarankaward.bin ${GAME_DATA_PATH}/arenaarenAward.bin ${GAME_DATA_PATH}/arenafirstrank.bin ${GAME_DATA_PATH}/arenabuychallenge.bin 

${GAME_DATA_PATH}/arenarobot.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/arena.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenarobot  --excel_sheetname=robot  --proto_msgname=arenarobot  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/arenarankaward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/arena.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenarankaward  --excel_sheetname=rankaward  --proto_msgname=arenarankaward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/arenaarenAward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/arena.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenaarenAward  --excel_sheetname=arenAward  --proto_msgname=arenaarenAward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/arenafirstrank.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/arena.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenafirstrank  --excel_sheetname=firstrank  --proto_msgname=arenafirstrank  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/arenabuychallenge.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/arena.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenabuychallenge  --excel_sheetname=buychallenge  --proto_msgname=arenabuychallenge  --start_row=4 --out_path=${GAME_DATA_PATH}/

