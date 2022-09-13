include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}
${GAME_DATA_PATH}/ConstDesc.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCEL_PATH}/Constant.xls
	${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/Constant.xls --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ConstDesc --excel_sheetname=Constant --proto_msgname=ConstDesc --start_row=3 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/NameDesc.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCEL_PATH}/NameDesc.xls
	${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/NameDesc.xls --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_NameDesc --excel_sheetname=NameDesc --proto_msgname=NameDesc --start_row=3 --out_path=${GAME_DATA_PATH}/
