include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_SensitivewordSensitive_word.bin ${PROTOCGEN_FILE_PATH}/SensitivewordSensitive_wordDesc.h ${PROTOCGEN_FILE_PATH}/SensitivewordSensitive_wordDesc.cpp ${PROTOCGEN_FILE_PATH}/E_SensitivewordRolesensitive.bin ${PROTOCGEN_FILE_PATH}/SensitivewordRolesensitiveDesc.h ${PROTOCGEN_FILE_PATH}/SensitivewordRolesensitiveDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_SensitivewordSensitive_word.bin:${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds ${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SensitivewordSensitive_word  --excel_sheetname=sensitive_word  --proto_msgname=E_SensitivewordSensitive_word  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SensitivewordSensitive_word.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SensitivewordSensitive_wordDesc.h ${PROTOCGEN_FILE_PATH}/SensitivewordSensitive_wordDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_SensitivewordRolesensitive.bin:${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds ${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SensitivewordRolesensitive  --excel_sheetname=rolesensitive  --proto_msgname=E_SensitivewordRolesensitive  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SensitivewordRolesensitive.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SensitivewordRolesensitiveDesc.h ${PROTOCGEN_FILE_PATH}/SensitivewordRolesensitiveDesc.cpp" --dst=${DESC_STORE_PATH}/

