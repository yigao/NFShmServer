include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/colPointscolPoints.bin ${PROTOCGEN_FILE_PATH}/ColpointsColpointsDesc.h ${PROTOCGEN_FILE_PATH}/ColpointsColpointsDesc.cpp ${PROTOCGEN_FILE_PATH}/colPointstask.bin ${PROTOCGEN_FILE_PATH}/ColpointsTaskDesc.h ${PROTOCGEN_FILE_PATH}/ColpointsTaskDesc.cpp 

${PROTOCGEN_FILE_PATH}/colPointscolPoints.bin:${PROTOCGEN_FILE_PATH}/colPoints.proto.ds ${RESDB_EXCELMMO_PATH}/colPoints.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/colPoints.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/colPoints.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_colPointscolPoints  --excel_sheetname=colPoints  --proto_msgname=colPointscolPoints  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/colPointscolPoints.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ColpointsColpointsDesc.h ${PROTOCGEN_FILE_PATH}/ColpointsColpointsDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/colPointstask.bin:${PROTOCGEN_FILE_PATH}/colPoints.proto.ds ${RESDB_EXCELMMO_PATH}/colPoints.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/colPoints.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/colPoints.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_colPointstask  --excel_sheetname=task  --proto_msgname=colPointstask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/colPointstask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ColpointsTaskDesc.h ${PROTOCGEN_FILE_PATH}/ColpointsTaskDesc.cpp" --dst=${DESC_STORE_PATH}/

