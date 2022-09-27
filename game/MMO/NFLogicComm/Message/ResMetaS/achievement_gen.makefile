include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/achievementachievement.bin ${PROTOCGEN_FILE_PATH}/achievementachievementreward.bin 

${PROTOCGEN_FILE_PATH}/achievementachievement.bin:${PROTOCGEN_FILE_PATH}/achievement.proto.ds ${RESDB_EXCELMMO_PATH}/achievement.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/achievement.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_achievementachievement  --excel_sheetname=achievement  --proto_msgname=achievementachievement  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/achievementachievement.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/achievementachievementreward.bin:${PROTOCGEN_FILE_PATH}/achievement.proto.ds ${RESDB_EXCELMMO_PATH}/achievement.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/achievement.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_achievementachievementreward  --excel_sheetname=achievementreward  --proto_msgname=achievementachievementreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/achievementachievementreward.bin" --dst=${GAME_DATA_PATH}/
