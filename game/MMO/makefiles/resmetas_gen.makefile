include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/msg_proto_finish ${PROTOCGEN_FILE_PATH}/ui_proto_finish ${PROTOCGEN_FILE_PATH}/role_proto_finish ${PROTOCGEN_FILE_PATH}/randomname_proto_finish ${PROTOCGEN_FILE_PATH}/sensitiveword_proto_finish ${PROTOCGEN_FILE_PATH}/map_proto_finish ${PROTOCGEN_FILE_PATH}/monster_proto_finish ${PROTOCGEN_FILE_PATH}/mount_proto_finish ${PROTOCGEN_FILE_PATH}/area_proto_finish ${PROTOCGEN_FILE_PATH}/skill_proto_finish ${PROTOCGEN_FILE_PATH}/item_proto_finish ${PROTOCGEN_FILE_PATH}/equip_proto_finish ${PROTOCGEN_FILE_PATH}/constant_proto_finish ${PROTOCGEN_FILE_PATH}/attribute_proto_finish ${PROTOCGEN_FILE_PATH}/fashion_proto_finish ${PROTOCGEN_FILE_PATH}/decorate_proto_finish ${PROTOCGEN_FILE_PATH}/footprint_proto_finish ${PROTOCGEN_FILE_PATH}/halo_proto_finish ${PROTOCGEN_FILE_PATH}/headPortrait_proto_finish ${PROTOCGEN_FILE_PATH}/meditation_proto_finish ${PROTOCGEN_FILE_PATH}/functionunlock_proto_finish ${PROTOCGEN_FILE_PATH}/GMCommand_proto_finish ${PROTOCGEN_FILE_PATH}/appearance_proto_finish ${PROTOCGEN_FILE_PATH}/link_proto_finish ${PROTOCGEN_FILE_PATH}/mail_proto_finish ${PROTOCGEN_FILE_PATH}/mall_proto_finish ${PROTOCGEN_FILE_PATH}/chat_proto_finish ${PROTOCGEN_FILE_PATH}/path_proto_finish ${PROTOCGEN_FILE_PATH}/intimacy_proto_finish ${PROTOCGEN_FILE_PATH}/ai_proto_finish ${PROTOCGEN_FILE_PATH}/boss_proto_finish ${PROTOCGEN_FILE_PATH}/point_proto_finish ${PROTOCGEN_FILE_PATH}/facade_proto_finish ${PROTOCGEN_FILE_PATH}/dup_proto_finish ${PROTOCGEN_FILE_PATH}/offline_proto_finish ${PROTOCGEN_FILE_PATH}/godRelics_proto_finish ${PROTOCGEN_FILE_PATH}/condition_proto_finish ${PROTOCGEN_FILE_PATH}/audio_proto_finish ${PROTOCGEN_FILE_PATH}/perActivity_proto_finish ${PROTOCGEN_FILE_PATH}/daily_proto_finish ${PROTOCGEN_FILE_PATH}/back_proto_finish ${PROTOCGEN_FILE_PATH}/set_proto_finish ${PROTOCGEN_FILE_PATH}/team_proto_finish ${PROTOCGEN_FILE_PATH}/box_proto_finish ${PROTOCGEN_FILE_PATH}/task_proto_finish ${PROTOCGEN_FILE_PATH}/taskdynamic_proto_finish ${PROTOCGEN_FILE_PATH}/taskreward_proto_finish ${PROTOCGEN_FILE_PATH}/tasktracker_proto_finish ${PROTOCGEN_FILE_PATH}/flash_proto_finish ${PROTOCGEN_FILE_PATH}/button_proto_finish ${PROTOCGEN_FILE_PATH}/vip_proto_finish ${PROTOCGEN_FILE_PATH}/arena_proto_finish ${PROTOCGEN_FILE_PATH}/pet_proto_finish ${PROTOCGEN_FILE_PATH}/avatar_proto_finish ${PROTOCGEN_FILE_PATH}/assist_proto_finish ${PROTOCGEN_FILE_PATH}/moneyReward_proto_finish ${PROTOCGEN_FILE_PATH}/escort_proto_finish ${PROTOCGEN_FILE_PATH}/guild_proto_finish ${PROTOCGEN_FILE_PATH}/collect_proto_finish ${PROTOCGEN_FILE_PATH}/title_proto_finish ${PROTOCGEN_FILE_PATH}/godevil_proto_finish ${PROTOCGEN_FILE_PATH}/occupation_proto_finish ${PROTOCGEN_FILE_PATH}/Godvalley_proto_finish ${PROTOCGEN_FILE_PATH}/recharge_proto_finish ${PROTOCGEN_FILE_PATH}/shenequip_proto_finish ${PROTOCGEN_FILE_PATH}/achievement_proto_finish ${PROTOCGEN_FILE_PATH}/ancientgod_proto_finish ${PROTOCGEN_FILE_PATH}/xiuzhen_proto_finish ${PROTOCGEN_FILE_PATH}/encyclopedia_proto_finish ${PROTOCGEN_FILE_PATH}/talent_proto_finish ${PROTOCGEN_FILE_PATH}/marry_proto_finish ${PROTOCGEN_FILE_PATH}/ranking_proto_finish ${PROTOCGEN_FILE_PATH}/waremblem_proto_finish ${PROTOCGEN_FILE_PATH}/pk1v1_proto_finish ${PROTOCGEN_FILE_PATH}/conflate_proto_finish ${PROTOCGEN_FILE_PATH}/dragonSoul_proto_finish ${PROTOCGEN_FILE_PATH}/personalshop_proto_finish ${PROTOCGEN_FILE_PATH}/washparty_proto_finish ${PROTOCGEN_FILE_PATH}/welfare_proto_finish ${PROTOCGEN_FILE_PATH}/qyPeak_proto_finish ${PROTOCGEN_FILE_PATH}/pk3v3_proto_finish ${PROTOCGEN_FILE_PATH}/guide_proto_finish ${PROTOCGEN_FILE_PATH}/cloudPeak_proto_finish ${PROTOCGEN_FILE_PATH}/xiuzhenroad_proto_finish ${PROTOCGEN_FILE_PATH}/gift_proto_finish ${PROTOCGEN_FILE_PATH}/battlePass_proto_finish ${PROTOCGEN_FILE_PATH}/findTreasure_proto_finish ${PROTOCGEN_FILE_PATH}/festival_proto_finish ${PROTOCGEN_FILE_PATH}/market_proto_finish ${PROTOCGEN_FILE_PATH}/dragon_proto_finish ${PROTOCGEN_FILE_PATH}/yanglong_proto_finish ${PROTOCGEN_FILE_PATH}/timeline_proto_finish ${PROTOCGEN_FILE_PATH}/jinglian_proto_finish ${PROTOCGEN_FILE_PATH}/equipImprove_proto_finish ${PROTOCGEN_FILE_PATH}/teleport_proto_finish ${PROTOCGEN_FILE_PATH}/xingchen_proto_finish ${PROTOCGEN_FILE_PATH}/mofa_proto_finish ${PROTOCGEN_FILE_PATH}/shenti_proto_finish ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_proto_finish 

