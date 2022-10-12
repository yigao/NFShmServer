include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/artifactartifact.bin ${PROTOCGEN_FILE_PATH}/ArtifactArtifactDesc.h ${PROTOCGEN_FILE_PATH}/ArtifactArtifactDesc.cpp 

${PROTOCGEN_FILE_PATH}/artifactartifact.bin:${PROTOCGEN_FILE_PATH}/artifact.proto.ds ${RESDB_EXCELMMO_PATH}/artifact.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/artifact.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/artifact.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_artifactartifact  --excel_sheetname=artifact  --proto_msgname=artifactartifact  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/artifactartifact.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArtifactArtifactDesc.h ${PROTOCGEN_FILE_PATH}/ArtifactArtifactDesc.cpp" --dst=${DESC_STORE_PATH}/

