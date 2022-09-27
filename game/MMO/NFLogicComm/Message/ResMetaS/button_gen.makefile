include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/buttonbutton.bin 

${PROTOCGEN_FILE_PATH}/buttonbutton.bin:${PROTOCGEN_FILE_PATH}/button.proto.ds ${RESDB_EXCELMMO_PATH}/button.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/button.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/button.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_buttonbutton  --excel_sheetname=button  --proto_msgname=buttonbutton  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/buttonbutton.bin" --dst=${GAME_DATA_PATH}/
