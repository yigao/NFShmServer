include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/dropdrop.bin 

${GAME_DATA_PATH}/dropdrop.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/drop.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/drop.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dropdrop  --excel_sheetname=drop  --proto_msgname=dropdrop  --start_row=4 --out_path=${GAME_DATA_PATH}/

