include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/bossrareItem.bin ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.h ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.cpp ${PROTOCGEN_FILE_PATH}/bossboss.bin ${PROTOCGEN_FILE_PATH}/BossBossDesc.h ${PROTOCGEN_FILE_PATH}/BossBossDesc.cpp ${PROTOCGEN_FILE_PATH}/bossbosstype.bin ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.h ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.cpp ${PROTOCGEN_FILE_PATH}/bosslayer.bin ${PROTOCGEN_FILE_PATH}/BossLayerDesc.h ${PROTOCGEN_FILE_PATH}/BossLayerDesc.cpp 

${PROTOCGEN_FILE_PATH}/bossrareItem.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_bossrareItem  --excel_sheetname=rareItem  --proto_msgname=bossrareItem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/bossrareItem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossRareitemDesc.h ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/bossboss.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_bossboss  --excel_sheetname=boss  --proto_msgname=bossboss  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/bossboss.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossBossDesc.h ${PROTOCGEN_FILE_PATH}/BossBossDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/bossbosstype.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_bossbosstype  --excel_sheetname=bosstype  --proto_msgname=bossbosstype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/bossbosstype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.h ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/bosslayer.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_bosslayer  --excel_sheetname=layer  --proto_msgname=bosslayer  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/bosslayer.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossLayerDesc.h ${PROTOCGEN_FILE_PATH}/BossLayerDesc.cpp" --dst=${DESC_STORE_PATH}/

