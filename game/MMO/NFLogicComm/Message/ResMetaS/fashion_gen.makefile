include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/fashionfashion.bin 

${GAME_DATA_PATH}/fashionfashion.bin:${PROTOCGEN_FILE_PATH}/fashion.proto.ds ${RESDB_EXCELMMO_PATH}/fashion.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/fashion.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/fashion.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fashionfashion  --excel_sheetname=fashion  --proto_msgname=fashionfashion  --start_row=4 --out_path=${GAME_DATA_PATH}/

