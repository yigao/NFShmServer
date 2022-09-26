include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/worldmapbossworldboss.bin ${GAME_DATA_PATH}/worldmapbossdroplist.bin ${GAME_DATA_PATH}/worldmapbossfestival.bin 

${GAME_DATA_PATH}/worldmapbossworldboss.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_worldmapbossworldboss  --excel_sheetname=worldboss  --proto_msgname=worldmapbossworldboss  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/worldmapbossdroplist.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_worldmapbossdroplist  --excel_sheetname=droplist  --proto_msgname=worldmapbossdroplist  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/worldmapbossfestival.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_worldmapbossfestival  --excel_sheetname=festival  --proto_msgname=worldmapbossfestival  --start_row=4 --out_path=${GAME_DATA_PATH}/

