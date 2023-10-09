include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_SkillBuff.bin ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.cpp ${PROTOCGEN_FILE_PATH}/E_SkillSkill.bin ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.cpp ${PROTOCGEN_FILE_PATH}/E_SkillBuffup.bin ${PROTOCGEN_FILE_PATH}/SkillBuffupDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_SkillSkillup.bin ${PROTOCGEN_FILE_PATH}/SkillSkillupDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillupDesc.cpp ${PROTOCGEN_FILE_PATH}/E_SkillSkillawake.bin ${PROTOCGEN_FILE_PATH}/SkillSkillawakeDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillawakeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_SkillSkilladvance.bin ${PROTOCGEN_FILE_PATH}/SkillSkilladvanceDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkilladvanceDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_SkillBuff.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SkillBuff  --excel_sheetname=buff  --proto_msgname=E_SkillBuff  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SkillBuff.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillBuffDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_SkillSkill.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SkillSkill  --excel_sheetname=skill  --proto_msgname=E_SkillSkill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SkillSkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillSkillDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_SkillBuffup.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SkillBuffup  --excel_sheetname=buffUp  --proto_msgname=E_SkillBuffup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SkillBuffup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillBuffupDesc.h ${PROTOCGEN_FILE_PATH}/SkillBuffupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_SkillSkillup.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SkillSkillup  --excel_sheetname=skillUp  --proto_msgname=E_SkillSkillup  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SkillSkillup.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillSkillupDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillupDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_SkillSkillawake.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SkillSkillawake  --excel_sheetname=skillAwake  --proto_msgname=E_SkillSkillawake  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SkillSkillawake.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillSkillawakeDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkillawakeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_SkillSkilladvance.bin:${PROTOCGEN_FILE_PATH}/skill.proto.ds ${RESDB_EXCELMMO_PATH}/skill.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/skill.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/skill.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_SkillSkilladvance  --excel_sheetname=skillAdvance  --proto_msgname=E_SkillSkilladvance  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_SkillSkilladvance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/SkillSkilladvanceDesc.h ${PROTOCGEN_FILE_PATH}/SkillSkilladvanceDesc.cpp" --dst=${DESC_STORE_PATH}/

