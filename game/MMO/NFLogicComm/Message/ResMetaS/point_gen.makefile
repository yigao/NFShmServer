include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/pointpoint.bin ${PROTOCGEN_FILE_PATH}/PointPointDesc.h ${PROTOCGEN_FILE_PATH}/PointPointDesc.cpp 

${PROTOCGEN_FILE_PATH}/pointpoint.bin:${PROTOCGEN_FILE_PATH}/point.proto.ds ${RESDB_EXCELMMO_PATH}/point.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/point.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/point.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_pointpoint  --excel_sheetname=point  --proto_msgname=pointpoint  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/pointpoint.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PointPointDesc.h ${PROTOCGEN_FILE_PATH}/PointPointDesc.cpp" --dst=${DESC_STORE_PATH}/

