include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/boxbox.bin ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.cpp 

${PROTOCGEN_FILE_PATH}/boxbox.bin:${PROTOCGEN_FILE_PATH}/box.proto.ds ${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/box.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_boxbox  --excel_sheetname=box  --proto_msgname=boxbox  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/boxbox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BoxBoxDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.cpp" --dst=${DESC_STORE_PATH}/

