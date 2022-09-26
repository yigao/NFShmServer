include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/rankingranking.bin ${GAME_DATA_PATH}/rankingdate.bin ${GAME_DATA_PATH}/rankingpkcons.bin 

${GAME_DATA_PATH}/rankingranking.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingranking  --excel_sheetname=ranking  --proto_msgname=rankingranking  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/rankingdate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingdate  --excel_sheetname=date  --proto_msgname=rankingdate  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/rankingpkcons.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingpkcons  --excel_sheetname=pkcons  --proto_msgname=rankingpkcons  --start_row=4 --out_path=${GAME_DATA_PATH}/

