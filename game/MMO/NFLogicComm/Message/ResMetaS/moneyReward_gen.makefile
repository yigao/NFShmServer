include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MoneyrewardMoneyreward.bin ${PROTOCGEN_FILE_PATH}/MoneyrewardMoneyrewardDesc.h ${PROTOCGEN_FILE_PATH}/MoneyrewardMoneyrewardDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MoneyrewardMoneyreward.bin:${PROTOCGEN_FILE_PATH}/moneyReward.proto.ds ${RESDB_EXCELMMO_PATH}/moneyReward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/moneyReward.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/moneyReward.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MoneyrewardMoneyreward  --excel_sheetname=moneyReward  --proto_msgname=E_MoneyrewardMoneyreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MoneyrewardMoneyreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MoneyrewardMoneyrewardDesc.h ${PROTOCGEN_FILE_PATH}/MoneyrewardMoneyrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