${PROTOCGEN_FILE_PATH}/msg_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Msg.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/msg_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/msg.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/msg.proto.ds --src=E_Msg.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Msg.pb.h ${PROTOCGEN_FILE_PATH}/E_Msg.pb.cc ${PROTOCGEN_FILE_PATH}/E_Msg_s.h ${PROTOCGEN_FILE_PATH}/E_Msg_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/msg_proto_finish


${PROTOCGEN_FILE_PATH}/ui_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Ui.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ui_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ui.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/ui.proto.ds --src=E_Ui.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ui.pb.h ${PROTOCGEN_FILE_PATH}/E_Ui.pb.cc ${PROTOCGEN_FILE_PATH}/E_Ui_s.h ${PROTOCGEN_FILE_PATH}/E_Ui_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ui_proto_finish


${PROTOCGEN_FILE_PATH}/role_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Role.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/role_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/role.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --src=E_Role.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Role.pb.h ${PROTOCGEN_FILE_PATH}/E_Role.pb.cc ${PROTOCGEN_FILE_PATH}/E_Role_s.h ${PROTOCGEN_FILE_PATH}/E_Role_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/role_proto_finish


${PROTOCGEN_FILE_PATH}/randomname_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Randomname.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/randomname_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --src=E_Randomname.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Randomname.pb.h ${PROTOCGEN_FILE_PATH}/E_Randomname.pb.cc ${PROTOCGEN_FILE_PATH}/E_Randomname_s.h ${PROTOCGEN_FILE_PATH}/E_Randomname_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/randomname_proto_finish


${PROTOCGEN_FILE_PATH}/sensitiveword_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Sensitiveword.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/sensitiveword_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds --src=E_Sensitiveword.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Sensitiveword.pb.h ${PROTOCGEN_FILE_PATH}/E_Sensitiveword.pb.cc ${PROTOCGEN_FILE_PATH}/E_Sensitiveword_s.h ${PROTOCGEN_FILE_PATH}/E_Sensitiveword_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/sensitiveword_proto_finish


${PROTOCGEN_FILE_PATH}/map_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Map.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/map_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/map.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/map.proto.ds --src=E_Map.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Map.pb.h ${PROTOCGEN_FILE_PATH}/E_Map.pb.cc ${PROTOCGEN_FILE_PATH}/E_Map_s.h ${PROTOCGEN_FILE_PATH}/E_Map_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/map_proto_finish


${PROTOCGEN_FILE_PATH}/monster_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Monster.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/monster_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/monster.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --src=E_Monster.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Monster.pb.h ${PROTOCGEN_FILE_PATH}/E_Monster.pb.cc ${PROTOCGEN_FILE_PATH}/E_Monster_s.h ${PROTOCGEN_FILE_PATH}/E_Monster_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/monster_proto_finish


${PROTOCGEN_FILE_PATH}/mount_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Mount.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mount_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mount.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --src=E_Mount.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mount.pb.h ${PROTOCGEN_FILE_PATH}/E_Mount.pb.cc ${PROTOCGEN_FILE_PATH}/E_Mount_s.h ${PROTOCGEN_FILE_PATH}/E_Mount_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mount_proto_finish


${PROTOCGEN_FILE_PATH}/area_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Area.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/area_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/area.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds --src=E_Area.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Area.pb.h ${PROTOCGEN_FILE_PATH}/E_Area.pb.cc ${PROTOCGEN_FILE_PATH}/E_Area_s.h ${PROTOCGEN_FILE_PATH}/E_Area_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/area_proto_finish


${PROTOCGEN_FILE_PATH}/skill_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Skill.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/skill_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/skill.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --src=E_Skill.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Skill.pb.h ${PROTOCGEN_FILE_PATH}/E_Skill.pb.cc ${PROTOCGEN_FILE_PATH}/E_Skill_s.h ${PROTOCGEN_FILE_PATH}/E_Skill_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/skill_proto_finish


${PROTOCGEN_FILE_PATH}/item_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Item.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/item_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/item.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/item.proto.ds --src=E_Item.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Item.pb.h ${PROTOCGEN_FILE_PATH}/E_Item.pb.cc ${PROTOCGEN_FILE_PATH}/E_Item_s.h ${PROTOCGEN_FILE_PATH}/E_Item_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/item_proto_finish


${PROTOCGEN_FILE_PATH}/equip_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Equip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/equip_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/equip.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --src=E_Equip.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Equip.pb.h ${PROTOCGEN_FILE_PATH}/E_Equip.pb.cc ${PROTOCGEN_FILE_PATH}/E_Equip_s.h ${PROTOCGEN_FILE_PATH}/E_Equip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/equip_proto_finish


${PROTOCGEN_FILE_PATH}/constant_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Constant.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/constant_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/constant.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --src=E_Constant.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Constant.pb.h ${PROTOCGEN_FILE_PATH}/E_Constant.pb.cc ${PROTOCGEN_FILE_PATH}/E_Constant_s.h ${PROTOCGEN_FILE_PATH}/E_Constant_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/constant_proto_finish


