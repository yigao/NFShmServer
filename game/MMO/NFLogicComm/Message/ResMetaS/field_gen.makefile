include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/fieldfield.bin ${PROTOCGEN_FILE_PATH}/FieldFieldDesc.h ${PROTOCGEN_FILE_PATH}/FieldFieldDesc.cpp ${PROTOCGEN_FILE_PATH}/fieldreiki.bin ${PROTOCGEN_FILE_PATH}/FieldReikiDesc.h ${PROTOCGEN_FILE_PATH}/FieldReikiDesc.cpp ${PROTOCGEN_FILE_PATH}/fieldexp.bin ${PROTOCGEN_FILE_PATH}/FieldExpDesc.h ${PROTOCGEN_FILE_PATH}/FieldExpDesc.cpp ${PROTOCGEN_FILE_PATH}/fieldvalue.bin ${PROTOCGEN_FILE_PATH}/FieldValueDesc.h ${PROTOCGEN_FILE_PATH}/FieldValueDesc.cpp ${PROTOCGEN_FILE_PATH}/fieldexpand.bin ${PROTOCGEN_FILE_PATH}/FieldExpandDesc.h ${PROTOCGEN_FILE_PATH}/FieldExpandDesc.cpp ${PROTOCGEN_FILE_PATH}/fieldstong.bin ${PROTOCGEN_FILE_PATH}/FieldStongDesc.h ${PROTOCGEN_FILE_PATH}/FieldStongDesc.cpp 

${PROTOCGEN_FILE_PATH}/fieldfield.bin:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldfield  --excel_sheetname=field  --proto_msgname=fieldfield  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fieldfield.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FieldFieldDesc.h ${PROTOCGEN_FILE_PATH}/FieldFieldDesc.cpp:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FieldFieldDesc.h ${PROTOCGEN_FILE_PATH}/FieldFieldDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/fieldreiki.bin:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldreiki  --excel_sheetname=reiki  --proto_msgname=fieldreiki  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fieldreiki.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FieldReikiDesc.h ${PROTOCGEN_FILE_PATH}/FieldReikiDesc.cpp:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FieldReikiDesc.h ${PROTOCGEN_FILE_PATH}/FieldReikiDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/fieldexp.bin:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldexp  --excel_sheetname=exp  --proto_msgname=fieldexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fieldexp.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FieldExpDesc.h ${PROTOCGEN_FILE_PATH}/FieldExpDesc.cpp:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FieldExpDesc.h ${PROTOCGEN_FILE_PATH}/FieldExpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/fieldvalue.bin:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldvalue  --excel_sheetname=value  --proto_msgname=fieldvalue  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fieldvalue.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FieldValueDesc.h ${PROTOCGEN_FILE_PATH}/FieldValueDesc.cpp:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FieldValueDesc.h ${PROTOCGEN_FILE_PATH}/FieldValueDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/fieldexpand.bin:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldexpand  --excel_sheetname=expand  --proto_msgname=fieldexpand  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fieldexpand.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FieldExpandDesc.h ${PROTOCGEN_FILE_PATH}/FieldExpandDesc.cpp:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FieldExpandDesc.h ${PROTOCGEN_FILE_PATH}/FieldExpandDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/fieldstong.bin:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/field.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/field.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_fieldstong  --excel_sheetname=stong  --proto_msgname=fieldstong  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/fieldstong.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/FieldStongDesc.h ${PROTOCGEN_FILE_PATH}/FieldStongDesc.cpp:${PROTOCGEN_FILE_PATH}/field.proto.ds ${RESDB_EXCELMMO_PATH}/field.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/FieldStongDesc.h ${PROTOCGEN_FILE_PATH}/FieldStongDesc.cpp" --dst=${DESC_STORE_PATH}/

