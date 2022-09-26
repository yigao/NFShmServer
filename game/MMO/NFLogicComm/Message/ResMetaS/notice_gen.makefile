include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/noticenotice.bin 

${GAME_DATA_PATH}/noticenotice.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/notice.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/notice.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_noticenotice  --excel_sheetname=notice  --proto_msgname=noticenotice  --start_row=4 --out_path=${GAME_DATA_PATH}/

