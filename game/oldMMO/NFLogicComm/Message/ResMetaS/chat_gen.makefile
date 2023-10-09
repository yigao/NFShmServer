include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_ChatChat.bin ${PROTOCGEN_FILE_PATH}/ChatChatDesc.h ${PROTOCGEN_FILE_PATH}/ChatChatDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ChatSpecialchat.bin ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.h ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_ChatChat.bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ChatChat  --excel_sheetname=chat  --proto_msgname=E_ChatChat  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ChatChat.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ChatChatDesc.h ${PROTOCGEN_FILE_PATH}/ChatChatDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ChatSpecialchat.bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ChatSpecialchat  --excel_sheetname=specialchat  --proto_msgname=E_ChatSpecialchat  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ChatSpecialchat.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.h ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.cpp" --dst=${DESC_STORE_PATH}/

