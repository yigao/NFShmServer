include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/effecteffect.bin ${PROTOCGEN_FILE_PATH}/EffectEffectDesc.h ${PROTOCGEN_FILE_PATH}/EffectEffectDesc.cpp 

${PROTOCGEN_FILE_PATH}/effecteffect.bin:${PROTOCGEN_FILE_PATH}/effect.proto.ds ${RESDB_EXCELMMO_PATH}/effect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/effect.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/effect.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_effecteffect  --excel_sheetname=effect  --proto_msgname=effecteffect  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/effecteffect.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EffectEffectDesc.h ${PROTOCGEN_FILE_PATH}/EffectEffectDesc.cpp:${PROTOCGEN_FILE_PATH}/effect.proto.ds ${RESDB_EXCELMMO_PATH}/effect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EffectEffectDesc.h ${PROTOCGEN_FILE_PATH}/EffectEffectDesc.cpp" --dst=${DESC_STORE_PATH}/

