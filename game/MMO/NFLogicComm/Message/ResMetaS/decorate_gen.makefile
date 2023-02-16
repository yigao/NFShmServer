include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_DecorateDecorate.bin ${PROTOCGEN_FILE_PATH}/DecorateDecorateDesc.h ${PROTOCGEN_FILE_PATH}/DecorateDecorateDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_DecorateDecorate.bin:${PROTOCGEN_FILE_PATH}/decorate.proto.ds ${RESDB_EXCELMMO_PATH}/decorate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/decorate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/decorate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DecorateDecorate  --excel_sheetname=decorate  --proto_msgname=E_DecorateDecorate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DecorateDecorate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DecorateDecorateDesc.h ${PROTOCGEN_FILE_PATH}/DecorateDecorateDesc.cpp" --dst=${DESC_STORE_PATH}/

