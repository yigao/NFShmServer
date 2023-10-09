include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_offline_bin

${PROTOCGEN_FILE_PATH}/module_offline_bin:${PROTOCGEN_FILE_PATH}/offline.proto.ds ${RESDB_EXCELMMO_PATH}/offline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_offline_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/offline.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/OfflineDescEx.h ${PROTOCGEN_FILE_PATH}/OfflineDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_OfflineOffline.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/OfflineOfflineDesc.h ${PROTOCGEN_FILE_PATH}/OfflineOfflineDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_OfflineItemlist.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/OfflineItemlistDesc.h ${PROTOCGEN_FILE_PATH}/OfflineItemlistDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_offline_bin
