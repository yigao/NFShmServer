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
${PROTOCGEN_FILE_PATH}/attribute.pb.h ${PROTOCGEN_FILE_PATH}/attribute.pb.cc ${PROTOCGEN_FILE_PATH}/attribute_s.h ${PROTOCGEN_FILE_PATH}/attribute_s.cpp ${PROTOCGEN_FILE_PATH}/attribute.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/attribute.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/attribute.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds  --proto_fname=attribute.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attribute.pb.h ${PROTOCGEN_FILE_PATH}/attribute.pb.cc ${PROTOCGEN_FILE_PATH}/attribute_s.h ${PROTOCGEN_FILE_PATH}/attribute_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/fashion.pb.h ${PROTOCGEN_FILE_PATH}/fashion.pb.cc ${PROTOCGEN_FILE_PATH}/fashion_s.h ${PROTOCGEN_FILE_PATH}/fashion_s.cpp ${PROTOCGEN_FILE_PATH}/fashion.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/fashion.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/fashion.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/fashion.proto.ds  --proto_fname=fashion.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fashion.pb.h ${PROTOCGEN_FILE_PATH}/fashion.pb.cc ${PROTOCGEN_FILE_PATH}/fashion_s.h ${PROTOCGEN_FILE_PATH}/fashion_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/decorate.pb.h ${PROTOCGEN_FILE_PATH}/decorate.pb.cc ${PROTOCGEN_FILE_PATH}/decorate_s.h ${PROTOCGEN_FILE_PATH}/decorate_s.cpp ${PROTOCGEN_FILE_PATH}/decorate.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/decorate.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/decorate.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/decorate.proto.ds  --proto_fname=decorate.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/decorate.pb.h ${PROTOCGEN_FILE_PATH}/decorate.pb.cc ${PROTOCGEN_FILE_PATH}/decorate_s.h ${PROTOCGEN_FILE_PATH}/decorate_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/footprint.pb.h ${PROTOCGEN_FILE_PATH}/footprint.pb.cc ${PROTOCGEN_FILE_PATH}/footprint_s.h ${PROTOCGEN_FILE_PATH}/footprint_s.cpp ${PROTOCGEN_FILE_PATH}/footprint.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/footprint.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/footprint.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/footprint.proto.ds  --proto_fname=footprint.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/footprint.pb.h ${PROTOCGEN_FILE_PATH}/footprint.pb.cc ${PROTOCGEN_FILE_PATH}/footprint_s.h ${PROTOCGEN_FILE_PATH}/footprint_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/halo.pb.h ${PROTOCGEN_FILE_PATH}/halo.pb.cc ${PROTOCGEN_FILE_PATH}/halo_s.h ${PROTOCGEN_FILE_PATH}/halo_s.cpp ${PROTOCGEN_FILE_PATH}/halo.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/halo.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/halo.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/halo.proto.ds  --proto_fname=halo.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/halo.pb.h ${PROTOCGEN_FILE_PATH}/halo.pb.cc ${PROTOCGEN_FILE_PATH}/halo_s.h ${PROTOCGEN_FILE_PATH}/halo_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/headPortrait.pb.h ${PROTOCGEN_FILE_PATH}/headPortrait.pb.cc ${PROTOCGEN_FILE_PATH}/headPortrait_s.h ${PROTOCGEN_FILE_PATH}/headPortrait_s.cpp ${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/headPortrait.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds  --proto_fname=headPortrait.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortrait.pb.h ${PROTOCGEN_FILE_PATH}/headPortrait.pb.cc ${PROTOCGEN_FILE_PATH}/headPortrait_s.h ${PROTOCGEN_FILE_PATH}/headPortrait_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/meditation.pb.h ${PROTOCGEN_FILE_PATH}/meditation.pb.cc ${PROTOCGEN_FILE_PATH}/meditation_s.h ${PROTOCGEN_FILE_PATH}/meditation_s.cpp ${PROTOCGEN_FILE_PATH}/meditation.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/meditation.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/meditation.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/meditation.proto.ds  --proto_fname=meditation.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/meditation.pb.h ${PROTOCGEN_FILE_PATH}/meditation.pb.cc ${PROTOCGEN_FILE_PATH}/meditation_s.h ${PROTOCGEN_FILE_PATH}/meditation_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/functionunlock.pb.h ${PROTOCGEN_FILE_PATH}/functionunlock.pb.cc ${PROTOCGEN_FILE_PATH}/functionunlock_s.h ${PROTOCGEN_FILE_PATH}/functionunlock_s.cpp ${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/functionunlock.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds  --proto_fname=functionunlock.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/functionunlock.pb.h ${PROTOCGEN_FILE_PATH}/functionunlock.pb.cc ${PROTOCGEN_FILE_PATH}/functionunlock_s.h ${PROTOCGEN_FILE_PATH}/functionunlock_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/GMCommand.pb.h ${PROTOCGEN_FILE_PATH}/GMCommand.pb.cc ${PROTOCGEN_FILE_PATH}/GMCommand_s.h ${PROTOCGEN_FILE_PATH}/GMCommand_s.cpp ${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/GMCommand.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds  --proto_fname=GMCommand.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMCommand.pb.h ${PROTOCGEN_FILE_PATH}/GMCommand.pb.cc ${PROTOCGEN_FILE_PATH}/GMCommand_s.h ${PROTOCGEN_FILE_PATH}/GMCommand_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/appearance.pb.h ${PROTOCGEN_FILE_PATH}/appearance.pb.cc ${PROTOCGEN_FILE_PATH}/appearance_s.h ${PROTOCGEN_FILE_PATH}/appearance_s.cpp ${PROTOCGEN_FILE_PATH}/appearance.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/appearance.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/appearance.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/appearance.proto.ds  --proto_fname=appearance.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/appearance.pb.h ${PROTOCGEN_FILE_PATH}/appearance.pb.cc ${PROTOCGEN_FILE_PATH}/appearance_s.h ${PROTOCGEN_FILE_PATH}/appearance_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/link.pb.h ${PROTOCGEN_FILE_PATH}/link.pb.cc ${PROTOCGEN_FILE_PATH}/link_s.h ${PROTOCGEN_FILE_PATH}/link_s.cpp ${PROTOCGEN_FILE_PATH}/link.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/link.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/link.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/link.proto.ds  --proto_fname=link.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/link.pb.h ${PROTOCGEN_FILE_PATH}/link.pb.cc ${PROTOCGEN_FILE_PATH}/link_s.h ${PROTOCGEN_FILE_PATH}/link_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/mail.pb.h ${PROTOCGEN_FILE_PATH}/mail.pb.cc ${PROTOCGEN_FILE_PATH}/mail_s.h ${PROTOCGEN_FILE_PATH}/mail_s.cpp ${PROTOCGEN_FILE_PATH}/mail.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/mail.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mail.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/mail.proto.ds  --proto_fname=mail.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mail.pb.h ${PROTOCGEN_FILE_PATH}/mail.pb.cc ${PROTOCGEN_FILE_PATH}/mail_s.h ${PROTOCGEN_FILE_PATH}/mail_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/chat.pb.h ${PROTOCGEN_FILE_PATH}/chat.pb.cc ${PROTOCGEN_FILE_PATH}/chat_s.h ${PROTOCGEN_FILE_PATH}/chat_s.cpp ${PROTOCGEN_FILE_PATH}/chat.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/chat.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/chat.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds  --proto_fname=chat.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chat.pb.h ${PROTOCGEN_FILE_PATH}/chat.pb.cc ${PROTOCGEN_FILE_PATH}/chat_s.h ${PROTOCGEN_FILE_PATH}/chat_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/path.pb.h ${PROTOCGEN_FILE_PATH}/path.pb.cc ${PROTOCGEN_FILE_PATH}/path_s.h ${PROTOCGEN_FILE_PATH}/path_s.cpp ${PROTOCGEN_FILE_PATH}/path.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/path.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/path.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/path.proto.ds  --proto_fname=path.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/path.pb.h ${PROTOCGEN_FILE_PATH}/path.pb.cc ${PROTOCGEN_FILE_PATH}/path_s.h ${PROTOCGEN_FILE_PATH}/path_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/intimacy.pb.h ${PROTOCGEN_FILE_PATH}/intimacy.pb.cc ${PROTOCGEN_FILE_PATH}/intimacy_s.h ${PROTOCGEN_FILE_PATH}/intimacy_s.cpp ${PROTOCGEN_FILE_PATH}/intimacy.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/intimacy.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds  --proto_fname=intimacy.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/intimacy.pb.h ${PROTOCGEN_FILE_PATH}/intimacy.pb.cc ${PROTOCGEN_FILE_PATH}/intimacy_s.h ${PROTOCGEN_FILE_PATH}/intimacy_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/ai.pb.h ${PROTOCGEN_FILE_PATH}/ai.pb.cc ${PROTOCGEN_FILE_PATH}/ai_s.h ${PROTOCGEN_FILE_PATH}/ai_s.cpp ${PROTOCGEN_FILE_PATH}/ai.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/ai.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ai.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds  --proto_fname=ai.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ai.pb.h ${PROTOCGEN_FILE_PATH}/ai.pb.cc ${PROTOCGEN_FILE_PATH}/ai_s.h ${PROTOCGEN_FILE_PATH}/ai_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/boss.pb.h ${PROTOCGEN_FILE_PATH}/boss.pb.cc ${PROTOCGEN_FILE_PATH}/boss_s.h ${PROTOCGEN_FILE_PATH}/boss_s.cpp ${PROTOCGEN_FILE_PATH}/boss.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/boss.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/boss.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds  --proto_fname=boss.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/boss.pb.h ${PROTOCGEN_FILE_PATH}/boss.pb.cc ${PROTOCGEN_FILE_PATH}/boss_s.h ${PROTOCGEN_FILE_PATH}/boss_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/point.pb.h ${PROTOCGEN_FILE_PATH}/point.pb.cc ${PROTOCGEN_FILE_PATH}/point_s.h ${PROTOCGEN_FILE_PATH}/point_s.cpp ${PROTOCGEN_FILE_PATH}/point.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/point.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/point.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/point.proto.ds  --proto_fname=point.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/point.pb.h ${PROTOCGEN_FILE_PATH}/point.pb.cc ${PROTOCGEN_FILE_PATH}/point_s.h ${PROTOCGEN_FILE_PATH}/point_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/facade.pb.h ${PROTOCGEN_FILE_PATH}/facade.pb.cc ${PROTOCGEN_FILE_PATH}/facade_s.h ${PROTOCGEN_FILE_PATH}/facade_s.cpp ${PROTOCGEN_FILE_PATH}/facade.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/facade.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/facade.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds  --proto_fname=facade.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facade.pb.h ${PROTOCGEN_FILE_PATH}/facade.pb.cc ${PROTOCGEN_FILE_PATH}/facade_s.h ${PROTOCGEN_FILE_PATH}/facade_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/dup.pb.h ${PROTOCGEN_FILE_PATH}/dup.pb.cc ${PROTOCGEN_FILE_PATH}/dup_s.h ${PROTOCGEN_FILE_PATH}/dup_s.cpp ${PROTOCGEN_FILE_PATH}/dup.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/dup.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/dup.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds  --proto_fname=dup.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dup.pb.h ${PROTOCGEN_FILE_PATH}/dup.pb.cc ${PROTOCGEN_FILE_PATH}/dup_s.h ${PROTOCGEN_FILE_PATH}/dup_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/offline.pb.h ${PROTOCGEN_FILE_PATH}/offline.pb.cc ${PROTOCGEN_FILE_PATH}/offline_s.h ${PROTOCGEN_FILE_PATH}/offline_s.cpp ${PROTOCGEN_FILE_PATH}/offline.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/offline.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/offline.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds  --proto_fname=offline.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/offline.pb.h ${PROTOCGEN_FILE_PATH}/offline.pb.cc ${PROTOCGEN_FILE_PATH}/offline_s.h ${PROTOCGEN_FILE_PATH}/offline_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/godRelics.pb.h ${PROTOCGEN_FILE_PATH}/godRelics.pb.cc ${PROTOCGEN_FILE_PATH}/godRelics_s.h ${PROTOCGEN_FILE_PATH}/godRelics_s.cpp ${PROTOCGEN_FILE_PATH}/godRelics.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/godRelics.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds  --proto_fname=godRelics.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godRelics.pb.h ${PROTOCGEN_FILE_PATH}/godRelics.pb.cc ${PROTOCGEN_FILE_PATH}/godRelics_s.h ${PROTOCGEN_FILE_PATH}/godRelics_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/condition.pb.h ${PROTOCGEN_FILE_PATH}/condition.pb.cc ${PROTOCGEN_FILE_PATH}/condition_s.h ${PROTOCGEN_FILE_PATH}/condition_s.cpp ${PROTOCGEN_FILE_PATH}/condition.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/condition.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/condition.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/condition.proto.ds  --proto_fname=condition.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/condition.pb.h ${PROTOCGEN_FILE_PATH}/condition.pb.cc ${PROTOCGEN_FILE_PATH}/condition_s.h ${PROTOCGEN_FILE_PATH}/condition_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/audio.pb.h ${PROTOCGEN_FILE_PATH}/audio.pb.cc ${PROTOCGEN_FILE_PATH}/audio_s.h ${PROTOCGEN_FILE_PATH}/audio_s.cpp ${PROTOCGEN_FILE_PATH}/audio.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/audio.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/audio.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/audio.proto.ds  --proto_fname=audio.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/audio.pb.h ${PROTOCGEN_FILE_PATH}/audio.pb.cc ${PROTOCGEN_FILE_PATH}/audio_s.h ${PROTOCGEN_FILE_PATH}/audio_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/perActivity.pb.h ${PROTOCGEN_FILE_PATH}/perActivity.pb.cc ${PROTOCGEN_FILE_PATH}/perActivity_s.h ${PROTOCGEN_FILE_PATH}/perActivity_s.cpp ${PROTOCGEN_FILE_PATH}/perActivity.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/perActivity.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds  --proto_fname=perActivity.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/perActivity.pb.h ${PROTOCGEN_FILE_PATH}/perActivity.pb.cc ${PROTOCGEN_FILE_PATH}/perActivity_s.h ${PROTOCGEN_FILE_PATH}/perActivity_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/daily.pb.h ${PROTOCGEN_FILE_PATH}/daily.pb.cc ${PROTOCGEN_FILE_PATH}/daily_s.h ${PROTOCGEN_FILE_PATH}/daily_s.cpp ${PROTOCGEN_FILE_PATH}/daily.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/daily.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/daily.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds  --proto_fname=daily.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/daily.pb.h ${PROTOCGEN_FILE_PATH}/daily.pb.cc ${PROTOCGEN_FILE_PATH}/daily_s.h ${PROTOCGEN_FILE_PATH}/daily_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/back.pb.h ${PROTOCGEN_FILE_PATH}/back.pb.cc ${PROTOCGEN_FILE_PATH}/back_s.h ${PROTOCGEN_FILE_PATH}/back_s.cpp ${PROTOCGEN_FILE_PATH}/back.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/back.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/back.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/back.proto.ds  --proto_fname=back.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/back.pb.h ${PROTOCGEN_FILE_PATH}/back.pb.cc ${PROTOCGEN_FILE_PATH}/back_s.h ${PROTOCGEN_FILE_PATH}/back_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/set.pb.h ${PROTOCGEN_FILE_PATH}/set.pb.cc ${PROTOCGEN_FILE_PATH}/set_s.h ${PROTOCGEN_FILE_PATH}/set_s.cpp ${PROTOCGEN_FILE_PATH}/set.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/set.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/set.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/set.proto.ds  --proto_fname=set.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/set.pb.h ${PROTOCGEN_FILE_PATH}/set.pb.cc ${PROTOCGEN_FILE_PATH}/set_s.h ${PROTOCGEN_FILE_PATH}/set_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/team.pb.h ${PROTOCGEN_FILE_PATH}/team.pb.cc ${PROTOCGEN_FILE_PATH}/team_s.h ${PROTOCGEN_FILE_PATH}/team_s.cpp ${PROTOCGEN_FILE_PATH}/team.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/team.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/team.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/team.proto.ds  --proto_fname=team.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/team.pb.h ${PROTOCGEN_FILE_PATH}/team.pb.cc ${PROTOCGEN_FILE_PATH}/team_s.h ${PROTOCGEN_FILE_PATH}/team_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/box.pb.h ${PROTOCGEN_FILE_PATH}/box.pb.cc ${PROTOCGEN_FILE_PATH}/box_s.h ${PROTOCGEN_FILE_PATH}/box_s.cpp ${PROTOCGEN_FILE_PATH}/box.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/box.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/box.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds  --proto_fname=box.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/box.pb.h ${PROTOCGEN_FILE_PATH}/box.pb.cc ${PROTOCGEN_FILE_PATH}/box_s.h ${PROTOCGEN_FILE_PATH}/box_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/task.pb.h ${PROTOCGEN_FILE_PATH}/task.pb.cc ${PROTOCGEN_FILE_PATH}/task_s.h ${PROTOCGEN_FILE_PATH}/task_s.cpp ${PROTOCGEN_FILE_PATH}/task.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/task.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/task.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/task.proto.ds  --proto_fname=task.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/task.pb.h ${PROTOCGEN_FILE_PATH}/task.pb.cc ${PROTOCGEN_FILE_PATH}/task_s.h ${PROTOCGEN_FILE_PATH}/task_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/taskdynamic.pb.h ${PROTOCGEN_FILE_PATH}/taskdynamic.pb.cc ${PROTOCGEN_FILE_PATH}/taskdynamic_s.h ${PROTOCGEN_FILE_PATH}/taskdynamic_s.cpp ${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/taskdynamic.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds  --proto_fname=taskdynamic.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskdynamic.pb.h ${PROTOCGEN_FILE_PATH}/taskdynamic.pb.cc ${PROTOCGEN_FILE_PATH}/taskdynamic_s.h ${PROTOCGEN_FILE_PATH}/taskdynamic_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/taskreward.pb.h ${PROTOCGEN_FILE_PATH}/taskreward.pb.cc ${PROTOCGEN_FILE_PATH}/taskreward_s.h ${PROTOCGEN_FILE_PATH}/taskreward_s.cpp ${PROTOCGEN_FILE_PATH}/taskreward.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/taskreward.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds  --proto_fname=taskreward.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskreward.pb.h ${PROTOCGEN_FILE_PATH}/taskreward.pb.cc ${PROTOCGEN_FILE_PATH}/taskreward_s.h ${PROTOCGEN_FILE_PATH}/taskreward_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/tasktracker.pb.h ${PROTOCGEN_FILE_PATH}/tasktracker.pb.cc ${PROTOCGEN_FILE_PATH}/tasktracker_s.h ${PROTOCGEN_FILE_PATH}/tasktracker_s.cpp ${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/tasktracker.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds  --proto_fname=tasktracker.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/tasktracker.pb.h ${PROTOCGEN_FILE_PATH}/tasktracker.pb.cc ${PROTOCGEN_FILE_PATH}/tasktracker_s.h ${PROTOCGEN_FILE_PATH}/tasktracker_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/flash.pb.h ${PROTOCGEN_FILE_PATH}/flash.pb.cc ${PROTOCGEN_FILE_PATH}/flash_s.h ${PROTOCGEN_FILE_PATH}/flash_s.cpp ${PROTOCGEN_FILE_PATH}/flash.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/flash.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/flash.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds  --proto_fname=flash.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/flash.pb.h ${PROTOCGEN_FILE_PATH}/flash.pb.cc ${PROTOCGEN_FILE_PATH}/flash_s.h ${PROTOCGEN_FILE_PATH}/flash_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/button.pb.h ${PROTOCGEN_FILE_PATH}/button.pb.cc ${PROTOCGEN_FILE_PATH}/button_s.h ${PROTOCGEN_FILE_PATH}/button_s.cpp ${PROTOCGEN_FILE_PATH}/button.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/button.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/button.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/button.proto.ds  --proto_fname=button.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/button.pb.h ${PROTOCGEN_FILE_PATH}/button.pb.cc ${PROTOCGEN_FILE_PATH}/button_s.h ${PROTOCGEN_FILE_PATH}/button_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/vip.pb.h ${PROTOCGEN_FILE_PATH}/vip.pb.cc ${PROTOCGEN_FILE_PATH}/vip_s.h ${PROTOCGEN_FILE_PATH}/vip_s.cpp ${PROTOCGEN_FILE_PATH}/vip.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/vip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/vip.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/vip.proto.ds  --proto_fname=vip.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/vip.pb.h ${PROTOCGEN_FILE_PATH}/vip.pb.cc ${PROTOCGEN_FILE_PATH}/vip_s.h ${PROTOCGEN_FILE_PATH}/vip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/arena.pb.h ${PROTOCGEN_FILE_PATH}/arena.pb.cc ${PROTOCGEN_FILE_PATH}/arena_s.h ${PROTOCGEN_FILE_PATH}/arena_s.cpp ${PROTOCGEN_FILE_PATH}/arena.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/arena.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/arena.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds  --proto_fname=arena.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arena.pb.h ${PROTOCGEN_FILE_PATH}/arena.pb.cc ${PROTOCGEN_FILE_PATH}/arena_s.h ${PROTOCGEN_FILE_PATH}/arena_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
