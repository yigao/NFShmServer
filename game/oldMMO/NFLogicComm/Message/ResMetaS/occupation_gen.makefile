include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_OccupationOccupation.bin ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.h ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.cpp ${PROTOCGEN_FILE_PATH}/E_OccupationStage.bin ${PROTOCGEN_FILE_PATH}/OccupationStageDesc.h ${PROTOCGEN_FILE_PATH}/OccupationStageDesc.cpp ${PROTOCGEN_FILE_PATH}/E_OccupationAttribute.bin ${PROTOCGEN_FILE_PATH}/OccupationAttributeDesc.h ${PROTOCGEN_FILE_PATH}/OccupationAttributeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_OccupationSoul.bin ${PROTOCGEN_FILE_PATH}/OccupationSoulDesc.h ${PROTOCGEN_FILE_PATH}/OccupationSoulDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_OccupationOccupation.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_OccupationOccupation  --excel_sheetname=occupation  --proto_msgname=E_OccupationOccupation  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_OccupationOccupation.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.h ${PROTOCGEN_FILE_PATH}/OccupationOccupationDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_OccupationStage.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_OccupationStage  --excel_sheetname=stage  --proto_msgname=E_OccupationStage  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_OccupationStage.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationStageDesc.h ${PROTOCGEN_FILE_PATH}/OccupationStageDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_OccupationAttribute.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_OccupationAttribute  --excel_sheetname=attribute  --proto_msgname=E_OccupationAttribute  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_OccupationAttribute.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationAttributeDesc.h ${PROTOCGEN_FILE_PATH}/OccupationAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_OccupationSoul.bin:${PROTOCGEN_FILE_PATH}/occupation.proto.ds ${RESDB_EXCELMMO_PATH}/occupation.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/occupation.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/occupation.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_OccupationSoul  --excel_sheetname=soul  --proto_msgname=E_OccupationSoul  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_OccupationSoul.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OccupationSoulDesc.h ${PROTOCGEN_FILE_PATH}/OccupationSoulDesc.cpp" --dst=${DESC_STORE_PATH}/

