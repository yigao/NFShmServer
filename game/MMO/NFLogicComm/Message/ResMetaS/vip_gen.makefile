include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/vipvip.bin ${GAME_DATA_PATH}/vipprivilege.bin ${GAME_DATA_PATH}/vipgift.bin 

${GAME_DATA_PATH}/vipvip.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/vip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/vip.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_vipvip  --excel_sheetname=vip  --proto_msgname=vipvip  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/vipprivilege.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/vip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/vip.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_vipprivilege  --excel_sheetname=privilege  --proto_msgname=vipprivilege  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/vipgift.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/vip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/vip.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_vipgift  --excel_sheetname=gift  --proto_msgname=vipgift  --start_row=4 --out_path=${GAME_DATA_PATH}/

