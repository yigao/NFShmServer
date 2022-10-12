include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}

${PROTOCGEN_FILE_PATH}/msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile:${RESDB_EXCELMMO_PATH}/msg.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile:${RESDB_EXCELMMO_PATH}/ui.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile:${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile:${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile:${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/login.proto ${PROTOCGEN_FILE_PATH}/login_gen.makefile:${RESDB_EXCELMMO_PATH}/login.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/login.proto ${PROTOCGEN_FILE_PATH}/login_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile:${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile:${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile:${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile:${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile:${RESDB_EXCELMMO_PATH}/item.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile:${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/


