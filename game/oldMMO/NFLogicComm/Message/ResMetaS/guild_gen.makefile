include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_GuildConstant.bin ${PROTOCGEN_FILE_PATH}/GuildConstantDesc.h ${PROTOCGEN_FILE_PATH}/GuildConstantDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GuildLevel.bin ${PROTOCGEN_FILE_PATH}/GuildLevelDesc.h ${PROTOCGEN_FILE_PATH}/GuildLevelDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GuildPosition.bin ${PROTOCGEN_FILE_PATH}/GuildPositionDesc.h ${PROTOCGEN_FILE_PATH}/GuildPositionDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GuildSalary.bin ${PROTOCGEN_FILE_PATH}/GuildSalaryDesc.h ${PROTOCGEN_FILE_PATH}/GuildSalaryDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GuildDonate.bin ${PROTOCGEN_FILE_PATH}/GuildDonateDesc.h ${PROTOCGEN_FILE_PATH}/GuildDonateDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GuildPacket.bin ${PROTOCGEN_FILE_PATH}/GuildPacketDesc.h ${PROTOCGEN_FILE_PATH}/GuildPacketDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GuildPrestigetask.bin ${PROTOCGEN_FILE_PATH}/GuildPrestigetaskDesc.h ${PROTOCGEN_FILE_PATH}/GuildPrestigetaskDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_GuildConstant.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildConstant  --excel_sheetname=constant  --proto_msgname=E_GuildConstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildConstantDesc.h ${PROTOCGEN_FILE_PATH}/GuildConstantDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GuildLevel.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildLevel  --excel_sheetname=level  --proto_msgname=E_GuildLevel  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildLevel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildLevelDesc.h ${PROTOCGEN_FILE_PATH}/GuildLevelDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GuildPosition.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildPosition  --excel_sheetname=position  --proto_msgname=E_GuildPosition  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildPosition.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildPositionDesc.h ${PROTOCGEN_FILE_PATH}/GuildPositionDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GuildSalary.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildSalary  --excel_sheetname=salary  --proto_msgname=E_GuildSalary  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildSalary.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildSalaryDesc.h ${PROTOCGEN_FILE_PATH}/GuildSalaryDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GuildDonate.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildDonate  --excel_sheetname=donate  --proto_msgname=E_GuildDonate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildDonate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildDonateDesc.h ${PROTOCGEN_FILE_PATH}/GuildDonateDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GuildPacket.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildPacket  --excel_sheetname=packet  --proto_msgname=E_GuildPacket  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildPacket.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildPacketDesc.h ${PROTOCGEN_FILE_PATH}/GuildPacketDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GuildPrestigetask.bin:${PROTOCGEN_FILE_PATH}/guild.proto.ds ${RESDB_EXCELMMO_PATH}/guild.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/guild.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/guild.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GuildPrestigetask  --excel_sheetname=prestigeTask  --proto_msgname=E_GuildPrestigetask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GuildPrestigetask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GuildPrestigetaskDesc.h ${PROTOCGEN_FILE_PATH}/GuildPrestigetaskDesc.cpp" --dst=${DESC_STORE_PATH}/

