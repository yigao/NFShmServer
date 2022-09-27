include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/rechargerecharge.bin 

${PROTOCGEN_FILE_PATH}/rechargerecharge.bin:${PROTOCGEN_FILE_PATH}/recharge.proto.ds ${RESDB_EXCELMMO_PATH}/recharge.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/recharge.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/recharge.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rechargerecharge  --excel_sheetname=recharge  --proto_msgname=rechargerecharge  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargerecharge.bin" --dst=${GAME_DATA_PATH}/
