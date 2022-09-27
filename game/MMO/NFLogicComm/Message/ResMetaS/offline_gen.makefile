include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/offlineoffline.bin ${GAME_DATA_PATH}/offlineitemlist.bin 

${GAME_DATA_PATH}/offlineoffline.bin:${PROTOCGEN_FILE_PATH}/offline.proto.ds ${RESDB_EXCELMMO_PATH}/offline.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/offline.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_offlineoffline  --excel_sheetname=offline  --proto_msgname=offlineoffline  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/offlineitemlist.bin:${PROTOCGEN_FILE_PATH}/offline.proto.ds ${RESDB_EXCELMMO_PATH}/offline.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/offline.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_offlineitemlist  --excel_sheetname=itemlist  --proto_msgname=offlineitemlist  --start_row=4 --out_path=${GAME_DATA_PATH}/

