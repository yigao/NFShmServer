include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_LinkLink.bin ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.h ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_LinkLink.bin:${PROTOCGEN_FILE_PATH}/link.proto.ds ${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/link.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/link.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_LinkLink  --excel_sheetname=link  --proto_msgname=E_LinkLink  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_LinkLink.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/LinkLinkDesc.h ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.cpp" --dst=${DESC_STORE_PATH}/

