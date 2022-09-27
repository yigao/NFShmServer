include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/fashionfashion.bin ${PROTOCGEN_FILE_PATH}/FashionFashionDesc.h ${PROTOCGEN_FILE_PATH}/FashionFashionDesc.cpp 

${PROTOCGEN_FILE_PATH}/fashionfashion.bin:${PROTOCGEN_FILE_PATH}/fashion.proto.ds ${RESDB_EXCELMMO_PATH}/fashion.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/fashion.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/fashion.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fashionfashion  --excel_sheetname=fashion  --proto_msgname=fashionfashion  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fashionfashion.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FashionFashionDesc.h ${PROTOCGEN_FILE_PATH}/FashionFashionDesc.cpp:${PROTOCGEN_FILE_PATH}/fashion.proto.ds ${RESDB_EXCELMMO_PATH}/fashion.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FashionFashionDesc.h ${PROTOCGEN_FILE_PATH}/FashionFashionDesc.cpp" --dst=${DESC_STORE_PATH}/

