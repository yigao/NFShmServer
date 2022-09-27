include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/mapmap.bin ${GAME_DATA_PATH}/mapitemdrop.bin ${GAME_DATA_PATH}/mapdestroyitem.bin 

${GAME_DATA_PATH}/mapmap.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mapmap  --excel_sheetname=map  --proto_msgname=mapmap  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/mapitemdrop.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mapitemdrop  --excel_sheetname=itemdrop  --proto_msgname=mapitemdrop  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/mapdestroyitem.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mapdestroyitem  --excel_sheetname=destroyitem  --proto_msgname=mapdestroyitem  --start_row=4 --out_path=${GAME_DATA_PATH}/

