include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/privilegeprivilege.bin ${PROTOCGEN_FILE_PATH}/PrivilegePrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/PrivilegePrivilegeDesc.cpp 

${PROTOCGEN_FILE_PATH}/privilegeprivilege.bin:${PROTOCGEN_FILE_PATH}/privilege.proto.ds ${RESDB_EXCELMMO_PATH}/privilege.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/privilege.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/privilege.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_privilegeprivilege  --excel_sheetname=privilege  --proto_msgname=privilegeprivilege  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/privilegeprivilege.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/PrivilegePrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/PrivilegePrivilegeDesc.cpp:${PROTOCGEN_FILE_PATH}/privilege.proto.ds ${RESDB_EXCELMMO_PATH}/privilege.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PrivilegePrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/PrivilegePrivilegeDesc.cpp" --dst=${DESC_STORE_PATH}/

