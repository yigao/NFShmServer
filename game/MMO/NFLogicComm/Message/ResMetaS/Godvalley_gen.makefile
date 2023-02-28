include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_GodvalleyBattle.bin ${PROTOCGEN_FILE_PATH}/GodvalleyBattleDesc.h ${PROTOCGEN_FILE_PATH}/GodvalleyBattleDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_GodvalleyBattle.bin:${PROTOCGEN_FILE_PATH}/Godvalley.proto.ds ${RESDB_EXCELMMO_PATH}/Godvalley.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/Godvalley.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Godvalley.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GodvalleyBattle  --excel_sheetname=Battle  --proto_msgname=E_GodvalleyBattle  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GodvalleyBattle.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodvalleyBattleDesc.h ${PROTOCGEN_FILE_PATH}/GodvalleyBattleDesc.cpp" --dst=${DESC_STORE_PATH}/