${PROTOCGEN_FILE_PATH}/attribute_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Attribute.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/attribute_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/attribute.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds --src=E_Attribute.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Attribute.pb.h ${PROTOCGEN_FILE_PATH}/E_Attribute.pb.cc ${PROTOCGEN_FILE_PATH}/E_Attribute_s.h ${PROTOCGEN_FILE_PATH}/E_Attribute_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/attribute_proto_finish


${PROTOCGEN_FILE_PATH}/fashion_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Fashion.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/fashion_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/fashion.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/fashion.proto.ds --src=E_Fashion.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Fashion.pb.h ${PROTOCGEN_FILE_PATH}/E_Fashion.pb.cc ${PROTOCGEN_FILE_PATH}/E_Fashion_s.h ${PROTOCGEN_FILE_PATH}/E_Fashion_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/fashion_proto_finish


${PROTOCGEN_FILE_PATH}/decorate_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Decorate.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/decorate_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/decorate.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/decorate.proto.ds --src=E_Decorate.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Decorate.pb.h ${PROTOCGEN_FILE_PATH}/E_Decorate.pb.cc ${PROTOCGEN_FILE_PATH}/E_Decorate_s.h ${PROTOCGEN_FILE_PATH}/E_Decorate_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/decorate_proto_finish


${PROTOCGEN_FILE_PATH}/footprint_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Footprint.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/footprint_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/footprint.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/footprint.proto.ds --src=E_Footprint.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Footprint.pb.h ${PROTOCGEN_FILE_PATH}/E_Footprint.pb.cc ${PROTOCGEN_FILE_PATH}/E_Footprint_s.h ${PROTOCGEN_FILE_PATH}/E_Footprint_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/footprint_proto_finish


${PROTOCGEN_FILE_PATH}/halo_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Halo.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/halo_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/halo.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/halo.proto.ds --src=E_Halo.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Halo.pb.h ${PROTOCGEN_FILE_PATH}/E_Halo.pb.cc ${PROTOCGEN_FILE_PATH}/E_Halo_s.h ${PROTOCGEN_FILE_PATH}/E_Halo_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/halo_proto_finish


${PROTOCGEN_FILE_PATH}/headPortrait_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Headportrait.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/headPortrait_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --src=E_Headportrait.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Headportrait.pb.h ${PROTOCGEN_FILE_PATH}/E_Headportrait.pb.cc ${PROTOCGEN_FILE_PATH}/E_Headportrait_s.h ${PROTOCGEN_FILE_PATH}/E_Headportrait_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/headPortrait_proto_finish


${PROTOCGEN_FILE_PATH}/meditation_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Meditation.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/meditation_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/meditation.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/meditation.proto.ds --src=E_Meditation.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Meditation.pb.h ${PROTOCGEN_FILE_PATH}/E_Meditation.pb.cc ${PROTOCGEN_FILE_PATH}/E_Meditation_s.h ${PROTOCGEN_FILE_PATH}/E_Meditation_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/meditation_proto_finish


${PROTOCGEN_FILE_PATH}/functionunlock_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Functionunlock.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/functionunlock_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/functionunlock.proto.ds --src=E_Functionunlock.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Functionunlock.pb.h ${PROTOCGEN_FILE_PATH}/E_Functionunlock.pb.cc ${PROTOCGEN_FILE_PATH}/E_Functionunlock_s.h ${PROTOCGEN_FILE_PATH}/E_Functionunlock_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/functionunlock_proto_finish


${PROTOCGEN_FILE_PATH}/GMCommand_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Gmcommand.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/GMCommand_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/GMCommand.proto.ds --src=E_Gmcommand.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Gmcommand.pb.h ${PROTOCGEN_FILE_PATH}/E_Gmcommand.pb.cc ${PROTOCGEN_FILE_PATH}/E_Gmcommand_s.h ${PROTOCGEN_FILE_PATH}/E_Gmcommand_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/GMCommand_proto_finish


${PROTOCGEN_FILE_PATH}/appearance_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Appearance.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/appearance_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/appearance.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/appearance.proto.ds --src=E_Appearance.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Appearance.pb.h ${PROTOCGEN_FILE_PATH}/E_Appearance.pb.cc ${PROTOCGEN_FILE_PATH}/E_Appearance_s.h ${PROTOCGEN_FILE_PATH}/E_Appearance_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/appearance_proto_finish


${PROTOCGEN_FILE_PATH}/link_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Link.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/link_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/link.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/link.proto.ds --src=E_Link.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Link.pb.h ${PROTOCGEN_FILE_PATH}/E_Link.pb.cc ${PROTOCGEN_FILE_PATH}/E_Link_s.h ${PROTOCGEN_FILE_PATH}/E_Link_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/link_proto_finish


${PROTOCGEN_FILE_PATH}/mail_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Mail.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mail_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mail.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/mail.proto.ds --src=E_Mail.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mail.pb.h ${PROTOCGEN_FILE_PATH}/E_Mail.pb.cc ${PROTOCGEN_FILE_PATH}/E_Mail_s.h ${PROTOCGEN_FILE_PATH}/E_Mail_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mail_proto_finish


${PROTOCGEN_FILE_PATH}/mall_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Mall.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mall_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mall.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/mall.proto.ds --src=E_Mall.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mall.pb.h ${PROTOCGEN_FILE_PATH}/E_Mall.pb.cc ${PROTOCGEN_FILE_PATH}/E_Mall_s.h ${PROTOCGEN_FILE_PATH}/E_Mall_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mall_proto_finish


${PROTOCGEN_FILE_PATH}/chat_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Chat.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/chat_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/chat.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/chat.proto.ds --src=E_Chat.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Chat.pb.h ${PROTOCGEN_FILE_PATH}/E_Chat.pb.cc ${PROTOCGEN_FILE_PATH}/E_Chat_s.h ${PROTOCGEN_FILE_PATH}/E_Chat_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/chat_proto_finish


${PROTOCGEN_FILE_PATH}/path_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Path.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/path_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/path.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/path.proto.ds --src=E_Path.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Path.pb.h ${PROTOCGEN_FILE_PATH}/E_Path.pb.cc ${PROTOCGEN_FILE_PATH}/E_Path_s.h ${PROTOCGEN_FILE_PATH}/E_Path_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/path_proto_finish


