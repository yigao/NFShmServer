include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin

${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin:${PROTOCGEN_FILE_PATH}/tianxiafirst.proto.ds ${RESDB_EXCELMMO_PATH}/tianxiafirst.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/tianxiafirst.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/tianxiafirst.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstDescEx.h ${PROTOCGEN_FILE_PATH}/TianxiafirstDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstConstantDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstBattle.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstBattleDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstBattleDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstArtifact.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstArtifactDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstArtifactDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstStrong.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstStrongDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstStrongDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstStrongitem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstStrongitemDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstStrongitemDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstRefine.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstRefineDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstRefineDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstSqskill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstSqskillDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstSqskillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstGrade.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstGradeDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstGradeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstGradereward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstGraderewardDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstGraderewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstRankreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstRankrewardDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstRankrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstWatchreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstWatchrewardDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstWatchrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstLuckyreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstLuckyrewardDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstLuckyrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstMatchtimesreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstMatchtimesrewardDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstMatchtimesrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstMatchresultreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstMatchresultrewardDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstMatchresultrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstExtraaddattr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstExtraaddattrDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstExtraaddattrDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstFirstaddattr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstFirstaddattrDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstFirstaddattrDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstShop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstShopDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstShopDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstDanmaku.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstDanmakuDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstDanmakuDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin
