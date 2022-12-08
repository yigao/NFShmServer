include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/perActivityperActivity.bin ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.cpp ${PROTOCGEN_FILE_PATH}/perActivityweek.bin ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.cpp 

${PROTOCGEN_FILE_PATH}/perActivityperActivity.bin:${PROTOCGEN_FILE_PATH}/perActivity.proto.ds ${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/perActivity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_perActivityperActivity  --excel_sheetname=perActivity  --proto_msgname=perActivityperActivity  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/perActivityperActivity.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/perActivityweek.bin:${PROTOCGEN_FILE_PATH}/perActivity.proto.ds ${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/perActivity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_perActivityweek  --excel_sheetname=week  --proto_msgname=perActivityweek  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/perActivityweek.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.cpp" --dst=${DESC_STORE_PATH}/

