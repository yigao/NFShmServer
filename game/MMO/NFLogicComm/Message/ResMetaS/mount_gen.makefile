include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/mountmount.bin ${GAME_DATA_PATH}/mountstarUp.bin 

${GAME_DATA_PATH}/mountmount.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mountmount  --excel_sheetname=mount  --proto_msgname=mountmount  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/mountstarUp.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mountstarUp  --excel_sheetname=starUp  --proto_msgname=mountstarUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

