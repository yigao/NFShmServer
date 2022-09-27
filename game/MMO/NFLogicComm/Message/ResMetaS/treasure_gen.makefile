include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/treasuretreasure.bin ${PROTOCGEN_FILE_PATH}/TreasureTreasureDesc.h ${PROTOCGEN_FILE_PATH}/TreasureTreasureDesc.cpp ${PROTOCGEN_FILE_PATH}/treasurechange.bin ${PROTOCGEN_FILE_PATH}/TreasureChangeDesc.h ${PROTOCGEN_FILE_PATH}/TreasureChangeDesc.cpp ${PROTOCGEN_FILE_PATH}/treasurestarUp.bin ${PROTOCGEN_FILE_PATH}/TreasureStarupDesc.h ${PROTOCGEN_FILE_PATH}/TreasureStarupDesc.cpp ${PROTOCGEN_FILE_PATH}/treasurefragment.bin ${PROTOCGEN_FILE_PATH}/TreasureFragmentDesc.h ${PROTOCGEN_FILE_PATH}/TreasureFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/treasureequip.bin ${PROTOCGEN_FILE_PATH}/TreasureEquipDesc.h ${PROTOCGEN_FILE_PATH}/TreasureEquipDesc.cpp ${PROTOCGEN_FILE_PATH}/treasureslot.bin ${PROTOCGEN_FILE_PATH}/TreasureSlotDesc.h ${PROTOCGEN_FILE_PATH}/TreasureSlotDesc.cpp ${PROTOCGEN_FILE_PATH}/treasurerefine.bin ${PROTOCGEN_FILE_PATH}/TreasureRefineDesc.h ${PROTOCGEN_FILE_PATH}/TreasureRefineDesc.cpp 

${PROTOCGEN_FILE_PATH}/treasuretreasure.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasuretreasure  --excel_sheetname=treasure  --proto_msgname=treasuretreasure  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasuretreasure.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureTreasureDesc.h ${PROTOCGEN_FILE_PATH}/TreasureTreasureDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureTreasureDesc.h ${PROTOCGEN_FILE_PATH}/TreasureTreasureDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/treasurechange.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurechange  --excel_sheetname=change  --proto_msgname=treasurechange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasurechange.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureChangeDesc.h ${PROTOCGEN_FILE_PATH}/TreasureChangeDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureChangeDesc.h ${PROTOCGEN_FILE_PATH}/TreasureChangeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/treasurestarUp.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurestarUp  --excel_sheetname=starUp  --proto_msgname=treasurestarUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasurestarUp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureStarupDesc.h ${PROTOCGEN_FILE_PATH}/TreasureStarupDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureStarupDesc.h ${PROTOCGEN_FILE_PATH}/TreasureStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/treasurefragment.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurefragment  --excel_sheetname=fragment  --proto_msgname=treasurefragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasurefragment.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureFragmentDesc.h ${PROTOCGEN_FILE_PATH}/TreasureFragmentDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureFragmentDesc.h ${PROTOCGEN_FILE_PATH}/TreasureFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/treasureequip.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasureequip  --excel_sheetname=equip  --proto_msgname=treasureequip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasureequip.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureEquipDesc.h ${PROTOCGEN_FILE_PATH}/TreasureEquipDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureEquipDesc.h ${PROTOCGEN_FILE_PATH}/TreasureEquipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/treasureslot.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasureslot  --excel_sheetname=slot  --proto_msgname=treasureslot  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasureslot.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureSlotDesc.h ${PROTOCGEN_FILE_PATH}/TreasureSlotDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureSlotDesc.h ${PROTOCGEN_FILE_PATH}/TreasureSlotDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/treasurerefine.bin:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/treasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/treasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_treasurerefine  --excel_sheetname=refine  --proto_msgname=treasurerefine  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/treasurerefine.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/TreasureRefineDesc.h ${PROTOCGEN_FILE_PATH}/TreasureRefineDesc.cpp:${PROTOCGEN_FILE_PATH}/treasure.proto.ds ${RESDB_EXCELMMO_PATH}/treasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TreasureRefineDesc.h ${PROTOCGEN_FILE_PATH}/TreasureRefineDesc.cpp" --dst=${DESC_STORE_PATH}/

