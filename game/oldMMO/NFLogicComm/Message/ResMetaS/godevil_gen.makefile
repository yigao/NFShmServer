include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_GodevilPreposetask.bin ${PROTOCGEN_FILE_PATH}/GodevilPreposetaskDesc.h ${PROTOCGEN_FILE_PATH}/GodevilPreposetaskDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GodevilGodevillv.bin ${PROTOCGEN_FILE_PATH}/GodevilGodevillvDesc.h ${PROTOCGEN_FILE_PATH}/GodevilGodevillvDesc.cpp ${PROTOCGEN_FILE_PATH}/E_GodevilGodevilprivilege.bin ${PROTOCGEN_FILE_PATH}/GodevilGodevilprivilegeDesc.h ${PROTOCGEN_FILE_PATH}/GodevilGodevilprivilegeDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_GodevilPreposetask.bin:${PROTOCGEN_FILE_PATH}/godevil.proto.ds ${RESDB_EXCELMMO_PATH}/godevil.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godevil.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godevil.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GodevilPreposetask  --excel_sheetname=preposeTask  --proto_msgname=E_GodevilPreposetask  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GodevilPreposetask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodevilPreposetaskDesc.h ${PROTOCGEN_FILE_PATH}/GodevilPreposetaskDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GodevilGodevillv.bin:${PROTOCGEN_FILE_PATH}/godevil.proto.ds ${RESDB_EXCELMMO_PATH}/godevil.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godevil.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godevil.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GodevilGodevillv  --excel_sheetname=godevilLv  --proto_msgname=E_GodevilGodevillv  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GodevilGodevillv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodevilGodevillvDesc.h ${PROTOCGEN_FILE_PATH}/GodevilGodevillvDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_GodevilGodevilprivilege.bin:${PROTOCGEN_FILE_PATH}/godevil.proto.ds ${RESDB_EXCELMMO_PATH}/godevil.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/godevil.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godevil.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_GodevilGodevilprivilege  --excel_sheetname=godevilPrivilege  --proto_msgname=E_GodevilGodevilprivilege  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_GodevilGodevilprivilege.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/GodevilGodevilprivilegeDesc.h ${PROTOCGEN_FILE_PATH}/GodevilGodevilprivilegeDesc.cpp" --dst=${DESC_STORE_PATH}/

