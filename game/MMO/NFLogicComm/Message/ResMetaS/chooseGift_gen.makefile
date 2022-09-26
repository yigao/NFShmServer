include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/chooseGiftchooseGift.bin 

${GAME_DATA_PATH}/chooseGiftchooseGift.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/chooseGift.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chooseGift.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_chooseGiftchooseGift  --excel_sheetname=chooseGift  --proto_msgname=chooseGiftchooseGift  --start_row=4 --out_path=${GAME_DATA_PATH}/

