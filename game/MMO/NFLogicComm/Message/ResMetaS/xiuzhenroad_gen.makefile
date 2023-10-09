include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_xiuzhenroad_bin

${PROTOCGEN_FILE_PATH}/module_xiuzhenroad_bin:${PROTOCGEN_FILE_PATH}/xiuzhenroad.proto.ds ${RESDB_EXCELMMO_PATH}/xiuzhenroad.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_xiuzhenroad_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/xiuzhenroad.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/xiuzhenroad.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/XiuzhenroadDescEx.h ${PROTOCGEN_FILE_PATH}/XiuzhenroadDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenroadTask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenroadTaskDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenroadTaskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenroadBonuspoints.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenroadBonuspointsDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenroadBonuspointsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenroadSkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenroadSkillDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenroadSkillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_XiuzhenroadClassify.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/XiuzhenroadClassifyDesc.h ${PROTOCGEN_FILE_PATH}/XiuzhenroadClassifyDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_xiuzhenroad_bin
