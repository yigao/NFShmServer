include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/attributeattribute.bin ${GAME_DATA_PATH}/attributesuppress.bin ${GAME_DATA_PATH}/attributepowersup.bin 

${GAME_DATA_PATH}/attributeattribute.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_attributeattribute  --excel_sheetname=attribute  --proto_msgname=attributeattribute  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/attributesuppress.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_attributesuppress  --excel_sheetname=suppress  --proto_msgname=attributesuppress  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/attributepowersup.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_attributepowersup  --excel_sheetname=powersup  --proto_msgname=attributepowersup  --start_row=4 --out_path=${GAME_DATA_PATH}/

