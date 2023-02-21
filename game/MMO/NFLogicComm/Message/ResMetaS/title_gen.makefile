include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_TitleType.bin ${PROTOCGEN_FILE_PATH}/TitleTypeDesc.h ${PROTOCGEN_FILE_PATH}/TitleTypeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_TitleTitle.bin ${PROTOCGEN_FILE_PATH}/TitleTitleDesc.h ${PROTOCGEN_FILE_PATH}/TitleTitleDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_TitleType.bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_TitleType  --excel_sheetname=type  --proto_msgname=E_TitleType  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_TitleType.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TitleTypeDesc.h ${PROTOCGEN_FILE_PATH}/TitleTypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_TitleTitle.bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_TitleTitle  --excel_sheetname=title  --proto_msgname=E_TitleTitle  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_TitleTitle.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/TitleTitleDesc.h ${PROTOCGEN_FILE_PATH}/TitleTitleDesc.cpp" --dst=${DESC_STORE_PATH}/

