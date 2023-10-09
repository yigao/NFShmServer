include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_PeractivityPeractivity.bin ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PeractivityWeek.bin ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_PeractivityPeractivity.bin:${PROTOCGEN_FILE_PATH}/perActivity.proto.ds ${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/perActivity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PeractivityPeractivity  --excel_sheetname=perActivity  --proto_msgname=E_PeractivityPeractivity  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PeractivityPeractivity.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PeractivityWeek.bin:${PROTOCGEN_FILE_PATH}/perActivity.proto.ds ${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/perActivity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PeractivityWeek  --excel_sheetname=week  --proto_msgname=E_PeractivityWeek  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PeractivityWeek.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.cpp" --dst=${DESC_STORE_PATH}/

