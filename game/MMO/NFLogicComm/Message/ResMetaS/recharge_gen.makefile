include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_recharge_bin

${PROTOCGEN_FILE_PATH}/module_recharge_bin:${PROTOCGEN_FILE_PATH}/recharge.proto.ds ${RESDB_EXCELMMO_PATH}/recharge.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_recharge_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/recharge.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/recharge.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/RechargeDescEx.h ${PROTOCGEN_FILE_PATH}/RechargeDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RechargeRecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RechargeRechargeDesc.h ${PROTOCGEN_FILE_PATH}/RechargeRechargeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RechargeOneclickbuy.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RechargeOneclickbuyDesc.h ${PROTOCGEN_FILE_PATH}/RechargeOneclickbuyDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_recharge_bin
