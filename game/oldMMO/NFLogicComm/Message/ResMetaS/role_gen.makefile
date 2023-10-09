include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_RoleBorn.bin ${PROTOCGEN_FILE_PATH}/RoleBornDesc.h ${PROTOCGEN_FILE_PATH}/RoleBornDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleMastermale.bin ${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleMasterfemale.bin ${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleSicklemale.bin ${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleSicklefemale.bin ${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleSwordmale.bin ${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleSwordfemale.bin ${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleTaidaomale.bin ${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleTaidaofemale.bin ${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleExp.bin ${PROTOCGEN_FILE_PATH}/RoleExpDesc.h ${PROTOCGEN_FILE_PATH}/RoleExpDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleSkilltype.bin ${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.h ${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleAddskill.bin ${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.h ${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.cpp ${PROTOCGEN_FILE_PATH}/E_RoleWorldexp.bin ${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.h ${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_RoleBorn.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleBorn  --excel_sheetname=born  --proto_msgname=E_RoleBorn  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleBorn.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleBornDesc.h ${PROTOCGEN_FILE_PATH}/RoleBornDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleMastermale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleMastermale  --excel_sheetname=masterMale  --proto_msgname=E_RoleMastermale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleMastermale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleMasterfemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleMasterfemale  --excel_sheetname=masterFemale  --proto_msgname=E_RoleMasterfemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleMasterfemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleSicklemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleSicklemale  --excel_sheetname=sickleMale  --proto_msgname=E_RoleSicklemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleSicklemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleSicklefemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleSicklefemale  --excel_sheetname=sickleFemale  --proto_msgname=E_RoleSicklefemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleSicklefemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleSwordmale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleSwordmale  --excel_sheetname=swordMale  --proto_msgname=E_RoleSwordmale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleSwordmale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleSwordfemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleSwordfemale  --excel_sheetname=swordFemale  --proto_msgname=E_RoleSwordfemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleSwordfemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleTaidaomale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleTaidaomale  --excel_sheetname=taidaoMale  --proto_msgname=E_RoleTaidaomale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleTaidaomale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleTaidaofemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleTaidaofemale  --excel_sheetname=taidaoFemale  --proto_msgname=E_RoleTaidaofemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleTaidaofemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleExp.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleExp  --excel_sheetname=exp  --proto_msgname=E_RoleExp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleExp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleExpDesc.h ${PROTOCGEN_FILE_PATH}/RoleExpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleSkilltype.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleSkilltype  --excel_sheetname=skillType  --proto_msgname=E_RoleSkilltype  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleSkilltype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.h ${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleAddskill.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleAddskill  --excel_sheetname=addSkill  --proto_msgname=E_RoleAddskill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleAddskill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.h ${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/E_RoleWorldexp.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_RoleWorldexp  --excel_sheetname=worldexp  --proto_msgname=E_RoleWorldexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/E_RoleWorldexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.h ${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.cpp" --dst=${DESC_STORE_PATH}/

