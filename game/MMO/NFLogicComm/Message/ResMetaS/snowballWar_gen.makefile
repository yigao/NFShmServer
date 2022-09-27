include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/snowballWarcons.bin 

${GAME_DATA_PATH}/snowballWarcons.bin:${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds ${RESDB_EXCELMMO_PATH}/snowballWar.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/snowballWar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_snowballWarcons  --excel_sheetname=cons  --proto_msgname=snowballWarcons  --start_row=4 --out_path=${GAME_DATA_PATH}/