${PROTOCGEN_FILE_PATH}/intimacy_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Intimacy.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/intimacy_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds --src=E_Intimacy.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Intimacy.pb.h ${PROTOCGEN_FILE_PATH}/E_Intimacy.pb.cc ${PROTOCGEN_FILE_PATH}/E_Intimacy_s.h ${PROTOCGEN_FILE_PATH}/E_Intimacy_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/intimacy_proto_finish


${PROTOCGEN_FILE_PATH}/ai_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Ai.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ai_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ai.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/ai.proto.ds --src=E_Ai.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ai.pb.h ${PROTOCGEN_FILE_PATH}/E_Ai.pb.cc ${PROTOCGEN_FILE_PATH}/E_Ai_s.h ${PROTOCGEN_FILE_PATH}/E_Ai_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ai_proto_finish


${PROTOCGEN_FILE_PATH}/boss_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Boss.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/boss_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/boss.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --src=E_Boss.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Boss.pb.h ${PROTOCGEN_FILE_PATH}/E_Boss.pb.cc ${PROTOCGEN_FILE_PATH}/E_Boss_s.h ${PROTOCGEN_FILE_PATH}/E_Boss_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/boss_proto_finish


${PROTOCGEN_FILE_PATH}/point_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Point.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/point_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/point.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/point.proto.ds --src=E_Point.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Point.pb.h ${PROTOCGEN_FILE_PATH}/E_Point.pb.cc ${PROTOCGEN_FILE_PATH}/E_Point_s.h ${PROTOCGEN_FILE_PATH}/E_Point_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/point_proto_finish


${PROTOCGEN_FILE_PATH}/facade_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Facade.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/facade_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/facade.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --src=E_Facade.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Facade.pb.h ${PROTOCGEN_FILE_PATH}/E_Facade.pb.cc ${PROTOCGEN_FILE_PATH}/E_Facade_s.h ${PROTOCGEN_FILE_PATH}/E_Facade_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/facade_proto_finish


${PROTOCGEN_FILE_PATH}/dup_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Dup.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/dup_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/dup.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --src=E_Dup.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Dup.pb.h ${PROTOCGEN_FILE_PATH}/E_Dup.pb.cc ${PROTOCGEN_FILE_PATH}/E_Dup_s.h ${PROTOCGEN_FILE_PATH}/E_Dup_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/dup_proto_finish


${PROTOCGEN_FILE_PATH}/offline_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Offline.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/offline_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/offline.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds --src=E_Offline.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Offline.pb.h ${PROTOCGEN_FILE_PATH}/E_Offline.pb.cc ${PROTOCGEN_FILE_PATH}/E_Offline_s.h ${PROTOCGEN_FILE_PATH}/E_Offline_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/offline_proto_finish


${PROTOCGEN_FILE_PATH}/godRelics_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Godrelics.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/godRelics_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds --src=E_Godrelics.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Godrelics.pb.h ${PROTOCGEN_FILE_PATH}/E_Godrelics.pb.cc ${PROTOCGEN_FILE_PATH}/E_Godrelics_s.h ${PROTOCGEN_FILE_PATH}/E_Godrelics_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/godRelics_proto_finish


${PROTOCGEN_FILE_PATH}/condition_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Condition.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/condition_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/condition.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/condition.proto.ds --src=E_Condition.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Condition.pb.h ${PROTOCGEN_FILE_PATH}/E_Condition.pb.cc ${PROTOCGEN_FILE_PATH}/E_Condition_s.h ${PROTOCGEN_FILE_PATH}/E_Condition_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/condition_proto_finish


${PROTOCGEN_FILE_PATH}/audio_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Audio.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/audio_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/audio.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/audio.proto.ds --src=E_Audio.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Audio.pb.h ${PROTOCGEN_FILE_PATH}/E_Audio.pb.cc ${PROTOCGEN_FILE_PATH}/E_Audio_s.h ${PROTOCGEN_FILE_PATH}/E_Audio_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/audio_proto_finish


${PROTOCGEN_FILE_PATH}/perActivity_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Peractivity.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/perActivity_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --src=E_Peractivity.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Peractivity.pb.h ${PROTOCGEN_FILE_PATH}/E_Peractivity.pb.cc ${PROTOCGEN_FILE_PATH}/E_Peractivity_s.h ${PROTOCGEN_FILE_PATH}/E_Peractivity_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/perActivity_proto_finish


${PROTOCGEN_FILE_PATH}/daily_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Daily.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/daily_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/daily.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/daily.proto.ds --src=E_Daily.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Daily.pb.h ${PROTOCGEN_FILE_PATH}/E_Daily.pb.cc ${PROTOCGEN_FILE_PATH}/E_Daily_s.h ${PROTOCGEN_FILE_PATH}/E_Daily_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/daily_proto_finish


${PROTOCGEN_FILE_PATH}/back_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Back.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/back_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/back.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/back.proto.ds --src=E_Back.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Back.pb.h ${PROTOCGEN_FILE_PATH}/E_Back.pb.cc ${PROTOCGEN_FILE_PATH}/E_Back_s.h ${PROTOCGEN_FILE_PATH}/E_Back_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/back_proto_finish


${PROTOCGEN_FILE_PATH}/set_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Set.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/set_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/set.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/set.proto.ds --src=E_Set.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Set.pb.h ${PROTOCGEN_FILE_PATH}/E_Set.pb.cc ${PROTOCGEN_FILE_PATH}/E_Set_s.h ${PROTOCGEN_FILE_PATH}/E_Set_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/set_proto_finish


${PROTOCGEN_FILE_PATH}/team_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Team.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/team_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/team.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/team.proto.ds --src=E_Team.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Team.pb.h ${PROTOCGEN_FILE_PATH}/E_Team.pb.cc ${PROTOCGEN_FILE_PATH}/E_Team_s.h ${PROTOCGEN_FILE_PATH}/E_Team_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/team_proto_finish


