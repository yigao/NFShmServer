include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/soloduanwei.bin ${PROTOCGEN_FILE_PATH}/SoloDuanweiDesc.h ${PROTOCGEN_FILE_PATH}/SoloDuanweiDesc.cpp ${PROTOCGEN_FILE_PATH}/solorank.bin ${PROTOCGEN_FILE_PATH}/SoloRankDesc.h ${PROTOCGEN_FILE_PATH}/SoloRankDesc.cpp ${PROTOCGEN_FILE_PATH}/solopipei.bin ${PROTOCGEN_FILE_PATH}/SoloPipeiDesc.h ${PROTOCGEN_FILE_PATH}/SoloPipeiDesc.cpp ${PROTOCGEN_FILE_PATH}/soloconstant.bin ${PROTOCGEN_FILE_PATH}/SoloConstantDesc.h ${PROTOCGEN_FILE_PATH}/SoloConstantDesc.cpp 

${PROTOCGEN_FILE_PATH}/soloduanwei.bin:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/solo.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/solo.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_soloduanwei  --excel_sheetname=duanwei  --proto_msgname=soloduanwei  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/soloduanwei.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/SoloDuanweiDesc.h ${PROTOCGEN_FILE_PATH}/SoloDuanweiDesc.cpp:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SoloDuanweiDesc.h ${PROTOCGEN_FILE_PATH}/SoloDuanweiDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/solorank.bin:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/solo.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/solo.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_solorank  --excel_sheetname=rank  --proto_msgname=solorank  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/solorank.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/SoloRankDesc.h ${PROTOCGEN_FILE_PATH}/SoloRankDesc.cpp:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SoloRankDesc.h ${PROTOCGEN_FILE_PATH}/SoloRankDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/solopipei.bin:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/solo.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/solo.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_solopipei  --excel_sheetname=pipei  --proto_msgname=solopipei  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/solopipei.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/SoloPipeiDesc.h ${PROTOCGEN_FILE_PATH}/SoloPipeiDesc.cpp:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SoloPipeiDesc.h ${PROTOCGEN_FILE_PATH}/SoloPipeiDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/soloconstant.bin:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/solo.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/solo.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_soloconstant  --excel_sheetname=constant  --proto_msgname=soloconstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/soloconstant.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/SoloConstantDesc.h ${PROTOCGEN_FILE_PATH}/SoloConstantDesc.cpp:${PROTOCGEN_FILE_PATH}/solo.proto.ds ${RESDB_EXCELMMO_PATH}/solo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SoloConstantDesc.h ${PROTOCGEN_FILE_PATH}/SoloConstantDesc.cpp" --dst=${DESC_STORE_PATH}/

