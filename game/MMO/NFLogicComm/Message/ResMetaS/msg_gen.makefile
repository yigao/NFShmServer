include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/msgphpmsg.bin 

${GAME_DATA_PATH}/msgphpmsg.bin:${PROTOCGEN_FILE_PATH}/msg.proto.ds ${RESDB_EXCELMMO_PATH}/msg.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/msg.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/msg.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_msgphpmsg  --excel_sheetname=phpmsg  --proto_msgname=msgphpmsg  --start_row=4 --out_path=${GAME_DATA_PATH}/

