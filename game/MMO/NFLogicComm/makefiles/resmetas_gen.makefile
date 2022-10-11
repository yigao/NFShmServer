include ./define.makefile

.PHONY:all

all:${RESDB_DESC_H} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_H} ${RESDB_DESC_STRUCT_CPP}

${PROTOCGEN_FILE_PATH}/msg.pb.h ${PROTOCGEN_FILE_PATH}/msg.pb.cc ${PROTOCGEN_FILE_PATH}/msg_s.h ${PROTOCGEN_FILE_PATH}/msg_s.cpp ${PROTOCGEN_FILE_PATH}/msg.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/msg.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/msg.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/msg.proto.ds  --proto_fname=msg.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/msg.pb.h ${PROTOCGEN_FILE_PATH}/msg.pb.cc ${PROTOCGEN_FILE_PATH}/msg_s.h ${PROTOCGEN_FILE_PATH}/msg_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/ui.pb.h ${PROTOCGEN_FILE_PATH}/ui.pb.cc ${PROTOCGEN_FILE_PATH}/ui_s.h ${PROTOCGEN_FILE_PATH}/ui_s.cpp ${PROTOCGEN_FILE_PATH}/ui.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/ui.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ui.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/ui.proto.ds  --proto_fname=ui.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ui.pb.h ${PROTOCGEN_FILE_PATH}/ui.pb.cc ${PROTOCGEN_FILE_PATH}/ui_s.h ${PROTOCGEN_FILE_PATH}/ui_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/role.pb.h ${PROTOCGEN_FILE_PATH}/role.pb.cc ${PROTOCGEN_FILE_PATH}/role_s.h ${PROTOCGEN_FILE_PATH}/role_s.cpp ${PROTOCGEN_FILE_PATH}/role.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/role.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/role.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds  --proto_fname=role.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/role.pb.h ${PROTOCGEN_FILE_PATH}/role.pb.cc ${PROTOCGEN_FILE_PATH}/role_s.h ${PROTOCGEN_FILE_PATH}/role_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/randomname.pb.h ${PROTOCGEN_FILE_PATH}/randomname.pb.cc ${PROTOCGEN_FILE_PATH}/randomname_s.h ${PROTOCGEN_FILE_PATH}/randomname_s.cpp ${PROTOCGEN_FILE_PATH}/randomname.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/randomname.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/randomname.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds  --proto_fname=randomname.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomname.pb.h ${PROTOCGEN_FILE_PATH}/randomname.pb.cc ${PROTOCGEN_FILE_PATH}/randomname_s.h ${PROTOCGEN_FILE_PATH}/randomname_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/sensitiveword.pb.h ${PROTOCGEN_FILE_PATH}/sensitiveword.pb.cc ${PROTOCGEN_FILE_PATH}/sensitiveword_s.h ${PROTOCGEN_FILE_PATH}/sensitiveword_s.cpp ${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/sensitiveword.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds  --proto_fname=sensitiveword.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/sensitiveword.pb.h ${PROTOCGEN_FILE_PATH}/sensitiveword.pb.cc ${PROTOCGEN_FILE_PATH}/sensitiveword_s.h ${PROTOCGEN_FILE_PATH}/sensitiveword_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/login.pb.h ${PROTOCGEN_FILE_PATH}/login.pb.cc ${PROTOCGEN_FILE_PATH}/login_s.h ${PROTOCGEN_FILE_PATH}/login_s.cpp ${PROTOCGEN_FILE_PATH}/login.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/login.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/login.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/login.proto.ds  --proto_fname=login.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/login.pb.h ${PROTOCGEN_FILE_PATH}/login.pb.cc ${PROTOCGEN_FILE_PATH}/login_s.h ${PROTOCGEN_FILE_PATH}/login_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/map.pb.h ${PROTOCGEN_FILE_PATH}/map.pb.cc ${PROTOCGEN_FILE_PATH}/map_s.h ${PROTOCGEN_FILE_PATH}/map_s.cpp ${PROTOCGEN_FILE_PATH}/map.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/map.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/map.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds  --proto_fname=map.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/map.pb.h ${PROTOCGEN_FILE_PATH}/map.pb.cc ${PROTOCGEN_FILE_PATH}/map_s.h ${PROTOCGEN_FILE_PATH}/map_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/monster.pb.h ${PROTOCGEN_FILE_PATH}/monster.pb.cc ${PROTOCGEN_FILE_PATH}/monster_s.h ${PROTOCGEN_FILE_PATH}/monster_s.cpp ${PROTOCGEN_FILE_PATH}/monster.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/monster.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/monster.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds  --proto_fname=monster.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monster.pb.h ${PROTOCGEN_FILE_PATH}/monster.pb.cc ${PROTOCGEN_FILE_PATH}/monster_s.h ${PROTOCGEN_FILE_PATH}/monster_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/area.pb.h ${PROTOCGEN_FILE_PATH}/area.pb.cc ${PROTOCGEN_FILE_PATH}/area_s.h ${PROTOCGEN_FILE_PATH}/area_s.cpp ${PROTOCGEN_FILE_PATH}/area.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/area.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/area.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds  --proto_fname=area.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/area.pb.h ${PROTOCGEN_FILE_PATH}/area.pb.cc ${PROTOCGEN_FILE_PATH}/area_s.h ${PROTOCGEN_FILE_PATH}/area_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/skill.pb.h ${PROTOCGEN_FILE_PATH}/skill.pb.cc ${PROTOCGEN_FILE_PATH}/skill_s.h ${PROTOCGEN_FILE_PATH}/skill_s.cpp ${PROTOCGEN_FILE_PATH}/skill.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/skill.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/skill.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds  --proto_fname=skill.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skill.pb.h ${PROTOCGEN_FILE_PATH}/skill.pb.cc ${PROTOCGEN_FILE_PATH}/skill_s.h ${PROTOCGEN_FILE_PATH}/skill_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/item.pb.h ${PROTOCGEN_FILE_PATH}/item.pb.cc ${PROTOCGEN_FILE_PATH}/item_s.h ${PROTOCGEN_FILE_PATH}/item_s.cpp ${PROTOCGEN_FILE_PATH}/item.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/item.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/item.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/item.proto.ds  --proto_fname=item.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/item.pb.h ${PROTOCGEN_FILE_PATH}/item.pb.cc ${PROTOCGEN_FILE_PATH}/item_s.h ${PROTOCGEN_FILE_PATH}/item_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/equip.pb.h ${PROTOCGEN_FILE_PATH}/equip.pb.cc ${PROTOCGEN_FILE_PATH}/equip_s.h ${PROTOCGEN_FILE_PATH}/equip_s.cpp ${PROTOCGEN_FILE_PATH}/equip.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/equip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/equip.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds  --proto_fname=equip.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equip.pb.h ${PROTOCGEN_FILE_PATH}/equip.pb.cc ${PROTOCGEN_FILE_PATH}/equip_s.h ${PROTOCGEN_FILE_PATH}/equip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp ${PROTOCGEN_FILE_PATH}/constant.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/constant.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/constant.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds  --proto_fname=constant.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
