include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/mountmount.bin ${PROTOCGEN_FILE_PATH}/MountMountDesc.h ${PROTOCGEN_FILE_PATH}/MountMountDesc.cpp ${PROTOCGEN_FILE_PATH}/mountstarUp.bin ${PROTOCGEN_FILE_PATH}/MountStarupDesc.h ${PROTOCGEN_FILE_PATH}/MountStarupDesc.cpp 

${PROTOCGEN_FILE_PATH}/mountmount.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mountmount  --excel_sheetname=mount  --proto_msgname=mountmount  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mountmount.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/MountMountDesc.h ${PROTOCGEN_FILE_PATH}/MountMountDesc.cpp:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountMountDesc.h ${PROTOCGEN_FILE_PATH}/MountMountDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/mountstarUp.bin:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/mount.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/mount.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_mountstarUp  --excel_sheetname=starUp  --proto_msgname=mountstarUp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/mountstarUp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/MountStarupDesc.h ${PROTOCGEN_FILE_PATH}/MountStarupDesc.cpp:${PROTOCGEN_FILE_PATH}/mount.proto.ds ${RESDB_EXCELMMO_PATH}/mount.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/MountStarupDesc.h ${PROTOCGEN_FILE_PATH}/MountStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

