include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/offlineoffline.bin ${PROTOCGEN_FILE_PATH}/OfflineOfflineDesc.h ${PROTOCGEN_FILE_PATH}/OfflineOfflineDesc.cpp ${PROTOCGEN_FILE_PATH}/offlineitemlist.bin ${PROTOCGEN_FILE_PATH}/OfflineItemlistDesc.h ${PROTOCGEN_FILE_PATH}/OfflineItemlistDesc.cpp 

${PROTOCGEN_FILE_PATH}/offlineoffline.bin:${PROTOCGEN_FILE_PATH}/offline.proto.ds ${RESDB_EXCELMMO_PATH}/offline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/offline.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_offlineoffline  --excel_sheetname=offline  --proto_msgname=offlineoffline  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/offlineoffline.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OfflineOfflineDesc.h ${PROTOCGEN_FILE_PATH}/OfflineOfflineDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/offlineitemlist.bin:${PROTOCGEN_FILE_PATH}/offline.proto.ds ${RESDB_EXCELMMO_PATH}/offline.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/offline.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/offline.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_offlineitemlist  --excel_sheetname=itemlist  --proto_msgname=offlineitemlist  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/offlineitemlist.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/OfflineItemlistDesc.h ${PROTOCGEN_FILE_PATH}/OfflineItemlistDesc.cpp" --dst=${DESC_STORE_PATH}/

