include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}

${RESDB_DESC_BIN}:${RESDB_META_DESCRIPTOR} ${RESDB_DESC_EXCEL}
	for xml in $(RESDB_DESC_BIN3);do\
		echo $$xml;\
		${EXCEL2BIN} --excel=${RESDB_EXCEL_PATH}/$$xml.xls --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff --proto_sheet_msgname=Sheet_$$xml --excel_sheetname=$$xml --proto_msgname=$$xml --start_row=3 --out_path=${GAME_DATA_PATH}/;\
	done
