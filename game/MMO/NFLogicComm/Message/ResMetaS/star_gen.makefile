include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/starpoint.bin ${PROTOCGEN_FILE_PATH}/StarPointDesc.h ${PROTOCGEN_FILE_PATH}/StarPointDesc.cpp ${PROTOCGEN_FILE_PATH}/starstar.bin ${PROTOCGEN_FILE_PATH}/StarStarDesc.h ${PROTOCGEN_FILE_PATH}/StarStarDesc.cpp ${PROTOCGEN_FILE_PATH}/starexp.bin ${PROTOCGEN_FILE_PATH}/StarExpDesc.h ${PROTOCGEN_FILE_PATH}/StarExpDesc.cpp ${PROTOCGEN_FILE_PATH}/starastrology.bin ${PROTOCGEN_FILE_PATH}/StarAstrologyDesc.h ${PROTOCGEN_FILE_PATH}/StarAstrologyDesc.cpp 

${PROTOCGEN_FILE_PATH}/starpoint.bin:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/star.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starpoint  --excel_sheetname=point  --proto_msgname=starpoint  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/starpoint.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/StarPointDesc.h ${PROTOCGEN_FILE_PATH}/StarPointDesc.cpp:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/StarPointDesc.h ${PROTOCGEN_FILE_PATH}/StarPointDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/starstar.bin:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/star.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starstar  --excel_sheetname=star  --proto_msgname=starstar  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/starstar.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/StarStarDesc.h ${PROTOCGEN_FILE_PATH}/StarStarDesc.cpp:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/StarStarDesc.h ${PROTOCGEN_FILE_PATH}/StarStarDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/starexp.bin:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/star.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starexp  --excel_sheetname=exp  --proto_msgname=starexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/starexp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/StarExpDesc.h ${PROTOCGEN_FILE_PATH}/StarExpDesc.cpp:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/StarExpDesc.h ${PROTOCGEN_FILE_PATH}/StarExpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/starastrology.bin:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/star.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/star.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_starastrology  --excel_sheetname=astrology  --proto_msgname=starastrology  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/starastrology.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/StarAstrologyDesc.h ${PROTOCGEN_FILE_PATH}/StarAstrologyDesc.cpp:${PROTOCGEN_FILE_PATH}/star.proto.ds ${RESDB_EXCELMMO_PATH}/star.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/StarAstrologyDesc.h ${PROTOCGEN_FILE_PATH}/StarAstrologyDesc.cpp" --dst=${DESC_STORE_PATH}/

