include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/GMCommandGMCommand.bin ${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.h ${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.cpp 

${PROTOCGEN_FILE_PATH}/GMCommandGMCommand.bin:${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds ${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMCommand.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMCommandGMCommand  --excel_sheetname=GMCommand  --proto_msgname=GMCommandGMCommand  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMCommandGMCommand.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.h ${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.cpp:${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds ${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.h ${PROTOCGEN_FILE_PATH}/GmcommandGmcommandDesc.cpp" --dst=${DESC_STORE_PATH}/

