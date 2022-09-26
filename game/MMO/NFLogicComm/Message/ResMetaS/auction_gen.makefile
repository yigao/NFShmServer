include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/auctionacquisition.bin ${GAME_DATA_PATH}/auctionpurchase.bin 

${GAME_DATA_PATH}/auctionacquisition.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/auction.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/auction.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_auctionacquisition  --excel_sheetname=acquisition  --proto_msgname=auctionacquisition  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/auctionpurchase.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/auction.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/auction.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_auctionpurchase  --excel_sheetname=purchase  --proto_msgname=auctionpurchase  --start_row=4 --out_path=${GAME_DATA_PATH}/

