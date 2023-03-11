include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_ShenequipEquip.bin ${PROTOCGEN_FILE_PATH}/ShenequipEquipDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipEquipDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ShenequipAtt.bin ${PROTOCGEN_FILE_PATH}/ShenequipAttDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipAttDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ShenequipLvup.bin ${PROTOCGEN_FILE_PATH}/ShenequipLvupDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipLvupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ShenequipClear.bin ${PROTOCGEN_FILE_PATH}/ShenequipClearDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipClearDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ShenequipAwaken.bin ${PROTOCGEN_FILE_PATH}/ShenequipAwakenDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipAwakenDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ShenequipStarup.bin ${PROTOCGEN_FILE_PATH}/ShenequipStarupDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipStarupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_ShenequipPrepose.bin ${PROTOCGEN_FILE_PATH}/ShenequipPreposeDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipPreposeDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_ShenequipEquip.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipEquip  --excel_sheetname=equip  --proto_msgname=E_ShenequipEquip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipEquip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipEquipDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipEquipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ShenequipAtt.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipAtt  --excel_sheetname=att  --proto_msgname=E_ShenequipAtt  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipAtt.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipAttDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipAttDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ShenequipLvup.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipLvup  --excel_sheetname=lvUp  --proto_msgname=E_ShenequipLvup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipLvup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipLvupDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipLvupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ShenequipClear.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipClear  --excel_sheetname=clear  --proto_msgname=E_ShenequipClear  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipClear.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipClearDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipClearDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ShenequipAwaken.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipAwaken  --excel_sheetname=awaken  --proto_msgname=E_ShenequipAwaken  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipAwaken.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipAwakenDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipAwakenDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ShenequipStarup.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipStarup  --excel_sheetname=starUp  --proto_msgname=E_ShenequipStarup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipStarup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipStarupDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_ShenequipPrepose.bin:${PROTOCGEN_FILE_PATH}/shenequip.proto.ds ${RESDB_EXCELMMO_PATH}/shenequip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/shenequip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/shenequip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_ShenequipPrepose  --excel_sheetname=prepose  --proto_msgname=E_ShenequipPrepose  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_ShenequipPrepose.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ShenequipPreposeDesc.h ${PROTOCGEN_FILE_PATH}/ShenequipPreposeDesc.cpp" --dst=${DESC_STORE_PATH}/

