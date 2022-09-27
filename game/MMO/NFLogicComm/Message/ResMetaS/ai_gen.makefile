include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/aiai.bin 

${GAME_DATA_PATH}/aiai.bin:${PROTOCGEN_FILE_PATH}/ai.proto.ds ${RESDB_EXCELMMO_PATH}/ai.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ai.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_aiai  --excel_sheetname=ai  --proto_msgname=aiai  --start_row=4 --out_path=${GAME_DATA_PATH}/

