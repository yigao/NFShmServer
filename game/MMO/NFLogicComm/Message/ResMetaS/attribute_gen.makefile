include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_attribute_bin

${PROTOCGEN_FILE_PATH}/module_attribute_bin:${PROTOCGEN_FILE_PATH}/attribute.proto.ds ${RESDB_EXCELMMO_PATH}/attribute.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_attribute_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/attribute.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/attribute.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AttributeDescEx.h ${PROTOCGEN_FILE_PATH}/AttributeDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AttributeAttribute.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.h ${PROTOCGEN_FILE_PATH}/AttributeAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AttributeSuppress.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.h ${PROTOCGEN_FILE_PATH}/AttributeSuppressDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AttributePowersup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.h ${PROTOCGEN_FILE_PATH}/AttributePowersupDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_attribute_bin
