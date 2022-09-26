include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/duplicateduplicate.bin ${GAME_DATA_PATH}/duplicateconstant.bin ${GAME_DATA_PATH}/duplicateendlessMaze.bin ${GAME_DATA_PATH}/duplicatetowerReward.bin ${GAME_DATA_PATH}/duplicatedungeonReward.bin ${GAME_DATA_PATH}/duplicategroup.bin ${GAME_DATA_PATH}/duplicatesweepmonsterNum.bin ${GAME_DATA_PATH}/duplicateGuildbosstime.bin ${GAME_DATA_PATH}/duplicateGuildboss.bin ${GAME_DATA_PATH}/duplicateGuildDuplicate.bin 

${GAME_DATA_PATH}/duplicateduplicate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateduplicate  --excel_sheetname=duplicate  --proto_msgname=duplicateduplicate  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicateconstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateconstant  --excel_sheetname=constant  --proto_msgname=duplicateconstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicateendlessMaze.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateendlessMaze  --excel_sheetname=endlessMaze  --proto_msgname=duplicateendlessMaze  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicatetowerReward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicatetowerReward  --excel_sheetname=towerReward  --proto_msgname=duplicatetowerReward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicatedungeonReward.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicatedungeonReward  --excel_sheetname=dungeonReward  --proto_msgname=duplicatedungeonReward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicategroup.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicategroup  --excel_sheetname=group  --proto_msgname=duplicategroup  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicatesweepmonsterNum.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicatesweepmonsterNum  --excel_sheetname=sweepmonsterNum  --proto_msgname=duplicatesweepmonsterNum  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicateGuildbosstime.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateGuildbosstime  --excel_sheetname=Guildbosstime  --proto_msgname=duplicateGuildbosstime  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicateGuildboss.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateGuildboss  --excel_sheetname=Guildboss  --proto_msgname=duplicateGuildboss  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/duplicateGuildDuplicate.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateGuildDuplicate  --excel_sheetname=GuildDuplicate  --proto_msgname=duplicateGuildDuplicate  --start_row=4 --out_path=${GAME_DATA_PATH}/

