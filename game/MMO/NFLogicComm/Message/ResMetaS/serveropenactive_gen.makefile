include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/serveropenactiveserviceActivity.bin ${GAME_DATA_PATH}/serveropenactivepageBook.bin ${GAME_DATA_PATH}/serveropenactivepage.bin ${GAME_DATA_PATH}/serveropenactivemRank.bin ${GAME_DATA_PATH}/serveropenactivemAdvanced.bin ${GAME_DATA_PATH}/serveropenactivemRecharge.bin ${GAME_DATA_PATH}/serveropenactivemGoods.bin 

${GAME_DATA_PATH}/serveropenactiveserviceActivity.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactiveserviceActivity  --excel_sheetname=serviceActivity  --proto_msgname=serveropenactiveserviceActivity  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/serveropenactivepageBook.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivepageBook  --excel_sheetname=pageBook  --proto_msgname=serveropenactivepageBook  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/serveropenactivepage.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivepage  --excel_sheetname=page  --proto_msgname=serveropenactivepage  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/serveropenactivemRank.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemRank  --excel_sheetname=mRank  --proto_msgname=serveropenactivemRank  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/serveropenactivemAdvanced.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemAdvanced  --excel_sheetname=mAdvanced  --proto_msgname=serveropenactivemAdvanced  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/serveropenactivemRecharge.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemRecharge  --excel_sheetname=mRecharge  --proto_msgname=serveropenactivemRecharge  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/serveropenactivemGoods.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemGoods  --excel_sheetname=mGoods  --proto_msgname=serveropenactivemGoods  --start_row=4 --out_path=${GAME_DATA_PATH}/

