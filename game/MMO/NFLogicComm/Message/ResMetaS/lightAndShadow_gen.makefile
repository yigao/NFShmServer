include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/lightAndShadowcons.bin ${GAME_DATA_PATH}/lightAndShadowreward.bin 

${GAME_DATA_PATH}/lightAndShadowcons.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_lightAndShadowcons  --excel_sheetname=cons  --proto_msgname=lightAndShadowcons  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/lightAndShadowreward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_lightAndShadowreward  --excel_sheetname=reward  --proto_msgname=lightAndShadowreward  --start_row=4 --out_path=${GAME_DATA_PATH}/

