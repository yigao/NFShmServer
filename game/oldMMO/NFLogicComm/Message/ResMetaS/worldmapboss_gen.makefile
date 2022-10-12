include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/worldmapbossworldboss.bin ${PROTOCGEN_FILE_PATH}/WorldmapbossWorldbossDesc.h ${PROTOCGEN_FILE_PATH}/WorldmapbossWorldbossDesc.cpp ${PROTOCGEN_FILE_PATH}/worldmapbossdroplist.bin ${PROTOCGEN_FILE_PATH}/WorldmapbossDroplistDesc.h ${PROTOCGEN_FILE_PATH}/WorldmapbossDroplistDesc.cpp ${PROTOCGEN_FILE_PATH}/worldmapbossfestival.bin ${PROTOCGEN_FILE_PATH}/WorldmapbossFestivalDesc.h ${PROTOCGEN_FILE_PATH}/WorldmapbossFestivalDesc.cpp 

${PROTOCGEN_FILE_PATH}/worldmapbossworldboss.bin:${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds ${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_worldmapbossworldboss  --excel_sheetname=worldboss  --proto_msgname=worldmapbossworldboss  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/worldmapbossworldboss.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/WorldmapbossWorldbossDesc.h ${PROTOCGEN_FILE_PATH}/WorldmapbossWorldbossDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/worldmapbossdroplist.bin:${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds ${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_worldmapbossdroplist  --excel_sheetname=droplist  --proto_msgname=worldmapbossdroplist  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/worldmapbossdroplist.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/WorldmapbossDroplistDesc.h ${PROTOCGEN_FILE_PATH}/WorldmapbossDroplistDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/worldmapbossfestival.bin:${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds ${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/worldmapboss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/worldmapboss.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_worldmapbossfestival  --excel_sheetname=festival  --proto_msgname=worldmapbossfestival  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/worldmapbossfestival.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/WorldmapbossFestivalDesc.h ${PROTOCGEN_FILE_PATH}/WorldmapbossFestivalDesc.cpp" --dst=${DESC_STORE_PATH}/

