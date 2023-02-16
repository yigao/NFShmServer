include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_PetDisplay.bin ${PROTOCGEN_FILE_PATH}/PetDisplayDesc.h ${PROTOCGEN_FILE_PATH}/PetDisplayDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetAttributetpye.bin ${PROTOCGEN_FILE_PATH}/PetAttributetpyeDesc.h ${PROTOCGEN_FILE_PATH}/PetAttributetpyeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetLvexp.bin ${PROTOCGEN_FILE_PATH}/PetLvexpDesc.h ${PROTOCGEN_FILE_PATH}/PetLvexpDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetAdvancelv.bin ${PROTOCGEN_FILE_PATH}/PetAdvancelvDesc.h ${PROTOCGEN_FILE_PATH}/PetAdvancelvDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetStarup.bin ${PROTOCGEN_FILE_PATH}/PetStarupDesc.h ${PROTOCGEN_FILE_PATH}/PetStarupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetEgg.bin ${PROTOCGEN_FILE_PATH}/PetEggDesc.h ${PROTOCGEN_FILE_PATH}/PetEggDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetDecompose.bin ${PROTOCGEN_FILE_PATH}/PetDecomposeDesc.h ${PROTOCGEN_FILE_PATH}/PetDecomposeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_PetFetters.bin ${PROTOCGEN_FILE_PATH}/PetFettersDesc.h ${PROTOCGEN_FILE_PATH}/PetFettersDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_PetDisplay.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetDisplay  --excel_sheetname=display  --proto_msgname=E_PetDisplay  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetDisplayDesc.h ${PROTOCGEN_FILE_PATH}/PetDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetAttributetpye.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetAttributetpye  --excel_sheetname=attributeTpye  --proto_msgname=E_PetAttributetpye  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetAttributetpye.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetAttributetpyeDesc.h ${PROTOCGEN_FILE_PATH}/PetAttributetpyeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetLvexp.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetLvexp  --excel_sheetname=LvExp  --proto_msgname=E_PetLvexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetLvexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetLvexpDesc.h ${PROTOCGEN_FILE_PATH}/PetLvexpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetAdvancelv.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetAdvancelv  --excel_sheetname=advanceLv  --proto_msgname=E_PetAdvancelv  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetAdvancelv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetAdvancelvDesc.h ${PROTOCGEN_FILE_PATH}/PetAdvancelvDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetStarup.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetStarup  --excel_sheetname=starUp  --proto_msgname=E_PetStarup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetStarup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetStarupDesc.h ${PROTOCGEN_FILE_PATH}/PetStarupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetEgg.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetEgg  --excel_sheetname=egg  --proto_msgname=E_PetEgg  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetEgg.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetEggDesc.h ${PROTOCGEN_FILE_PATH}/PetEggDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetDecompose.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetDecompose  --excel_sheetname=decompose  --proto_msgname=E_PetDecompose  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetDecompose.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetDecomposeDesc.h ${PROTOCGEN_FILE_PATH}/PetDecomposeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_PetFetters.bin:${PROTOCGEN_FILE_PATH}/pet.proto.ds ${RESDB_EXCELMMO_PATH}/pet.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/pet.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/pet.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_PetFetters  --excel_sheetname=fetters  --proto_msgname=E_PetFetters  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_PetFetters.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/PetFettersDesc.h ${PROTOCGEN_FILE_PATH}/PetFettersDesc.cpp" --dst=${DESC_STORE_PATH}/

