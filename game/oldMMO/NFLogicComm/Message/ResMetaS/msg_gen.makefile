include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MsgPhpmsg.bin ${PROTOCGEN_FILE_PATH}/MsgPhpmsgDesc.h ${PROTOCGEN_FILE_PATH}/MsgPhpmsgDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MsgPhpmsg.bin:${PROTOCGEN_FILE_PATH}/msg.proto.ds ${RESDB_EXCELMMO_PATH}/msg.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/msg.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/msg.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MsgPhpmsg  --excel_sheetname=phpmsg  --proto_msgname=E_MsgPhpmsg  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MsgPhpmsg.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MsgPhpmsgDesc.h ${PROTOCGEN_FILE_PATH}/MsgPhpmsgDesc.cpp" --dst=${DESC_STORE_PATH}/

