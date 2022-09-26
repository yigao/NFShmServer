include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/handbookhandbook.bin ${GAME_DATA_PATH}/handbookfate.bin ${GAME_DATA_PATH}/handbookattr.bin 

${GAME_DATA_PATH}/handbookhandbook.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/handbook.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/handbook.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_handbookhandbook  --excel_sheetname=handbook  --proto_msgname=handbookhandbook  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/handbookfate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/handbook.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/handbook.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_handbookfate  --excel_sheetname=fate  --proto_msgname=handbookfate  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/handbookattr.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/handbook.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/handbook.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_handbookattr  --excel_sheetname=attr  --proto_msgname=handbookattr  --start_row=4 --out_path=${GAME_DATA_PATH}/

