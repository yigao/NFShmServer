include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/chooseGiftchooseGift.bin 

${PROTOCGEN_FILE_PATH}/chooseGiftchooseGift.bin:${PROTOCGEN_FILE_PATH}/chooseGift.proto.ds ${RESDB_EXCELMMO_PATH}/chooseGift.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chooseGift.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chooseGift.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_chooseGiftchooseGift  --excel_sheetname=chooseGift  --proto_msgname=chooseGiftchooseGift  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chooseGiftchooseGift.bin" --dst=${GAME_DATA_PATH}/
