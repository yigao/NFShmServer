include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/equipequip.bin ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstrong.bin ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp ${PROTOCGEN_FILE_PATH}/equipgemfine.bin ${PROTOCGEN_FILE_PATH}/EquipGemfineDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemfineDesc.cpp ${PROTOCGEN_FILE_PATH}/equipgem.bin ${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp ${PROTOCGEN_FILE_PATH}/equipatt.bin ${PROTOCGEN_FILE_PATH}/EquipAttDesc.h ${PROTOCGEN_FILE_PATH}/EquipAttDesc.cpp ${PROTOCGEN_FILE_PATH}/equipsuit.bin ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.h ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.cpp ${PROTOCGEN_FILE_PATH}/equipclear.bin ${PROTOCGEN_FILE_PATH}/EquipClearDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstrongexp.bin ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp ${PROTOCGEN_FILE_PATH}/equipgemfineexp.bin ${PROTOCGEN_FILE_PATH}/EquipGemfineexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemfineexpDesc.cpp ${PROTOCGEN_FILE_PATH}/equipclearteam.bin ${PROTOCGEN_FILE_PATH}/EquipClearteamDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearteamDesc.cpp ${PROTOCGEN_FILE_PATH}/equipawakening.bin ${PROTOCGEN_FILE_PATH}/EquipAwakeningDesc.h ${PROTOCGEN_FILE_PATH}/EquipAwakeningDesc.cpp ${PROTOCGEN_FILE_PATH}/equipenchanting.bin ${PROTOCGEN_FILE_PATH}/EquipEnchantingDesc.h ${PROTOCGEN_FILE_PATH}/EquipEnchantingDesc.cpp ${PROTOCGEN_FILE_PATH}/equipmarry.bin ${PROTOCGEN_FILE_PATH}/EquipMarryDesc.h ${PROTOCGEN_FILE_PATH}/EquipMarryDesc.cpp 

${PROTOCGEN_FILE_PATH}/equipequip.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipequip  --excel_sheetname=equip  --proto_msgname=equipequip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipequip.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstrong.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrong  --excel_sheetname=strong  --proto_msgname=equipstrong  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstrong.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipgemfine.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgemfine  --excel_sheetname=gemfine  --proto_msgname=equipgemfine  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipgemfine.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipGemfineDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemfineDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGemfineDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemfineDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipgem.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgem  --excel_sheetname=gem  --proto_msgname=equipgem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipgem.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipatt.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipatt  --excel_sheetname=att  --proto_msgname=equipatt  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipatt.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipAttDesc.h ${PROTOCGEN_FILE_PATH}/EquipAttDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipAttDesc.h ${PROTOCGEN_FILE_PATH}/EquipAttDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipsuit.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipsuit  --excel_sheetname=suit  --proto_msgname=equipsuit  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipsuit.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipSuitDesc.h ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipSuitDesc.h ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipclear.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipclear  --excel_sheetname=clear  --proto_msgname=equipclear  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipclear.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipClearDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipClearDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstrongexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrongexp  --excel_sheetname=strongexp  --proto_msgname=equipstrongexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstrongexp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipgemfineexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgemfineexp  --excel_sheetname=gemfineexp  --proto_msgname=equipgemfineexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipgemfineexp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipGemfineexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemfineexpDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGemfineexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemfineexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipclearteam.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipclearteam  --excel_sheetname=clearteam  --proto_msgname=equipclearteam  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipclearteam.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipClearteamDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearteamDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipClearteamDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearteamDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipawakening.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipawakening  --excel_sheetname=awakening  --proto_msgname=equipawakening  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipawakening.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipAwakeningDesc.h ${PROTOCGEN_FILE_PATH}/EquipAwakeningDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipAwakeningDesc.h ${PROTOCGEN_FILE_PATH}/EquipAwakeningDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipenchanting.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipenchanting  --excel_sheetname=enchanting  --proto_msgname=equipenchanting  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipenchanting.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipEnchantingDesc.h ${PROTOCGEN_FILE_PATH}/EquipEnchantingDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipEnchantingDesc.h ${PROTOCGEN_FILE_PATH}/EquipEnchantingDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipmarry.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipmarry  --excel_sheetname=marry  --proto_msgname=equipmarry  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipmarry.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/EquipMarryDesc.h ${PROTOCGEN_FILE_PATH}/EquipMarryDesc.cpp:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipMarryDesc.h ${PROTOCGEN_FILE_PATH}/EquipMarryDesc.cpp" --dst=${DESC_STORE_PATH}/

