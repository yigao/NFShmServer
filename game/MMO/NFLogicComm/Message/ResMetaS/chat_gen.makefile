include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/chatchat.bin ${GAME_DATA_PATH}/chatspecialchat.bin 

${GAME_DATA_PATH}/chatchat.bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_chatchat  --excel_sheetname=chat  --proto_msgname=chatchat  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/chatspecialchat.bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_chatspecialchat  --excel_sheetname=specialchat  --proto_msgname=chatspecialchat  --start_row=4 --out_path=${GAME_DATA_PATH}/

