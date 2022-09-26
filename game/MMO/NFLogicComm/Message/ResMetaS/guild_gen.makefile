include ./define.makefile

.PHONY:all

all:${GAME_DATA_PATH}/guildconstant.bin ${GAME_DATA_PATH}/guildlevel.bin ${GAME_DATA_PATH}/guildcollege.bin ${GAME_DATA_PATH}/guildposition.bin ${GAME_DATA_PATH}/guildhouse.bin ${GAME_DATA_PATH}/guildgift.bin ${GAME_DATA_PATH}/guildguildance.bin ${GAME_DATA_PATH}/guildwarconstant.bin ${GAME_DATA_PATH}/guildwarmorale.bin ${GAME_DATA_PATH}/guildwarrevive.bin 

${GAME_DATA_PATH}/guildconstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildconstant  --excel_sheetname=constant  --proto_msgname=guildconstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildlevel.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildlevel  --excel_sheetname=level  --proto_msgname=guildlevel  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildcollege.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildcollege  --excel_sheetname=college  --proto_msgname=guildcollege  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildposition.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildposition  --excel_sheetname=position  --proto_msgname=guildposition  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildhouse.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildhouse  --excel_sheetname=house  --proto_msgname=guildhouse  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildgift.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildgift  --excel_sheetname=gift  --proto_msgname=guildgift  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildguildance.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildguildance  --excel_sheetname=guildance  --proto_msgname=guildguildance  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildwarconstant.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildwarconstant  --excel_sheetname=warconstant  --proto_msgname=guildwarconstant  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildwarmorale.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildwarmorale  --excel_sheetname=warmorale  --proto_msgname=guildwarmorale  --start_row=4 --out_path=${GAME_DATA_PATH}/

${GAME_DATA_PATH}/guildwarrevive.bin:${RESDB_META_DESCRIPTOR} ${RESDB_EXCELMMO_PATH}/guild.xlsx
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${RESDB_META_DESCRIPTOR} --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildwarrevive  --excel_sheetname=warrevive  --proto_msgname=guildwarrevive  --start_row=4 --out_path=${GAME_DATA_PATH}/

