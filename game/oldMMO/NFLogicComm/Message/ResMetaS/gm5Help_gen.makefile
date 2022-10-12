include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/gm5Helpcons.bin ${PROTOCGEN_FILE_PATH}/Gm5helpConsDesc.h ${PROTOCGEN_FILE_PATH}/Gm5helpConsDesc.cpp ${PROTOCGEN_FILE_PATH}/gm5Helpreward.bin ${PROTOCGEN_FILE_PATH}/Gm5helpRewardDesc.h ${PROTOCGEN_FILE_PATH}/Gm5helpRewardDesc.cpp 

${PROTOCGEN_FILE_PATH}/gm5Helpcons.bin:${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds ${RESDB_EXCELMMO_PATH}/gm5Help.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/gm5Help.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_gm5Helpcons  --excel_sheetname=cons  --proto_msgname=gm5Helpcons  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/gm5Helpcons.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Gm5helpConsDesc.h ${PROTOCGEN_FILE_PATH}/Gm5helpConsDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/gm5Helpreward.bin:${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds ${RESDB_EXCELMMO_PATH}/gm5Help.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/gm5Help.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/gm5Help.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_gm5Helpreward  --excel_sheetname=reward  --proto_msgname=gm5Helpreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/gm5Helpreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/Gm5helpRewardDesc.h ${PROTOCGEN_FILE_PATH}/Gm5helpRewardDesc.cpp" --dst=${DESC_STORE_PATH}/

