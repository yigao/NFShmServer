include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/occupationoccupation.bin ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.h ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.cpp ${PROTOCGEN_FILE_PATH}/occupationaptitude.bin ${PROTOCGEN_FILE_PATH}/OccupationAptitudeDesc.h ${PROTOCGEN_FILE_PATH}/OccupationAptitudeDesc.cpp ${PROTOCGEN_FILE_PATH}/occupationconditionList.bin ${PROTOCGEN_FILE_PATH}/OccupationConditionlistDesc.h ${PROTOCGEN_FILE_PATH}/OccupationConditionlistDesc.cpp 

${PROTOCGEN_FILE_PATH}/occupationoccupation.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_occupationoccupation  --excel_sheetname=occupation  --proto_msgname=occupationoccupation  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/occupationoccupation.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.h ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/occupationaptitude.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_occupationaptitude  --excel_sheetname=aptitude  --proto_msgname=occupationaptitude  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/occupationaptitude.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationAptitudeDesc.h ${PROTOCGEN_FILE_PATH}/OccupationAptitudeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/occupationconditionList.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_occupationconditionList  --excel_sheetname=conditionList  --proto_msgname=occupationconditionList  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/occupationconditionList.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationConditionlistDesc.h ${PROTOCGEN_FILE_PATH}/OccupationConditionlistDesc.cpp" --dst=${DESC_STORE_PATH}/

