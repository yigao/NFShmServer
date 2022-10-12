include ./define.makefile

.PHONY:all

all:${RESDB_DESC_H} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_H} ${RESDB_DESC_STRUCT_CPP}

${PROTOCGEN_FILE_PATH}/achievement.pb.h ${PROTOCGEN_FILE_PATH}/achievement.pb.cc ${PROTOCGEN_FILE_PATH}/achievement_s.h ${PROTOCGEN_FILE_PATH}/achievement_s.cpp ${PROTOCGEN_FILE_PATH}/achievement.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/achievement.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/achievement.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds  --proto_fname=achievement.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/achievement.pb.h ${PROTOCGEN_FILE_PATH}/achievement.pb.cc ${PROTOCGEN_FILE_PATH}/achievement_s.h ${PROTOCGEN_FILE_PATH}/achievement_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/activity.pb.h ${PROTOCGEN_FILE_PATH}/activity.pb.cc ${PROTOCGEN_FILE_PATH}/activity_s.h ${PROTOCGEN_FILE_PATH}/activity_s.cpp ${PROTOCGEN_FILE_PATH}/activity.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/activity.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/activity.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/activity.proto.ds  --proto_fname=activity.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activity.pb.h ${PROTOCGEN_FILE_PATH}/activity.pb.cc ${PROTOCGEN_FILE_PATH}/activity_s.h ${PROTOCGEN_FILE_PATH}/activity_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/ai.pb.h ${PROTOCGEN_FILE_PATH}/ai.pb.cc ${PROTOCGEN_FILE_PATH}/ai_s.h ${PROTOCGEN_FILE_PATH}/ai_s.cpp ${PROTOCGEN_FILE_PATH}/ai.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/ai.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ai.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds  --proto_fname=ai.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ai.pb.h ${PROTOCGEN_FILE_PATH}/ai.pb.cc ${PROTOCGEN_FILE_PATH}/ai_s.h ${PROTOCGEN_FILE_PATH}/ai_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/area.pb.h ${PROTOCGEN_FILE_PATH}/area.pb.cc ${PROTOCGEN_FILE_PATH}/area_s.h ${PROTOCGEN_FILE_PATH}/area_s.cpp ${PROTOCGEN_FILE_PATH}/area.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/area.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/area.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds  --proto_fname=area.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/area.pb.h ${PROTOCGEN_FILE_PATH}/area.pb.cc ${PROTOCGEN_FILE_PATH}/area_s.h ${PROTOCGEN_FILE_PATH}/area_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/arena.pb.h ${PROTOCGEN_FILE_PATH}/arena.pb.cc ${PROTOCGEN_FILE_PATH}/arena_s.h ${PROTOCGEN_FILE_PATH}/arena_s.cpp ${PROTOCGEN_FILE_PATH}/arena.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/arena.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/arena.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds  --proto_fname=arena.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arena.pb.h ${PROTOCGEN_FILE_PATH}/arena.pb.cc ${PROTOCGEN_FILE_PATH}/arena_s.h ${PROTOCGEN_FILE_PATH}/arena_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/artifact.pb.h ${PROTOCGEN_FILE_PATH}/artifact.pb.cc ${PROTOCGEN_FILE_PATH}/artifact_s.h ${PROTOCGEN_FILE_PATH}/artifact_s.cpp ${PROTOCGEN_FILE_PATH}/artifact.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/artifact.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/artifact.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/artifact.proto.ds  --proto_fname=artifact.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/artifact.pb.h ${PROTOCGEN_FILE_PATH}/artifact.pb.cc ${PROTOCGEN_FILE_PATH}/artifact_s.h ${PROTOCGEN_FILE_PATH}/artifact_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/attribute.pb.h ${PROTOCGEN_FILE_PATH}/attribute.pb.cc ${PROTOCGEN_FILE_PATH}/attribute_s.h ${PROTOCGEN_FILE_PATH}/attribute_s.cpp ${PROTOCGEN_FILE_PATH}/attribute.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/attribute.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/attribute.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds  --proto_fname=attribute.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attribute.pb.h ${PROTOCGEN_FILE_PATH}/attribute.pb.cc ${PROTOCGEN_FILE_PATH}/attribute_s.h ${PROTOCGEN_FILE_PATH}/attribute_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/auction.pb.h ${PROTOCGEN_FILE_PATH}/auction.pb.cc ${PROTOCGEN_FILE_PATH}/auction_s.h ${PROTOCGEN_FILE_PATH}/auction_s.cpp ${PROTOCGEN_FILE_PATH}/auction.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/auction.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/auction.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/auction.proto.ds  --proto_fname=auction.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/auction.pb.h ${PROTOCGEN_FILE_PATH}/auction.pb.cc ${PROTOCGEN_FILE_PATH}/auction_s.h ${PROTOCGEN_FILE_PATH}/auction_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/audio.pb.h ${PROTOCGEN_FILE_PATH}/audio.pb.cc ${PROTOCGEN_FILE_PATH}/audio_s.h ${PROTOCGEN_FILE_PATH}/audio_s.cpp ${PROTOCGEN_FILE_PATH}/audio.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/audio.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/audio.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/audio.proto.ds  --proto_fname=audio.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/audio.pb.h ${PROTOCGEN_FILE_PATH}/audio.pb.cc ${PROTOCGEN_FILE_PATH}/audio_s.h ${PROTOCGEN_FILE_PATH}/audio_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/back.pb.h ${PROTOCGEN_FILE_PATH}/back.pb.cc ${PROTOCGEN_FILE_PATH}/back_s.h ${PROTOCGEN_FILE_PATH}/back_s.cpp ${PROTOCGEN_FILE_PATH}/back.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/back.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/back.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/back.proto.ds  --proto_fname=back.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/back.pb.h ${PROTOCGEN_FILE_PATH}/back.pb.cc ${PROTOCGEN_FILE_PATH}/back_s.h ${PROTOCGEN_FILE_PATH}/back_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/box.pb.h ${PROTOCGEN_FILE_PATH}/box.pb.cc ${PROTOCGEN_FILE_PATH}/box_s.h ${PROTOCGEN_FILE_PATH}/box_s.cpp ${PROTOCGEN_FILE_PATH}/box.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/box.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/box.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds  --proto_fname=box.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/box.pb.h ${PROTOCGEN_FILE_PATH}/box.pb.cc ${PROTOCGEN_FILE_PATH}/box_s.h ${PROTOCGEN_FILE_PATH}/box_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/button.pb.h ${PROTOCGEN_FILE_PATH}/button.pb.cc ${PROTOCGEN_FILE_PATH}/button_s.h ${PROTOCGEN_FILE_PATH}/button_s.cpp ${PROTOCGEN_FILE_PATH}/button.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/button.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/button.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/button.proto.ds  --proto_fname=button.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/button.pb.h ${PROTOCGEN_FILE_PATH}/button.pb.cc ${PROTOCGEN_FILE_PATH}/button_s.h ${PROTOCGEN_FILE_PATH}/button_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/chat.pb.h ${PROTOCGEN_FILE_PATH}/chat.pb.cc ${PROTOCGEN_FILE_PATH}/chat_s.h ${PROTOCGEN_FILE_PATH}/chat_s.cpp ${PROTOCGEN_FILE_PATH}/chat.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/chat.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/chat.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds  --proto_fname=chat.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chat.pb.h ${PROTOCGEN_FILE_PATH}/chat.pb.cc ${PROTOCGEN_FILE_PATH}/chat_s.h ${PROTOCGEN_FILE_PATH}/chat_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/combine.pb.h ${PROTOCGEN_FILE_PATH}/combine.pb.cc ${PROTOCGEN_FILE_PATH}/combine_s.h ${PROTOCGEN_FILE_PATH}/combine_s.cpp ${PROTOCGEN_FILE_PATH}/combine.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/combine.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/combine.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/combine.proto.ds  --proto_fname=combine.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combine.pb.h ${PROTOCGEN_FILE_PATH}/combine.pb.cc ${PROTOCGEN_FILE_PATH}/combine_s.h ${PROTOCGEN_FILE_PATH}/combine_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp ${PROTOCGEN_FILE_PATH}/constant.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/constant.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/constant.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds  --proto_fname=constant.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.pb.h ${PROTOCGEN_FILE_PATH}/constant.pb.cc ${PROTOCGEN_FILE_PATH}/constant_s.h ${PROTOCGEN_FILE_PATH}/constant_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/drop.pb.h ${PROTOCGEN_FILE_PATH}/drop.pb.cc ${PROTOCGEN_FILE_PATH}/drop_s.h ${PROTOCGEN_FILE_PATH}/drop_s.cpp ${PROTOCGEN_FILE_PATH}/drop.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/drop.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/drop.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/drop.proto.ds  --proto_fname=drop.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/drop.pb.h ${PROTOCGEN_FILE_PATH}/drop.pb.cc ${PROTOCGEN_FILE_PATH}/drop_s.h ${PROTOCGEN_FILE_PATH}/drop_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/duplicate.pb.h ${PROTOCGEN_FILE_PATH}/duplicate.pb.cc ${PROTOCGEN_FILE_PATH}/duplicate_s.h ${PROTOCGEN_FILE_PATH}/duplicate_s.cpp ${PROTOCGEN_FILE_PATH}/duplicate.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/duplicate.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/duplicate.proto.ds  --proto_fname=duplicate.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicate.pb.h ${PROTOCGEN_FILE_PATH}/duplicate.pb.cc ${PROTOCGEN_FILE_PATH}/duplicate_s.h ${PROTOCGEN_FILE_PATH}/duplicate_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/dynamicexp.pb.h ${PROTOCGEN_FILE_PATH}/dynamicexp.pb.cc ${PROTOCGEN_FILE_PATH}/dynamicexp_s.h ${PROTOCGEN_FILE_PATH}/dynamicexp_s.cpp ${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/dynamicexp.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/dynamicexp.proto.ds  --proto_fname=dynamicexp.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dynamicexp.pb.h ${PROTOCGEN_FILE_PATH}/dynamicexp.pb.cc ${PROTOCGEN_FILE_PATH}/dynamicexp_s.h ${PROTOCGEN_FILE_PATH}/dynamicexp_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/effect.pb.h ${PROTOCGEN_FILE_PATH}/effect.pb.cc ${PROTOCGEN_FILE_PATH}/effect_s.h ${PROTOCGEN_FILE_PATH}/effect_s.cpp ${PROTOCGEN_FILE_PATH}/effect.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/effect.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/effect.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/effect.proto.ds  --proto_fname=effect.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/effect.pb.h ${PROTOCGEN_FILE_PATH}/effect.pb.cc ${PROTOCGEN_FILE_PATH}/effect_s.h ${PROTOCGEN_FILE_PATH}/effect_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/element.pb.h ${PROTOCGEN_FILE_PATH}/element.pb.cc ${PROTOCGEN_FILE_PATH}/element_s.h ${PROTOCGEN_FILE_PATH}/element_s.cpp ${PROTOCGEN_FILE_PATH}/element.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/element.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/element.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/element.proto.ds  --proto_fname=element.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/element.pb.h ${PROTOCGEN_FILE_PATH}/element.pb.cc ${PROTOCGEN_FILE_PATH}/element_s.h ${PROTOCGEN_FILE_PATH}/element_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/equip.pb.h ${PROTOCGEN_FILE_PATH}/equip.pb.cc ${PROTOCGEN_FILE_PATH}/equip_s.h ${PROTOCGEN_FILE_PATH}/equip_s.cpp ${PROTOCGEN_FILE_PATH}/equip.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/equip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/equip.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds  --proto_fname=equip.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equip.pb.h ${PROTOCGEN_FILE_PATH}/equip.pb.cc ${PROTOCGEN_FILE_PATH}/equip_s.h ${PROTOCGEN_FILE_PATH}/equip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/escort.pb.h ${PROTOCGEN_FILE_PATH}/escort.pb.cc ${PROTOCGEN_FILE_PATH}/escort_s.h ${PROTOCGEN_FILE_PATH}/escort_s.cpp ${PROTOCGEN_FILE_PATH}/escort.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/escort.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/escort.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds  --proto_fname=escort.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/escort.pb.h ${PROTOCGEN_FILE_PATH}/escort.pb.cc ${PROTOCGEN_FILE_PATH}/escort_s.h ${PROTOCGEN_FILE_PATH}/escort_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/fashion.pb.h ${PROTOCGEN_FILE_PATH}/fashion.pb.cc ${PROTOCGEN_FILE_PATH}/fashion_s.h ${PROTOCGEN_FILE_PATH}/fashion_s.cpp ${PROTOCGEN_FILE_PATH}/fashion.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/fashion.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/fashion.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/fashion.proto.ds  --proto_fname=fashion.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fashion.pb.h ${PROTOCGEN_FILE_PATH}/fashion.pb.cc ${PROTOCGEN_FILE_PATH}/fashion_s.h ${PROTOCGEN_FILE_PATH}/fashion_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/festival.pb.h ${PROTOCGEN_FILE_PATH}/festival.pb.cc ${PROTOCGEN_FILE_PATH}/festival_s.h ${PROTOCGEN_FILE_PATH}/festival_s.cpp ${PROTOCGEN_FILE_PATH}/festival.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/festival.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/festival.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/festival.proto.ds  --proto_fname=festival.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/festival.pb.h ${PROTOCGEN_FILE_PATH}/festival.pb.cc ${PROTOCGEN_FILE_PATH}/festival_s.h ${PROTOCGEN_FILE_PATH}/festival_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/field.pb.h ${PROTOCGEN_FILE_PATH}/field.pb.cc ${PROTOCGEN_FILE_PATH}/field_s.h ${PROTOCGEN_FILE_PATH}/field_s.cpp ${PROTOCGEN_FILE_PATH}/field.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/field.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/field.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds  --proto_fname=field.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/field.pb.h ${PROTOCGEN_FILE_PATH}/field.pb.cc ${PROTOCGEN_FILE_PATH}/field_s.h ${PROTOCGEN_FILE_PATH}/field_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/flash.pb.h ${PROTOCGEN_FILE_PATH}/flash.pb.cc ${PROTOCGEN_FILE_PATH}/flash_s.h ${PROTOCGEN_FILE_PATH}/flash_s.cpp ${PROTOCGEN_FILE_PATH}/flash.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/flash.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/flash.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds  --proto_fname=flash.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/flash.pb.h ${PROTOCGEN_FILE_PATH}/flash.pb.cc ${PROTOCGEN_FILE_PATH}/flash_s.h ${PROTOCGEN_FILE_PATH}/flash_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/functionunlock.pb.h ${PROTOCGEN_FILE_PATH}/functionunlock.pb.cc ${PROTOCGEN_FILE_PATH}/functionunlock_s.h ${PROTOCGEN_FILE_PATH}/functionunlock_s.cpp ${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/functionunlock.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds  --proto_fname=functionunlock.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/functionunlock.pb.h ${PROTOCGEN_FILE_PATH}/functionunlock.pb.cc ${PROTOCGEN_FILE_PATH}/functionunlock_s.h ${PROTOCGEN_FILE_PATH}/functionunlock_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/getTreasure.pb.h ${PROTOCGEN_FILE_PATH}/getTreasure.pb.cc ${PROTOCGEN_FILE_PATH}/getTreasure_s.h ${PROTOCGEN_FILE_PATH}/getTreasure_s.cpp ${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/getTreasure.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds  --proto_fname=getTreasure.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasure.pb.h ${PROTOCGEN_FILE_PATH}/getTreasure.pb.cc ${PROTOCGEN_FILE_PATH}/getTreasure_s.h ${PROTOCGEN_FILE_PATH}/getTreasure_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/GMCommand.pb.h ${PROTOCGEN_FILE_PATH}/GMCommand.pb.cc ${PROTOCGEN_FILE_PATH}/GMCommand_s.h ${PROTOCGEN_FILE_PATH}/GMCommand_s.cpp ${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/GMCommand.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds  --proto_fname=GMCommand.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMCommand.pb.h ${PROTOCGEN_FILE_PATH}/GMCommand.pb.cc ${PROTOCGEN_FILE_PATH}/GMCommand_s.h ${PROTOCGEN_FILE_PATH}/GMCommand_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/godHood.pb.h ${PROTOCGEN_FILE_PATH}/godHood.pb.cc ${PROTOCGEN_FILE_PATH}/godHood_s.h ${PROTOCGEN_FILE_PATH}/godHood_s.cpp ${PROTOCGEN_FILE_PATH}/godHood.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/godHood.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/godHood.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/godHood.proto.ds  --proto_fname=godHood.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godHood.pb.h ${PROTOCGEN_FILE_PATH}/godHood.pb.cc ${PROTOCGEN_FILE_PATH}/godHood_s.h ${PROTOCGEN_FILE_PATH}/godHood_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/guide.pb.h ${PROTOCGEN_FILE_PATH}/guide.pb.cc ${PROTOCGEN_FILE_PATH}/guide_s.h ${PROTOCGEN_FILE_PATH}/guide_s.cpp ${PROTOCGEN_FILE_PATH}/guide.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/guide.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/guide.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/guide.proto.ds  --proto_fname=guide.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guide.pb.h ${PROTOCGEN_FILE_PATH}/guide.pb.cc ${PROTOCGEN_FILE_PATH}/guide_s.h ${PROTOCGEN_FILE_PATH}/guide_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/guild.pb.h ${PROTOCGEN_FILE_PATH}/guild.pb.cc ${PROTOCGEN_FILE_PATH}/guild_s.h ${PROTOCGEN_FILE_PATH}/guild_s.cpp ${PROTOCGEN_FILE_PATH}/guild.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/guild.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/guild.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds  --proto_fname=guild.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guild.pb.h ${PROTOCGEN_FILE_PATH}/guild.pb.cc ${PROTOCGEN_FILE_PATH}/guild_s.h ${PROTOCGEN_FILE_PATH}/guild_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/handbook.pb.h ${PROTOCGEN_FILE_PATH}/handbook.pb.cc ${PROTOCGEN_FILE_PATH}/handbook_s.h ${PROTOCGEN_FILE_PATH}/handbook_s.cpp ${PROTOCGEN_FILE_PATH}/handbook.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/handbook.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/handbook.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/handbook.proto.ds  --proto_fname=handbook.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/handbook.pb.h ${PROTOCGEN_FILE_PATH}/handbook.pb.cc ${PROTOCGEN_FILE_PATH}/handbook_s.h ${PROTOCGEN_FILE_PATH}/handbook_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/huoyuedu.pb.h ${PROTOCGEN_FILE_PATH}/huoyuedu.pb.cc ${PROTOCGEN_FILE_PATH}/huoyuedu_s.h ${PROTOCGEN_FILE_PATH}/huoyuedu_s.cpp ${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/huoyuedu.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/huoyuedu.proto.ds  --proto_fname=huoyuedu.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/huoyuedu.pb.h ${PROTOCGEN_FILE_PATH}/huoyuedu.pb.cc ${PROTOCGEN_FILE_PATH}/huoyuedu_s.h ${PROTOCGEN_FILE_PATH}/huoyuedu_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/intimacy.pb.h ${PROTOCGEN_FILE_PATH}/intimacy.pb.cc ${PROTOCGEN_FILE_PATH}/intimacy_s.h ${PROTOCGEN_FILE_PATH}/intimacy_s.cpp ${PROTOCGEN_FILE_PATH}/intimacy.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/intimacy.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds  --proto_fname=intimacy.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/intimacy.pb.h ${PROTOCGEN_FILE_PATH}/intimacy.pb.cc ${PROTOCGEN_FILE_PATH}/intimacy_s.h ${PROTOCGEN_FILE_PATH}/intimacy_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/item.pb.h ${PROTOCGEN_FILE_PATH}/item.pb.cc ${PROTOCGEN_FILE_PATH}/item_s.h ${PROTOCGEN_FILE_PATH}/item_s.cpp ${PROTOCGEN_FILE_PATH}/item.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/item.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/item.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/item.proto.ds  --proto_fname=item.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/item.pb.h ${PROTOCGEN_FILE_PATH}/item.pb.cc ${PROTOCGEN_FILE_PATH}/item_s.h ${PROTOCGEN_FILE_PATH}/item_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/link.pb.h ${PROTOCGEN_FILE_PATH}/link.pb.cc ${PROTOCGEN_FILE_PATH}/link_s.h ${PROTOCGEN_FILE_PATH}/link_s.cpp ${PROTOCGEN_FILE_PATH}/link.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/link.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/link.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/link.proto.ds  --proto_fname=link.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/link.pb.h ${PROTOCGEN_FILE_PATH}/link.pb.cc ${PROTOCGEN_FILE_PATH}/link_s.h ${PROTOCGEN_FILE_PATH}/link_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/login.pb.h ${PROTOCGEN_FILE_PATH}/login.pb.cc ${PROTOCGEN_FILE_PATH}/login_s.h ${PROTOCGEN_FILE_PATH}/login_s.cpp ${PROTOCGEN_FILE_PATH}/login.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/login.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/login.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/login.proto.ds  --proto_fname=login.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/login.pb.h ${PROTOCGEN_FILE_PATH}/login.pb.cc ${PROTOCGEN_FILE_PATH}/login_s.h ${PROTOCGEN_FILE_PATH}/login_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/mail.pb.h ${PROTOCGEN_FILE_PATH}/mail.pb.cc ${PROTOCGEN_FILE_PATH}/mail_s.h ${PROTOCGEN_FILE_PATH}/mail_s.cpp ${PROTOCGEN_FILE_PATH}/mail.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/mail.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mail.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/mail.proto.ds  --proto_fname=mail.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mail.pb.h ${PROTOCGEN_FILE_PATH}/mail.pb.cc ${PROTOCGEN_FILE_PATH}/mail_s.h ${PROTOCGEN_FILE_PATH}/mail_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/mall.pb.h ${PROTOCGEN_FILE_PATH}/mall.pb.cc ${PROTOCGEN_FILE_PATH}/mall_s.h ${PROTOCGEN_FILE_PATH}/mall_s.cpp ${PROTOCGEN_FILE_PATH}/mall.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/mall.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mall.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds  --proto_fname=mall.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mall.pb.h ${PROTOCGEN_FILE_PATH}/mall.pb.cc ${PROTOCGEN_FILE_PATH}/mall_s.h ${PROTOCGEN_FILE_PATH}/mall_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/map.pb.h ${PROTOCGEN_FILE_PATH}/map.pb.cc ${PROTOCGEN_FILE_PATH}/map_s.h ${PROTOCGEN_FILE_PATH}/map_s.cpp ${PROTOCGEN_FILE_PATH}/map.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/map.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/map.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds  --proto_fname=map.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/map.pb.h ${PROTOCGEN_FILE_PATH}/map.pb.cc ${PROTOCGEN_FILE_PATH}/map_s.h ${PROTOCGEN_FILE_PATH}/map_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/marry.pb.h ${PROTOCGEN_FILE_PATH}/marry.pb.cc ${PROTOCGEN_FILE_PATH}/marry_s.h ${PROTOCGEN_FILE_PATH}/marry_s.cpp ${PROTOCGEN_FILE_PATH}/marry.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/marry.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/marry.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds  --proto_fname=marry.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marry.pb.h ${PROTOCGEN_FILE_PATH}/marry.pb.cc ${PROTOCGEN_FILE_PATH}/marry_s.h ${PROTOCGEN_FILE_PATH}/marry_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/monster.pb.h ${PROTOCGEN_FILE_PATH}/monster.pb.cc ${PROTOCGEN_FILE_PATH}/monster_s.h ${PROTOCGEN_FILE_PATH}/monster_s.cpp ${PROTOCGEN_FILE_PATH}/monster.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/monster.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/monster.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds  --proto_fname=monster.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monster.pb.h ${PROTOCGEN_FILE_PATH}/monster.pb.cc ${PROTOCGEN_FILE_PATH}/monster_s.h ${PROTOCGEN_FILE_PATH}/monster_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/mount.pb.h ${PROTOCGEN_FILE_PATH}/mount.pb.cc ${PROTOCGEN_FILE_PATH}/mount_s.h ${PROTOCGEN_FILE_PATH}/mount_s.cpp ${PROTOCGEN_FILE_PATH}/mount.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/mount.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mount.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds  --proto_fname=mount.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mount.pb.h ${PROTOCGEN_FILE_PATH}/mount.pb.cc ${PROTOCGEN_FILE_PATH}/mount_s.h ${PROTOCGEN_FILE_PATH}/mount_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/msg.pb.h ${PROTOCGEN_FILE_PATH}/msg.pb.cc ${PROTOCGEN_FILE_PATH}/msg_s.h ${PROTOCGEN_FILE_PATH}/msg_s.cpp ${PROTOCGEN_FILE_PATH}/msg.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/msg.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/msg.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/msg.proto.ds  --proto_fname=msg.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/msg.pb.h ${PROTOCGEN_FILE_PATH}/msg.pb.cc ${PROTOCGEN_FILE_PATH}/msg_s.h ${PROTOCGEN_FILE_PATH}/msg_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/must.pb.h ${PROTOCGEN_FILE_PATH}/must.pb.cc ${PROTOCGEN_FILE_PATH}/must_s.h ${PROTOCGEN_FILE_PATH}/must_s.cpp ${PROTOCGEN_FILE_PATH}/must.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/must.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/must.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/must.proto.ds  --proto_fname=must.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/must.pb.h ${PROTOCGEN_FILE_PATH}/must.pb.cc ${PROTOCGEN_FILE_PATH}/must_s.h ${PROTOCGEN_FILE_PATH}/must_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/occupation.pb.h ${PROTOCGEN_FILE_PATH}/occupation.pb.cc ${PROTOCGEN_FILE_PATH}/occupation_s.h ${PROTOCGEN_FILE_PATH}/occupation_s.cpp ${PROTOCGEN_FILE_PATH}/occupation.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/occupation.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/occupation.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds  --proto_fname=occupation.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/occupation.pb.h ${PROTOCGEN_FILE_PATH}/occupation.pb.cc ${PROTOCGEN_FILE_PATH}/occupation_s.h ${PROTOCGEN_FILE_PATH}/occupation_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/offline.pb.h ${PROTOCGEN_FILE_PATH}/offline.pb.cc ${PROTOCGEN_FILE_PATH}/offline_s.h ${PROTOCGEN_FILE_PATH}/offline_s.cpp ${PROTOCGEN_FILE_PATH}/offline.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/offline.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/offline.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds  --proto_fname=offline.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/offline.pb.h ${PROTOCGEN_FILE_PATH}/offline.pb.cc ${PROTOCGEN_FILE_PATH}/offline_s.h ${PROTOCGEN_FILE_PATH}/offline_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/operate.pb.h ${PROTOCGEN_FILE_PATH}/operate.pb.cc ${PROTOCGEN_FILE_PATH}/operate_s.h ${PROTOCGEN_FILE_PATH}/operate_s.cpp ${PROTOCGEN_FILE_PATH}/operate.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/operate.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/operate.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/operate.proto.ds  --proto_fname=operate.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operate.pb.h ${PROTOCGEN_FILE_PATH}/operate.pb.cc ${PROTOCGEN_FILE_PATH}/operate_s.h ${PROTOCGEN_FILE_PATH}/operate_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/partner.pb.h ${PROTOCGEN_FILE_PATH}/partner.pb.cc ${PROTOCGEN_FILE_PATH}/partner_s.h ${PROTOCGEN_FILE_PATH}/partner_s.cpp ${PROTOCGEN_FILE_PATH}/partner.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/partner.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/partner.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/partner.proto.ds  --proto_fname=partner.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partner.pb.h ${PROTOCGEN_FILE_PATH}/partner.pb.cc ${PROTOCGEN_FILE_PATH}/partner_s.h ${PROTOCGEN_FILE_PATH}/partner_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/randomname.pb.h ${PROTOCGEN_FILE_PATH}/randomname.pb.cc ${PROTOCGEN_FILE_PATH}/randomname_s.h ${PROTOCGEN_FILE_PATH}/randomname_s.cpp ${PROTOCGEN_FILE_PATH}/randomname.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/randomname.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/randomname.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds  --proto_fname=randomname.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomname.pb.h ${PROTOCGEN_FILE_PATH}/randomname.pb.cc ${PROTOCGEN_FILE_PATH}/randomname_s.h ${PROTOCGEN_FILE_PATH}/randomname_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/ranking.pb.h ${PROTOCGEN_FILE_PATH}/ranking.pb.cc ${PROTOCGEN_FILE_PATH}/ranking_s.h ${PROTOCGEN_FILE_PATH}/ranking_s.cpp ${PROTOCGEN_FILE_PATH}/ranking.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/ranking.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ranking.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds  --proto_fname=ranking.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ranking.pb.h ${PROTOCGEN_FILE_PATH}/ranking.pb.cc ${PROTOCGEN_FILE_PATH}/ranking_s.h ${PROTOCGEN_FILE_PATH}/ranking_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/recharge.pb.h ${PROTOCGEN_FILE_PATH}/recharge.pb.cc ${PROTOCGEN_FILE_PATH}/recharge_s.h ${PROTOCGEN_FILE_PATH}/recharge_s.cpp ${PROTOCGEN_FILE_PATH}/recharge.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/recharge.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/recharge.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/recharge.proto.ds  --proto_fname=recharge.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/recharge.pb.h ${PROTOCGEN_FILE_PATH}/recharge.pb.cc ${PROTOCGEN_FILE_PATH}/recharge_s.h ${PROTOCGEN_FILE_PATH}/recharge_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/role.pb.h ${PROTOCGEN_FILE_PATH}/role.pb.cc ${PROTOCGEN_FILE_PATH}/role_s.h ${PROTOCGEN_FILE_PATH}/role_s.cpp ${PROTOCGEN_FILE_PATH}/role.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/role.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/role.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds  --proto_fname=role.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/role.pb.h ${PROTOCGEN_FILE_PATH}/role.pb.cc ${PROTOCGEN_FILE_PATH}/role_s.h ${PROTOCGEN_FILE_PATH}/role_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/sensitiveword.pb.h ${PROTOCGEN_FILE_PATH}/sensitiveword.pb.cc ${PROTOCGEN_FILE_PATH}/sensitiveword_s.h ${PROTOCGEN_FILE_PATH}/sensitiveword_s.cpp ${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/sensitiveword.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds  --proto_fname=sensitiveword.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/sensitiveword.pb.h ${PROTOCGEN_FILE_PATH}/sensitiveword.pb.cc ${PROTOCGEN_FILE_PATH}/sensitiveword_s.h ${PROTOCGEN_FILE_PATH}/sensitiveword_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/serverlist.pb.h ${PROTOCGEN_FILE_PATH}/serverlist.pb.cc ${PROTOCGEN_FILE_PATH}/serverlist_s.h ${PROTOCGEN_FILE_PATH}/serverlist_s.cpp ${PROTOCGEN_FILE_PATH}/serverlist.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/serverlist.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/serverlist.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/serverlist.proto.ds  --proto_fname=serverlist.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serverlist.pb.h ${PROTOCGEN_FILE_PATH}/serverlist.pb.cc ${PROTOCGEN_FILE_PATH}/serverlist_s.h ${PROTOCGEN_FILE_PATH}/serverlist_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/skill.pb.h ${PROTOCGEN_FILE_PATH}/skill.pb.cc ${PROTOCGEN_FILE_PATH}/skill_s.h ${PROTOCGEN_FILE_PATH}/skill_s.cpp ${PROTOCGEN_FILE_PATH}/skill.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/skill.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/skill.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds  --proto_fname=skill.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skill.pb.h ${PROTOCGEN_FILE_PATH}/skill.pb.cc ${PROTOCGEN_FILE_PATH}/skill_s.h ${PROTOCGEN_FILE_PATH}/skill_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/star.pb.h ${PROTOCGEN_FILE_PATH}/star.pb.cc ${PROTOCGEN_FILE_PATH}/star_s.h ${PROTOCGEN_FILE_PATH}/star_s.cpp ${PROTOCGEN_FILE_PATH}/star.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/star.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/star.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/star.proto.ds  --proto_fname=star.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/star.pb.h ${PROTOCGEN_FILE_PATH}/star.pb.cc ${PROTOCGEN_FILE_PATH}/star_s.h ${PROTOCGEN_FILE_PATH}/star_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
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
${PROTOCGEN_FILE_PATH}/team.pb.h ${PROTOCGEN_FILE_PATH}/team.pb.cc ${PROTOCGEN_FILE_PATH}/team_s.h ${PROTOCGEN_FILE_PATH}/team_s.cpp ${PROTOCGEN_FILE_PATH}/team.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/team.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/team.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/team.proto.ds  --proto_fname=team.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/team.pb.h ${PROTOCGEN_FILE_PATH}/team.pb.cc ${PROTOCGEN_FILE_PATH}/team_s.h ${PROTOCGEN_FILE_PATH}/team_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/teleport.pb.h ${PROTOCGEN_FILE_PATH}/teleport.pb.cc ${PROTOCGEN_FILE_PATH}/teleport_s.h ${PROTOCGEN_FILE_PATH}/teleport_s.cpp ${PROTOCGEN_FILE_PATH}/teleport.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/teleport.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/teleport.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/teleport.proto.ds  --proto_fname=teleport.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/teleport.pb.h ${PROTOCGEN_FILE_PATH}/teleport.pb.cc ${PROTOCGEN_FILE_PATH}/teleport_s.h ${PROTOCGEN_FILE_PATH}/teleport_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/title.pb.h ${PROTOCGEN_FILE_PATH}/title.pb.cc ${PROTOCGEN_FILE_PATH}/title_s.h ${PROTOCGEN_FILE_PATH}/title_s.cpp ${PROTOCGEN_FILE_PATH}/title.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/title.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/title.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds  --proto_fname=title.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/title.pb.h ${PROTOCGEN_FILE_PATH}/title.pb.cc ${PROTOCGEN_FILE_PATH}/title_s.h ${PROTOCGEN_FILE_PATH}/title_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/treasure.pb.h ${PROTOCGEN_FILE_PATH}/treasure.pb.cc ${PROTOCGEN_FILE_PATH}/treasure_s.h ${PROTOCGEN_FILE_PATH}/treasure_s.cpp ${PROTOCGEN_FILE_PATH}/treasure.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/treasure.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/treasure.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds  --proto_fname=treasure.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasure.pb.h ${PROTOCGEN_FILE_PATH}/treasure.pb.cc ${PROTOCGEN_FILE_PATH}/treasure_s.h ${PROTOCGEN_FILE_PATH}/treasure_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/ui.pb.h ${PROTOCGEN_FILE_PATH}/ui.pb.cc ${PROTOCGEN_FILE_PATH}/ui_s.h ${PROTOCGEN_FILE_PATH}/ui_s.cpp ${PROTOCGEN_FILE_PATH}/ui.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/ui.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ui.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/ui.proto.ds  --proto_fname=ui.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ui.pb.h ${PROTOCGEN_FILE_PATH}/ui.pb.cc ${PROTOCGEN_FILE_PATH}/ui_s.h ${PROTOCGEN_FILE_PATH}/ui_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/vip.pb.h ${PROTOCGEN_FILE_PATH}/vip.pb.cc ${PROTOCGEN_FILE_PATH}/vip_s.h ${PROTOCGEN_FILE_PATH}/vip_s.cpp ${PROTOCGEN_FILE_PATH}/vip.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/vip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/vip.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/vip.proto.ds  --proto_fname=vip.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/vip.pb.h ${PROTOCGEN_FILE_PATH}/vip.pb.cc ${PROTOCGEN_FILE_PATH}/vip_s.h ${PROTOCGEN_FILE_PATH}/vip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/warland.pb.h ${PROTOCGEN_FILE_PATH}/warland.pb.cc ${PROTOCGEN_FILE_PATH}/warland_s.h ${PROTOCGEN_FILE_PATH}/warland_s.cpp ${PROTOCGEN_FILE_PATH}/warland.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/warland.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/warland.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds  --proto_fname=warland.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/warland.pb.h ${PROTOCGEN_FILE_PATH}/warland.pb.cc ${PROTOCGEN_FILE_PATH}/warland_s.h ${PROTOCGEN_FILE_PATH}/warland_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/wing.pb.h ${PROTOCGEN_FILE_PATH}/wing.pb.cc ${PROTOCGEN_FILE_PATH}/wing_s.h ${PROTOCGEN_FILE_PATH}/wing_s.cpp ${PROTOCGEN_FILE_PATH}/wing.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/wing.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/wing.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/wing.proto.ds  --proto_fname=wing.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/wing.pb.h ${PROTOCGEN_FILE_PATH}/wing.pb.cc ${PROTOCGEN_FILE_PATH}/wing_s.h ${PROTOCGEN_FILE_PATH}/wing_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/serveropenactive.pb.h ${PROTOCGEN_FILE_PATH}/serveropenactive.pb.cc ${PROTOCGEN_FILE_PATH}/serveropenactive_s.h ${PROTOCGEN_FILE_PATH}/serveropenactive_s.cpp ${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/serveropenactive.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/serveropenactive.proto.ds  --proto_fname=serveropenactive.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactive.pb.h ${PROTOCGEN_FILE_PATH}/serveropenactive.pb.cc ${PROTOCGEN_FILE_PATH}/serveropenactive_s.h ${PROTOCGEN_FILE_PATH}/serveropenactive_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/witch.pb.h ${PROTOCGEN_FILE_PATH}/witch.pb.cc ${PROTOCGEN_FILE_PATH}/witch_s.h ${PROTOCGEN_FILE_PATH}/witch_s.cpp ${PROTOCGEN_FILE_PATH}/witch.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/witch.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/witch.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/witch.proto.ds  --proto_fname=witch.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/witch.pb.h ${PROTOCGEN_FILE_PATH}/witch.pb.cc ${PROTOCGEN_FILE_PATH}/witch_s.h ${PROTOCGEN_FILE_PATH}/witch_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/solo.pb.h ${PROTOCGEN_FILE_PATH}/solo.pb.cc ${PROTOCGEN_FILE_PATH}/solo_s.h ${PROTOCGEN_FILE_PATH}/solo_s.cpp ${PROTOCGEN_FILE_PATH}/solo.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/solo.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/solo.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/solo.proto.ds  --proto_fname=solo.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/solo.pb.h ${PROTOCGEN_FILE_PATH}/solo.pb.cc ${PROTOCGEN_FILE_PATH}/solo_s.h ${PROTOCGEN_FILE_PATH}/solo_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/show.pb.h ${PROTOCGEN_FILE_PATH}/show.pb.cc ${PROTOCGEN_FILE_PATH}/show_s.h ${PROTOCGEN_FILE_PATH}/show_s.cpp ${PROTOCGEN_FILE_PATH}/show.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/show.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/show.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/show.proto.ds  --proto_fname=show.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/show.pb.h ${PROTOCGEN_FILE_PATH}/show.pb.cc ${PROTOCGEN_FILE_PATH}/show_s.h ${PROTOCGEN_FILE_PATH}/show_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/notice.pb.h ${PROTOCGEN_FILE_PATH}/notice.pb.cc ${PROTOCGEN_FILE_PATH}/notice_s.h ${PROTOCGEN_FILE_PATH}/notice_s.cpp ${PROTOCGEN_FILE_PATH}/notice.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/notice.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/notice.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/notice.proto.ds  --proto_fname=notice.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/notice.pb.h ${PROTOCGEN_FILE_PATH}/notice.pb.cc ${PROTOCGEN_FILE_PATH}/notice_s.h ${PROTOCGEN_FILE_PATH}/notice_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/conditionshop.pb.h ${PROTOCGEN_FILE_PATH}/conditionshop.pb.cc ${PROTOCGEN_FILE_PATH}/conditionshop_s.h ${PROTOCGEN_FILE_PATH}/conditionshop_s.cpp ${PROTOCGEN_FILE_PATH}/conditionshop.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/conditionshop.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/conditionshop.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/conditionshop.proto.ds  --proto_fname=conditionshop.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/conditionshop.pb.h ${PROTOCGEN_FILE_PATH}/conditionshop.pb.cc ${PROTOCGEN_FILE_PATH}/conditionshop_s.h ${PROTOCGEN_FILE_PATH}/conditionshop_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/closetest.pb.h ${PROTOCGEN_FILE_PATH}/closetest.pb.cc ${PROTOCGEN_FILE_PATH}/closetest_s.h ${PROTOCGEN_FILE_PATH}/closetest_s.cpp ${PROTOCGEN_FILE_PATH}/closetest.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/closetest.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/closetest.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/closetest.proto.ds  --proto_fname=closetest.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/closetest.pb.h ${PROTOCGEN_FILE_PATH}/closetest.pb.cc ${PROTOCGEN_FILE_PATH}/closetest_s.h ${PROTOCGEN_FILE_PATH}/closetest_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/worldmapboss.pb.h ${PROTOCGEN_FILE_PATH}/worldmapboss.pb.cc ${PROTOCGEN_FILE_PATH}/worldmapboss_s.h ${PROTOCGEN_FILE_PATH}/worldmapboss_s.cpp ${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/worldmapboss.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds  --proto_fname=worldmapboss.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/worldmapboss.pb.h ${PROTOCGEN_FILE_PATH}/worldmapboss.pb.cc ${PROTOCGEN_FILE_PATH}/worldmapboss_s.h ${PROTOCGEN_FILE_PATH}/worldmapboss_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/dragonWorldWar.pb.h ${PROTOCGEN_FILE_PATH}/dragonWorldWar.pb.cc ${PROTOCGEN_FILE_PATH}/dragonWorldWar_s.h ${PROTOCGEN_FILE_PATH}/dragonWorldWar_s.cpp ${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/dragonWorldWar.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds  --proto_fname=dragonWorldWar.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dragonWorldWar.pb.h ${PROTOCGEN_FILE_PATH}/dragonWorldWar.pb.cc ${PROTOCGEN_FILE_PATH}/dragonWorldWar_s.h ${PROTOCGEN_FILE_PATH}/dragonWorldWar_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/manor.pb.h ${PROTOCGEN_FILE_PATH}/manor.pb.cc ${PROTOCGEN_FILE_PATH}/manor_s.h ${PROTOCGEN_FILE_PATH}/manor_s.cpp ${PROTOCGEN_FILE_PATH}/manor.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/manor.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/manor.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/manor.proto.ds  --proto_fname=manor.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manor.pb.h ${PROTOCGEN_FILE_PATH}/manor.pb.cc ${PROTOCGEN_FILE_PATH}/manor_s.h ${PROTOCGEN_FILE_PATH}/manor_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/condition.pb.h ${PROTOCGEN_FILE_PATH}/condition.pb.cc ${PROTOCGEN_FILE_PATH}/condition_s.h ${PROTOCGEN_FILE_PATH}/condition_s.cpp ${PROTOCGEN_FILE_PATH}/condition.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/condition.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/condition.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/condition.proto.ds  --proto_fname=condition.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/condition.pb.h ${PROTOCGEN_FILE_PATH}/condition.pb.cc ${PROTOCGEN_FILE_PATH}/condition_s.h ${PROTOCGEN_FILE_PATH}/condition_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/privilege.pb.h ${PROTOCGEN_FILE_PATH}/privilege.pb.cc ${PROTOCGEN_FILE_PATH}/privilege_s.h ${PROTOCGEN_FILE_PATH}/privilege_s.cpp ${PROTOCGEN_FILE_PATH}/privilege.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/privilege.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/privilege.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/privilege.proto.ds  --proto_fname=privilege.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/privilege.pb.h ${PROTOCGEN_FILE_PATH}/privilege.pb.cc ${PROTOCGEN_FILE_PATH}/privilege_s.h ${PROTOCGEN_FILE_PATH}/privilege_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/godpower.pb.h ${PROTOCGEN_FILE_PATH}/godpower.pb.cc ${PROTOCGEN_FILE_PATH}/godpower_s.h ${PROTOCGEN_FILE_PATH}/godpower_s.cpp ${PROTOCGEN_FILE_PATH}/godpower.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/godpower.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/godpower.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/godpower.proto.ds  --proto_fname=godpower.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godpower.pb.h ${PROTOCGEN_FILE_PATH}/godpower.pb.cc ${PROTOCGEN_FILE_PATH}/godpower_s.h ${PROTOCGEN_FILE_PATH}/godpower_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/headPortrait.pb.h ${PROTOCGEN_FILE_PATH}/headPortrait.pb.cc ${PROTOCGEN_FILE_PATH}/headPortrait_s.h ${PROTOCGEN_FILE_PATH}/headPortrait_s.cpp ${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/headPortrait.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds  --proto_fname=headPortrait.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortrait.pb.h ${PROTOCGEN_FILE_PATH}/headPortrait.pb.cc ${PROTOCGEN_FILE_PATH}/headPortrait_s.h ${PROTOCGEN_FILE_PATH}/headPortrait_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/gm5Help.pb.h ${PROTOCGEN_FILE_PATH}/gm5Help.pb.cc ${PROTOCGEN_FILE_PATH}/gm5Help_s.h ${PROTOCGEN_FILE_PATH}/gm5Help_s.cpp ${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/gm5Help.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds  --proto_fname=gm5Help.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/gm5Help.pb.h ${PROTOCGEN_FILE_PATH}/gm5Help.pb.cc ${PROTOCGEN_FILE_PATH}/gm5Help_s.h ${PROTOCGEN_FILE_PATH}/gm5Help_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/godGM.pb.h ${PROTOCGEN_FILE_PATH}/godGM.pb.cc ${PROTOCGEN_FILE_PATH}/godGM_s.h ${PROTOCGEN_FILE_PATH}/godGM_s.cpp ${PROTOCGEN_FILE_PATH}/godGM.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/godGM.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/godGM.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/godGM.proto.ds  --proto_fname=godGM.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godGM.pb.h ${PROTOCGEN_FILE_PATH}/godGM.pb.cc ${PROTOCGEN_FILE_PATH}/godGM_s.h ${PROTOCGEN_FILE_PATH}/godGM_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/serverHorn.pb.h ${PROTOCGEN_FILE_PATH}/serverHorn.pb.cc ${PROTOCGEN_FILE_PATH}/serverHorn_s.h ${PROTOCGEN_FILE_PATH}/serverHorn_s.cpp ${PROTOCGEN_FILE_PATH}/serverHorn.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/serverHorn.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/serverHorn.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/serverHorn.proto.ds  --proto_fname=serverHorn.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serverHorn.pb.h ${PROTOCGEN_FILE_PATH}/serverHorn.pb.cc ${PROTOCGEN_FILE_PATH}/serverHorn_s.h ${PROTOCGEN_FILE_PATH}/serverHorn_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/lightAndShadow.pb.h ${PROTOCGEN_FILE_PATH}/lightAndShadow.pb.cc ${PROTOCGEN_FILE_PATH}/lightAndShadow_s.h ${PROTOCGEN_FILE_PATH}/lightAndShadow_s.cpp ${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/lightAndShadow.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds  --proto_fname=lightAndShadow.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/lightAndShadow.pb.h ${PROTOCGEN_FILE_PATH}/lightAndShadow.pb.cc ${PROTOCGEN_FILE_PATH}/lightAndShadow_s.h ${PROTOCGEN_FILE_PATH}/lightAndShadow_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/rechargeReturn.pb.h ${PROTOCGEN_FILE_PATH}/rechargeReturn.pb.cc ${PROTOCGEN_FILE_PATH}/rechargeReturn_s.h ${PROTOCGEN_FILE_PATH}/rechargeReturn_s.cpp ${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/rechargeReturn.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/rechargeReturn.proto.ds  --proto_fname=rechargeReturn.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturn.pb.h ${PROTOCGEN_FILE_PATH}/rechargeReturn.pb.cc ${PROTOCGEN_FILE_PATH}/rechargeReturn_s.h ${PROTOCGEN_FILE_PATH}/rechargeReturn_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/snowballWar.pb.h ${PROTOCGEN_FILE_PATH}/snowballWar.pb.cc ${PROTOCGEN_FILE_PATH}/snowballWar_s.h ${PROTOCGEN_FILE_PATH}/snowballWar_s.cpp ${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/snowballWar.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/snowballWar.proto.ds  --proto_fname=snowballWar.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/snowballWar.pb.h ${PROTOCGEN_FILE_PATH}/snowballWar.pb.cc ${PROTOCGEN_FILE_PATH}/snowballWar_s.h ${PROTOCGEN_FILE_PATH}/snowballWar_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/chooseGift.pb.h ${PROTOCGEN_FILE_PATH}/chooseGift.pb.cc ${PROTOCGEN_FILE_PATH}/chooseGift_s.h ${PROTOCGEN_FILE_PATH}/chooseGift_s.cpp ${PROTOCGEN_FILE_PATH}/chooseGift.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/chooseGift.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/chooseGift.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/chooseGift.proto.ds  --proto_fname=chooseGift.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chooseGift.pb.h ${PROTOCGEN_FILE_PATH}/chooseGift.pb.cc ${PROTOCGEN_FILE_PATH}/chooseGift_s.h ${PROTOCGEN_FILE_PATH}/chooseGift_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/treasureBowl.pb.h ${PROTOCGEN_FILE_PATH}/treasureBowl.pb.cc ${PROTOCGEN_FILE_PATH}/treasureBowl_s.h ${PROTOCGEN_FILE_PATH}/treasureBowl_s.cpp ${PROTOCGEN_FILE_PATH}/treasureBowl.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/treasureBowl.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/treasureBowl.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/treasureBowl.proto.ds  --proto_fname=treasureBowl.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasureBowl.pb.h ${PROTOCGEN_FILE_PATH}/treasureBowl.pb.cc ${PROTOCGEN_FILE_PATH}/treasureBowl_s.h ${PROTOCGEN_FILE_PATH}/treasureBowl_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/welfarelink.pb.h ${PROTOCGEN_FILE_PATH}/welfarelink.pb.cc ${PROTOCGEN_FILE_PATH}/welfarelink_s.h ${PROTOCGEN_FILE_PATH}/welfarelink_s.cpp ${PROTOCGEN_FILE_PATH}/welfarelink.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/welfarelink.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/welfarelink.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/welfarelink.proto.ds  --proto_fname=welfarelink.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/welfarelink.pb.h ${PROTOCGEN_FILE_PATH}/welfarelink.pb.cc ${PROTOCGEN_FILE_PATH}/welfarelink_s.h ${PROTOCGEN_FILE_PATH}/welfarelink_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/GMtools.pb.h ${PROTOCGEN_FILE_PATH}/GMtools.pb.cc ${PROTOCGEN_FILE_PATH}/GMtools_s.h ${PROTOCGEN_FILE_PATH}/GMtools_s.cpp ${PROTOCGEN_FILE_PATH}/GMtools.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/GMtools.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/GMtools.proto.ds  --proto_fname=GMtools.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtools.pb.h ${PROTOCGEN_FILE_PATH}/GMtools.pb.cc ${PROTOCGEN_FILE_PATH}/GMtools_s.h ${PROTOCGEN_FILE_PATH}/GMtools_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/indultTask.pb.h ${PROTOCGEN_FILE_PATH}/indultTask.pb.cc ${PROTOCGEN_FILE_PATH}/indultTask_s.h ${PROTOCGEN_FILE_PATH}/indultTask_s.cpp ${PROTOCGEN_FILE_PATH}/indultTask.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/indultTask.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/indultTask.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/indultTask.proto.ds  --proto_fname=indultTask.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/indultTask.pb.h ${PROTOCGEN_FILE_PATH}/indultTask.pb.cc ${PROTOCGEN_FILE_PATH}/indultTask_s.h ${PROTOCGEN_FILE_PATH}/indultTask_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
${PROTOCGEN_FILE_PATH}/colPoints.pb.h ${PROTOCGEN_FILE_PATH}/colPoints.pb.cc ${PROTOCGEN_FILE_PATH}/colPoints_s.h ${PROTOCGEN_FILE_PATH}/colPoints_s.cpp ${PROTOCGEN_FILE_PATH}/colPoints.proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/colPoints.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/colPoints.proto.ds  --cpp_out=${PROTOCGEN_FILE_PATH}
	${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/colPoints.proto.ds  --proto_fname=colPoints.proto --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/colPoints.pb.h ${PROTOCGEN_FILE_PATH}/colPoints.pb.cc ${PROTOCGEN_FILE_PATH}/colPoints_s.h ${PROTOCGEN_FILE_PATH}/colPoints_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
