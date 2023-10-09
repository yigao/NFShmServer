include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_audio_bin

${PROTOCGEN_FILE_PATH}/module_audio_bin:${PROTOCGEN_FILE_PATH}/audio.proto.ds ${RESDB_EXCELMMO_PATH}/audio.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_audio_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/audio.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/audio.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AudioDescEx.h ${PROTOCGEN_FILE_PATH}/AudioDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_audio_bin
