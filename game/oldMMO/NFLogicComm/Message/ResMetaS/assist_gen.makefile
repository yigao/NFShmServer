include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_AssistBox.bin ${PROTOCGEN_FILE_PATH}/AssistBoxDesc.h ${PROTOCGEN_FILE_PATH}/AssistBoxDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AssistThank.bin ${PROTOCGEN_FILE_PATH}/AssistThankDesc.h ${PROTOCGEN_FILE_PATH}/AssistThankDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AssistConst.bin ${PROTOCGEN_FILE_PATH}/AssistConstDesc.h ${PROTOCGEN_FILE_PATH}/AssistConstDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_AssistBox.bin:${PROTOCGEN_FILE_PATH}/assist.proto.ds ${RESDB_EXCELMMO_PATH}/assist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/assist.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/assist.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AssistBox  --excel_sheetname=box  --proto_msgname=E_AssistBox  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AssistBox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AssistBoxDesc.h ${PROTOCGEN_FILE_PATH}/AssistBoxDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AssistThank.bin:${PROTOCGEN_FILE_PATH}/assist.proto.ds ${RESDB_EXCELMMO_PATH}/assist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/assist.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/assist.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AssistThank  --excel_sheetname=thank  --proto_msgname=E_AssistThank  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AssistThank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AssistThankDesc.h ${PROTOCGEN_FILE_PATH}/AssistThankDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AssistConst.bin:${PROTOCGEN_FILE_PATH}/assist.proto.ds ${RESDB_EXCELMMO_PATH}/assist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/assist.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/assist.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AssistConst  --excel_sheetname=const  --proto_msgname=E_AssistConst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AssistConst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AssistConstDesc.h ${PROTOCGEN_FILE_PATH}/AssistConstDesc.cpp" --dst=${DESC_STORE_PATH}/

