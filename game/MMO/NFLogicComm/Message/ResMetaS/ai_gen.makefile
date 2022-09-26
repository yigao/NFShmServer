include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/aiai.bin 

${GAME_DATA_PATH}/aiai.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/ai.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ai.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_aiai  --excel_sheetname=ai  --proto_msgname=aiai  --start_row=4 --out_path=${GAME_DATA_PATH}/

