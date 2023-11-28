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
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Soul3dmodel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/Soul3dmodelDesc.h ${PROTOCGEN_FILE_PATH}/Soul3dmodelDesc.cpp" --dst=${DESC_STORE_PATH}/
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
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulAttr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulAttrDesc.h ${PROTOCGEN_FILE_PATH}/SoulAttrDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulSkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulSkillDesc.h ${PROTOCGEN_FILE_PATH}/SoulSkillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBone.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBoneDesc.h ${PROTOCGEN_FILE_PATH}/SoulBoneDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBonekill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBonekillDesc.h ${PROTOCGEN_FILE_PATH}/SoulBonekillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulBonestrong.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulBonestrongDesc.h ${PROTOCGEN_FILE_PATH}/SoulBonestrongDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulGuwen.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulGuwenDesc.h ${PROTOCGEN_FILE_PATH}/SoulGuwenDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulGuwentype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulGuwentypeDesc.h ${PROTOCGEN_FILE_PATH}/SoulGuwentypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulGuwentypesuit.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulGuwentypesuitDesc.h ${PROTOCGEN_FILE_PATH}/SoulGuwentypesuitDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulGuwenskill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulGuwenskillDesc.h ${PROTOCGEN_FILE_PATH}/SoulGuwenskillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulGuwensuit.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulGuwensuitDesc.h ${PROTOCGEN_FILE_PATH}/SoulGuwensuitDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulAffixes.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulAffixesDesc.h ${PROTOCGEN_FILE_PATH}/SoulAffixesDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulAffixesfumo.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulAffixesfumoDesc.h ${PROTOCGEN_FILE_PATH}/SoulAffixesfumoDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulAffixessuit.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulAffixessuitDesc.h ${PROTOCGEN_FILE_PATH}/SoulAffixessuitDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SoulGuwenattr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SoulGuwenattrDesc.h ${PROTOCGEN_FILE_PATH}/SoulGuwenattrDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_soul_bin
