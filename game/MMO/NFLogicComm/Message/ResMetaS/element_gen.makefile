include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/elementelement.bin ${PROTOCGEN_FILE_PATH}/ElementElementDesc.h ${PROTOCGEN_FILE_PATH}/ElementElementDesc.cpp ${PROTOCGEN_FILE_PATH}/elementfragment.bin ${PROTOCGEN_FILE_PATH}/ElementFragmentDesc.h ${PROTOCGEN_FILE_PATH}/ElementFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/elementelementUI.bin ${PROTOCGEN_FILE_PATH}/ElementElementuiDesc.h ${PROTOCGEN_FILE_PATH}/ElementElementuiDesc.cpp 

${PROTOCGEN_FILE_PATH}/elementelement.bin:${PROTOCGEN_FILE_PATH}/element.proto.ds ${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/element.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/element.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_elementelement  --excel_sheetname=element  --proto_msgname=elementelement  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/elementelement.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ElementElementDesc.h ${PROTOCGEN_FILE_PATH}/ElementElementDesc.cpp:${PROTOCGEN_FILE_PATH}/element.proto.ds ${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ElementElementDesc.h ${PROTOCGEN_FILE_PATH}/ElementElementDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/elementfragment.bin:${PROTOCGEN_FILE_PATH}/element.proto.ds ${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/element.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/element.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_elementfragment  --excel_sheetname=fragment  --proto_msgname=elementfragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/elementfragment.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ElementFragmentDesc.h ${PROTOCGEN_FILE_PATH}/ElementFragmentDesc.cpp:${PROTOCGEN_FILE_PATH}/element.proto.ds ${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ElementFragmentDesc.h ${PROTOCGEN_FILE_PATH}/ElementFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/elementelementUI.bin:${PROTOCGEN_FILE_PATH}/element.proto.ds ${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/element.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/element.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_elementelementUI  --excel_sheetname=elementUI  --proto_msgname=elementelementUI  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/elementelementUI.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ElementElementuiDesc.h ${PROTOCGEN_FILE_PATH}/ElementElementuiDesc.cpp:${PROTOCGEN_FILE_PATH}/element.proto.ds ${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ElementElementuiDesc.h ${PROTOCGEN_FILE_PATH}/ElementElementuiDesc.cpp" --dst=${DESC_STORE_PATH}/

