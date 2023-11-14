include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/msg_xlsx_finish ${PROTOCGEN_FILE_PATH}/ui_xlsx_finish ${PROTOCGEN_FILE_PATH}/role_xlsx_finish ${PROTOCGEN_FILE_PATH}/randomname_xlsx_finish ${PROTOCGEN_FILE_PATH}/sensitiveword_xlsx_finish ${PROTOCGEN_FILE_PATH}/map_xlsx_finish ${PROTOCGEN_FILE_PATH}/monster_xlsx_finish ${PROTOCGEN_FILE_PATH}/mount_xlsx_finish ${PROTOCGEN_FILE_PATH}/area_xlsx_finish ${PROTOCGEN_FILE_PATH}/skill_xlsx_finish ${PROTOCGEN_FILE_PATH}/item_xlsx_finish ${PROTOCGEN_FILE_PATH}/equip_xlsx_finish ${PROTOCGEN_FILE_PATH}/constant_xlsx_finish ${PROTOCGEN_FILE_PATH}/attribute_xlsx_finish ${PROTOCGEN_FILE_PATH}/fashion_xlsx_finish ${PROTOCGEN_FILE_PATH}/decorate_xlsx_finish ${PROTOCGEN_FILE_PATH}/footprint_xlsx_finish ${PROTOCGEN_FILE_PATH}/halo_xlsx_finish ${PROTOCGEN_FILE_PATH}/headPortrait_xlsx_finish ${PROTOCGEN_FILE_PATH}/meditation_xlsx_finish ${PROTOCGEN_FILE_PATH}/functionunlock_xlsx_finish ${PROTOCGEN_FILE_PATH}/GMCommand_xlsx_finish ${PROTOCGEN_FILE_PATH}/appearance_xlsx_finish ${PROTOCGEN_FILE_PATH}/link_xlsx_finish ${PROTOCGEN_FILE_PATH}/mail_xlsx_finish ${PROTOCGEN_FILE_PATH}/mall_xlsx_finish ${PROTOCGEN_FILE_PATH}/chat_xlsx_finish ${PROTOCGEN_FILE_PATH}/path_xlsx_finish ${PROTOCGEN_FILE_PATH}/intimacy_xlsx_finish ${PROTOCGEN_FILE_PATH}/ai_xlsx_finish ${PROTOCGEN_FILE_PATH}/boss_xlsx_finish ${PROTOCGEN_FILE_PATH}/point_xlsx_finish ${PROTOCGEN_FILE_PATH}/facade_xlsx_finish ${PROTOCGEN_FILE_PATH}/dup_xlsx_finish ${PROTOCGEN_FILE_PATH}/offline_xlsx_finish ${PROTOCGEN_FILE_PATH}/godRelics_xlsx_finish ${PROTOCGEN_FILE_PATH}/condition_xlsx_finish ${PROTOCGEN_FILE_PATH}/audio_xlsx_finish ${PROTOCGEN_FILE_PATH}/perActivity_xlsx_finish ${PROTOCGEN_FILE_PATH}/daily_xlsx_finish ${PROTOCGEN_FILE_PATH}/back_xlsx_finish ${PROTOCGEN_FILE_PATH}/set_xlsx_finish ${PROTOCGEN_FILE_PATH}/team_xlsx_finish ${PROTOCGEN_FILE_PATH}/box_xlsx_finish ${PROTOCGEN_FILE_PATH}/task_xlsx_finish ${PROTOCGEN_FILE_PATH}/taskdynamic_xlsx_finish ${PROTOCGEN_FILE_PATH}/taskreward_xlsx_finish ${PROTOCGEN_FILE_PATH}/tasktracker_xlsx_finish ${PROTOCGEN_FILE_PATH}/flash_xlsx_finish ${PROTOCGEN_FILE_PATH}/button_xlsx_finish ${PROTOCGEN_FILE_PATH}/vip_xlsx_finish ${PROTOCGEN_FILE_PATH}/arena_xlsx_finish ${PROTOCGEN_FILE_PATH}/pet_xlsx_finish ${PROTOCGEN_FILE_PATH}/avatar_xlsx_finish ${PROTOCGEN_FILE_PATH}/assist_xlsx_finish ${PROTOCGEN_FILE_PATH}/moneyReward_xlsx_finish ${PROTOCGEN_FILE_PATH}/escort_xlsx_finish ${PROTOCGEN_FILE_PATH}/guild_xlsx_finish ${PROTOCGEN_FILE_PATH}/collect_xlsx_finish ${PROTOCGEN_FILE_PATH}/title_xlsx_finish ${PROTOCGEN_FILE_PATH}/godevil_xlsx_finish ${PROTOCGEN_FILE_PATH}/occupation_xlsx_finish ${PROTOCGEN_FILE_PATH}/Godvalley_xlsx_finish ${PROTOCGEN_FILE_PATH}/recharge_xlsx_finish ${PROTOCGEN_FILE_PATH}/shenequip_xlsx_finish ${PROTOCGEN_FILE_PATH}/achievement_xlsx_finish ${PROTOCGEN_FILE_PATH}/ancientgod_xlsx_finish ${PROTOCGEN_FILE_PATH}/xiuzhen_xlsx_finish ${PROTOCGEN_FILE_PATH}/encyclopedia_xlsx_finish ${PROTOCGEN_FILE_PATH}/talent_xlsx_finish ${PROTOCGEN_FILE_PATH}/marry_xlsx_finish ${PROTOCGEN_FILE_PATH}/ranking_xlsx_finish ${PROTOCGEN_FILE_PATH}/waremblem_xlsx_finish ${PROTOCGEN_FILE_PATH}/pk1v1_xlsx_finish ${PROTOCGEN_FILE_PATH}/conflate_xlsx_finish ${PROTOCGEN_FILE_PATH}/dragonSoul_xlsx_finish ${PROTOCGEN_FILE_PATH}/personalshop_xlsx_finish ${PROTOCGEN_FILE_PATH}/washparty_xlsx_finish ${PROTOCGEN_FILE_PATH}/welfare_xlsx_finish ${PROTOCGEN_FILE_PATH}/qyPeak_xlsx_finish ${PROTOCGEN_FILE_PATH}/pk3v3_xlsx_finish ${PROTOCGEN_FILE_PATH}/guide_xlsx_finish ${PROTOCGEN_FILE_PATH}/cloudPeak_xlsx_finish ${PROTOCGEN_FILE_PATH}/xiuzhenroad_xlsx_finish ${PROTOCGEN_FILE_PATH}/gift_xlsx_finish ${PROTOCGEN_FILE_PATH}/battlePass_xlsx_finish ${PROTOCGEN_FILE_PATH}/findTreasure_xlsx_finish ${PROTOCGEN_FILE_PATH}/festival_xlsx_finish ${PROTOCGEN_FILE_PATH}/market_xlsx_finish ${PROTOCGEN_FILE_PATH}/dragon_xlsx_finish ${PROTOCGEN_FILE_PATH}/yanglong_xlsx_finish ${PROTOCGEN_FILE_PATH}/timeline_xlsx_finish ${PROTOCGEN_FILE_PATH}/jinglian_xlsx_finish ${PROTOCGEN_FILE_PATH}/equipImprove_xlsx_finish ${PROTOCGEN_FILE_PATH}/teleport_xlsx_finish ${PROTOCGEN_FILE_PATH}/xingchen_xlsx_finish ${PROTOCGEN_FILE_PATH}/mofa_xlsx_finish ${PROTOCGEN_FILE_PATH}/shenti_xlsx_finish ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_xlsx_finish ${PROTOCGEN_FILE_PATH}/soul_xlsx_finish ${PROTOCGEN_FILE_PATH}/nickgod_xlsx_finish ${PROTOCGEN_FILE_PATH}/tianxiafirst_xlsx_finish 

