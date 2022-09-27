include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/lightAndShadowcons.bin ${PROTOCGEN_FILE_PATH}/LightandshadowConsDesc.h ${PROTOCGEN_FILE_PATH}/LightandshadowConsDesc.cpp ${PROTOCGEN_FILE_PATH}/lightAndShadowreward.bin ${PROTOCGEN_FILE_PATH}/LightandshadowRewardDesc.h ${PROTOCGEN_FILE_PATH}/LightandshadowRewardDesc.cpp 

${PROTOCGEN_FILE_PATH}/lightAndShadowcons.bin:${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds ${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_lightAndShadowcons  --excel_sheetname=cons  --proto_msgname=lightAndShadowcons  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/lightAndShadowcons.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/LightandshadowConsDesc.h ${PROTOCGEN_FILE_PATH}/LightandshadowConsDesc.cpp:${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds ${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/LightandshadowConsDesc.h ${PROTOCGEN_FILE_PATH}/LightandshadowConsDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/lightAndShadowreward.bin:${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds ${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_lightAndShadowreward  --excel_sheetname=reward  --proto_msgname=lightAndShadowreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/lightAndShadowreward.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/LightandshadowRewardDesc.h ${PROTOCGEN_FILE_PATH}/LightandshadowRewardDesc.cpp:${PROTOCGEN_FILE_PATH}/lightAndShadow.proto.ds ${RESDB_EXCELMMO_PATH}/lightAndShadow.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/LightandshadowRewardDesc.h ${PROTOCGEN_FILE_PATH}/LightandshadowRewardDesc.cpp" --dst=${DESC_STORE_PATH}/

