include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_findTreasure_bin

${PROTOCGEN_FILE_PATH}/module_findTreasure_bin:${PROTOCGEN_FILE_PATH}/findTreasure.proto.ds ${RESDB_EXCELMMO_PATH}/findTreasure.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_findTreasure_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/findTreasure.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/findTreasure.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FindtreasureDescEx.h ${PROTOCGEN_FILE_PATH}/FindtreasureDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureFindtreasure.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureFindtreasureDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureFindtreasureDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureFindpool.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureFindpoolDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureFindpoolDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureConstantDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureTotal.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureTotalDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureTotalDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureActive.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureActiveDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureActiveDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureActiveup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureActiveupDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureActiveupDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureActivegoods.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureActivegoodsDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureActivegoodsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureActiveshop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureActiveshopDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureActiveshopDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FindtreasureShop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FindtreasureShopDesc.h ${PROTOCGEN_FILE_PATH}/FindtreasureShopDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_findTreasure_bin
