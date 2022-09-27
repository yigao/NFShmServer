include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/skillskill.bin ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.cpp ${PROTOCGEN_FILE_PATH}/skillbuff.bin ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.cpp 

${PROTOCGEN_FILE_PATH}/skillskill.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_skillskill  --excel_sheetname=skill  --proto_msgname=skillskill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skillskill.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/SkillSkillDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.cpp:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillSkillDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/skillbuff.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_skillbuff  --excel_sheetname=buff  --proto_msgname=skillbuff  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/skillbuff.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/SkillBuffDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.cpp:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillBuffDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.cpp" --dst=${DESC_STORE_PATH}/

