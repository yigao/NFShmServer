include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/marryconst.bin ${GAME_DATA_PATH}/marrybanquet.bin ${GAME_DATA_PATH}/marrygear.bin ${GAME_DATA_PATH}/marrytimes.bin ${GAME_DATA_PATH}/marrywarm.bin ${GAME_DATA_PATH}/marrylevelexp.bin 

${GAME_DATA_PATH}/marryconst.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marryconst  --excel_sheetname=const  --proto_msgname=marryconst  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/marrybanquet.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrybanquet  --excel_sheetname=banquet  --proto_msgname=marrybanquet  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/marrygear.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrygear  --excel_sheetname=gear  --proto_msgname=marrygear  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/marrytimes.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrytimes  --excel_sheetname=times  --proto_msgname=marrytimes  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/marrywarm.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrywarm  --excel_sheetname=warm  --proto_msgname=marrywarm  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/marrylevelexp.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrylevelexp  --excel_sheetname=levelexp  --proto_msgname=marrylevelexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

