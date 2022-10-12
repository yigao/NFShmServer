include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/conditioncondition.bin ${PROTOCGEN_FILE_PATH}/ConditionConditionDesc.h ${PROTOCGEN_FILE_PATH}/ConditionConditionDesc.cpp 

${PROTOCGEN_FILE_PATH}/conditioncondition.bin:${PROTOCGEN_FILE_PATH}/condition.proto.ds ${RESDB_EXCELMMO_PATH}/condition.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/condition.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/condition.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_conditioncondition  --excel_sheetname=condition  --proto_msgname=conditioncondition  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/conditioncondition.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ConditionConditionDesc.h ${PROTOCGEN_FILE_PATH}/ConditionConditionDesc.cpp" --dst=${DESC_STORE_PATH}/

