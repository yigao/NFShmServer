include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/warlandconstant.bin ${PROTOCGEN_FILE_PATH}/WarlandConstantDesc.h ${PROTOCGEN_FILE_PATH}/WarlandConstantDesc.cpp ${PROTOCGEN_FILE_PATH}/warlandmultiKill.bin ${PROTOCGEN_FILE_PATH}/WarlandMultikillDesc.h ${PROTOCGEN_FILE_PATH}/WarlandMultikillDesc.cpp ${PROTOCGEN_FILE_PATH}/warlandrankreward.bin ${PROTOCGEN_FILE_PATH}/WarlandRankrewardDesc.h ${PROTOCGEN_FILE_PATH}/WarlandRankrewardDesc.cpp 

${PROTOCGEN_FILE_PATH}/warlandconstant.bin:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/warland.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_warlandconstant  --excel_sheetname=constant  --proto_msgname=warlandconstant  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/warlandconstant.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/WarlandConstantDesc.h ${PROTOCGEN_FILE_PATH}/WarlandConstantDesc.cpp:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/WarlandConstantDesc.h ${PROTOCGEN_FILE_PATH}/WarlandConstantDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/warlandmultiKill.bin:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/warland.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_warlandmultiKill  --excel_sheetname=multiKill  --proto_msgname=warlandmultiKill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/warlandmultiKill.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/WarlandMultikillDesc.h ${PROTOCGEN_FILE_PATH}/WarlandMultikillDesc.cpp:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/WarlandMultikillDesc.h ${PROTOCGEN_FILE_PATH}/WarlandMultikillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/warlandrankreward.bin:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/warland.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/warland.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_warlandrankreward  --excel_sheetname=rankreward  --proto_msgname=warlandrankreward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/warlandrankreward.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/WarlandRankrewardDesc.h ${PROTOCGEN_FILE_PATH}/WarlandRankrewardDesc.cpp:${PROTOCGEN_FILE_PATH}/warland.proto.ds ${RESDB_EXCELMMO_PATH}/warland.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/WarlandRankrewardDesc.h ${PROTOCGEN_FILE_PATH}/WarlandRankrewardDesc.cpp" --dst=${DESC_STORE_PATH}/

