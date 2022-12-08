include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/tasktask.bin ${PROTOCGEN_FILE_PATH}/TaskTaskDesc.h ${PROTOCGEN_FILE_PATH}/TaskTaskDesc.cpp 

${PROTOCGEN_FILE_PATH}/tasktask.bin:${PROTOCGEN_FILE_PATH}/task.proto.ds ${RESDB_EXCELMMO_PATH}/task.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/task.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/task.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_tasktask  --excel_sheetname=task  --proto_msgname=tasktask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/tasktask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskTaskDesc.h ${PROTOCGEN_FILE_PATH}/TaskTaskDesc.cpp" --dst=${DESC_STORE_PATH}/

