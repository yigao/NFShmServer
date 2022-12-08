include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/roleborn.bin ${PROTOCGEN_FILE_PATH}/RoleBornDesc.h ${PROTOCGEN_FILE_PATH}/RoleBornDesc.cpp ${PROTOCGEN_FILE_PATH}/rolemasterMale.bin ${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.cpp ${PROTOCGEN_FILE_PATH}/rolemasterFemale.bin ${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/rolesickleMale.bin ${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/rolesickleFemale.bin ${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/roleswordMale.bin ${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.cpp ${PROTOCGEN_FILE_PATH}/roleswordFemale.bin ${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/roletaidaoMale.bin ${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.cpp ${PROTOCGEN_FILE_PATH}/roletaidaoFemale.bin ${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.cpp ${PROTOCGEN_FILE_PATH}/roleexp.bin ${PROTOCGEN_FILE_PATH}/RoleExpDesc.h ${PROTOCGEN_FILE_PATH}/RoleExpDesc.cpp ${PROTOCGEN_FILE_PATH}/roleskillType.bin ${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.h ${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.cpp ${PROTOCGEN_FILE_PATH}/roleaddSkill.bin ${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.h ${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.cpp ${PROTOCGEN_FILE_PATH}/roleworldexp.bin ${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.h ${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.cpp 

${PROTOCGEN_FILE_PATH}/roleborn.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleborn  --excel_sheetname=born  --proto_msgname=roleborn  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleborn.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleBornDesc.h ${PROTOCGEN_FILE_PATH}/RoleBornDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rolemasterMale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rolemasterMale  --excel_sheetname=masterMale  --proto_msgname=rolemasterMale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rolemasterMale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMastermaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rolemasterFemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rolemasterFemale  --excel_sheetname=masterFemale  --proto_msgname=rolemasterFemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rolemasterFemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleMasterfemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rolesickleMale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rolesickleMale  --excel_sheetname=sickleMale  --proto_msgname=rolesickleMale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rolesickleMale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/rolesickleFemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_rolesickleFemale  --excel_sheetname=sickleFemale  --proto_msgname=rolesickleFemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/rolesickleFemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSicklefemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roleswordMale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleswordMale  --excel_sheetname=swordMale  --proto_msgname=roleswordMale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleswordMale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordmaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roleswordFemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleswordFemale  --excel_sheetname=swordFemale  --proto_msgname=roleswordFemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleswordFemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleSwordfemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roletaidaoMale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roletaidaoMale  --excel_sheetname=taidaoMale  --proto_msgname=roletaidaoMale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roletaidaoMale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaomaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roletaidaoFemale.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roletaidaoFemale  --excel_sheetname=taidaoFemale  --proto_msgname=roletaidaoFemale  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roletaidaoFemale.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.h ${PROTOCGEN_FILE_PATH}/RoleTaidaofemaleDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roleexp.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleexp  --excel_sheetname=exp  --proto_msgname=roleexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleExpDesc.h ${PROTOCGEN_FILE_PATH}/RoleExpDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roleskillType.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleskillType  --excel_sheetname=skillType  --proto_msgname=roleskillType  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleskillType.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.h ${PROTOCGEN_FILE_PATH}/RoleSkilltypeDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roleaddSkill.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleaddSkill  --excel_sheetname=addSkill  --proto_msgname=roleaddSkill  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleaddSkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.h ${PROTOCGEN_FILE_PATH}/RoleAddskillDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/roleworldexp.bin:${PROTOCGEN_FILE_PATH}/role.proto.ds ${RESDB_EXCELMMO_PATH}/role.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/role.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/role.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_roleworldexp  --excel_sheetname=worldexp  --proto_msgname=roleworldexp  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/roleworldexp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.h ${PROTOCGEN_FILE_PATH}/RoleWorldexpDesc.cpp" --dst=${DESC_STORE_PATH}/

