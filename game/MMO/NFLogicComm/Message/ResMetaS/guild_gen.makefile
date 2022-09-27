include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/guildconstant.bin ${PROTOCGEN_FILE_PATH}/guildlevel.bin ${PROTOCGEN_FILE_PATH}/guildcollege.bin ${PROTOCGEN_FILE_PATH}/guildposition.bin ${PROTOCGEN_FILE_PATH}/guildhouse.bin ${PROTOCGEN_FILE_PATH}/guildgift.bin ${PROTOCGEN_FILE_PATH}/guildguildance.bin ${PROTOCGEN_FILE_PATH}/guildwarconstant.bin ${PROTOCGEN_FILE_PATH}/guildwarmorale.bin ${PROTOCGEN_FILE_PATH}/guildwarrevive.bin 

${PROTOCGEN_FILE_PATH}/guildconstant.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildconstant  --excel_sheetname=constant  --proto_msgname=guildconstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildconstant.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildlevel.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildlevel  --excel_sheetname=level  --proto_msgname=guildlevel  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildlevel.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildcollege.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildcollege  --excel_sheetname=college  --proto_msgname=guildcollege  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildcollege.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildposition.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildposition  --excel_sheetname=position  --proto_msgname=guildposition  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildposition.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildhouse.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildhouse  --excel_sheetname=house  --proto_msgname=guildhouse  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildhouse.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildgift.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildgift  --excel_sheetname=gift  --proto_msgname=guildgift  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildgift.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildguildance.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildguildance  --excel_sheetname=guildance  --proto_msgname=guildguildance  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildguildance.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildwarconstant.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildwarconstant  --excel_sheetname=warconstant  --proto_msgname=guildwarconstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildwarconstant.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildwarmorale.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildwarmorale  --excel_sheetname=warmorale  --proto_msgname=guildwarmorale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildwarmorale.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/guildwarrevive.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_guildwarrevive  --excel_sheetname=warrevive  --proto_msgname=guildwarrevive  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/guildwarrevive.bin" --dst=${GAME_DATA_PATH}/
