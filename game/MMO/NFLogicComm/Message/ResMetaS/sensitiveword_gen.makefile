include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/sensitivewordsensitive_word.bin ${GAME_DATA_PATH}/sensitivewordrolesensitive.bin 

${GAME_DATA_PATH}/sensitivewordsensitive_word.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_sensitivewordsensitive_word  --excel_sheetname=sensitive_word  --proto_msgname=sensitivewordsensitive_word  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/sensitivewordrolesensitive.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_sensitivewordrolesensitive  --excel_sheetname=rolesensitive  --proto_msgname=sensitivewordrolesensitive  --start_row=4 --out_path=${GAME_DATA_PATH}/

