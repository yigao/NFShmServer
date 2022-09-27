include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/teamteam.bin 

${GAME_DATA_PATH}/teamteam.bin:${PROTOCGEN_FILE_PATH}/team.proto.ds ${RESDB_EXCELMMO_PATH}/team.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/team.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/team.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_teamteam  --excel_sheetname=team  --proto_msgname=teamteam  --start_row=4 --out_path=${GAME_DATA_PATH}/