${PROTOCGEN_FILE_PATH}/box_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Box.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/box_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/box.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds --src=E_Box.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Box.pb.h ${PROTOCGEN_FILE_PATH}/E_Box.pb.cc ${PROTOCGEN_FILE_PATH}/E_Box_s.h ${PROTOCGEN_FILE_PATH}/E_Box_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/box_proto_finish


${PROTOCGEN_FILE_PATH}/task_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Task.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/task_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/task.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/task.proto.ds --src=E_Task.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Task.pb.h ${PROTOCGEN_FILE_PATH}/E_Task.pb.cc ${PROTOCGEN_FILE_PATH}/E_Task_s.h ${PROTOCGEN_FILE_PATH}/E_Task_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/task_proto_finish


${PROTOCGEN_FILE_PATH}/taskdynamic_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Taskdynamic.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/taskdynamic_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --src=E_Taskdynamic.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Taskdynamic.pb.h ${PROTOCGEN_FILE_PATH}/E_Taskdynamic.pb.cc ${PROTOCGEN_FILE_PATH}/E_Taskdynamic_s.h ${PROTOCGEN_FILE_PATH}/E_Taskdynamic_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/taskdynamic_proto_finish


${PROTOCGEN_FILE_PATH}/taskreward_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Taskreward.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/taskreward_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds --src=E_Taskreward.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Taskreward.pb.h ${PROTOCGEN_FILE_PATH}/E_Taskreward.pb.cc ${PROTOCGEN_FILE_PATH}/E_Taskreward_s.h ${PROTOCGEN_FILE_PATH}/E_Taskreward_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/taskreward_proto_finish


${PROTOCGEN_FILE_PATH}/tasktracker_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Tasktracker.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/tasktracker_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds --src=E_Tasktracker.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Tasktracker.pb.h ${PROTOCGEN_FILE_PATH}/E_Tasktracker.pb.cc ${PROTOCGEN_FILE_PATH}/E_Tasktracker_s.h ${PROTOCGEN_FILE_PATH}/E_Tasktracker_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/tasktracker_proto_finish


${PROTOCGEN_FILE_PATH}/flash_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Flash.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/flash_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/flash.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds --src=E_Flash.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Flash.pb.h ${PROTOCGEN_FILE_PATH}/E_Flash.pb.cc ${PROTOCGEN_FILE_PATH}/E_Flash_s.h ${PROTOCGEN_FILE_PATH}/E_Flash_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/flash_proto_finish


${PROTOCGEN_FILE_PATH}/button_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Button.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/button_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/button.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/button.proto.ds --src=E_Button.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Button.pb.h ${PROTOCGEN_FILE_PATH}/E_Button.pb.cc ${PROTOCGEN_FILE_PATH}/E_Button_s.h ${PROTOCGEN_FILE_PATH}/E_Button_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/button_proto_finish


${PROTOCGEN_FILE_PATH}/vip_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Vip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/vip_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/vip.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/vip.proto.ds --src=E_Vip.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Vip.pb.h ${PROTOCGEN_FILE_PATH}/E_Vip.pb.cc ${PROTOCGEN_FILE_PATH}/E_Vip_s.h ${PROTOCGEN_FILE_PATH}/E_Vip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/vip_proto_finish


${PROTOCGEN_FILE_PATH}/arena_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Arena.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/arena_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/arena.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --src=E_Arena.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Arena.pb.h ${PROTOCGEN_FILE_PATH}/E_Arena.pb.cc ${PROTOCGEN_FILE_PATH}/E_Arena_s.h ${PROTOCGEN_FILE_PATH}/E_Arena_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/arena_proto_finish


${PROTOCGEN_FILE_PATH}/pet_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Pet.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/pet_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/pet.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --src=E_Pet.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pet.pb.h ${PROTOCGEN_FILE_PATH}/E_Pet.pb.cc ${PROTOCGEN_FILE_PATH}/E_Pet_s.h ${PROTOCGEN_FILE_PATH}/E_Pet_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/pet_proto_finish


${PROTOCGEN_FILE_PATH}/avatar_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Avatar.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/avatar_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --src=E_Avatar.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Avatar.pb.h ${PROTOCGEN_FILE_PATH}/E_Avatar.pb.cc ${PROTOCGEN_FILE_PATH}/E_Avatar_s.h ${PROTOCGEN_FILE_PATH}/E_Avatar_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/avatar_proto_finish


${PROTOCGEN_FILE_PATH}/assist_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Assist.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/assist_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/assist.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/assist.proto.ds --src=E_Assist.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Assist.pb.h ${PROTOCGEN_FILE_PATH}/E_Assist.pb.cc ${PROTOCGEN_FILE_PATH}/E_Assist_s.h ${PROTOCGEN_FILE_PATH}/E_Assist_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/assist_proto_finish


${PROTOCGEN_FILE_PATH}/moneyReward_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Moneyreward.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/moneyReward_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/moneyReward.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/moneyReward.proto.ds --src=E_Moneyreward.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Moneyreward.pb.h ${PROTOCGEN_FILE_PATH}/E_Moneyreward.pb.cc ${PROTOCGEN_FILE_PATH}/E_Moneyreward_s.h ${PROTOCGEN_FILE_PATH}/E_Moneyreward_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/moneyReward_proto_finish


${PROTOCGEN_FILE_PATH}/escort_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Escort.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/escort_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/escort.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --src=E_Escort.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Escort.pb.h ${PROTOCGEN_FILE_PATH}/E_Escort.pb.cc ${PROTOCGEN_FILE_PATH}/E_Escort_s.h ${PROTOCGEN_FILE_PATH}/E_Escort_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/escort_proto_finish


${PROTOCGEN_FILE_PATH}/guild_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Guild.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/guild_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/guild.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --src=E_Guild.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Guild.pb.h ${PROTOCGEN_FILE_PATH}/E_Guild.pb.cc ${PROTOCGEN_FILE_PATH}/E_Guild_s.h ${PROTOCGEN_FILE_PATH}/E_Guild_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/guild_proto_finish


