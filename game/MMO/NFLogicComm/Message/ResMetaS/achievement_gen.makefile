include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_achievement_bin

${PROTOCGEN_FILE_PATH}/module_achievement_bin:${PROTOCGEN_FILE_PATH}/achievement.proto.ds ${RESDB_EXCELMMO_PATH}/achievement.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_achievement_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/achievement.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AchievementDescEx.h ${PROTOCGEN_FILE_PATH}/AchievementDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AchievementAchievement.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AchievementAchievementDesc.h ${PROTOCGEN_FILE_PATH}/AchievementAchievementDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AchievementTotalachievements.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AchievementTotalachievementsDesc.h ${PROTOCGEN_FILE_PATH}/AchievementTotalachievementsDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_achievement_bin
