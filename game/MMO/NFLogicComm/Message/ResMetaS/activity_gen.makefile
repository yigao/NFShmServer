include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/activitydaily.bin ${GAME_DATA_PATH}/activityactivitynotice.bin ${GAME_DATA_PATH}/activityscuffle.bin ${GAME_DATA_PATH}/activitychaosDragons.bin ${GAME_DATA_PATH}/activitycircus.bin ${GAME_DATA_PATH}/activitycircusNum.bin ${GAME_DATA_PATH}/activitycircusDan.bin ${GAME_DATA_PATH}/activitymathrule.bin ${GAME_DATA_PATH}/activitymathreward.bin ${GAME_DATA_PATH}/activitygvgConst.bin ${GAME_DATA_PATH}/activitygvgRankReward.bin ${GAME_DATA_PATH}/activitygvgReward.bin ${GAME_DATA_PATH}/activityworldTreasureConst.bin ${GAME_DATA_PATH}/activityworldTreasureMap.bin ${GAME_DATA_PATH}/activityworldTreasureMonster.bin ${GAME_DATA_PATH}/activitylosttempleConstant.bin 

${GAME_DATA_PATH}/activitydaily.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitydaily  --excel_sheetname=daily  --proto_msgname=activitydaily  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activityactivitynotice.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityactivitynotice  --excel_sheetname=activitynotice  --proto_msgname=activityactivitynotice  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activityscuffle.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityscuffle  --excel_sheetname=scuffle  --proto_msgname=activityscuffle  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitychaosDragons.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitychaosDragons  --excel_sheetname=chaosDragons  --proto_msgname=activitychaosDragons  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitycircus.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitycircus  --excel_sheetname=circus  --proto_msgname=activitycircus  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitycircusNum.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitycircusNum  --excel_sheetname=circusNum  --proto_msgname=activitycircusNum  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitycircusDan.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitycircusDan  --excel_sheetname=circusDan  --proto_msgname=activitycircusDan  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitymathrule.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitymathrule  --excel_sheetname=mathrule  --proto_msgname=activitymathrule  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitymathreward.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitymathreward  --excel_sheetname=mathreward  --proto_msgname=activitymathreward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitygvgConst.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitygvgConst  --excel_sheetname=gvgConst  --proto_msgname=activitygvgConst  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitygvgRankReward.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitygvgRankReward  --excel_sheetname=gvgRankReward  --proto_msgname=activitygvgRankReward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitygvgReward.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitygvgReward  --excel_sheetname=gvgReward  --proto_msgname=activitygvgReward  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activityworldTreasureConst.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityworldTreasureConst  --excel_sheetname=worldTreasureConst  --proto_msgname=activityworldTreasureConst  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activityworldTreasureMap.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityworldTreasureMap  --excel_sheetname=worldTreasureMap  --proto_msgname=activityworldTreasureMap  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activityworldTreasureMonster.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityworldTreasureMonster  --excel_sheetname=worldTreasureMonster  --proto_msgname=activityworldTreasureMonster  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/activitylosttempleConstant.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitylosttempleConstant  --excel_sheetname=losttempleConstant  --proto_msgname=activitylosttempleConstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

