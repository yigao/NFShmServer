include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/itemitem.bin 

${PROTOCGEN_FILE_PATH}/itemitem.bin:${PROTOCGEN_FILE_PATH}/item.proto.ds ${RESDB_EXCELMMO_PATH}/item.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/item.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/item.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_itemitem  --excel_sheetname=item  --proto_msgname=itemitem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/itemitem.bin" --dst=${GAME_DATA_PATH}/
