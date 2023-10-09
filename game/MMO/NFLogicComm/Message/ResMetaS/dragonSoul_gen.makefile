include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_dragonSoul_bin

${PROTOCGEN_FILE_PATH}/module_dragonSoul_bin:${PROTOCGEN_FILE_PATH}/dragonSoul.proto.ds ${RESDB_EXCELMMO_PATH}/dragonSoul.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_dragonSoul_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/dragonSoul.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dragonSoul.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/DragonsoulDescEx.h ${PROTOCGEN_FILE_PATH}/DragonsoulDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulHole.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulHoleDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulHoleDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulOfferexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulOfferexpDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulOfferexpDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulStrongexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulStrongexpDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulStrongexpDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulFlyexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulFlyexpDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulFlyexpDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulFlyatt.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulFlyattDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulFlyattDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulFly.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulFlyDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulFlyDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulAwake.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulAwakeDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulAwakeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulName.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulNameDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulNameDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonsoulStarcollect.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonsoulStarcollectDesc.h ${PROTOCGEN_FILE_PATH}/DragonsoulStarcollectDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_dragonSoul_bin
