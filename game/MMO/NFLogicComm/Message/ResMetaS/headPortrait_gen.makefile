include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/headPortraithead.bin ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.cpp ${PROTOCGEN_FILE_PATH}/headPortraitframe.bin ${PROTOCGEN_FILE_PATH}/HeadportraitFrameDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitFrameDesc.cpp ${PROTOCGEN_FILE_PATH}/headPortraitbubble.bin ${PROTOCGEN_FILE_PATH}/HeadportraitBubbleDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitBubbleDesc.cpp 

${PROTOCGEN_FILE_PATH}/headPortraithead.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraithead  --excel_sheetname=head  --proto_msgname=headPortraithead  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortraithead.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.cpp:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/headPortraitframe.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraitframe  --excel_sheetname=frame  --proto_msgname=headPortraitframe  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortraitframe.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/HeadportraitFrameDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitFrameDesc.cpp:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HeadportraitFrameDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitFrameDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/headPortraitbubble.bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_headPortraitbubble  --excel_sheetname=bubble  --proto_msgname=headPortraitbubble  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/headPortraitbubble.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/HeadportraitBubbleDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitBubbleDesc.cpp:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HeadportraitBubbleDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitBubbleDesc.cpp" --dst=${DESC_STORE_PATH}/

