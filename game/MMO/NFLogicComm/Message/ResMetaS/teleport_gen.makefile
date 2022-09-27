include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/teleportborn.bin ${PROTOCGEN_FILE_PATH}/teleportteleport.bin 

${PROTOCGEN_FILE_PATH}/teleportborn.bin:${PROTOCGEN_FILE_PATH}/teleport.proto.ds ${RESDB_EXCELMMO_PATH}/teleport.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/teleport.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/teleport.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_teleportborn  --excel_sheetname=born  --proto_msgname=teleportborn  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/teleportborn.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/teleportteleport.bin:${PROTOCGEN_FILE_PATH}/teleport.proto.ds ${RESDB_EXCELMMO_PATH}/teleport.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/teleport.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/teleport.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_teleportteleport  --excel_sheetname=teleport  --proto_msgname=teleportteleport  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/teleportteleport.bin" --dst=${GAME_DATA_PATH}/
