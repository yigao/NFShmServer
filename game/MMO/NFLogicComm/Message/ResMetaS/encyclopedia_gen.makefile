include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_encyclopedia_bin

${PROTOCGEN_FILE_PATH}/module_encyclopedia_bin:${PROTOCGEN_FILE_PATH}/encyclopedia.proto.ds ${RESDB_EXCELMMO_PATH}/encyclopedia.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_encyclopedia_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/encyclopedia.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/encyclopedia.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaDescEx.h ${PROTOCGEN_FILE_PATH}/EncyclopediaDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaHandbook.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaHandbookfate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookfateDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookfateDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaHandbookresolve.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookresolveDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookresolveDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaHandbooklv_attr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaHandbooklv_attrDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaHandbooklv_attrDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaHandbookstar_attr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookstar_attrDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaHandbookstar_attrDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaBeast.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaBeastDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaBeastDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaEquipexpvalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaEquipexpvalueDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaEquipexpvalueDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaBeastexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaBeastexpDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaBeastexpDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaBeastexpand.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaBeastexpandDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaBeastexpandDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaBeastprivilege.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaBeastprivilegeDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaBeastprivilegeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaEmploy.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaEmployDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaEmployDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EncyclopediaTable.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EncyclopediaTableDesc.h ${PROTOCGEN_FILE_PATH}/EncyclopediaTableDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_encyclopedia_bin
