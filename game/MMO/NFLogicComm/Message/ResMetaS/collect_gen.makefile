include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_CollectCollect.bin ${PROTOCGEN_FILE_PATH}/CollectCollectDesc.h ${PROTOCGEN_FILE_PATH}/CollectCollectDesc.cpp ${PROTOCGEN_FILE_PATH}/E_CollectAttributetpye.bin ${PROTOCGEN_FILE_PATH}/CollectAttributetpyeDesc.h ${PROTOCGEN_FILE_PATH}/CollectAttributetpyeDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_CollectCollect.bin:${PROTOCGEN_FILE_PATH}/collect.proto.ds ${RESDB_EXCELMMO_PATH}/collect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/collect.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/collect.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_CollectCollect  --excel_sheetname=collect  --proto_msgname=E_CollectCollect  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_CollectCollect.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/CollectCollectDesc.h ${PROTOCGEN_FILE_PATH}/CollectCollectDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_CollectAttributetpye.bin:${PROTOCGEN_FILE_PATH}/collect.proto.ds ${RESDB_EXCELMMO_PATH}/collect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/collect.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/collect.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_CollectAttributetpye  --excel_sheetname=attributeTpye  --proto_msgname=E_CollectAttributetpye  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_CollectAttributetpye.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/CollectAttributetpyeDesc.h ${PROTOCGEN_FILE_PATH}/CollectAttributetpyeDesc.cpp" --dst=${DESC_STORE_PATH}/

