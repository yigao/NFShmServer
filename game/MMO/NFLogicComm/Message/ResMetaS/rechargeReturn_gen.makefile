include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/rechargeReturnrechargeReturn.bin ${PROTOCGEN_FILE_PATH}/RechargereturnRechargereturnDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnRechargereturnDesc.cpp ${PROTOCGEN_FILE_PATH}/rechargeReturntime.bin ${PROTOCGEN_FILE_PATH}/RechargereturnTimeDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnTimeDesc.cpp ${PROTOCGEN_FILE_PATH}/rechargeReturncontinuousReturn.bin ${PROTOCGEN_FILE_PATH}/RechargereturnContinuousreturnDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnContinuousreturnDesc.cpp ${PROTOCGEN_FILE_PATH}/rechargeReturnrechargeTrigger.bin ${PROTOCGEN_FILE_PATH}/RechargereturnRechargetriggerDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnRechargetriggerDesc.cpp ${PROTOCGEN_FILE_PATH}/rechargeReturnconstant.bin ${PROTOCGEN_FILE_PATH}/RechargereturnConstantDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnConstantDesc.cpp 

${PROTOCGEN_FILE_PATH}/rechargeReturnrechargeReturn.bin:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rechargeReturnrechargeReturn  --excel_sheetname=rechargeReturn  --proto_msgname=rechargeReturnrechargeReturn  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturnrechargeReturn.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/RechargereturnRechargereturnDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnRechargereturnDesc.cpp:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RechargereturnRechargereturnDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnRechargereturnDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rechargeReturntime.bin:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rechargeReturntime  --excel_sheetname=time  --proto_msgname=rechargeReturntime  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturntime.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/RechargereturnTimeDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnTimeDesc.cpp:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RechargereturnTimeDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnTimeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rechargeReturncontinuousReturn.bin:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rechargeReturncontinuousReturn  --excel_sheetname=continuousReturn  --proto_msgname=rechargeReturncontinuousReturn  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturncontinuousReturn.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/RechargereturnContinuousreturnDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnContinuousreturnDesc.cpp:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RechargereturnContinuousreturnDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnContinuousreturnDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rechargeReturnrechargeTrigger.bin:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rechargeReturnrechargeTrigger  --excel_sheetname=rechargeTrigger  --proto_msgname=rechargeReturnrechargeTrigger  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturnrechargeTrigger.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/RechargereturnRechargetriggerDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnRechargetriggerDesc.cpp:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RechargereturnRechargetriggerDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnRechargetriggerDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rechargeReturnconstant.bin:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rechargeReturnconstant  --excel_sheetname=constant  --proto_msgname=rechargeReturnconstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturnconstant.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/RechargereturnConstantDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnConstantDesc.cpp:${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds ${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RechargereturnConstantDesc.h ${PROTOCGEN_FILE_PATH}/RechargereturnConstantDesc.cpp" --dst=${DESC_STORE_PATH}/

