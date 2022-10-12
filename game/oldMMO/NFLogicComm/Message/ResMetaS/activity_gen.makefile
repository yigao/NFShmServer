include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/activitydaily.bin ${PROTOCGEN_FILE_PATH}/ActivityDailyDesc.h ${PROTOCGEN_FILE_PATH}/ActivityDailyDesc.cpp ${PROTOCGEN_FILE_PATH}/activityactivitynotice.bin ${PROTOCGEN_FILE_PATH}/ActivityActivitynoticeDesc.h ${PROTOCGEN_FILE_PATH}/ActivityActivitynoticeDesc.cpp ${PROTOCGEN_FILE_PATH}/activityscuffle.bin ${PROTOCGEN_FILE_PATH}/ActivityScuffleDesc.h ${PROTOCGEN_FILE_PATH}/ActivityScuffleDesc.cpp ${PROTOCGEN_FILE_PATH}/activitychaosDragons.bin ${PROTOCGEN_FILE_PATH}/ActivityChaosdragonsDesc.h ${PROTOCGEN_FILE_PATH}/ActivityChaosdragonsDesc.cpp ${PROTOCGEN_FILE_PATH}/activitycircus.bin ${PROTOCGEN_FILE_PATH}/ActivityCircusDesc.h ${PROTOCGEN_FILE_PATH}/ActivityCircusDesc.cpp ${PROTOCGEN_FILE_PATH}/activitycircusNum.bin ${PROTOCGEN_FILE_PATH}/ActivityCircusnumDesc.h ${PROTOCGEN_FILE_PATH}/ActivityCircusnumDesc.cpp ${PROTOCGEN_FILE_PATH}/activitycircusDan.bin ${PROTOCGEN_FILE_PATH}/ActivityCircusdanDesc.h ${PROTOCGEN_FILE_PATH}/ActivityCircusdanDesc.cpp ${PROTOCGEN_FILE_PATH}/activitymathrule.bin ${PROTOCGEN_FILE_PATH}/ActivityMathruleDesc.h ${PROTOCGEN_FILE_PATH}/ActivityMathruleDesc.cpp ${PROTOCGEN_FILE_PATH}/activitymathreward.bin ${PROTOCGEN_FILE_PATH}/ActivityMathrewardDesc.h ${PROTOCGEN_FILE_PATH}/ActivityMathrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/activitygvgConst.bin ${PROTOCGEN_FILE_PATH}/ActivityGvgconstDesc.h ${PROTOCGEN_FILE_PATH}/ActivityGvgconstDesc.cpp ${PROTOCGEN_FILE_PATH}/activitygvgRankReward.bin ${PROTOCGEN_FILE_PATH}/ActivityGvgrankrewardDesc.h ${PROTOCGEN_FILE_PATH}/ActivityGvgrankrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/activitygvgReward.bin ${PROTOCGEN_FILE_PATH}/ActivityGvgrewardDesc.h ${PROTOCGEN_FILE_PATH}/ActivityGvgrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/activityworldTreasureConst.bin ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasureconstDesc.h ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasureconstDesc.cpp ${PROTOCGEN_FILE_PATH}/activityworldTreasureMap.bin ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremapDesc.h ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremapDesc.cpp ${PROTOCGEN_FILE_PATH}/activityworldTreasureMonster.bin ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremonsterDesc.h ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremonsterDesc.cpp ${PROTOCGEN_FILE_PATH}/activitylosttempleConstant.bin ${PROTOCGEN_FILE_PATH}/ActivityLosttempleconstantDesc.h ${PROTOCGEN_FILE_PATH}/ActivityLosttempleconstantDesc.cpp 

