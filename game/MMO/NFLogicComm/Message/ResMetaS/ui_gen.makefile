include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_ui_bin

${PROTOCGEN_FILE_PATH}/module_ui_bin:${PROTOCGEN_FILE_PATH}/ui.proto.ds ${RESDB_EXCELMMO_PATH}/ui.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_ui_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/ui.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ui.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/UiDescEx.h ${PROTOCGEN_FILE_PATH}/UiDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_UiEffect.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/UiEffectDesc.h ${PROTOCGEN_FILE_PATH}/UiEffectDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_ui_bin
