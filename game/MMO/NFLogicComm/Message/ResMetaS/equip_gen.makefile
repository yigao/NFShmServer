include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/equipequip.bin ${GAME_DATA_PATH}/equipstrong.bin ${GAME_DATA_PATH}/equipgemfine.bin ${GAME_DATA_PATH}/equipgem.bin ${GAME_DATA_PATH}/equipatt.bin ${GAME_DATA_PATH}/equipsuit.bin ${GAME_DATA_PATH}/equipclear.bin ${GAME_DATA_PATH}/equipstrongexp.bin ${GAME_DATA_PATH}/equipgemfineexp.bin ${GAME_DATA_PATH}/equipclearteam.bin ${GAME_DATA_PATH}/equipawakening.bin ${GAME_DATA_PATH}/equipenchanting.bin ${GAME_DATA_PATH}/equipmarry.bin 

${GAME_DATA_PATH}/equipequip.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipequip  --excel_sheetname=equip  --proto_msgname=equipequip  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipstrong.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrong  --excel_sheetname=strong  --proto_msgname=equipstrong  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipgemfine.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgemfine  --excel_sheetname=gemfine  --proto_msgname=equipgemfine  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipgem.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgem  --excel_sheetname=gem  --proto_msgname=equipgem  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipatt.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipatt  --excel_sheetname=att  --proto_msgname=equipatt  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipsuit.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipsuit  --excel_sheetname=suit  --proto_msgname=equipsuit  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipclear.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipclear  --excel_sheetname=clear  --proto_msgname=equipclear  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipstrongexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrongexp  --excel_sheetname=strongexp  --proto_msgname=equipstrongexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipgemfineexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgemfineexp  --excel_sheetname=gemfineexp  --proto_msgname=equipgemfineexp  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipclearteam.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipclearteam  --excel_sheetname=clearteam  --proto_msgname=equipclearteam  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipawakening.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipawakening  --excel_sheetname=awakening  --proto_msgname=equipawakening  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipenchanting.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipenchanting  --excel_sheetname=enchanting  --proto_msgname=equipenchanting  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/equipmarry.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipmarry  --excel_sheetname=marry  --proto_msgname=equipmarry  --start_row=4 --out_path=${GAME_DATA_PATH}/

