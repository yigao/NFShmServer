include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/fieldfield.bin ${GAME_DATA_PATH}/fieldreiki.bin ${GAME_DATA_PATH}/fieldexp.bin ${GAME_DATA_PATH}/fieldvalue.bin ${GAME_DATA_PATH}/fieldexpand.bin ${GAME_DATA_PATH}/fieldstong.bin 

${GAME_DATA_PATH}/fieldfield.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/field.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldfield  --excel_sheetname=field  --proto_msgname=fieldfield  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/fieldreiki.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/field.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldreiki  --excel_sheetname=reiki  --proto_msgname=fieldreiki  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/fieldexp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/field.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldexp  --excel_sheetname=exp  --proto_msgname=fieldexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/fieldvalue.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/field.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldvalue  --excel_sheetname=value  --proto_msgname=fieldvalue  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/fieldexpand.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/field.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldexpand  --excel_sheetname=expand  --proto_msgname=fieldexpand  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/fieldstong.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/field.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldstong  --excel_sheetname=stong  --proto_msgname=fieldstong  --start_row=4 --out_path=${GAME_DATA_PATH}/

