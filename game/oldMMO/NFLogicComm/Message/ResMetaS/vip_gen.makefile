include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_VipVip.bin ${PROTOCGEN_FILE_PATH}/VipVipDesc.h ${PROTOCGEN_FILE_PATH}/VipVipDesc.cpp ${PROTOCGEN_FILE_PATH}/E_VipPrivilege.bin ${PROTOCGEN_FILE_PATH}/VipPrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/VipPrivilegeDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_VipVip.bin:${PROTOCGEN_FILE_PATH}/vip.proto.ds ${RESDB_EXCELMMO_PATH}/vip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/vip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/vip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_VipVip  --excel_sheetname=vip  --proto_msgname=E_VipVip  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_VipVip.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/VipVipDesc.h ${PROTOCGEN_FILE_PATH}/VipVipDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_VipPrivilege.bin:${PROTOCGEN_FILE_PATH}/vip.proto.ds ${RESDB_EXCELMMO_PATH}/vip.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/vip.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/vip.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_VipPrivilege  --excel_sheetname=privilege  --proto_msgname=E_VipPrivilege  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_VipPrivilege.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/VipPrivilegeDesc.h ${PROTOCGEN_FILE_PATH}/VipPrivilegeDesc.cpp" --dst=${DESC_STORE_PATH}/

