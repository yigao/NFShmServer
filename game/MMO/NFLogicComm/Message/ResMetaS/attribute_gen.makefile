include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/attributeattribute.bin ${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.h ${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.cpp ${PROTOCGEN_FILE_PATH}/attributesuppress.bin ${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.h ${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.cpp ${PROTOCGEN_FILE_PATH}/attributepowersup.bin ${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.h ${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.cpp 

${PROTOCGEN_FILE_PATH}/attributeattribute.bin:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_attributeattribute  --excel_sheetname=attribute  --proto_msgname=attributeattribute  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attributeattribute.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.h ${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.cpp:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.h ${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/attributesuppress.bin:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_attributesuppress  --excel_sheetname=suppress  --proto_msgname=attributesuppress  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attributesuppress.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.h ${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.cpp:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.h ${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/attributepowersup.bin:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_attributepowersup  --excel_sheetname=powersup  --proto_msgname=attributepowersup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/attributepowersup.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.h ${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.cpp:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.h ${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.cpp" --dst=${DESC_STORE_PATH}/

