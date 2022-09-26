include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/GMCommandGMCommand.bin 

${GAME_DATA_PATH}/GMCommandGMCommand.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/GMCommand.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GMCommandGMCommand  --excel_sheetname=GMCommand  --proto_msgname=GMCommandGMCommand  --start_row=4 --out_path=${GAME_DATA_PATH}/

