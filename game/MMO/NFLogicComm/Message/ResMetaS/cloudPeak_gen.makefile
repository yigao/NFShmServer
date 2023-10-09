include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_cloudPeak_bin

${PROTOCGEN_FILE_PATH}/module_cloudPeak_bin:${PROTOCGEN_FILE_PATH}/cloudPeak.proto.ds ${RESDB_EXCELMMO_PATH}/cloudPeak.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_cloudPeak_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/cloudPeak.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/cloudPeak.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/CloudpeakDescEx.h ${PROTOCGEN_FILE_PATH}/CloudpeakDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_CloudpeakRankrewards.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/CloudpeakRankrewardsDesc.h ${PROTOCGEN_FILE_PATH}/CloudpeakRankrewardsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_CloudpeakConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/CloudpeakConstantDesc.h ${PROTOCGEN_FILE_PATH}/CloudpeakConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_CloudpeakExp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/CloudpeakExpDesc.h ${PROTOCGEN_FILE_PATH}/CloudpeakExpDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_cloudPeak_bin
