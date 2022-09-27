include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/GMtoolsGMTools.bin ${PROTOCGEN_FILE_PATH}/GMtoolsrecharge.bin ${PROTOCGEN_FILE_PATH}/GMtoolsgift.bin ${PROTOCGEN_FILE_PATH}/GMtoolsunlimit.bin ${PROTOCGEN_FILE_PATH}/GMtoolsupperLimit.bin 

${PROTOCGEN_FILE_PATH}/GMtoolsGMTools.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsGMTools  --excel_sheetname=GMTools  --proto_msgname=GMtoolsGMTools  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtoolsGMTools.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/GMtoolsrecharge.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsrecharge  --excel_sheetname=recharge  --proto_msgname=GMtoolsrecharge  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtoolsrecharge.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/GMtoolsgift.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsgift  --excel_sheetname=gift  --proto_msgname=GMtoolsgift  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtoolsgift.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/GMtoolsunlimit.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsunlimit  --excel_sheetname=unlimit  --proto_msgname=GMtoolsunlimit  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtoolsunlimit.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/GMtoolsupperLimit.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsupperLimit  --excel_sheetname=upperLimit  --proto_msgname=GMtoolsupperLimit  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtoolsupperLimit.bin" --dst=${GAME_DATA_PATH}/
