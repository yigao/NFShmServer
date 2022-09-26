include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/conditionshopconditionshop.bin 

${GAME_DATA_PATH}/conditionshopconditionshop.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/conditionshop.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/conditionshop.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_conditionshopconditionshop  --excel_sheetname=conditionshop  --proto_msgname=conditionshopconditionshop  --start_row=4 --out_path=${GAME_DATA_PATH}/

