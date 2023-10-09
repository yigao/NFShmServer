include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_team_bin

${PROTOCGEN_FILE_PATH}/module_team_bin:${PROTOCGEN_FILE_PATH}/team.proto.ds ${RESDB_EXCELMMO_PATH}/team.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_team_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/team.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/team.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TeamDescEx.h ${PROTOCGEN_FILE_PATH}/TeamDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TeamTeam.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TeamTeamDesc.h ${PROTOCGEN_FILE_PATH}/TeamTeamDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_team_bin
