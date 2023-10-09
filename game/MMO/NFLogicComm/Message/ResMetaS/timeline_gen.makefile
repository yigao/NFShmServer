include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_timeline_bin

${PROTOCGEN_FILE_PATH}/module_timeline_bin:${PROTOCGEN_FILE_PATH}/timeline.proto.ds ${RESDB_EXCELMMO_PATH}/timeline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_timeline_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/timeline.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/timeline.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TimelineDescEx.h ${PROTOCGEN_FILE_PATH}/TimelineDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_timeline_bin
