include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_market_bin

${PROTOCGEN_FILE_PATH}/module_market_bin:${PROTOCGEN_FILE_PATH}/market.proto.ds ${RESDB_EXCELMMO_PATH}/market.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_market_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/market.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/market.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/MarketDescEx.h ${PROTOCGEN_FILE_PATH}/MarketDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MarketMarket.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MarketMarketDesc.h ${PROTOCGEN_FILE_PATH}/MarketMarketDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MarketBig.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MarketBigDesc.h ${PROTOCGEN_FILE_PATH}/MarketBigDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MarketSmall.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MarketSmallDesc.h ${PROTOCGEN_FILE_PATH}/MarketSmallDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MarketConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MarketConstantDesc.h ${PROTOCGEN_FILE_PATH}/MarketConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_market_bin
