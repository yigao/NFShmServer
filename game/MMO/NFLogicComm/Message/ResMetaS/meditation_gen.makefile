include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_MeditationMeditation.bin ${PROTOCGEN_FILE_PATH}/MeditationMeditationDesc.h ${PROTOCGEN_FILE_PATH}/MeditationMeditationDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_MeditationMeditation.bin:${PROTOCGEN_FILE_PATH}/meditation.proto.ds ${RESDB_EXCELMMO_PATH}/meditation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/meditation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/meditation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_MeditationMeditation  --excel_sheetname=meditation  --proto_msgname=E_MeditationMeditation  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_MeditationMeditation.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MeditationMeditationDesc.h ${PROTOCGEN_FILE_PATH}/MeditationMeditationDesc.cpp" --dst=${DESC_STORE_PATH}/

