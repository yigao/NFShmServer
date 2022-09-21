include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}

${GAME_DATA_PATH}/ConstDesc.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCEL_PATH}/ConstDesc.xls
	${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/ConstDesc.xls --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ConstDesc --excel_sheetname=ConstDesc --proto_msgname=ConstDesc --start_row=3 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/NameDesc.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCEL_PATH}/NameDesc.xls
	${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/NameDesc.xls --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_NameDesc --excel_sheetname=NameDesc --proto_msgname=NameDesc --start_row=3 --out_path=${GAME_DATA_PATH}/

#${RESDB_BIN_FILE}:${RESDB_META_DESCRIPTOR} ${RESDB_DESC_EXCEL}
#	mkdir -p ${GAME_DATA_PATH}
#	for xml in $(RESDB_DESC_BIN3);do\
#		echo $$xml;\
		#${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/$$xml.xls --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff --proto_sheet_msgname=Sheet_$$xml --excel_sheetname=$$xml --proto_msgname=$$xml --start_row=3 --out_path=${GAME_DATA_PATH}/;\
#	done
