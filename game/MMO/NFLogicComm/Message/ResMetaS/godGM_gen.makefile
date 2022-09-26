include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/godGMgodGM.bin 

${GAME_DATA_PATH}/godGMgodGM.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/godGM.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godGM.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godGMgodGM  --excel_sheetname=godGM  --proto_msgname=godGMgodGM  --start_row=4 --out_path=${GAME_DATA_PATH}/

