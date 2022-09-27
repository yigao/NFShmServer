include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/indultTaskindultTask.bin ${PROTOCGEN_FILE_PATH}/IndulttaskIndulttaskDesc.h ${PROTOCGEN_FILE_PATH}/IndulttaskIndulttaskDesc.cpp ${PROTOCGEN_FILE_PATH}/indultTasktask.bin ${PROTOCGEN_FILE_PATH}/IndulttaskTaskDesc.h ${PROTOCGEN_FILE_PATH}/IndulttaskTaskDesc.cpp 

${PROTOCGEN_FILE_PATH}/indultTaskindultTask.bin:${PROTOCGEN_FILE_PATH}/indultTask.proto.ds ${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/indultTask.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/indultTask.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_indultTaskindultTask  --excel_sheetname=indultTask  --proto_msgname=indultTaskindultTask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/indultTaskindultTask.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/IndulttaskIndulttaskDesc.h ${PROTOCGEN_FILE_PATH}/IndulttaskIndulttaskDesc.cpp:${PROTOCGEN_FILE_PATH}/indultTask.proto.ds ${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/IndulttaskIndulttaskDesc.h ${PROTOCGEN_FILE_PATH}/IndulttaskIndulttaskDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/indultTasktask.bin:${PROTOCGEN_FILE_PATH}/indultTask.proto.ds ${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/indultTask.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/indultTask.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_indultTasktask  --excel_sheetname=task  --proto_msgname=indultTasktask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/indultTasktask.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/IndulttaskTaskDesc.h ${PROTOCGEN_FILE_PATH}/IndulttaskTaskDesc.cpp:${PROTOCGEN_FILE_PATH}/indultTask.proto.ds ${RESDB_EXCELMMO_PATH}/indultTask.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/IndulttaskTaskDesc.h ${PROTOCGEN_FILE_PATH}/IndulttaskTaskDesc.cpp" --dst=${DESC_STORE_PATH}/

