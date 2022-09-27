include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/monstermonster.bin ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.h ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.cpp ${PROTOCGEN_FILE_PATH}/monsterdisplay.bin ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/monstervalue.bin ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.cpp 

${PROTOCGEN_FILE_PATH}/monstermonster.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_monstermonster  --excel_sheetname=monster  --proto_msgname=monstermonster  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monstermonster.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.h ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.cpp:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.h ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/monsterdisplay.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_monsterdisplay  --excel_sheetname=display  --proto_msgname=monsterdisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monsterdisplay.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.cpp:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/monstervalue.bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_monstervalue  --excel_sheetname=value  --proto_msgname=monstervalue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monstervalue.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/MonsterValueDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.cpp:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MonsterValueDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.cpp" --dst=${DESC_STORE_PATH}/

