include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/snowballWarcons.bin ${PROTOCGEN_FILE_PATH}/SnowballwarConsDesc.h ${PROTOCGEN_FILE_PATH}/SnowballwarConsDesc.cpp 

${PROTOCGEN_FILE_PATH}/snowballWarcons.bin:${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds ${RESDB_EXCELMMO_PATH}/snowballWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/snowballWar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_snowballWarcons  --excel_sheetname=cons  --proto_msgname=snowballWarcons  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/snowballWarcons.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SnowballwarConsDesc.h ${PROTOCGEN_FILE_PATH}/SnowballwarConsDesc.cpp" --dst=${DESC_STORE_PATH}/

