include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_talent_bin

${PROTOCGEN_FILE_PATH}/module_talent_bin:${PROTOCGEN_FILE_PATH}/talent.proto.ds ${RESDB_EXCELMMO_PATH}/talent.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_talent_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/talent.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/talent.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TalentDescEx.h ${PROTOCGEN_FILE_PATH}/TalentDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TalentTalent.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TalentTalentDesc.h ${PROTOCGEN_FILE_PATH}/TalentTalentDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TalentTalenttype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TalentTalenttypeDesc.h ${PROTOCGEN_FILE_PATH}/TalentTalenttypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_talent_bin
