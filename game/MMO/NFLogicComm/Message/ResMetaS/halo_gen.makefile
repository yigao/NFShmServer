include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_halo_bin

${PROTOCGEN_FILE_PATH}/module_halo_bin:${PROTOCGEN_FILE_PATH}/halo.proto.ds ${RESDB_EXCELMMO_PATH}/halo.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_halo_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/halo.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/halo.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/HaloDescEx.h ${PROTOCGEN_FILE_PATH}/HaloDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_HaloHalo.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/HaloHaloDesc.h ${PROTOCGEN_FILE_PATH}/HaloHaloDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_halo_bin
