include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/dailydaily.bin ${PROTOCGEN_FILE_PATH}/DailyDailyDesc.h ${PROTOCGEN_FILE_PATH}/DailyDailyDesc.cpp ${PROTOCGEN_FILE_PATH}/dailyreward.bin ${PROTOCGEN_FILE_PATH}/DailyRewardDesc.h ${PROTOCGEN_FILE_PATH}/DailyRewardDesc.cpp ${PROTOCGEN_FILE_PATH}/dailycultivate.bin ${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.h ${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.cpp 

${PROTOCGEN_FILE_PATH}/dailydaily.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dailydaily  --excel_sheetname=daily  --proto_msgname=dailydaily  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dailydaily.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailyDailyDesc.h ${PROTOCGEN_FILE_PATH}/DailyDailyDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/dailyreward.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dailyreward  --excel_sheetname=reward  --proto_msgname=dailyreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dailyreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailyRewardDesc.h ${PROTOCGEN_FILE_PATH}/DailyRewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/dailycultivate.bin:${PROTOCGEN_FILE_PATH}/daily.proto.ds ${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/daily.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dailycultivate  --excel_sheetname=cultivate  --proto_msgname=dailycultivate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dailycultivate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.h ${PROTOCGEN_FILE_PATH}/DailyCultivateDesc.cpp" --dst=${DESC_STORE_PATH}/

