include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/dynamicexpdynamicexp.bin ${PROTOCGEN_FILE_PATH}/DynamicexpDynamicexpDesc.h ${PROTOCGEN_FILE_PATH}/DynamicexpDynamicexpDesc.cpp 

${PROTOCGEN_FILE_PATH}/dynamicexpdynamicexp.bin:${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds ${RESDB_EXCELMMO_PATH}/dynamicexp.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dynamicexp.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dynamicexpdynamicexp  --excel_sheetname=dynamicexp  --proto_msgname=dynamicexpdynamicexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dynamicexpdynamicexp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/DynamicexpDynamicexpDesc.h ${PROTOCGEN_FILE_PATH}/DynamicexpDynamicexpDesc.cpp:${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds ${RESDB_EXCELMMO_PATH}/dynamicexp.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DynamicexpDynamicexpDesc.h ${PROTOCGEN_FILE_PATH}/DynamicexpDynamicexpDesc.cpp" --dst=${DESC_STORE_PATH}/

