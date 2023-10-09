include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_pk1v1_bin

${PROTOCGEN_FILE_PATH}/module_pk1v1_bin:${PROTOCGEN_FILE_PATH}/pk1v1.proto.ds ${RESDB_EXCELMMO_PATH}/pk1v1.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_pk1v1_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/pk1v1.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pk1v1.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/Pk1v1DescEx.h ${PROTOCGEN_FILE_PATH}/Pk1v1DescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk1v1Rank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk1v1RankDesc.h ${PROTOCGEN_FILE_PATH}/Pk1v1RankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk1v1Reward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk1v1RewardDesc.h ${PROTOCGEN_FILE_PATH}/Pk1v1RewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk1v1Dailyreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk1v1DailyrewardDesc.h ${PROTOCGEN_FILE_PATH}/Pk1v1DailyrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_pk1v1_bin
