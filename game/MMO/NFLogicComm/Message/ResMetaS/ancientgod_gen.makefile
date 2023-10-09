include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_ancientgod_bin

${PROTOCGEN_FILE_PATH}/module_ancientgod_bin:${PROTOCGEN_FILE_PATH}/ancientgod.proto.ds ${RESDB_EXCELMMO_PATH}/ancientgod.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_ancientgod_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/ancientgod.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ancientgod.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AncientgodDescEx.h ${PROTOCGEN_FILE_PATH}/AncientgodDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodAncientgod.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodAncientgodDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodAncientgodDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodLvup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodLvupDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodLvupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodEquipvalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodEquipvalueDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodEquipvalueDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodBless.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodBlessDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodBlessDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodAdvance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodAdvanceDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodAdvanceDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodAtt.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodAttDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodAttDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AncientgodStarcollect.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AncientgodStarcollectDesc.h ${PROTOCGEN_FILE_PATH}/AncientgodStarcollectDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_ancientgod_bin
