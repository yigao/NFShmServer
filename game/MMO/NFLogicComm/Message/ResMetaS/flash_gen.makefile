include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/flashflash.bin ${PROTOCGEN_FILE_PATH}/flashitemFlash.bin 

${PROTOCGEN_FILE_PATH}/flashflash.bin:${PROTOCGEN_FILE_PATH}/flash.proto.ds ${RESDB_EXCELMMO_PATH}/flash.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_flashflash  --excel_sheetname=flash  --proto_msgname=flashflash  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/flashflash.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/flashitemFlash.bin:${PROTOCGEN_FILE_PATH}/flash.proto.ds ${RESDB_EXCELMMO_PATH}/flash.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_flashitemFlash  --excel_sheetname=itemFlash  --proto_msgname=flashitemFlash  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/flashitemFlash.bin" --dst=${GAME_DATA_PATH}/
