include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_RandomnameManfirst.bin ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RandomnameMansecond.bin ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RandomnameManthird.bin ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RandomnameWomanfirst.bin ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RandomnameWomansecond.bin ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RandomnameWomanthird.bin ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_RandomnameManfirst.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RandomnameManfirst  --excel_sheetname=manfirst  --proto_msgname=E_RandomnameManfirst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RandomnameManfirst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RandomnameMansecond.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RandomnameMansecond  --excel_sheetname=mansecond  --proto_msgname=E_RandomnameMansecond  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RandomnameMansecond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RandomnameManthird.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RandomnameManthird  --excel_sheetname=manthird  --proto_msgname=E_RandomnameManthird  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RandomnameManthird.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RandomnameWomanfirst.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RandomnameWomanfirst  --excel_sheetname=womanfirst  --proto_msgname=E_RandomnameWomanfirst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RandomnameWomanfirst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RandomnameWomansecond.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RandomnameWomansecond  --excel_sheetname=womansecond  --proto_msgname=E_RandomnameWomansecond  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RandomnameWomansecond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RandomnameWomanthird.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RandomnameWomanthird  --excel_sheetname=womanthird  --proto_msgname=E_RandomnameWomanthird  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RandomnameWomanthird.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.cpp" --dst=${DESC_STORE_PATH}/

