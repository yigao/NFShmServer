include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/manorconstants.bin ${GAME_DATA_PATH}/manoritemCost.bin ${GAME_DATA_PATH}/manormanorlist.bin ${GAME_DATA_PATH}/manorproduct.bin ${GAME_DATA_PATH}/manorbuild.bin ${GAME_DATA_PATH}/manorbuildUp.bin ${GAME_DATA_PATH}/manoregg.bin ${GAME_DATA_PATH}/manorpatBeast.bin ${GAME_DATA_PATH}/manorpatBeastUP.bin ${GAME_DATA_PATH}/manorbuildBuff.bin ${GAME_DATA_PATH}/manorshop.bin ${GAME_DATA_PATH}/manorbuildAdd.bin ${GAME_DATA_PATH}/manorlog.bin 

${GAME_DATA_PATH}/manorconstants.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorconstants  --excel_sheetname=constants  --proto_msgname=manorconstants  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manoritemCost.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manoritemCost  --excel_sheetname=itemCost  --proto_msgname=manoritemCost  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manormanorlist.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manormanorlist  --excel_sheetname=manorlist  --proto_msgname=manormanorlist  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorproduct.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorproduct  --excel_sheetname=product  --proto_msgname=manorproduct  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorbuild.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuild  --excel_sheetname=build  --proto_msgname=manorbuild  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorbuildUp.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuildUp  --excel_sheetname=buildUp  --proto_msgname=manorbuildUp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manoregg.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manoregg  --excel_sheetname=egg  --proto_msgname=manoregg  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorpatBeast.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorpatBeast  --excel_sheetname=patBeast  --proto_msgname=manorpatBeast  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorpatBeastUP.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorpatBeastUP  --excel_sheetname=patBeastUP  --proto_msgname=manorpatBeastUP  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorbuildBuff.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuildBuff  --excel_sheetname=buildBuff  --proto_msgname=manorbuildBuff  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorshop.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorshop  --excel_sheetname=shop  --proto_msgname=manorshop  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorbuildAdd.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorbuildAdd  --excel_sheetname=buildAdd  --proto_msgname=manorbuildAdd  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/manorlog.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/manor.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/manor.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_manorlog  --excel_sheetname=log  --proto_msgname=manorlog  --start_row=4 --out_path=${GAME_DATA_PATH}/

