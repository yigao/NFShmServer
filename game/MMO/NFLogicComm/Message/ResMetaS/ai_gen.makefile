include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/aiai.bin 

${PROTOCGEN_FILE_PATH}/aiai.bin:${PROTOCGEN_FILE_PATH}/ai.proto.ds ${RESDB_EXCELMMO_PATH}/ai.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ai.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_aiai  --excel_sheetname=ai  --proto_msgname=aiai  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/aiai.bin" --dst=${GAME_DATA_PATH}/
