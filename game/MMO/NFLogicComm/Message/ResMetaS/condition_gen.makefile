include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/conditioncondition.bin 

${GAME_DATA_PATH}/conditioncondition.bin:${PROTOCGEN_FILE_PATH}/condition.proto.ds ${RESDB_EXCELMMO_PATH}/condition.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/condition.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/condition.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_conditioncondition  --excel_sheetname=condition  --proto_msgname=conditioncondition  --start_row=4 --out_path=${GAME_DATA_PATH}/

