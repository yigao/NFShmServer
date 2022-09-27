include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/GMCommandGMCommand.bin 

${GAME_DATA_PATH}/GMCommandGMCommand.bin:${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds ${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMCommand.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMCommandGMCommand  --excel_sheetname=GMCommand  --proto_msgname=GMCommandGMCommand  --start_row=4 --out_path=${GAME_DATA_PATH}/

