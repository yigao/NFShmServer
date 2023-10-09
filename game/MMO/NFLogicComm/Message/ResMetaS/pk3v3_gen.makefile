include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_pk3v3_bin

${PROTOCGEN_FILE_PATH}/module_pk3v3_bin:${PROTOCGEN_FILE_PATH}/pk3v3.proto.ds ${RESDB_EXCELMMO_PATH}/pk3v3.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_pk3v3_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/pk3v3.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pk3v3.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/Pk3v3DescEx.h ${PROTOCGEN_FILE_PATH}/Pk3v3DescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3Level.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk3v3LevelDesc.h ${PROTOCGEN_FILE_PATH}/Pk3v3LevelDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3Reward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk3v3RewardDesc.h ${PROTOCGEN_FILE_PATH}/Pk3v3RewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3Badge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk3v3BadgeDesc.h ${PROTOCGEN_FILE_PATH}/Pk3v3BadgeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3Constant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk3v3ConstantDesc.h ${PROTOCGEN_FILE_PATH}/Pk3v3ConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3Exp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Pk3v3ExpDesc.h ${PROTOCGEN_FILE_PATH}/Pk3v3ExpDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_pk3v3_bin
