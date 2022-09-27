include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/skillskill.bin ${GAME_DATA_PATH}/skillbuff.bin 

${GAME_DATA_PATH}/skillskill.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_skillskill  --excel_sheetname=skill  --proto_msgname=skillskill  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/skillbuff.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_skillbuff  --excel_sheetname=buff  --proto_msgname=skillbuff  --start_row=4 --out_path=${GAME_DATA_PATH}/

