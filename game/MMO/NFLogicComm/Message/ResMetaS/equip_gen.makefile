include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/equipequip.bin ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstrong.bin ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstrongexp.bin ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstrongtotal.bin ${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.cpp ${PROTOCGEN_FILE_PATH}/equipgem.bin ${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstoveatt.bin ${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.cpp ${PROTOCGEN_FILE_PATH}/equipstoveexp.bin ${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.cpp ${PROTOCGEN_FILE_PATH}/equipgrade.bin ${PROTOCGEN_FILE_PATH}/EquipGradeDesc.h ${PROTOCGEN_FILE_PATH}/EquipGradeDesc.cpp 

${PROTOCGEN_FILE_PATH}/equipequip.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipequip  --excel_sheetname=equip  --proto_msgname=equipequip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipequip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstrong.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrong  --excel_sheetname=strong  --proto_msgname=equipstrong  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstrong.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstrongexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrongexp  --excel_sheetname=strongexp  --proto_msgname=equipstrongexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstrongexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstrongtotal.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstrongtotal  --excel_sheetname=strongtotal  --proto_msgname=equipstrongtotal  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstrongtotal.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipgem.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgem  --excel_sheetname=gem  --proto_msgname=equipgem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipgem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstoveatt.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstoveatt  --excel_sheetname=stoveatt  --proto_msgname=equipstoveatt  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstoveatt.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipstoveexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipstoveexp  --excel_sheetname=stoveexp  --proto_msgname=equipstoveexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipstoveexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/equipgrade.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_equipgrade  --excel_sheetname=grade  --proto_msgname=equipgrade  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/equipgrade.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGradeDesc.h ${PROTOCGEN_FILE_PATH}/EquipGradeDesc.cpp" --dst=${DESC_STORE_PATH}/

