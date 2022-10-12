include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/closetestActivity.bin ${PROTOCGEN_FILE_PATH}/ClosetestActivityDesc.h ${PROTOCGEN_FILE_PATH}/ClosetestActivityDesc.cpp ${PROTOCGEN_FILE_PATH}/closetestRebate.bin ${PROTOCGEN_FILE_PATH}/ClosetestRebateDesc.h ${PROTOCGEN_FILE_PATH}/ClosetestRebateDesc.cpp 

${PROTOCGEN_FILE_PATH}/closetestActivity.bin:${PROTOCGEN_FILE_PATH}/closetest.proto.ds ${RESDB_EXCELMMO_PATH}/closetest.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/closetest.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/closetest.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_closetestActivity  --excel_sheetname=Activity  --proto_msgname=closetestActivity  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/closetestActivity.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ClosetestActivityDesc.h ${PROTOCGEN_FILE_PATH}/ClosetestActivityDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/closetestRebate.bin:${PROTOCGEN_FILE_PATH}/closetest.proto.ds ${RESDB_EXCELMMO_PATH}/closetest.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/closetest.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/closetest.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_closetestRebate  --excel_sheetname=Rebate  --proto_msgname=closetestRebate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/closetestRebate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ClosetestRebateDesc.h ${PROTOCGEN_FILE_PATH}/ClosetestRebateDesc.cpp" --dst=${DESC_STORE_PATH}/

