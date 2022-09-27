include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/monstermonster.bin ${GAME_DATA_PATH}/monsterdisplay.bin ${GAME_DATA_PATH}/monstervalue.bin 

${GAME_DATA_PATH}/monstermonster.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_monstermonster  --excel_sheetname=monster  --proto_msgname=monstermonster  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/monsterdisplay.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_monsterdisplay  --excel_sheetname=display  --proto_msgname=monsterdisplay  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/monstervalue.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_monstervalue  --excel_sheetname=value  --proto_msgname=monstervalue  --start_row=4 --out_path=${GAME_DATA_PATH}/

