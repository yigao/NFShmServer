include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/marryconst.bin ${PROTOCGEN_FILE_PATH}/marrybanquet.bin ${PROTOCGEN_FILE_PATH}/marrygear.bin ${PROTOCGEN_FILE_PATH}/marrytimes.bin ${PROTOCGEN_FILE_PATH}/marrywarm.bin ${PROTOCGEN_FILE_PATH}/marrylevelexp.bin 

${PROTOCGEN_FILE_PATH}/marryconst.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marryconst  --excel_sheetname=const  --proto_msgname=marryconst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marryconst.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/marrybanquet.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrybanquet  --excel_sheetname=banquet  --proto_msgname=marrybanquet  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marrybanquet.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/marrygear.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrygear  --excel_sheetname=gear  --proto_msgname=marrygear  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marrygear.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/marrytimes.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrytimes  --excel_sheetname=times  --proto_msgname=marrytimes  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marrytimes.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/marrywarm.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrywarm  --excel_sheetname=warm  --proto_msgname=marrywarm  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marrywarm.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/marrylevelexp.bin:${PROTOCGEN_FILE_PATH}/marry.proto.ds ${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/marry.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_marrylevelexp  --excel_sheetname=levelexp  --proto_msgname=marrylevelexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marrylevelexp.bin" --dst=${GAME_DATA_PATH}/
