include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_teleport_bin

${PROTOCGEN_FILE_PATH}/module_teleport_bin:${PROTOCGEN_FILE_PATH}/teleport.proto.ds ${RESDB_EXCELMMO_PATH}/teleport.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_teleport_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/teleport.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/teleport.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TeleportDescEx.h ${PROTOCGEN_FILE_PATH}/TeleportDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TeleportTeleport.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TeleportTeleportDesc.h ${PROTOCGEN_FILE_PATH}/TeleportTeleportDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_teleport_bin
