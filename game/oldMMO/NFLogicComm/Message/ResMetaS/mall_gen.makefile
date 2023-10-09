include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MallMall.bin ${PROTOCGEN_FILE_PATH}/MallMallDesc.h ${PROTOCGEN_FILE_PATH}/MallMallDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MallMalltype.bin ${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.h ${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MallMalltype_tab.bin ${PROTOCGEN_FILE_PATH}/MallMalltype_tabDesc.h ${PROTOCGEN_FILE_PATH}/MallMalltype_tabDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MallMall.bin:${PROTOCGEN_FILE_PATH}/mall.proto.ds ${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mall.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MallMall  --excel_sheetname=mall  --proto_msgname=E_MallMall  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MallMall.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MallMallDesc.h ${PROTOCGEN_FILE_PATH}/MallMallDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MallMalltype.bin:${PROTOCGEN_FILE_PATH}/mall.proto.ds ${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mall.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MallMalltype  --excel_sheetname=malltype  --proto_msgname=E_MallMalltype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MallMalltype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.h ${PROTOCGEN_FILE_PATH}/MallMalltypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MallMalltype_tab.bin:${PROTOCGEN_FILE_PATH}/mall.proto.ds ${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mall.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MallMalltype_tab  --excel_sheetname=malltype_tab  --proto_msgname=E_MallMalltype_tab  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MallMalltype_tab.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MallMalltype_tabDesc.h ${PROTOCGEN_FILE_PATH}/MallMalltype_tabDesc.cpp" --dst=${DESC_STORE_PATH}/

