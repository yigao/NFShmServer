include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/wingwing.bin ${PROTOCGEN_FILE_PATH}/wingchange.bin ${PROTOCGEN_FILE_PATH}/wingfragment.bin ${PROTOCGEN_FILE_PATH}/wingstarUp.bin 

${PROTOCGEN_FILE_PATH}/wingwing.bin:${PROTOCGEN_FILE_PATH}/wing.proto.ds ${RESDB_EXCELMMO_PATH}/wing.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/wing.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingwing  --excel_sheetname=wing  --proto_msgname=wingwing  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/wingwing.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/wingchange.bin:${PROTOCGEN_FILE_PATH}/wing.proto.ds ${RESDB_EXCELMMO_PATH}/wing.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/wing.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingchange  --excel_sheetname=change  --proto_msgname=wingchange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/wingchange.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/wingfragment.bin:${PROTOCGEN_FILE_PATH}/wing.proto.ds ${RESDB_EXCELMMO_PATH}/wing.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/wing.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingfragment  --excel_sheetname=fragment  --proto_msgname=wingfragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/wingfragment.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/wingstarUp.bin:${PROTOCGEN_FILE_PATH}/wing.proto.ds ${RESDB_EXCELMMO_PATH}/wing.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/wing.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/wing.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_wingstarUp  --excel_sheetname=starUp  --proto_msgname=wingstarUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/wingstarUp.bin" --dst=${GAME_DATA_PATH}/
