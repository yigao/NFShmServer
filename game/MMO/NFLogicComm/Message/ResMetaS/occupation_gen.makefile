include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_occupation_bin

${PROTOCGEN_FILE_PATH}/module_occupation_bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_occupation_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/OccupationDescEx.h ${PROTOCGEN_FILE_PATH}/OccupationDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_OccupationOccupation.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.h ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_OccupationStage.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/OccupationStageDesc.h ${PROTOCGEN_FILE_PATH}/OccupationStageDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_OccupationAttribute.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/OccupationAttributeDesc.h ${PROTOCGEN_FILE_PATH}/OccupationAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_OccupationSoul.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/OccupationSoulDesc.h ${PROTOCGEN_FILE_PATH}/OccupationSoulDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_occupation_bin
