include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_AvatarFragment.bin ${PROTOCGEN_FILE_PATH}/AvatarFragmentDesc.h ${PROTOCGEN_FILE_PATH}/AvatarFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarValue.bin ${PROTOCGEN_FILE_PATH}/AvatarValueDesc.h ${PROTOCGEN_FILE_PATH}/AvatarValueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarDisplay.bin ${PROTOCGEN_FILE_PATH}/AvatarDisplayDesc.h ${PROTOCGEN_FILE_PATH}/AvatarDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarChange.bin ${PROTOCGEN_FILE_PATH}/AvatarChangeDesc.h ${PROTOCGEN_FILE_PATH}/AvatarChangeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarChangetab.bin ${PROTOCGEN_FILE_PATH}/AvatarChangetabDesc.h ${PROTOCGEN_FILE_PATH}/AvatarChangetabDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarBattleslot.bin ${PROTOCGEN_FILE_PATH}/AvatarBattleslotDesc.h ${PROTOCGEN_FILE_PATH}/AvatarBattleslotDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarAdvance.bin ${PROTOCGEN_FILE_PATH}/AvatarAdvanceDesc.h ${PROTOCGEN_FILE_PATH}/AvatarAdvanceDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarSkill.bin ${PROTOCGEN_FILE_PATH}/AvatarSkillDesc.h ${PROTOCGEN_FILE_PATH}/AvatarSkillDesc.cpp ${PROTOCGEN_FILE_PATH}/E_AvatarEquipsuit.bin ${PROTOCGEN_FILE_PATH}/AvatarEquipsuitDesc.h ${PROTOCGEN_FILE_PATH}/AvatarEquipsuitDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_AvatarFragment.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarFragment  --excel_sheetname=fragment  --proto_msgname=E_AvatarFragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarFragment.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarFragmentDesc.h ${PROTOCGEN_FILE_PATH}/AvatarFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarValue.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarValue  --excel_sheetname=value  --proto_msgname=E_AvatarValue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarValue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarValueDesc.h ${PROTOCGEN_FILE_PATH}/AvatarValueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarDisplay.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarDisplay  --excel_sheetname=disPlay  --proto_msgname=E_AvatarDisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarDisplayDesc.h ${PROTOCGEN_FILE_PATH}/AvatarDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarChange.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarChange  --excel_sheetname=change  --proto_msgname=E_AvatarChange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarChange.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarChangeDesc.h ${PROTOCGEN_FILE_PATH}/AvatarChangeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarChangetab.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarChangetab  --excel_sheetname=changeTab  --proto_msgname=E_AvatarChangetab  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarChangetab.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarChangetabDesc.h ${PROTOCGEN_FILE_PATH}/AvatarChangetabDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarBattleslot.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarBattleslot  --excel_sheetname=battleSlot  --proto_msgname=E_AvatarBattleslot  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarBattleslot.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarBattleslotDesc.h ${PROTOCGEN_FILE_PATH}/AvatarBattleslotDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarAdvance.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarAdvance  --excel_sheetname=advance  --proto_msgname=E_AvatarAdvance  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarAdvance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarAdvanceDesc.h ${PROTOCGEN_FILE_PATH}/AvatarAdvanceDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarSkill.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarSkill  --excel_sheetname=skill  --proto_msgname=E_AvatarSkill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarSkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarSkillDesc.h ${PROTOCGEN_FILE_PATH}/AvatarSkillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_AvatarEquipsuit.bin:${PROTOCGEN_FILE_PATH}/avatar.proto.ds ${RESDB_EXCELMMO_PATH}/avatar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/avatar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/avatar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AvatarEquipsuit  --excel_sheetname=equipSuit  --proto_msgname=E_AvatarEquipsuit  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_AvatarEquipsuit.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AvatarEquipsuitDesc.h ${PROTOCGEN_FILE_PATH}/AvatarEquipsuitDesc.cpp" --dst=${DESC_STORE_PATH}/

