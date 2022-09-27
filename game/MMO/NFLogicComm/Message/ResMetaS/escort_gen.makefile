include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/escortescort.bin ${GAME_DATA_PATH}/escortchance.bin ${GAME_DATA_PATH}/escortrewardExp.bin 

${GAME_DATA_PATH}/escortescort.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_escortescort  --excel_sheetname=escort  --proto_msgname=escortescort  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/escortchance.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_escortchance  --excel_sheetname=chance  --proto_msgname=escortchance  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/escortrewardExp.bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_escortrewardExp  --excel_sheetname=rewardExp  --proto_msgname=escortrewardExp  --start_row=4 --out_path=${GAME_DATA_PATH}/

