include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/escortescort.bin ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.h ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.cpp ${PROTOCGEN_FILE_PATH}/escortchance.bin ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.h ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.cpp ${PROTOCGEN_FILE_PATH}/escortrewardExp.bin ${PROTOCGEN_FILE_PATH}/EscortRewardexpDesc.h ${PROTOCGEN_FILE_PATH}/EscortRewardexpDesc.cpp 

${PROTOCGEN_FILE_PATH}/escortescort.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_escortescort  --excel_sheetname=escort  --proto_msgname=escortescort  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/escortescort.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EscortEscortDesc.h ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.cpp:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortEscortDesc.h ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/escortchance.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_escortchance  --excel_sheetname=chance  --proto_msgname=escortchance  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/escortchance.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EscortChanceDesc.h ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.cpp:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortChanceDesc.h ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/escortrewardExp.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_escortrewardExp  --excel_sheetname=rewardExp  --proto_msgname=escortrewardExp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/escortrewardExp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EscortRewardexpDesc.h ${PROTOCGEN_FILE_PATH}/EscortRewardexpDesc.cpp:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EscortRewardexpDesc.h ${PROTOCGEN_FILE_PATH}/EscortRewardexpDesc.cpp" --dst=${DESC_STORE_PATH}/

