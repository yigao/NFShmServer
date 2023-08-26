include ./define.makefile

.PHONY:all

all:constant_xlsx Fish_xlsx 

constant_xlsx:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/


Fish_xlsx:${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Fish.proto ${PROTOCGEN_FILE_PATH}/Fish_gen.makefile" --dst=${RESDB_META_PATH}/


