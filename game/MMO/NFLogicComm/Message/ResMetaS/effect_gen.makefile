include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/effecteffect.bin 

${GAME_DATA_PATH}/effecteffect.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/effect.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/effect.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_effecteffect  --excel_sheetname=effect  --proto_msgname=effecteffect  --start_row=4 --out_path=${GAME_DATA_PATH}/

