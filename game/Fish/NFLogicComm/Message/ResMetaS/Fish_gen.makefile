include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_FishRoom.bin ${PROTOCGEN_FILE_PATH}/FishRoomDesc.h ${PROTOCGEN_FILE_PATH}/FishRoomDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishGunvalue.bin ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.h ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishCtrllevel.bin ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.h ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishConfig.bin ${PROTOCGEN_FILE_PATH}/FishConfigDesc.h ${PROTOCGEN_FILE_PATH}/FishConfigDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_FishRoom.bin:${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FishRoom  --excel_sheetname=Room  --proto_msgname=E_FishRoom  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FishRoom.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FishRoomDesc.h ${PROTOCGEN_FILE_PATH}/FishRoomDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FishGunvalue.bin:${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FishGunvalue  --excel_sheetname=GunValue  --proto_msgname=E_FishGunvalue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FishGunvalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.h ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FishCtrllevel.bin:${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FishCtrllevel  --excel_sheetname=CtrlLevel  --proto_msgname=E_FishCtrllevel  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FishCtrllevel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.h ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_FishConfig.bin:${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_FishConfig  --excel_sheetname=Config  --proto_msgname=E_FishConfig  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_FishConfig.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FishConfigDesc.h ${PROTOCGEN_FILE_PATH}/FishConfigDesc.cpp" --dst=${DESC_STORE_PATH}/

