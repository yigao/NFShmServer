include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/getTreasurerareItem.bin ${GAME_DATA_PATH}/getTreasuretimesControl.bin ${GAME_DATA_PATH}/getTreasureArrivalBossReward.bin ${GAME_DATA_PATH}/getTreasureArrivalBossControl.bin ${GAME_DATA_PATH}/getTreasurevipBossControl.bin ${GAME_DATA_PATH}/getTreasureboss.bin ${GAME_DATA_PATH}/getTreasurehelp.bin 

${GAME_DATA_PATH}/getTreasurerareItem.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasurerareItem  --excel_sheetname=rareItem  --proto_msgname=getTreasurerareItem  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/getTreasuretimesControl.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasuretimesControl  --excel_sheetname=timesControl  --proto_msgname=getTreasuretimesControl  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/getTreasureArrivalBossReward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasureArrivalBossReward  --excel_sheetname=ArrivalBossReward  --proto_msgname=getTreasureArrivalBossReward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/getTreasureArrivalBossControl.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasureArrivalBossControl  --excel_sheetname=ArrivalBossControl  --proto_msgname=getTreasureArrivalBossControl  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/getTreasurevipBossControl.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasurevipBossControl  --excel_sheetname=vipBossControl  --proto_msgname=getTreasurevipBossControl  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/getTreasureboss.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasureboss  --excel_sheetname=boss  --proto_msgname=getTreasureboss  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/getTreasurehelp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasurehelp  --excel_sheetname=help  --proto_msgname=getTreasurehelp  --start_row=4 --out_path=${GAME_DATA_PATH}/

