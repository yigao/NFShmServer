include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/auctionacquisition.bin ${PROTOCGEN_FILE_PATH}/auctionpurchase.bin 

${PROTOCGEN_FILE_PATH}/auctionacquisition.bin:${PROTOCGEN_FILE_PATH}/auction.proto.ds ${RESDB_EXCELMMO_PATH}/auction.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/auction.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/auction.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_auctionacquisition  --excel_sheetname=acquisition  --proto_msgname=auctionacquisition  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/auctionacquisition.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/auctionpurchase.bin:${PROTOCGEN_FILE_PATH}/auction.proto.ds ${RESDB_EXCELMMO_PATH}/auction.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/auction.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/auction.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_auctionpurchase  --excel_sheetname=purchase  --proto_msgname=auctionpurchase  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/auctionpurchase.bin" --dst=${GAME_DATA_PATH}/
