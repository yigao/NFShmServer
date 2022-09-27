include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/godHoodgodHood.bin ${PROTOCGEN_FILE_PATH}/godHoodexp.bin 

${PROTOCGEN_FILE_PATH}/godHoodgodHood.bin:${PROTOCGEN_FILE_PATH}/godHood.proto.ds ${RESDB_EXCELMMO_PATH}/godHood.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godHood.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godHood.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godHoodgodHood  --excel_sheetname=godHood  --proto_msgname=godHoodgodHood  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godHoodgodHood.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/godHoodexp.bin:${PROTOCGEN_FILE_PATH}/godHood.proto.ds ${RESDB_EXCELMMO_PATH}/godHood.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godHood.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godHood.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godHoodexp  --excel_sheetname=exp  --proto_msgname=godHoodexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godHoodexp.bin" --dst=${GAME_DATA_PATH}/
