include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_personalshop_bin

${PROTOCGEN_FILE_PATH}/module_personalshop_bin:${PROTOCGEN_FILE_PATH}/personalshop.proto.ds ${RESDB_EXCELMMO_PATH}/personalshop.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_personalshop_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/personalshop.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/personalshop.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/PersonalshopDescEx.h ${PROTOCGEN_FILE_PATH}/PersonalshopDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PersonalshopShopitems.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PersonalshopShopitemsDesc.h ${PROTOCGEN_FILE_PATH}/PersonalshopShopitemsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PersonalshopShops.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PersonalshopShopsDesc.h ${PROTOCGEN_FILE_PATH}/PersonalshopShopsDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_personalshop_bin
