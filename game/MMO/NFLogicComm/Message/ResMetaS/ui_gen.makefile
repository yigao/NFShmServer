include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/uieffect.bin 

${GAME_DATA_PATH}/uieffect.bin:${PROTOCGEN_FILE_PATH}/ui.proto.ds ${RESDB_EXCELMMO_PATH}/ui.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ui.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ui.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_uieffect  --excel_sheetname=effect  --proto_msgname=uieffect  --start_row=4 --out_path=${GAME_DATA_PATH}/

