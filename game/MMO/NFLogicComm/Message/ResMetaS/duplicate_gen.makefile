include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/duplicateduplicate.bin ${PROTOCGEN_FILE_PATH}/duplicateconstant.bin ${PROTOCGEN_FILE_PATH}/duplicateendlessMaze.bin ${PROTOCGEN_FILE_PATH}/duplicatetowerReward.bin ${PROTOCGEN_FILE_PATH}/duplicatedungeonReward.bin ${PROTOCGEN_FILE_PATH}/duplicategroup.bin ${PROTOCGEN_FILE_PATH}/duplicatesweepmonsterNum.bin ${PROTOCGEN_FILE_PATH}/duplicateGuildbosstime.bin ${PROTOCGEN_FILE_PATH}/duplicateGuildboss.bin ${PROTOCGEN_FILE_PATH}/duplicateGuildDuplicate.bin 

${PROTOCGEN_FILE_PATH}/duplicateduplicate.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateduplicate  --excel_sheetname=duplicate  --proto_msgname=duplicateduplicate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicateduplicate.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicateconstant.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateconstant  --excel_sheetname=constant  --proto_msgname=duplicateconstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicateconstant.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicateendlessMaze.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateendlessMaze  --excel_sheetname=endlessMaze  --proto_msgname=duplicateendlessMaze  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicateendlessMaze.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicatetowerReward.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicatetowerReward  --excel_sheetname=towerReward  --proto_msgname=duplicatetowerReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicatetowerReward.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicatedungeonReward.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicatedungeonReward  --excel_sheetname=dungeonReward  --proto_msgname=duplicatedungeonReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicatedungeonReward.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicategroup.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicategroup  --excel_sheetname=group  --proto_msgname=duplicategroup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicategroup.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicatesweepmonsterNum.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicatesweepmonsterNum  --excel_sheetname=sweepmonsterNum  --proto_msgname=duplicatesweepmonsterNum  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicatesweepmonsterNum.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicateGuildbosstime.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateGuildbosstime  --excel_sheetname=Guildbosstime  --proto_msgname=duplicateGuildbosstime  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicateGuildbosstime.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicateGuildboss.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateGuildboss  --excel_sheetname=Guildboss  --proto_msgname=duplicateGuildboss  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicateGuildboss.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/duplicateGuildDuplicate.bin:${PROTOCGEN_FILE_PATH}/duplicate.proto.ds ${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/duplicate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duplicateGuildDuplicate  --excel_sheetname=GuildDuplicate  --proto_msgname=duplicateGuildDuplicate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicateGuildDuplicate.bin" --dst=${GAME_DATA_PATH}/