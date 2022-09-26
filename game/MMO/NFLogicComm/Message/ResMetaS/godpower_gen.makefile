include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/godpowergodpower.bin ${GAME_DATA_PATH}/godpowerskillupdate.bin 

${GAME_DATA_PATH}/godpowergodpower.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/godpower.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godpower.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godpowergodpower  --excel_sheetname=godpower  --proto_msgname=godpowergodpower  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/godpowerskillupdate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/godpower.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godpower.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godpowerskillupdate  --excel_sheetname=skillupdate  --proto_msgname=godpowerskillupdate  --start_row=4 --out_path=${GAME_DATA_PATH}/

