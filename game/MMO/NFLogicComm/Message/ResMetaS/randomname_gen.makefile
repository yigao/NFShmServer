include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/randomnamemanfirst.bin ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.cpp ${PROTOCGEN_FILE_PATH}/randomnamemansecond.bin ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.cpp ${PROTOCGEN_FILE_PATH}/randomnamemanthird.bin ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.cpp ${PROTOCGEN_FILE_PATH}/randomnamewomanfirst.bin ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.cpp ${PROTOCGEN_FILE_PATH}/randomnamewomansecond.bin ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.cpp ${PROTOCGEN_FILE_PATH}/randomnamewomanthird.bin ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.cpp 

${PROTOCGEN_FILE_PATH}/randomnamemanfirst.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamemanfirst  --excel_sheetname=manfirst  --proto_msgname=randomnamemanfirst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomnamemanfirst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManfirstDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/randomnamemansecond.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamemansecond  --excel_sheetname=mansecond  --proto_msgname=randomnamemansecond  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomnamemansecond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameMansecondDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/randomnamemanthird.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamemanthird  --excel_sheetname=manthird  --proto_msgname=randomnamemanthird  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomnamemanthird.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameManthirdDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/randomnamewomanfirst.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamewomanfirst  --excel_sheetname=womanfirst  --proto_msgname=randomnamewomanfirst  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomnamewomanfirst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanfirstDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/randomnamewomansecond.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamewomansecond  --excel_sheetname=womansecond  --proto_msgname=randomnamewomansecond  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomnamewomansecond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomansecondDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/randomnamewomanthird.bin:${PROTOCGEN_FILE_PATH}/randomname.proto.ds ${RESDB_EXCELMMO_PATH}/randomname.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/randomname.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/randomname.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_randomnamewomanthird  --excel_sheetname=womanthird  --proto_msgname=randomnamewomanthird  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/randomnamewomanthird.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.h ${PROTOCGEN_FILE_PATH}/RandomnameWomanthirdDesc.cpp" --dst=${DESC_STORE_PATH}/

