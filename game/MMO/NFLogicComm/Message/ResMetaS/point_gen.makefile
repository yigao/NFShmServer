include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_point_bin

${PROTOCGEN_FILE_PATH}/module_point_bin:${PROTOCGEN_FILE_PATH}/point.proto.ds ${RESDB_EXCELMMO_PATH}/point.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_point_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/point.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/point.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/PointDescEx.h ${PROTOCGEN_FILE_PATH}/PointDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PointPoint.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PointPointDesc.h ${PROTOCGEN_FILE_PATH}/PointPointDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_point_bin
