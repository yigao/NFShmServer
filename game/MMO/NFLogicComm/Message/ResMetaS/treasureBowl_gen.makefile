include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/treasureBowltreasureBowl.bin 

${GAME_DATA_PATH}/treasureBowltreasureBowl.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/treasureBowl.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasureBowl.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasureBowltreasureBowl  --excel_sheetname=treasureBowl  --proto_msgname=treasureBowltreasureBowl  --start_row=4 --out_path=${GAME_DATA_PATH}/

