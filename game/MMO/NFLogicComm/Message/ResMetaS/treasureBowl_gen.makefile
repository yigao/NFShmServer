include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/treasureBowltreasureBowl.bin ${PROTOCGEN_FILE_PATH}/TreasurebowlTreasurebowlDesc.h ${PROTOCGEN_FILE_PATH}/TreasurebowlTreasurebowlDesc.cpp 

${PROTOCGEN_FILE_PATH}/treasureBowltreasureBowl.bin:${PROTOCGEN_FILE_PATH}/treasureBowl.proto.ds ${RESDB_EXCELMMO_PATH}/treasureBowl.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasureBowl.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasureBowl.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasureBowltreasureBowl  --excel_sheetname=treasureBowl  --proto_msgname=treasureBowltreasureBowl  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasureBowltreasureBowl.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasurebowlTreasurebowlDesc.h ${PROTOCGEN_FILE_PATH}/TreasurebowlTreasurebowlDesc.cpp" --dst=${DESC_STORE_PATH}/

