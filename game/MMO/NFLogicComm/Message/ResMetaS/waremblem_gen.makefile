include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_waremblem_bin

${PROTOCGEN_FILE_PATH}/module_waremblem_bin:${PROTOCGEN_FILE_PATH}/waremblem.proto.ds ${RESDB_EXCELMMO_PATH}/waremblem.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_waremblem_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/waremblem.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/waremblem.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/WaremblemDescEx.h ${PROTOCGEN_FILE_PATH}/WaremblemDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_WaremblemWaremblem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/WaremblemWaremblemDesc.h ${PROTOCGEN_FILE_PATH}/WaremblemWaremblemDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_WaremblemLv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/WaremblemLvDesc.h ${PROTOCGEN_FILE_PATH}/WaremblemLvDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_WaremblemStar.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/WaremblemStarDesc.h ${PROTOCGEN_FILE_PATH}/WaremblemStarDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_waremblem_bin
