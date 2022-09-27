include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/rankingranking.bin ${GAME_DATA_PATH}/rankingdate.bin ${GAME_DATA_PATH}/rankingpkcons.bin 

${GAME_DATA_PATH}/rankingranking.bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingranking  --excel_sheetname=ranking  --proto_msgname=rankingranking  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/rankingdate.bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingdate  --excel_sheetname=date  --proto_msgname=rankingdate  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/rankingpkcons.bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingpkcons  --excel_sheetname=pkcons  --proto_msgname=rankingpkcons  --start_row=4 --out_path=${GAME_DATA_PATH}/