${PROTOCGEN_FILE_PATH}/collect_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Collect.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/collect_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/collect.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/collect.proto.ds --src=E_Collect.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Collect.pb.h ${PROTOCGEN_FILE_PATH}/E_Collect.pb.cc ${PROTOCGEN_FILE_PATH}/E_Collect_s.h ${PROTOCGEN_FILE_PATH}/E_Collect_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/collect_proto_finish


${PROTOCGEN_FILE_PATH}/title_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Title.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/title_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/title.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --src=E_Title.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Title.pb.h ${PROTOCGEN_FILE_PATH}/E_Title.pb.cc ${PROTOCGEN_FILE_PATH}/E_Title_s.h ${PROTOCGEN_FILE_PATH}/E_Title_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/title_proto_finish


${PROTOCGEN_FILE_PATH}/godevil_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Godevil.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/godevil_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/godevil.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/godevil.proto.ds --src=E_Godevil.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Godevil.pb.h ${PROTOCGEN_FILE_PATH}/E_Godevil.pb.cc ${PROTOCGEN_FILE_PATH}/E_Godevil_s.h ${PROTOCGEN_FILE_PATH}/E_Godevil_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/godevil_proto_finish


${PROTOCGEN_FILE_PATH}/occupation_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Occupation.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/occupation_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --src=E_Occupation.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Occupation.pb.h ${PROTOCGEN_FILE_PATH}/E_Occupation.pb.cc ${PROTOCGEN_FILE_PATH}/E_Occupation_s.h ${PROTOCGEN_FILE_PATH}/E_Occupation_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/occupation_proto_finish


${PROTOCGEN_FILE_PATH}/Godvalley_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Godvalley.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/Godvalley_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/Godvalley.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/Godvalley.proto.ds --src=E_Godvalley.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Godvalley.pb.h ${PROTOCGEN_FILE_PATH}/E_Godvalley.pb.cc ${PROTOCGEN_FILE_PATH}/E_Godvalley_s.h ${PROTOCGEN_FILE_PATH}/E_Godvalley_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/Godvalley_proto_finish


${PROTOCGEN_FILE_PATH}/recharge_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Recharge.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/recharge_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/recharge.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/recharge.proto.ds --src=E_Recharge.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Recharge.pb.h ${PROTOCGEN_FILE_PATH}/E_Recharge.pb.cc ${PROTOCGEN_FILE_PATH}/E_Recharge_s.h ${PROTOCGEN_FILE_PATH}/E_Recharge_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/recharge_proto_finish


${PROTOCGEN_FILE_PATH}/shenequip_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Shenequip.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/shenequip_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --src=E_Shenequip.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Shenequip.pb.h ${PROTOCGEN_FILE_PATH}/E_Shenequip.pb.cc ${PROTOCGEN_FILE_PATH}/E_Shenequip_s.h ${PROTOCGEN_FILE_PATH}/E_Shenequip_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/shenequip_proto_finish


${PROTOCGEN_FILE_PATH}/achievement_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Achievement.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/achievement_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/achievement.proto.ds --src=E_Achievement.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Achievement.pb.h ${PROTOCGEN_FILE_PATH}/E_Achievement.pb.cc ${PROTOCGEN_FILE_PATH}/E_Achievement_s.h ${PROTOCGEN_FILE_PATH}/E_Achievement_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/achievement_proto_finish


${PROTOCGEN_FILE_PATH}/ancientgod_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Ancientgod.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ancientgod_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ancientgod.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/ancientgod.proto.ds --src=E_Ancientgod.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ancientgod.pb.h ${PROTOCGEN_FILE_PATH}/E_Ancientgod.pb.cc ${PROTOCGEN_FILE_PATH}/E_Ancientgod_s.h ${PROTOCGEN_FILE_PATH}/E_Ancientgod_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ancientgod_proto_finish


${PROTOCGEN_FILE_PATH}/xiuzhen_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Xiuzhen.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xiuzhen_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/xiuzhen.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/xiuzhen.proto.ds --src=E_Xiuzhen.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xiuzhen.pb.h ${PROTOCGEN_FILE_PATH}/E_Xiuzhen.pb.cc ${PROTOCGEN_FILE_PATH}/E_Xiuzhen_s.h ${PROTOCGEN_FILE_PATH}/E_Xiuzhen_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xiuzhen_proto_finish


${PROTOCGEN_FILE_PATH}/encyclopedia_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Encyclopedia.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/encyclopedia_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/encyclopedia.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/encyclopedia.proto.ds --src=E_Encyclopedia.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Encyclopedia.pb.h ${PROTOCGEN_FILE_PATH}/E_Encyclopedia.pb.cc ${PROTOCGEN_FILE_PATH}/E_Encyclopedia_s.h ${PROTOCGEN_FILE_PATH}/E_Encyclopedia_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/encyclopedia_proto_finish


${PROTOCGEN_FILE_PATH}/talent_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Talent.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/talent_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/talent.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/talent.proto.ds --src=E_Talent.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Talent.pb.h ${PROTOCGEN_FILE_PATH}/E_Talent.pb.cc ${PROTOCGEN_FILE_PATH}/E_Talent_s.h ${PROTOCGEN_FILE_PATH}/E_Talent_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/talent_proto_finish


${PROTOCGEN_FILE_PATH}/marry_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Marry.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/marry_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/marry.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/marry.proto.ds --src=E_Marry.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Marry.pb.h ${PROTOCGEN_FILE_PATH}/E_Marry.pb.cc ${PROTOCGEN_FILE_PATH}/E_Marry_s.h ${PROTOCGEN_FILE_PATH}/E_Marry_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/marry_proto_finish


${PROTOCGEN_FILE_PATH}/ranking_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Ranking.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ranking_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/ranking.proto.ds --src=E_Ranking.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ranking.pb.h ${PROTOCGEN_FILE_PATH}/E_Ranking.pb.cc ${PROTOCGEN_FILE_PATH}/E_Ranking_s.h ${PROTOCGEN_FILE_PATH}/E_Ranking_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ranking_proto_finish


${PROTOCGEN_FILE_PATH}/waremblem_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Waremblem.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/waremblem_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/waremblem.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/waremblem.proto.ds --src=E_Waremblem.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Waremblem.pb.h ${PROTOCGEN_FILE_PATH}/E_Waremblem.pb.cc ${PROTOCGEN_FILE_PATH}/E_Waremblem_s.h ${PROTOCGEN_FILE_PATH}/E_Waremblem_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/waremblem_proto_finish


