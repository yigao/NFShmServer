include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/huoyuedureward.bin ${PROTOCGEN_FILE_PATH}/huoyueduactive.bin 

${PROTOCGEN_FILE_PATH}/huoyuedureward.bin:${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds ${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_huoyuedureward  --excel_sheetname=reward  --proto_msgname=huoyuedureward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/huoyuedureward.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/huoyueduactive.bin:${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds ${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_huoyueduactive  --excel_sheetname=active  --proto_msgname=huoyueduactive  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/huoyueduactive.bin" --dst=${GAME_DATA_PATH}/
