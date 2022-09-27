include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/dynamicexpdynamicexp.bin 

${GAME_DATA_PATH}/dynamicexpdynamicexp.bin:${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds ${RESDB_EXCELMMO_PATH}/dynamicexp.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dynamicexp.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dynamicexpdynamicexp  --excel_sheetname=dynamicexp  --proto_msgname=dynamicexpdynamicexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

