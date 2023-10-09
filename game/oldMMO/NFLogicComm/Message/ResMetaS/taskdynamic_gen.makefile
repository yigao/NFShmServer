include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskdynamic.bin ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.cpp ${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskcomcond.bin ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.cpp ${PROTOCGEN_FILE_PATH}/E_TaskdynamicTasktext.bin ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskdynamic.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_TaskdynamicTaskdynamic  --excel_sheetname=taskdynamic  --proto_msgname=E_TaskdynamicTaskdynamic  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskdynamic.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskcomcond.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_TaskdynamicTaskcomcond  --excel_sheetname=taskcomcond  --proto_msgname=E_TaskdynamicTaskcomcond  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskcomcond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_TaskdynamicTasktext.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_TaskdynamicTasktext  --excel_sheetname=tasktext  --proto_msgname=E_TaskdynamicTasktext  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_TaskdynamicTasktext.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.cpp" --dst=${DESC_STORE_PATH}/

