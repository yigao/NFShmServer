include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_BackBack.bin ${PROTOCGEN_FILE_PATH}/BackBackDesc.h ${PROTOCGEN_FILE_PATH}/BackBackDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_BackBack.bin:${PROTOCGEN_FILE_PATH}/back.proto.ds ${RESDB_EXCELMMO_PATH}/back.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/back.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/back.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BackBack  --excel_sheetname=back  --proto_msgname=E_BackBack  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BackBack.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BackBackDesc.h ${PROTOCGEN_FILE_PATH}/BackBackDesc.cpp" --dst=${DESC_STORE_PATH}/

