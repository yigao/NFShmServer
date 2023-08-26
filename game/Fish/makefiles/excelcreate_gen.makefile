include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_list

${PROTOCGEN_FILE_PATH}/module_list:${RESDB_EXCELMMO_PATH}/list.txt
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_list
	${NFEXCELPROCESS} --work="exceltomakefile" --src="${EXCEL_MMO_FILES_LIST}" --dst="${PROTOCGEN_FILE_PATH}/"
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/excelmmo_gen.makefile ${PROTOCGEN_FILE_PATH}/resmetas_gen.makefile" --dst=${MAKEFILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_list
