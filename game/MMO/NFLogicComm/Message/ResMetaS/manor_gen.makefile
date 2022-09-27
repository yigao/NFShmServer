include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/manorconstants.bin ${PROTOCGEN_FILE_PATH}/manoritemCost.bin ${PROTOCGEN_FILE_PATH}/manormanorlist.bin ${PROTOCGEN_FILE_PATH}/manorproduct.bin ${PROTOCGEN_FILE_PATH}/manorbuild.bin ${PROTOCGEN_FILE_PATH}/manorbuildUp.bin ${PROTOCGEN_FILE_PATH}/manoregg.bin ${PROTOCGEN_FILE_PATH}/manorpatBeast.bin ${PROTOCGEN_FILE_PATH}/manorpatBeastUP.bin ${PROTOCGEN_FILE_PATH}/manorbuildBuff.bin ${PROTOCGEN_FILE_PATH}/manorshop.bin ${PROTOCGEN_FILE_PATH}/manorbuildAdd.bin ${PROTOCGEN_FILE_PATH}/manorlog.bin 

${PROTOCGEN_FILE_PATH}/manorconstants.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorconstants  --excel_sheetname=constants  --proto_msgname=manorconstants  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorconstants.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manoritemCost.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manoritemCost  --excel_sheetname=itemCost  --proto_msgname=manoritemCost  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manoritemCost.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manormanorlist.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manormanorlist  --excel_sheetname=manorlist  --proto_msgname=manormanorlist  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manormanorlist.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorproduct.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorproduct  --excel_sheetname=product  --proto_msgname=manorproduct  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorproduct.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorbuild.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuild  --excel_sheetname=build  --proto_msgname=manorbuild  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorbuild.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorbuildUp.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuildUp  --excel_sheetname=buildUp  --proto_msgname=manorbuildUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorbuildUp.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manoregg.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manoregg  --excel_sheetname=egg  --proto_msgname=manoregg  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manoregg.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorpatBeast.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorpatBeast  --excel_sheetname=patBeast  --proto_msgname=manorpatBeast  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorpatBeast.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorpatBeastUP.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorpatBeastUP  --excel_sheetname=patBeastUP  --proto_msgname=manorpatBeastUP  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorpatBeastUP.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorbuildBuff.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuildBuff  --excel_sheetname=buildBuff  --proto_msgname=manorbuildBuff  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorbuildBuff.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorshop.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorshop  --excel_sheetname=shop  --proto_msgname=manorshop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorshop.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorbuildAdd.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuildAdd  --excel_sheetname=buildAdd  --proto_msgname=manorbuildAdd  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorbuildAdd.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/manorlog.bin:${PROTOCGEN_FILE_PATH}/manor.proto.ds ${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorlog  --excel_sheetname=log  --proto_msgname=manorlog  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manorlog.bin" --dst=${GAME_DATA_PATH}/
