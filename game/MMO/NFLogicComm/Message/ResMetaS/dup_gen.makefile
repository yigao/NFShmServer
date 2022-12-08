include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/dupBPlevel.bin ${PROTOCGEN_FILE_PATH}/DupBplevelDesc.h ${PROTOCGEN_FILE_PATH}/DupBplevelDesc.cpp ${PROTOCGEN_FILE_PATH}/dupdup.bin ${PROTOCGEN_FILE_PATH}/DupDupDesc.h ${PROTOCGEN_FILE_PATH}/DupDupDesc.cpp ${PROTOCGEN_FILE_PATH}/duptowerReward.bin ${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.h ${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.cpp ${PROTOCGEN_FILE_PATH}/dupgroup.bin ${PROTOCGEN_FILE_PATH}/DupGroupDesc.h ${PROTOCGEN_FILE_PATH}/DupGroupDesc.cpp 

${PROTOCGEN_FILE_PATH}/dupBPlevel.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dupBPlevel  --excel_sheetname=BPlevel  --proto_msgname=dupBPlevel  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dupBPlevel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupBplevelDesc.h ${PROTOCGEN_FILE_PATH}/DupBplevelDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/dupdup.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dupdup  --excel_sheetname=dup  --proto_msgname=dupdup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dupdup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupDupDesc.h ${PROTOCGEN_FILE_PATH}/DupDupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/duptowerReward.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_duptowerReward  --excel_sheetname=towerReward  --proto_msgname=duptowerReward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/duptowerReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.h ${PROTOCGEN_FILE_PATH}/DupTowerrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/dupgroup.bin:${PROTOCGEN_FILE_PATH}/dup.proto.ds ${RESDB_EXCELMMO_PATH}/dup.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dup.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dup.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dupgroup  --excel_sheetname=group  --proto_msgname=dupgroup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dupgroup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DupGroupDesc.h ${PROTOCGEN_FILE_PATH}/DupGroupDesc.cpp" --dst=${DESC_STORE_PATH}/

