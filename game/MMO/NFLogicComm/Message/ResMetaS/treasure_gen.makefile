include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/treasuretreasure.bin ${GAME_DATA_PATH}/treasurechange.bin ${GAME_DATA_PATH}/treasurestarUp.bin ${GAME_DATA_PATH}/treasurefragment.bin ${GAME_DATA_PATH}/treasureequip.bin ${GAME_DATA_PATH}/treasureslot.bin ${GAME_DATA_PATH}/treasurerefine.bin 

${GAME_DATA_PATH}/treasuretreasure.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasuretreasure  --excel_sheetname=treasure  --proto_msgname=treasuretreasure  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/treasurechange.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurechange  --excel_sheetname=change  --proto_msgname=treasurechange  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/treasurestarUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurestarUp  --excel_sheetname=starUp  --proto_msgname=treasurestarUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/treasurefragment.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurefragment  --excel_sheetname=fragment  --proto_msgname=treasurefragment  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/treasureequip.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasureequip  --excel_sheetname=equip  --proto_msgname=treasureequip  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/treasureslot.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasureslot  --excel_sheetname=slot  --proto_msgname=treasureslot  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/treasurerefine.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurerefine  --excel_sheetname=refine  --proto_msgname=treasurerefine  --start_row=4 --out_path=${GAME_DATA_PATH}/

