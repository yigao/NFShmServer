include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_guide_bin

${PROTOCGEN_FILE_PATH}/module_guide_bin:${PROTOCGEN_FILE_PATH}/guide.proto.ds ${RESDB_EXCELMMO_PATH}/guide.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_guide_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/guide.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guide.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/GuideDescEx.h ${PROTOCGEN_FILE_PATH}/GuideDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_guide_bin
