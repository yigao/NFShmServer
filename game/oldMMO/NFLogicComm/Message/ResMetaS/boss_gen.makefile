include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_BossRareitem.bin ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.h ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.cpp ${PROTOCGEN_FILE_PATH}/E_BossBoss.bin ${PROTOCGEN_FILE_PATH}/BossBossDesc.h ${PROTOCGEN_FILE_PATH}/BossBossDesc.cpp ${PROTOCGEN_FILE_PATH}/E_BossBosstype.bin ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.h ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_BossLayer.bin ${PROTOCGEN_FILE_PATH}/BossLayerDesc.h ${PROTOCGEN_FILE_PATH}/BossLayerDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_BossRareitem.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BossRareitem  --excel_sheetname=rareItem  --proto_msgname=E_BossRareitem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BossRareitem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossRareitemDesc.h ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_BossBoss.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BossBoss  --excel_sheetname=boss  --proto_msgname=E_BossBoss  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BossBoss.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossBossDesc.h ${PROTOCGEN_FILE_PATH}/BossBossDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_BossBosstype.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BossBosstype  --excel_sheetname=bosstype  --proto_msgname=E_BossBosstype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BossBosstype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.h ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_BossLayer.bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BossLayer  --excel_sheetname=layer  --proto_msgname=E_BossLayer  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BossLayer.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BossLayerDesc.h ${PROTOCGEN_FILE_PATH}/BossLayerDesc.cpp" --dst=${DESC_STORE_PATH}/

