include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/taskdynamictaskdynamic.bin ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.cpp ${PROTOCGEN_FILE_PATH}/taskdynamictaskcomcond.bin ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.cpp ${PROTOCGEN_FILE_PATH}/taskdynamictasktext.bin ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.cpp 

${PROTOCGEN_FILE_PATH}/taskdynamictaskdynamic.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskdynamictaskdynamic  --excel_sheetname=taskdynamic  --proto_msgname=taskdynamictaskdynamic  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskdynamictaskdynamic.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/taskdynamictaskcomcond.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskdynamictaskcomcond  --excel_sheetname=taskcomcond  --proto_msgname=taskdynamictaskcomcond  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskdynamictaskcomcond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/taskdynamictasktext.bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_taskdynamictasktext  --excel_sheetname=tasktext  --proto_msgname=taskdynamictasktext  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/taskdynamictasktext.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.cpp" --dst=${DESC_STORE_PATH}/

