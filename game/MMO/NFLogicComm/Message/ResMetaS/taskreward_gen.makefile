include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/taskrewardtaskreward.bin ${PROTOCGEN_FILE_PATH}/TaskrewardTaskrewardDesc.h ${PROTOCGEN_FILE_PATH}/TaskrewardTaskrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/taskrewardtasktype.bin ${PROTOCGEN_FILE_PATH}/TaskrewardTasktypeDesc.h ${PROTOCGEN_FILE_PATH}/TaskrewardTasktypeDesc.cpp 

${PROTOCGEN_FILE_PATH}/taskrewardtaskreward.bin:${PROTOCGEN_FILE_PATH}/taskreward.proto.ds ${RESDB_EXCELMMO_PATH}/taskreward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskreward.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskrewardtaskreward  --excel_sheetname=taskreward  --proto_msgname=taskrewardtaskreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskrewardtaskreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskrewardTaskrewardDesc.h ${PROTOCGEN_FILE_PATH}/TaskrewardTaskrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/taskrewardtasktype.bin:${PROTOCGEN_FILE_PATH}/taskreward.proto.ds ${RESDB_EXCELMMO_PATH}/taskreward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskreward.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskrewardtasktype  --excel_sheetname=tasktype  --proto_msgname=taskrewardtasktype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskrewardtasktype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskrewardTasktypeDesc.h ${PROTOCGEN_FILE_PATH}/TaskrewardTasktypeDesc.cpp" --dst=${DESC_STORE_PATH}/

