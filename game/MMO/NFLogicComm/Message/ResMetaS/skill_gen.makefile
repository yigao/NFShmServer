include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/skillskill.bin ${GAME_DATA_PATH}/skillbuff.bin 

${GAME_DATA_PATH}/skillskill.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/skill.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_skillskill  --excel_sheetname=skill  --proto_msgname=skillskill  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/skillbuff.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/skill.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_skillbuff  --excel_sheetname=buff  --proto_msgname=skillbuff  --start_row=4 --out_path=${GAME_DATA_PATH}/

