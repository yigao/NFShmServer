include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/godpowergodpower.bin ${PROTOCGEN_FILE_PATH}/GodpowerGodpowerDesc.h ${PROTOCGEN_FILE_PATH}/GodpowerGodpowerDesc.cpp ${PROTOCGEN_FILE_PATH}/godpowerskillupdate.bin ${PROTOCGEN_FILE_PATH}/GodpowerSkillupdateDesc.h ${PROTOCGEN_FILE_PATH}/GodpowerSkillupdateDesc.cpp 

${PROTOCGEN_FILE_PATH}/godpowergodpower.bin:${PROTOCGEN_FILE_PATH}/godpower.proto.ds ${RESDB_EXCELMMO_PATH}/godpower.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godpower.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godpower.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godpowergodpower  --excel_sheetname=godpower  --proto_msgname=godpowergodpower  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godpowergodpower.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodpowerGodpowerDesc.h ${PROTOCGEN_FILE_PATH}/GodpowerGodpowerDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/godpowerskillupdate.bin:${PROTOCGEN_FILE_PATH}/godpower.proto.ds ${RESDB_EXCELMMO_PATH}/godpower.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godpower.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godpower.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_godpowerskillupdate  --excel_sheetname=skillupdate  --proto_msgname=godpowerskillupdate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/godpowerskillupdate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodpowerSkillupdateDesc.h ${PROTOCGEN_FILE_PATH}/GodpowerSkillupdateDesc.cpp" --dst=${DESC_STORE_PATH}/

