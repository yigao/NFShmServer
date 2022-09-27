include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/godpowergodpower.bin ${GAME_DATA_PATH}/godpowerskillupdate.bin 

${GAME_DATA_PATH}/godpowergodpower.bin:${PROTOCGEN_FILE_PATH}/godpower.proto.ds ${RESDB_EXCELMMO_PATH}/godpower.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godpower.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godpower.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godpowergodpower  --excel_sheetname=godpower  --proto_msgname=godpowergodpower  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/godpowerskillupdate.bin:${PROTOCGEN_FILE_PATH}/godpower.proto.ds ${RESDB_EXCELMMO_PATH}/godpower.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godpower.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godpower.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godpowerskillupdate  --excel_sheetname=skillupdate  --proto_msgname=godpowerskillupdate  --start_row=4 --out_path=${GAME_DATA_PATH}/

