include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_guild_bin

${PROTOCGEN_FILE_PATH}/module_guild_bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_guild_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/GuildDescEx.h ${PROTOCGEN_FILE_PATH}/GuildDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildConstantDesc.h ${PROTOCGEN_FILE_PATH}/GuildConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildLevel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildLevelDesc.h ${PROTOCGEN_FILE_PATH}/GuildLevelDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildPosition.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildPositionDesc.h ${PROTOCGEN_FILE_PATH}/GuildPositionDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildSalary.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildSalaryDesc.h ${PROTOCGEN_FILE_PATH}/GuildSalaryDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildDonate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildDonateDesc.h ${PROTOCGEN_FILE_PATH}/GuildDonateDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildPacket.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildPacketDesc.h ${PROTOCGEN_FILE_PATH}/GuildPacketDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildPrestigetask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildPrestigetaskDesc.h ${PROTOCGEN_FILE_PATH}/GuildPrestigetaskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildLvreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildLvrewardDesc.h ${PROTOCGEN_FILE_PATH}/GuildLvrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildCollege.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildCollegeDesc.h ${PROTOCGEN_FILE_PATH}/GuildCollegeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildAnswer.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildAnswerDesc.h ${PROTOCGEN_FILE_PATH}/GuildAnswerDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildRank_reward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildRank_rewardDesc.h ${PROTOCGEN_FILE_PATH}/GuildRank_rewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildShouhskill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildShouhskillDesc.h ${PROTOCGEN_FILE_PATH}/GuildShouhskillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildGwreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildGwrewardDesc.h ${PROTOCGEN_FILE_PATH}/GuildGwrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildGwwinstreak.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildGwwinstreakDesc.h ${PROTOCGEN_FILE_PATH}/GuildGwwinstreakDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildTtower.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildTtowerDesc.h ${PROTOCGEN_FILE_PATH}/GuildTtowerDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildTtowerdevelop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildTtowerdevelopDesc.h ${PROTOCGEN_FILE_PATH}/GuildTtowerdevelopDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GuildTtowerdevelop_data.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GuildTtowerdevelop_dataDesc.h ${PROTOCGEN_FILE_PATH}/GuildTtowerdevelop_dataDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_guild_bin
