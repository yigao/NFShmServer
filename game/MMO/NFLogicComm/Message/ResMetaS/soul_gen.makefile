include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_soul_bin

${PROTOCGEN_FILE_PATH}/module_soul_bin:${PROTOCGEN_FILE_PATH}/soul.proto.ds ${RESDB_EXCELMMO_PATH}/soul.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_soul_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/soul.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/soul.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/SoulDescEx.h ${PROTOCGEN_FILE_PATH}/SoulDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulOpen.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulOpenDesc.h ${PROTOCGEN_FILE_PATH}/SoulOpenDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulSoul.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulSoulDesc.h ${PROTOCGEN_FILE_PATH}/SoulSoulDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulSoulbasic.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulSoulbasicDesc.h ${PROTOCGEN_FILE_PATH}/SoulSoulbasicDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulSouladvance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulSouladvanceDesc.h ${PROTOCGEN_FILE_PATH}/SoulSouladvanceDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBless.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBlessDesc.h ${PROTOCGEN_FILE_PATH}/SoulBlessDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulPrivilege.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulPrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/SoulPrivilegeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulCrystal.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulCrystalDesc.h ${PROTOCGEN_FILE_PATH}/SoulCrystalDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulCrystallv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulCrystallvDesc.h ${PROTOCGEN_FILE_PATH}/SoulCrystallvDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulCrystaltop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulCrystaltopDesc.h ${PROTOCGEN_FILE_PATH}/SoulCrystaltopDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulCrystalhole.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulCrystalholeDesc.h ${PROTOCGEN_FILE_PATH}/SoulCrystalholeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulFusion.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulFusionDesc.h ${PROTOCGEN_FILE_PATH}/SoulFusionDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBone.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBoneDesc.h ${PROTOCGEN_FILE_PATH}/SoulBoneDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBoneequip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBoneequipDesc.h ${PROTOCGEN_FILE_PATH}/SoulBoneequipDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBoneskill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBoneskillDesc.h ${PROTOCGEN_FILE_PATH}/SoulBoneskillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBonekill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBonekillDesc.h ${PROTOCGEN_FILE_PATH}/SoulBonekillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBonestrong.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBonestrongDesc.h ${PROTOCGEN_FILE_PATH}/SoulBonestrongDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_soul_bin
