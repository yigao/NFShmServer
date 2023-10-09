include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_qyPeak_bin

${PROTOCGEN_FILE_PATH}/module_qyPeak_bin:${PROTOCGEN_FILE_PATH}/qyPeak.proto.ds ${RESDB_EXCELMMO_PATH}/qyPeak.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_qyPeak_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/qyPeak.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/qyPeak.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/QypeakDescEx.h ${PROTOCGEN_FILE_PATH}/QypeakDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QypeakBack.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QypeakBackDesc.h ${PROTOCGEN_FILE_PATH}/QypeakBackDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QypeakConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QypeakConstantDesc.h ${PROTOCGEN_FILE_PATH}/QypeakConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_qyPeak_bin
