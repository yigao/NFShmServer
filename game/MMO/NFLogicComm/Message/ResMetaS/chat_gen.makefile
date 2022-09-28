include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/chatchat.bin ${PROTOCGEN_FILE_PATH}/ChatChatDesc.h ${PROTOCGEN_FILE_PATH}/ChatChatDesc.cpp ${PROTOCGEN_FILE_PATH}/chatspecialchat.bin ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.h ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.cpp 

${PROTOCGEN_FILE_PATH}/chatchat.bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_chatchat  --excel_sheetname=chat  --proto_msgname=chatchat  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chatchat.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ChatChatDesc.h ${PROTOCGEN_FILE_PATH}/ChatChatDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/chatspecialchat.bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_chatspecialchat  --excel_sheetname=specialchat  --proto_msgname=chatspecialchat  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chatspecialchat.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.h ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.cpp" --dst=${DESC_STORE_PATH}/

