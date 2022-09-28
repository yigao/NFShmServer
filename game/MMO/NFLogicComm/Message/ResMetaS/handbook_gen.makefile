include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/handbookhandbook.bin ${PROTOCGEN_FILE_PATH}/HandbookHandbookDesc.h ${PROTOCGEN_FILE_PATH}/HandbookHandbookDesc.cpp ${PROTOCGEN_FILE_PATH}/handbookfate.bin ${PROTOCGEN_FILE_PATH}/HandbookFateDesc.h ${PROTOCGEN_FILE_PATH}/HandbookFateDesc.cpp ${PROTOCGEN_FILE_PATH}/handbookattr.bin ${PROTOCGEN_FILE_PATH}/HandbookAttrDesc.h ${PROTOCGEN_FILE_PATH}/HandbookAttrDesc.cpp 

${PROTOCGEN_FILE_PATH}/handbookhandbook.bin:${PROTOCGEN_FILE_PATH}/handbook.proto.ds ${RESDB_EXCELMMO_PATH}/handbook.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/handbook.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/handbook.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_handbookhandbook  --excel_sheetname=handbook  --proto_msgname=handbookhandbook  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/handbookhandbook.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HandbookHandbookDesc.h ${PROTOCGEN_FILE_PATH}/HandbookHandbookDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/handbookfate.bin:${PROTOCGEN_FILE_PATH}/handbook.proto.ds ${RESDB_EXCELMMO_PATH}/handbook.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/handbook.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/handbook.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_handbookfate  --excel_sheetname=fate  --proto_msgname=handbookfate  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/handbookfate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HandbookFateDesc.h ${PROTOCGEN_FILE_PATH}/HandbookFateDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/handbookattr.bin:${PROTOCGEN_FILE_PATH}/handbook.proto.ds ${RESDB_EXCELMMO_PATH}/handbook.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/handbook.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/handbook.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_handbookattr  --excel_sheetname=attr  --proto_msgname=handbookattr  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/handbookattr.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HandbookAttrDesc.h ${PROTOCGEN_FILE_PATH}/HandbookAttrDesc.cpp" --dst=${DESC_STORE_PATH}/

