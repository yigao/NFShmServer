include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_equipImprove_bin

${PROTOCGEN_FILE_PATH}/module_equipImprove_bin:${PROTOCGEN_FILE_PATH}/equipImprove.proto.ds ${RESDB_EXCELMMO_PATH}/equipImprove.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_equipImprove_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/equipImprove.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equipImprove.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/EquipimproveDescEx.h ${PROTOCGEN_FILE_PATH}/EquipimproveDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EquipimproveUpquality.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EquipimproveUpqualityDesc.h ${PROTOCGEN_FILE_PATH}/EquipimproveUpqualityDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EquipimproveAwaken.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EquipimproveAwakenDesc.h ${PROTOCGEN_FILE_PATH}/EquipimproveAwakenDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EquipimproveSoaring.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EquipimproveSoaringDesc.h ${PROTOCGEN_FILE_PATH}/EquipimproveSoaringDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EquipimproveSeal.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EquipimproveSealDesc.h ${PROTOCGEN_FILE_PATH}/EquipimproveSealDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EquipimproveSealslot.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EquipimproveSealslotDesc.h ${PROTOCGEN_FILE_PATH}/EquipimproveSealslotDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EquipimproveSealsuit.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EquipimproveSealsuitDesc.h ${PROTOCGEN_FILE_PATH}/EquipimproveSealsuitDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_equipImprove_bin
