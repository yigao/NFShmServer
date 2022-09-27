include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/warlandconstant.bin ${GAME_DATA_PATH}/warlandmultiKill.bin ${GAME_DATA_PATH}/warlandrankreward.bin 

${GAME_DATA_PATH}/warlandconstant.bin:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/warland.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_warlandconstant  --excel_sheetname=constant  --proto_msgname=warlandconstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/warlandmultiKill.bin:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/warland.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_warlandmultiKill  --excel_sheetname=multiKill  --proto_msgname=warlandmultiKill  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/warlandrankreward.bin:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/warland.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_warlandrankreward  --excel_sheetname=rankreward  --proto_msgname=warlandrankreward  --start_row=4 --out_path=${GAME_DATA_PATH}/

