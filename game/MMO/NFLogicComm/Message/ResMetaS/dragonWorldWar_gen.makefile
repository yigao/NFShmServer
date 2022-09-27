include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/dragonWorldWarconstants.bin ${PROTOCGEN_FILE_PATH}/DragonworldwarConstantsDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarConstantsDesc.cpp ${PROTOCGEN_FILE_PATH}/dragonWorldWargoldskill.bin ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldskillDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldskillDesc.cpp ${PROTOCGEN_FILE_PATH}/dragonWorldWargoldShop.bin ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldshopDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldshopDesc.cpp 

${PROTOCGEN_FILE_PATH}/dragonWorldWarconstants.bin:${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dragonWorldWarconstants  --excel_sheetname=constants  --proto_msgname=dragonWorldWarconstants  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dragonWorldWarconstants.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/DragonworldwarConstantsDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarConstantsDesc.cpp:${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DragonworldwarConstantsDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarConstantsDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/dragonWorldWargoldskill.bin:${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dragonWorldWargoldskill  --excel_sheetname=goldskill  --proto_msgname=dragonWorldWargoldskill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dragonWorldWargoldskill.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/DragonworldwarGoldskillDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldskillDesc.cpp:${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DragonworldwarGoldskillDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldskillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/dragonWorldWargoldShop.bin:${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_dragonWorldWargoldShop  --excel_sheetname=goldShop  --proto_msgname=dragonWorldWargoldShop  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/dragonWorldWargoldShop.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/DragonworldwarGoldshopDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldshopDesc.cpp:${PROTOCGEN_FILE_PATH}/dragonWorldWar.proto.ds ${RESDB_EXCELMMO_PATH}/dragonWorldWar.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/DragonworldwarGoldshopDesc.h ${PROTOCGEN_FILE_PATH}/DragonworldwarGoldshopDesc.cpp" --dst=${DESC_STORE_PATH}/

