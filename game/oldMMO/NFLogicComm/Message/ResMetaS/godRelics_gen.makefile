include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_GodrelicsGodrelics.bin ${PROTOCGEN_FILE_PATH}/GodrelicsGodrelicsDesc.h ${PROTOCGEN_FILE_PATH}/GodrelicsGodrelicsDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GodrelicsCondition.bin ${PROTOCGEN_FILE_PATH}/GodrelicsConditionDesc.h ${PROTOCGEN_FILE_PATH}/GodrelicsConditionDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_GodrelicsGodrelics.bin:${PROTOCGEN_FILE_PATH}/godRelics.proto.ds ${RESDB_EXCELMMO_PATH}/godRelics.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godRelics.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GodrelicsGodrelics  --excel_sheetname=godRelics  --proto_msgname=E_GodrelicsGodrelics  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GodrelicsGodrelics.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodrelicsGodrelicsDesc.h ${PROTOCGEN_FILE_PATH}/GodrelicsGodrelicsDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GodrelicsCondition.bin:${PROTOCGEN_FILE_PATH}/godRelics.proto.ds ${RESDB_EXCELMMO_PATH}/godRelics.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godRelics.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GodrelicsCondition  --excel_sheetname=condition  --proto_msgname=E_GodrelicsCondition  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GodrelicsCondition.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodrelicsConditionDesc.h ${PROTOCGEN_FILE_PATH}/GodrelicsConditionDesc.cpp" --dst=${DESC_STORE_PATH}/

