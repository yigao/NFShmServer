include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/teamteam.bin 

${PROTOCGEN_FILE_PATH}/teamteam.bin:${PROTOCGEN_FILE_PATH}/team.proto.ds ${RESDB_EXCELMMO_PATH}/team.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/team.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/team.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_teamteam  --excel_sheetname=team  --proto_msgname=teamteam  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/teamteam.bin" --dst=${GAME_DATA_PATH}/
