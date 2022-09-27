include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/randomnamemanfirst.bin ${GAME_DATA_PATH}/randomnamemansecond.bin ${GAME_DATA_PATH}/randomnamemanthird.bin ${GAME_DATA_PATH}/randomnamewomanfirst.bin ${GAME_DATA_PATH}/randomnamewomansecond.bin ${GAME_DATA_PATH}/randomnamewomanthird.bin 

${GAME_DATA_PATH}/randomnamemanfirst.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamemanfirst  --excel_sheetname=manfirst  --proto_msgname=randomnamemanfirst  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/randomnamemansecond.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamemansecond  --excel_sheetname=mansecond  --proto_msgname=randomnamemansecond  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/randomnamemanthird.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamemanthird  --excel_sheetname=manthird  --proto_msgname=randomnamemanthird  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/randomnamewomanfirst.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamewomanfirst  --excel_sheetname=womanfirst  --proto_msgname=randomnamewomanfirst  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/randomnamewomansecond.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamewomansecond  --excel_sheetname=womansecond  --proto_msgname=randomnamewomansecond  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/randomnamewomanthird.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamewomanthird  --excel_sheetname=womanthird  --proto_msgname=randomnamewomanthird  --start_row=4 --out_path=${GAME_DATA_PATH}/