${PROTOCGEN_FILE_PATH}/pk1v1_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Pk1v1.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/pk1v1_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/pk1v1.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/pk1v1.proto.ds --src=E_Pk1v1.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk1v1.pb.h ${PROTOCGEN_FILE_PATH}/E_Pk1v1.pb.cc ${PROTOCGEN_FILE_PATH}/E_Pk1v1_s.h ${PROTOCGEN_FILE_PATH}/E_Pk1v1_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/pk1v1_proto_finish


${PROTOCGEN_FILE_PATH}/conflate_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Conflate.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/conflate_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/conflate.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/conflate.proto.ds --src=E_Conflate.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Conflate.pb.h ${PROTOCGEN_FILE_PATH}/E_Conflate.pb.cc ${PROTOCGEN_FILE_PATH}/E_Conflate_s.h ${PROTOCGEN_FILE_PATH}/E_Conflate_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/conflate_proto_finish


${PROTOCGEN_FILE_PATH}/dragonSoul_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Dragonsoul.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/dragonSoul_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/dragonSoul.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/dragonSoul.proto.ds --src=E_Dragonsoul.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Dragonsoul.pb.h ${PROTOCGEN_FILE_PATH}/E_Dragonsoul.pb.cc ${PROTOCGEN_FILE_PATH}/E_Dragonsoul_s.h ${PROTOCGEN_FILE_PATH}/E_Dragonsoul_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/dragonSoul_proto_finish


${PROTOCGEN_FILE_PATH}/personalshop_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Personalshop.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/personalshop_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/personalshop.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/personalshop.proto.ds --src=E_Personalshop.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Personalshop.pb.h ${PROTOCGEN_FILE_PATH}/E_Personalshop.pb.cc ${PROTOCGEN_FILE_PATH}/E_Personalshop_s.h ${PROTOCGEN_FILE_PATH}/E_Personalshop_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/personalshop_proto_finish


${PROTOCGEN_FILE_PATH}/washparty_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Washparty.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/washparty_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/washparty.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/washparty.proto.ds --src=E_Washparty.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Washparty.pb.h ${PROTOCGEN_FILE_PATH}/E_Washparty.pb.cc ${PROTOCGEN_FILE_PATH}/E_Washparty_s.h ${PROTOCGEN_FILE_PATH}/E_Washparty_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/washparty_proto_finish


${PROTOCGEN_FILE_PATH}/welfare_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Welfare.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/welfare_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/welfare.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/welfare.proto.ds --src=E_Welfare.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Welfare.pb.h ${PROTOCGEN_FILE_PATH}/E_Welfare.pb.cc ${PROTOCGEN_FILE_PATH}/E_Welfare_s.h ${PROTOCGEN_FILE_PATH}/E_Welfare_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/welfare_proto_finish


${PROTOCGEN_FILE_PATH}/qyPeak_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Qypeak.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/qyPeak_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/qyPeak.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/qyPeak.proto.ds --src=E_Qypeak.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Qypeak.pb.h ${PROTOCGEN_FILE_PATH}/E_Qypeak.pb.cc ${PROTOCGEN_FILE_PATH}/E_Qypeak_s.h ${PROTOCGEN_FILE_PATH}/E_Qypeak_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/qyPeak_proto_finish


${PROTOCGEN_FILE_PATH}/pk3v3_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Pk3v3.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/pk3v3_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/pk3v3.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/pk3v3.proto.ds --src=E_Pk3v3.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3.pb.h ${PROTOCGEN_FILE_PATH}/E_Pk3v3.pb.cc ${PROTOCGEN_FILE_PATH}/E_Pk3v3_s.h ${PROTOCGEN_FILE_PATH}/E_Pk3v3_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/pk3v3_proto_finish


${PROTOCGEN_FILE_PATH}/guide_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Guide.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/guide_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/guide.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/guide.proto.ds --src=E_Guide.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Guide.pb.h ${PROTOCGEN_FILE_PATH}/E_Guide.pb.cc ${PROTOCGEN_FILE_PATH}/E_Guide_s.h ${PROTOCGEN_FILE_PATH}/E_Guide_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/guide_proto_finish


${PROTOCGEN_FILE_PATH}/cloudPeak_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Cloudpeak.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/cloudPeak_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/cloudPeak.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/cloudPeak.proto.ds --src=E_Cloudpeak.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Cloudpeak.pb.h ${PROTOCGEN_FILE_PATH}/E_Cloudpeak.pb.cc ${PROTOCGEN_FILE_PATH}/E_Cloudpeak_s.h ${PROTOCGEN_FILE_PATH}/E_Cloudpeak_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/cloudPeak_proto_finish


${PROTOCGEN_FILE_PATH}/xiuzhenroad_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Xiuzhenroad.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xiuzhenroad_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/xiuzhenroad.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/xiuzhenroad.proto.ds --src=E_Xiuzhenroad.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xiuzhenroad.pb.h ${PROTOCGEN_FILE_PATH}/E_Xiuzhenroad.pb.cc ${PROTOCGEN_FILE_PATH}/E_Xiuzhenroad_s.h ${PROTOCGEN_FILE_PATH}/E_Xiuzhenroad_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xiuzhenroad_proto_finish


${PROTOCGEN_FILE_PATH}/gift_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Gift.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/gift_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/gift.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/gift.proto.ds --src=E_Gift.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Gift.pb.h ${PROTOCGEN_FILE_PATH}/E_Gift.pb.cc ${PROTOCGEN_FILE_PATH}/E_Gift_s.h ${PROTOCGEN_FILE_PATH}/E_Gift_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/gift_proto_finish


${PROTOCGEN_FILE_PATH}/battlePass_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Battlepass.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/battlePass_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/battlePass.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/battlePass.proto.ds --src=E_Battlepass.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Battlepass.pb.h ${PROTOCGEN_FILE_PATH}/E_Battlepass.pb.cc ${PROTOCGEN_FILE_PATH}/E_Battlepass_s.h ${PROTOCGEN_FILE_PATH}/E_Battlepass_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/battlePass_proto_finish


