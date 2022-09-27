include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/getTreasurerareItem.bin ${PROTOCGEN_FILE_PATH}/GettreasureRareitemDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureRareitemDesc.cpp ${PROTOCGEN_FILE_PATH}/getTreasuretimesControl.bin ${PROTOCGEN_FILE_PATH}/GettreasureTimescontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureTimescontrolDesc.cpp ${PROTOCGEN_FILE_PATH}/getTreasureArrivalBossReward.bin ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbossrewardDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbossrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/getTreasureArrivalBossControl.bin ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbosscontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbosscontrolDesc.cpp ${PROTOCGEN_FILE_PATH}/getTreasurevipBossControl.bin ${PROTOCGEN_FILE_PATH}/GettreasureVipbosscontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureVipbosscontrolDesc.cpp ${PROTOCGEN_FILE_PATH}/getTreasureboss.bin ${PROTOCGEN_FILE_PATH}/GettreasureBossDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureBossDesc.cpp ${PROTOCGEN_FILE_PATH}/getTreasurehelp.bin ${PROTOCGEN_FILE_PATH}/GettreasureHelpDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureHelpDesc.cpp 

${PROTOCGEN_FILE_PATH}/getTreasurerareItem.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasurerareItem  --excel_sheetname=rareItem  --proto_msgname=getTreasurerareItem  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasurerareItem.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureRareitemDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureRareitemDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureRareitemDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureRareitemDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/getTreasuretimesControl.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasuretimesControl  --excel_sheetname=timesControl  --proto_msgname=getTreasuretimesControl  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasuretimesControl.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureTimescontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureTimescontrolDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureTimescontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureTimescontrolDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/getTreasureArrivalBossReward.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasureArrivalBossReward  --excel_sheetname=ArrivalBossReward  --proto_msgname=getTreasureArrivalBossReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasureArrivalBossReward.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureArrivalbossrewardDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbossrewardDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureArrivalbossrewardDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbossrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/getTreasureArrivalBossControl.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasureArrivalBossControl  --excel_sheetname=ArrivalBossControl  --proto_msgname=getTreasureArrivalBossControl  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasureArrivalBossControl.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureArrivalbosscontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbosscontrolDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureArrivalbosscontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureArrivalbosscontrolDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/getTreasurevipBossControl.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasurevipBossControl  --excel_sheetname=vipBossControl  --proto_msgname=getTreasurevipBossControl  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasurevipBossControl.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureVipbosscontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureVipbosscontrolDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureVipbosscontrolDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureVipbosscontrolDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/getTreasureboss.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasureboss  --excel_sheetname=boss  --proto_msgname=getTreasureboss  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasureboss.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureBossDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureBossDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureBossDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureBossDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/getTreasurehelp.bin:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/getTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_getTreasurehelp  --excel_sheetname=help  --proto_msgname=getTreasurehelp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/getTreasurehelp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/GettreasureHelpDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureHelpDesc.cpp:${PROTOCGEN_FILE_PATH}/getTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/getTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GettreasureHelpDesc.h ${PROTOCGEN_FILE_PATH}/GettreasureHelpDesc.cpp" --dst=${DESC_STORE_PATH}/

