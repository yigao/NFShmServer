include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_RechargeRecharge.bin ${PROTOCGEN_FILE_PATH}/RechargeRechargeDesc.h ${PROTOCGEN_FILE_PATH}/RechargeRechargeDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_RechargeRecharge.bin:${PROTOCGEN_FILE_PATH}/recharge.proto.ds ${RESDB_EXCELMMO_PATH}/recharge.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/recharge.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/recharge.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RechargeRecharge  --excel_sheetname=recharge  --proto_msgname=E_RechargeRecharge  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RechargeRecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RechargeRechargeDesc.h ${PROTOCGEN_FILE_PATH}/RechargeRechargeDesc.cpp" --dst=${DESC_STORE_PATH}/

