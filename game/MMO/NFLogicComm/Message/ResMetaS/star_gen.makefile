include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/starpoint.bin ${GAME_DATA_PATH}/starstar.bin ${GAME_DATA_PATH}/starexp.bin ${GAME_DATA_PATH}/starastrology.bin 

${GAME_DATA_PATH}/starpoint.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/star.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starpoint  --excel_sheetname=point  --proto_msgname=starpoint  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/starstar.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/star.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starstar  --excel_sheetname=star  --proto_msgname=starstar  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/starexp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/star.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starexp  --excel_sheetname=exp  --proto_msgname=starexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/starastrology.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/star.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starastrology  --excel_sheetname=astrology  --proto_msgname=starastrology  --start_row=4 --out_path=${GAME_DATA_PATH}/

