include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/facadedisplay.bin ${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.h ${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/facadevalue.bin ${PROTOCGEN_FILE_PATH}/FacadeValueDesc.h ${PROTOCGEN_FILE_PATH}/FacadeValueDesc.cpp ${PROTOCGEN_FILE_PATH}/facadetype.bin ${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.cpp ${PROTOCGEN_FILE_PATH}/facadefragment.bin ${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.h ${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.cpp ${PROTOCGEN_FILE_PATH}/facadechange.bin ${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.cpp ${PROTOCGEN_FILE_PATH}/facadestarUp.bin ${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.h ${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.cpp ${PROTOCGEN_FILE_PATH}/facadesoul.bin ${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.cpp ${PROTOCGEN_FILE_PATH}/facadesoulActive.bin ${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.cpp ${PROTOCGEN_FILE_PATH}/facadesoulLv.bin ${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.cpp ${PROTOCGEN_FILE_PATH}/facadesoulAchievement.bin ${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.cpp 

${PROTOCGEN_FILE_PATH}/facadedisplay.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadedisplay  --excel_sheetname=display  --proto_msgname=facadedisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadedisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.h ${PROTOCGEN_FILE_PATH}/FacadeDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadevalue.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadevalue  --excel_sheetname=value  --proto_msgname=facadevalue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadevalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeValueDesc.h ${PROTOCGEN_FILE_PATH}/FacadeValueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadetype.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadetype  --excel_sheetname=type  --proto_msgname=facadetype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadetype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeTypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadefragment.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadefragment  --excel_sheetname=fragment  --proto_msgname=facadefragment  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadefragment.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.h ${PROTOCGEN_FILE_PATH}/FacadeFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadechange.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadechange  --excel_sheetname=change  --proto_msgname=facadechange  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadechange.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.h ${PROTOCGEN_FILE_PATH}/FacadeChangeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadestarUp.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadestarUp  --excel_sheetname=starUp  --proto_msgname=facadestarUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadestarUp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.h ${PROTOCGEN_FILE_PATH}/FacadeStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadesoul.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadesoul  --excel_sheetname=soul  --proto_msgname=facadesoul  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadesoul.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadesoulActive.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadesoulActive  --excel_sheetname=soulActive  --proto_msgname=facadesoulActive  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadesoulActive.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulactiveDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadesoulLv.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadesoulLv  --excel_sheetname=soulLv  --proto_msgname=facadesoulLv  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadesoulLv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoullvDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/facadesoulAchievement.bin:${PROTOCGEN_FILE_PATH}/facade.proto.ds ${RESDB_EXCELMMO_PATH}/facade.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/facade.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/facade.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_facadesoulAchievement  --excel_sheetname=soulAchievement  --proto_msgname=facadesoulAchievement  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/facadesoulAchievement.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.h ${PROTOCGEN_FILE_PATH}/FacadeSoulachievementDesc.cpp" --dst=${DESC_STORE_PATH}/

