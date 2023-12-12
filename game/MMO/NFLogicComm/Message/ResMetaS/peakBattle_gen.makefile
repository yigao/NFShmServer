include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_peakBattle_bin

${PROTOCGEN_FILE_PATH}/module_peakBattle_bin:${PROTOCGEN_FILE_PATH}/peakBattle.proto.ds ${RESDB_EXCELMMO_PATH}/peakBattle.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_peakBattle_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/peakBattle.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/peakBattle.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/PeakbattleDescEx.h ${PROTOCGEN_FILE_PATH}/PeakbattleDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PeakbattleConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PeakbattleConstantDesc.h ${PROTOCGEN_FILE_PATH}/PeakbattleConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PeakbattleAward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PeakbattleAwardDesc.h ${PROTOCGEN_FILE_PATH}/PeakbattleAwardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PeakbattleGuess.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PeakbattleGuessDesc.h ${PROTOCGEN_FILE_PATH}/PeakbattleGuessDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_peakBattle_bin
