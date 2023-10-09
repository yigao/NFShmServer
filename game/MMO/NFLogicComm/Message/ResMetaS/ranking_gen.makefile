include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_ranking_bin

${PROTOCGEN_FILE_PATH}/module_ranking_bin:${PROTOCGEN_FILE_PATH}/ranking.proto.ds ${RESDB_EXCELMMO_PATH}/ranking.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_ranking_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/ranking.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/RankingDescEx.h ${PROTOCGEN_FILE_PATH}/RankingDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RankingRanking.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RankingRankingDesc.h ${PROTOCGEN_FILE_PATH}/RankingRankingDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RankingDate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RankingDateDesc.h ${PROTOCGEN_FILE_PATH}/RankingDateDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RankingButton.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RankingButtonDesc.h ${PROTOCGEN_FILE_PATH}/RankingButtonDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_ranking_bin
