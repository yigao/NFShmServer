include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_qunxiongzhulu_bin

${PROTOCGEN_FILE_PATH}/module_qunxiongzhulu_bin:${PROTOCGEN_FILE_PATH}/qunxiongzhulu.proto.ds ${RESDB_EXCELMMO_PATH}/qunxiongzhulu.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_qunxiongzhulu_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/qunxiongzhulu.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/qunxiongzhulu.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluDescEx.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QunxiongzhuluConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluConstantDesc.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QunxiongzhuluSkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluSkillDesc.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluSkillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QunxiongzhuluServerrank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluServerrankDesc.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluServerrankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QunxiongzhuluWorldrank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluWorldrankDesc.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluWorldrankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QunxiongzhuluLocalrank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluLocalrankDesc.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluLocalrankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_QunxiongzhuluBossreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/QunxiongzhuluBossrewardDesc.h ${PROTOCGEN_FILE_PATH}/QunxiongzhuluBossrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_qunxiongzhulu_bin
