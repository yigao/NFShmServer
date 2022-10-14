include ./define.makefile

.PHONY:all

all:${GAME_SQL_PATH}/create_tbRoleInfo.sql

${GAME_SQL_PATH}/create_tbRoleInfo.sql:${COMMON_LOGIC_META_DESCRIPTOR}
	mkdir -p ${GAME_SQL_PATH}
	${PROTO2SQL} --proto_ds=${COMMON_LOGIC_META_DESCRIPTOR} --message_fullname=proto_ff.tbRoleInfo --out_path=${GAME_SQL_PATH}/ \



