include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/mapmap.bin ${PROTOCGEN_FILE_PATH}/mapitemdrop.bin ${PROTOCGEN_FILE_PATH}/mapdestroyitem.bin 

${PROTOCGEN_FILE_PATH}/mapmap.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mapmap  --excel_sheetname=map  --proto_msgname=mapmap  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mapmap.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/mapitemdrop.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mapitemdrop  --excel_sheetname=itemdrop  --proto_msgname=mapitemdrop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mapitemdrop.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/mapdestroyitem.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mapdestroyitem  --excel_sheetname=destroyitem  --proto_msgname=mapdestroyitem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mapdestroyitem.bin" --dst=${GAME_DATA_PATH}/
