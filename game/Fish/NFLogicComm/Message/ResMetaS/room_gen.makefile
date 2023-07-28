include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_RoomRoom.bin ${PROTOCGEN_FILE_PATH}/RoomRoomDesc.h ${PROTOCGEN_FILE_PATH}/RoomRoomDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_RoomRoom.bin:${PROTOCGEN_FILE_PATH}/room.proto.ds ${RESDB_EXCELMMO_PATH}/room.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/room.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/room.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoomRoom  --excel_sheetname=room  --proto_msgname=E_RoomRoom  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoomRoom.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoomRoomDesc.h ${PROTOCGEN_FILE_PATH}/RoomRoomDesc.cpp" --dst=${DESC_STORE_PATH}/

