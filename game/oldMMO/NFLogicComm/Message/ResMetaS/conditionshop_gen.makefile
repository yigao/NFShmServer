include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/conditionshopconditionshop.bin ${PROTOCGEN_FILE_PATH}/ConditionshopConditionshopDesc.h ${PROTOCGEN_FILE_PATH}/ConditionshopConditionshopDesc.cpp 

${PROTOCGEN_FILE_PATH}/conditionshopconditionshop.bin:${PROTOCGEN_FILE_PATH}/conditionshop.proto.ds ${RESDB_EXCELMMO_PATH}/conditionshop.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/conditionshop.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/conditionshop.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_conditionshopconditionshop  --excel_sheetname=conditionshop  --proto_msgname=conditionshopconditionshop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/conditionshopconditionshop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ConditionshopConditionshopDesc.h ${PROTOCGEN_FILE_PATH}/ConditionshopConditionshopDesc.cpp" --dst=${DESC_STORE_PATH}/

