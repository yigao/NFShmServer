include ./define.makefile

.PHONY:all

all:${GAME_SQL_PATH}/create_RoleDBData.sql ${GAME_SQL_PATH}/create_RoleDBSnsDetail.sql ${GAME_SQL_PATH}/create_dbServerMgr.sql

${GAME_SQL_PATH}/create_RoleDBData.sql:${COMMON_LOGIC_META_DESCRIPTOR}
	mkdir -p ${GAME_SQL_PATH}
	${PROTO2SQL} --proto_ds=${COMMON_LOGIC_META_DESCRIPTOR} --message_fullname=proto_ff.RoleDBData --out_path=${GAME_SQL_PATH}/ \

${GAME_SQL_PATH}/create_RoleDBSnsDetail.sql:${COMMON_LOGIC_META_DESCRIPTOR}
	mkdir -p ${GAME_SQL_PATH}
	${PROTO2SQL} --proto_ds=${COMMON_LOGIC_META_DESCRIPTOR} --message_fullname=proto_ff.RoleDBSnsDetail --out_path=${GAME_SQL_PATH}/ \

${GAME_SQL_PATH}/create_dbServerMgr.sql:${COMMON_LOGIC_META_DESCRIPTOR}
	mkdir -p ${GAME_SQL_PATH}
	${PROTO2SQL} --proto_ds=${COMMON_LOGIC_META_DESCRIPTOR} --message_fullname=proto_ff.dbServerMgr --out_path=${GAME_SQL_PATH}/ \

