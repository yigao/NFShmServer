include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/dropdrop.bin ${PROTOCGEN_FILE_PATH}/DropDropDesc.h ${PROTOCGEN_FILE_PATH}/DropDropDesc.cpp 

${PROTOCGEN_FILE_PATH}/dropdrop.bin:${PROTOCGEN_FILE_PATH}/drop.proto.ds ${RESDB_EXCELMMO_PATH}/drop.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/drop.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/drop.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dropdrop  --excel_sheetname=drop  --proto_msgname=dropdrop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dropdrop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DropDropDesc.h ${PROTOCGEN_FILE_PATH}/DropDropDesc.cpp" --dst=${DESC_STORE_PATH}/