${PROTOCGEN_FILE_PATH}/findTreasure_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Findtreasure.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/findTreasure_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/findTreasure.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/findTreasure.proto.ds --src=E_Findtreasure.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Findtreasure.pb.h ${PROTOCGEN_FILE_PATH}/E_Findtreasure.pb.cc ${PROTOCGEN_FILE_PATH}/E_Findtreasure_s.h ${PROTOCGEN_FILE_PATH}/E_Findtreasure_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/findTreasure_proto_finish


${PROTOCGEN_FILE_PATH}/festival_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Festival.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/festival_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/festival.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/festival.proto.ds --src=E_Festival.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Festival.pb.h ${PROTOCGEN_FILE_PATH}/E_Festival.pb.cc ${PROTOCGEN_FILE_PATH}/E_Festival_s.h ${PROTOCGEN_FILE_PATH}/E_Festival_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/festival_proto_finish


${PROTOCGEN_FILE_PATH}/market_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Market.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/market_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/market.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/market.proto.ds --src=E_Market.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Market.pb.h ${PROTOCGEN_FILE_PATH}/E_Market.pb.cc ${PROTOCGEN_FILE_PATH}/E_Market_s.h ${PROTOCGEN_FILE_PATH}/E_Market_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/market_proto_finish


${PROTOCGEN_FILE_PATH}/dragon_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Dragon.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/dragon_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/dragon.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/dragon.proto.ds --src=E_Dragon.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Dragon.pb.h ${PROTOCGEN_FILE_PATH}/E_Dragon.pb.cc ${PROTOCGEN_FILE_PATH}/E_Dragon_s.h ${PROTOCGEN_FILE_PATH}/E_Dragon_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/dragon_proto_finish


${PROTOCGEN_FILE_PATH}/yanglong_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Yanglong.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/yanglong_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/yanglong.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/yanglong.proto.ds --src=E_Yanglong.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Yanglong.pb.h ${PROTOCGEN_FILE_PATH}/E_Yanglong.pb.cc ${PROTOCGEN_FILE_PATH}/E_Yanglong_s.h ${PROTOCGEN_FILE_PATH}/E_Yanglong_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/yanglong_proto_finish


${PROTOCGEN_FILE_PATH}/timeline_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Timeline.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/timeline_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/timeline.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/timeline.proto.ds --src=E_Timeline.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Timeline.pb.h ${PROTOCGEN_FILE_PATH}/E_Timeline.pb.cc ${PROTOCGEN_FILE_PATH}/E_Timeline_s.h ${PROTOCGEN_FILE_PATH}/E_Timeline_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/timeline_proto_finish


${PROTOCGEN_FILE_PATH}/jinglian_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Jinglian.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/jinglian_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/jinglian.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/jinglian.proto.ds --src=E_Jinglian.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Jinglian.pb.h ${PROTOCGEN_FILE_PATH}/E_Jinglian.pb.cc ${PROTOCGEN_FILE_PATH}/E_Jinglian_s.h ${PROTOCGEN_FILE_PATH}/E_Jinglian_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/jinglian_proto_finish


${PROTOCGEN_FILE_PATH}/equipImprove_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Equipimprove.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/equipImprove_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/equipImprove.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/equipImprove.proto.ds --src=E_Equipimprove.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Equipimprove.pb.h ${PROTOCGEN_FILE_PATH}/E_Equipimprove.pb.cc ${PROTOCGEN_FILE_PATH}/E_Equipimprove_s.h ${PROTOCGEN_FILE_PATH}/E_Equipimprove_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/equipImprove_proto_finish


${PROTOCGEN_FILE_PATH}/teleport_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Teleport.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/teleport_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/teleport.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/teleport.proto.ds --src=E_Teleport.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Teleport.pb.h ${PROTOCGEN_FILE_PATH}/E_Teleport.pb.cc ${PROTOCGEN_FILE_PATH}/E_Teleport_s.h ${PROTOCGEN_FILE_PATH}/E_Teleport_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/teleport_proto_finish


${PROTOCGEN_FILE_PATH}/xingchen_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Xingchen.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xingchen_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/xingchen.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/xingchen.proto.ds --src=E_Xingchen.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xingchen.pb.h ${PROTOCGEN_FILE_PATH}/E_Xingchen.pb.cc ${PROTOCGEN_FILE_PATH}/E_Xingchen_s.h ${PROTOCGEN_FILE_PATH}/E_Xingchen_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xingchen_proto_finish


${PROTOCGEN_FILE_PATH}/mofa_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Mofa.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mofa_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/mofa.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/mofa.proto.ds --src=E_Mofa.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mofa.pb.h ${PROTOCGEN_FILE_PATH}/E_Mofa.pb.cc ${PROTOCGEN_FILE_PATH}/E_Mofa_s.h ${PROTOCGEN_FILE_PATH}/E_Mofa_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mofa_proto_finish


${PROTOCGEN_FILE_PATH}/shenti_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Shenti.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/shenti_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/shenti.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/shenti.proto.ds --src=E_Shenti.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Shenti.pb.h ${PROTOCGEN_FILE_PATH}/E_Shenti.pb.cc ${PROTOCGEN_FILE_PATH}/E_Shenti_s.h ${PROTOCGEN_FILE_PATH}/E_Shenti_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/shenti_proto_finish


${PROTOCGEN_FILE_PATH}/xiuzhenWorld_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/E_Xiuzhenworld.proto
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_proto_finish
	${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/xiuzhenWorld.proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltostruct" --proto_ds=${PROTOCGEN_FILE_PATH}/xiuzhenWorld.proto.ds --src=E_Xiuzhenworld.proto --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xiuzhenworld.pb.h ${PROTOCGEN_FILE_PATH}/E_Xiuzhenworld.pb.cc ${PROTOCGEN_FILE_PATH}/E_Xiuzhenworld_s.h ${PROTOCGEN_FILE_PATH}/E_Xiuzhenworld_s.cpp " --dst=${NEW_PROTOCGEN_FILE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_proto_finish


