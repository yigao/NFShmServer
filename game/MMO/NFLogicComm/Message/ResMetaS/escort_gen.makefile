include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_EscortEscort.bin ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.h ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EscortChance.bin ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.h ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EscortReward.bin ${PROTOCGEN_FILE_PATH}/EscortRewardDesc.h ${PROTOCGEN_FILE_PATH}/EscortRewardDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EscortConst.bin ${PROTOCGEN_FILE_PATH}/EscortConstDesc.h ${PROTOCGEN_FILE_PATH}/EscortConstDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_EscortEscort.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EscortEscort  --excel_sheetname=escort  --proto_msgname=E_EscortEscort  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EscortEscort.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortEscortDesc.h ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EscortChance.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EscortChance  --excel_sheetname=chance  --proto_msgname=E_EscortChance  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EscortChance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortChanceDesc.h ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EscortReward.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EscortReward  --excel_sheetname=reward  --proto_msgname=E_EscortReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EscortReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortRewardDesc.h ${PROTOCGEN_FILE_PATH}/EscortRewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EscortConst.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EscortConst  --excel_sheetname=const  --proto_msgname=E_EscortConst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EscortConst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortConstDesc.h ${PROTOCGEN_FILE_PATH}/EscortConstDesc.cpp" --dst=${DESC_STORE_PATH}/

