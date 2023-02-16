include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_DupBplevel.bin ${PROTOCGEN_FILE_PATH}/DupBplevelDesc.h ${PROTOCGEN_FILE_PATH}/DupBplevelDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DupDup.bin ${PROTOCGEN_FILE_PATH}/DupDupDesc.h ${PROTOCGEN_FILE_PATH}/DupDupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DupTowerreward.bin ${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.h ${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DupGroup.bin ${PROTOCGEN_FILE_PATH}/DupGroupDesc.h ${PROTOCGEN_FILE_PATH}/DupGroupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_DupSweepmonsternum.bin ${PROTOCGEN_FILE_PATH}/DupSweepmonsternumDesc.h ${PROTOCGEN_FILE_PATH}/DupSweepmonsternumDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_DupBplevel.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DupBplevel  --excel_sheetname=BPlevel  --proto_msgname=E_DupBplevel  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DupBplevel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupBplevelDesc.h ${PROTOCGEN_FILE_PATH}/DupBplevelDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DupDup.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DupDup  --excel_sheetname=dup  --proto_msgname=E_DupDup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DupDup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupDupDesc.h ${PROTOCGEN_FILE_PATH}/DupDupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DupTowerreward.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DupTowerreward  --excel_sheetname=towerReward  --proto_msgname=E_DupTowerreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DupTowerreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.h ${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DupGroup.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DupGroup  --excel_sheetname=group  --proto_msgname=E_DupGroup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DupGroup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupGroupDesc.h ${PROTOCGEN_FILE_PATH}/DupGroupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_DupSweepmonsternum.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_DupSweepmonsternum  --excel_sheetname=sweepmonsterNum  --proto_msgname=E_DupSweepmonsternum  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_DupSweepmonsternum.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupSweepmonsternumDesc.h ${PROTOCGEN_FILE_PATH}/DupSweepmonsternumDesc.cpp" --dst=${DESC_STORE_PATH}/

