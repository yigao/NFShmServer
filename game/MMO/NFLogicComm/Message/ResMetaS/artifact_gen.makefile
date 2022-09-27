include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/artifactartifact.bin 

${GAME_DATA_PATH}/artifactartifact.bin:${PROTOCGEN_FILE_PATH}/artifact.proto.ds ${RESDB_EXCELMMO_PATH}/artifact.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/artifact.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/artifact.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_artifactartifact  --excel_sheetname=artifact  --proto_msgname=artifactartifact  --start_row=4 --out_path=${GAME_DATA_PATH}/

