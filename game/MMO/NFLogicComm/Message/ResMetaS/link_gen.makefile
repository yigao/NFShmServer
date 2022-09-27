include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/linklink.bin ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.h ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.cpp 

${PROTOCGEN_FILE_PATH}/linklink.bin:${PROTOCGEN_FILE_PATH}/link.proto.ds ${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/link.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/link.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_linklink  --excel_sheetname=link  --proto_msgname=linklink  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/linklink.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/LinkLinkDesc.h ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.cpp:${PROTOCGEN_FILE_PATH}/link.proto.ds ${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/LinkLinkDesc.h ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.cpp" --dst=${DESC_STORE_PATH}/

