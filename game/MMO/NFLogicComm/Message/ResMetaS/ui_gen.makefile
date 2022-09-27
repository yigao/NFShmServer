include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/uieffect.bin 

${PROTOCGEN_FILE_PATH}/uieffect.bin:${PROTOCGEN_FILE_PATH}/ui.proto.ds ${RESDB_EXCELMMO_PATH}/ui.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ui.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ui.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_uieffect  --excel_sheetname=effect  --proto_msgname=uieffect  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/uieffect.bin" --dst=${GAME_DATA_PATH}/
