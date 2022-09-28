include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/areaarea.bin ${PROTOCGEN_FILE_PATH}/AreaAreaDesc.h ${PROTOCGEN_FILE_PATH}/AreaAreaDesc.cpp ${PROTOCGEN_FILE_PATH}/areapath.bin ${PROTOCGEN_FILE_PATH}/AreaPathDesc.h ${PROTOCGEN_FILE_PATH}/AreaPathDesc.cpp 

${PROTOCGEN_FILE_PATH}/areaarea.bin:${PROTOCGEN_FILE_PATH}/area.proto.ds ${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/area.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_areaarea  --excel_sheetname=area  --proto_msgname=areaarea  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/areaarea.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AreaAreaDesc.h ${PROTOCGEN_FILE_PATH}/AreaAreaDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/areapath.bin:${PROTOCGEN_FILE_PATH}/area.proto.ds ${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/area.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_areapath  --excel_sheetname=path  --proto_msgname=areapath  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/areapath.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AreaPathDesc.h ${PROTOCGEN_FILE_PATH}/AreaPathDesc.cpp" --dst=${DESC_STORE_PATH}/

