include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}

${PROTOCGEN_FILE_PATH}/msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile:${RESDB_EXCELMMO_PATH}/msg.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile:${RESDB_EXCELMMO_PATH}/ui.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile:${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile:${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile:${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile:${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile:${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/mount.proto ${PROTOCGEN_FILE_PATH}/mount_gen.makefile:${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mount.proto ${PROTOCGEN_FILE_PATH}/mount_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile:${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile:${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile:${RESDB_EXCELMMO_PATH}/item.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile:${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/attribute.proto ${PROTOCGEN_FILE_PATH}/attribute_gen.makefile:${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attribute.proto ${PROTOCGEN_FILE_PATH}/attribute_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/fashion.proto ${PROTOCGEN_FILE_PATH}/fashion_gen.makefile:${RESDB_EXCELMMO_PATH}/fashion.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fashion.proto ${PROTOCGEN_FILE_PATH}/fashion_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/decorate.proto ${PROTOCGEN_FILE_PATH}/decorate_gen.makefile:${RESDB_EXCELMMO_PATH}/decorate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/decorate.proto ${PROTOCGEN_FILE_PATH}/decorate_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/footprint.proto ${PROTOCGEN_FILE_PATH}/footprint_gen.makefile:${RESDB_EXCELMMO_PATH}/footprint.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/footprint.proto ${PROTOCGEN_FILE_PATH}/footprint_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/halo.proto ${PROTOCGEN_FILE_PATH}/halo_gen.makefile:${RESDB_EXCELMMO_PATH}/halo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/halo.proto ${PROTOCGEN_FILE_PATH}/halo_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/headPortrait.proto ${PROTOCGEN_FILE_PATH}/headPortrait_gen.makefile:${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortrait.proto ${PROTOCGEN_FILE_PATH}/headPortrait_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/meditation.proto ${PROTOCGEN_FILE_PATH}/meditation_gen.makefile:${RESDB_EXCELMMO_PATH}/meditation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/meditation.proto ${PROTOCGEN_FILE_PATH}/meditation_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/functionunlock.proto ${PROTOCGEN_FILE_PATH}/functionunlock_gen.makefile:${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/functionunlock.proto ${PROTOCGEN_FILE_PATH}/functionunlock_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/GMCommand.proto ${PROTOCGEN_FILE_PATH}/GMCommand_gen.makefile:${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMCommand.proto ${PROTOCGEN_FILE_PATH}/GMCommand_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/appearance.proto ${PROTOCGEN_FILE_PATH}/appearance_gen.makefile:${RESDB_EXCELMMO_PATH}/appearance.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/appearance.proto ${PROTOCGEN_FILE_PATH}/appearance_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/link.proto ${PROTOCGEN_FILE_PATH}/link_gen.makefile:${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/link.proto ${PROTOCGEN_FILE_PATH}/link_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/mail.proto ${PROTOCGEN_FILE_PATH}/mail_gen.makefile:${RESDB_EXCELMMO_PATH}/mail.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mail.proto ${PROTOCGEN_FILE_PATH}/mail_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/mall.proto ${PROTOCGEN_FILE_PATH}/mall_gen.makefile:${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mall.proto ${PROTOCGEN_FILE_PATH}/mall_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/chat.proto ${PROTOCGEN_FILE_PATH}/chat_gen.makefile:${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chat.proto ${PROTOCGEN_FILE_PATH}/chat_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/path.proto ${PROTOCGEN_FILE_PATH}/path_gen.makefile:${RESDB_EXCELMMO_PATH}/path.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/path.proto ${PROTOCGEN_FILE_PATH}/path_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/intimacy.proto ${PROTOCGEN_FILE_PATH}/intimacy_gen.makefile:${RESDB_EXCELMMO_PATH}/intimacy.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/intimacy.proto ${PROTOCGEN_FILE_PATH}/intimacy_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/ai.proto ${PROTOCGEN_FILE_PATH}/ai_gen.makefile:${RESDB_EXCELMMO_PATH}/ai.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ai.proto ${PROTOCGEN_FILE_PATH}/ai_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/boss.proto ${PROTOCGEN_FILE_PATH}/boss_gen.makefile:${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/boss.proto ${PROTOCGEN_FILE_PATH}/boss_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/point.proto ${PROTOCGEN_FILE_PATH}/point_gen.makefile:${RESDB_EXCELMMO_PATH}/point.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/point.proto ${PROTOCGEN_FILE_PATH}/point_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/facade.proto ${PROTOCGEN_FILE_PATH}/facade_gen.makefile:${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facade.proto ${PROTOCGEN_FILE_PATH}/facade_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/dup.proto ${PROTOCGEN_FILE_PATH}/dup_gen.makefile:${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dup.proto ${PROTOCGEN_FILE_PATH}/dup_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/offline.proto ${PROTOCGEN_FILE_PATH}/offline_gen.makefile:${RESDB_EXCELMMO_PATH}/offline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/offline.proto ${PROTOCGEN_FILE_PATH}/offline_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/godRelics.proto ${PROTOCGEN_FILE_PATH}/godRelics_gen.makefile:${RESDB_EXCELMMO_PATH}/godRelics.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godRelics.proto ${PROTOCGEN_FILE_PATH}/godRelics_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/condition.proto ${PROTOCGEN_FILE_PATH}/condition_gen.makefile:${RESDB_EXCELMMO_PATH}/condition.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/condition.proto ${PROTOCGEN_FILE_PATH}/condition_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/audio.proto ${PROTOCGEN_FILE_PATH}/audio_gen.makefile:${RESDB_EXCELMMO_PATH}/audio.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/audio.proto ${PROTOCGEN_FILE_PATH}/audio_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/perActivity.proto ${PROTOCGEN_FILE_PATH}/perActivity_gen.makefile:${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/perActivity.proto ${PROTOCGEN_FILE_PATH}/perActivity_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/daily.proto ${PROTOCGEN_FILE_PATH}/daily_gen.makefile:${RESDB_EXCELMMO_PATH}/daily.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/daily.proto ${PROTOCGEN_FILE_PATH}/daily_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/back.proto ${PROTOCGEN_FILE_PATH}/back_gen.makefile:${RESDB_EXCELMMO_PATH}/back.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/back.proto ${PROTOCGEN_FILE_PATH}/back_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/set.proto ${PROTOCGEN_FILE_PATH}/set_gen.makefile:${RESDB_EXCELMMO_PATH}/set.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/set.proto ${PROTOCGEN_FILE_PATH}/set_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/team.proto ${PROTOCGEN_FILE_PATH}/team_gen.makefile:${RESDB_EXCELMMO_PATH}/team.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/team.proto ${PROTOCGEN_FILE_PATH}/team_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/box.proto ${PROTOCGEN_FILE_PATH}/box_gen.makefile:${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/box.proto ${PROTOCGEN_FILE_PATH}/box_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/task.proto ${PROTOCGEN_FILE_PATH}/task_gen.makefile:${RESDB_EXCELMMO_PATH}/task.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/task.proto ${PROTOCGEN_FILE_PATH}/task_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/taskdynamic.proto ${PROTOCGEN_FILE_PATH}/taskdynamic_gen.makefile:${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskdynamic.proto ${PROTOCGEN_FILE_PATH}/taskdynamic_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/taskreward.proto ${PROTOCGEN_FILE_PATH}/taskreward_gen.makefile:${RESDB_EXCELMMO_PATH}/taskreward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskreward.proto ${PROTOCGEN_FILE_PATH}/taskreward_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/tasktracker.proto ${PROTOCGEN_FILE_PATH}/tasktracker_gen.makefile:${RESDB_EXCELMMO_PATH}/tasktracker.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/tasktracker.proto ${PROTOCGEN_FILE_PATH}/tasktracker_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/flash.proto ${PROTOCGEN_FILE_PATH}/flash_gen.makefile:${RESDB_EXCELMMO_PATH}/flash.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/flash.proto ${PROTOCGEN_FILE_PATH}/flash_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/button.proto ${PROTOCGEN_FILE_PATH}/button_gen.makefile:${RESDB_EXCELMMO_PATH}/button.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/button.proto ${PROTOCGEN_FILE_PATH}/button_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/vip.proto ${PROTOCGEN_FILE_PATH}/vip_gen.makefile:${RESDB_EXCELMMO_PATH}/vip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/vip.proto ${PROTOCGEN_FILE_PATH}/vip_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/arena.proto ${PROTOCGEN_FILE_PATH}/arena_gen.makefile:${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arena.proto ${PROTOCGEN_FILE_PATH}/arena_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/pet.proto ${PROTOCGEN_FILE_PATH}/pet_gen.makefile:${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/pet.proto ${PROTOCGEN_FILE_PATH}/pet_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/avatar.proto ${PROTOCGEN_FILE_PATH}/avatar_gen.makefile:${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/avatar.proto ${PROTOCGEN_FILE_PATH}/avatar_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/assist.proto ${PROTOCGEN_FILE_PATH}/assist_gen.makefile:${RESDB_EXCELMMO_PATH}/assist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/assist.proto ${PROTOCGEN_FILE_PATH}/assist_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/moneyReward.proto ${PROTOCGEN_FILE_PATH}/moneyReward_gen.makefile:${RESDB_EXCELMMO_PATH}/moneyReward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/moneyReward.proto ${PROTOCGEN_FILE_PATH}/moneyReward_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/escort.proto ${PROTOCGEN_FILE_PATH}/escort_gen.makefile:${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/escort.proto ${PROTOCGEN_FILE_PATH}/escort_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/guild.proto ${PROTOCGEN_FILE_PATH}/guild_gen.makefile:${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guild.proto ${PROTOCGEN_FILE_PATH}/guild_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/collect.proto ${PROTOCGEN_FILE_PATH}/collect_gen.makefile:${RESDB_EXCELMMO_PATH}/collect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/collect.proto ${PROTOCGEN_FILE_PATH}/collect_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/title.proto ${PROTOCGEN_FILE_PATH}/title_gen.makefile:${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/title.proto ${PROTOCGEN_FILE_PATH}/title_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/godevil.proto ${PROTOCGEN_FILE_PATH}/godevil_gen.makefile:${RESDB_EXCELMMO_PATH}/godevil.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godevil.proto ${PROTOCGEN_FILE_PATH}/godevil_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/occupation.proto ${PROTOCGEN_FILE_PATH}/occupation_gen.makefile:${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/occupation.proto ${PROTOCGEN_FILE_PATH}/occupation_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/Godvalley.proto ${PROTOCGEN_FILE_PATH}/Godvalley_gen.makefile:${RESDB_EXCELMMO_PATH}/Godvalley.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Godvalley.proto ${PROTOCGEN_FILE_PATH}/Godvalley_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/recharge.proto ${PROTOCGEN_FILE_PATH}/recharge_gen.makefile:${RESDB_EXCELMMO_PATH}/recharge.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/recharge.proto ${PROTOCGEN_FILE_PATH}/recharge_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/shenequip.proto ${PROTOCGEN_FILE_PATH}/shenequip_gen.makefile:${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/shenequip.proto ${PROTOCGEN_FILE_PATH}/shenequip_gen.makefile" --dst=${RESDB_META_PATH}/


