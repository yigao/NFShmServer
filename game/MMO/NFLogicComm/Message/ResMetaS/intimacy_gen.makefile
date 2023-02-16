include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_IntimacyIntimacy.bin ${PROTOCGEN_FILE_PATH}/IntimacyIntimacyDesc.h ${PROTOCGEN_FILE_PATH}/IntimacyIntimacyDesc.cpp ${PROTOCGEN_FILE_PATH}/E_IntimacyGift.bin ${PROTOCGEN_FILE_PATH}/IntimacyGiftDesc.h ${PROTOCGEN_FILE_PATH}/IntimacyGiftDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_IntimacyIntimacy.bin:${PROTOCGEN_FILE_PATH}/intimacy.proto.ds ${RESDB_EXCELMMO_PATH}/intimacy.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/intimacy.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_IntimacyIntimacy  --excel_sheetname=intimacy  --proto_msgname=E_IntimacyIntimacy  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_IntimacyIntimacy.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/IntimacyIntimacyDesc.h ${PROTOCGEN_FILE_PATH}/IntimacyIntimacyDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_IntimacyGift.bin:${PROTOCGEN_FILE_PATH}/intimacy.proto.ds ${RESDB_EXCELMMO_PATH}/intimacy.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/intimacy.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_IntimacyGift  --excel_sheetname=gift  --proto_msgname=E_IntimacyGift  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_IntimacyGift.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/IntimacyGiftDesc.h ${PROTOCGEN_FILE_PATH}/IntimacyGiftDesc.cpp" --dst=${DESC_STORE_PATH}/

