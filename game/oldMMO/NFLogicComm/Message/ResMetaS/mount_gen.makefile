include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MountFragment.bin ${PROTOCGEN_FILE_PATH}/MountFragmentDesc.h ${PROTOCGEN_FILE_PATH}/MountFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountValue.bin ${PROTOCGEN_FILE_PATH}/MountValueDesc.h ${PROTOCGEN_FILE_PATH}/MountValueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountDisplay.bin ${PROTOCGEN_FILE_PATH}/MountDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MountDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountUnlock.bin ${PROTOCGEN_FILE_PATH}/MountUnlockDesc.h ${PROTOCGEN_FILE_PATH}/MountUnlockDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountChange.bin ${PROTOCGEN_FILE_PATH}/MountChangeDesc.h ${PROTOCGEN_FILE_PATH}/MountChangeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountAdvance.bin ${PROTOCGEN_FILE_PATH}/MountAdvanceDesc.h ${PROTOCGEN_FILE_PATH}/MountAdvanceDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountHuakun.bin ${PROTOCGEN_FILE_PATH}/MountHuakunDesc.h ${PROTOCGEN_FILE_PATH}/MountHuakunDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountHuakun_advancevalue.bin ${PROTOCGEN_FILE_PATH}/MountHuakun_advancevalueDesc.h ${PROTOCGEN_FILE_PATH}/MountHuakun_advancevalueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountBlood.bin ${PROTOCGEN_FILE_PATH}/MountBloodDesc.h ${PROTOCGEN_FILE_PATH}/MountBloodDesc.cpp ${PROTOCGEN_FILE_PATH}/E_MountBaby_egg.bin ${PROTOCGEN_FILE_PATH}/MountBaby_eggDesc.h ${PROTOCGEN_FILE_PATH}/MountBaby_eggDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MountFragment.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountFragment  --excel_sheetname=fragment  --proto_msgname=E_MountFragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountFragment.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountFragmentDesc.h ${PROTOCGEN_FILE_PATH}/MountFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountValue.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountValue  --excel_sheetname=value  --proto_msgname=E_MountValue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountValue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountValueDesc.h ${PROTOCGEN_FILE_PATH}/MountValueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountDisplay.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountDisplay  --excel_sheetname=disPlay  --proto_msgname=E_MountDisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MountDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountUnlock.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountUnlock  --excel_sheetname=Unlock  --proto_msgname=E_MountUnlock  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountUnlock.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountUnlockDesc.h ${PROTOCGEN_FILE_PATH}/MountUnlockDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountChange.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountChange  --excel_sheetname=change  --proto_msgname=E_MountChange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountChange.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountChangeDesc.h ${PROTOCGEN_FILE_PATH}/MountChangeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountAdvance.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountAdvance  --excel_sheetname=advance  --proto_msgname=E_MountAdvance  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountAdvance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountAdvanceDesc.h ${PROTOCGEN_FILE_PATH}/MountAdvanceDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountHuakun.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountHuakun  --excel_sheetname=huaKun  --proto_msgname=E_MountHuakun  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountHuakun.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountHuakunDesc.h ${PROTOCGEN_FILE_PATH}/MountHuakunDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountHuakun_advancevalue.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountHuakun_advancevalue  --excel_sheetname=huaKun_advanceValue  --proto_msgname=E_MountHuakun_advancevalue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountHuakun_advancevalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountHuakun_advancevalueDesc.h ${PROTOCGEN_FILE_PATH}/MountHuakun_advancevalueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountBlood.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountBlood  --excel_sheetname=blood  --proto_msgname=E_MountBlood  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountBlood.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountBloodDesc.h ${PROTOCGEN_FILE_PATH}/MountBloodDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_MountBaby_egg.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MountBaby_egg  --excel_sheetname=baby_egg  --proto_msgname=E_MountBaby_egg  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MountBaby_egg.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountBaby_eggDesc.h ${PROTOCGEN_FILE_PATH}/MountBaby_eggDesc.cpp" --dst=${DESC_STORE_PATH}/

