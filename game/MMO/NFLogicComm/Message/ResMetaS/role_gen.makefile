include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/roleborn.bin ${PROTOCGEN_FILE_PATH}/rolewarrior.bin ${PROTOCGEN_FILE_PATH}/rolemaster.bin ${PROTOCGEN_FILE_PATH}/roleassassin.bin ${PROTOCGEN_FILE_PATH}/roleshooter.bin ${PROTOCGEN_FILE_PATH}/roleexp.bin ${PROTOCGEN_FILE_PATH}/roleskillType.bin ${PROTOCGEN_FILE_PATH}/roleaddSkill.bin ${PROTOCGEN_FILE_PATH}/roleworldexp.bin 

${PROTOCGEN_FILE_PATH}/roleborn.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleborn  --excel_sheetname=born  --proto_msgname=roleborn  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleborn.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/rolewarrior.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rolewarrior  --excel_sheetname=warrior  --proto_msgname=rolewarrior  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rolewarrior.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/rolemaster.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rolemaster  --excel_sheetname=master  --proto_msgname=rolemaster  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rolemaster.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/roleassassin.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleassassin  --excel_sheetname=assassin  --proto_msgname=roleassassin  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleassassin.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/roleshooter.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleshooter  --excel_sheetname=shooter  --proto_msgname=roleshooter  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleshooter.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/roleexp.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleexp  --excel_sheetname=exp  --proto_msgname=roleexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleexp.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/roleskillType.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleskillType  --excel_sheetname=skillType  --proto_msgname=roleskillType  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleskillType.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/roleaddSkill.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleaddSkill  --excel_sheetname=addSkill  --proto_msgname=roleaddSkill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleaddSkill.bin" --dst=${GAME_DATA_PATH}/
${PROTOCGEN_FILE_PATH}/roleworldexp.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleworldexp  --excel_sheetname=worldexp  --proto_msgname=roleworldexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleworldexp.bin" --dst=${GAME_DATA_PATH}/
