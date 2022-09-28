include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/serveropenactiveserviceActivity.bin ${PROTOCGEN_FILE_PATH}/ServeropenactiveServiceactivityDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveServiceactivityDesc.cpp ${PROTOCGEN_FILE_PATH}/serveropenactivepageBook.bin ${PROTOCGEN_FILE_PATH}/ServeropenactivePagebookDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactivePagebookDesc.cpp ${PROTOCGEN_FILE_PATH}/serveropenactivepage.bin ${PROTOCGEN_FILE_PATH}/ServeropenactivePageDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactivePageDesc.cpp ${PROTOCGEN_FILE_PATH}/serveropenactivemRank.bin ${PROTOCGEN_FILE_PATH}/ServeropenactiveMrankDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMrankDesc.cpp ${PROTOCGEN_FILE_PATH}/serveropenactivemAdvanced.bin ${PROTOCGEN_FILE_PATH}/ServeropenactiveMadvancedDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMadvancedDesc.cpp ${PROTOCGEN_FILE_PATH}/serveropenactivemRecharge.bin ${PROTOCGEN_FILE_PATH}/ServeropenactiveMrechargeDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMrechargeDesc.cpp ${PROTOCGEN_FILE_PATH}/serveropenactivemGoods.bin ${PROTOCGEN_FILE_PATH}/ServeropenactiveMgoodsDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMgoodsDesc.cpp 

${PROTOCGEN_FILE_PATH}/serveropenactiveserviceActivity.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactiveserviceActivity  --excel_sheetname=serviceActivity  --proto_msgname=serveropenactiveserviceActivity  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactiveserviceActivity.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactiveServiceactivityDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveServiceactivityDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/serveropenactivepageBook.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivepageBook  --excel_sheetname=pageBook  --proto_msgname=serveropenactivepageBook  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactivepageBook.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactivePagebookDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactivePagebookDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/serveropenactivepage.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivepage  --excel_sheetname=page  --proto_msgname=serveropenactivepage  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactivepage.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactivePageDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactivePageDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/serveropenactivemRank.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemRank  --excel_sheetname=mRank  --proto_msgname=serveropenactivemRank  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactivemRank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactiveMrankDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMrankDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/serveropenactivemAdvanced.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemAdvanced  --excel_sheetname=mAdvanced  --proto_msgname=serveropenactivemAdvanced  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactivemAdvanced.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactiveMadvancedDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMadvancedDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/serveropenactivemRecharge.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemRecharge  --excel_sheetname=mRecharge  --proto_msgname=serveropenactivemRecharge  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactivemRecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactiveMrechargeDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMrechargeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/serveropenactivemGoods.bin:${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds ${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serveropenactivemGoods  --excel_sheetname=mGoods  --proto_msgname=serveropenactivemGoods  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactivemGoods.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ServeropenactiveMgoodsDesc.h ${PROTOCGEN_FILE_PATH}/ServeropenactiveMgoodsDesc.cpp" --dst=${DESC_STORE_PATH}/

