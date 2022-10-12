include ./define.makefile

.PHONY:all

all:${RESDB_BIN_FILE}

${PROTOCGEN_FILE_PATH}/achievement.proto ${PROTOCGEN_FILE_PATH}/achievement_gen.makefile:${RESDB_EXCELMMO_PATH}/achievement.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/achievement.proto ${PROTOCGEN_FILE_PATH}/achievement_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/activity.proto ${PROTOCGEN_FILE_PATH}/activity_gen.makefile:${RESDB_EXCELMMO_PATH}/activity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/activity.proto ${PROTOCGEN_FILE_PATH}/activity_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/ai.proto ${PROTOCGEN_FILE_PATH}/ai_gen.makefile:${RESDB_EXCELMMO_PATH}/ai.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ai.proto ${PROTOCGEN_FILE_PATH}/ai_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile:${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/area.proto ${PROTOCGEN_FILE_PATH}/area_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/arena.proto ${PROTOCGEN_FILE_PATH}/arena_gen.makefile:${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arena.proto ${PROTOCGEN_FILE_PATH}/arena_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/artifact.proto ${PROTOCGEN_FILE_PATH}/artifact_gen.makefile:${RESDB_EXCELMMO_PATH}/artifact.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/artifact.proto ${PROTOCGEN_FILE_PATH}/artifact_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/attribute.proto ${PROTOCGEN_FILE_PATH}/attribute_gen.makefile:${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attribute.proto ${PROTOCGEN_FILE_PATH}/attribute_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/auction.proto ${PROTOCGEN_FILE_PATH}/auction_gen.makefile:${RESDB_EXCELMMO_PATH}/auction.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/auction.proto ${PROTOCGEN_FILE_PATH}/auction_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/audio.proto ${PROTOCGEN_FILE_PATH}/audio_gen.makefile:${RESDB_EXCELMMO_PATH}/audio.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/audio.proto ${PROTOCGEN_FILE_PATH}/audio_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/back.proto ${PROTOCGEN_FILE_PATH}/back_gen.makefile:${RESDB_EXCELMMO_PATH}/back.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/back.proto ${PROTOCGEN_FILE_PATH}/back_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/box.proto ${PROTOCGEN_FILE_PATH}/box_gen.makefile:${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/box.proto ${PROTOCGEN_FILE_PATH}/box_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/button.proto ${PROTOCGEN_FILE_PATH}/button_gen.makefile:${RESDB_EXCELMMO_PATH}/button.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/button.proto ${PROTOCGEN_FILE_PATH}/button_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/chat.proto ${PROTOCGEN_FILE_PATH}/chat_gen.makefile:${RESDB_EXCELMMO_PATH}/chat.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chat.proto ${PROTOCGEN_FILE_PATH}/chat_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/combine.proto ${PROTOCGEN_FILE_PATH}/combine_gen.makefile:${RESDB_EXCELMMO_PATH}/combine.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/combine.proto ${PROTOCGEN_FILE_PATH}/combine_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile:${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/constant.proto ${PROTOCGEN_FILE_PATH}/constant_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/drop.proto ${PROTOCGEN_FILE_PATH}/drop_gen.makefile:${RESDB_EXCELMMO_PATH}/drop.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/drop.proto ${PROTOCGEN_FILE_PATH}/drop_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/duplicate.proto ${PROTOCGEN_FILE_PATH}/duplicate_gen.makefile:${RESDB_EXCELMMO_PATH}/duplicate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duplicate.proto ${PROTOCGEN_FILE_PATH}/duplicate_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/dynamicexp.proto ${PROTOCGEN_FILE_PATH}/dynamicexp_gen.makefile:${RESDB_EXCELMMO_PATH}/dynamicexp.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dynamicexp.proto ${PROTOCGEN_FILE_PATH}/dynamicexp_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/effect.proto ${PROTOCGEN_FILE_PATH}/effect_gen.makefile:${RESDB_EXCELMMO_PATH}/effect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/effect.proto ${PROTOCGEN_FILE_PATH}/effect_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/element.proto ${PROTOCGEN_FILE_PATH}/element_gen.makefile:${RESDB_EXCELMMO_PATH}/element.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/element.proto ${PROTOCGEN_FILE_PATH}/element_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile:${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equip.proto ${PROTOCGEN_FILE_PATH}/equip_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/escort.proto ${PROTOCGEN_FILE_PATH}/escort_gen.makefile:${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/escort.proto ${PROTOCGEN_FILE_PATH}/escort_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/fashion.proto ${PROTOCGEN_FILE_PATH}/fashion_gen.makefile:${RESDB_EXCELMMO_PATH}/fashion.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fashion.proto ${PROTOCGEN_FILE_PATH}/fashion_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/festival.proto ${PROTOCGEN_FILE_PATH}/festival_gen.makefile:${RESDB_EXCELMMO_PATH}/festival.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/festival.proto ${PROTOCGEN_FILE_PATH}/festival_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/field.proto ${PROTOCGEN_FILE_PATH}/field_gen.makefile:${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/field.proto ${PROTOCGEN_FILE_PATH}/field_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/flash.proto ${PROTOCGEN_FILE_PATH}/flash_gen.makefile:${RESDB_EXCELMMO_PATH}/flash.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/flash.proto ${PROTOCGEN_FILE_PATH}/flash_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/functionunlock.proto ${PROTOCGEN_FILE_PATH}/functionunlock_gen.makefile:${RESDB_EXCELMMO_PATH}/functionunlock.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/functionunlock.proto ${PROTOCGEN_FILE_PATH}/functionunlock_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/getTreasure.proto ${PROTOCGEN_FILE_PATH}/getTreasure_gen.makefile:${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasure.proto ${PROTOCGEN_FILE_PATH}/getTreasure_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/GMCommand.proto ${PROTOCGEN_FILE_PATH}/GMCommand_gen.makefile:${RESDB_EXCELMMO_PATH}/GMCommand.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMCommand.proto ${PROTOCGEN_FILE_PATH}/GMCommand_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/godHood.proto ${PROTOCGEN_FILE_PATH}/godHood_gen.makefile:${RESDB_EXCELMMO_PATH}/godHood.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godHood.proto ${PROTOCGEN_FILE_PATH}/godHood_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/guide.proto ${PROTOCGEN_FILE_PATH}/guide_gen.makefile:${RESDB_EXCELMMO_PATH}/guide.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guide.proto ${PROTOCGEN_FILE_PATH}/guide_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/guild.proto ${PROTOCGEN_FILE_PATH}/guild_gen.makefile:${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guild.proto ${PROTOCGEN_FILE_PATH}/guild_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/handbook.proto ${PROTOCGEN_FILE_PATH}/handbook_gen.makefile:${RESDB_EXCELMMO_PATH}/handbook.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/handbook.proto ${PROTOCGEN_FILE_PATH}/handbook_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/huoyuedu.proto ${PROTOCGEN_FILE_PATH}/huoyuedu_gen.makefile:${RESDB_EXCELMMO_PATH}/huoyuedu.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/huoyuedu.proto ${PROTOCGEN_FILE_PATH}/huoyuedu_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/intimacy.proto ${PROTOCGEN_FILE_PATH}/intimacy_gen.makefile:${RESDB_EXCELMMO_PATH}/intimacy.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/intimacy.proto ${PROTOCGEN_FILE_PATH}/intimacy_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile:${RESDB_EXCELMMO_PATH}/item.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/item.proto ${PROTOCGEN_FILE_PATH}/item_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/link.proto ${PROTOCGEN_FILE_PATH}/link_gen.makefile:${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/link.proto ${PROTOCGEN_FILE_PATH}/link_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/login.proto ${PROTOCGEN_FILE_PATH}/login_gen.makefile:${RESDB_EXCELMMO_PATH}/login.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/login.proto ${PROTOCGEN_FILE_PATH}/login_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/mail.proto ${PROTOCGEN_FILE_PATH}/mail_gen.makefile:${RESDB_EXCELMMO_PATH}/mail.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mail.proto ${PROTOCGEN_FILE_PATH}/mail_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/mall.proto ${PROTOCGEN_FILE_PATH}/mall_gen.makefile:${RESDB_EXCELMMO_PATH}/mall.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mall.proto ${PROTOCGEN_FILE_PATH}/mall_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile:${RESDB_EXCELMMO_PATH}/map.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/map.proto ${PROTOCGEN_FILE_PATH}/map_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/marry.proto ${PROTOCGEN_FILE_PATH}/marry_gen.makefile:${RESDB_EXCELMMO_PATH}/marry.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/marry.proto ${PROTOCGEN_FILE_PATH}/marry_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile:${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/monster.proto ${PROTOCGEN_FILE_PATH}/monster_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/mount.proto ${PROTOCGEN_FILE_PATH}/mount_gen.makefile:${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mount.proto ${PROTOCGEN_FILE_PATH}/mount_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile:${RESDB_EXCELMMO_PATH}/msg.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/msg.proto ${PROTOCGEN_FILE_PATH}/msg_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/must.proto ${PROTOCGEN_FILE_PATH}/must_gen.makefile:${RESDB_EXCELMMO_PATH}/must.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/must.proto ${PROTOCGEN_FILE_PATH}/must_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/occupation.proto ${PROTOCGEN_FILE_PATH}/occupation_gen.makefile:${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/occupation.proto ${PROTOCGEN_FILE_PATH}/occupation_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/offline.proto ${PROTOCGEN_FILE_PATH}/offline_gen.makefile:${RESDB_EXCELMMO_PATH}/offline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/offline.proto ${PROTOCGEN_FILE_PATH}/offline_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/operate.proto ${PROTOCGEN_FILE_PATH}/operate_gen.makefile:${RESDB_EXCELMMO_PATH}/operate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/operate.proto ${PROTOCGEN_FILE_PATH}/operate_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/partner.proto ${PROTOCGEN_FILE_PATH}/partner_gen.makefile:${RESDB_EXCELMMO_PATH}/partner.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/partner.proto ${PROTOCGEN_FILE_PATH}/partner_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile:${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomname.proto ${PROTOCGEN_FILE_PATH}/randomname_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/ranking.proto ${PROTOCGEN_FILE_PATH}/ranking_gen.makefile:${RESDB_EXCELMMO_PATH}/ranking.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ranking.proto ${PROTOCGEN_FILE_PATH}/ranking_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/recharge.proto ${PROTOCGEN_FILE_PATH}/recharge_gen.makefile:${RESDB_EXCELMMO_PATH}/recharge.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/recharge.proto ${PROTOCGEN_FILE_PATH}/recharge_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile:${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/role.proto ${PROTOCGEN_FILE_PATH}/role_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile:${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/sensitiveword.proto ${PROTOCGEN_FILE_PATH}/sensitiveword_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/serverlist.proto ${PROTOCGEN_FILE_PATH}/serverlist_gen.makefile:${RESDB_EXCELMMO_PATH}/serverlist.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serverlist.proto ${PROTOCGEN_FILE_PATH}/serverlist_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile:${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skill.proto ${PROTOCGEN_FILE_PATH}/skill_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/star.proto ${PROTOCGEN_FILE_PATH}/star_gen.makefile:${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/star.proto ${PROTOCGEN_FILE_PATH}/star_gen.makefile" --dst=${RESDB_META_PATH}/


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


${PROTOCGEN_FILE_PATH}/team.proto ${PROTOCGEN_FILE_PATH}/team_gen.makefile:${RESDB_EXCELMMO_PATH}/team.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/team.proto ${PROTOCGEN_FILE_PATH}/team_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/teleport.proto ${PROTOCGEN_FILE_PATH}/teleport_gen.makefile:${RESDB_EXCELMMO_PATH}/teleport.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/teleport.proto ${PROTOCGEN_FILE_PATH}/teleport_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/title.proto ${PROTOCGEN_FILE_PATH}/title_gen.makefile:${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/title.proto ${PROTOCGEN_FILE_PATH}/title_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/treasure.proto ${PROTOCGEN_FILE_PATH}/treasure_gen.makefile:${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasure.proto ${PROTOCGEN_FILE_PATH}/treasure_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile:${RESDB_EXCELMMO_PATH}/ui.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ui.proto ${PROTOCGEN_FILE_PATH}/ui_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/vip.proto ${PROTOCGEN_FILE_PATH}/vip_gen.makefile:${RESDB_EXCELMMO_PATH}/vip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/vip.proto ${PROTOCGEN_FILE_PATH}/vip_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/warland.proto ${PROTOCGEN_FILE_PATH}/warland_gen.makefile:${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/warland.proto ${PROTOCGEN_FILE_PATH}/warland_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/wing.proto ${PROTOCGEN_FILE_PATH}/wing_gen.makefile:${RESDB_EXCELMMO_PATH}/wing.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/wing.proto ${PROTOCGEN_FILE_PATH}/wing_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/serveropenactive.proto ${PROTOCGEN_FILE_PATH}/serveropenactive_gen.makefile:${RESDB_EXCELMMO_PATH}/serveropenactive.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serveropenactive.proto ${PROTOCGEN_FILE_PATH}/serveropenactive_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/witch.proto ${PROTOCGEN_FILE_PATH}/witch_gen.makefile:${RESDB_EXCELMMO_PATH}/witch.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/witch.proto ${PROTOCGEN_FILE_PATH}/witch_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/solo.proto ${PROTOCGEN_FILE_PATH}/solo_gen.makefile:${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/solo.proto ${PROTOCGEN_FILE_PATH}/solo_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/show.proto ${PROTOCGEN_FILE_PATH}/show_gen.makefile:${RESDB_EXCELMMO_PATH}/show.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/show.proto ${PROTOCGEN_FILE_PATH}/show_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/notice.proto ${PROTOCGEN_FILE_PATH}/notice_gen.makefile:${RESDB_EXCELMMO_PATH}/notice.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/notice.proto ${PROTOCGEN_FILE_PATH}/notice_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/conditionshop.proto ${PROTOCGEN_FILE_PATH}/conditionshop_gen.makefile:${RESDB_EXCELMMO_PATH}/conditionshop.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/conditionshop.proto ${PROTOCGEN_FILE_PATH}/conditionshop_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/closetest.proto ${PROTOCGEN_FILE_PATH}/closetest_gen.makefile:${RESDB_EXCELMMO_PATH}/closetest.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/closetest.proto ${PROTOCGEN_FILE_PATH}/closetest_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/worldmapboss.proto ${PROTOCGEN_FILE_PATH}/worldmapboss_gen.makefile:${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/worldmapboss.proto ${PROTOCGEN_FILE_PATH}/worldmapboss_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto ${PROTOCGEN_FILE_PATH}/dragonWorldWar_gen.makefile:${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto ${PROTOCGEN_FILE_PATH}/dragonWorldWar_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/manor.proto ${PROTOCGEN_FILE_PATH}/manor_gen.makefile:${RESDB_EXCELMMO_PATH}/manor.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/manor.proto ${PROTOCGEN_FILE_PATH}/manor_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/condition.proto ${PROTOCGEN_FILE_PATH}/condition_gen.makefile:${RESDB_EXCELMMO_PATH}/condition.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/condition.proto ${PROTOCGEN_FILE_PATH}/condition_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/privilege.proto ${PROTOCGEN_FILE_PATH}/privilege_gen.makefile:${RESDB_EXCELMMO_PATH}/privilege.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/privilege.proto ${PROTOCGEN_FILE_PATH}/privilege_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/godpower.proto ${PROTOCGEN_FILE_PATH}/godpower_gen.makefile:${RESDB_EXCELMMO_PATH}/godpower.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godpower.proto ${PROTOCGEN_FILE_PATH}/godpower_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/headPortrait.proto ${PROTOCGEN_FILE_PATH}/headPortrait_gen.makefile:${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortrait.proto ${PROTOCGEN_FILE_PATH}/headPortrait_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/gm5Help.proto ${PROTOCGEN_FILE_PATH}/gm5Help_gen.makefile:${RESDB_EXCELMMO_PATH}/gm5Help.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/gm5Help.proto ${PROTOCGEN_FILE_PATH}/gm5Help_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/godGM.proto ${PROTOCGEN_FILE_PATH}/godGM_gen.makefile:${RESDB_EXCELMMO_PATH}/godGM.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godGM.proto ${PROTOCGEN_FILE_PATH}/godGM_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/serverHorn.proto ${PROTOCGEN_FILE_PATH}/serverHorn_gen.makefile:${RESDB_EXCELMMO_PATH}/serverHorn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/serverHorn.proto ${PROTOCGEN_FILE_PATH}/serverHorn_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/lightAndShadow.proto ${PROTOCGEN_FILE_PATH}/lightAndShadow_gen.makefile:${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/lightAndShadow.proto ${PROTOCGEN_FILE_PATH}/lightAndShadow_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/rechargeReturn.proto ${PROTOCGEN_FILE_PATH}/rechargeReturn_gen.makefile:${RESDB_EXCELMMO_PATH}/rechargeReturn.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rechargeReturn.proto ${PROTOCGEN_FILE_PATH}/rechargeReturn_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/snowballWar.proto ${PROTOCGEN_FILE_PATH}/snowballWar_gen.makefile:${RESDB_EXCELMMO_PATH}/snowballWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/snowballWar.proto ${PROTOCGEN_FILE_PATH}/snowballWar_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/chooseGift.proto ${PROTOCGEN_FILE_PATH}/chooseGift_gen.makefile:${RESDB_EXCELMMO_PATH}/chooseGift.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/chooseGift.proto ${PROTOCGEN_FILE_PATH}/chooseGift_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/treasureBowl.proto ${PROTOCGEN_FILE_PATH}/treasureBowl_gen.makefile:${RESDB_EXCELMMO_PATH}/treasureBowl.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasureBowl.proto ${PROTOCGEN_FILE_PATH}/treasureBowl_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/welfarelink.proto ${PROTOCGEN_FILE_PATH}/welfarelink_gen.makefile:${RESDB_EXCELMMO_PATH}/welfarelink.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/welfarelink.proto ${PROTOCGEN_FILE_PATH}/welfarelink_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/GMtools.proto ${PROTOCGEN_FILE_PATH}/GMtools_gen.makefile:${RESDB_EXCELMMO_PATH}/GMtools.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GMtools.proto ${PROTOCGEN_FILE_PATH}/GMtools_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/indultTask.proto ${PROTOCGEN_FILE_PATH}/indultTask_gen.makefile:${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/indultTask.proto ${PROTOCGEN_FILE_PATH}/indultTask_gen.makefile" --dst=${RESDB_META_PATH}/


${PROTOCGEN_FILE_PATH}/colPoints.proto ${PROTOCGEN_FILE_PATH}/colPoints_gen.makefile:${RESDB_EXCELMMO_PATH}/colPoints.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2PROTO} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/colPoints.proto ${PROTOCGEN_FILE_PATH}/colPoints_gen.makefile" --dst=${RESDB_META_PATH}/


