include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MapMap.bin ${PROTOCGEN_FILE_PATH}/MapMapDesc.h ${PROTOCGEN_FILE_PATH}/MapMapDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MapItemdrop.bin ${PROTOCGEN_FILE_PATH}/MapItemdropDesc.h ${PROTOCGEN_FILE_PATH}/MapItemdropDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MapDestroyitem.bin ${PROTOCGEN_FILE_PATH}/MapDestroyitemDesc.h ${PROTOCGEN_FILE_PATH}/MapDestroyitemDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MapMap.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MapMap  --excel_sheetname=map  --proto_msgname=E_MapMap  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MapMap.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MapMapDesc.h ${PROTOCGEN_FILE_PATH}/MapMapDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MapItemdrop.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MapItemdrop  --excel_sheetname=itemdrop  --proto_msgname=E_MapItemdrop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MapItemdrop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MapItemdropDesc.h ${PROTOCGEN_FILE_PATH}/MapItemdropDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MapDestroyitem.bin:${PROTOCGEN_FILE_PATH}/map.proto.ds ${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/map.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MapDestroyitem  --excel_sheetname=destroyitem  --proto_msgname=E_MapDestroyitem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MapDestroyitem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MapDestroyitemDesc.h ${PROTOCGEN_FILE_PATH}/MapDestroyitemDesc.cpp" --dst=${DESC_STORE_PATH}/

