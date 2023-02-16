include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_ArenaRobot.bin ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ArenaArenaward.bin ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ArenaRankaward.bin ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ArenaFirstrank.bin ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.h ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ArenaBuychallenge.bin ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_ArenaRobot.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ArenaRobot  --excel_sheetname=robot  --proto_msgname=E_ArenaRobot  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ArenaRobot.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ArenaArenaward.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ArenaArenaward  --excel_sheetname=arenAward  --proto_msgname=E_ArenaArenaward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ArenaArenaward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ArenaRankaward.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ArenaRankaward  --excel_sheetname=rankaward  --proto_msgname=E_ArenaRankaward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ArenaRankaward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ArenaFirstrank.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ArenaFirstrank  --excel_sheetname=firstrank  --proto_msgname=E_ArenaFirstrank  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ArenaFirstrank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.h ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ArenaBuychallenge.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ArenaBuychallenge  --excel_sheetname=buychallenge  --proto_msgname=E_ArenaBuychallenge  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ArenaBuychallenge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.cpp" --dst=${DESC_STORE_PATH}/

