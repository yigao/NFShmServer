include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_conflate_bin

${PROTOCGEN_FILE_PATH}/module_conflate_bin:${PROTOCGEN_FILE_PATH}/conflate.proto.ds ${RESDB_EXCELMMO_PATH}/conflate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_conflate_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/conflate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/conflate.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/ConflateDescEx.h ${PROTOCGEN_FILE_PATH}/ConflateDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateEquip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflateEquipDesc.h ${PROTOCGEN_FILE_PATH}/ConflateEquipDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateGrouptype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflateGrouptypeDesc.h ${PROTOCGEN_FILE_PATH}/ConflateGrouptypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateSubtype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflateSubtypeDesc.h ${PROTOCGEN_FILE_PATH}/ConflateSubtypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateProp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflatePropDesc.h ${PROTOCGEN_FILE_PATH}/ConflatePropDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateJewelry_sp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflateJewelry_spDesc.h ${PROTOCGEN_FILE_PATH}/ConflateJewelry_spDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateJewelry_zl.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflateJewelry_zlDesc.h ${PROTOCGEN_FILE_PATH}/ConflateJewelry_zlDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConflateJewelry_sj.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConflateJewelry_sjDesc.h ${PROTOCGEN_FILE_PATH}/ConflateJewelry_sjDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_conflate_bin
