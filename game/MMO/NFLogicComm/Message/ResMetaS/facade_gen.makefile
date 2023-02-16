include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_FacadeDisplay.bin ${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.h ${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeValue.bin ${PROTOCGEN_FILE_PATH}/FacadeValueDesc.h ${PROTOCGEN_FILE_PATH}/FacadeValueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeType.bin ${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeFragment.bin ${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.h ${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeChange.bin ${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeStarup.bin ${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.h ${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeSoul.bin ${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeSoulactive.bin ${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeSoullv.bin ${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FacadeSoulachievement.bin ${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_FacadeDisplay.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeDisplay  --excel_sheetname=display  --proto_msgname=E_FacadeDisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.h ${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeValue.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeValue  --excel_sheetname=value  --proto_msgname=E_FacadeValue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeValue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeValueDesc.h ${PROTOCGEN_FILE_PATH}/FacadeValueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeType.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeType  --excel_sheetname=type  --proto_msgname=E_FacadeType  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeType.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeFragment.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeFragment  --excel_sheetname=fragment  --proto_msgname=E_FacadeFragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeFragment.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.h ${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeChange.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeChange  --excel_sheetname=change  --proto_msgname=E_FacadeChange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeChange.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeStarup.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeStarup  --excel_sheetname=starUp  --proto_msgname=E_FacadeStarup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeStarup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.h ${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeSoul.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeSoul  --excel_sheetname=soul  --proto_msgname=E_FacadeSoul  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeSoul.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeSoulactive.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeSoulactive  --excel_sheetname=soulActive  --proto_msgname=E_FacadeSoulactive  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeSoulactive.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeSoullv.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeSoullv  --excel_sheetname=soulLv  --proto_msgname=E_FacadeSoullv  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeSoullv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FacadeSoulachievement.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FacadeSoulachievement  --excel_sheetname=soulAchievement  --proto_msgname=E_FacadeSoulachievement  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FacadeSoulachievement.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.cpp" --dst=${DESC_STORE_PATH}/

