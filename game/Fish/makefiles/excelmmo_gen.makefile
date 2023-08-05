include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}

${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/room.proto ${PROTOCGEN_FILE_PATH}/room_gen.makefile:${RESDB_EXCELMMO_PATH}/room.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/room.proto ${PROTOCGEN_FILE_PATH}/room_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/GunValue.proto ${PROTOCGEN_FILE_PATH}/GunValue_gen.makefile:${RESDB_EXCELMMO_PATH}/GunValue.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GunValue.proto ${PROTOCGEN_FILE_PATH}/GunValue_gen.makefile" --dst=${RESDB_META_PATH}/