${PROTOCGEN_FILE_PATH}/activitydaily.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitydaily  --excel_sheetname=daily  --proto_msgname=activitydaily  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitydaily.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityDailyDesc.h ${PROTOCGEN_FILE_PATH}/ActivityDailyDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activityactivitynotice.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityactivitynotice  --excel_sheetname=activitynotice  --proto_msgname=activityactivitynotice  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activityactivitynotice.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityActivitynoticeDesc.h ${PROTOCGEN_FILE_PATH}/ActivityActivitynoticeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activityscuffle.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityscuffle  --excel_sheetname=scuffle  --proto_msgname=activityscuffle  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activityscuffle.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityScuffleDesc.h ${PROTOCGEN_FILE_PATH}/ActivityScuffleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitychaosDragons.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitychaosDragons  --excel_sheetname=chaosDragons  --proto_msgname=activitychaosDragons  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitychaosDragons.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityChaosdragonsDesc.h ${PROTOCGEN_FILE_PATH}/ActivityChaosdragonsDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitycircus.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitycircus  --excel_sheetname=circus  --proto_msgname=activitycircus  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitycircus.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityCircusDesc.h ${PROTOCGEN_FILE_PATH}/ActivityCircusDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitycircusNum.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitycircusNum  --excel_sheetname=circusNum  --proto_msgname=activitycircusNum  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitycircusNum.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityCircusnumDesc.h ${PROTOCGEN_FILE_PATH}/ActivityCircusnumDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitycircusDan.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitycircusDan  --excel_sheetname=circusDan  --proto_msgname=activitycircusDan  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitycircusDan.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityCircusdanDesc.h ${PROTOCGEN_FILE_PATH}/ActivityCircusdanDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitymathrule.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitymathrule  --excel_sheetname=mathrule  --proto_msgname=activitymathrule  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitymathrule.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityMathruleDesc.h ${PROTOCGEN_FILE_PATH}/ActivityMathruleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitymathreward.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitymathreward  --excel_sheetname=mathreward  --proto_msgname=activitymathreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitymathreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityMathrewardDesc.h ${PROTOCGEN_FILE_PATH}/ActivityMathrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitygvgConst.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitygvgConst  --excel_sheetname=gvgConst  --proto_msgname=activitygvgConst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitygvgConst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityGvgconstDesc.h ${PROTOCGEN_FILE_PATH}/ActivityGvgconstDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitygvgRankReward.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitygvgRankReward  --excel_sheetname=gvgRankReward  --proto_msgname=activitygvgRankReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitygvgRankReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityGvgrankrewardDesc.h ${PROTOCGEN_FILE_PATH}/ActivityGvgrankrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitygvgReward.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitygvgReward  --excel_sheetname=gvgReward  --proto_msgname=activitygvgReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitygvgReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityGvgrewardDesc.h ${PROTOCGEN_FILE_PATH}/ActivityGvgrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activityworldTreasureConst.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityworldTreasureConst  --excel_sheetname=worldTreasureConst  --proto_msgname=activityworldTreasureConst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activityworldTreasureConst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityWorldtreasureconstDesc.h ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasureconstDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activityworldTreasureMap.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityworldTreasureMap  --excel_sheetname=worldTreasureMap  --proto_msgname=activityworldTreasureMap  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activityworldTreasureMap.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremapDesc.h ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremapDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activityworldTreasureMonster.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activityworldTreasureMonster  --excel_sheetname=worldTreasureMonster  --proto_msgname=activityworldTreasureMonster  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activityworldTreasureMonster.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremonsterDesc.h ${PROTOCGEN_FILE_PATH}/ActivityWorldtreasuremonsterDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/activitylosttempleConstant.bin:${PROTOCGEN_FILE_PATH}/activity.proto.ds ${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/activity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_activitylosttempleConstant  --excel_sheetname=losttempleConstant  --proto_msgname=activitylosttempleConstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activitylosttempleConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ActivityLosttempleconstantDesc.h ${PROTOCGEN_FILE_PATH}/ActivityLosttempleconstantDesc.cpp" --dst=${DESC_STORE_PATH}/

