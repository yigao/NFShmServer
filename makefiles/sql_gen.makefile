include ./define.makefile

.PHONY:all

all:${SQL_FILE}

${GAME_SQL_PATH}/create_tbAccountTable.sql:${PROTOCOL_COMM_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${PROTOCOL_COMM_DESCRIPTOR} --message_fullname=proto_ff.tbAccountTable --out_path=${GAME_SQL_PATH}/ \

${GAME_SQL_PATH}/create_tbUserDetailData.sql:${PROTOCOL_COMM_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${PROTOCOL_COMM_DESCRIPTOR} --message_fullname=proto_ff.tbUserDetailData --out_path=${GAME_SQL_PATH}/ \

${GAME_SQL_PATH}/create_tbUserSimpleData.sql:${PROTOCOL_COMM_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${PROTOCOL_COMM_DESCRIPTOR} --message_fullname=proto_ff.tbUserSimpleData --out_path=${GAME_SQL_PATH}/ \

${GAME_SQL_PATH}/create_ConstDesc.sql:${RESDB_META_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${RESDB_META_DESCRIPTOR} --message_fullname=proto_ff.ConstDesc --out_path=${GAME_SQL_PATH}/ \
	--sheet_fullname=proto_ff.Sheet_ConstDesc --bin_filename=${GAME_DATA_PATH}/ConstDesc.bin

${GAME_SQL_PATH}/create_tbEventLog.sql:${PROTOCOL_COMM_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${PROTOCOL_COMM_DESCRIPTOR} --message_fullname=proto_ff.tbEventLog --out_path=${GAME_SQL_PATH}/ \

${GAME_SQL_PATH}/create_NameDesc.sql:${RESDB_META_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${RESDB_META_DESCRIPTOR} --message_fullname=proto_ff.NameDesc --out_path=${GAME_SQL_PATH}/ \
	--sheet_fullname=proto_ff.Sheet_NameDesc --bin_filename=${GAME_DATA_PATH}/NameDesc.bin

