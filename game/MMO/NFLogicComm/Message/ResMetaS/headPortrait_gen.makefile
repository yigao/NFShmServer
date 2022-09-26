include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/headPortraithead.bin ${GAME_DATA_PATH}/headPortraitframe.bin ${GAME_DATA_PATH}/headPortraitbubble.bin 

${GAME_DATA_PATH}/headPortraithead.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraithead  --excel_sheetname=head  --proto_msgname=headPortraithead  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/headPortraitframe.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraitframe  --excel_sheetname=frame  --proto_msgname=headPortraitframe  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/headPortraitbubble.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraitbubble  --excel_sheetname=bubble  --proto_msgname=headPortraitbubble  --start_row=4 --out_path=${GAME_DATA_PATH}/

