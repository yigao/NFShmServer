include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/achievementachievement.bin ${GAME_DATA_PATH}/achievementachievementreward.bin 

${GAME_DATA_PATH}/achievementachievement.bin:${PROTOCGEN_FILE_PATH}/achievement.proto.ds ${RESDB_EXCELMMO_PATH}/achievement.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/achievement.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_achievementachievement  --excel_sheetname=achievement  --proto_msgname=achievementachievement  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/achievementachievementreward.bin:${PROTOCGEN_FILE_PATH}/achievement.proto.ds ${RESDB_EXCELMMO_PATH}/achievement.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/achievement.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_achievementachievementreward  --excel_sheetname=achievementreward  --proto_msgname=achievementachievementreward  --start_row=4 --out_path=${GAME_DATA_PATH}/

