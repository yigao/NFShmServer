include ./define.makefile
.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_ss ${PROTOCGEN_FILE_PATH}/module_hcpp ${PROTOCGEN_FILE_PATH}/module_descstore ${PROTOCGEN_FILE_PATH}/common_ds

${PROTOCGEN_FILE_PATH}/module_ss :${PROTOCOL_SS_LOGIC_XML} ${PROTOCOL_COMM_XML} ${PROTOCOL_FIELD_XML}
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_ss
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_PATH} -I${PROTOCOL_SS_LOGIC_PATH}  -I${PROTOCOL_CS_LOGIC_PATH} -I${COMMON_LOGIC_META_PATH} -I${PROTOCOL_KERNEL_PATH}\
		--cpp_out=${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCOL_SS_LOGIC_H} ${PROTOCOL_SS_LOGIC_CPP}" --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_ss

${PROTOCGEN_FILE_PATH}/module_hcpp :${PROTOCOL_CS_LOGIC_XML} ${PROTOCOL_COMM_XML} ${PROTOCOL_FIELD_XML}
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_hcpp
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_CS_LOGIC_PATH} -I${COMMON_LOGIC_META_PATH} -I${PROTOCOL_KERNEL_PATH}\
		--cpp_out=${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCOL_CS_LOGIC_H} ${PROTOCOL_CS_LOGIC_CPP}" --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_hcpp

${PROTOCGEN_FILE_PATH}/module_descstore:${PROTOCGEN_FILE_PATH}/NFDescStoreHead.h ${PROTOCGEN_FILE_PATH}/NFDescStoreDefine.h ${PROTOCGEN_FILE_PATH}/NFDescStoreRegister.h
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_descstore
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/NFDescStoreHead.h" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/NFDescStoreDefine.h" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/NFDescStoreRegister.h" --dst=${DESC_STORE_PATH}/
	echo "" >> ${DESC_STORE_PATH}/NFDescStoreHead.h
	echo "" >> ${DESC_STORE_PATH}/NFDescStoreDefine.h
	echo "" >> ${DESC_STORE_PATH}/NFDescStoreRegister.h
	touch ${PROTOCGEN_FILE_PATH}/module_descstore

#${RESDB_DESC_H} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_H} ${RESDB_DESC_STRUCT_CPP} ${RESDB_META_DESCRIPTOR}:${RESDB_DESC_XML} ${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML}
#	mkdir -p ${PROTOCGEN_FILE_PATH}
#	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH}\
#			--include_imports --descriptor_set_out=${RESDB_META_DESCRIPTOR} --cpp_out=${PROTOCGEN_FILE_PATH}
#	for xml in $(RESDB_DESC_XML2);do\
#		${PROTO2STRUCT} --proto_ds=${RESDB_META_DESCRIPTOR} --proto_fname=$$xml --out_path=${PROTOCGEN_FILE_PATH}/;\
#		echo $$xml;\
#	done
#	${FILE_COPY_EXE} --src="${RESDB_DESC_H} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_H} ${RESDB_DESC_STRUCT_CPP}" --dst=${NEW_PROTOCGEN_FILE_PATH}/


${PROTOCGEN_FILE_PATH}/common_ds:${COMMON_LOGIC_DESC_XML} ${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML}
	mkdir -p ${PROTOCGEN_FILE_PATH}
	mkdir -p ${GAME_SQL_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/common_ds
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} -I${COMMON_LOGIC_META_PATH}\
			--include_imports --descriptor_set_out=${COMMON_LOGIC_META_DESCRIPTOR} --cpp_out=${PROTOCGEN_FILE_PATH}
	for xml in $(COMMON_LOGIC_DESC_XML2);do\
		${PROTO2STRUCT} --proto_ds=${COMMON_LOGIC_META_DESCRIPTOR} --proto_fname=$$xml --out_path=${PROTOCGEN_FILE_PATH}/;\
		echo $$xml;\
	done
	${FILE_COPY_EXE} --src="${COMMON_LOGIC_DESC_H} ${COMMON_LOGIC_DESC_CPP} ${COMMON_LOGIC_DESC_STRUCT_H} ${COMMON_LOGIC_DESC_STRUCT_CPP}" --dst=${NEW_PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${COMMON_LOGIC_META_DESCRIPTOR} " --dst=${GAME_SQL_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/common_ds
