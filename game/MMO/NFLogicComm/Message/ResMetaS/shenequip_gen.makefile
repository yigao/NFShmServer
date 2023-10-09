include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_shenequip_bin

${PROTOCGEN_FILE_PATH}/module_shenequip_bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_shenequip_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/ShenequipDescEx.h ${PROTOCGEN_FILE_PATH}/ShenequipDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipEquip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipEquipDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipEquipDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipAtt.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipAttDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipAttDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipLvup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipLvupDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipLvupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipClear.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipClearDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipClearDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipAwaken.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipAwakenDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipAwakenDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipStarup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipStarupDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipStarupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ShenequipPrepose.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ShenequipPreposeDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipPreposeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_shenequip_bin
