include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/titletype.bin ${PROTOCGEN_FILE_PATH}/titletitle.bin 

${PROTOCGEN_FILE_PATH}/titletype.bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_titletype  --excel_sheetname=type  --proto_msgname=titletype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/titletype.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/titletitle.bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_titletitle  --excel_sheetname=title  --proto_msgname=titletitle  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/titletitle.bin" --dst=${GAME_DATA_PATH}/
