include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/elementelement.bin ${GAME_DATA_PATH}/elementfragment.bin ${GAME_DATA_PATH}/elementelementUI.bin 

${GAME_DATA_PATH}/elementelement.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/element.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/element.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_elementelement  --excel_sheetname=element  --proto_msgname=elementelement  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/elementfragment.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/element.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/element.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_elementfragment  --excel_sheetname=fragment  --proto_msgname=elementfragment  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/elementelementUI.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/element.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/element.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_elementelementUI  --excel_sheetname=elementUI  --proto_msgname=elementelementUI  --start_row=4 --out_path=${GAME_DATA_PATH}/

