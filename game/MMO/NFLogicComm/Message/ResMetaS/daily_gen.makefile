include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_DailyDaily.bin ${PROTOCGEN_FILE_PATH}/DailyDailyDesc.h ${PROTOCGEN_FILE_PATH}/DailyDailyDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DailyReward.bin ${PROTOCGEN_FILE_PATH}/DailyRewardDesc.h ${PROTOCGEN_FILE_PATH}/DailyRewardDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DailyCultivate.bin ${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.h ${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DailySports.bin ${PROTOCGEN_FILE_PATH}/DailySportsDesc.h ${PROTOCGEN_FILE_PATH}/DailySportsDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_DailyDaily.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DailyDaily  --excel_sheetname=daily  --proto_msgname=E_DailyDaily  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DailyDaily.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailyDailyDesc.h ${PROTOCGEN_FILE_PATH}/DailyDailyDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DailyReward.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DailyReward  --excel_sheetname=reward  --proto_msgname=E_DailyReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DailyReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailyRewardDesc.h ${PROTOCGEN_FILE_PATH}/DailyRewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DailyCultivate.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DailyCultivate  --excel_sheetname=cultivate  --proto_msgname=E_DailyCultivate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DailyCultivate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.h ${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DailySports.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DailySports  --excel_sheetname=sports  --proto_msgname=E_DailySports  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DailySports.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailySportsDesc.h ${PROTOCGEN_FILE_PATH}/DailySportsDesc.cpp" --dst=${DESC_STORE_PATH}/

