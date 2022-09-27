include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/combinecitem.bin ${PROTOCGEN_FILE_PATH}/combinestarUp.bin ${PROTOCGEN_FILE_PATH}/combineitemUp.bin ${PROTOCGEN_FILE_PATH}/combinerankUp.bin ${PROTOCGEN_FILE_PATH}/combinequalityUp.bin 

${PROTOCGEN_FILE_PATH}/combinecitem.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinecitem  --excel_sheetname=citem  --proto_msgname=combinecitem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combinecitem.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/combinestarUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinestarUp  --excel_sheetname=starUp  --proto_msgname=combinestarUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combinestarUp.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/combineitemUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combineitemUp  --excel_sheetname=itemUp  --proto_msgname=combineitemUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combineitemUp.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/combinerankUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinerankUp  --excel_sheetname=rankUp  --proto_msgname=combinerankUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combinerankUp.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/combinequalityUp.bin:${PROTOCGEN_FILE_PATH}/combine.proto.ds ${RESDB_EXCELMMO_PATH}/combine.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/combine.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_combinequalityUp  --excel_sheetname=qualityUp  --proto_msgname=combinequalityUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combinequalityUp.bin" --dst=${GAME_DATA_PATH}/
