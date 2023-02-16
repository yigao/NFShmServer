include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MonsterMonster.bin ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.h ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MonsterDisplay.bin ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MonsterValue.bin ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MonsterValueparam.bin ${PROTOCGEN_FILE_PATH}/MonsterValueparamDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueparamDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MonsterDrop.bin ${PROTOCGEN_FILE_PATH}/MonsterDropDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDropDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MonsterMonster.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MonsterMonster  --excel_sheetname=monster  --proto_msgname=E_MonsterMonster  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MonsterMonster.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.h ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MonsterDisplay.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MonsterDisplay  --excel_sheetname=display  --proto_msgname=E_MonsterDisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MonsterDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MonsterValue.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MonsterValue  --excel_sheetname=value  --proto_msgname=E_MonsterValue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MonsterValue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterValueDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MonsterValueparam.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MonsterValueparam  --excel_sheetname=valueParam  --proto_msgname=E_MonsterValueparam  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MonsterValueparam.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterValueparamDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueparamDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MonsterDrop.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MonsterDrop  --excel_sheetname=drop  --proto_msgname=E_MonsterDrop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MonsterDrop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterDropDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDropDesc.cpp" --dst=${DESC_STORE_PATH}/

