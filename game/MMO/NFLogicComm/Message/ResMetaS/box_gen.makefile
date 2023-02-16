include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_BoxBox.bin ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.cpp ${PROTOCGEN_FILE_PATH}/E_BoxBoxdata.bin ${PROTOCGEN_FILE_PATH}/BoxBoxdataDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxdataDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_BoxBox.bin:${PROTOCGEN_FILE_PATH}/box.proto.ds ${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/box.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BoxBox  --excel_sheetname=box  --proto_msgname=E_BoxBox  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BoxBox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BoxBoxDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_BoxBoxdata.bin:${PROTOCGEN_FILE_PATH}/box.proto.ds ${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/box.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_BoxBoxdata  --excel_sheetname=boxdata  --proto_msgname=E_BoxBoxdata  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_BoxBoxdata.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/BoxBoxdataDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxdataDesc.cpp" --dst=${DESC_STORE_PATH}/

