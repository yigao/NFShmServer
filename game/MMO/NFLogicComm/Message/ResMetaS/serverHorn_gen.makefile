include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/serverHornserverHorn.bin 

${GAME_DATA_PATH}/serverHornserverHorn.bin:${PROTOCGEN_FILE_PATH}/serverHorn.proto.ds ${RESDB_EXCELMMO_PATH}/serverHorn.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/serverHorn.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/serverHorn.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_serverHornserverHorn  --excel_sheetname=serverHorn  --proto_msgname=serverHornserverHorn  --start_row=4 --out_path=${GAME_DATA_PATH}/

