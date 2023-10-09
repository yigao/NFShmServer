include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_AiAi.bin ${PROTOCGEN_FILE_PATH}/AiAiDesc.h ${PROTOCGEN_FILE_PATH}/AiAiDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_AiAi.bin:${PROTOCGEN_FILE_PATH}/ai.proto.ds ${RESDB_EXCELMMO_PATH}/ai.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/ai.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AiAi  --excel_sheetname=ai  --proto_msgname=E_AiAi  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AiAi.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AiAiDesc.h ${PROTOCGEN_FILE_PATH}/AiAiDesc.cpp" --dst=${DESC_STORE_PATH}/

