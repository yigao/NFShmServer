include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_ConstantConstant.bin ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.h ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_ConstantConstant.bin:${PROTOCGEN_FILE_PATH}/constant.proto.ds ${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/constant.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ConstantConstant  --excel_sheetname=constant  --proto_msgname=E_ConstantConstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ConstantConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.h ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.cpp" --dst=${DESC_STORE_PATH}/

