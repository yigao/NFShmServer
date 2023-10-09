include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_moneyReward_bin

${PROTOCGEN_FILE_PATH}/module_moneyReward_bin:${PROTOCGEN_FILE_PATH}/moneyReward.proto.ds ${RESDB_EXCELMMO_PATH}/moneyReward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_moneyReward_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/moneyReward.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/moneyReward.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/MoneyrewardDescEx.h ${PROTOCGEN_FILE_PATH}/MoneyrewardDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MoneyrewardMoneyreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MoneyrewardMoneyrewardDesc.h ${PROTOCGEN_FILE_PATH}/MoneyrewardMoneyrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_moneyReward_bin
