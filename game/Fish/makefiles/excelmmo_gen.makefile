include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/constant_xlsx_finish ${PROTOCGEN_FILE_PATH}/Fish_xlsx_finish 

${PROTOCGEN_FILE_PATH}/constant_xlsx_finish:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/constant_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/constant_xlsx_finish


${PROTOCGEN_FILE_PATH}/Fish_xlsx_finish:${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/Fish_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Fish.proto ${PROTOCGEN_FILE_PATH}/Fish_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/Fish_xlsx_finish


