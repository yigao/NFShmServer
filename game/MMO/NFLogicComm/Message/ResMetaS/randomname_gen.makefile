include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_randomname_bin

${PROTOCGEN_FILE_PATH}/module_randomname_bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_randomname_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/RandomnameDescEx.h ${PROTOCGEN_FILE_PATH}/RandomnameDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RandomnameManfirst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RandomnameMansecond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RandomnameManthird.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RandomnameWomanfirst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RandomnameWomansecond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_RandomnameWomanthird.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_randomname_bin
