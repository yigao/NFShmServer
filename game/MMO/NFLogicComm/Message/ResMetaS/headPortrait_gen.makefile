include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_HeadportraitHead.bin ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_HeadportraitHead.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_HeadportraitHead  --excel_sheetname=head  --proto_msgname=E_HeadportraitHead  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_HeadportraitHead.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.cpp" --dst=${DESC_STORE_PATH}/

