include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/GMtoolsGMTools.bin ${GAME_DATA_PATH}/GMtoolsrecharge.bin ${GAME_DATA_PATH}/GMtoolsgift.bin ${GAME_DATA_PATH}/GMtoolsunlimit.bin ${GAME_DATA_PATH}/GMtoolsupperLimit.bin 

${GAME_DATA_PATH}/GMtoolsGMTools.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsGMTools  --excel_sheetname=GMTools  --proto_msgname=GMtoolsGMTools  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/GMtoolsrecharge.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsrecharge  --excel_sheetname=recharge  --proto_msgname=GMtoolsrecharge  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/GMtoolsgift.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsgift  --excel_sheetname=gift  --proto_msgname=GMtoolsgift  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/GMtoolsunlimit.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsunlimit  --excel_sheetname=unlimit  --proto_msgname=GMtoolsunlimit  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/GMtoolsupperLimit.bin:${PROTOCGEN_FILE_PATH}/GMtools.proto.ds ${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMtools.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMtoolsupperLimit  --excel_sheetname=upperLimit  --proto_msgname=GMtoolsupperLimit  --start_row=4 --out_path=${GAME_DATA_PATH}/

