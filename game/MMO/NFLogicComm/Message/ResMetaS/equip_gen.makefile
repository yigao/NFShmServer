include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_EquipEquip.bin ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipAttribute.bin ${PROTOCGEN_FILE_PATH}/EquipAttributeDesc.h ${PROTOCGEN_FILE_PATH}/EquipAttributeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipStrong.bin ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipStrongexp.bin ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipStrongtotal.bin ${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipGem.bin ${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipGemlv.bin ${PROTOCGEN_FILE_PATH}/EquipGemlvDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemlvDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipStoveatt.bin ${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipStoveexp.bin ${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipGrade.bin ${PROTOCGEN_FILE_PATH}/EquipGradeDesc.h ${PROTOCGEN_FILE_PATH}/EquipGradeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipClear.bin ${PROTOCGEN_FILE_PATH}/EquipClearDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipSuit.bin ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.h ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.cpp ${PROTOCGEN_FILE_PATH}/E_EquipBreak.bin ${PROTOCGEN_FILE_PATH}/EquipBreakDesc.h ${PROTOCGEN_FILE_PATH}/EquipBreakDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_EquipEquip.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipEquip  --excel_sheetname=equip  --proto_msgname=E_EquipEquip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipEquip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipEquipDesc.h ${PROTOCGEN_FILE_PATH}/EquipEquipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipAttribute.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipAttribute  --excel_sheetname=attribute  --proto_msgname=E_EquipAttribute  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipAttribute.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipAttributeDesc.h ${PROTOCGEN_FILE_PATH}/EquipAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipStrong.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipStrong  --excel_sheetname=strong  --proto_msgname=E_EquipStrong  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipStrong.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipStrongexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipStrongexp  --excel_sheetname=strongexp  --proto_msgname=E_EquipStrongexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipStrongexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipStrongtotal.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipStrongtotal  --excel_sheetname=strongtotal  --proto_msgname=E_EquipStrongtotal  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipStrongtotal.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.h ${PROTOCGEN_FILE_PATH}/EquipStrongtotalDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipGem.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipGem  --excel_sheetname=gem  --proto_msgname=E_EquipGem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipGem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGemDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipGemlv.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipGemlv  --excel_sheetname=gemLv  --proto_msgname=E_EquipGemlv  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipGemlv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGemlvDesc.h ${PROTOCGEN_FILE_PATH}/EquipGemlvDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipStoveatt.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipStoveatt  --excel_sheetname=stoveatt  --proto_msgname=E_EquipStoveatt  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipStoveatt.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveattDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipStoveexp.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipStoveexp  --excel_sheetname=stoveexp  --proto_msgname=E_EquipStoveexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipStoveexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.h ${PROTOCGEN_FILE_PATH}/EquipStoveexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipGrade.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipGrade  --excel_sheetname=grade  --proto_msgname=E_EquipGrade  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipGrade.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipGradeDesc.h ${PROTOCGEN_FILE_PATH}/EquipGradeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipClear.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipClear  --excel_sheetname=clear  --proto_msgname=E_EquipClear  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipClear.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipClearDesc.h ${PROTOCGEN_FILE_PATH}/EquipClearDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipSuit.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipSuit  --excel_sheetname=suit  --proto_msgname=E_EquipSuit  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipSuit.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipSuitDesc.h ${PROTOCGEN_FILE_PATH}/EquipSuitDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_EquipBreak.bin:${PROTOCGEN_FILE_PATH}/equip.proto.ds ${RESDB_EXCELMMO_PATH}/equip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/equip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/equip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_EquipBreak  --excel_sheetname=break  --proto_msgname=E_EquipBreak  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_EquipBreak.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/EquipBreakDesc.h ${PROTOCGEN_FILE_PATH}/EquipBreakDesc.cpp" --dst=${DESC_STORE_PATH}/

