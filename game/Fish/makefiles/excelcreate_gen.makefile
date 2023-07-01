include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/excelmmo_gen.makefile ${PROTOCGEN_FILE_PATH}/resmetas_gen.makefile

${PROTOCGEN_FILE_PATH}/excelmmo_gen.makefile ${PROTOCGEN_FILE_PATH}/resmetas_gen.makefile:${RESDB_EXCELMMO_PATH}/list.txt
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2MAKEFILE} --src="${EXCEL_MMO_FILES_LIST}" --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/excelmmo_gen.makefile ${PROTOCGEN_FILE_PATH}/resmetas_gen.makefile" --dst=${MAKEFILE_PATH}/

#${EXCEL_MMO_PROTO_BIN_FILES} ${EXCEL_MMO_MAKEFILE_BIN_FILES}:${EXCEL_MMO_FILES}
#	mkdir -p ${PROTOCGEN_FILE_PATH}
#	for xml in $(EXCEL_MMO_FILES);do\
#		${EXCEL2PROTO} --excel=$$xml --out_path=${PROTOCGEN_FILE_PATH}/;\
#	done
#	${FILE_COPY_EXE} --src="${EXCEL_MMO_PROTO_BIN_FILES} ${EXCEL_MMO_MAKEFILE_BIN_FILES}" --dst=${RESDB_META_PATH}/