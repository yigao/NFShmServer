include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/headPortraithead.bin ${GAME_DATA_PATH}/headPortraitframe.bin ${GAME_DATA_PATH}/headPortraitbubble.bin 

${GAME_DATA_PATH}/headPortraithead.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraithead  --excel_sheetname=head  --proto_msgname=headPortraithead  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/headPortraitframe.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraitframe  --excel_sheetname=frame  --proto_msgname=headPortraitframe  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/headPortraitbubble.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraitbubble  --excel_sheetname=bubble  --proto_msgname=headPortraitbubble  --start_row=4 --out_path=${GAME_DATA_PATH}/

