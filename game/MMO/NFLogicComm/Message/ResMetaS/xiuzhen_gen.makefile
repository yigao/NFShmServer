include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_xiuzhen_bin

${PROTOCGEN_FILE_PATH}/module_xiuzhen_bin:${PROTOCGEN_FILE_PATH}/xiuzhen.proto.ds ${RESDB_EXCELMMO_PATH}/xiuzhen.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_xiuzhen_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/xiuzhen.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/xiuzhen.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/XiuzhenDescEx.h ${PROTOCGEN_FILE_PATH}/XiuzhenDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenStages.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenStagesDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenStagesDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenGb_areas.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenGb_areasDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenGb_areasDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenGb_area_events.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenGb_area_eventsDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenGb_area_eventsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenGb_lvlup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenGb_lvlupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenGb_lvlupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenEvolve.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenEvolveDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenEvolveDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenLgtypes.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenLgtypesDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenLgtypesDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenLglvlup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenLglvlupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenLglvlupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenLgpotions.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenLgpotionsDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenLgpotionsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenGftypes.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenGftypesDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenGftypesDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenGflvlup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenGflvlupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenGflvlupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenGfstageup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenGfstageupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenGfstageupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenJmtypes.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenJmtypesDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenJmtypesDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenJmlvlup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenJmlvlupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenJmlvlupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenJmstageup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenJmstageupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenJmstageupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenJmmergeup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenJmmergeupDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenJmmergeupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenPrivilege.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenPrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenPrivilegeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_xiuzhen_bin
