include ./define.makefile

.PHONY:all

all:${SQL_FILE}

${GAME_SQL_PATH}/create_ConstDesc.sql:${RESDB_META_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${RESDB_META_DESCRIPTOR} --message_fullname=proto_ff.ConstDesc --out_path=${GAME_SQL_PATH}/ \
	--sheet_fullname=proto_ff.Sheet_ConstDesc --bin_filename=${GAME_DATA_PATH}/ConstDesc.bin

${GAME_SQL_PATH}/create_NameDesc.sql:${RESDB_META_DESCRIPTOR}
	${PROTO2SQL} --proto_ds=${RESDB_META_DESCRIPTOR} --message_fullname=proto_ff.NameDesc --out_path=${GAME_SQL_PATH}/ \
	--sheet_fullname=proto_ff.Sheet_NameDesc --bin_filename=${GAME_DATA_PATH}/NameDesc.bin

