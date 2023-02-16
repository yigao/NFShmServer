include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_PathPath.bin ${PROTOCGEN_FILE_PATH}/PathPathDesc.h ${PROTOCGEN_FILE_PATH}/PathPathDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_PathPath.bin:${PROTOCGEN_FILE_PATH}/path.proto.ds ${RESDB_EXCELMMO_PATH}/path.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/path.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/path.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PathPath  --excel_sheetname=path  --proto_msgname=E_PathPath  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PathPath.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PathPathDesc.h ${PROTOCGEN_FILE_PATH}/PathPathDesc.cpp" --dst=${DESC_STORE_PATH}/

