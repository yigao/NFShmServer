include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_chat_bin

${PROTOCGEN_FILE_PATH}/module_chat_bin:${PROTOCGEN_FILE_PATH}/chat.proto.ds ${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_chat_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/chat.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/ChatDescEx.h ${PROTOCGEN_FILE_PATH}/ChatDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ChatChat.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ChatChatDesc.h ${PROTOCGEN_FILE_PATH}/ChatChatDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ChatSpecialchat.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.h ${PROTOCGEN_FILE_PATH}/ChatSpecialchatDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_chat_bin