${PROTOCGEN_FILE_PATH}/msg_xlsx_finish:${RESDB_EXCELMMO_PATH}/msg.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/msg_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/msg_xlsx_finish


${PROTOCGEN_FILE_PATH}/ui_xlsx_finish:${RESDB_EXCELMMO_PATH}/ui.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ui_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ui_xlsx_finish


${PROTOCGEN_FILE_PATH}/role_xlsx_finish:${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/role_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/role_xlsx_finish


${PROTOCGEN_FILE_PATH}/randomname_xlsx_finish:${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/randomname_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/randomname_xlsx_finish


${PROTOCGEN_FILE_PATH}/sensitiveword_xlsx_finish:${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/sensitiveword_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/sensitiveword_xlsx_finish


${PROTOCGEN_FILE_PATH}/map_xlsx_finish:${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/map_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/map_xlsx_finish


${PROTOCGEN_FILE_PATH}/monster_xlsx_finish:${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/monster_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/monster_xlsx_finish


${PROTOCGEN_FILE_PATH}/mount_xlsx_finish:${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mount_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mount.proto ${PROTOCGEN_FILE_PATH}/mount_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mount_xlsx_finish


${PROTOCGEN_FILE_PATH}/area_xlsx_finish:${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/area_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/area_xlsx_finish


${PROTOCGEN_FILE_PATH}/skill_xlsx_finish:${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/skill_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/skill_xlsx_finish


${PROTOCGEN_FILE_PATH}/item_xlsx_finish:${RESDB_EXCELMMO_PATH}/item.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/item_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/item_xlsx_finish


${PROTOCGEN_FILE_PATH}/equip_xlsx_finish:${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/equip_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/equip_xlsx_finish


${PROTOCGEN_FILE_PATH}/constant_xlsx_finish:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/constant_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/constant_xlsx_finish


${PROTOCGEN_FILE_PATH}/attribute_xlsx_finish:${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/attribute_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Attribute.proto ${PROTOCGEN_FILE_PATH}/attribute_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/attribute_xlsx_finish


${PROTOCGEN_FILE_PATH}/fashion_xlsx_finish:${RESDB_EXCELMMO_PATH}/fashion.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/fashion_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Fashion.proto ${PROTOCGEN_FILE_PATH}/fashion_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/fashion_xlsx_finish


${PROTOCGEN_FILE_PATH}/decorate_xlsx_finish:${RESDB_EXCELMMO_PATH}/decorate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/decorate_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Decorate.proto ${PROTOCGEN_FILE_PATH}/decorate_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/decorate_xlsx_finish


${PROTOCGEN_FILE_PATH}/footprint_xlsx_finish:${RESDB_EXCELMMO_PATH}/footprint.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/footprint_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Footprint.proto ${PROTOCGEN_FILE_PATH}/footprint_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/footprint_xlsx_finish


${PROTOCGEN_FILE_PATH}/halo_xlsx_finish:${RESDB_EXCELMMO_PATH}/halo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/halo_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Halo.proto ${PROTOCGEN_FILE_PATH}/halo_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/halo_xlsx_finish


${PROTOCGEN_FILE_PATH}/headPortrait_xlsx_finish:${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/headPortrait_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Headportrait.proto ${PROTOCGEN_FILE_PATH}/headPortrait_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/headPortrait_xlsx_finish


${PROTOCGEN_FILE_PATH}/meditation_xlsx_finish:${RESDB_EXCELMMO_PATH}/meditation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/meditation_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Meditation.proto ${PROTOCGEN_FILE_PATH}/meditation_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/meditation_xlsx_finish


${PROTOCGEN_FILE_PATH}/functionunlock_xlsx_finish:${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/functionunlock_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Functionunlock.proto ${PROTOCGEN_FILE_PATH}/functionunlock_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/functionunlock_xlsx_finish


${PROTOCGEN_FILE_PATH}/GMCommand_xlsx_finish:${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/GMCommand_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Gmcommand.proto ${PROTOCGEN_FILE_PATH}/GMCommand_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/GMCommand_xlsx_finish


${PROTOCGEN_FILE_PATH}/appearance_xlsx_finish:${RESDB_EXCELMMO_PATH}/appearance.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/appearance_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Appearance.proto ${PROTOCGEN_FILE_PATH}/appearance_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/appearance_xlsx_finish


${PROTOCGEN_FILE_PATH}/link_xlsx_finish:${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/link_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Link.proto ${PROTOCGEN_FILE_PATH}/link_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/link_xlsx_finish


${PROTOCGEN_FILE_PATH}/mail_xlsx_finish:${RESDB_EXCELMMO_PATH}/mail.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mail_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mail.proto ${PROTOCGEN_FILE_PATH}/mail_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mail_xlsx_finish


${PROTOCGEN_FILE_PATH}/mall_xlsx_finish:${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mall_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mall.proto ${PROTOCGEN_FILE_PATH}/mall_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mall_xlsx_finish


${PROTOCGEN_FILE_PATH}/chat_xlsx_finish:${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/chat_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Chat.proto ${PROTOCGEN_FILE_PATH}/chat_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/chat_xlsx_finish


${PROTOCGEN_FILE_PATH}/path_xlsx_finish:${RESDB_EXCELMMO_PATH}/path.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/path_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Path.proto ${PROTOCGEN_FILE_PATH}/path_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/path_xlsx_finish


${PROTOCGEN_FILE_PATH}/intimacy_xlsx_finish:${RESDB_EXCELMMO_PATH}/intimacy.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/intimacy_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Intimacy.proto ${PROTOCGEN_FILE_PATH}/intimacy_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/intimacy_xlsx_finish


${PROTOCGEN_FILE_PATH}/ai_xlsx_finish:${RESDB_EXCELMMO_PATH}/ai.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ai_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ai.proto ${PROTOCGEN_FILE_PATH}/ai_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ai_xlsx_finish


${PROTOCGEN_FILE_PATH}/boss_xlsx_finish:${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/boss_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Boss.proto ${PROTOCGEN_FILE_PATH}/boss_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/boss_xlsx_finish


${PROTOCGEN_FILE_PATH}/point_xlsx_finish:${RESDB_EXCELMMO_PATH}/point.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/point_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Point.proto ${PROTOCGEN_FILE_PATH}/point_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/point_xlsx_finish


${PROTOCGEN_FILE_PATH}/facade_xlsx_finish:${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/facade_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Facade.proto ${PROTOCGEN_FILE_PATH}/facade_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/facade_xlsx_finish


${PROTOCGEN_FILE_PATH}/dup_xlsx_finish:${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/dup_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Dup.proto ${PROTOCGEN_FILE_PATH}/dup_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/dup_xlsx_finish


${PROTOCGEN_FILE_PATH}/offline_xlsx_finish:${RESDB_EXCELMMO_PATH}/offline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/offline_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Offline.proto ${PROTOCGEN_FILE_PATH}/offline_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/offline_xlsx_finish


${PROTOCGEN_FILE_PATH}/godRelics_xlsx_finish:${RESDB_EXCELMMO_PATH}/godRelics.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/godRelics_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Godrelics.proto ${PROTOCGEN_FILE_PATH}/godRelics_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/godRelics_xlsx_finish


${PROTOCGEN_FILE_PATH}/condition_xlsx_finish:${RESDB_EXCELMMO_PATH}/condition.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/condition_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Condition.proto ${PROTOCGEN_FILE_PATH}/condition_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/condition_xlsx_finish


${PROTOCGEN_FILE_PATH}/audio_xlsx_finish:${RESDB_EXCELMMO_PATH}/audio.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/audio_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Audio.proto ${PROTOCGEN_FILE_PATH}/audio_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/audio_xlsx_finish


${PROTOCGEN_FILE_PATH}/perActivity_xlsx_finish:${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/perActivity_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Peractivity.proto ${PROTOCGEN_FILE_PATH}/perActivity_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/perActivity_xlsx_finish


${PROTOCGEN_FILE_PATH}/daily_xlsx_finish:${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/daily_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Daily.proto ${PROTOCGEN_FILE_PATH}/daily_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/daily_xlsx_finish


${PROTOCGEN_FILE_PATH}/back_xlsx_finish:${RESDB_EXCELMMO_PATH}/back.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/back_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Back.proto ${PROTOCGEN_FILE_PATH}/back_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/back_xlsx_finish


${PROTOCGEN_FILE_PATH}/set_xlsx_finish:${RESDB_EXCELMMO_PATH}/set.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/set_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Set.proto ${PROTOCGEN_FILE_PATH}/set_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/set_xlsx_finish


${PROTOCGEN_FILE_PATH}/team_xlsx_finish:${RESDB_EXCELMMO_PATH}/team.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/team_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Team.proto ${PROTOCGEN_FILE_PATH}/team_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/team_xlsx_finish


${PROTOCGEN_FILE_PATH}/box_xlsx_finish:${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/box_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Box.proto ${PROTOCGEN_FILE_PATH}/box_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/box_xlsx_finish


${PROTOCGEN_FILE_PATH}/task_xlsx_finish:${RESDB_EXCELMMO_PATH}/task.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/task_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Task.proto ${PROTOCGEN_FILE_PATH}/task_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/task_xlsx_finish


${PROTOCGEN_FILE_PATH}/taskdynamic_xlsx_finish:${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/taskdynamic_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Taskdynamic.proto ${PROTOCGEN_FILE_PATH}/taskdynamic_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/taskdynamic_xlsx_finish


${PROTOCGEN_FILE_PATH}/taskreward_xlsx_finish:${RESDB_EXCELMMO_PATH}/taskreward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/taskreward_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Taskreward.proto ${PROTOCGEN_FILE_PATH}/taskreward_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/taskreward_xlsx_finish


${PROTOCGEN_FILE_PATH}/tasktracker_xlsx_finish:${RESDB_EXCELMMO_PATH}/tasktracker.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/tasktracker_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Tasktracker.proto ${PROTOCGEN_FILE_PATH}/tasktracker_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/tasktracker_xlsx_finish


${PROTOCGEN_FILE_PATH}/flash_xlsx_finish:${RESDB_EXCELMMO_PATH}/flash.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/flash_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Flash.proto ${PROTOCGEN_FILE_PATH}/flash_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/flash_xlsx_finish


${PROTOCGEN_FILE_PATH}/button_xlsx_finish:${RESDB_EXCELMMO_PATH}/button.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/button_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Button.proto ${PROTOCGEN_FILE_PATH}/button_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/button_xlsx_finish


${PROTOCGEN_FILE_PATH}/vip_xlsx_finish:${RESDB_EXCELMMO_PATH}/vip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/vip_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Vip.proto ${PROTOCGEN_FILE_PATH}/vip_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/vip_xlsx_finish


${PROTOCGEN_FILE_PATH}/arena_xlsx_finish:${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/arena_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Arena.proto ${PROTOCGEN_FILE_PATH}/arena_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/arena_xlsx_finish


${PROTOCGEN_FILE_PATH}/pet_xlsx_finish:${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/pet_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pet.proto ${PROTOCGEN_FILE_PATH}/pet_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/pet_xlsx_finish


${PROTOCGEN_FILE_PATH}/avatar_xlsx_finish:${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/avatar_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Avatar.proto ${PROTOCGEN_FILE_PATH}/avatar_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/avatar_xlsx_finish


${PROTOCGEN_FILE_PATH}/assist_xlsx_finish:${RESDB_EXCELMMO_PATH}/assist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/assist_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Assist.proto ${PROTOCGEN_FILE_PATH}/assist_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/assist_xlsx_finish


${PROTOCGEN_FILE_PATH}/moneyReward_xlsx_finish:${RESDB_EXCELMMO_PATH}/moneyReward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/moneyReward_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Moneyreward.proto ${PROTOCGEN_FILE_PATH}/moneyReward_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/moneyReward_xlsx_finish


${PROTOCGEN_FILE_PATH}/escort_xlsx_finish:${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/escort_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Escort.proto ${PROTOCGEN_FILE_PATH}/escort_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/escort_xlsx_finish


${PROTOCGEN_FILE_PATH}/guild_xlsx_finish:${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/guild_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Guild.proto ${PROTOCGEN_FILE_PATH}/guild_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/guild_xlsx_finish


${PROTOCGEN_FILE_PATH}/collect_xlsx_finish:${RESDB_EXCELMMO_PATH}/collect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/collect_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Collect.proto ${PROTOCGEN_FILE_PATH}/collect_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/collect_xlsx_finish


${PROTOCGEN_FILE_PATH}/title_xlsx_finish:${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/title_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Title.proto ${PROTOCGEN_FILE_PATH}/title_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/title_xlsx_finish


${PROTOCGEN_FILE_PATH}/godevil_xlsx_finish:${RESDB_EXCELMMO_PATH}/godevil.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/godevil_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Godevil.proto ${PROTOCGEN_FILE_PATH}/godevil_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/godevil_xlsx_finish


${PROTOCGEN_FILE_PATH}/occupation_xlsx_finish:${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/occupation_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Occupation.proto ${PROTOCGEN_FILE_PATH}/occupation_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/occupation_xlsx_finish


${PROTOCGEN_FILE_PATH}/Godvalley_xlsx_finish:${RESDB_EXCELMMO_PATH}/Godvalley.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/Godvalley_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Godvalley.proto ${PROTOCGEN_FILE_PATH}/Godvalley_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/Godvalley_xlsx_finish


${PROTOCGEN_FILE_PATH}/recharge_xlsx_finish:${RESDB_EXCELMMO_PATH}/recharge.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/recharge_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Recharge.proto ${PROTOCGEN_FILE_PATH}/recharge_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/recharge_xlsx_finish


${PROTOCGEN_FILE_PATH}/shenequip_xlsx_finish:${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/shenequip_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Shenequip.proto ${PROTOCGEN_FILE_PATH}/shenequip_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/shenequip_xlsx_finish


${PROTOCGEN_FILE_PATH}/achievement_xlsx_finish:${RESDB_EXCELMMO_PATH}/achievement.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/achievement_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Achievement.proto ${PROTOCGEN_FILE_PATH}/achievement_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/achievement_xlsx_finish


${PROTOCGEN_FILE_PATH}/ancientgod_xlsx_finish:${RESDB_EXCELMMO_PATH}/ancientgod.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ancientgod_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ancientgod.proto ${PROTOCGEN_FILE_PATH}/ancientgod_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ancientgod_xlsx_finish


${PROTOCGEN_FILE_PATH}/xiuzhen_xlsx_finish:${RESDB_EXCELMMO_PATH}/xiuzhen.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xiuzhen_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xiuzhen.proto ${PROTOCGEN_FILE_PATH}/xiuzhen_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xiuzhen_xlsx_finish


${PROTOCGEN_FILE_PATH}/encyclopedia_xlsx_finish:${RESDB_EXCELMMO_PATH}/encyclopedia.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/encyclopedia_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Encyclopedia.proto ${PROTOCGEN_FILE_PATH}/encyclopedia_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/encyclopedia_xlsx_finish


${PROTOCGEN_FILE_PATH}/talent_xlsx_finish:${RESDB_EXCELMMO_PATH}/talent.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/talent_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Talent.proto ${PROTOCGEN_FILE_PATH}/talent_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/talent_xlsx_finish


${PROTOCGEN_FILE_PATH}/marry_xlsx_finish:${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/marry_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Marry.proto ${PROTOCGEN_FILE_PATH}/marry_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/marry_xlsx_finish


${PROTOCGEN_FILE_PATH}/ranking_xlsx_finish:${RESDB_EXCELMMO_PATH}/ranking.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/ranking_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Ranking.proto ${PROTOCGEN_FILE_PATH}/ranking_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/ranking_xlsx_finish


${PROTOCGEN_FILE_PATH}/waremblem_xlsx_finish:${RESDB_EXCELMMO_PATH}/waremblem.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/waremblem_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Waremblem.proto ${PROTOCGEN_FILE_PATH}/waremblem_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/waremblem_xlsx_finish


${PROTOCGEN_FILE_PATH}/pk1v1_xlsx_finish:${RESDB_EXCELMMO_PATH}/pk1v1.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/pk1v1_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk1v1.proto ${PROTOCGEN_FILE_PATH}/pk1v1_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/pk1v1_xlsx_finish


${PROTOCGEN_FILE_PATH}/conflate_xlsx_finish:${RESDB_EXCELMMO_PATH}/conflate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/conflate_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Conflate.proto ${PROTOCGEN_FILE_PATH}/conflate_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/conflate_xlsx_finish


${PROTOCGEN_FILE_PATH}/dragonSoul_xlsx_finish:${RESDB_EXCELMMO_PATH}/dragonSoul.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/dragonSoul_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Dragonsoul.proto ${PROTOCGEN_FILE_PATH}/dragonSoul_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/dragonSoul_xlsx_finish


${PROTOCGEN_FILE_PATH}/personalshop_xlsx_finish:${RESDB_EXCELMMO_PATH}/personalshop.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/personalshop_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Personalshop.proto ${PROTOCGEN_FILE_PATH}/personalshop_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/personalshop_xlsx_finish


${PROTOCGEN_FILE_PATH}/washparty_xlsx_finish:${RESDB_EXCELMMO_PATH}/washparty.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/washparty_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Washparty.proto ${PROTOCGEN_FILE_PATH}/washparty_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/washparty_xlsx_finish


${PROTOCGEN_FILE_PATH}/welfare_xlsx_finish:${RESDB_EXCELMMO_PATH}/welfare.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/welfare_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Welfare.proto ${PROTOCGEN_FILE_PATH}/welfare_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/welfare_xlsx_finish


${PROTOCGEN_FILE_PATH}/qyPeak_xlsx_finish:${RESDB_EXCELMMO_PATH}/qyPeak.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/qyPeak_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Qypeak.proto ${PROTOCGEN_FILE_PATH}/qyPeak_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/qyPeak_xlsx_finish


${PROTOCGEN_FILE_PATH}/pk3v3_xlsx_finish:${RESDB_EXCELMMO_PATH}/pk3v3.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/pk3v3_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Pk3v3.proto ${PROTOCGEN_FILE_PATH}/pk3v3_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/pk3v3_xlsx_finish


${PROTOCGEN_FILE_PATH}/guide_xlsx_finish:${RESDB_EXCELMMO_PATH}/guide.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/guide_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Guide.proto ${PROTOCGEN_FILE_PATH}/guide_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/guide_xlsx_finish


${PROTOCGEN_FILE_PATH}/cloudPeak_xlsx_finish:${RESDB_EXCELMMO_PATH}/cloudPeak.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/cloudPeak_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Cloudpeak.proto ${PROTOCGEN_FILE_PATH}/cloudPeak_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/cloudPeak_xlsx_finish


${PROTOCGEN_FILE_PATH}/xiuzhenroad_xlsx_finish:${RESDB_EXCELMMO_PATH}/xiuzhenroad.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xiuzhenroad_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xiuzhenroad.proto ${PROTOCGEN_FILE_PATH}/xiuzhenroad_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xiuzhenroad_xlsx_finish


${PROTOCGEN_FILE_PATH}/gift_xlsx_finish:${RESDB_EXCELMMO_PATH}/gift.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/gift_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Gift.proto ${PROTOCGEN_FILE_PATH}/gift_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/gift_xlsx_finish


${PROTOCGEN_FILE_PATH}/battlePass_xlsx_finish:${RESDB_EXCELMMO_PATH}/battlePass.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/battlePass_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Battlepass.proto ${PROTOCGEN_FILE_PATH}/battlePass_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/battlePass_xlsx_finish


${PROTOCGEN_FILE_PATH}/findTreasure_xlsx_finish:${RESDB_EXCELMMO_PATH}/findTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/findTreasure_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Findtreasure.proto ${PROTOCGEN_FILE_PATH}/findTreasure_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/findTreasure_xlsx_finish


${PROTOCGEN_FILE_PATH}/festival_xlsx_finish:${RESDB_EXCELMMO_PATH}/festival.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/festival_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Festival.proto ${PROTOCGEN_FILE_PATH}/festival_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/festival_xlsx_finish


${PROTOCGEN_FILE_PATH}/market_xlsx_finish:${RESDB_EXCELMMO_PATH}/market.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/market_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Market.proto ${PROTOCGEN_FILE_PATH}/market_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/market_xlsx_finish


${PROTOCGEN_FILE_PATH}/dragon_xlsx_finish:${RESDB_EXCELMMO_PATH}/dragon.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/dragon_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Dragon.proto ${PROTOCGEN_FILE_PATH}/dragon_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/dragon_xlsx_finish


${PROTOCGEN_FILE_PATH}/yanglong_xlsx_finish:${RESDB_EXCELMMO_PATH}/yanglong.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/yanglong_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Yanglong.proto ${PROTOCGEN_FILE_PATH}/yanglong_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/yanglong_xlsx_finish


${PROTOCGEN_FILE_PATH}/timeline_xlsx_finish:${RESDB_EXCELMMO_PATH}/timeline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/timeline_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Timeline.proto ${PROTOCGEN_FILE_PATH}/timeline_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/timeline_xlsx_finish


${PROTOCGEN_FILE_PATH}/jinglian_xlsx_finish:${RESDB_EXCELMMO_PATH}/jinglian.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/jinglian_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Jinglian.proto ${PROTOCGEN_FILE_PATH}/jinglian_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/jinglian_xlsx_finish


${PROTOCGEN_FILE_PATH}/equipImprove_xlsx_finish:${RESDB_EXCELMMO_PATH}/equipImprove.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/equipImprove_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Equipimprove.proto ${PROTOCGEN_FILE_PATH}/equipImprove_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/equipImprove_xlsx_finish


${PROTOCGEN_FILE_PATH}/teleport_xlsx_finish:${RESDB_EXCELMMO_PATH}/teleport.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/teleport_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Teleport.proto ${PROTOCGEN_FILE_PATH}/teleport_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/teleport_xlsx_finish


${PROTOCGEN_FILE_PATH}/xingchen_xlsx_finish:${RESDB_EXCELMMO_PATH}/xingchen.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xingchen_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xingchen.proto ${PROTOCGEN_FILE_PATH}/xingchen_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xingchen_xlsx_finish


${PROTOCGEN_FILE_PATH}/mofa_xlsx_finish:${RESDB_EXCELMMO_PATH}/mofa.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/mofa_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Mofa.proto ${PROTOCGEN_FILE_PATH}/mofa_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/mofa_xlsx_finish


${PROTOCGEN_FILE_PATH}/shenti_xlsx_finish:${RESDB_EXCELMMO_PATH}/shenti.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/shenti_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Shenti.proto ${PROTOCGEN_FILE_PATH}/shenti_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/shenti_xlsx_finish


${PROTOCGEN_FILE_PATH}/xiuzhenWorld_xlsx_finish:${RESDB_EXCELMMO_PATH}/xiuzhenWorld.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Xiuzhenworld.proto ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/xiuzhenWorld_xlsx_finish


${PROTOCGEN_FILE_PATH}/soul_xlsx_finish:${RESDB_EXCELMMO_PATH}/soul.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/soul_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Soul.proto ${PROTOCGEN_FILE_PATH}/soul_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/soul_xlsx_finish


${PROTOCGEN_FILE_PATH}/nickgod_xlsx_finish:${RESDB_EXCELMMO_PATH}/nickgod.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/nickgod_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Nickgod.proto ${PROTOCGEN_FILE_PATH}/nickgod_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/nickgod_xlsx_finish


${PROTOCGEN_FILE_PATH}/tianxiafirst_xlsx_finish:${RESDB_EXCELMMO_PATH}/tianxiafirst.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/tianxiafirst_xlsx_finish
	${NFEXCELPROCESS} --work="exceltoproto" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_Tianxiafirst.proto ${PROTOCGEN_FILE_PATH}/tianxiafirst_gen.makefile" --dst=${RESDB_META_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/tianxiafirst_xlsx_finish


