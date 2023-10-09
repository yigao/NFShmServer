include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_footprint_bin

${PROTOCGEN_FILE_PATH}/module_footprint_bin:${PROTOCGEN_FILE_PATH}/footprint.proto.ds ${RESDB_EXCELMMO_PATH}/footprint.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_footprint_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/footprint.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/footprint.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FootprintDescEx.h ${PROTOCGEN_FILE_PATH}/FootprintDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FootprintFootprint.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FootprintFootprintDesc.h ${PROTOCGEN_FILE_PATH}/FootprintFootprintDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_footprint_bin
