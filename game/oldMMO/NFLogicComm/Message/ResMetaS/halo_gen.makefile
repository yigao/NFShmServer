include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_HaloHalo.bin ${PROTOCGEN_FILE_PATH}/HaloHaloDesc.h ${PROTOCGEN_FILE_PATH}/HaloHaloDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_HaloHalo.bin:${PROTOCGEN_FILE_PATH}/halo.proto.ds ${RESDB_EXCELMMO_PATH}/halo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/halo.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/halo.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_HaloHalo  --excel_sheetname=halo  --proto_msgname=E_HaloHalo  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_HaloHalo.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/HaloHaloDesc.h ${PROTOCGEN_FILE_PATH}/HaloHaloDesc.cpp" --dst=${DESC_STORE_PATH}/

