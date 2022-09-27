include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/witchaward.bin ${GAME_DATA_PATH}/witchsummon.bin ${GAME_DATA_PATH}/witchrewardExp.bin 

${GAME_DATA_PATH}/witchaward.bin:${PROTOCGEN_FILE_PATH}/witch.proto.ds ${RESDB_EXCELMMO_PATH}/witch.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/witch.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/witch.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_witchaward  --excel_sheetname=award  --proto_msgname=witchaward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/witchsummon.bin:${PROTOCGEN_FILE_PATH}/witch.proto.ds ${RESDB_EXCELMMO_PATH}/witch.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/witch.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/witch.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_witchsummon  --excel_sheetname=summon  --proto_msgname=witchsummon  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/witchrewardExp.bin:${PROTOCGEN_FILE_PATH}/witch.proto.ds ${RESDB_EXCELMMO_PATH}/witch.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/witch.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/witch.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_witchrewardExp  --excel_sheetname=rewardExp  --proto_msgname=witchrewardExp  --start_row=4 --out_path=${GAME_DATA_PATH}/

