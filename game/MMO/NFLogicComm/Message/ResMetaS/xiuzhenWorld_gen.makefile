include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_xiuzhenWorld_bin

${PROTOCGEN_FILE_PATH}/module_xiuzhenWorld_bin:${PROTOCGEN_FILE_PATH}/xiuzhenWorld.proto.ds ${RESDB_EXCELMMO_PATH}/xiuzhenWorld.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_xiuzhenWorld_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/xiuzhenWorld.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/xiuzhenWorld.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/XiuzhenworldDescEx.h ${PROTOCGEN_FILE_PATH}/XiuzhenworldDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenworldConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenworldConstantDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenworldConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenworldExpmap.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenworldExpmapDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenworldExpmapDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_xiuzhenWorld_bin
