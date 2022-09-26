include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/dragonWorldWarconstants.bin ${GAME_DATA_PATH}/dragonWorldWargoldskill.bin ${GAME_DATA_PATH}/dragonWorldWargoldShop.bin 

${GAME_DATA_PATH}/dragonWorldWarconstants.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dragonWorldWarconstants  --excel_sheetname=constants  --proto_msgname=dragonWorldWarconstants  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/dragonWorldWargoldskill.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dragonWorldWargoldskill  --excel_sheetname=goldskill  --proto_msgname=dragonWorldWargoldskill  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/dragonWorldWargoldShop.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dragonWorldWargoldShop  --excel_sheetname=goldShop  --proto_msgname=dragonWorldWargoldShop  --start_row=4 --out_path=${GAME_DATA_PATH}/

