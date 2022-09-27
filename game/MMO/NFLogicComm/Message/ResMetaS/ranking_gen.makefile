include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/rankingranking.bin ${PROTOCGEN_FILE_PATH}/rankingdate.bin ${PROTOCGEN_FILE_PATH}/rankingpkcons.bin 

${PROTOCGEN_FILE_PATH}/rankingranking.bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingranking  --excel_sheetname=ranking  --proto_msgname=rankingranking  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rankingranking.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/rankingdate.bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingdate  --excel_sheetname=date  --proto_msgname=rankingdate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rankingdate.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/rankingpkcons.bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rankingpkcons  --excel_sheetname=pkcons  --proto_msgname=rankingpkcons  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rankingpkcons.bin" --dst=${GAME_DATA_PATH}/
