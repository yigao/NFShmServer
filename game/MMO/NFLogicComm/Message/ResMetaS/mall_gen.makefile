include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/mallmall.bin ${PROTOCGEN_FILE_PATH}/MallMallDesc.h ${PROTOCGEN_FILE_PATH}/MallMallDesc.cpp ${PROTOCGEN_FILE_PATH}/mallmalltype.bin ${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.h ${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.cpp 

${PROTOCGEN_FILE_PATH}/mallmall.bin:${PROTOCGEN_FILE_PATH}/mall.proto.ds ${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mall.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mallmall  --excel_sheetname=mall  --proto_msgname=mallmall  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mallmall.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MallMallDesc.h ${PROTOCGEN_FILE_PATH}/MallMallDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/mallmalltype.bin:${PROTOCGEN_FILE_PATH}/mall.proto.ds ${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mall.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mallmalltype  --excel_sheetname=malltype  --proto_msgname=mallmalltype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mallmalltype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.h ${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.cpp" --dst=${DESC_STORE_PATH}/

